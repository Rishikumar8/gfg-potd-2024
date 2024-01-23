/*

Author : Rishi Kumar Choudhry
Date : 16/01/2024
Problem : Sequence of Sequence
Difficulty : Medium


*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    long long int numberSequence(int m, int n) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // Base case: there is 1 way to create a sequence of length 0
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j / 2]) % MOD;
            }
        }

        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
