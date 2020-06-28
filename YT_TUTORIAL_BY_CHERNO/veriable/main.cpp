#include<iostream>

int main(){

    //possible datatype for whole number is int, long, short, long int, long long
    //possible datatype for decimal number is float and double
    //datatype for character is char
    //datatype for string is array of char i.e. char[]
    //boolean datatype for use to store true and false --> '0' means false other than that is true
    //sizeof() display size of any variable on memory
    //two other type of datatype we have which is pointer(int* pointer) and refences(int& reference)

    int int_variable = 8;
    std::cout << "int variable: "<< int_variable<< std::endl;
    int_variable = 20;
    std::cout << "modified int variable: "<< int_variable<< std::endl;

    unsigned int positive = 20;
    std::cout << "Positive Number: "<< positive<< std::endl;

    float float_number = 1.2f;
    double double_number = 2.3;
}