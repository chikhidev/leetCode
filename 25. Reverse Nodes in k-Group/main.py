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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        int counter = k - 1;
        vector<ListNode*> queue;
        size_t queue_curs = 0;
        bool head_set = false;
        ListNode* last_indec = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = (queue_curs == 0) ? NULL : queue[queue_curs - 1];
            queue.push_back(curr);
            queue_curs++;

            if (counter == 0) {
                if (!head_set) {
                    head = queue[queue_curs - 1];
                    head_set = true;
                }
                if (last_indec) {
                    last_indec->next = queue[queue_curs - 1];
                }
                last_indec = queue[0];
                queue[0]->next = next;
                queue.clear();
                queue_curs = 0;
                counter = k - 1;
            } else {
                counter--;
            }
            curr = next;
        }

        if (queue_curs != 0) {
            for (size_t i = 0; i < queue_curs; i++) {
                if (last_indec && i == 0) {
                    last_indec->next = queue[0];
                }
                if (i == (queue_curs - 1))
                    queue[i]->next = NULL;
                else
                    queue[i]->next = queue[i + 1];
            }
        }

        return head;
    }
};
