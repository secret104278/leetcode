#include <string>

using namespace std;


/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {

        // 用 int array 會比用 map 快
        int R2I[128];
        R2I['I'] = 1;
        R2I['V'] = 5;
        R2I['X'] = 10;
        R2I['L'] = 50;
        R2I['C'] = 100;
        R2I['D'] = 500;
        R2I['M'] = 1000;

        int secondLastPosition = s.size()-2;

        int sum = R2I[s.back()];
        for (int i = secondLastPosition; i >= 0; i--) {
            int current = R2I[s.at(i)];
            int last = R2I[s.at(i+1)];

            // 觀察規則
            if (current < last) {
                sum -= current;
            } else {
                sum += current;
            }

            // switch (s.at(i)) {
            //     case 'I':
            //         if (s.at(i+1) == 'V' || s.at(i+1) == 'X') {
            //             sum -= R2I[s.at(i)];
            //             break;
            //         }
            //         sum += R2I[s.at(i)];
            //         break;
            //     case 'X':
            //         if (s.at(i+1) == 'L' || s.at(i+1) == 'C') {
            //             sum -= R2I[s.at(i)];
            //             break;
            //         }
            //         sum += R2I[s.at(i)];
            //         break;
            //     case 'C':
            //         if (s.at(i+1) == 'D' || s.at(i+1) == 'M') {
            //             sum -= R2I[s.at(i)];
            //             break;
            //         }
            //         sum += R2I[s.at(i)];
            //         break;
            //     default:
            //         sum += R2I[s.at(i)];
            //         break;
            // }
        }
        return sum;
    }
};
// @lc code=end

