const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, M] = input[0].split(" ").map(Number);
const miro = [];
for (let n = 1; n <= N; n++) {
  miro.push(input[n].split("").map(Number));
}
const visited = Array.from({ length: N }, () =>
  Array.from({ length: M }, () => false)
);
const distance = [
  [0, 1],
  [1, 0],
  [-1, 0],
  [0, -1],
];

class Queue {
  constructor() {
    this.list = [];
    this.head = 0;
    this.tail = 0;
  }

  enqueue(x, y) {
    this.list.push({ x, y });
    this.tail++;
  }

  dequeue() {
    const item = this.list[this.head];
    this.head++;
    return item;
  }

  isEmpty() {
    return this.head === this.tail;
  }
}

function bfs(x, y) {
  const queue = new Queue();
  queue.enqueue(x, y);
  visited[x][y] = true;

  const dist = Array.from({ length: N }, () =>
    Array.from({ length: M }, () => 0)
  );
  dist[x][y] = 1;

  while (!queue.isEmpty()) {
    const { x: curX, y: curY } = queue.dequeue();

    if (curX === N - 1 && curY === M - 1) {
      return dist[curX][curY];
    }

    for (let i = 0; i < 4; i++) {
      const nextX = curX + distance[i][0];
      const nextY = curY + distance[i][1];

      if (nextX < 0 || nextX >= N) continue;
      if (nextY < 0 || nextY >= M) continue;
      if (visited[nextX][nextY]) continue;
      if (miro[nextX][nextY] === 0) continue;

      visited[nextX][nextY] = true;
      dist[nextX][nextY] = dist[curX][curY] + 1;
      queue.enqueue(nextX, nextY);
    }
  }

  return -1;
}

console.log(bfs(0, 0));
