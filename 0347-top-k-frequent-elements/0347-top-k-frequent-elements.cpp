class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        for (int i = 0; i < nums.size(); i++) {
            mapp[nums[i]]++;
        }
        vector<vector<int>> freq;
        for (auto pair : mapp) {
            freq.push_back({pair.first, pair.second});
        }
        sort(freq.begin(), freq.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1]; // ascending by frequency
             });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freq[freq.size() - 1 - i][0]);
        }
        return ans;
    }
};