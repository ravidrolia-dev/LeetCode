class Solution {
public:
    bool canConstruct(string ran, string mag) {
        if(ran.size() > mag.size())return false;
        unordered_map<char,int> mapp;
        for(int i = 0 ; i <mag.size() ; i++){
            mapp[mag[i]]++;
        }
        for(int i = 0 ; i < ran.size() ; i++){
            if(mapp.count(ran[i])){
                mapp[ran[i]]--;
                if(mapp[ran[i]] == 0){
                    mapp.erase(ran[i]);
                }
            }else{
                return false;
            }
        }
        return true;
    }
};