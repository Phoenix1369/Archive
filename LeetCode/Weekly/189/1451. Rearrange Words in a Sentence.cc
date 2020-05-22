#define ALL(x) (x).begin(), (x).end()
vector<string> T;
int N;

class Solution {
public:
    string arrangeWords(string text) {
        N = split(text);
        stable_sort(ALL(T), [](const string& lhs, const string& rhs) {
            return lhs.size() < rhs.size();
        });
        upper(T[0][0]);
        for (int i = 1; i < N; ++i) lower(T[i][0]);
        return join();
    }

private:
    // Character
    void lower(char& c) { if (c <= 'Z') c += ' '; }
    void upper(char& c) { if (c >= 'a') c -= ' '; }
    
    // String
    string join() {
        ostringstream oss;
        int N = T.size();
        for (int i = 0; i < N; ++i) {
            if (i) oss << ' ';
            oss << T[i];
        }
        return oss.str();
    }
    
    int split(string& s) {
        istringstream iss{s};
        T.clear();
        while (iss >> s) {
            T.push_back(s);
        }
        return T.size();
    }
};
