const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, K] = input.shift().split(" ").map(Number);
const arr = Array.from({ length: N }, (_, k) => +input[k]).sort(
  (a, b) => b - a
);

let count = 0;
let remaining = K;
for (let i = 0; i < N; i++) {
  if (arr[i] <= remaining) {
    count += Math.floor(remaining / arr[i]);
    remaining = remaining % arr[i];
  }
}

console.log(count);