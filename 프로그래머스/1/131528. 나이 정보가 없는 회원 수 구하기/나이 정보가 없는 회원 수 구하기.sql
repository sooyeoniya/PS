-- 코드를 입력하세요
SELECT COUNT(USER_ID) AS USERS
FROM USER_INFO
WHERE AGE IS NULL
GROUP BY AGE