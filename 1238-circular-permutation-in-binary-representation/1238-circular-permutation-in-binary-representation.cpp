class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(1<<n,0);
        int k = 0;
        for(int i = 0 ; i < (1<<n) ; i++){
            ans[i] = i^(i>>1);
            if(ans[i] == start){
                k = i;
            }
        }
        reverse(ans.begin() , ans.begin()+k);
        reverse(ans.begin()+k , ans.end());
        reverse(ans.begin() , ans.end());
        return ans;
    }
};