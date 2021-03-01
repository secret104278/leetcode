/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <string>
#include <vector>

using namespace std;

/*
((()))
(()())
(())()
()(())
()()()

DFS
把每個括弧想成是 tree node，value 是 "(" 或 ")"
(())
()()
起始值是 left = n, right = 0
每走到一個 node 可以選擇要放"(" 或 ")"
IF left > 0 && right > 0
=> 放左 result + 放右 result
ELSE IF left > 0
=> 放左 result
ELSE IF right > 0
=> 放右 result
ELSE
=> []

每放一個 "("，left--, right++
每放一個 ")"，right--
*/

// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    if (n == 0) {  // early exist
      return {};
    }

    vector<string> ans = vector<string>();
    dfs(n, 0, "", ans);
    return ans;
  }

  void dfs(int left, int right, string cur, vector<string> &res) {
    if (left == 0 && right == 0) {
      res.push_back(cur);
    }

    vector<string> ans = vector<string>();
    if (left > 0) {
      dfs(left - 1, right + 1, cur + "(", res);  // add "("
    }
    if (right > 0) {
      dfs(left, right - 1, cur + ")", res);  // add ")"
    }
  }
};
// @lc code=end
