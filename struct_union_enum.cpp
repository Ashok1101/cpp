#include <iostream>
using namespace std;
typedef struct emp{  //structure
    int eid;
    string name;
    float salary;
}e;
union money{       // takes only one item at a time
    int pounds;
    char gold;
    float rice;
};
int main()
{
    struct emp rahul;
    e mohan;     // using typedef,struct emp = e
    rahul.eid=01;
    mohan.eid=02;
    rahul.name="rahul";
    rahul.salary=120000;
    cout<<"eid:"<<rahul.eid<<endl;
    cout<<"eid:"<<mohan.eid<<endl;
    cout<<"name:"<<rahul.name<<endl;
    cout<<"salary:"<<rahul.salary<<endl;
    union money m1;    
    m1.rice=33;
    m1.gold='j';
    cout<<m1.rice<<endl; // returns garbage value bcoz last taken is gold
    cout<<m1.gold<<endl;
    // enum
    enum meal{breakfast,lunch,dinner};
    meal m=lunch;
    cout<<m<<endl;
    cout<<breakfast<<endl;
    cout<<(m==1)<<endl;
}