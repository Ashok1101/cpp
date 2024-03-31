// C++ program to illustrate macros
#include <iostream>
using namespace std;

// Macro definition
#define LIMIT 5    // object-like macros
#define AREA(l, b) (l * b)  //function-like macros
        // Chain Macros
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138
        // multi-line macro
#define ELE 1, \
            2, \
            3


int main()
{
	// Print the value of macro defined
	cout << "The value of LIMIT"<< " is " << LIMIT<<endl;


    // Given lengths l1 and l2
    int l1 = 10, l2 = 5, area;
    // Find the area using macros
    area = AREA(l1, l2);
    // Print the area
    cout << "Area of rectangle"<< " is: "<<area<<endl;


    // Print the message
    cout << "Geeks for Geeks have "<< INSTAGRAM << "K followers on Instagram!"<<endl;


    int arr[] = { ELE };
    // Print elements
    printf("Elements of Array are:\n");
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << ' ';
    }
	return 0;
}

/*
1. What are the Advantages of Macros?
Ans.-

a) Increased productivity: Macros can save time and reduce errors by automating repetitive tasks.
b) Customization: Macros can be customized to fit specific needs, allowing for greater flexibility in how tasks are completed.
c) Consistency: Macros can help ensure consistency in tasks by following a set of predetermined instructions.
d) Efficiency: Macros can perform tasks more quickly than humans, improving overall efficiency.
e) Ease of use: Macros are easy to create and use, requiring little to no programming knowledge

2. What are the disadvantages of Macros?
Ans.-

a) Security risks: Macros can be a security risk if they are not properly secured or if they are used to execute malicious code.
b) Limited functionality: Macros may not be able to perform more complex tasks, limiting their usefulness.
c) Compatibility issues: Macros may not be compatible with all software applications, limiting their usefulness.
d) Maintenance: Macros may require maintenance and updates, which can be time-consuming and costly.
e) Dependence: Over-reliance on macros can result in decreased problem-solving skills and critical thinking.
*/