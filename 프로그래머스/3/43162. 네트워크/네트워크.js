let answer = 0;

function solution(n, computers) {    
    const visited = Array(n).fill(false);
    
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            reculsive(n, i, computers, visited);
            answer += 1;
        }
    }
    
    return answer;
}

function reculsive(n, node, computers, visited) {
    visited[node] = true;
    
    for (let i = 0; i < n; i++) {
        if ((computers[node][i] === 1 || computers[i][node]) && !visited[i]) {
            reculsive(n, i, computers, visited)
        }
    }
}