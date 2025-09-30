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

let card = Array.from({ length: N }, (_, i) => i);
const original = [...card];
let count = 0;

function isGoal() {
  for (let i = 0; i < N; i++) {
    if (P[card[i]] !== i % 3) return false;
  }
  return true;
}

if (isGoal()) {
  console.log(0);
  return;
}

while (true) {
  count++;

  const newCard = Array(N);
  for (let i = 0; i < N; i++) {
    newCard[S[i]] = card[i];
  }
  card = newCard;

  if (isGoal()) {
    console.log(count);
    break;
  }

  if (card.every((v, i) => v === original[i])) {
    console.log(-1);
    break;
  }
}
