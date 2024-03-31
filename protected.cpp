#include <iostream>
using namespace std;
//protected access modifier
class base{
    protected:
    int l=10;
    public:
    int b=5;
};
class area:public base{
    public:
    int a=l*b;
};
int main()
{   
    area o;
    // cout<<"length: "<<o.l<<endl;  //even if l is taken public in area but it was protected in base so it will remain protected
    cout<<"area: "<<o.a<<endl;
}

//                     	      Public Derivation      	Private Derivation    	Protected Derivation
// Private members           	Not Inherited              	Not Inherited          Not Inherited              
// Protected members             Protected                 Private                Protected                    
// Public members           	   Public	                Private                Protected  
 





