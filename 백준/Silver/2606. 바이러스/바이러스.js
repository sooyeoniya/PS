const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.trim());

const N = +input.shift();
const E = +input.shift();
const computers = input.map((el) => el.split(" ").map(Number));
const visited = Array.from({ length: N + 1 }, () => false);
const list = Array.from({ length: N + 1 }, () => []);
let answer = 0;

computers.map(([from, to]) => {
  list[from].push(to);
  list[to].push(from);
});

function dfs(node) {
  visited[node] = true;
  for (let i = 0; i < list[node].length; i++) {
    const nextNode = list[node][i];

    if (!visited[nextNode]) {
      answer++;
      dfs(nextNode);
    }
  }
}

dfs(1);

console.log(answer);
