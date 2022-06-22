#include <iostream>
#include <vector>
using namespace std;

//Given a sorted array in ascending order, binary search algo is able to 
//find the target in O(logN) time

class BinarySearch
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int pivot = left + (right - left) / 2; //***equivalent to (left + right) / 2, but this way is able to prevent the int overflow.

            if(nums[pivot] == target)
                return pivot;
            else if(target > nums[pivot])
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        return -1;
    }
};

int main()
{
    vector<int> testVec = {-2, -1, 5, 7, 11, 27, 39, 55}; //target = -2, 39, 10

    BinarySearch binarySearch;
    cout << "Find target -2 at index: " << binarySearch.search(testVec, -2) << endl;
    cout << "Find target 39 at index: " << binarySearch.search(testVec, 39) << endl;
    cout << "Find target 10 at index: " << binarySearch.search(testVec, 10) << endl;

    return 0;
}