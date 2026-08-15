class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = 0,rightmax =0,total=0,left = 0 ;
        int right = n-1 ;
        while(left<right){
            if(height[left] <= height[right]){
                if(leftmax > height[left]){
                    total += leftmax - height[left];
                }else leftmax = height[left];
                left++;
            }else{
                if(rightmax > height[right]){
                    total += rightmax - height[right];
                }else rightmax = height[right];
                right--;
            }
        }
        return total;
    }
};