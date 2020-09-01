/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

/*

isPalin[i, j] = true
-> s[i] == s[j] && isPalin[i+1, j-1] = true

Base Case1: isPalin[i, i] = true
Base Case2: isPalin[i, i+1] = s[i] == s[i+1]

*/

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int strLen = s.length();
        bool isPalin[strLen][strLen];

        for (int i = 0; i < strLen; i++) {
            // Base Case1
            isPalin[i, i] = true;
        }
    }
};
// @lc code=end

