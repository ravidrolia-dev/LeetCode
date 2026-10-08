class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        int idx1 = 0;
        int idx2 = 0;
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == '('){
                if(st.empty()) {
                    idx1 = i + 1;
                }
                st.push(i);
            }else{
                if(st.size() == 1){
                    idx2 = i;
                }
                st.pop();
            }
            if(st.empty()){
                ans += s.substr(idx1,idx2-idx1);
            }
        }
        return ans;
    }
};