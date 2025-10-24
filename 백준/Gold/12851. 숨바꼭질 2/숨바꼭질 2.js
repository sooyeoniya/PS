const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, K] = input[0].split(" ").map(Number);
const visited = Array(100_001).fill(0);
let count = 0;

function bfs(node) {
  let index = 0;

  const queue = [node];
  visited[node] = 1;

  while (queue.length > index) {
    const cur = queue[index++];

    if (cur === K) count++;

    for (const next of [cur - 1, cur + 1, cur * 2]) {
      if (next < 0 || next > 100_000) continue;
      if (visited[next] === 0 || visited[next] === visited[cur] + 1) {
        queue.push(next);
        visited[next] = visited[cur] + 1;
      }
    }
  }
}

bfs(N);

console.log(visited[K] - 1);
console.log(count);
