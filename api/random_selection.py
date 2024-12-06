import os
import yaml
from glob import glob

def extract_tags(file_path):
    try:
        with open(file_path, 'r') as file:
            lines = file.readlines()
            
            # Extract the YAML front matter
            if lines[0].strip() == "---":
                yaml_content = []
                for line in lines[1:]:
                    if line.strip() == "---":
                        break
                    yaml_content.append(line)
                
                # Parse the YAML content
                yaml_data = yaml.safe_load("\n".join(yaml_content))
                return yaml_data.get('tags', [])
            else:
                print(f"No YAML front matter found in {file_path}")
                return []
    except Exception as e:
        print(f"Error reading file {file_path}: {e}")
        return []

TAGS = {
    "Array" : 1780,
    "String" : 745,
    "Hash Table" : 645,
    "Dynamic Programming" : 547,
    "Math" : 537,
    "Sorting" : 420,
    "Greedy" : 389,
    "Depth-First Search" : 301,
    "Database" : 289,
    "Binary Search" : 289,
    "Matrix" : 239,
    "Tree" : 236,
    "Breadth-First Search" : 233,
    "Bit Manipulation" : 228,
    "Two Pointers" : 210,
    "Prefix Sum" : 180,
    "Heap (Priority Queue)" : 179,
    "Binary Tree" : 176,
    "Simulation" : 165,
    "Stack" : 163,
    "Counting" : 152,
    "Graph" : 152,
    "Sliding Window" : 138,
    "Design" : 125,
    "Backtracking" : 104,
    "Enumeration" : 95,
    "Union Find" : 84,
    "Linked List" : 79,
    "Ordered Set" : 64,
    "Number Theory" : 63,
    "Monotonic Stack" : 62,
    "Trie" : 54,
    "Segment Tree" : 51,
    "Bitmask" : 47,
    "Divide and Conquer" : 47,
    "Queue" : 46,
    "Recursion" : 46,
    "Combinatorics" : 43,
    "Binary Search Tree" : 40,
    "Hash Function" : 39,
    "Binary Indexed Tree" : 39,
    "Geometry" : 38,
    "Memoization" : 38,
    "String Matching" : 33,
    "Topological Sort" : 32,
    "Shortest Path" : 31,
    "Rolling Hash" : 30,
    "Game Theory" : 28,
    "Interactive" : 23,
    "Data Stream" : 20,
    "Monotonic Queue" : 17,
    "Brainteaser" : 17,
    "Randomized" : 12,
    "Merge Sort" : 12,
    "Doubly-Linked List" : 11,
    "Counting Sort" : 9,
    "Iterator" : 9,
    "Concurrency" : 9,
    "Probability and Statistics" : 7,
    "Quickselect" : 7,
    "Suffix Array" : 7,
    "Bucket Sort" : 6,
    "Minimum Spanning Tree" : 5,
    "Shell" : 4,
    "Line Sweep" : 4,
    "Reservoir Sampling" : 4,
    "Strongly Connected Component" : 3,
    "Eulerian Circuit" : 3,
    "Radix Sort" : 3,
    "Rejection Sampling" : 2,
    "Biconnected Component" : 1
}

TARGET_TAGS = [
    "Depth-First Search",
    "Binary Search",
    "Tree",
    "Breadth-First Search",
    "Binary Tree",
    "Graph",
    "Union Find",
    "Trie",
    "Segment Tree",
    "Binary Search Tree",
    "Binary Indexed Tree",
    "Topological Sort",
    "Shortest Path",
    "Minimum Spanning Tree",
    "Strongly Connected Component",
    "Biconnected Component"
]

if __name__ == "__main__":
    # Directory containing the README.md files
    tags_dict = {tag: [] for tag in TAGS}
    
    for file_path in glob("/home/phucnp/storage/algorithms/problems/leetcode/cheatsheet/solution/*/*/README_EN.md"):
        tags = extract_tags(file_path)
        
        for tag in tags:
            if tag not in TAGS:
                # raise Exception(f"Invalid tag {tag} in {file_path}")
                continue
            
            tags_dict[tag].append(
                (file_path.split("/")[-2][:4])
            )
            
    diff_tags = []
    for tag in tags_dict:
        # print(f"{tag = }, {TAGS[tag] = }, {len(tags_dict[tag]) = }")
        if (TAGS[tag] != len(tags_dict[tag])):
            diff_tags.append((tag, len(tags_dict[tag]), TAGS[tag]))
    
    [print(diff_tag) for diff_tag in diff_tags]
    
    target_probs = []
    [target_probs.extend(tags_dict[tag]) for tag in TARGET_TAGS]
    import random
    print(f"Lucky problem: {random.choice(target_probs)}")
        
            
    


