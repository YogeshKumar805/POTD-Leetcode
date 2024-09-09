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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);


        int top = 0, left = 0;
        int bottom = m-1, right = n-1;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        while(head){
            // Right
            for(int i = left; i <= right && head; i++){
                ans[top][i] = head -> val;
                head = head -> next;
            }
            top++;

            //Bottom
            for(int i = top; i <= bottom && head; i++){
                ans[i][right] = head -> val;
                head = head -> next;
            }
            right--;

            // Left
            for(int i = right; i >= left && head; i--){
                ans[bottom][i] = head -> val;
                head = head -> next;
            }
            bottom--;

            //Up
            for(int i = bottom; i >= top && head; i--){
                ans[i][left] = head -> val;
                head = head -> next; 
            }
            left++;
        }

        return ans;
    }
};
