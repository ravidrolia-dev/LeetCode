class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int  n = nums.size();
        int ans = 0;
        for(int i = 0 ; i <  31 ; i++){
            int ones = 0 ;
            for(int j : nums){
                if((j>>i)&1)ones++;
            }
            int zeroes = n - ones;
            ans += ones*zeroes;
        }
        return ans;
    }
};