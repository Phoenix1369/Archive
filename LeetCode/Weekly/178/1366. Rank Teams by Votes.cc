const int MAXA = 26;
int cnt[MAXA][MAXA];
char  S[MAXA+5];
bool used[MAXA];
int N;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        N = votes[0].size();
        init();
        for (auto vote: votes) {
            for (int i = 0; i < N; ++i) {
                ++cnt[i][vote[i]-'A'];
            }
        }
        for (int i = 0; i < N; ++i) {
            int k = best(i);
            used[k] = true;
            S[i] = 'A' + k;
        }
        S[N] = '\0';
        return S;
    }

private:
    int best(int pos) {
        list<int> run;
        for (int j = 0; j < MAXA; ++j) {
            if (!used[j]) run.push_back(j);
        }
        for (int i = 0; (run.size() > 1u) && (i < MAXA); ++i) {
            int top = 0;
            for (int j: run) {
                top = max(cnt[i][j], top);
            }
            for (auto jtr = run.begin(); jtr != run.end(); ) {
                if (cnt[i][*jtr] < top) {
                    jtr = run.erase(jtr);
                } else {
                    ++jtr;
                }
            }
        }
        return run.front();
    }
    
    void init() {
        for (int i = 0; i < MAXA; ++i) {
            for (int j = 0; j < MAXA; ++j) {
                cnt[i][j] = 0;
            }
            used[i] = false;
        }
    }
};
