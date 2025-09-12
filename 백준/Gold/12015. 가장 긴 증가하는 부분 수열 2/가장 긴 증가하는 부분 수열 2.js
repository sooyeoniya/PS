const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const N = +input[0];
const A = input[1].split(" ").map(Number);

const lis = [A[0]];

for (let i = 1; i < N; i++) {
  if (lis.at(-1) < A[i]) {
    lis.push(A[i]);
  } else {
    let left = 0;
    let right = lis.length - 1;
    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (lis[mid] < A[i]) left = mid + 1;
      else right = mid;
    }
    lis[left] = A[i];
  }
}

console.log(lis.length);
