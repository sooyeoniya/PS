const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [_, T] = input.shift().split(" ").map(Number);
let ans = Infinity;

input.forEach((line) => {
  const [S, I, C] = line.split(" ").map(Number);

  const busDispatches = Array.from({ length: C }, (_, i) => S + I * i);
  const validDispatches = busDispatches.filter((busTime) => busTime >= T);

  if (validDispatches.length) ans = Math.min(ans, ...validDispatches);
});

console.log(ans === Infinity ? -1 : ans - T);
