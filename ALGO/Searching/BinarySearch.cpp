#include <iostream>

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