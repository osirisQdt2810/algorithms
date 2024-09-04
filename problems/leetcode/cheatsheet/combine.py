from glob import glob
from tqdm import tqdm
from natsort import natsorted
import re
from pathlib import Path

# List of file paths
readme_files = glob("/home/phucnp/storage/cp/leetcode_solutions/solution/*/*/README_EN.md")
    
readme_files = natsorted(readme_files)

# Path for the combined README file
combined_readme = './readme.md'
img_src_pattern = re.compile(r'<img\s+alt="[^"]*"\s+src="([^"]+)"\s+style="[^"]*"\s*/>')

# Regular expression pattern to match content between problem:start and description:end
pattern = re.compile(r'<!-- problem:start -->(.*?)<!-- description:end -->', re.DOTALL)

# Open the combined README file in write mode
with open(combined_readme, 'w') as outfile:
    for file in readme_files:
        with open(file, 'r') as infile:
            content = infile.read()
            # Extract the desired content
                
            match = pattern.search(content)
            if match:
                newcontent = match.group(1).strip()
                img_srcs = img_src_pattern.findall(newcontent)
                
                for img_src in img_srcs:
                    img = Path(img_src).name
                    newcontent = newcontent.replace(img_src, "")
                
                # Write the extracted content to the combined file
                outfile.write(newcontent)  # .strip() removes leading/trailing whitespace
                outfile.write('\n\n')  # Add a newline between each section