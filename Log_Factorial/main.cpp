#include <cmath>
#include <iostream>


double compute_log_factorial(int input)
{
    if(input < 0) {
        throw "Input is not in the domain!\nAborting...";
    }
    if(input == 1) {
        return 0;
    }
    else {
        return log10(input) + compute_log_factorial(input - 1);
    }
}

int main()
{
    try {
        while(1) {
            int input;
            std::cout << "Enter input: ";
            std::cin >> input;

            double result = compute_log_factorial(input);
            std::cout << "Result of computation: " << result << std::endl;
        }
    }
    catch(const char* error) {
        std::cout << error << std::endl;
    }

    return 0;
}