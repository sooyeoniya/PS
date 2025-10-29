const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, L, W, H] = input[0].split(" ").map(Number);

let left = 0;
let right = Math.min(L, W, H);
let mid = 0;

for (let i = 0; i < 100; i++) {
  mid = (left + right) / 2;

  const boxCount =
    Math.floor(L / mid) * Math.floor(W / mid) * Math.floor(H / mid);

  if (boxCount >= N) left = mid;
  else right = mid;
}

console.log(left.toFixed(9));
