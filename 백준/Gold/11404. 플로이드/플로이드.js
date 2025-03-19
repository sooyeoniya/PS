const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const inputs = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

function solution(inputs) {
  const n = +inputs[0];
  const m = +inputs[1];
  const arr = inputs.slice(2);
  const answer = Array.from({ length: n }, () => new Array(n).fill(Infinity));

  for (let i = 0; i < m; i++) {
    const [a, b, c] = arr[i].split(" ").map(Number);
    answer[a - 1][b - 1] = Math.min(answer[a - 1][b - 1], c);
  }
  for (let i = 0; i < n; i++) answer[i][i] = 0;

  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        answer[i][j] = Math.min(answer[i][j], answer[i][k] + answer[k][j]);
      }
    }
  }

  for (let i = 0; i < n; i++) {
    let arr = [];
    for (let j = 0; j < n; j++) {
      if (answer[i][j] === Infinity) arr.push(0);
      else arr.push(answer[i][j]);
    }
    console.log(arr.join(" "));
  }
}

solution(inputs);
