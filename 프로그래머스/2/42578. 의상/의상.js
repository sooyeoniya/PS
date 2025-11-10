function solution(clothes) {
    const map = new Map();
    
    clothes.forEach(([_, type]) => {
        map.set(type, (map.get(type) ?? 0) + 1);
    });

    return [...map.values()].reduce((sum, curTypeCount) => sum * (curTypeCount + 1), 1) - 1;
}