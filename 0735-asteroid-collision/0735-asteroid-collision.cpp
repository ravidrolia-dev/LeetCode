class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for(int i = 0 ; i < ast.size() ; i++){
            bool alive = true;
            while(!st.empty()){
                if(st.top() > 0 && ast[i] < 0 ){
                    if(abs(st.top()) == abs(ast[i])){
                        alive = false;
                        st.pop();
                        break;
                    }else if(abs(st.top()) > abs(ast[i])){
                        alive = false;
                        break;
                    }else{
                        st.pop();
                    }
                }else{
                    break;
                }
            }
            if(alive)st.push(ast[i]);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};