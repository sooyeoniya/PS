function solution(n, wires) {
    var answer = Infinity;
    const graph = Array.from({ length: n + 1 }, () => []);

    for (let [v1, v2] of wires) {
        graph[v1].push(v2);
        graph[v2].push(v1);
    }
    
    for (let [v1, v2] of wires) {
        const visited = Array(n + 1).fill(false);   
        visited[v1] = true;
        visited[v2] = true;
        
        const a = reculsive(v1, visited, graph);
        const b = reculsive(v2, visited, graph);

        answer = Math.min(answer, Math.abs(a - b));
    }

    return answer;
}

function reculsive(node, visited, graph) {
    let count = 1;
    
    for (let nearNode of graph[node]) {
        if (visited[nearNode]) continue;
        
        visited[nearNode] = true;
        count += reculsive(nearNode, visited, graph);
        visited[nearNode] = false;
    }
    
    return count;
}