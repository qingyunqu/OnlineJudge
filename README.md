# OnlineJudge
刷题！刷题！刷题！
## 常见动态规划总结
* 最长公共子序列：`dp[i][j]为以A[i]和B[j]为结尾的最长公共子序列`
```
初始：int dp[lenth(A)+1][lenth(B)+1]，初始都为0
dp[i][j] = dp[i-1][j-1] + 1    "A[i] == B[j]" 或
dp[i][j] = max(dp[i-1][j], dp[i][j-1])    "A[i] != B[j]"
1 <= i <= lenth(A), 1 <= j <= lenth(B)
结果为dp[lenth(A)][lenth(B)]
```
* 01背包问题：`dp[i][j]为以j为容量只放前i个物品的最大价值`
```
初始：int dp[n + 1][W + 1]，初始都为0
dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]) "j >= w[i]" 否则
dp[i][j] = dp[i-1][j]
1 <= i <= n, 1 <= j <= W
结果为dp[n][W]
```
* Multiplication Puzzle：问题为抽出一张卡片，记该卡片与其相邻两张卡片的乘积为此次积分，求只剩头尾两张卡片时的最小积分，`dp[l][r]为从l到r这个区域(闭区间)的最小积分`
```
初始：
```