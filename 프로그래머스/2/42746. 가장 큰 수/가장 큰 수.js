function solution(numbers) {
    const answer = numbers.map(String).sort((a, b) => (b + a) - (a + b)).join("");
    return answer[0] === "0" ? "0" : answer;
}