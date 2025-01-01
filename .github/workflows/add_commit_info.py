import sys
def alter(file,old_str,new_str):
    file_data = ""
    with open(file, "r", encoding="utf-8") as f:
        for line in f:
            if old_str in line:
                line = line.replace(old_str, new_str)
            file_data += line
    with open(file,"w",encoding="utf-8") as f:
        f.write(file_data)

commit_sha = sys.argv[1]

alter("src/include/info.hpp", "#define PROJECT_VERSION \"1.0.0\"", f"#define PROJECT_VERSION \"1.0.0 {commit_sha[:7]} build\"")
