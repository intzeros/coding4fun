class Solution {
public:
    int uniquePaths(int m, int n) {
        int M = min(m, n) - 1, N = m+n-2;
        double c = 1;
        for(int k = 1; k <= M; k++){    // C(M, N)
            c = (N-k+1)*c/k;
        }
        return (int)c;
    }
};
