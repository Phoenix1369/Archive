const int DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MAXC = 15;
const int YEAR = 365;
char C[MAXC];

struct Date {
    int Y, M, D;
    
    bool operator < (const Date& o) const {
        return (Y != o.Y)
            ? (Y < o.Y) : (M != o.M)
            ? (M < o.M)
            : (D < o.D);
    }
};

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        Date d1, d2;
        parse(date1, d1);
        parse(date2, d2);
        if (d2 < d1) {
            swap(d1, d2);
        }
        if (d1.Y == d2.Y) {
            return sameyear(d1, d2);
        }
        Date d3 {d1.Y, 12, DAYS[12]};
        Date d4 {d2.Y,  1, DAYS[ 0]};
        int ret = sameyear(d1, d3);
        for (int i = d1.Y + 1; i < d2.Y; ++i) {
            ret += YEAR;
            if (isleap(i)) ++ret;
        }
        ret += sameyear(d4, d2);
        return ret;
    }

private:
    bool isleap(int y) {
        return !(y % 400) || (!(y % 4) && (y % 100));
    }
    
    void parse(string s, Date& d) {
        strcpy(C, s.c_str());
        d.Y = atoi(C);
        d.M = atoi(C + 5);
        d.D = atoi(C + 8);
    }
    
    int sameyear(const Date& d1, const Date& d2) {
        int ret = 0;
        for (int i = d1.M; i < d2.M; ++i) {
            ret += DAYS[i];
            if ((i == 2) && isleap(d1.Y)) ++ret;
        }
        ret += d2.D - d1.D;
        return ret;
    }
};
