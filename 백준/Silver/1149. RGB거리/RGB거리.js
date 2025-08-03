const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const inputs = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

function solution(inputs) {
  const [N, ...rest] = inputs;
  const items = rest.map((item) => item.split(" ").map(Number));

  let answer = Infinity;

  const dp = Array.from({ length: N }, () => Array(3).fill(Infinity));

  for (let i = 0; i < 3; i++) {
    dp[0][i] = items[0][i];
  }

  for (let n = 1; n < N; n++) {
    dp[n][0] = Math.min(dp[n - 1][1], dp[n - 1][2]) + items[n][0];
    dp[n][1] = Math.min(dp[n - 1][0], dp[n - 1][2]) + items[n][1];
    dp[n][2] = Math.min(dp[n - 1][0], dp[n - 1][1]) + items[n][2];
  }

  answer = Math.min(...dp[N - 1]);
  console.log(answer);
}

solution(inputs);

// N개의 집

// 1: 2
// 2: 1, 3
// 3: 2, 4
// N: N-1

// 0 < cost <= 1,000
