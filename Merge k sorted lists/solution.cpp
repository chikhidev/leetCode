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

int listLength(ListNode *list) {
    int i = 0;
    ListNode *tmp = list;
    while (tmp) {
        tmp = tmp->next;
        i++;
    }
    return i;
}

void    pushNode(ListNode **list, int value) {
    ListNode *prev = NULL;
    ListNode *tmp = *list;
    ListNode *newNode = new ListNode(value);

    if (!*list) {
        *list = newNode;
        return ;
    }

    for (; tmp; tmp = tmp->next) {
        if (!prev && value < (*list)->val) {
            newNode->next = *list;
            *list = newNode;
            return ;
        } else if (value < tmp->val) {
            prev->next = newNode;
            newNode->next = tmp;
            return ;
        }
        if (!tmp->next) {
            tmp->next = newNode;
            return ;
        }
        prev = tmp;
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        int len = lists.size();
        int longest = 0;
        vector<ListNode*> currentShunk(len);

        for (int i = 0; i < len; i++) {
            currentShunk[i] = lists[i];
            int currentLength = listLength(lists[i]);
            if (currentLength > longest) {
                longest = currentLength;
            }
        }

        while (longest > 0) {
            for (int i = 0; i < len; i++) {
                if (!currentShunk[i]) {
                    continue;
                }
                std::cout << currentShunk[i]->val << std::endl;
                pushNode(&head, currentShunk[i]->val);
                ListNode *next = currentShunk[i]->next;
                delete currentShunk[i];
                currentShunk[i] = next;
            }
            longest--;
        }
        return head;
    }
};