#include <iostream>
using namespace std;

class Hero {
    
private:
    int health;

public:
    char level;
    char *name;
    static int timeToComplete;

    // Constructor
    Hero() {
        cout << "Constructor called" << endl;
        name = new char[100];
    }

    // Parameterised constructor
    Hero(int health) {
        cout << "Parameterised constructor called" << endl;
        cout << "Value of this: " << this << endl;
        this->health = health;
    }

    Hero(int health, char level) {
        cout << "Parameterised constructor called" << endl;
        this->health = health;
        this->level = level;
    }

    // Copy constructor
    Hero(const Hero &temp) {
        // Deep copy
        char *arr = new char[strlen(temp.name) + 1];
        strcpy(arr, temp.name);
        this->name = arr;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout << "[ Name: " << this->name << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Level: " << this->level << " ]";
        cout << endl;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    static int getTimeToComplete() {
        return timeToComplete ;
    }

    // Destructor
    ~Hero() {   
        cout << "Destructor called" << endl;
    }

};

int Hero::timeToComplete = 5;

int main() {

    // // Calling static function
    // cout << Hero::getTimeToComplete() << endl;




    // // RECOMMENDED
    // cout << Hero::timeToComplete << endl;

    // // NOT RECOMMENDED
    // Hero a;
    // cout << a.timeToComplete << endl;

    // Hero b;
    // b.timeToComplete = 10 ;
    // cout << a.timeToComplete << endl;
    // cout << b.timeToComplete << endl;




    // // Static allocation
    // Hero a;

    // // Dynamic allocation
    // Hero *b = new Hero();
    // // Manually calling destructor
    // delete b;




    // // Shallow and Deep copy
    // Hero h1;
    // h1.setHealth(12);
    // h1.setLevel('D');
    // char name[7] = "Tanish";
    // h1.setName(name);
    // h1.print();

    // // Use default copy constructor
    // Hero h2(h1);
    // // Hero h2 = h1;
    // h2.print(); 

    // h1.name[0] = 'M';
    // h1.print();
    // h2.print();

    // // Assignment operator
    // cout << "Using assignment operator" << endl;
    // h1 = h2;
    // h1.print();
    // h2.print();




    // Calling copy constructor
    // Hero S(70, 'C');
    // S.print();

    // Hero R(S);
    // R.print();




    // // Calling parameterised constructor
    // Hero ramesh(10);
    // cout << "Address of ramesh: " << &ramesh << endl;
    // ramesh.print();

    // Hero *h =  new Hero(15);
    // h->print();

    // Hero temp(22, 'B');
    // temp.print();




    // // Static allocation
    // Hero a;
    // a.setHealth(80);
    // a.setLevel('B');
    // cout << "Level: " << a.level << endl;
    // cout << "Health: " << a.getHealth() << endl;

    // // Dynamic Allocation
    // Hero *b = new Hero;
    // b->setHealth(70);
    // b->setLevel('A');
    // cout << "Level: " << (*b).level << endl;
    // cout << "Health: " << (*b).getHealth() << endl;

    // cout << "Level: " << b->level << endl;
    // cout << "Health: " << b->getHealth() << endl;


    

    // Hero ramesh;   
    // cout << "Size of Ramesh: " << sizeof(ramesh) << endl;
    // cout << "Ramesh's Health: " << ramesh.getHealth() << endl;
    // ramesh.setHealth(70);
    // ramesh.level = 'A';
    // cout << "Ramesh's Health: " << ramesh.getHealth() << endl; 
    // cout << "Ramesh's Level: " << ramesh.level << endl; 

    return 0;
}