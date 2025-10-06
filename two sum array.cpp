#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};  // found the pair
        }
        mp[nums[i]] = i; // store current value and its index
    }
    return {}; // not needed, since problem guarantees a solution
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}
