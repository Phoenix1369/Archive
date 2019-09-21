#define ALL(x) (x).begin(), (x).end()
const int MAXB = 5000;
int N;

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        N = arr.size();
        sort(ALL(arr));
        arr.insert(arr.begin(), 0);
        for (int i = 0; i < N; ++i) {
            arr[i+1] += arr[i];
            if (arr[i+1] > MAXB) {
                return i;
            }
        }
        return N;
    }
};
