class Solution {
public:
    int minBitFlips(int start, int goal) {
        string st = dectobin(start);
        string go = dectobin(goal);
        int diff = 0;
        int cnt = 0 ; 
        if(st.size() >= go.size()){
            diff = st.size() - go.size();
            for(int i = 0 ; i < diff ; i++){
                if(st[i] == '1')cnt++;
            }
            for(int i = diff ; i < st.size() ; i++){
                if(st[i] != go[i - diff] )cnt++;
            }
        }else{
            diff = go.size() - st.size();
            for(int i = 0 ; i < diff ; i++){
                if(go[i] == '1')cnt++;
            }
            for(int i = diff ; i < go.size() ; i++){
                if(go[i] != st[i - diff] )cnt++;
            }
        }
        return cnt;
    }
    string dectobin(int n){
        if (n == 0) return "0";
        string ans = "";
        while(n > 0 ){
            ans.push_back((n%2) + '0');
            n = n/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};