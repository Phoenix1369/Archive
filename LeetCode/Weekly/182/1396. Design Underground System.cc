typedef long long lld;
const int MAXQ = 2e4+5;

struct Data { lld sum; int cnt; };
map<string, Data> A;

struct Enter { string stn; int time; };
map<int, Enter> S;

class UndergroundSystem {
public:
    UndergroundSystem() {
        A.clear();
        S.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        S[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto prev = S[id];
        string path = prev.stn + ' ' + stationName;
        auto data = A[path];
        data.sum += t - prev.time;
        ++data.cnt;
        A[path] = data;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto data = A[startStation + ' ' + endStation];
        return 1.0 * data.sum / data.cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
