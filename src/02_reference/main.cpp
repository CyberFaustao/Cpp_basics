#include <iostream>

#define LOG(x) std::cout << x << std::endl

/*
 References are basically pointers. There's nothing you can do with a pointer that you cant do with the Reference.
 References are just syntax sugar. So you dont have to write de-referencing statemnts. Which leads to better code
 If you can use a reference, use it!

 BEAR IN MIND: Once you1ve declared a reference. you cannot change whta it is pointed to. Only a normal pointer can
*/

void Increment(int value)
{
    //because value was passed just as a value. The compiler will create a new variable inside of Increment(). Doubling the memory needed

    value++; //same as doing int value = value + 1; <--- creating a new variable called value
}

void IncrementByPointer(int* value)
{
    (*value)++; //de-referencing needed so we are changing the value stored not the pointer itself. De-reference first then increase
}

void IncrementByReference(int& value)
{
    value++; //no de-reference needed when dealing with references. IT'S EASIER!
}

int main()
{
    int a =5;

    int& ref = a; //Here we've created a reference called ref. "ref" doenst really exists. Only "a" does. Thats the power of references

    ref =2;

    LOG(a);

    Increment(a);
    
    LOG(a);

    IncrementByPointer(&a);

    LOG(a);

    IncrementByReference(a);

    LOG(a);

    int b =20;

    int& ref_b = b;

    ref_b = a; // you are not changing what the ref_b is pointing too. All you are doing here is b=a

    LOG(b);


}