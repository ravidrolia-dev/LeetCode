class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0 ; //left
        int r = 0 ; //right
        int maxfruits = 0;
        unordered_map<int,int> basket;
        while(r < fruits.size()){
            basket[fruits[r]]++;
            while(basket.size() > 2){
                basket[fruits[l]]--;
                if(basket[fruits[l]] == 0){
                    basket.erase(fruits[l]);
                }
                l++;
            }
            maxfruits = max(maxfruits, r-l+1);
            r++;
        }
        return maxfruits;
    }
};