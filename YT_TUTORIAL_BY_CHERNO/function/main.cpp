#include <iostream>

//For every function define in code, compiler has to create different stack for it in memory.
//So while calling one fuction from function compiler has to change load its stack(block of memory assign to function).
//Each stack of function will store data related to that function like its parameter, return value, local variable of function 
//To execute function, Compiler has to work little bit more in term of memory management, so more function call can compromize performance of program.
//But function are really helpfull to avoid duplicate or repetitive code.

int add(int a,int b){
    return a+b;
}

int multiply(int a,int b){
    return a*b;
}

int divide(int a,int b){
    return a/b;
}

int substract(int a,int b){
    return a-b;
}
int main(){

    std::cout<< "Addition: "<<add(3,4)<< std::endl;
    std::cout<< "Multiplication: "<<multiply(3,4)<< std::endl;
    std::cout<< "Divinations: "<<divide(3,4)<< std::endl;
    std::cout<< "Substraction: "<<substract(3,4)<< std::endl;
}