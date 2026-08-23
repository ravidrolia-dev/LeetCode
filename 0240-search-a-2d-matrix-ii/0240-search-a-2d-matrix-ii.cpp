class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++){
            if(check(matrix[i],target))return true;
        }
        return false;
    }
    bool check(vector<int> & matrix,int target){
        int left = 0;
        int right = matrix.size() - 1;
        while(left <= right){
            int mid = left + ( right - left)/2;
            if(matrix[mid] == target)return true;
            if(matrix[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }
};