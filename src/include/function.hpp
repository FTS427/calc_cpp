#ifndef Function_HPP
#define Function_HPP

#include <stdio.h>

#include "./tui.hpp"

namespace function {

    inline void help() {
        printf("Usage: calc [option]\n");
        printf("Options:\n");
        printf(" -v, --version     Show version\n");
        printf(" -i, --info        Show info\n");
        printf(" -h, --help        Show help\n");
        printf(" -c, --calc NUM1 OPTION NUM2      Calculate\n");
    }
    
    inline void info() {
        printf("==== %s ====\n", PROJECT_NAME);
        printf(" - Version: %s build\n", PROJECT_VERSION);
        printf(" - Repository: %s%s%s\n", UNDERLINE, PROJECT_REPO, RESET);
        printf(" - License: %s\n", PROJECT_LICENSE);
        printf(" - Description: %s\n", PROJECT_DESCRIPTION);
        printf(" - Made by %s\n", PROJECT_AUTHOR);
    }
    
    inline void version() { printf("%s\n", PROJECT_VERSION); }
    
    inline void error() {
        printf("%s%s%sInvalid operation!\n%s", ALARM, F_RED, BOLD, RESET);
    }

} // namespace function

#endif