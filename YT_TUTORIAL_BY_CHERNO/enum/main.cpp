#include <iostream>

// can't declare same same named variable in enum 
// enum variable are case-sensitive

enum Example : int {
    A,B,C
};

enum Sample : int {
    D,E,F
};

int main(){
    
    Example value = A;
    std::cout << B << std::endl; 
}