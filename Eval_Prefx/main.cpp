#include <iostream>
#include <string>
#include <vector>

int eval(std::string& input, std::string::const_iterator& citerator)
{
    int result = 0;

    if(citerator != input.end()) {

        while(citerator != input.end() && *citerator == ' ') {
            ++citerator;
        }

        if(citerator == input.end()) {
            return 0;
        }

        if(*citerator == '*') {
            ++citerator;
            return eval(input, citerator)*eval(input, citerator);
        }

        if(*citerator == '+') {
            ++citerator;
            return eval(input,citerator)+eval(input, citerator);
        }

        while(citerator != input.end() && '0' <= *citerator && *citerator <= '9') {
            result = 10*result + static_cast<int>(*citerator - '0'); //The case where the entered number is not one digit like 132
            ++citerator;
        }
    }

    return result;
}



int main()
{
    std::string input;
    std::cout << "Input a prefix expression: ";


    
    std::cin >> input;
    auto citerator = input.cbegin();
    auto result = eval(input, citerator);

    std::cout << result << std::endl;
    return 0;
}