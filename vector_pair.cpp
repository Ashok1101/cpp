#include <iostream>
#include<vector>     //for vector
#include<algorithm>  //sort requires
using namespace std;
//vector->dynamic array
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    vector<int>::iterator it;   //'it' is a pointer of iterator
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
    for(auto element:v){     //auto ->compiler decides datatype according to initialization
        cout<<element<<endl;
    }
    v.pop_back();   //1 2
    vector<int>v1(3,50);  //50 50 50
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
    //insert
    vector<int> :: iterator iter = vec1.begin();
    vec1.insert(iter,566);
    cout<<vec1;
    swap(v,v1);   //swap
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
    // vector<vector<int>> grid(n,vector<int>(m,-1));  //2D vector
    
    //Pair
    pair<int,char>p;
    p.first=3;
    p.second='c';
    
    
}
