import sys

def alter(file, old_str, new_str):
    file_data = ""
    found = False
    with open(file, "r", encoding="utf-8") as f:
        for line in f:
            if old_str in line:
                line = line.replace(old_str, new_str)
                found = True
            file_data += line
    if found:
        with open(file, "w", encoding="utf-8") as f:
            f.write(file_data)
    else:
        print(f"Warning: '{old_str}' not found in {file}.")

if len(sys.argv) < 2:
    print("Error: Missing commit SHA as an argument.")
    sys.exit(1)

commit_sha = sys.argv[1]

alter(
    "CMakeLists.txt",
    'add_definitions(-DPROJECT_VERSION=\"${PROJECT_VERSION}\")',
    'add_definitions(-DPROJECT_VERSION=\"${PROJECT_VERSION} ' + f'{commit_sha[:7]}\")'
)