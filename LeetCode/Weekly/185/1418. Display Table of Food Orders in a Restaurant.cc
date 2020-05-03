class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> data;
        map<int, string> tables;
        set<string> items;
        for (auto& row: orders) {
            auto t = row[1];
            auto f = row[2];
            int tn = stoi(t);
            ++data[tn][f];
            tables[tn] = t;
            items.insert(f);
        }
        int N = tables.size();
        vector<vector<string>> ret;
        ret.reserve(N+1);
        vector<string> head = {"Table"};
        for (auto f: items) {
            head.push_back(f);
        }
        ret.push_back(head);
        int M = head.size();
        for (auto t: tables) {
            vector<string> row;
            row.reserve(M);
            row.push_back(t.second);
            for (int i = 1; i < M; ++i) {
                row.push_back(to_string(data[t.first][head[i]]));
            }
            ret.push_back(row);
        }
        return ret;
    }
};
