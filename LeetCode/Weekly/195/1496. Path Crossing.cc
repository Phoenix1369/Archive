typedef pair<int,int> pii;
const map<char,int> pos = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
const pii dir[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
set<pii> seen;

class Solution {
public:
    bool isPathCrossing(string path) {
        seen.clear();
        pii cur{0,0};
        seen.insert(cur);
        for (char c: path) {
            int d = pos.at(c);
            pii nxt = {
                cur.first  + dir[d].first,
                cur.second + dir[d].second
            };
            if (seen.count(nxt)) {
                return true;
            }
            cur = move(nxt);
            seen.insert(cur);
        }
        return false;
    }
};
