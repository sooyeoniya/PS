const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [W, H, f, c, x1, y1, x2, y2] = input[0].split(" ").map(BigInt);

const paintW = x2 - x1;
const paintH = y2 - y1;

let answer = W * H;
const overlapWidth = f < W - f ? f : W - f;

if (overlapWidth <= x1) {
  answer -= paintW * paintH * (c + 1n);
} else if (overlapWidth < x2) {
  answer -= (overlapWidth - x1) * paintH * (c + 1n) * 2n;
  answer -= (x2 - overlapWidth) * paintH * (c + 1n);
} else {
  answer -= paintW * paintH * (c + 1n) * 2n;
}

console.log(answer.toString());
