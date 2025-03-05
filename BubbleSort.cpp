#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Leetcode Q912
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Traverse all the element count
        int count = 1;
        // Bubble sort
        // Move the biggest element to the last
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size() - count; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j], nums[j+1]);
                }
            }
            count++;
        }
        return nums;
    }
};

int main()
{
    Solution Sol;
    // Test case
    vector<int> nums = {18, 2, 20, 34, 12};
    for(int i = 0; i < nums.size(); i++)
    {
        cout << Sol.sortArray(nums)[i] << " ";
    }
    cout << endl;
    
    return 0;
}