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
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> stack;
        ListNode dummy=ListNode();
        ListNode* tail=&dummy; //Maintain a pointer to the tail 
        ListNode* ptr=NULL;
        for (ListNode* curr=head; curr; curr = curr->next, delete ptr) {
            int x = curr->val;
            ListNode* ptr=curr;
            
            // Monotonic increasing stack
            while (!stack.empty() && (stack.back()<x))
                stack.pop_back();
            stack.push_back(x);
        }
        // Add remaining elements from stack
        for (int val : stack) {
            tail->next = new ListNode(val, NULL);
            tail=tail->next;
        }

        return dummy.next;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
