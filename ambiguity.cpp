#include <iostream>
using namespace std;
//Ambiguity resolution
class base1{
    public:
    int l;
    int getlen(int l1){
        l=l1;
        return l;
    } 
};
class base2{
    public:
    int b;
    int getlen(int l2){
        b=l2;
        return b;
    }
};
class area:public base1,public base2{
    public:
    int a=l*b;
    int getlen(int d){
        base2 :: getlen(d);  // Ambiguity solved
        return b;
    }
};
int main()
{   base1 b1;
    cout<<b1.getlen(10)<<endl;
    base2 b2;
    cout<<b2.getlen(4)<<endl;
    area o;
    cout<<"area: "<<o.a<<endl;
    cout<<o.getlen(7)<<endl;  //Ambiguity raised
}






