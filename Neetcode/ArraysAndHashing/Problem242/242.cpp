/*
 * 242. Valid Anagram
 * Link: https://leetcode.com/problems/valid-anagram/
 * Date: 2025-04-14
 * Author: Carson Phillips
 * Category: Arrays & Hashing (NeetCode)
 * Difficulty: Easy
 *
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 * Constraints:
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 */

#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, int> count;

    for (char c : s) count[c]++;
    for (char c : t) count[c]--;

    for (auto it = count.begin(); it != count.end(); ++it) {
        if (it->second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s1 = "anagram";
    string t1 = "nagaram";
    string s2 = "rat";
    string t2 = "car";

    if(isAnagram(s1, t1) && !isAnagram(s2, t2)) {
        cout << "pass";
    } else {
        cout << "fail";
    }
    return 0;
}

/* Solution Explanation:
 * This problem can be solved by sorting both strings and comparing them,
 * but a more optimal and scalable solution uses a single unordered_map.
 * We first count the frequency of each character in string `s`, then
 * subtract the frequency using characters from string `t`.
 *
 * If the strings are anagrams, the resulting frequency map should have
 * all zero values. If any character has a non-zero count, we return false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(k), where k is the number of unique characters
 *
 * Note: Explanation written by Carson Phillips with refinement from ChatGPT.
 */
