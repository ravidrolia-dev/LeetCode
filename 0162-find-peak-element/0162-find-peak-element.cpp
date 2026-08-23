class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start)/2;
        while(start <= end){
            mid = start + (end - start)/2;
            if(mid == 0 && nums[mid] > nums[mid+1])return mid;
            if(mid == n-1 && nums[mid] > nums[mid-1])return mid;
            if( mid != 0 && mid != n-1 &&nums[mid-1]<nums[mid] && nums[mid] > nums[mid +1])return mid;
            if(mid != n-1 && nums[mid + 1] >= nums[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return mid;
    }
};