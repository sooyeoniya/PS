function solution(n, computers) {
    var answer = 0;
    const visited = Array(n).fill(false);
    
    for (let i = 0; i < computers.length; i++) {
        if (!visited[i]) {
            reculsive(i, n, computers, visited);
            answer += 1;
        }
    }

    return answer;
}

function reculsive(node, n, computers, visited) {    
    for (let i = 0; i < n; i++) {
        if ((computers[node][i] === 1 || computers[i][node] === 1) && !visited[i]) {
            visited[i] = true;
            reculsive(i, n, computers, visited);
        }
    }
}
