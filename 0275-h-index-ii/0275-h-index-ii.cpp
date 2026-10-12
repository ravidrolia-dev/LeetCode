class Solution {
public:
    int hIndex(vector<int>& citations) {
    int n = citations.size();
    int l = 0;
    int r = n-1;
    int ans = 0;
    while(l <= r){
        int mid = l + (r-l)/2;
        int rem = n-mid;
        if(rem <= citations[mid]){
            ans = rem;
            r = mid-1;
        }else{
            l = mid+1;
        }

    }
    return ans;
    }
};