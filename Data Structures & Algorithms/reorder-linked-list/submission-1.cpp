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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr){
            if (fast->next == nullptr) break;
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr != nullptr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // while (prev != nullptr){
        //     std::cout << prev->val << '\n';
        //     prev = prev->next;
        // }

        while (head != nullptr){
            ListNode* nxt = head->next;
            ListNode* nxt_prev = prev->next;

            if (prev != nullptr) head->next = prev, head = head->next, prev = nxt_prev;
            head->next = nxt;
            head = head->next;
        }
    }
};
