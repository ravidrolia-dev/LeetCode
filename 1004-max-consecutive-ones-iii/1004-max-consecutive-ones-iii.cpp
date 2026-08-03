class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 ; //left
        int r = 0 ; //right
        int maxones = 0 ; 
        int count = 0 ;
        while(r < nums.size()){
            if(nums[r] == 0){
                count++;
            }    
            while(count > k){
                if(nums[l] == 0 ){
                    count--;
                }
                l++;
            }
            maxones = max(maxones,r - l + 1);
            r++;
        }
        return maxones;
    }
};