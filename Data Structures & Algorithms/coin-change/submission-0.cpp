class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        sort(coins.begin(), coins.end());

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++) {
            if(coins[i] <= amount) dp[coins[i]] = 1;
            if(coins[i] == amount) return 1;
        }

        for(int i = 1; i <= amount; i++) {
            auto t = i;
            if(dp[i] != INT_MAX) continue;
            for(int j = 0; j < coins.size(); j++) {
                if(coins[j] > i) break;
                if(dp[i-coins[j]] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }

        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
