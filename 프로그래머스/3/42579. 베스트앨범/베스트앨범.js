function solution(genres, plays) {
    let answer = [];
    const totalPlayCountByGenre = new Map();
    const playCountBySong = new Map();

    new Set(genres).forEach((genre) =>  playCountBySong.set(genre, new Map()));

    for (let i = 0; i < genres.length; i++) {
        totalPlayCountByGenre.set(genres[i], (totalPlayCountByGenre.get(genres[i]) ?? 0) + plays[i]);
        playCountBySong.get(genres[i]).set(i, plays[i]);
    }
    
    const sortedGenres = [...totalPlayCountByGenre].sort((a, b) => b[1] - a[1]).map(([genre]) => genre);
    
    for (let i = 0; i < sortedGenres.length; i++) {
        const genre = sortedGenres[i];
        const map = playCountBySong.get(genre);
        
        const sortedPrimaryKeys = [...map.keys()].sort((a, b) => {
            return map.get(b) - map.get(a);
        });

        answer = answer.concat(sortedPrimaryKeys.slice(0, 2));
    }
    
    return answer;
}

// function solution(genres, plays) {
//     var answer = [];

//     const n = plays.length

//     const genrePlays = new Map()
//     const songPlays = new Map()
//     new Set(genres).forEach(e => songPlays.set(e, new Map()))
//     for (let i = 0; i < n; i++) {
//         const g = genres[i]
//         const p = plays[i]
//         genrePlays.set(g, (genrePlays.get(g) ?? 0) + p)
//         songPlays.get(g).set(i, p)
//     }
//     console.log(genrePlays)
//     console.log(songPlays)

//     const sortedGenre = [...genrePlays.keys()].sort((a, b) => genrePlays.get(b) - genrePlays.get(a))
//     console.log(sortedGenre)
//     for (let g of sortedGenre) {
//         const s = songPlays.get(g)
//         const sorted = [...s.keys()].sort((a, b) => {
//             const diff = s.get(a) - s.get(b)
//             if (diff != 0) return -diff
//             else return a - b
//         })
//         answer = answer.concat(sorted.slice(0, 2))
//     }

//     return answer;
// }