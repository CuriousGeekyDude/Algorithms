#include "Eval_Infix.hpp"
#include <iostream>

void Eval_Infix::infix_to_postfix()
{
    for(size_t i = 0; i < infix_form.size(); ++i) {
        if(infix_form[i] == '(') {
            continue;
        }

        if(infix_form[i] == '*' || infix_form[i] == '+' || infix_form[i] == '/' || infix_form[i] == '-') {
            operators.push_back(infix_form[i]);
            continue;
        }

        if(infix_form[i] == ')') {
            if(operators.size() != 0) {
                const char dummy_var = *(--(operators.end()));
                operators.pop_back();
                postfix_form.push_back(dummy_var);
                continue;
            }

            else { throw "Incorrect format!\nAborting..."; }
        }

        if(48 <= infix_form[i] && infix_form[i] <= 57) {
            postfix_form.push_back(infix_form[i]);
        }

        else { throw "Incorrect format!\nAborting..."; }
    }

    if(operators.size() != 0) {
        const char dummy_var = *(operators.begin());
        operators.pop_back();
        postfix_form.push_back(dummy_var);
    }
}

std::vector<int>::const_iterator last_element(const std::vector<int>::const_iterator* iterator)
{
    auto iter = *iterator;
    return (--iter);
}

int pop_last_element(std::vector<int>& eval_postfix_form)   //One bug found here for case -(-5)
{
    auto const_iter = eval_postfix_form.cend();
    auto iterator = last_element(&const_iter);
    const int dummy_var = *iterator;
    eval_postfix_form.pop_back();
    return dummy_var;
}

int convert_to_digit(const char digit)
{
    int digit_result = static_cast<int>(digit - '0');
    return digit_result;
}


void Eval_Infix::evaluate_postfix()
{
    if(postfix_form.size() == 0) {
        throw "postfix_form is empty!\nAborting...";
    }

    auto iter = postfix_form.cbegin();
    for(; iter != postfix_form.cend(); ++iter) {

        if(iter == postfix_form.cbegin()) {
            if(*iter == '+' || *iter == '-' || *iter == '/' || *iter == '*') {
                throw "Incorrect format!\nAborting";
            }
        }

        if(48 <= *iter && *iter <= 57) {
            eval_postfix_form.push_back(convert_to_digit(*iter));
            continue;
        }
        
        if(*iter == '+' || *iter == '-' || *iter == '/' || *iter == '*') {
            if(*iter != '-') {
                if(eval_postfix_form.size() < 2) {
                    throw "eval_postfix_form has insufficient number of operands!\nAborting";
                }
            }

            if(*iter == '-' && eval_postfix_form.size() == 1) {
                eval_postfix_form[0] = -eval_postfix_form[0];
                break;
            }


            int dummy_int1 = 0;
            int dummy_int2 = 0;
            switch(*iter) {

                case '+':
                    dummy_int1 = pop_last_element(eval_postfix_form);
                    dummy_int2 = pop_last_element(eval_postfix_form);
                    eval_postfix_form.push_back(dummy_int1 + dummy_int2);
                    break;
                case '-':
                    dummy_int1 = pop_last_element(eval_postfix_form);
                    dummy_int2 = pop_last_element(eval_postfix_form);
                    eval_postfix_form.push_back(dummy_int2 - dummy_int1);
                    break;
                case '*':
                    dummy_int1 = pop_last_element(eval_postfix_form);
                    dummy_int2 = pop_last_element(eval_postfix_form);
                    eval_postfix_form.push_back(dummy_int1 * dummy_int2);
                    break;
                case '/':
                    dummy_int1 = pop_last_element(eval_postfix_form);
                    dummy_int2 = pop_last_element(eval_postfix_form);
                    eval_postfix_form.push_back(dummy_int2 / dummy_int1);
                    break;

            }

        }

    }
    if(eval_postfix_form.size() != 1) {
        throw "eval_postfix_form not size 1!\nAborting...";
    }
    
    eval_result = eval_postfix_form[0];
}



void Eval_Infix::reset_field_members()
{
    infix_form = "";
    operators.clear();
    postfix_form.clear();
    eval_postfix_form.clear();
}


void Eval_Infix::get_postfix_form()
{
    for(auto element : postfix_form) {
        std::cout << element;
    }
    std::cout << std::endl;
}


void Eval_Infix::cancel_out_minuses()
{
    if(postfix_form.size() == 0) {
        return;
    }

    auto iter = postfix_form.begin();
    if(*iter < 48 || 57 < *iter) {
        throw "postfixe_form is filled in the wrong way!\nAborting...";
    }

    ++iter;
    for(; iter != postfix_form.end(); ++iter) {
        auto iter_dummy = iter;
        if(++iter_dummy != postfix_form.end()) {
            if(*iter == '-' && *iter == *iter_dummy) {
                ++iter_dummy;
                iter = postfix_form.erase(iter, iter_dummy);
                
                if(postfix_form.size() >= 2) {
                    iter = postfix_form.insert(iter, '+');
                }
            }
        }
    }
}
