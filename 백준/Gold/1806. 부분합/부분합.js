const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, S] = input[0].split(" ").map(Number);
const sequence = input[1].split(" ").map(Number);

let minLength = 100_001;
let startIndex = 0;
let endIndex = 0;
let sum = 0;

while (endIndex < N) {
  sum += sequence[endIndex];

  while (sum >= S) {
    const distnace = endIndex - startIndex + 1;
    minLength = Math.min(minLength, distnace);
    sum -= sequence[startIndex];
    startIndex++;
  }

  endIndex++;
}

if (minLength === 100_001) console.log(0);
else console.log(minLength);

// 시간 복잡도: O(N)
// 공간 복잡도: O(1)
