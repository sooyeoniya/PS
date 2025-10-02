const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const [N, K] = input[0].split(" ").map(Number);

function bfs() {
  const visited = Array(100_001).fill(false);
  const q = [[N, 0]];
  visited[N] = true;

  while (q.length) {
    const [pos, time] = q.shift();

    if (pos === K) return time;

    for (let next of [pos * 2, pos - 1, pos + 1]) {
      if (next < 0 || next > 100_000 || visited[next]) continue;

      if (next === pos * 2) q.unshift([next, time]);
      else q.push([next, time + 1]);

      visited[next] = true;
    }
  }
}

console.log(bfs());
