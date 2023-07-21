class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the first element >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};


// OR 

class Solution {
private:
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = (r-l)/2+l;
            if (nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            }
            else {
                int idx = lower_bound(sub, x); // Find the index of the first element >= x
                sub[idx] = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};
