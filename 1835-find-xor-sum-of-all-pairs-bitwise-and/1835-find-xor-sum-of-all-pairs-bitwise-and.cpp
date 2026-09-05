class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor2 = 0 ;
        int n1 = arr1.size();
        int n2 = arr2.size();
        for(int i : arr2){
            xor2 ^= i;
        }
        int ans = 0 ; 
        for(int i = 0 ; i < n1 ; i++){
            ans ^= (arr1[i]&xor2);
        }
        return ans;
    }
};