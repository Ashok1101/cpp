# include <iostream>
using namespace std;
// this pointer 
class base{
    int a=29;
    public:
    int getdata(int a){
        this->a=a;     // 'this' is used for using same variable
        return a;
    }
};
int main(){
    base b;
    cout<<b.getdata(45)<<endl;
}