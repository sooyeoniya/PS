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

  for (let startColor = 0; startColor < 3; startColor++) {
    const dp = Array.from({ length: N }, () => Array(3).fill(Infinity));
    dp[0][startColor] = items[0][startColor];

    for (let n = 1; n < N; n++) {
      dp[n][0] = Math.min(dp[n - 1][1], dp[n - 1][2]) + items[n][0];
      dp[n][1] = Math.min(dp[n - 1][0], dp[n - 1][2]) + items[n][1];
      dp[n][2] = Math.min(dp[n - 1][0], dp[n - 1][1]) + items[n][2];
    }

    for (let endColor = 0; endColor < 3; endColor++) {
      if (startColor === endColor) continue;
      answer = Math.min(answer, dp[N - 1][endColor]);
    }
  }

  console.log(answer);
}

solution(inputs);

// N개의 집

// 1: 2, N
// 2: 1, 3
// 3: 2, 4
// N: N-1, 1

// 0 < cost <= 1,000
