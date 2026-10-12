// Last updated: 10/12/2026, 9:56:58 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        
        // 1. Check if there are at least k nodes left to reverse
        while (count < k) {
            if (temp == nullptr) {
                return head; // Less than k nodes left, don't reverse
            }
            temp = temp->next;
            count++;
        }

        // 2. Recursively reverse the remaining nodes
        // 'temp' currently points to the (k+1)-th node
        ListNode* prevnode = reverseKGroup(temp, k);

        // 3. Reverse the current group of k nodes
        temp = head;
        count = 0;
        while (count < k) {
            ListNode* next = temp->next;
            temp->next = prevnode; // Point to the reversed rest of the list
            
            prevnode = temp;
            temp = next;
            count++;
        }
        
        // 4. prevnode is the new head of this reversed group
        return prevnode;
    }
};
