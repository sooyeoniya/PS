const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, M] = input.shift().split(" ");
const [x1, y1, x2, y2] = input.shift().split(" ");
const room = input.map((line) => line.split(""));
const visited = Array.from({ length: N }, () => Array(M).fill(false));

const dx = [0, 0, 1, -1];
const dy = [1, -1, 0, 0];

function bfs(startX, startY) {
  let count = 0;
  const queue = [];
  queue.push([startX, startY]);
  visited[startX][startY] = true;

  while (queue.length > 0) {
    const friends = [];
    count++;

    while (queue.length > 0) {
      const [curX, curY] = queue.shift();

      for (let i = 0; i < 4; i++) {
        const nextX = curX + dx[i];
        const nextY = curY + dy[i];

        if (
          nextX < 0 ||
          nextY < 0 ||
          nextX >= N ||
          nextY >= M ||
          visited[nextX][nextY]
        ) {
          continue;
        }

        visited[nextX][nextY] = true;

        if (room[nextX][nextY] === "0") {
          queue.push([nextX, nextY]);
        } else if (room[nextX][nextY] === "1") {
          room[nextX][nextY] = "0";
          friends.push([nextX, nextY]);
        } else if (room[nextX][nextY] === "#") {
          return count;
        }
      }
    }

    friends.forEach(([x, y]) => queue.push([x, y]));
  }
}

console.log(bfs(x1 - 1, y1 - 1));
