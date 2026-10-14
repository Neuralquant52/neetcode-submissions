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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* lengthCounter = head;
        int length{};
        while (lengthCounter != nullptr){
            length++;
            lengthCounter = lengthCounter->next;
        }

        int N = length - n;
        std::cout << N << '\n';

        if (N == 0) return head->next;
        ListNode* curr = head;

        for (int i{}; i < N-1 ; i++) curr = curr->next;

        if (curr != nullptr && curr->next != nullptr) curr->next = curr->next->next;

        return head;
    }
};
