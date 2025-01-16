const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split('\n')
  .map((el) => el.trim());

const [N, M, S] = input;

function solution() {
  let cnt = 0;
  let answer = 0;
  let i = 0;

  while (i < M - 1) {
    if (S.slice(i, i + 3) === 'IOI') {
      cnt += 1;
      if (cnt >= N) {
        answer += 1;
      }
      i += 2;
    } else {
      cnt = 0;
      i += 1;
    }
  }

  console.log(answer);
}

solution();
