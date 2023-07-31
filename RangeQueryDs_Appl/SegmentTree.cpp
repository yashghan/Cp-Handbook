class Solution {
private:
    vector<int> seg;

    void build(int index, int start, int end) {
        if (start == end) {
            seg[index] = 1;
            return;
        }
        int mid = (start + end) / 2;
        build(2 * index, start, mid);
        build(2 * index + 1, mid + 1, end);
        seg[index] = seg[2 * index] + seg[2 * index + 1];
    }

    int query(int index, int start, int end, int left, int right) {
        if (left > right) return 0;
        if (right < start || left > end) return 0;
        if (left <= start && end <= right) return seg[index];
        int mid = (start + end) / 2;
        int l = query(index * 2, start, mid, left, right);
        int r = query(index * 2 + 1, mid + 1, end, left, right);
        return l + r;
    }

    void update(int index, int start, int end, int pos) {
        if (pos < start || pos > end) return;
        if (pos == start && pos == end) {
            seg[index] = 0;
            return;
        }
        int mid = (start + end) / 2;
        update(index * 2, start, mid, pos);
        update(index * 2 + 1, mid + 1, end, pos);
        seg[index] = seg[2 * index] + seg[2 * index + 1];
    }

public:
    long functionLogic() {
        //
        
    }
};
