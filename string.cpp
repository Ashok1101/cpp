#include <iostream>
#include <string>  // to use string
#include <algorithm>  // to sort
using namespace std;
// String
int main()
{   
    string str="arvind patel";
    cout<<str<<endl;
    string s1(5,'o');  //prints 5 times 'o'
    cout<<s1<<endl;
    getline(cin,str); // prints complete line
    cout<<str<<endl;
    s1="fam";
    string s2="ily";
    s1.append(s2);
    cout<<s1<<endl;
    cout<<s1+s2<<endl;
    cout<<s1[3]<<endl;   //index starts with 0
    // s2.clear();
    cout<<s2<<endl;
    cout<<s2.compare(s1)<<endl;
    s1.erase(3,2);  //from index 3 erase 2 characters
    cout<<s1<<endl;
    cout<<s1.find("am")<<endl; //returns index of 1st character
    s1.insert(3,"il");      //insert 'il' to index 3
    cout<<s1<<endl;
    cout<<s1.size()<<endl;     //length
    cout<<s1.length()<<endl;  //length
    string s3=s1.substr(3,2);  // substring
    cout<<s3<<endl;
    s3="768";
    int w=stoi(s3);
    cout<<w+2<<endl;      // 2 get add to 768
    w=768;
    cout<<to_string(w)+'2'<<endl;  //2 get append to 768
    sort(s1.begin(),s1.end());   
    cout<<s1<<endl;   //sort alphabetical
    for(int i=0;i<s1.size();i++){     //convert to uppercase
        if(s1[i]>='a'&& s1[i]<='z'){
            s1[i]-=32;      //'A'-'a'=32; ascii values
        }
    }cout<<s1<<endl;
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);  //inbuilt function 
    cout<<s1<<endl;
    string s="12345";  // to sort decreasingly
    sort(s.begin(),s.end(),greater<int>());
    cout<<s<<endl;
    s="dmgvhvuiirrtbuu";
    
}