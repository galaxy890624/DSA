#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Leetcode Q912
// Quick sort
class Solution {
public:
    // Subarray
    void Partition(vector<int>& nums, int start, int end){
        // Boundary condition

        // If start == end, the subarray has only one element, which is already sorted.
        // If start > end, it means the pointers have crossed, and further recursion would be invalid.
        if(start >= end)
        {
            return;
        }
        // Initialize

        // Choice middle element index
        int pivot = (start + end) / 2;
        // Left pointer index 
        int left = start;
        // Right pointer index
        int right = end;

        // Move the number which is smaller then nums[pivot] to left hand side, and so does the larger one
        while(left < right)
        {
            // Find nums[left] until nums[left] > nums[pivot]
            while(nums[left] < nums[pivot])
            {
                left++;
            }
            // And so does nums[right]
            while(nums[right] > nums[pivot])
            {
                right--;
            }
            // Ensures swaps only happen when left pointer has not crossed right one
            if(left <= right)
            {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        // Recrusion

        // Pivot left hand side
        Partition(nums, start, right);
        // Pivot right hand side
        Partition(nums, left, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        Partition(nums, 0, nums.size() - 1);

        return nums;
    }
};

int main()
{
    Solution Sol;
    // Test case
    vector<int> nums = {39, 11, 48, 5, 77, 18, 70, 25, 55, 33};
    for(int i = 0; i < nums.size(); i++)
    {
        cout << Sol.sortArray(nums)[i] << " ";
    }
    cout << endl;
    
    return 0;
}