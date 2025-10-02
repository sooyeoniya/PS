const [subin, sister] = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(val => +val);
const visited = Array.from({ length: 100001 }, () => false);

const moveSubin = N => {
  const queue = [[N, 0]];
  visited[N] = true;

  while (queue.length) {
    const [current, time] = queue.shift();

    if (current === sister) return time;
	
    [current - 1, current + 1, current * 2].forEach(move => {
      if (visited[move] || move < 0 || move > 100001) return;

      visited[move] = true;

      if (move !== current * 2) queue.push([move, time + 1]);
      else queue.unshift([move, time]);
    });
  }
};

console.log(moveSubin(subin));