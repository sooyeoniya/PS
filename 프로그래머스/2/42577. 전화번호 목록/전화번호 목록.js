// 효율성 테스트 3, 4 무한 대기 발생
// function solution(phone_book) {
//     var answer = true;
//     const sortedPhoneBook = phone_book.sort((a, b) => a.length - b.length);
    
//     for (let i = 0; i < sortedPhoneBook.length; i++) {
//         for (let j = i + 1; j < sortedPhoneBook.length; j++) {
//             if (sortedPhoneBook[i].length === sortedPhoneBook[j].length) continue;
//             if (sortedPhoneBook[j].startsWith(sortedPhoneBook[i])) {
//                 answer = false;
//                 break;
//             }
//         }
//         if (!answer) break;
//     }
    
//     return answer;
// }

function solution(phone_book) {
    var answer = true;
    
    // 사전순 정렬만 하면됨, 그러면 위에 코드처럼 for문 2번 안돌려도 되고 인접한 다음꺼만 확인하면 됨
    const sortedPhoneBook = phone_book.sort();
    
     for (let i = 0; i < sortedPhoneBook.length - 1; i++) {
         if (sortedPhoneBook[i + 1].startsWith(sortedPhoneBook[i])) {
             answer = false;
             break;
         }
     }
    
    return answer;
}