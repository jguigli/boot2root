import os
import re
import subprocess
import hashlib

# Files directory path
directory_path = './'

print("Sort pcap files...")

# key: file number, value: code line
code_snippets = {}

# Loop on files in directory
for filename in os.listdir(directory_path):
    # check if extension is .pcap
    if filename.endswith(".pcap"):
        # create the full path for file
        filepath = os.path.join(directory_path, filename)

        # Read file
        with open(filepath, 'r') as file:
            lines = file.readlines()
            code_lines = []
            for line in lines:
                # search // line for find file number
                if "//file" in line:
                    # Extraire all
                    file_number = int(re.search(r'\d+', line).group())
                else:
                    stripped_line = line.strip()
                    if stripped_line:
                        code_lines.append(stripped_line)

            if code_lines:
                code_snippets[file_number] = code_lines;

print("Sorting done...")

# Create new file.c
new_source_path = './solution.c'

# sort numbers and fill C file
with open(new_source_path, 'w') as source_file:
    for file_number in sorted(code_snippets.keys()):
        for line in code_snippets[file_number]:
            source_file.write(line + '\n')

print("C file was build with success...");

print("Compile C file...")

subprocess.run(["gcc", "solution.c", "-o", "result"])

print("Compilation DONE!")

print("Result with SHA256 on the password:")

res = subprocess.run(["./result"], capture_output=True, text=True)

if res.returncode != 0:
    print(f"Oups C program failed: {stderr.decode()}")
else:
    output = res.stdout.split('\n')
    first_line = output[0]

# Recover the password
words = first_line.split()
password = words[-1] if words else ""


# Hash the password
if password:
    sha256_hash = hashlib.sha256(password.encode()).hexdigest()
    print(sha256_hash)
else:
    print("OUPS. No password")
