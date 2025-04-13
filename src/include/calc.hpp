#ifndef CALC_HPP
#define CALC_HPP

#include <stdexcept>
#include <cmath>

class Calculate {
private:
    double num1_;
    double num2_;
    double result_{0.0};
    char op_;
    bool status_{false};

    [[nodiscard]] static constexpr bool isValidOp(char op) noexcept {
        constexpr char valid_ops[] = {'+', '-', '*', '/', '^'};
        for (char valid_op : valid_ops) {
            if (op == valid_op) return true;
        }
        return false;
    }

    void calculate() noexcept {
        try {
            switch (op_) {
                case '+': result_ = num1_ + num2_; break;
                case '-': result_ = num1_ - num2_; break;
                case '*': result_ = num1_ * num2_; break;
                case '/': 
                    if (num2_ == 0) throw std::domain_error("ERROR\n");
                    result_ = num1_ / num2_; 
                    break;
                case '^': 
                    result_ = std::pow(num1_, num2_);
                    break;
                default: 
                    throw std::invalid_argument("Invalid argument!\n");
            }
            status_ = std::isfinite(result_);
        } catch (...) {
            status_ = false;
            result_ = 0.0;
        }
    }

public:
    Calculate(double n1, char op, double n2) 
        : num1_(n1), num2_(n2), op_(op) 
    {
        if (!isValidOp(op)) {
            throw std::invalid_argument("Invalid argument!\n");
        }
        calculate();
    }

    // 禁用拷贝
    Calculate(const Calculate&) = delete;
    Calculate& operator=(const Calculate&) = delete;
    
    // 启用移动
    Calculate(Calculate&&) noexcept = default;
    Calculate& operator=(Calculate&&) noexcept = default;

    // 查询接口
    [[nodiscard]] constexpr bool getStatus() const noexcept { return status_; }
    [[nodiscard]] constexpr double getResult() const noexcept { return result_; }
    [[nodiscard]] constexpr double getNum1() const noexcept { return num1_; }
    [[nodiscard]] constexpr double getNum2() const noexcept { return num2_; }
    [[nodiscard]] constexpr char getOp() const noexcept { return op_; }
};

#endif // CALC_HPP