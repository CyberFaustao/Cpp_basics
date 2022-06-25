#include<iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

struct Vector2
{
    float x,y;

    Vector2(float x, float y)
        : x(x) , y(y) {}

    Vector2 Add(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator+(const Vector2& other) const
    {
        return Add(other);
    }

    static void Print(const Vector2& vector)
    {
        std::cout<<vector.x<<","<<vector.y<<std::endl;
    }
};

class Entity
{
protected:
    Vector2* m_position;
    std::string* m_name;
    int speed;
public:
    Entity(const std::string& name, const Vector2& init_position)
    : m_position(new Vector2(init_position)),m_name(new std::string(name)){}

    virtual  void move(const Vector2& movement) = 0;

};

class Enemy : public Entity
{
public:
    Enemy(const std::string& name, const Vector2& init_position)
    : Entity(name,init_position)
    {
        LOG("New player created");
    }
    
    void move(const Vector2& movement) override 
    { 
        (*m_position) = (*m_position)+movement;
    }
};

class Player : public Entity
{
private:



public:

    Player(const std::string& name, const Vector2& init_position)
    : Entity(name,init_position)
    {
        LOG("New player created");
    }

    ~Player()
    {
        LOG("Player destroyed");
        free(this->m_position);
        free(this->m_name);
    }

    void move(const Vector2& movement) override 
    { 
        (*m_position) = (*m_position)+movement;
    }

    const std::string& GetName() const {return (*m_name);}

    void PrintName() const {std::cout<<this->m_name <<std::endl;}

    void PrintPosition() const 
    {
        Vector2::Print(*m_position);
    }
};


int main()
{   
    Player* p;

    {
        p = new Player(std::string("Bruno"),Vector2(10,2));
        p->PrintPosition();

        //Enemy e;


    }

    // LOG(p->GetName());

    // p->move(Vector2(2,2));

    // p->PrintPosition();
    
    // p->move(Vector2(10,2));

    // p->PrintPosition();

     delete p;



}