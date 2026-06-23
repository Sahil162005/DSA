class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

    
        vector<vector<int>> prev(m, vector<int>(2, 0));
        vector<vector<int>> curr(m, vector<int>(2, 0));

    
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {

                if (a == b) continue;

                if (b > a)
                    prev[b][1]++;   
                else
                    prev[b][0]++;     
            }
        }

     
        if (n == 2) {
            long long ans = 0;
            for (int i = 0; i < m; i++)
                ans = (ans + prev[i][0] + prev[i][1]) % MOD;
            return ans;
        }

       
        for (int len = 3; len <= n; len++) {

            vector<int> prefUp(m), prefDown(m);

            prefUp[0] = prev[0][1];
            prefDown[0] = prev[0][0];

            for (int i = 1; i < m; i++) {
                prefUp[i] = (prefUp[i - 1] + prev[i][1]) % MOD;
                prefDown[i] = (prefDown[i - 1] + prev[i][0]) % MOD;
            }

            int totalUp = prefUp[m - 1];
            int totalDown = prefDown[m - 1];

            for (int x = 0; x < m; x++) {

                
                curr[x][0] = (totalUp - prefUp[x] + MOD) % MOD;

                
                curr[x][1] = (x > 0 ? prefDown[x - 1] : 0);
            }

            prev.swap(curr);

            for (int i = 0; i < m; i++) {
                curr[i][0] = 0;
                curr[i][1] = 0;
            }
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + prev[i][0]) % MOD;
            ans = (ans + prev[i][1]) % MOD;
        }

        return ans;
    }
};