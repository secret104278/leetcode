/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

#include <vector>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    // SOL1: Priority Queue
    // vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    //     // pair <x_position, heigh>
    //     // order is important!! pair Comp will sort by first then second
    //     multiset<pair<int, int>> critical_p;
    //     vector<vector<int>> result;
    //     multiset<int> pq = {0};
    //     int prev = 0;

    //     for (auto build: buildings) {
    //         critical_p.emplace(make_pair(build[0], -build[2]));
    //         critical_p.emplace(make_pair(build[1], build[2]));
    //     }

    //     for (auto p: critical_p) {
    //         if (p.second < 0) pq.emplace(-p.second);
    //         else pq.erase(pq.find(p.second));

    //         int cur = *pq.rbegin();
    //         if (cur != prev) {
    //             result.push_back(vector<int>{p.first, cur});
    //             prev = cur;
    //         }
    //     }

    //     return result;
    // }

    // SOL2: Divide & Conquer
    // vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    //     if buildings.size

    //     int m = buildings.size() / 2;

    //     auto first = vector<vector<int>>(buildings.begin(), buildings.begin()+m);
    //     auto second = vector<vector<int>>(buildings.begin() + m, buildings.end());
    //     return merge(first, second);
    // }

    // vector<vector<int>> merge(vector<vector<int>>& fist, vector<vector<int>>& second) {
    //     return {};
    // }

};
// @lc code=end
