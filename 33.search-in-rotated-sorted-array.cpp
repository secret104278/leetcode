#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    if (nums.size() == 1)
      if (*nums.begin() == target)
        return 0;
      else
        return -1;

    int pivot = 0;

    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      cout << nums.at(mid) << ' ' << nums.at(right) << endl;
      if (mid == left) {
        if (nums.at(mid) > nums.at(right)) {
          pivot = mid;
        } else {
          pivot = right;
        }
        break;
      }

      if (nums.at(left) > nums.at(mid)) {
        right = mid;
      } else if (nums.at(mid) > nums.at(right)) {
        left = mid;
      } else {
        break;
      }
    }

    cout << pivot << endl;

    vector<int> origin_nums = vector<int>();
    origin_nums.insert(origin_nums.end(), nums.end() - pivot, nums.end());
    origin_nums.insert(origin_nums.end(), nums.begin(),
                       nums.begin() + nums.size() - pivot);

    left = 0;
    right = origin_nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (origin_nums.at(mid) == target) {
        if (mid - pivot < 0) {
          return mid - pivot + origin_nums.size();
        } else {
          return mid - pivot;
        }

      } else if (target > origin_nums.at(mid)) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return -1;
  }
};

// @lc code=end

int main() {
  Solution s = Solution();
  //   vector<int> nums = {3, 5, 1};
  //   cout << s.search(nums, 5);

  vector<int> nums = {1, 3};
  cout << s.search(nums, 1);
}
