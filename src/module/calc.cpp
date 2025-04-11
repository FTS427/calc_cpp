class Calculate{
    private:
        double Num1, Num2, resault=0;
        char op;
        bool status;

    public:
        Calculate(double N1, char Op, double N2):
            Num1(N1), Num2(N2), op(Op){}

        void calc_resault(){
            if(op == '+'){
                resault = Num1 + Num2;
                status = true;
            }
            else if (op == '-') {
                resault = Num1 - Num2;
                status = true;
            }
            else if (op == '*') {
                resault = Num1* Num2;
                status = true;
            }
            else if (op == '/' && Num2 != 0) {
                resault = Num1 / Num2;
                status = true;
            }
            else if (op == '^' && Num1 != 0) {
                resault = pow(Num1, Num2);
                status = true;
            }
            else {
                status = false;
            }
        }

        bool get_status() const {
            return status;
        }

        double get_resault() const {
            return resault;
        }
};