const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const T = +input.shift();
const dx = [0, 0, -1, 1];
const dy = [1, -1, 0, 0];

function bfs(startX, startY) {
  const queue = [];
  queue.push([startX, startY]);

  while (queue.length > 0) {
    const [curX, curY] = queue.shift();

    for (let i = 0; i < 4; i++) {
      const nextX = curX + dx[i];
      const nextY = curY + dy[i];

      if (nextX < 0 || nextY < 0 || nextX >= M || nextY >= N) continue;
      if (arr[nextX][nextY] === 0) continue;

      queue.push([nextX, nextY]);
      arr[nextX][nextY] = 0;
    }
  }
}

for (let i = 0; i < T; i++) {
  let count = 0;
  var [M, N, K] = input.shift().split(" ").map(Number);
  var arr = Array.from({ length: M }, () => Array(N).fill(0));

  for (let j = 0; j < K; j++) {
    const [X, Y] = input.shift().split(" ").map(Number);
    arr[X][Y] = 1;
  }

  for (let i = 0; i < M; i++) {
    for (let j = 0; j < N; j++) {
      if (arr[i][j] === 1) {
        bfs(i, j);
        count++;
      }
    }
  }

  console.log(count);
}
