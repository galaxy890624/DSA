#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Leetcode Q912
// Selection sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Traverse all the element of nums, choose a minimum element and move to index = i
        for(int i = 0; i < nums.size() - 1; i++)
        {
            // If nums[j] < nums[i], swap them
            for(int j = i; j < nums.size(); j++)
            {
                if(nums[j] < nums[i])
                {
                    swap(nums[j], nums[i]);
                    // i++; j reset to 0;
                    continue;
                }
            }

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