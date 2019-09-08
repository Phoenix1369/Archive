class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        vector<int>& D = distance;
        int N = D.size();
        
        D.insert(D.begin(), 0);
        for (int i = 1; i <= N; ++i) {
            D[i] += D[i-1];
        }
        
        int& A = start;
        int& B = destination;
        if (A > B) swap(A, B);
        int edge = D[B] - D[A];
        return min(edge, D[N] - edge);
    }
};  // Alias variable names with references.
