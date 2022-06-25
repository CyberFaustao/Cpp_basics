#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Entity
{
public:
    static int x,y;
    
    void Print()
    {
        std::cout << x << "," << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

int main()
{
    Entity e;
    e.x = 2;
    e.y = 3;

    Entity e2;
    e2.x = 5;
    e2.y = 8;

    //The steps above will only work if you have defined x and y (line 16 and 17), since they are static

    e.Print();
    e2.Print();

    //Because x and y are declared as static, that means that only one instance of x and y will exist through out all instances of the Entity class
    //So if you change x and y in one object of entity all object will receive this update. You'll print [5,8] twice

    //Because of this shared propriety you dont have to refer to x and y through an Entity object. you can refer directly
    Entity::x = 10;
    Entity::y = 5;

    e.Print();
    e2.Print();

    //You could do the same with the Print function and declare it as static. In which case you would refere to it as:
    //Entity::Print();
    //Keep in mind that static functions can only access static variables!!
    //That is because static methods, even though are inside a class. They are actually seem as outside the class
    //*classes in cpp dont really exist, they are just a hidden parameter that is passed to all non-static methods created. Static methods dont receive this parameter and so are not inside the class
}