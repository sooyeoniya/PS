const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [H, W] = input[0].split(" ").map(Number);
const rainwater = input[1].split(" ").map(Number);
let amountOfWater = 0;

for (let i = 1; i < W - 1; i++) {
  const leftMaxHeight = Math.max(...rainwater.slice(0, i));
  const rightMaxHeight = Math.max(...rainwater.slice(i + 1));

  const minHeight = Math.min(leftMaxHeight, rightMaxHeight);
  if (rainwater[i] < minHeight) amountOfWater += minHeight - rainwater[i];
}

console.log(amountOfWater);
