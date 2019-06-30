const int MAXP = 1005;
int arr[MAXP];

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for (int i = 0; i < MAXP; ++i) {
            arr[i] = 0;
        }
        for (auto trip: trips) {
            arr[trip[1]] += trip[0];
            arr[trip[2]] -= trip[0];
        }
        for (int i = 0; i < MAXP; ++i) {
            if (i) arr[i] += arr[i-1];
            if (arr[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};
