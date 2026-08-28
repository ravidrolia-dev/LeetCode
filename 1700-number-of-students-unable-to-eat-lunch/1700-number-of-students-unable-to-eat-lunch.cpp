class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        for(int i = 0 ; i < students.size() ; i++){
            q.push(students[i]);
            st.push(sandwiches[students.size() - 1 - i]);
        }
        int rotations = 0;

        while(!q.empty() && rotations < q.size()) {
            if(q.front() == st.top()) {
                q.pop();
                st.pop();
                rotations = 0;
            }
            else {
                q.push(q.front());
                q.pop();
                rotations++;
            }
        }

        return q.size();
    }
};