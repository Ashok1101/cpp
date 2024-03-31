#include <iostream>
using namespace std;
//single inheritance
// Base Class
class Employee
{
public:
    int id;
    float salary=90;
    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
    Employee() {}
};

class details : public Employee{
    public:
    string name="arvind";
};
//multilevel
class multilevel : public details{
    public:
    int a=89;
};
int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    details d1;
    cout <<d1.name<<endl;
    cout << d1.salary<<endl;
    multiple m;
    cout<<m.name<<endl;
    return 0;
}
