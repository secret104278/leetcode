#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
#define AlphabetLen 26
#define AlphabetIndex(x) int(x) - 'a'

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;

        int allocatable[AlphabetLen] = {0};
        for (char &c : chars) {
            allocatable[AlphabetIndex(c)] += 1;
        }

        for (string &w : words) {
            int require[AlphabetLen] = {0};
            for (char &c : w) {
                require[AlphabetIndex(c)] += 1;
            }
            
            bool allmeet = true;
            for (int i = 0; i < AlphabetLen; ++i) {
                if (allocatable[i] < require[i]) {
                    allmeet = false;
                    break;
                }
            }

            if (allmeet) {
                result += w.length();
            }
        }

        return result;
    }
};
// @lc code=end

