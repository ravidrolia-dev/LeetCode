class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        int xors = 0;
        for(int i : nums){
            xors ^= i;
        }
        return xors;
    }
};