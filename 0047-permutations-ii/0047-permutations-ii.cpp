class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allperm;
        getperm(nums,0,allperm);
        return allperm;
    }
    void getperm(vector<int>&nums,int idx, vector<vector<int>> &allperm){
        if(idx == nums.size()){
            allperm.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i = idx ; i < nums.size(); i++){
            if(used.count(nums[i])){
                continue;
            }
            used.insert(nums[i]);
            swap(nums[i],nums[idx]);
            getperm(nums,idx + 1,allperm);
            swap(nums[i],nums[idx]);
        }
    }
};