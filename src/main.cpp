#include <iostream>
#include <string_view>
#include <unordered_map>
#include <functional>

#include "include/tui.hpp"
#include "include/calc.hpp"
#include "include/function.hpp"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        function::error();
        return 1;
    }

    const std::string_view cmd(argv[1]);
    
    static const std::unordered_map<std::string_view, std::function<void()>> commands = {
        {"-v", function::version},
        {"--version", function::version},
        {"-h", function::help},
        {"--help", function::help},
        {"-i", function::info},
        {"--info", function::info}
    };

    if (auto it = commands.find(cmd); it != commands.end()) {
        it->second();
        return 0;
    }

    if ((cmd == "-c" || cmd == "--calc") && argc == 5) {
        try {
            Calculate calc(
                std::stod(argv[2]),
                argv[3][0],
                std::stod(argv[4])
            );

            if (calc.getStatus()) {
                printf("%.2f %s%c%s %.2f %s=%s %.2f\n", 
                    calc.getNum1(), F_YELLOW, calc.getOp(), RESET,
                    calc.getNum2(), F_YELLOW, RESET, calc.getResult());
                return 0;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }

    function::error();
    return 1;
}
