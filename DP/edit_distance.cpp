// iterative
int Solution::minDistance(string A, string B) {
    int n = A.size();
    int m = B.size();
    
    int dp[n+1][m+1];
    for(int i = 0; i <= n ;i++)
    {
        dp[i][0] = i;
    }
    for(int i = 0; i <= m; i++)
    {
    	dp[0][i] = i;
    }

    for(int i = 1; i <= n; i++)
    {
    	for(int j = 1; j <= m; j++)
    	{
    		if(A[i-1] == B[j-1])
    			dp[i][j] = dp[i-1][j-1];
    		else
    		{
    			dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
    		}
    	}
    }
    return dp[n][m];
}

// recursive
int solve(vector<vector<int> > &dp, string &a, string &b, int i, int j)
{
    if(i == 0)
    return j;
    if(j == 0)
    return i;
    if(dp[i][j] != -1)
    return dp[i][j];
    int x = solve(dp,a,b,i-1,j-1);
    if(a[i-1] == b[j-1])
    return dp[i][j] = x;
    
    dp[i][j] = min({solve(dp,a,b,i-1,j),solve(dp,a,b,i,j-1),x})+1;
    return dp[i][j];
}
int Solution::minDistance(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
    int ans = solve(dp,a,b,n,m);
    return ans;
}
