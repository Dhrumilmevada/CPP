#include <iostream>

//Pointer and reference are almost of same type.
//With compare reference, pointers are more powerful in terms of manipulating memory.

//Unlike pointers refences cannot allocate new memory block. They can just point to already allocated memory address.
//Reference variable have been assigned reference to already assign memory addresses at a time of initialization.

//once reference variable was initialized a to memory address, reference variable can not been changed to other memory address but value stored to address
//can be changed. 

//Whenever reference of reference variable need to be changed than pointer will be better option in this case. 

void increment(int* value){
    (*value)++;
}

void increment(int& value){
    value++;
}
//From above program,It is clear that syntax for refences is much simpler and clear compare to pointer as they are providing same functionality. 


int main(){

    int a = 5;
    std::cout<< "Value of variable 'a': "<< a << std::endl;
    int& ref = a;
    std::cout<< "Value of variable 'a' using reference: "<< ref << std::endl;
    ref = 10;
    std::cout<< "Changed value of variable 'a' using reference: "<< ref << std::endl;

    int b = 23;
    std::cout<< "Value of variable 'b': "<< b << std::endl;

    increment(&b);
    std::cout << "Increment value of variable 'b' by using pointer: " << b << std::endl;

    increment(b);
    std::cout << "Increment value of variable 'b' by using reference: " << b << std::endl;


    int c = 100;
    int d = 102;

    std::cout<< "Value of variable 'c': "<< c << std::endl;
    std::cout<< "Value of variable 'd': "<< d << std::endl;
    int& ref_c = c;

    std::cout<< "Value of variable 'c': using reference: "<< ref_c << std::endl;

    ref_c = d; // it will not start refencing to new address i.e. address of variable 'd', but it will assign value of variable 'd' to variable 'c' 
               // pointer is better choice here this kind of case
    std::cout<< "Value of variable 'c' after changing reference: "<< c << std::endl;
    std::cout<< "Value of variable 'd' after changing reference: "<< d << std::endl;

}