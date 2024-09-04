from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
from transformers import BertModel, BertTokenizer
from sentence_transformers import SentenceTransformer
import torch
import numpy as np
from natsort import natsorted
import re

from glob import glob
import argparse
from typing import List, Tuple

def search_1(readme: List[str], query: str, topk: int) -> List[int]:
    documents = readme + [query]
    vectorizer = TfidfVectorizer().fit_transform(documents)
    cosine_similarities = cosine_similarity(vectorizer[-1], vectorizer[:-1])
    indices = np.argsort(cosine_similarities[0])[-topk:][::-1]
    return indices, cosine_similarities[0][indices].tolist()

def search_2(readme: List[str], query: str, topk: int) -> List[int]:
    # Load pre-trained BERT model and tokenizer
    tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')
    model = BertModel.from_pretrained('bert-base-uncased')

    # Move the model to GPU if available
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    model.to(device)

    def get_bert_embeddings(text):
        encoded_input = tokenizer(text, return_tensors='pt', padding=True, truncation=True, max_length=512)
        encoded_input = {key: value.to(device) for key, value in encoded_input.items()}  # Move input to GPU
        with torch.no_grad():
            output = model(**encoded_input)
        embeddings = output.last_hidden_state.mean(dim=1).cpu().numpy()  # Move output back to CPU for numpy
        return embeddings
    
    doc_embeddings = np.vstack([get_bert_embeddings(text) for text in readme + [query]])
    cosine_similarities = cosine_similarity(doc_embeddings[-1].reshape(1, -1), doc_embeddings[:-1])
    indices = np.argsort(cosine_similarities[0])[::-1][:topk]
    return indices,  cosine_similarities[0][indices].tolist()

def search_3(readme: List[str], query: str, topk: int) -> List[int]:
    # Load the pre-trained SentenceTransformer model
    model = SentenceTransformer('all-MiniLM-L6-v2')
    if torch.cuda.is_available():
        model = model.to('cuda')
    doc_embeddings = model.encode(readme + [query], convert_to_tensor=True, device='cuda' if torch.cuda.is_available() else 'cpu')
    cosine_similarities = cosine_similarity(doc_embeddings[-1].cpu().numpy().reshape(1, -1), doc_embeddings[:-1].cpu().numpy())[0]
    indices = np.argsort(cosine_similarities)[::-1][:topk]
    return indices, cosine_similarities[indices].tolist()
    
def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", default=1, type=int)
    parser.add_argument("--topk", default=1, type=int)
    parser.add_argument("--query", default="", type=str)
    return parser.parse_args()

def readme() -> Tuple[List[str], List[str]]:
    files = natsorted(glob("/home/phucnp/storage/cp/leetcode_solutions/solution/*/*/README_EN.md"))
    
    def extract_readme_details(content):
        # Extract Problem Name
        problem_name_match = re.search(r'# \[(.+?)\]', content)
        problem_name = problem_name_match.group(1).strip() if problem_name_match else None

        # Extract Difficulty
        difficulty_match = re.search(r'difficulty:\s*(\w+)', content)
        difficulty = difficulty_match.group(1).strip() if difficulty_match else None

        # Extract Detail Description without examples
        description_no_example_match = re.search(r'<!-- description:start -->(.*?)(<strong class="example">|<strong>Example)', content, re.DOTALL)
        description_no_example = re.sub(r'<[^>]*>', '', description_no_example_match.group(1).strip()) if description_no_example_match else None

        # Extract Detail Description with examples
        description_with_example_match = re.search(r'<!-- description:start -->(.*?)<!-- description:end -->', content, re.DOTALL)
        description_with_example = description_with_example_match.group(1).strip() if description_with_example_match else None

        return problem_name, difficulty, description_no_example, description_with_example 
    
    rmes, probs, diffs = [], [], []
    cnt = 0
    for file in files:
        with open(file, 'r') as infile:
            content = infile.read()
            details = extract_readme_details(content)
            if details[0] is None or details[2] is None:
                # print(content)
                err1 = "{}_{}_{}".format(cnt, "pr" if details[0] is None else "", "ds" if details[2] is None else "")
                with open(f"{err1}.md", "w") as fw:
                    fw.write(content)
                cnt+=1
                continue
            
            rmes.append(details[2])
            probs.append(details[0])
            diffs.append(details[1])
    
    return rmes, probs, diffs

if __name__ == "__main__":
    args = parse_args()
    rme, prob, diffs = readme()
    if (args.mode == 1):
        indices, scores = search_1(rme, args.query, args.topk)
    elif (args.mode == 2):
        indices, scores = search_2(rme, args.query, args.topk)
    elif (args.mode == 3):
        indices, scores = search_3(rme, args.query, args.topk) 
        
    for idx, score, diff in zip(indices, scores, diffs):
        print(f"score = {score}, problem = {prob[idx]}")