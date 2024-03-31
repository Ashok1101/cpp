#include <iostream>
using namespace std;
//virtual base class
class grandfather{
    public:
    int a=10;
};
class father:virtual public grandfather{   // virtual-When one class is made virtual then only one copy of its data
    public:                               // member and member function is passed to the classes inheriting it. 
    int b=9;
};
class mother:virtual public grandfather{
    public:
    int c=6;
};
class son:public father,public mother{
    public:
    int d = a+b+c;  // here a is ambiguous
};
int main()
{   grandfather g;
    cout<<g.a<<endl;
    father f;
    cout<<"father.a: "<<f.a<<endl;
    son s;
    cout<<"son.a: "<<s.a<<endl;
}






