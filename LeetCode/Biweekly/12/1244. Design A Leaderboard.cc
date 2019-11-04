const int MAXF = 1005;

class Leaderboard {
    std::unordered_map<int,int> board;

public:
    Leaderboard() {
        board.clear();
        board.reserve(MAXF);
    }

    void addScore(int playerId, int score) {
        board[playerId] += score;
    }

    int top(int K) {
        std::vector<int> scores;
        for (auto itr: board) {
            scores.push_back(itr.second);
        }
        int N = scores.size();
        int M = N - K;
        std::nth_element(scores.begin(), scores.begin() + M, scores.end());
        int sum = 0;
        for (int i = M; i < N; ++i) {
            sum += scores[i];
        }
        return sum;
    }

    void reset(int playerId) {
        board[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
