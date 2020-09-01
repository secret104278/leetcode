/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
private:

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        static const vector<string> v = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> tmp = letterCombinations(digits.substr(1));
        if (tmp.size() == 0 ) {
            tmp.push_back("");
        }

        vector<string> ans = vector<string>();
        for (const char c : v[digits[0] - '0']) {
            for (string str : tmp) {
                ans.push_back(c + str);
            }
        }
        return ans;
    }
};
// @lc code=end

