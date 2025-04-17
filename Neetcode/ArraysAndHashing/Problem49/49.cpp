/*
* 1. Group Anagrams
 * Link: https://leetcode.com/problems/group-anagrams/
 * Date: 2025-04-14
 * Author: Carson Phillips
 * Category: Arrays & Hashing (NeetCode)
 * Difficulty: Medium
 *
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Explanation:
 * There is no string in strs that can be rearranged to form "bat".
 * The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
 * The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
 *
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 *
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *
 * Constraints:
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < strs.size(); i++) {
        string s = strs[i];
        sort(s.begin(), s.end());
        m[s].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto& p : m) {
        ans.push_back(p.second);
    }
    return ans;
}

bool deepCompare(vector<vector<string>> a, vector<vector<string>> b) {
      for (auto& group : a) sort(group.begin(), group.end());
      for (auto& group : b) sort(group.begin(), group.end());
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      return a == b;
}

int main() {
     vector<string> test1 = {"eat","tea","tan","ate","nat","bat"};
     vector<vector<string>> expected1 = {{"bat"},{"nat","tan"}, {"ate","eat","tea"}};
     vector<string> test2 = {""};
     vector<vector<string>> expected2 = {{""}};
     vector<string> test3 = {"a"};
     vector<vector<string>> expected3 = {{"a"}};

     if (deepCompare(groupAnagrams(test1), expected1) && deepCompare(groupAnagrams(test2), expected2) && deepCompare(groupAnagrams(test3), expected3)) {
         cout << "pass";
     } else {
         cout << "fail";
     }

     return 0;
}