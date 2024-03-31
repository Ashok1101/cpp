#include<iostream>
using namespace std;

int main(){
    
    float *p = new float(40.78);
    // delete[] p;
    cout << "The value at address p is " << *(p) << endl;
    // array using dynamic memory
    int *arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    // delete[] arr;
    cout << "The value of arr[0] is " << arr[0] << endl;
    cout << "The value of arr[1] is " << arr[1] << endl;
    cout << "The value of arr[2] is " << arr[2] << endl;
    // 2d array using dynamic memory
    int n=10;
    int **ar=new int*[n]; // to create rows
    for(int i=0;i<n;i++){
        ar[i]= new int[n];   // to create columns
    }
    return 0;
}
