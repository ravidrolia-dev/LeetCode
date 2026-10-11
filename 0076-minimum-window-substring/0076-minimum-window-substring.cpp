class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())return "";
        int m = s.size();
        int n = t.size();
        vector<int> need(128,0);
        vector<int> window(128,0);
        for(int i = 0 ; i < n ; i++){
            need[t[i]-'A']++;
        }
        int l = 0;
        int formed = 0;
        int required = 0;
        for(int i : need){
            if(i>0)required++;
        }
        int minlen = INT_MAX;
        int start = 0;
        for(int r = 0 ; r < m ; r++){
            window[s[r]-'A']++;
            if(need[s[r]-'A'] > 0 && window[s[r]-'A'] == need[s[r]-'A']){
                formed++;
            }
            while(formed == required){
                if(r-l+1 < minlen){
                    minlen =r-l+1;
                    start = l;
                }
                window[s[l]-'A']--;
                if(need[s[l]-'A'] > 0 && window[s[l]-'A'] < need[s[l]-'A']){
                    formed--;
                }
                l++;
            }
        }
        if(minlen == INT_MAX)return "";
        else return s.substr(start,minlen);

    }
};