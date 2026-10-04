class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        vector<int> ch(3,0);
        for(int i = 0 ; i < n ; i++){
            if(bills[i] == 5){
                ch[0]++;
            }
            else if(bills[i] == 10){
                if(ch[0] == 0){
                    return false;
                }
                ch[1]++;
                ch[0]--;
            }
            else{
                if(ch[1] >= 1 && ch[0] >= 1){
                    ch[1]--;
                    ch[0]--;
                }
                else if(ch[0] >= 3){
                    ch[0] = ch[0] - 3;
                }
                else{
                    return false;
                }
                ch[2]++;
            }
        }
        return true;
    }
};