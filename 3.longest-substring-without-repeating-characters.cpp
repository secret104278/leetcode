/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <string>
#include <unordered_map>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    // ANS1: two pointers with advance fine tune
    // * substring 一定有開始和終點，所以可以用 two pointer 去想, one for substring 起點， another for substring 終點
    // * 用 HashMap 紀錄 char 是否已經在 substring 出現過
    // * 當 s[i,j] 沒有 reapeating，而 s[i,j+1] 有
    // -> BAD: 從 s[i+1, i+1] 開始找
    // -> GOOD: 在 s[i,j] 之中一定並且只有唯一一個字是等於 s[j+1] 的，如果知道那個字的 index(k) ，就可以直接從 s[k+1, j+1] 開始找

    // Q1: 如何知道和 s[j+1] 重複的字是在 i ~ k 的哪一個位置出現？
    // Q2: 當切換成 s[k+1, j+1] 時，如何將 s[i, k] 出現過的紀錄移除？
    // A: 用 HashMap 紀錄 char --> index，Q1 可以直接從 map 中查到位置。
    //    Q2 因為 substring 從 k+1 的位置開始檢查，所以當 map 中查到的位置 < k+1 的話，就代表這個紀錄不算數。

    // int lengthOfLongestSubstring(string s) {
    //     unordered_map<char, int> charIndexMap;
    //     int maxLen = 0;
    //     int i = 0;

    //     for (int j = i; j < s.length(); j++) {
    //         const char c = s[j];
    //         if (charIndexMap.find(c) != charIndexMap.end()) {
    //             const int repeatingIdx = charIndexMap[c];    
    //             if (repeatingIdx >= i) {
    //                 i = repeatingIdx + 1;
    //             }
    //         }

    //         charIndexMap[c] = j;
    //         maxLen = max(maxLen, j-i+1);
    //     }

    //     return maxLen;
    // }

    // ANS2: two pointers with simple sliding windows
    int lengthOfLongestSubstring(string s) {
        set<char> charExistSet;
        int i = 0, j = 0;
        int maxLen = 0;

        while (i < s.length() && j < s.length()) {
            if (charExistSet.count(s[j]) == 0) {
                charExistSet.insert(s[j]);
                maxLen = max(maxLen, j-i+1);
                j++;
            } else {
                charExistSet.erase(s[i]);
                i++;
            }
        }

        return maxLen;
    }
};
// @lc code=end

