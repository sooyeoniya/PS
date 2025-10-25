const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, M] = input.shift().split(" ").map(Number);
const jewel = Array.from({ length: M }, (_, index) => +input[index]).sort(
  (a, b) => a - b
);

let left = 1;
let right = jewel[M - 1];

while (left <= right) {
  let mid = Math.floor((left + right) / 2);
  let count = 0;

  for (let i = 0; i < M; i++) {
    count += Math.floor(jewel[i] / mid);
    if (jewel[i] % mid) count++;
  }

  if (count <= N) right = mid - 1;
  else left = mid + 1;
}

console.log(left);
