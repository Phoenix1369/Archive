#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
const int MAXN = 5e4+5;
const int MINV = -1;
vector<pair<int,int>> A[MAXN];

class SnapshotArray {
    int cnt;
    int N;

public:
    SnapshotArray(int length) {
        N = length;
        cnt = 0;
        for (int i = 0; i < N; ++i) {
            A[i].clear();
            A[i].emplace_back(0, 0); // (cnt, val);
        }
    }
    
    void set(int index, int val) {
        if (A[index].back().x == cnt) {
            A[index].back().y = val;
        } else {
            A[index].emplace_back(cnt, val);
        }
    }
    
    int snap() {
        return cnt++;
    }
    
    int get(int index, int snap_id) {
        auto ptr = lower_bound(ALL(A[index]), make_pair(snap_id, MINV));
        if (ptr == A[index].end()) {
            --ptr;
        }
        if ((ptr != A[index].begin()) && (ptr->x > snap_id)) {
            --ptr;
        }
        return ptr->y;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
