/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true



Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109

Solution by Carson Phillips 4/14/2025
*/
#include <algorithm>
#include <iostream>
#include <set>
#include<vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1]) {
      return true;
    }
  }
  return false;
}

int main() {
  vector<int> test1 = {1, 2, 3, 1};
  vector<int> test2 = {1, 2, 3, 4};
  vector<int> test3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

  if (containsDuplicate(test1) && !containsDuplicate(test2) && containsDuplicate(test3)) {
    cout << "Pass";
  } else {
    cout << "Fail";
  }

  return 0;
}

