/*
 * 1. Two Sum
 * Link: https://leetcode.com/problems/two-sum/
 * Date: 2025-04-14
 * Author: Carson Phillips
 * Category: Arrays & Hashing (NeetCode)
 * Difficulty: Easy
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 */

#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        if(map.find(target - nums[i]) != map.end()) {
            return {map.at(target - nums[i]), i};
        }
        map[nums[i]] = i;
    };
    return {};
}

int main() {
    vector<int> test1 = {2, 7, 11, 15};
    vector<int> expected1 = {0, 1};
    vector<int> test2 = {3, 2, 4};
    vector<int> expected2 = {1, 2};
    vector<int> test3 = {3, 3};
    vector<int> expected3 = {0, 1};
    if (twoSum(test1, 9) == expected1 && twoSum(test2, 6) == expected2 && twoSum(test3, 6) == expected3) {
        cout << "pass";
        } else {
            cout << "fail";
        }
    return 0;
}

/* Solution Explanation:
 * A naive approach would be to use two nested loops to check every possible pair of numbers
 * and see if they add up to the target. While this works, it results in O(n^2) time complexity,
 * which is inefficient for large inputs.
 *
 * A more optimal solution uses an unordered map (hash map) to achieve O(n) time complexity.
 * As we iterate through the array, we calculate the complement for each number by subtracting
 * it from the target. If the complement is already in the map, we've found a valid pair and
 * return their indices. Otherwise, we store the current number and its index in the map.
 *
 * This allows us to check for matches in constant time as we go, rather than comparing every
 * number to every other number.
 *
 * Note: Explanation written by Carson Phillips with refinement from ChatGPT.
 */