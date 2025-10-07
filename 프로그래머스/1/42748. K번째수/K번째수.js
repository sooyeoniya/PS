function solution(array, commands) {
    let answer = [];
    commands.forEach(([i, j, k]) => {
        answer.push(array.slice(i - 1, j).sort((a, b) => a - b)[k - 1]);
    });
    return answer;
}