class Solution {
    set<string> unique;
public:
    int numUniqueEmails(vector<string>& emails) {
        unique.clear();
        for (string& em: emails) {
            size_t pos = em.find('@');

            string res{};
            for (size_t i = 0; i < pos; ++i) {
                if (em[i] == '+') {
                    break;
                } else if (em[i] != '.') {
                    res += em[i];
                }
            }
            res += em.substr(pos);
            unique.insert(res);
        }
        return unique.size();
    }
};
