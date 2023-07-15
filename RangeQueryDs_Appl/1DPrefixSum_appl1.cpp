class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        cout << n << endl;
        vector<int> left_min(n, 0);
        vector<int> right_max(n, 0);
        left_min[0] = nums[0];
        right_max[n-1] = nums[n-1];
        
        for(int i = 1; i < n; i++){
            left_min[i] = min(left_min[i-1], nums[i]);
            right_max[n-i-1] = max(right_max[n-i], nums[n-i-1]);
        }

        // for(int i = 0; i < n; i++){
        //     cout << "left_min: " << left_min[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < n; i++){
        //     cout << "right_max: " << right_max[i] << " ";
        // }
        // cout << endl;

        for(int j = 1; j < n-1; j++){
            //           i   <     j   &&      j  <  k         
            if(left_min[j-1] < nums[j] && nums[j] < right_max[j+1]){
                return true;
            }
        }
        return false;
    }
};
