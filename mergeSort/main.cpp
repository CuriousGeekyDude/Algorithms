#include <iostream>
#include <vector>
#include <string>
#include <exception>


void merge(std::vector<int>& input_array, const int begin_index, const int almost_middle, const int end_index)
{
    std::vector<int> ordered_array;

    if(input_array.empty() == false) {
        for(int k = 0, i = begin_index, j = almost_middle+begin_index; k < end_index-begin_index; ++k) {
            if(end_index <= j) {
                ordered_array.push_back(input_array[i]);
                ++i; continue;
            }

            if(almost_middle + begin_index <= i) {
                ordered_array.push_back(input_array[j]);
                ++j; continue;
            }

            if(input_array[i] < input_array[j]) {
                ordered_array.push_back(input_array[i]);
                ++i;
            }
            else {
                ordered_array.push_back(input_array[j]);
                ++j;
            }
        }

        for(int k = begin_index; k-begin_index < end_index-begin_index; ++k) {
            input_array[k] = ordered_array[k-begin_index];
        }
    }
}

void merge_sort(std::vector<int>& input_array, const int begin_index, const int end_index) {
    if(end_index != begin_index+1) {
        int almost_middle = ((end_index-begin_index)/2);
        
        merge_sort(input_array, begin_index, begin_index+almost_middle);
        merge_sort(input_array, begin_index+almost_middle, end_index);
        merge(input_array, begin_index, almost_middle, end_index);
    }
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

    merge_sort(input_array, 0, input_array.size());
    for(auto var : input_array) {
        std::cout << var << " ";
    }

    std::cout << std::endl;


    }
    }

    catch(const std::invalid_argument& error) {
        std::cout << "\nError: " << error.what() << "[Invalid arguement]." << std::endl;
    }

    return 0;
}
