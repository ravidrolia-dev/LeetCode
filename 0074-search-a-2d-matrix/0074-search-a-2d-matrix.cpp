class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int start = 0;
        int end = n - 1;
        int mid = start + (end - start) / 2;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (matrix[mid][0] <= target) {
                if (matrix[mid][matrix[mid].size() - 1] >= target) {
                    end = mid;
                }else{
                    start = mid+1;
                }
            } else {
                end = mid - 1;
            }
        }
        int left = 0;
        int right = matrix[start].size() - 1;
        while(left <= right){
            mid = left + ( right - left)/2;
            if(matrix[start][mid] == target)return true;
            if(matrix[start][mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
    }
};