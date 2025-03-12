const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const inputs = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

function solution2(inputs) {
  const [str1, str2] = inputs;

  const dp = new Array(str1.length + 1).fill(0);

  for (ch of str2) {
    let prevNum = 0;
    let curNum = 0;

    for (let j = 1; j < dp.length; j++) {
      curNum = dp[j];

      if (ch === str1[j - 1]) dp[j] = prevNum + 1;
      else dp[j] = Math.max(dp[j], dp[j - 1]);

      prevNum = curNum;
    }
  }
  console.log(dp[dp.length - 1]);
}

solution2(inputs);
