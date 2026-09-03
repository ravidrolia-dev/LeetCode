class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mapp;
        for(int i = 0 ; i < nums.size() ; i++){
            int comp = target - nums[i];
            if(mapp.count(comp)){
                return {mapp[comp],i};
            }
            mapp[nums[i]] = i; 

        }
        return {};
    }
};