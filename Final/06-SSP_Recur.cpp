#include <iostream>
#include <vector>
using namespace std;

bool subsetSumRecursive(vector<int>& nums, int target, int index) {
    if (target == 0)
        return true;
    if (index < 0 || target < 0)
        return false;
    if (nums[index] > target)
        return subsetSumRecursive(nums, target, index - 1);
    return subsetSumRecursive(nums, target - nums[index], index - 1) || subsetSumRecursive(nums, target, index - 1);
}

bool subsetSum(vector<int>& nums, int target) {
    int n = nums.size();
    return subsetSumRecursive(nums, target, n - 1);
}

int main() {
    vector<int> nums = {2, 3, 7, 8, 10};
    int target = 11;
    if (subsetSum(nums, target))
        cout << "Subset with the given sum exists." << endl;
    else
        cout << "Subset with the given sum does not exist." << endl;
    return 0;
}
