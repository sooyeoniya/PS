
class Queue {
    constructor () {
        this.list = [];
        this.head = 0;
        this.tail = 0;
    }
    
    enqueue(item) {
        this.list[this.tail++] = item;
    }
    
    dequeue() {
        if (this.isEmpty()) return undefined;
        return this.list[this.head++];
    }
    
    isEmpty() {
        return this.head === this.tail;
    }
}

const dx = [1, -1, 0, 0];
const dy = [0, 0, 1, -1];

const startX = 0;
const startY = 0;
const startCnt = 1;

let answer = Infinity;
const queue = new Queue();

function solution(maps) {
    const n = maps.length;
    const m = maps[0].length;
    
    const visited = Array.from({ length: n }, () => Array(m).fill(false));
    
    queue.enqueue([startX, startY, startCnt]);
    visited[startX][startY] = true;
    
    while (!queue.isEmpty()) {
        const [curX, curY, cnt] = queue.dequeue();
        
        if (curX === n - 1 && curY === m - 1) {
            answer = Math.min(answer, cnt);
            break;
        }
        
        for (let [x, y] of [[1, 0], [-1, 0], [0, 1], [0, -1]]) {
            const nextX = curX + x;
            const nextY = curY + y;
            
            if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue;
            if (visited[nextX][nextY] || !maps[nextX][nextY]) continue;

            queue.enqueue([nextX, nextY, cnt + 1]);
            visited[nextX][nextY] = true;
        }
    }
    
    if (answer !== Infinity) return answer;
    return -1;
}

