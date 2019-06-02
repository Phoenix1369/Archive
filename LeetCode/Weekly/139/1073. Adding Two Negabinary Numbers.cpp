#define ALL(x) (x).begin(), (x).end()
vector<int> res;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(ALL(arr1));
        reverse(ALL(arr2));
        res.clear();

        int n1 = arr1.size();
        int n2 = arr2.size();
        int N = max(n1, n2);
        int N3 = N + 3;
        push_zeroes(arr1, N3);
        push_zeroes(arr2, N3);
        push_zeroes(res, N3);

        for (int i = 0; i < N; ++i) {
            int sum = arr1[i] + arr2[i] + res[i];
            res[i] = sum & 1;
            if (sum >> 1) {
                if (arr1[i+1]) --arr1[i+1];
                else if (arr2[i+1]) --arr2[i+1];
                else if (res[i+1]) --res[i+1];
                else {
                    ++res[i+1];
                    ++res[i+2];
                }
            }
        }
        while (!res.empty() && !res.back()) {
            res.pop_back();
        }
        if (res.empty()) {
            res.push_back(0);
        }
        reverse(ALL(res));
        return res;
    }

private:
    void push_zeroes(vector<int>& vec, unsigned size) {
        vec.reserve(size);
        while (vec.size() < size) {
            vec.push_back(0);
        }
    }
};

