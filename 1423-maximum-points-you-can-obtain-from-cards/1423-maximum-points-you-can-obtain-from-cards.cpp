class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int total = 0;
        for(int i = 0; i < n ; i++){
            total += card[i];
        }
        if(n == k)return total;
        int sum = 0;
        int left = 0;
        int right = 0;
        for(int i = 0 ; i < n - k ; i++){
            sum += card[i];
            right++;
        }
        int minsum = sum;
        while(right < n){
            sum += card[right++];
            sum -= card[left++];
            minsum = min(minsum,sum);
        }
        return total-minsum;

    }
};