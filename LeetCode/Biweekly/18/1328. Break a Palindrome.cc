#define ALL(x) (x).begin(), (x).end()
string P;
int N;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        P = move(palindrome);
        N = P.size();
        int pos = find_non_a();
        if (pos != -1) {
            P[pos] = 'a';
        } else if (N != 1) {
            P[N-1] = 'b';
        } else {
            P = "";
        }
        return P;
    }

private:
    int find_non_a() {
        int N2 = N/2;
        for (int i = 0; i < N2; ++i) {
            if (P[i] != 'a') {
                return i;
            }
        }
        // Skip middle character of odd-length strings
        return -1;
    }
};
