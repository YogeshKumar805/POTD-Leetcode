class Solution {
public:
    int minimumCost(vector<int>& A) {
        int α = 51, β = 51;

        for (int i = 1; i < A.size(); i++) {
            if (A[i] < β) {
                β = A[i];
                if (β < α)
                    α ^= β, β ^= α, α ^= β;
            }
            if (α == 1 && β == 1) break;
        }

        return A[0] + α + β;
    }
};
