class Solution {
    set<string> exact;
    map<string, string> exact_ignore_case, exact_ignore_vowel;

    void init(const vector<string>& wordlist) {
        exact.clear();
        exact_ignore_case.clear();
        exact_ignore_vowel.clear();
        for (const auto& w: wordlist) {
            exact.insert(w);
        }
        for (const auto& w: wordlist) {
            string s = make_ignore_case(w);
            if (!exact_ignore_case.count(s)) {
                exact_ignore_case[s] = w;
            }
        }
        for (const auto& w: wordlist) {
            string s = make_ignore_vowel(w);
            if (!exact_ignore_vowel.count(s)) {
                exact_ignore_vowel[s] = w;
            }
        }
    }

    string make_ignore_case(string s) {
        for (char& c: s) {
            c = tolower(c);
        }
        return s;
    }

    const string VOWEL = "aeiou";
    string make_ignore_vowel(string s) {
        for (char& c: s) {
            c = tolower(c);
            if (VOWEL.find(c) != string::npos) {
                c = 'a';
            }
        }
        return s;
    }

    string solve(const string& q) {
        if (exact.count(q)) {
            return q;
        }
        string q2 = make_ignore_case(q);
        if (exact_ignore_case.count(q2)) {
            return exact_ignore_case.at(q2);
        }
        string q3 = make_ignore_vowel(q);
        if (exact_ignore_vowel.count(q3)) {
            return exact_ignore_vowel.at(q3);
        }
        return "";
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        init(wordlist);

        vector<string> answer;
        for (const auto& q: queries) {
            answer.push_back(solve(q));
        }
        return answer;
    }
};
