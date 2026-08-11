class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = 0;
        long long sum = 0;
        int freq = 0;
        while(r < nums.size()){
            sum += nums[r];
            long long diff = (long long)nums[r]*(r-l+1) - sum;
            if(diff > k){
                sum -= nums[l++];
            }
            freq = max(freq,r-l+1);
            r++;
        }
        return freq;
    }
};