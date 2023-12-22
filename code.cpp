class Solution {
public:
    int profit(vector<int>& prices,int n,int i,int b,vector<vector<int>>&dp)
    {
        if(i==n)
        return 0;
        if(dp[i][b]!=-1)
        return dp[i][b];
        if(b==0)
        {
           // int sum=
            return dp[i][b]=max(prices[i]+profit(prices,n,i+1,1,dp),profit(prices,n,i+1,0,dp));
        }
        else
        {
            return dp[i][b]=max(-prices[i]+profit(prices,n,i+1,0,dp),profit(prices,n,i+1,1,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // int res=profit(prices,n,0,1,dp);
        // return max(0,res);
        long long dp[n+1][2];
        dp[n][0]=dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int b=0;b<=1;b++)
            {
                if(b==0)
                dp[i][b]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                else
                dp[i][b]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
            }
        }
        return dp[0][1];
    }
};
