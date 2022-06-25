#include <iostream>

#define LOG(x) std::cout << x << std::endl

/*
    Think of classes as structs that can hold not only variable but fucntions as well

    variables are called proprieties in classes
    functions are called methods in classes

    by default, everything is created as private in classes, unless ordered otherwise
*/

class Player{

    int x,y;
    int speed;

public:
    int z,w;
    void move(int xi , int yi)
    {
        z += xi;
        w += yi;
    }

};

/*
    In cpp structs and classes are basically the same. They both can hold variables and functions
    the main difference is that everything inside a struct is created as public by default

    So if they do the same thing... why use one or another?

            Well the anwser is simple. Structs exist in cpp for backwards compatibility with c language scripts,
        where classes dont exist, only structs do.
            Having said that. REMEMBER!!! If you are going to use structs in cpp, even though they can hold functions too, DONT DO IT.
        If you are going to create a data structure that will hold both variables and functions ALWAYS USE CLASS
*/
struct PlayerStruct{
    int x,y;
    int speed;

public:
    int z,w;
    void move(int xi , int yi)
    {
        z += xi;
        w += yi;
    }

};

void move(Player& player, int xi , int yi)
{
    player.z += xi;
    player.w += yi;
}

int main()
{
    Player player; //class object
    PlayerStruct player_struct; //struct object
    
    //player.x = 5; //this will cause an error because by default everything is created as private in classes in cpp 
    player_struct.x = 3; //this is possible because everything is public by default in a struct in cpp

    player.z = 2; // this is possible since z and w are under the public group
    player.w = 2;
    
    LOG(player.z);
    LOG(player.w);

    move(player,2,2);

    LOG(player.z);
    LOG(player.w);

    player.move(2,2);
    LOG(player.z);
    LOG(player.w);


}