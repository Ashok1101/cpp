#include<iostream>
#include<functional>
#include<algorithm>
 
using namespace std;
 
int main(){
 
    // Function Objects (Functor) : A function wrapped in a class so that it is available like an object
    int arr[] = {1, 73, 4, 2, 54, 7};
    sort(arr,arr+5);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
 
// But what if we wanted to sort the same array in descending order, since the sort function can default sort in ascending order only? So, here comes our saviour, functional objects. Our sort function also takes a third parameter which is a functor ( functional object).

sort( arr, arr+6, greater< int >( ));

    return 0;
}
