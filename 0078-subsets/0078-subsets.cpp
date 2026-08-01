class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;
        powersubset(nums,ans,0,allsubsets);
        return allsubsets;
    }
    void powersubset(vector<int>& nums , vector<int>&ans , int n,vector<vector<int>> &allsubsets){
        if(n == nums.size()){
            allsubsets.push_back({ans});
            return;
        }
        ans.push_back(nums[n]);
        powersubset(nums,ans,n+1,allsubsets);
        ans.pop_back();
        powersubset(nums,ans,n+1,allsubsets);
    }
};