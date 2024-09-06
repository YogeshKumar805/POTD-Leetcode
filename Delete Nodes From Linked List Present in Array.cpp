class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Convert the array `nums` into a set for fast lookup of values to be removed.
        set<int> st(nums.begin(), nums.end());

        // Initialize a pointer `curr` to traverse the linked list.
        ListNode* curr = head;
        
        // Traverse the list to find the first node whose value is NOT in the set.
        // This node will be the new head of the modified linked list.
        while(curr) {
            if(st.count(curr->val)) { 
                // If the current node's value is in the set, skip this node.
                curr = curr->next;
            }
            else break; // Stop when we find a node whose value is NOT in the set.
        }

        // The first valid node becomes the new head of the modified list.
        ListNode* newHead = curr;

        // Traverse the rest of the linked list and remove nodes whose values exist in the set.
        while(curr && curr->next) { 
            if(st.count(curr->next->val)) {
                // If the next node's value is in the set, skip the next node by adjusting pointers.
                curr->next = curr->next->next;
            } 
            else {
                // Move to the next node if it's not in the set.
                curr = curr->next;
            }
        }

        // Return the new head of the modified linked list.
        return newHead;
    }
};
