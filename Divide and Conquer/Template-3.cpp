class Solution {
private:
    vector<int> less;
    vector<int> greater;

public:
    long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> map(n); // map from nums2 to index
        for (int i = 0; i < n; i++) {
            map[nums2[i]] = i;
        }
        vector<int> index(n); // index array representing positions of nums1 values in nums2
        for (int i = 0; i < n; i++) {
            index[i] = map[nums1[i]];
        }
        less.resize(n);
        greater.resize(n);
        mergesort(index, 0, index.size());
        long answer = 0L;
        for (int i = 0; i < n; i++) {
            answer += 1L * less[i] * greater[i];
        }
        return answer;
    }

    void mergesort(vector<int>& arr, int lo, int hi) {
        if (lo + 1 >= hi) {
            return;
        }
        int n = arr.size();
        int mid = lo + (hi - lo) / 2;
        mergesort(arr, lo, mid);
        mergesort(arr, mid, hi);
        merge(arr, lo, mid, hi);
    }

    void merge(vector<int>& arr, int lo, int mid, int hi) {
        int n = hi - lo;
        vector<int> tmp(n);
        int id = 0;
        int i = lo, j = mid;
        while (i < mid && j < hi) {
            if (arr[i] < arr[j]) {
                tmp[id] = arr[i];
                greater[arr[i]] += (hi - j);
                i++;
            }
            else if (arr[i] > arr[j]) {
                tmp[id] = arr[j];
                less[arr[j]] += (i - lo);
                j++;
            }
            id++;
        }
        while (i < mid) {
            tmp[id] = arr[i];
            greater[arr[i]] += (hi - j);
            i++;
            id++;
        }
        while (j < hi) {
            tmp[id] = arr[j];
            less[arr[j]] += (i - lo);
            j++;
            id++;
        }
        copy(tmp.begin(), tmp.end(), arr.begin() + lo);
    }
};


// For sorting in descending order 

class Solution {
private:
    void merge(vector<int>& count, vector<pair<int, int>> &v, int lo, int mid, int hi) {
        int sz = hi - lo;
        vector<pair<int, int>> temp(sz);
        int id = 0;
        int i = lo, j = mid;

        while (i < mid && j < hi) {
            if (v[i].first <= v[j].first) {
                temp[id] = v[j];
                id++;
                j++;
            } 
            else {
                count[v[i].second] += hi - j;
                temp[id] = v[i];
                id++;
                i++;    
            }
        }

        while (i < mid) {
            temp[id] = v[i];
            i++;
            id++;
        }

        while (j < hi) {
            temp[id] = v[j];
            j++;
            id++;
        }

        for (int k = 0; k < temp.size(); k++) {
            v[lo + k] = temp[k];
        }
    }

private:
    void mergesort(vector<int>& count, vector<pair<int, int>> &v, int lo, int hi) {
        if (lo + 1 >= hi) {
            return;
        }
        // int n = arr.size();
        int mid = lo + (hi - lo) / 2;
        mergesort(count, v, lo, mid);
        mergesort(count, v, mid, hi);
        merge(count, v, lo, mid, hi);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)   
            v[i] = make_pair(nums[i], i);

        mergesort(count, v, 0, n);

        return count;
    }
};



