const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, K] = input[0].split(" ").map(Number);
const arr = input[1].split(" ").map(Number);
let maxlength = 0;
let left = 0;
let right = 0;
const kMap = {};

while (left <= right && right < N) {
  while (kMap[arr[right]] === K) {
    kMap[arr[left]]--;
    left++;
  }

  maxlength = Math.max(maxlength, right - left + 1);
  kMap[arr[right]] = (kMap[arr[right]] ?? 0) + 1;
  right++;
}

console.log(maxlength);
