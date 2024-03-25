#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool subsetSumRecursive(vector<int>& nums, int target, int index, unordered_map<string, bool>& memo) {
    if (target == 0)
        return true;
    if (index < 0 || target < 0)
        return false;
    string key = to_string(index) + "-" + to_string(target);
    if (memo.find(key) != memo.end())
        return memo[key];
    if (nums[index] > target)
        memo[key] = subsetSumRecursive(nums, target, index - 1, memo);
    else
        memo[key] = subsetSumRecursive(nums, target - nums[index], index - 1, memo) || subsetSumRecursive(nums, target, index - 1, memo);
    return memo[key];
}

bool subsetSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<string, bool> memo;
    return subsetSumRecursive(nums, target, n - 1, memo);
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
