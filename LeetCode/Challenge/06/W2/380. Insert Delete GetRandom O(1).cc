std::unordered_map<int, int> pos;
std::vector<int> A;

std::random_device seed;
std::mt19937 engine(seed());

class RandomizedSet {
public:
    RandomizedSet() {
        pos.clear();
        A.clear();
    }

    bool insert(int val) {
        if (pos.count(val)) {
            return false;
        }
        pos[val] = A.size();
        A.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!pos.count(val)) {
            return false;
        }
        int N = A.size();
        int cur = pos.at(val);
        if (cur != N-1) {
            pos.at(A[N-1]) = cur;
            swap(A[cur], A[N-1]);
        }
        pos.erase(val);
        A.pop_back();
        return true;
    }

    int getRandom() {
        int N = A.size();
        std::uniform_int_distribution<int> dist(0, N-1);
        return A[dist(engine)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
