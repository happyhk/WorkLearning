class Solution {
public:
    vector<double> twoSum(int n) {
      int dp[15][70];
      memset(dp, 0, sizeof(dp));
      for(int i = 1; i <= 6; ++i) dp[1][i] = 1;
      for(int i = 2; i <= n; ++i) {
        for(int j = i; j <= 6*i; ++j) {
          for(int cur = 1; cur <= 6; ++cur) { 
            if(j - cur <= 0) break;
            dp[i][j] += dp[i-1][j-cur];
          }
        }
      }

      int sum = pow(6,n);
      vector<double> res;
      for(int i = n; i <= 6*n; ++i){
        res.push_back(dp[n][i]*1.0/sum);
      }
      return res;
    }
};
