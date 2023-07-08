#include "Eval_Infix.hpp"
#include <iostream>

int main()
{
    std::string input;
    

    try {
        while(1) {
            std::cout << "Please enter your infix expression: ";
            std::cin >> input;
            Eval_Infix infix_evaluator(input);
            infix_evaluator.infix_to_postfix();
            infix_evaluator.evaluate_postfix();
            std::cout << infix_evaluator.eval_result << std::endl;
        }

    }

    catch(const char* error) {
        std::cout << error << std::endl;
    }

    return 0;
}