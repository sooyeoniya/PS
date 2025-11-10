function solution(m, n, puddles) {
    const MOD = 1000000007;
    const dp = Array.from({ length: n }, () => Array(m).fill(0));
    dp[0][0] = 1;
    puddles.forEach(([i, j]) => dp[j - 1][i - 1] = -1);
    
    for (let i = 1; i < n; i++) {
        if (dp[i][0] === -1) continue;
        dp[i][0] = Math.max(0, dp[i - 1][0]);
    }
    for (let i = 1; i < m; i++) {
        if (dp[0][i] === -1) continue;
        dp[0][i] = Math.max(0, dp[0][i - 1]);
    }
    
    for (let i = 1; i < n; i++) {
        for (let j = 1; j < m; j++) {
            if (dp[i][j] === -1) continue;
            if (dp[i - 1][j] !== -1) dp[i][j] += dp[i - 1][j];
            if (dp[i][j - 1] !== -1) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    return dp[n - 1][m - 1];
}