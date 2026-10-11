class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())return {};
        unordered_map<char,int> mp;
        for(char c : p){
            mp[c]++;
        }
        int l = 0;
        unordered_map<char,int> mp1;
        vector<int> ans;
        for(int r = 0 ; r < s.size() ; r++){
            mp1[s[r]]++;
            if(r-l+1 > p.size()){
                mp1[s[l]]--;
                if(mp1[s[l]] == 0){
                    mp1.erase(s[l]);
                }
                l++;
            }
            if(mp == mp1){
                ans.push_back(l);
            }
        }
        return ans;
    }
};