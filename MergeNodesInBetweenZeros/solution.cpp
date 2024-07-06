/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *lastInPlace = head;
        int merge = 0;

        ListNode* tmp = head;
        while (tmp) {
            if (tmp->val == 0 && merge != 0) {
                lastInPlace->val = merge;
                if (tmp->next) {
                    lastInPlace = lastInPlace->next;
                }
                merge = 0;
            } else {
                merge += tmp->val;
            }
            tmp=tmp->next;
        }
        lastInPlace->next = NULL;

        return head;
    }
};
