// Last updated: 10/12/2026, 9:51:20 PM
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
    int pairSum(ListNode* head) {
        vector<int> v;
        while(head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        int sum =0 ;
        for(int i =0 ; i< v.size()/2 ; i++){
            sum = max(v[i] + v[v.size() - i -1] , sum);
        }
        return sum;
    }
};