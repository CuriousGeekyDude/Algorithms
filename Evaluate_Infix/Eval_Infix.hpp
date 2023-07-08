#ifndef EVAL_INFIX_HPP
#define EVAL_INFIX_HPP

#include <string>
#include <vector>
#include <list>

class Eval_Infix
{
    public:
        Eval_Infix(const std::string& input) : infix_form(input) {};

        void infix_to_postfix();
        void evaluate_postfix();


        void reset_field_members();
        void get_postfix_form();    //Only used for debugging purposes
        
        void cancel_out_minus();
        
        int eval_result;


    private:

        std::string infix_form;
        std::vector<char> operators;
        std::list<char> postfix_form;
        std::vector<int> eval_postfix_form;

};



#endif