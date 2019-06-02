class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        if (l2 > l1) {
            swap(str1, str2);
            swap(l1, l2);
        }
        if (str2.empty()) {
            return str1;
        }
        int N = min(l1, l2);
        for (int i = 0; i < N; ++i) {
            if (str1[i] != str2[i]) {
                return "";
            }
        }
        if (l1 == l2) {
            return str1;
        }
        str1 = str1.substr(N);
        return gcdOfStrings(str2, str1);
    }
};

