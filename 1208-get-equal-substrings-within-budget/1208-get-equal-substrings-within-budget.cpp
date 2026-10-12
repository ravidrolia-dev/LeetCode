class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        int n = s.size();
        int ans = 0;
        int windowcost = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            windowcost += abs(s[r] - t[r]);
            while (windowcost > maxcost) {
                windowcost -= abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans,r - l + 1);
        }
        return ans;
    }
};