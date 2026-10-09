class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        for(int i = 0 ; i < n ; i++){
            if(mp.count(nums[i]+1)){
                ans = max(ans,mp[nums[i]]+mp[nums[i]+1]);
            }
        }
        return ans;
    }
};