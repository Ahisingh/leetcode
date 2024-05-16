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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* merged = new ListNode();
        // Use a temporary pointer to keep track of the last node in the merged list.
        ListNode* temp = merged;

        // Check if either of the linked lists is empty.
        if (l1 == NULL) {
            return l2;
        }

        if (l2 == NULL) {
            return l1;
        }

        // Iterate through both linked lists until either of them becomes empty.
        while (l1 != NULL && l2 != NULL) {
            // Compare the values of the current nodes in l1 and l2.
            if (l1->val < l2->val) {
                // Append the smaller value to the merged list, move l1 to the next node.
                temp->next = l1;
                l1 = l1->next;
            } else {
                // Append the smaller or equal value to the merged list, move l2 to the next node.
                temp->next = l2;
                l2 = l2->next;
            }

            // Move temp pointer one step forward.
            temp = temp->next;
        }

        // Check if there are remaining nodes in either l1 or l2. If yes, append them to the merged list.
        if (l1 == NULL) {
            temp->next = l2;
        } else {
            temp->next = l1;
        }

        // Return the merged list, excluding the dummy node.
        return merged->next;
    }
};