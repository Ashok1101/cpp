#include <iostream>
using namespace std;
//Constructor :default,parameterized & overloading,copy
class Complex
{
    int a, b;

public:
    // Creating a Constructor
    // Constructor is a special member function with the same name as of the class.
    //It is used to initialize the objects of its class
    //It is automatically invoked whenever an object is created
    // It has no return type 

    Complex(void); // Constructor declaration
    Complex(int,int);   //Constructor overloading
    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex ::Complex(void) // ----> This is a default constructor as it takes no parameters
{
    a = 10;
    b = 0;
    // cout<<"Hello world";
}
Complex ::Complex(int x,int y=1) // ----> This is a parameterized constructor as it takes 2 parameters
{
    a = x;
    b = y;                     //y has default value if not given
    // cout<<"Hello world";
}
int main()
{
    Complex c1;
    Complex c2(8,9); //implicit call
    Complex c3 = Complex(6,4);  //explicit call
    Complex c4 = Complex(7);
    Complex c5(c2);   // copy constructor // this is 'shallow copy' means if i do changes in c2 then it reflects in c5 also
    c1.printNumber();
    c2.printNumber();
    c3.printNumber();
    c4.printNumber();
    c5.printNumber();
    return 0;
}

/*Important Characteristics of Constructors in C++

1. A constructor should be declared in the public section of the class
2. They are automatically invoked whenever the object is created
3. They cannot return values and do not have return types
4. It can have default arguments
5. We cannot refer to their address*/ 

/* shallow copy -
1)same addresss is access by different variable names 
2) if value is changed of one then changes will reflect in others as well*/
/*  deep copy -
1)content of one is copied but saved with different address{another variable}
2) here changes in 1 will not affect others value
*/
