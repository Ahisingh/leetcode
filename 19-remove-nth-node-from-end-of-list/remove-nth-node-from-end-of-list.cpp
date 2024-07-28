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
    // Helper function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Reverse the linked list
        head = reverseList(head);

        // Step 2: Delete the N-th node from the beginning (which was originally N-th from the end)
        if (n == 1) {
            ListNode* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        } else {
            ListNode* current = head;
            for (int i = 1; i < n - 1; i++) {
                current = current->next;
            }
            ListNode* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            delete nodeToDelete;
        }

        // Step 3: Reverse the list again to restore the original order
        head = reverseList(head);

        return head;
    }
};
