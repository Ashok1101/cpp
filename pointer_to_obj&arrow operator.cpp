#include<iostream>
using namespace std;
//pointer to obj & arrow operator
class Complex{
    int real, imaginary;
    public:
        void getData(){
            cout<<"The real part is "<< real<<endl;
            cout<<"The imaginary part is "<< imaginary<<endl;
        }

        void setData(int a, int b){
            real = a;
            imaginary = b;
        }

};
int main(){
    Complex *ptr = new Complex;  //pointer to objects
    (*ptr).setData(2,45);
    (*ptr).getData();
    ptr->setData(1, 54);   //ptr-> is equal to  *ptr 
    ptr->getData(); 

    // Array of Objects
    Complex *ptr1 = new Complex[4]; 
    ptr1->setData(1, 4); 
    ptr1->getData();
    return 0;
}
