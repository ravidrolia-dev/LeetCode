class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int idx = 0; idx < 32; idx++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] & (1 << idx))
                    cnt++;
            }
            if (cnt % 3 != 0) {
                ans = ans | (1 << idx);
            }
        }
        return ans;
    }
};