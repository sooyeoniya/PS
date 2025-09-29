const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const N = +input[0];
const leftHugePeopleCounts = input[1].split(" ").map(Number);
const line = Array(N).fill(0);

for (let i = 0; i < N; i++) {
  let count = 0;
  for (let j = 0; j < N; j++) {
    if (line[j] === 0) {
      if (count === leftHugePeopleCounts[i]) {
        line[j] = i + 1;
        break;
      }
      count++;
    }
  }
}

console.log(line.join(" "));
