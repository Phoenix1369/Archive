typedef long long lld;
const int MAXR = 1<<16;
const int MAXP = 65;
lld dp[MAXP][MAXR]; // Using first [i] people, make skill set [j]
int sz[MAXP][MAXR];

map<string,int> id;
vector<int> ppl, ret;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        id.clear();
        ppl.clear();
        int R = req_skills.size();
        int L = 1 << R;
        int P = people.size();
        
        for (int i = 0; i < R; ++i) {
            id[req_skills[i]] = i;
        }
        ppl.reserve(P + 1);
        ppl.push_back(0);
        for (int i = 0; i < P; ++i) {
            int skills = 0;
            for (auto s: people[i]) {
                skills |= 1<<id[s];
            }
            ppl.push_back(skills);
        }

        for (int i = 0; i <= P; ++i) {
            for (int j = 0; j < L; ++j) {
                dp[i][j] = 0;
                sz[i][j] = P + 1;
            }
        }
        dp[0][0] = sz[0][0] = 0;
        for (int i = 1; i <= P; ++i) {
            dp[i][ppl[i]] = 1LL<<(i-1);
            sz[i][ppl[i]] = 1;
            for (int bit = 0; bit < i; ++bit) {
                for (int sset = 0; sset < L; ++sset) {
                    int nset = sset | ppl[i];
                    if (nset == sset) {
                        if (!sz[i][sset] || (sz[i][sset] > sz[bit][sset])) {
                            dp[i][sset] = dp[bit][sset];
                            sz[i][sset] = sz[bit][sset];
                        }
                    } else {
                        if (!sz[i][nset] || (sz[i][nset] > sz[bit][sset] + 1)) {
                            dp[i][nset] = dp[bit][sset] | dp[i][ppl[i]];
                            sz[i][nset] = sz[bit][sset] + 1;
                        }
                    }
                }
            }
        }

        ret.clear();
        for (int i = 0; i < P; ++i) {
            if ((dp[P][L-1] >> i) & 1) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
