const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n').map((el) => el.trim());

const N = +input[0];
const grid = input.slice(1).map((line) => line.split(''));

const dx = [-1, 1, 0, 0];
const dy = [0, 0, -1, 1];

const bfs = (x, y, color, visited, grid) => {
  const queue = [[x, y]];
  visited[x][y] = true;

  while (queue.length) {
    const [cx, cy] = queue.shift();

    for (let dir = 0; dir < 4; dir++) {
      const nx = cx + dx[dir];
      const ny = cy + dy[dir];

      if (
        nx >= 0 && 
        nx < N && 
        ny >= 0 && 
        ny < N &&
        !visited[nx][ny] &&
        grid[nx][ny] === color
      ) {
        visited[nx][ny] = true;
        queue.push([nx, ny]);
      }
    }
  }
}

const countRegions = (grid, isColorBlind) => {
  const visited = Array.from({ length: N }, () => Array(N).fill(false));
  let regions = 0;

  for (let x = 0; x < N; x++) {
    for (let y = 0; y < N; y++) {
      if (!visited[x][y]) {
        regions++;
        const color = grid[x][y];

        // 적록색약이면 R과 G 동일하게 처리
        if (isColorBlind && (color === 'R' || color === 'G')) {
          bfs(x, y, 'R', visited, grid.map((row) => row.map((el) => el === 'G' ? 'R' : el)));
        } else {
          bfs(x, y, color, visited, grid);
        }
      }
    }
  }

  return regions;
}

const normal = countRegions(grid, false);
const colorBlind = countRegions(grid, true);

console.log(`${normal} ${colorBlind}`);
