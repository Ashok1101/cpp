#include<iostream>
using namespace std;
//arrays of obj & passing obj to function & friend function
class complex{
    int a;
    int b;

    public: 
        void setData(int v1, int v2){
            a = v1;
            b = v2;
        }
        friend complex setDataBySum(complex o1,complex o2); //friend function is used to access private data by outside function
        // void setDataBySum(complex o1, complex o2){
        //     a = o1.a + o2.a;
        //     b = o1.b + o2.b;
        // }

        void printNumber(){
            cout<<"Your complex number is "<<a<<" + "<<b<<"i"<<endl;
        }
};
complex setDataBySum(complex o1, complex o2){
            complex c[2];
            c[2].setData((o1.a + o2.a),(o1.b + o2.b));
            return c[2];
        }


int main(){
    complex c[3];  //array of objects 
    c[0].setData(1, 2);
    c[0].printNumber();

    c[1].setData(3, 4);
    c[1].printNumber();

    c[2]=setDataBySum(c[0], c[1]);  // passing objects as function arguements
    c[2].printNumber();
    return 0;
}

/* Properties of friend functions
1. Not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contans the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name to access any member.

*/