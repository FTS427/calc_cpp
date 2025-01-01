#include <cstdlib>
#include <cstring>
#include <cmath>

double calc(char *num1, char *op, char *num2){
    double n1 = atof(num1);
    double n2 = atof(num2);
    if (strcmp(op, "+") == 0){
        return n1 + n2;
    }
    else if (strcmp(op, "-") == 0){
        return n1 - n2;
    }
    else if (strcmp(op, "*") == 0){
        return n1 * n2;
    }
    else if (strcmp(op, "/") == 0 && n2 != 0){
        return n1 / n2;
    }
    else if (strcmp(op, "^") == 0 && n2 != 0){
        return pow(n1, n2);
    }
    else {
        return 0;
    }
}