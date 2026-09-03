class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n,0);
        for(int i = 0 ; i < n ; i++){
            for(char ch : words[i]){
                mask[i] |= (1<<(ch - 'a'));
            }
        }
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if((mask[i] & mask[j]) == 0){
                    int l1 = words[i].size();
                    int l2 = words[j].size();
                    maxi = max(maxi , l1*l2);
                }
            }
        }
        return maxi;
    }
};