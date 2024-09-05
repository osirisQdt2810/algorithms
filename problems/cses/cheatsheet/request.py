import requests
import re
import pickle

data = {
    "problems": [],
    "descriptions": []
}

# Fetch the main problem list page
src = requests.get('https://cses.fi/problemset/list/').text

ind = 0

combined_readme = ""
combined_readme_file = './readme.md'

pids = {}

def remove_http(content: str) -> str:
    http_pattern_1 = r"https://fastly\.jsdelivr\.net"
    http_pattern_2 = r"https://leetcode\.com/"
    http_pattern_3 = r"https://en\.wikipedia\.org"
    http_pattern_4 = r"https://support\.leetcode\.com"
    http_pattern_5 = r"https://www\.youtube\.com"
    http_pattern_6 = r"https://"
    http_pattern_7 = r"http://"
    
    content = re.sub(http_pattern_1, '', content)
    content = re.sub(http_pattern_2, '', content)
    content = re.sub(http_pattern_3, '', content)
    content = re.sub(http_pattern_4, '', content)
    content = re.sub(http_pattern_5, '', content)
    content = re.sub(http_pattern_6, '', content)
    content = re.sub(http_pattern_7, '', content)
    return content

def modify(content: str) -> str:
    mapm = {
        r"\\rightarrow" : '->',
        r"\\leftarrow" : '<-',
        r"\\leftrightarrow" : '<->',
        r"\\le" : '<=',
        r"\\ldots" : '...',
        r"\\cdot" : '.',
        r"\\div" : '/',
        r"\\pm" : '+-',
        r"\\times" : 'x'
    }
    
    for k, v in mapm.items():
        content = re.sub(k, v, content)
    return content
        
with open(combined_readme_file, 'w') as outfile:
    cnt = 0
    while True:
        start = src.find('<a href="/problemset/task/', ind)
        if start == -1:
            break
        end = src.find('</a>', start)

        # Extract problem ID and name
        pid = src[start + len('<a href="/problemset/task/'):start + len('<a href="/problemset/task/') + 4]
        name = src[start + len('<a href="/problemset/task/') + 6: end]

        # Fetch the content of the specific problem by constructing its URL
        if pid not in pids:
            pids[pid] = True
            print(pid)
            problem_url = f'https://cses.fi/problemset/task/{pid}/'
            problem_page = requests.get(problem_url).text

            # Extract the problem description
            from bs4 import BeautifulSoup

            # Fetch the content of the problem page
            response = requests.get(problem_url)

            # Parse the HTML content
            soup = BeautifulSoup(response.text, 'html.parser')

            # Extract the title
            title = soup.find('title').text

            # Extract the content in <div class="md">
            content_div = soup.find('div', class_='md')
            content_div = remove_http(modify(str(content_div)))

            # Print or process the extracted information
            # print(f"<title>{title}</title>")
            # print(f'<div class="md">{content_div}</div>')
            
            combined_readme = "## " + str(pid) + "." + title + "\n"
            combined_readme += f'<div class="md">{content_div}</div>\n\n'
            
            ind = end
            
            data['problems'].append(str(pid) + "." + title)
            data['descriptions'].append(content_div)
        
            outfile.write(combined_readme)
            
        else:
            print(f"{pid = } has already existed")
            
        cnt+=1
        # if cnt == 10:
        #     break

with open('./readme.pkl', 'wb') as file:
    pickle.dump(data, file)