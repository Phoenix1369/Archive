const int MAXN = 205;
int P[MAXN];
int cnt, D, N;

class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        N = n;
        D = discount;
        int M = products.size();
        for (int i = 0; i < M; ++i) {
            P[products[i]] = prices[i];
        }
        cnt = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double cost = 0.0;
        int M = product.size();
        for (int i = 0; i < M; ++i) {
            cost += P[product[i]] * amount[i];
        }
        if (++cnt == N) {
            cost = cost - 1.0 * D * cost / 100.0;
            cnt = 0;
        }
        return cost;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
