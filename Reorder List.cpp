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
    ListNode* reverse(ListNode* head){
        ListNode*prev=NULL,*next=head;
        while(head){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }

    ListNode* merge(ListNode* h1,ListNode* h2){
        if(h1==NULL)return h2;
        if(h2->next==NULL)return h1;
        h1->next=merge(h2,h1->next);
        return h1;
    }

    ListNode* findmid(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)return;

        ListNode* mid=findmid(head);
        ListNode* head_of_revll=reverse(mid);
        merge(head,head_of_revll);
    }
};
