#include <iostream>
#include <vector>
#include <string>
#include <exception>

int max(const std::vector<int>& input_array, size_t begin_index, size_t end_index)
{
    if(end_index < begin_index) {
        throw "Out of bounds error!\nAborting...";
    }

    if(begin_index == end_index) {
        return input_array[begin_index];
    }

    size_t middle_index = begin_index + ((end_index - begin_index)/2);

    int result1 = max(input_array, begin_index, middle_index);
    int result2 = max(input_array, middle_index+1, end_index);

    if(result1 < result2) {
        return result2;
    }

    else { return result1; }
}



int main()
{

    try {
        while(1) {
            std::vector<int> input_array;
            std::string input;
            std::vector<std::string> input_tokens;
            std::cout << "Enter your numbers seperated by space: ";
            std::getline(std::cin, input);

            if(input.empty()) {continue;}
            for(std::string::const_iterator iter = input.cbegin(); iter != input.cend(); iter++) {
                if(*iter == ' ') {
                    continue;
                }

                std::string dummy_var;
                while(iter != input.cend() && *iter != ' ') {
                    dummy_var.push_back(*iter);
                    ++iter;
                }
                input_tokens.push_back(dummy_var);

                if(iter == input.cend()) {break;}
            }
            if(input_tokens.empty()) { continue; }
            for(std::vector<std::string>::iterator iter = input_tokens.begin(); iter != input_tokens.end(); ++iter) {
                input_array.push_back(std::stoi(*iter));   
            }
            

            int max_number = max(input_array, 0, input_array.size()-1);
            std::cout << "The biggest number is: " << max_number<< std::endl;

        }
    }

    catch(const char* error) {
        std::cout << error << std::endl;
    }

    catch(const std::invalid_argument& error) {
        std::cout << "\nError: " << error.what() << "[Invalid arguement]." << std::endl;
    }

    return 0;
}