class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allsubset;
        vector<int> ans;
        powersubset(nums,ans,0,allsubset);
        return allsubset;
    }
    void powersubset(vector<int> &nums , vector<int> &ans, int n ,vector<vector<int>> &allsubset){
        if(n == nums.size()){
            allsubset.push_back(ans);
            return;
        }
        ans.push_back(nums[n]);
        powersubset(nums,ans,n+1,allsubset);
        int idx = n+1;
        ans.pop_back();
        while(idx< nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        powersubset(nums,ans,idx,allsubset);
    }
};