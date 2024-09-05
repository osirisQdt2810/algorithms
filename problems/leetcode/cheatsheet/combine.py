from glob import glob
from tqdm import tqdm
from natsort import natsorted
import re
from pathlib import Path

# List of file paths
readme_files = glob("/home/phucnp/storage/cp/revision/problems/leetcode/cheatsheet/solution/*/*/README_EN.md")
    
readme_files = natsorted(readme_files)

# Path for the combined README file
combined_readme = './readme.md'

# Regular expression pattern to match content between problem:start and description:end
pattern = re.compile(r'<!-- problem:start -->(.*?)<!-- description:end -->', re.DOTALL)
http_pattern_1 = r"https://fastly\.jsdelivr\.net"
http_pattern_2 = r"https://leetcode\.com/"
http_pattern_3 = r"https://en\.wikipedia\.org"
http_pattern_4 = r"https://support\.leetcode\.com"
http_pattern_5 = r"https://www\.youtube\.com"
http_pattern_6 = r"https://"
http_pattern_7 = r"http://"

# Use re.sub to remove all matches
# Open the combined README file in write mode
with open(combined_readme, 'w') as outfile:
    for file in readme_files:
        with open(file, 'r') as infile:
            content = infile.read()
            # Extract the desired content
                
            match = pattern.search(content)
            
            if match:
                content = match.group(1).strip()
                content = re.sub(http_pattern_1, '', content)
                content = re.sub(http_pattern_2, '', content)
                content = re.sub(http_pattern_3, '', content)
                content = re.sub(http_pattern_4, '', content)
                content = re.sub(http_pattern_5, '', content)
                content = re.sub(http_pattern_6, '', content)
                content = re.sub(http_pattern_7, '', content)
                
                                
                # for img_src in img_srcs:
                #     img = Path(img_src).name
                #     newcontent = newcontent.replace(img_src, "")
                
                # Write the extracted content to the combined file
                outfile.write(content)  # .strip() removes leading/trailing whitespace
                outfile.write('\n\n')  # Add a newline between each section