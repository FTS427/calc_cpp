#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>

#include "include/tui.hpp"

#include "module/calc.cpp"
#include "module/function.cpp"

using function::error;

int main(int argc, char *argv[]){
    Calculate calc(0, ' ', 0);
    
    if (argc > 1){
        if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0 ){
            function::version();
        }
        else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0 ){
            function::help();
        }
        else if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--info") == 0 ){
            function::info();
        }
        else if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--calc") == 0 && argc >= 5){
            calc = Calculate(atof(argv[2]), *argv[3], atof(argv[4]));
            calc.calc_resault();

            if (calc.get_status()){
                printf("%s %s%s%s %s %s=%s %lf\n", argv[2], F_YELLOW, argv[3], RESET, argv[4],F_YELLOW ,RESET, calc.get_resault());
            }
            else{
                error();
            }
        }
        else{
            error();
        }
    }
    else {
        error();
    }
    return 0;
}
