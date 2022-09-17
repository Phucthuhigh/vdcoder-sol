# DPCODE

while (1):
    s=input()
    if (s=="0"): break
    s=" "+s
    n=len(s)-1
    dp=[0]*(n+1)
    dp[0]=1
    dp[1]=1
    for i in range(2,n+1):
        if s[i]!='0':dp[i]+=dp[i-1]
        if (s[i-1]=='1') or (s[i-1]=='2' and s[i]<='6'):
            dp[i]+=dp[i-2]
    print(dp[n])
    