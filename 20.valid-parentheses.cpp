#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> cache;
        for (char &c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    cache.push(c);
                    break;

                case ')':
                case ']':
                case '}':
                    if (cache.size() == 0) return false;

                    switch (cache.top()) {
                        case '(': if (c != ')') return false; break;
                        case '[': if (c != ']') return false; break;
                        case '{': if (c != '}') return false; break;
                    }
                    cache.pop();
                    break;

                default: // Invalid char
                    return false;
            }
        }

        if (cache.size() != 0) return false;

        return true;
    }
};
// @lc code=end

int main() {
    cout << Solution().isValid("()") << endl;
}