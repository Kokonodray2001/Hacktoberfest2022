class Solution {
public:
    int solve(string &s1,string &s2,int i,int j, vector<vector<int>>&dp){
        if(i==-1 || j == -1)
            return i>j?i+1:j+1;
    
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i] == s2[j] )
            return solve(s1,s2,i-1,j-1,dp);
        
        int mini =  INT32_MAX;
        
        mini =  min(mini,1+solve(s1,s2,i-1,j-1,dp));
        mini =  min(mini,1+solve(s1,s2,i-1,j,dp));
        mini =  min(mini,1+solve(s1,s2,i,j-1,dp));
        dp[i][j] =  mini;
        return dp[i][j];
    }
    
    
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m =  s2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //return solve(s1,s2,n-1,m-1,dp);
        vector<int>cur(m+1,0);
        vector<int>pre(m+1,0);
        for(int i =0;i<m+1;i++)
                cur[i] =  i;
        //for(int i =0;i<m+1;i++){
           //     dp[0][i] =i;
          //  }
        pre = cur;
        for(int i =1;i<=n;i++){
            cur[0] = i;
            for(int j  =1;j<=m;j++){
            
                int mini =  INT32_MAX;
                
                if(s1[i-1] == s2[j-1] )
                    mini = pre[j-1];//dp[i-1][j-1];
                else{       
                mini =  min(mini,1+pre[j-1]);
                mini =  min(mini,1+pre[j]);
                mini =  min(mini,1+cur[j-1]);
                }    
                    
            cur[j] =  mini;
            
            }
            pre = cur;
        }
        return cur[m];
    }
};
