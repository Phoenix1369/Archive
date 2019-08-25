#define ALL(x) (x).begin(), (x).end()
const int AMNT = 1000;
const int DIFF = 60;
const int MAXC = 15;
const int MAXN = 1005;

class Solution {
    bool invalid[MAXN];
    char name[MAXN][MAXC];
    char city[MAXN][MAXC];
    int time[MAXN];
    int N;
    
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        N = transactions.size();
        for (int i = 0; i < N; ++i) {
            int amount;
            sscanf(transactions[i].c_str(), "%[^,],%d,%d,%[^,]",
                   name[i], &time[i], &amount, city[i]);
            if (amount > AMNT) {
                invalid[i] = true;
            }
        }
        vector<string> ret;
        for (int i = 0; i < N; ++i) {
            if (invalid[i] || within_hour(i)) {
                ret.push_back(transactions[i]);
            }
        }
        return ret;
    }

private:
    bool within_hour(int i) {
        for (int j = 0; j < N; ++j) {
            // Same name, different city.
            if (j == i) continue;
            if (strcmp(name[j], name[i]) != 0) continue;
            if (strcmp(city[j], city[i]) == 0) continue;
            if (abs(time[j] - time[i]) <= DIFF) {
                return true;
            }
        }
        return false;
    }
};
