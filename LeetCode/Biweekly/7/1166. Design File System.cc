const char DELIM = '/';
const int NOPE = -1;

struct Node {
    int val;
    unordered_map<string, Node*> data;

    Node() : Node{NOPE} { }
    Node(int val) : val{val} { }

    bool create(const string& path, unsigned pos, int value) {
        if (pos == path.size()) {
            return false;
        }
        unsigned beg = ++pos;
        while ((pos < path.size()) && (path[pos] != DELIM)) ++pos;
        string key = path.substr(beg, pos - beg);
        if (data.count(key)) {
            return data.at(key)->create(path, pos, value);
        }
        if (pos < path.size()) {
            return false;
        }
        data[key] = new Node(value);
        return true;
    }

    int get(const string& path, unsigned pos) {
        if (pos == path.size()) {
            return val;
        }
        unsigned beg = ++pos;
        while ((pos < path.size()) && (path[pos] != DELIM)) ++pos;
        string key = path.substr(beg, pos - beg);
        if (data.count(key)) {
            return data.at(key)->get(path, pos);
        }
        return NOPE;
    }
};

class FileSystem {
    Node *root;

public:
    FileSystem() {
        root = new Node();
    }
    
    bool create(string path, int value) {
        return root->create(path, 0, value);
    }
    
    int get(string path) {
        return root->get(path, 0);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */
