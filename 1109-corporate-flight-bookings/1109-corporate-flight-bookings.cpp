class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+1,0);
        int s = bookings.size();
        for(int i = 0 ; i < s ; i++){
            ans[bookings[i][0]-1] += bookings[i][2];
            ans[bookings[i][1]] -= bookings[i][2];
        }
        int sum = 0;
        for(int i = 0 ; i < n ;i++){
            ans[i] += sum;
            sum = ans[i];
        }
        ans.pop_back();
        return ans;
    }
};