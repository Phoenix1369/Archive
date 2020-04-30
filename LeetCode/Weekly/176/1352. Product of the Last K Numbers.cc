const int MAXN = 4e4+5;
int A[MAXN];
int N, Z;

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        A[0] = 1;
        N = 0;
        Z = -1;
    }
    
    void add(int num) {
        A[++N] = num;
        if (A[N-1] != 0) {
            A[N] *= A[N-1];
        }
        if (num == 0) {
            Z = N;
        }
    }
    
    int getProduct(int k) {
        if (Z > N-k) {
            return 0;
        }
        if (A[N-k] == 0) {
            return A[N];
        }
        return A[N] / A[N-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
