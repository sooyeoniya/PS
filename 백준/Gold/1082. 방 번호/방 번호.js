const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

// N: 사용 가능한 숫자의 개수 (0부터 N-1까지)
// P: 각 숫자의 가격 배열 (P[i]는 숫자 i의 가격)
// M: 가지고 있는 총 돈의 양
const N = +input[0];
const P = input[1].split(" ").map(Number);
const M = +input[2];

// dp[j]: j원으로 만들 수 있는 가장 큰 숫자
const dp = Array.from({ length: M + 1 }, () => "");

// 큰 숫자부터 작은 숫자 순으로 처리 (더 큰 숫자를 우선적으로 만들기 위해)
for (let i = N - 1; i >= 0; i--) {
  // j: 현재 사용할 수 있는 총 금액 (숫자 i의 가격부터 M원까지)
  for (let j = P[i]; j <= M; j++) {
    // 숫자 i를 사고 남은 돈으로 만든 숫자(dp[j - P[i]], 즉 최대 숫자)에 i를 붙임
    const newNumber = dp[j - P[i]] + i.toString();

    // 더 큰 숫자인지 비교 (길이가 길거나, 길이가 같으면 사전순으로 더 큰 것)
    if (
      newNumber.length > dp[j].length ||
      (newNumber.length === dp[j].length && newNumber > dp[j])
    ) {
      dp[j] = newNumber;
    }
  }
}

// 0으로만 구성된 경우 처리 (0이 아닌 숫자로 시작해야 함)
let result = dp[M];
if (result === "" || result === "0" || result.startsWith("0")) {
  // 0이 아닌 숫자로 시작하는 가장 큰 숫자 찾기
  // 기본값을 "0"으로 설정 (최악의 경우라도 0은 만들 수 있음)
  let maxNumber = "0";

  // 숫자 0 제외하고 나머지 1 ~ (N - 1) 순회
  for (let i = 1; i < N; i++) {
    if (P[i] <= M) {
      if (dp[M - P[i]] !== "" || M - P[i] === 0) {
        const candidate = i.toString() + dp[M - P[i]]; // 순서 중요!
        if (
          candidate.length > maxNumber.length ||
          (candidate.length === maxNumber.length && candidate > maxNumber)
        ) {
          maxNumber = candidate;
        }
      }
    }
  }

  result = maxNumber;
}

console.log(result);
