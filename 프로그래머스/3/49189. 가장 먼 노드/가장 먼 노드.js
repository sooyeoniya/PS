function solution(n, edge) {
    const graph = Array.from({ length: n }, () => []);
    
    edge.forEach(([a, b]) => {
        graph[a - 1].push(b - 1);
        graph[b - 1].push(a - 1);
    })
    
    const d = Array(n).fill(Infinity);
    const visited = Array(n).fill(false);
    const startNode = 0;
    d[startNode] = 0;
    visited[startNode] = true;

    const queue = [];
    queue.push([startNode, d[startNode]]);
        
    while (queue.length) {
        const [curNode, curCost] = queue.shift();

        graph[curNode].forEach((nextNode) => {
            if (visited[nextNode]) return;
            d[nextNode] = Math.min(curCost + 1, d[nextNode]);
            queue.push([nextNode, d[nextNode]]);
            visited[nextNode] = true;
        });
    }
    
    const largestCost = Math.max(...d);    
    return d.filter((cost) => cost === largestCost).length;
}
