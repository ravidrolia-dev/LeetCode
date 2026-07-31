class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ind;
        for(int i = 0;i< nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                int sum = nums[i]+nums[j];
                if (sum == target){
                    ind.push_back(i);
                    ind.emplace_back(j);
                }
            }
        }
        for(auto it :ind){
            cout<<it<<" ";
        }
    return ind;}
};