const int MAXA = 26;
typedef bitset<MAXA> bts;
vector<bts> A;
int N, ret;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        A.clear();
        for (auto& s: arr) {
            bts cur;
            for (char c: s) {
                cur.set(c - 'a');
            }
            if (cur.count() == s.size()) {
                A.push_back(cur);
            }
        }
        N = A.size();
        ret = 0;
        bts src;
        dfs(src, 0);
        return ret;
    }

private:
    void dfs(bts& cur, int pos) {
        if (pos >= N) {
            int val = cur.count();
            ret = max(val, ret);
            return;
        }
        if ((cur & A[pos]).none()) {
            cur |= A[pos];
            dfs(cur, pos + 1);
            cur &= ~A[pos];
        }
        dfs(cur, pos + 1);
    }
};

/*
["un","iq","ue"]
["cha","r","act","ers"]
["abcdefghijklmnopqrstuvwxyz"]
>> 4
>> 6
>> 26
*/
