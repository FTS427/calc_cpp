#include <stdio.h>
#include <cstring>

#include "include/info.hpp"
#include "include/tui.hpp"

#include "module/calc.cpp"

int main(int argc, char *argv[]){
    if (argc >= 1){
        if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0 ){
            printf("%s\n", PROJECT_NAME);
            printf(" - Version: %s\n", PROJECT_VERSION);
            printf(" - Repository: %s%s%s\n", UNDERLINE, PROJECT_REPO, RESET);
            printf(" - Description: %s\n", PROJECT_DESCRIPTION);
            printf(" - Made by %s\n", PROJECT_AUTHOR);
        }
        else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--calc") == 0 ){
            printf("%s %s%s%s %s %s=%s %lf\n", argv[2], F_YELLOW, argv[3], RESET, argv[4],F_YELLOW ,RESET, calc(argv[2], argv[3], argv[4]));
        }
        else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0 ){
            printf("Usage: %s [option]\n", argv[0]);
            printf("Options:\n");
            printf("  -v, --version    Show version\n");
            printf("  -h, --help       Show help\n");
            printf("  -c NUM1 OPTION NUM2, --calc NUM1 OPTION NUM2      Calculate\n");
        }
    }
    return 0;
}