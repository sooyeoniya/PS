const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const N = +input[0];
const arr = input[1].split(" ").map(Number);

let left = 0;
let right = N - 1;
let sum = Infinity;
let optObj = { left: 0, right: N - 1, absSum: Infinity };

while (left < right) {
  sum = arr[left] + arr[right];

  if (sum === 0) {
    optObj = { left, right, absSum: sum };
    break;
  }

  if (sum < 0) {
    const absSum = Math.abs(sum);

    if (absSum < optObj.absSum) {
      optObj = { left, right, absSum };
    }

    left++;
  } else {
    const absSum = Math.abs(sum);

    if (absSum < optObj.absSum) {
      optObj = { left, right, absSum };
    }

    right--;
  }
}

console.log(arr[optObj.left], arr[optObj.right]);
