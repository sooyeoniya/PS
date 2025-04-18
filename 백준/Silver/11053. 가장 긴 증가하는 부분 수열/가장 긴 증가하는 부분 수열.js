const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const inputs = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

function solution(inputs) {
  const N = +inputs[0];
  const A = inputs[1].split(" ").map((el) => +el);
  const dp = new Array(N).fill(0);

  for (let i = 0; i < N; i++) {
    let count = 0;

    for (let j = 0; j < i; j++) {
      if (A[i] > A[j] && dp[j] > count) {
        count = dp[j];
      }
    }

    dp[i] = ++count;
  }

  console.log(Math.max(...dp));
}

solution(inputs);

/* ========================================================================= */

function binarySearch(list, left, right, value) {
  while (left < right) {
    let mid = Math.floor((left + right) / 2);

    if (list[mid] < value) {
      left = mid + 1;
    } else if (list[mid] > value) {
      right = mid;
    } else {
      return mid;
    }
  }

  return right;
}

function solution2(inputs) {
  const N = +inputs[0];
  const A = inputs[1].split(" ").map((el) => +el);

  const arr = [];
  arr.push(A[0]);

  for (let i = 1; i < N; i++) {
    if (arr[arr.length - 1] < A[i]) {
      arr.push(A[i]);
    } else {
      let index = binarySearch(arr, 0, arr.length - 1, A[i]);
      arr[index] = A[i];
    }
  }

  console.log(arr.length);
}

solution2(inputs);
