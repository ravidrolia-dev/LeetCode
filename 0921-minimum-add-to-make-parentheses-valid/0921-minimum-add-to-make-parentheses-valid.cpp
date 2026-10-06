class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st1;
        for(int i =0; i<s.length();i++){
            if(s[i] == '(') st1.push(s[i]);
            if(s[i] == ')'){
                if(!st1.empty() && st1.top() == '('){
                    st1.pop();
                }
                else{
                    st1.push(')');
                }
            }
        }
        return st1.size();
    }
};