//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long int f(int index, int coins[], int sum, vector<vector<long long int>>& dp) {
        if (index == 0) {
            return (sum % coins[0] == 0);
        }
        if (dp[index][sum] != -1) return dp[index][sum];
        long long int notake = f(index - 1, coins, sum, dp);
        long long int take = 0;
        if (coins[index] <= sum) take = f(index, coins, sum - coins[index], dp);
        return dp[index][sum] = take + notake;
    }

    long long int count(int coins[], int n, int sum) {
        vector<vector<long long int>> dp(n, vector<long long int>(sum + 1, -1));
        return f(n - 1, coins, sum, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends