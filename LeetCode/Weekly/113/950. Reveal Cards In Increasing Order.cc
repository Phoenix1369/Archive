#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(ALL(deck), greater<int>());
        deque<int> D;
        for (int x: deck) {
            if (!D.empty()) {
                D.push_front(D.back());
                D.pop_back();
            }
            D.push_front(x);
        }
        return vector<int>(ALL(D));
    }
};
