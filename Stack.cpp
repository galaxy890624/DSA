#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> data;  // Vector to store stack elements

public:
    void push(int value)
    {
        data.push_back(value); // Add element to the back
    }

    void pop()
    {
        if (!data.empty())
        {
            data.pop_back(); // Remove last element
        }
    }

    int top()
    {
        if (!data.empty())
        {
            return data.back(); // Return last element
        }
        throw out_of_range("Stack is empty");
    }

    bool empty()
    {
        return data.empty();
    }

    int size()
    {
        return data.size();
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top element: " << s.top() << endl; // Output: 20
    s.pop();
    cout << "Top element: " << s.top() << endl; // Output: 10
    return 0;
}