typedef pair<char,int> pii;
vector<pii> A;
int K, N;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        N = s.size();
        K = k;
        A.clear();
        
        int head = 0;
        while (head < N) {
            int tail = head;
            while ((tail < N) && (s[tail] == s[head])) ++tail;
            int cnt = tail - head;
            
            while (!A.empty() && A.back().first == s[head]) {
                cnt += A.back().second;
                A.pop_back();
            }
            
            cnt %= K;
            if (cnt > 0) {
                A.emplace_back(s[head], cnt);
            }
            
            head = tail;
        }
        
        string ret;
        for (auto data: A) {
            for (int i = 0; i < data.second; ++i) {
                ret.push_back(data.first);
            }
        }
        return ret;
    }
};
