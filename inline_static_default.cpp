#include<iostream>
using namespace std;
//inline function & static variable & default arguement {should be kept at last}
inline int sum(int a, int b=6){  //mostly used when function is short
    static int c=0; //this executes only 1 time //bydefault static data members value is 0
    c = a + b+c;
    return c;
}
int main(){
    int x =4, y=5;
    cout<<"The sum of 4 and 5 is "<<sum(x, y)<<endl; 
     /* instead of giving parameters to functions and getting value,
        inline function will come to function call to reduce time*/
    cout<<"The sum of 4 and 5 is "<<sum(x, y)<<endl;  //static will not run ,so c =9 from above
    cout<<"The sum of 4 and 5 is "<<sum(x, y)<<endl; //static will not run ,so c =18 from above
    cout<<"the sum of 4 and 6 is "<<sum(x)<<endl;  //default arguement
}
