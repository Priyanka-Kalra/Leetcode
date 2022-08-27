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

//TC-O(N),SC-O(1)
/*make two pointers slow and fast both initialised to head.now move slow by 1 node and fast by 2 nodes. slow pointer will point to middle when
fast==NULL (IN CASE OF EVEN NUMBER OF NODES)
fast->NEXT==NULL (IN CASE OF ODD NUMBER OF NODES)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode * slow=head;
        ListNode * fast=head;
        
        while(fast && fast->next ){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
};