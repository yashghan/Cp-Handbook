class Solution {
public:
    int offset = 100000;
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> pref(300002, 0);
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int start = nums[i] - k;
            int end = nums[i] + k;
            
            pref[offset + start]++;
            pref[offset + end + 1]--;  
        }
        
        int ans = pref[0];
        
        for(int i = 1; i < 300002; i++){
            pref[i] += pref[i-1];
            ans = max(ans, pref[i]);
        }
        
        return ans;
    }
};
