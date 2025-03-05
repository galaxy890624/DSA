#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Queue
{
private:
    vector<int> data;

public:
    void enqueue(int value)
    {
        data.push_back(value); // Insert at the back
    }

    void dequeue()
    {
        if (!data.empty())
        {
            data.erase(data.begin()); // Remove from front
        }
    }

    int front()
    {
        if (!data.empty())
        {
            return data.front(); // Return front element
        }
        throw out_of_range("Queue is empty");
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
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Front element: " << q.front() << endl; // Output: 10
    q.dequeue();
    cout << "Front element: " << q.front() << endl; // Output: 20
    return 0;
}