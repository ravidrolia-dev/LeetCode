class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = findmax(piles);
        while(left <= right){
            int mid = left + (right - left)/2;
            if(findhour(piles,mid) > h){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
    int findmax(const vector<int>&arr){
        int maxi = INT_MIN;
        for(int i = 0 ; i < arr.size() ; i++){
            maxi = max(maxi , arr[i]);
        }
        return maxi;
    }
    long long findhour(const vector<int> &arr, int k){
        long long hour = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i]%k == 0){
                hour += arr[i]/k;
            }else{
                hour += arr[i]/k + 1;
            }
        }
        return hour;
    }
};