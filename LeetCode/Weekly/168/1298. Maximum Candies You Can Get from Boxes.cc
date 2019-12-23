class Solution {
public:
    int maxCandies(
        vector<int>& status,    // (unlocked)
        vector<int>& candies,
        vector<vector<int>>& keys,
        vector<vector<int>>& containedBoxes,
        vector<int>& initialBoxes
    ) {
        // Only process a box once: obtained + unlocked.
        int N = status.size();
        vector<bool> has(N, 0);  // (obtained)
        vector<bool> seen(N, 0); // (inQueue)
        for (int box: initialBoxes) {
            has[box] = true;
        }
        int ret = 0;
        queue<int> Q;
        for (int box: initialBoxes) {
            if (has[box] && status[box] && !seen[box]) {
                ret += candies[box];
                seen[box] = true;
                Q.push(box);
            }
        }
        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (int box: containedBoxes[cur]) {
                has[box] = true;
            }
            for (int box: keys[cur]) {
                status[box] = true;
            }
            for (int box = 0; box < N; ++box) {
                if (has[box] && status[box] && !seen[box]) {
                    ret += candies[box];
                    seen[box] = true;
                    Q.push(box);
                }
            }
        }
        return ret;
    }
};

/*
[1,0,1,0]
[7,5,4,100]
[[],[],[1],[]]
[[1,2],[3],[],[]]
[0]
[1,0,0,0,0,0]
[1,1,1,1,1,1]
[[1,2,3,4,5],[],[],[],[],[]]
[[1,2,3,4,5],[],[],[],[],[]]
[0]
[1,1,1]
[100,1,100]
[[],[0,2],[]]
[[],[],[]]
[1]
[1]
[100]
[[]]
[[]]
[]
[1,1,1]
[2,3,2]
[[],[],[]]
[[],[],[]]
[2,1,0]
>> 16
>> 6
>> 1
>> 0
>> 7
*/
