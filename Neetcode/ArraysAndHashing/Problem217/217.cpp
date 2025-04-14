/*
 * 217. Contains Duplicate
 * Link: https://leetcode.com/problems/contains-duplicate/
 * Date: 2025-04-14
 * Author: Carson Phillips
 * Category: Arrays & Hashing (NeetCode)
 * Difficulty: Easy
 *
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Explanation:
 * The element 1 occurs at the indices 0 and 3.
 *
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Explanation:
 * All elements are distinct.
 *
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 */
#include <algorithm>
#include <iostream>
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

/* Solution Explanation:
 * One might initially approach this problem with a brute-force solution,
 * comparing each integer in the array to every other integer. While this
 * works, it has a time complexity of O(n^2).
 *
 * A better approach is to use a hash set (e.g., unordered_set), which allows
 * us to detect duplicates in O(n) time on average. However, in the worst case
 * (due to hash collisions), this can degrade to O(n^2).
 *
 * A more practical and predictable solution is to first sort the array, then
 * check each element against its neighbor. This runs in O(n log n) time and
 * is often faster in real-world use due to optimized sorting algorithms and
 * cache-friendly memory access.
 *
 * Note: Explanation written by Carson Phillips with refinement from ChatGPT.
 */



