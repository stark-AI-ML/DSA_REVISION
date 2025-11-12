#include <iostream>

/*Binary Search : Time Complexity O(log(n)*/

/*
Intuation : Opening book if sorted why would you check previous if you need to go further

Eg : 500 pages you need to go to 300 go for mid (250) you need to go right, right? so again open mid b.w.
250 and 500  --- 375 reched further search in b.w. 250 and 375...
*/
#include <vector>
int BinarySearch(std::vector<int> nums, int target)
{

    int s = 0;
    int e = nums.size();

    while (s < e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return 0;
}

int main()
{

    std::vector<int> nums{3, 4, 5, 6, 7, 8, 9, 10};

    int search = BinarySearch(nums, 4);
    std::cout << search;
}