class Solution {
public:
    int busyStudent(vector<int>& st, vector<int>& et, int qt) {
        int N = st.size();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            if ((st[i] <= qt) && (qt <= et[i])) ++ret;
        }
        return ret;
    }
};
