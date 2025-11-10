function solution(progresses, speeds) {
    var answer = [];
    
    // progresses 각각을 순회하면서 100 - progresses 해서 나온 결과를 speeds 로 나누면 남은 일수 나옴
    let remains = progresses.map((progress, index) => Math.ceil((100 - progress) / speeds[index]));

    // while 문 돌면서 remains 길이가 0이 될 때까지 하나씩 빼기
    while (remains.length !== 0) {
        let index = 1;
        while (1) {
            // index 값이 5인데, remains.length 가 5다 그러면 이미 이전 루프에서 마지막에 도달해둔 상태이므로 반환
            if (remains.length <= index) break;
            if (remains[0] >= remains[index]) index += 1;
            else break;
        }
        
        answer.push(index);
        for (let i = 0; i < index; i++) remains.shift();
    }

    return answer;
}