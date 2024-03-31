#include<iostream>
using namespace std;
class hero{
};
class vilan{
    int id;  // bydefault private

    public:
    int health;
    char level;
    int getprivateid(){
        // cout<<id<<endl;
        return id;
    }
    void setprivateid(int i){
        id=i;
    }
};
int main(){
    hero h1;    // instance of class
    vilan h2;
    cout<<"size: "<<sizeof(h1)<<endl; // size of empty class is '1'
    cout<<"health is: "<<h2.health<<endl;
    cout<<"level is: "<<h2.level<<endl;
    cout<<"id: "<<h2.getprivateid(); 
    h2.setprivateid(10);                   // use setter
    cout<<"id: "<<h2.getprivateid()<<endl;    // use getter
    cout<<"size: "<<sizeof(h2)<<endl;
}
/* 4 pillars of OOPS -
1) Encapsulation:- wrapping up data members & functions {data hiding}
2) Inheritance:- inherit the properties of parent class by child class
3) Polymorphism:- multiple forms
    i] Compile Time: Function & operator overloading(static)- two function with same name but diff nos of parameters; funcs with same name & same nos of parameters& same datatypes but diff return type is not allowed
    ii]Runtime time: (dynamic) method overridding - func under child class overrides parent class with same name
4) Abstraction:- hiding implementation 
*/