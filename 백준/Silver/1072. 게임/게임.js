const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [X, Y] = input[0].split(" ").map(Number);
const Z = Math.floor((100 * Y) / X);

let left = 1;
let right = 1_000_000_000;
let count = Infinity;

while (left <= right) {
  const mid = Math.floor((left + right) / 2);
  const newZ = Math.floor((100 * (Y + mid)) / (X + mid));

  if (newZ !== Z) {
    count = Math.min(count, mid);
    right = mid - 1;
  } else {
    left = mid + 1;
  }
}

if (count === Infinity) console.log(-1);
else console.log(count);
