const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

// DP 에서 길이 수를 저장하는게 아니라 문자열 자체를 저장해야 함
// 길이로만 저장할 경우 제대로 구분지을 수 없음

// DP의 각 길이는 각 문자열의 + 1임, 왜냐하면 0일 때는 빈 값으로 초기화 해두었기 때문

// dp[a][b] = a는 str1의 길이, b는 str2의 길이, dp[a][b] = LCS(최장 공통 부분 수열)

const [str1, str2] = input;

const dp = Array.from({ length: str1.length + 1 }, () =>
  Array.from({ length: str2.length + 1 }, () => "")
);

for (let i = 1; i < str1.length + 1; i++) {
  for (let j = 1; j < str2.length + 1; j++) {
    if (str1[i - 1] === str2[j - 1]) {
      dp[i][j] = dp[i - 1][j - 1] + str2[j - 1];
    } else {
      if (dp[i][j - 1].length > dp[i - 1][j].length) {
        dp[i][j] = dp[i][j - 1];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
}

const LCS = dp[str1.length][str2.length];

if (LCS.length === 0) {
  console.log(0);
} else {
  console.log(LCS.length);
  console.log(LCS);
}
