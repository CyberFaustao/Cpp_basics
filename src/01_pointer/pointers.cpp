#include <iostream>

void voidPointer()
{
    //void pointers we do not care for the type of data
    void* ptr = nullptr; //nullptr has the moemory of 0

}

void stackPointer()
{
    int var = 8;
    void* ptr = &var;
    int* ptr2 = &var;

    std::cout << "Memory of void pointer:" << ptr << std::endl; 
    std::cout << "Memory of int pointer:" << ptr2 <<std::endl;

    //No difference between void and int. Actually types dont mean anything. Its just easier.

    //std::cout << "value of void pointer:" << *ptr << std::endl; //because this pointer is a void. The compiler doesn't know how long the data stored is
    std::cout << "value of int pointer:" << *ptr2 <<std::endl; //because this pointer is an int pointer. The compiler knows hgow long the data stored is

    //The step above is called de-referencing. Method to get the stored data
}

void heapPointer()
{
    char* buffer = new char[8]; //When you use the new keyword you are allocating memory on the heap. Asking for 8 bytes. It returns a pointer to the beggining of that memory block

    memset(buffer,0,8);

    delete[] buffer; //when you allocate in the heap ALWAYS call delete function
}

int main()
{
    stackPointer();
    heapPointer();
}