class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xors(n+1 , 0);
        for(int i = 0 ; i < n ; i++){
            xors[i+1] = xors[i]^arr[i];
        }
        vector<int> ans;
        for(int i = 0 ; i < queries.size() ; i++){
            ans.push_back(xors[queries[i][1]+1]^xors[queries[i][0]]);
        }
        return ans;
    }
};