class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0 ;
        int r = nums.size();
        int mid = l + (r-l)/2;
        int ans = 0;
        for(int i : nums){
            ans += abs(nums[mid] - i);
        }
        return ans;
    }
};