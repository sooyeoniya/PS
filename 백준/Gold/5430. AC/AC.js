const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const [t, ...inputs] = fs.readFileSync(filePath).toString().trim().split('\n').map((el) => el.trim());
const T = +t;

function solution() {
  let idx = 0;
  const result = [];

  for (let i = 0; i < T; i++) {
    const p = inputs[idx++];
    const n = +inputs[idx++];
    const arrStr = inputs[idx++];
    const arr = n === 0 ? [] : arrStr.slice(1, -1).split(',').map(Number);

    let isReversed = false;
    let error = false;
    let front = 0;
    let rear = arr.length;

    for (func of p) {
      if (func === 'R') {
        isReversed = !isReversed;
      } else if (func === 'D') {
        if (front >= rear) {
          error = true;
          break;
        }
        if (isReversed) {
          rear--;
        } else {
          front++;
        }
      }
    }

    if (error) {
      result.push('error');
    } else {
      const resultArr = arr.slice(front, rear);
      if (isReversed) resultArr.reverse();
      result.push(`[${resultArr.join(',')}]`);
    }
  }

  console.log(result.join('\n'));
}

solution();
