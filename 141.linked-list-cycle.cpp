struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *current = head;
        ListNode *k = new ListNode(-1);

        while (current != nullptr) {
            if (current->next == k) return true;

            ListNode *tmp = current;
            current = current->next;
            tmp->next = k;
        }

        return false;
    }
};
// @lc code=end

