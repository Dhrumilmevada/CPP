#include <iostream>
//pointer are uses to manage memory.
//pointer point to memory address.

//delete will not directly free memory because it is really a costly operation. So it is maintaining free memory queue with stores locations which are free 
//by program. After set memory it got in queue it will free the system memory mean while if program tries to allocate new memory than it will first check
//already free memory in queue and utilize that memory block if possible.  

int main(){

    // Creating int pointer  
    int* ptr1 = new int;  
      
    // Initializing pointer with value 20 
    int* ptr2 = new int(20);  
  
    std::cout << "Value of ptr1 = " << *ptr1 << "\n"; 
    std::cout << "Value of ptr2 = " << *ptr2 << "\n"; 
  
    delete ptr1; // Destroying ptr1 
    delete ptr2; // Detroying ptr2 

    std::cout << "Value of ptr1 = " << *ptr1 << "\n"; 
    std::cout << "Value of ptr2 = " << *ptr2 << "\n"; 
  
  
    return 0; 
}