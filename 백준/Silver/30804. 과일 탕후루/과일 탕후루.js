// 풀이 1) 슬라이딩 윈도우 기법 + 투 포인터
const inputs = require('fs').readFileSync('/dev/stdin');
const [n, fruits] = inputs.toString().trim().split('\n');
const fruitsArr = fruits.split(' ').map(Number);
let frequencyArr = Array(10).fill(0);
let low = 0, ans = 0, dNums = 0;

for (let high = 0; high < n; ++high) {
  frequencyArr[fruitsArr[high]] += 1;

  if (frequencyArr[fruitsArr[high]] === 1) {
    dNums += 1;
  }

  while (dNums > 2) {
    frequencyArr[fruitsArr[low]] -= 1;

    if (frequencyArr[fruitsArr[low]] === 0) {
      dNums -= 1;
    }

    low += 1;
  }

  ans = Math.max(ans, high - low + 1);
}

console.log(ans);

//////////////////////////////////////////////////////////

// 풀이 2) 투 포인터
const inputs = require('fs').readFileSync('/dev/stdin');
const [n, fruits] = inputs.toString().trim().split('\n');
const fruitsArr = fruits.split(' ').map(Number);

const solution = (i, j) => {
  let maxNum = 0, cnt = 0;

  for (let idx = 0; idx < n; ++idx) {
    if (fruitsArr[idx] !== i && fruitsArr[idx] !== j) {
      maxNum = Math.max(maxNum, cnt);
      cnt = 0;
    } else {
      cnt += 1;
    }
  }

  return Math.max(maxNum, cnt);
}

let ans = 0;
for (let i = 1; i <= 9; ++i) {
  for (let j = i + 1; j <= 9; ++j) {
    ans = Math.max(ans, solution(i, j));
  }
}

console.log(ans);
