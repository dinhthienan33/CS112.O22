n=int(input())
grid=[input() for _ in range(n)]
dp=[[None]*n for _ in range(n)]
if(n==1):
    if(grid[0][0]=='.'):
        print(1)
    if(grid[0][0]=='*'):
        print(0)
elif(grid[0][0]=='*'):
    print(0)
else:
    dp[0][0]=1
    for i in range(n):
        for j in range(n):
            if grid[i][j]=='.' and (i!=0 or j!=0):
                dp[i][j] = 0
                if i>0 and dp[i-1][j]!=None:
                    dp[i][j] += dp[i-1][j]
                if j>0 and dp[i][j-1]!=None:
                    dp[i][j] += dp[i][j-1]
    MOD=pow(10,9)+7
    if(dp[n-1][n-1]!=None):
        print(dp[n-1][n-1]%MOD)
    else:
        print(0)