#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

// Leetcode Q912
// Heap sort
class Solution
{
public:
    // Function to heapify a subtree rooted at index "i"
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;  // Assume root is the largest
        int left = 2 * i + 1;  // Left child index
        int right = 2 * i + 2; // Right child index

        // If left child is larger than root
        if (left < n && nums[left] > nums[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && nums[right] > nums[largest])
            largest = right;

        // If largest is not root, swap and continue heapifying
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    // Main Heap Sort function
    void heapSort(vector<int>& nums) {
        int n = nums.size();

        // Build max heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--){
            heapify(nums, n, i);
        }

        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);  // Move current root to end
            heapify(nums, i, 0);  // Call heapify on reduced heap
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
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