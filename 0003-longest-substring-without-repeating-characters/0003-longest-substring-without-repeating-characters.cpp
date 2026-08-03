class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 ; //left
        int r = 0 ; //right
        int maxlen = 0;
        unordered_set<char> seen;
        while(r < s.size()){
            if(seen.count(s[r])){
                seen.erase(s[l]);
                l++;
            }else{
                seen.insert(s[r]);
                r++;
            }
            maxlen = max(maxlen,r-l);
        }
        return maxlen;
    }
};