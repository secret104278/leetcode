#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = i; j < matrix.size(); j++) {
        swap(*((*(matrix.begin() + i)).begin() + j),
             *((*(matrix.begin() + j)).begin() + i));
      }
    }
  }
};
// @lc code=end
