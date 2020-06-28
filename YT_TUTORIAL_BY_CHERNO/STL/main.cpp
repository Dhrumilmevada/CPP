#include <iostream> 
#include <array>
#include <vector>


void vectorDemo(){

}

void arrayDemo(){
    std::array<int,10> num = {1,2};

    std::cout << "check for empty: " << (num.empty() ? "YES" : "NO")<< std::endl;
    std::cout << "check for size: " << num.size() << std::endl;
    std::cout << "check for max_size: " << num.max_size() << std::endl;

    for (int i = 0; i<num.size(); i++){
        std::cout << "Elements at "<<i +1 <<" is "<< num[i] << std::endl ;
    }
    std::cout << std::endl;

    std::cout << "Element at 5 index is " << num.at(5) << std::endl;

    std::cout << "first element in array is " << num.front() << std::endl;

    std::cout << "last element in array is " << num.back() << std::endl;

    int* pointer = num.data();
    for (int* i = pointer; i!=num.end(); i++)
        std::cout << *i << " " ;
    std::cout << std::endl;

    std::array<int,10> copy;
    copy.fill(12); 

    int* pointer1 = copy.data();
    for (int* i = pointer1; i!=copy.end(); i++)
        std::cout << *i << " " ;
    std::cout << std::endl; 

    num.swap(copy);
    std::cout << "num:- ";
    for(int i: num)
        std::cout << i << " ";
    std::cout << std::endl; 

    std::cout << "copy:- ";
    for(int i: copy)
        std::cout << i << " ";
    std::cout << std::endl;

    copy[9] = 100;
    for(int i: copy)
        std::cout << i << " ";
    std::cout << std::endl;

    for ( auto it = copy.begin(); it != copy.end(); ++it )
        std::cout << *it << " " ;
    std::cout << std::endl;

    for( auto it = copy.rbegin(); it != copy.rend(); ++it ){
        *it = 5;    
        std::cout << *it << " " ;
    }
    std::cout << std::endl;

    for( auto it = copy.cbegin(); it != copy.cend(); ++it ){ 
        //*it = 50; not modify value   
        std::cout << *it << " " ;
    }
    std::cout << std::endl;

    
}

void moveDemo(){
    std::vector<int> v = {2,3,3,5,6};
    std::vector<int> vec;

    std::cout << "V" << std::endl;
    for (auto i = v.begin(); i != v.end(); ++i){ 
        if(v.begin() == v.end())
            std::cout <<" empty" << std::endl;
        std::cout << *i << " "; 
    }   
    std::cout << "\nVEC"<< std::endl;
    for (auto i = vec.begin(); i != vec.end(); ++i){ 
        if(vec.empty())
            std::cout <<" empty" << std::endl;
        std::cout << *i << " "; 
    }         
    std::cout << std::endl;


    vec = std::move(v);

    std::cout << "V" << std::endl;
    for (auto i = v.begin(); i != v.end(); ++i) 
        std::cout << *i << " "; 
    std::cout << std::endl;
    std::cout << "\nVEC"<< std::endl;
    for (auto i = vec.begin(); i != vec.end(); ++i) 
        std::cout << *i << " "; 
    std::cout << std::endl;
}

int main()
{
    arrayDemo();
}