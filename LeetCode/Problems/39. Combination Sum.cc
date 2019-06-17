class Solution {
    vector<int> cand;
    vector<int> current;
    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        cand = move(candidates);
        dfs(0, target);
        return res;
    }

private:
    void dfs(int pos, int sum) {
        if (sum == 0) {
            res.push_back(current);
            return;
        }
        if ((sum < 0) || (pos >= cand.size())) {
            return;
        }
        // Case #1: Skip
        dfs(pos + 1, sum);

        // Case #2: Take
        current.push_back(cand[pos]);
        dfs(pos, sum - cand[pos]);
        current.pop_back();
    }
};
