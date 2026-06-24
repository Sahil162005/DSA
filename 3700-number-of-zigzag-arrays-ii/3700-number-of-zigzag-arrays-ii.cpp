#include <bits/stdc++.h>
using namespace std;
static const long long MOD = 1e9 + 7;

typedef vector<vector<long long>> Mat;

Mat multiply(const Mat& A, const Mat& B) {
    int n = A.size();
    Mat C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++) {
            if (!A[i][k]) continue;
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        }
    return C;
}

Mat matpow(Mat M, long long p) {
    int n = M.size();
    Mat R(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) R[i][i] = 1;
    while (p > 0) {
        if (p & 1) R = multiply(R, M);
        M = multiply(M, M);
        p >>= 1;
    }
    return R;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        Mat T(sz, vector<long long>(sz, 0));
        for (int x = 0; x < m; x++) {
           
            for (int y = x + 1; y < m; y++)
                T[x][m + y] = 1;           
            for (int y = 0; y < x; y++)
                T[m + x][y] = 1;            
        }
        vector<long long> state(sz, 0);
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {
                if (a == b) continue;
                if (b > a) state[m + b]++;   
                else       state[b]++;        
            }
        }

        if (n == 2) {
            long long ans = 0;
            for (auto v : state) ans = (ans + v) % MOD;
            return ans;
        }


        Mat Tp = matpow(T, n - 2);
        vector<long long> res(sz, 0);
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                res[i] = (res[i] + Tp[i][j] * state[j]) % MOD;

        long long ans = 0;
        for (auto v : res) ans = (ans + v) % MOD;
        return ans;
    }
};