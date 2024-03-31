/* Program to implement a stack using
two queue */
#include <bits/stdc++.h>
using namespace std;

class Stack {
	// Two inbuilt queues
	queue<int> q1, q2;
public:
	void push(int x)
	{
		// Push x first in empty q2
		q2.push(x);
		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{
		// if no elements are there in q1
		if (q1.empty())
			return;
		q1.pop();
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size() { return q1.size(); }
};

// stack using single queue

class Stack1
{
    queue<int>q;
public:
    void push(int val);
    void pop();
    int top();
    bool empty();
};
 
// Push operation
void Stack1::push(int val)
{
    //  Get previous size of queue
    int s = q.size();
 
    // Push current element
    q.push(val);
 
    // Pop (or Dequeue) all previous
    // elements and put them after current
    // element
    for (int i=0; i<s; i++)
    {
        // this will add front element into
        // rear of queue
        q.push(q.front());
 
        // this will delete front element
        q.pop();
    }
}
 
// Removes the top element
void Stack1::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}
 
// Returns top of stack
int  Stack1::top()
{
    return (q.empty())? -1 : q.front();
}
 
// Returns true if Stack is empty else false
bool Stack1::empty()
{
    return (q.empty());
}
// Driver code
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << "current size: " << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << "current size: " << s.size() << endl;

    // stack using single queue
    Stack1 s1;
    s1.push(10);
    s1.push(20);
    cout << s1.top() << endl;
    s1.pop();
    s1.push(30);
    s1.pop();
    cout << s1.top() << endl;
    return 0;
}
