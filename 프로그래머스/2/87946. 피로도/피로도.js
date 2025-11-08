var answer = -1;

function solution(k, dungeons) {
    const visited = Array(dungeons.length).fill(false);
    reculsive(visited, k, dungeons);

    return answer;
}

function reculsive(visited, k, dungeons, count = 0) {
    answer = Math.max(answer, count);

    for (let nextDungeon = 0; nextDungeon < dungeons.length; nextDungeon++) {
        const [minFatigue, consumptionFatigue] = dungeons[nextDungeon];
        if (visited[nextDungeon] || k < minFatigue) continue;

        visited[nextDungeon] = true;
        reculsive(visited, k - consumptionFatigue, dungeons, count + 1);
        visited[nextDungeon] = false;
    }
}