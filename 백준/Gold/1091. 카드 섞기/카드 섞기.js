const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const N = +input[0];
const P = input[1].split(" ").map(Number);
const S = input[2].split(" ").map(Number);

let card = Array.from({ length: N }, (_, i) => i % 3);
let temp = new Array(N);
let count = 0;

while (true) {
  let isMatched = true;
  for (let i = 0; i < N; i++) {
    if (card[i] !== P[i]) {
      isMatched = false;
      break;
    }
  }

  if (!isMatched) {
    for (let i = 0; i < N; i++) {
      temp[i] = card[S[i]];
    }
    card = [...temp];
    count++;
  } else {
    console.log(count);
    break;
  }

  let infinity = true;
  for (let i = 0; i < N; i++) {
    if (card[i] !== i % 3) {
      infinity = false;
      break;
    }
  }
  if (infinity) {
    console.log(-1);
    break;
  }
}