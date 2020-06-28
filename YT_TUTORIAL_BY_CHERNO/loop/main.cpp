#include<iostream>

int main(){
    for(int i=0; i<5; i++){
        if(i==2) continue; // go to next iteration in loop
        if(i==3) break; // out of loop
        std::cout<< i << " --> Hello world" << std::endl;
    }

    int j = 1;
    while(j < 3){
        if(j==2) return 0; // out of loop and exit and return from function
        std::cout<< j++ << std::endl;
    }

    std::cout << "next is do..while Loop"<< std::endl;
    do{

    }while(false);
}