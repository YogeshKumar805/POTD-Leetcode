class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1 = {nums[0]};
        arr2 = {nums[1]};
        for(int i = 2;i<nums.size();i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }
        for(auto it : arr2){
            arr1.push_back(it);
        }
        return arr1;
    }
};
