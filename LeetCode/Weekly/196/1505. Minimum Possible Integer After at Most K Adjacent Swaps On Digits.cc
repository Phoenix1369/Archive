const int BASE = 10;
vector<queue<int>> D;
vector<bool> used;
string S;
string T;
int K, N;

// struct BinaryIndexedTree;
const int SRC = 1;
vector<int> B;

void add(int x, int val) {
    for (int i = x; i <= N; i += i & -i) {
        B[i] += val;
    }
}

int get(int x) {
    int sum = 0;
    for (int i = x; i >= SRC; i -= i & -i) {
        sum += B[i];
    }
    return sum;
}

class Solution {
public:
    string minInteger(string num, int k) {
        // Prepare
        S = move(num);
        N = S.size();
        K = k;
        S.insert(S.begin(), ' ');
        
        init();
        for (int i = 1; i <= N; ++i) {
            D[S[i]-'0'].push(i);
        }
        for (int i = 1; i <= N; ++i) {
            if (!used[i]) {
                process(i);
            }
        }
        return T;
    }

private:
    void init() {
        B.assign(N+1, 0);
        D.assign(BASE, queue<int>());
        used.assign(N+1, false);
        T.clear();
    }

    void process(int& i) {
        // Greedily swap in smallest digit within distance K of "i".
        bool yes = false;
        int realI = i + get(i);
        for (int j = 0; j < BASE; ++j) {
            if (D[j].empty()) {
                continue;
            }
            int realJ = D[j].front() + get(D[j].front());
            int diff = realJ - realI;
            if (diff <= K) {
                take(D[j].front());
                D[j].pop();
                yes = true;
                K -= diff;
                break;
            }
        }
        if (!yes) {
            take(i);
        } else {
            --i;
        }
    }

    void take(int pos) {
        T.push_back(S[pos]);
        used[pos] = true;
        add(SRC, +1);
        add(pos, -1);
    }
};
