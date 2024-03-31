#include <iostream>
using namespace std;
int swap(int *x,int *y){
        int temp=*x;
        *x=*y;
        *y=temp;
    }

int main()
{   
    // pointer 
    int a=10;
    int*p;
    p=&a;
    cout<<&a<<endl;    //returns address
    cout<<*p<<endl;   // returns value of a {dereference}
    *p=20;
    cout<<*p<<endl;   // we can change value by pointer as well
    p++;
    cout<<p<<endl;  // differece will be of 4 bcoz int type requires 4 byte
    int ar[]={10,20,30};
    cout<<*ar<<endl; // acts as pointer pointing to first item
    for(int i=0;i<3;i++){
        cout<<*(ar+i)<<endl;
    }
    //pointer to pointer
    int b=10;
    int*ptr=&b;
    int**q=&ptr;
    cout<<*q<<endl;
    cout<<**q<<endl;
    //call by value
    int x=11,y=10;
    swap(x,y);    // this will not swap bcoz x,y here and x,y in function has different address
    cout<<x<<" "<<y<<endl;
    //call by dereference
    swap(&x,&y);
    cout<<x<<" "<<y<<endl;  //swap is done
}