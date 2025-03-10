#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

// Leetcode Q912
// Priority queue
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap

        // Insert all elements into the min-heap
        for (int num : nums) {
            minHeap.push(num);
        }

        // Extract elements from the heap in sorted order
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = minHeap.top();
            minHeap.pop();
        }

        return nums;
    }
};

int main()
{
    Solution Sol;
    // Test case
    vector<int> nums = {27, 7, 80, 5, 67, 18, 62, 24, 58, 25};

    cout << "[";
    for(int i = 0; i < nums.size(); i++)
    {
        cout << Sol.sortArray(nums)[i];
        if(i != nums.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}