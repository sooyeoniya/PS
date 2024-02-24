SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS
WHERE SKILL_CODE & (SELECT SUM(CODE) FROM SKILLCODES 
                    WHERE NAME IN ('Python', 'C#'))
ORDER BY ID;
# 비트 AND(&) 연산 수행, 각 비트를 비교하여 둘 다 1이면 결과가 1이 되고, 그렇지 않으면 0
# SUM(CODE) 1280일 때 비트: 10100000000 (이진수)
# SKILL_CODE 400일 때 비트: 110010000 (이진수)
# AND 연산 결과: 100000000 (값: 256)
# AND 연산의 결과는 256이므로, WHERE 절이 TRUE가 되고 해당 개발자가 선택됨