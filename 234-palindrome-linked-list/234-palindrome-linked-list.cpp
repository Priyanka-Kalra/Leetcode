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
//1.create a new linked list which is reverse of given linked list.Now compare both.TC-O(N),SC-O(N)
//2.reverse from middle and compare  TC-O(N),SC-O(1)


class Solution {
    
    ListNode * reverse(ListNode *head){
        
        ListNode * prev=NULL;
        ListNode * cur=head;
        ListNode * nex;
        while(cur){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        if(!head ||!head->next)return true;
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        
        //middle
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //creating reverse of last second half
        ListNode *temp=slow->next;
        slow->next=NULL;
        ListNode *mid_head=reverse(temp);
        slow=head;
        
        //comparing both halves
        while(slow && mid_head){
            
            if(slow->val!=mid_head->val)return false;
            
            slow=slow->next;
            mid_head=mid_head->next;
            
        }
        return true;
        
    }
};