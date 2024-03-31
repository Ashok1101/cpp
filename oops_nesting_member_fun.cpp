#include<iostream>
using namespace std;
//oops and nesting of member function
class Employee
{
    private:           //access modifier
        int a, b, c;
        void sum(int a,int b,int c);
    public:
        int d, e;
        void setData(int a1, int b1, int c1); // Declaration
        void getData(){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of e is "<<e<<endl;
        }
};
void Employee :: sum(int a,int b,int c){
            cout<<"a+b+c+d+e :"<<a+b+c<<endl;
        }
void Employee :: setData(int a1, int b1, int c1){   //definition
    a = a1;
    b = b1;
    c = c1;
    d=d;
    e=e;
    void sum(int a,int b,int c);  // Nesting of member functions
}

int main(){
    Employee harry;
    // harry.a = 134; -->This will throw error as a is private
    harry.d = 34;
    harry.e = 89;
    harry.setData(1,2,4);  //private members can be access only by using function
    harry.getData();
    return 0;
}
// OOPs - Classes and objects

// C++ --> initially called --> C with classes by stroustroup
// class --> extension of structures (in C)
// structures had limitations
//      - members are public
//      - No methods
// classes --> structures + more
// classes --> can have methods and properties
// classes --> can make few members as private & few as public
// structures in C++ are typedefed
// you can declare objects along with the class declarion like this:
/* class Employee{
            // Class definition
        } harry, rohan, lovish; */
// harry.salary = 8 makes no sense if salary is private


