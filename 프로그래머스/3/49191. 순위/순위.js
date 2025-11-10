function solution(n, results) {
    var answer = 0;
    
    let arr = Array.from({ length: n }, () => {
        won = new Set();
        lost = new Set();
        return { won, lost };
    })
    
    // 각 인덱스(선수 번호 - 1)마다 이긴 사람 번호, 진 사람 번호를 넣는다
    // 기준: arr[1].won 은 1번 인덱스 선수를 이긴 사람들의 번호, lost 는 1번 인덱스 선수에게 진 사람들의 번호
    results.forEach(([wonIdx, lostIdx]) => {
        arr[wonIdx - 1].lost.add(lostIdx - 1);
        arr[lostIdx - 1].won.add(wonIdx - 1);
    });
    
    // arr를 하나씩 순회하면서 각 인덱스 선수들에게 이긴 사람과 진 사람들의 set을 가져와서
    // 현재 인덱스 선수를 이긴 선수(a)에게는 '현재 인덱스 선수에게 진 선수 쪽'을 모두 a에게 진 선수들의 set으로 넣기
    // 현재 인덱스 선수에게 진 선수(a)에게는 '현재 인덱스 선수에게 이긴 선수 쪽'을 모두 a의 이긴 선수들 set으로 넣기
    for (let i = 0; i < n; i++) {
        const { won: curWon, lost: curLost } = arr[i];
        
        curWon.forEach((winnerIdx) => {
            arr[winnerIdx].lost = new Set([...arr[winnerIdx].lost, ...curLost]);
        });
        
        curLost.forEach((loserIdx) => {
            arr[loserIdx].won = new Set([...arr[loserIdx].won, ...curWon]);
        });
    }
    
    // 각 인덱스 별 순회하면서 이긴사람 진사람 합친 수가 n-1(나 빼고 나머지 선수들 수)이랑 같다면 순위 매길 수 있는 선수임! filter로 걸러서 그 length를 계산    
    return arr.filter(({ won, lost }) => won.size + lost.size === n - 1).length;
}