/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

/*
通靈找到 permutation 的排序規則：
假如從右邊從 0 開始到 i，目標是要讓所有 num[i] >= num[i-1]。假如已達到，就
reverse 整個 array

因此從右邊開始找到第一組 num[i] < num[i-1]
然後從 range[i-1, 0] 找到一個 最小並且 > num[i] 的數
(因為 range[i-1, 0] 是降冪排序，所以從最右邊開始找就可以找到最小的。)
假如我們找到 num[j] > num[i]，應該 swap (num[i],num[j])。然後 reverse(i-1,0)。
這樣 num[i-1]，在 range[i, 0] 最大的數）會在最左邊，然後剩下右邊的會是升冪(關鍵)

*/

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    bool ok = false;

    for (auto it_i = nums.rbegin(); it_i != nums.rend(); it_i++) {
      if (it_i != nums.rbegin() && *it_i < *(it_i - 1)) {
        for (auto it_j = nums.rbegin(); it_j != it_i; it_j++) {
          if (*it_j > *it_i) {
            swap(*it_j, *it_i);
            break;
          }
        }
        // reverse range[0, i-1]
        reverse(nums.rbegin(), it_i);
        ok = true;
        break;
      }
    }

    if (!ok) {
      reverse(nums.begin(), nums.end());
    }
  }
};
// @lc code=end
