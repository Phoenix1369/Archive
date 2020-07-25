#define ALL(x) (x).begin(), (x).end()
const vector<string> M = {
    "",
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
};

class Solution {
public:
    string reformatDate(string date) {
        istringstream iss{date};
        string dd, mm, yy;
        iss >> dd >> mm >> yy;
        ostringstream oss;
        const auto mval = find(ALL(M), mm) - M.begin();
        const auto dval = dd.substr(0, dd.size() - 2u);
        oss << yy << '-'
            << setfill('0') << setw(2) << mval << '-'
            << setfill('0') << setw(2) << dval;
        return oss.str();
    }
};
