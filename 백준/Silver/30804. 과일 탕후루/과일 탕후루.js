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
