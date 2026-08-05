class Solution {
public:
    bool check(vector<int>& nums) {
        for(int x = 0 ; x < nums.size() ; x++){
            vector<int> arr;
            for(int i = 0 ; i < nums.size() ; i++){
                arr.push_back(nums[(i+x)%nums.size()]);
            }
            if(issort(arr)) return 1;   
        }
        return 0;
    }
    bool issort(vector<int> &arr){
        for(int i = 0 ;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]) return 0;
        }
        return 1;
    }
};