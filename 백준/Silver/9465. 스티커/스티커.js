const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const T = +input[0];
let N, A, B;

for (let t = 0; t < T; t++) {
  N = +input[1 + t * 3];
  A = input[2 + t * 3].split(" ").map(Number);
  B = input[3 + t * 3].split(" ").map(Number);

  const dp = Array.from({ length: 2 }, () => Array.from(N + 1).fill(0));
  dp[0][0] = A[0];
  dp[1][0] = B[0];

  dp[0][1] = A[1] + dp[1][0];
  dp[1][1] = B[1] + dp[0][0];

  for (let n = 2; n < N; n++) {
    dp[0][n] = Math.max(dp[1][n - 1], dp[1][n - 2]) + A[n];
    dp[1][n] = Math.max(dp[0][n - 1], dp[0][n - 2]) + B[n];
  }

  console.log(Math.max(dp[0][N - 1], dp[1][N - 1]));
}
