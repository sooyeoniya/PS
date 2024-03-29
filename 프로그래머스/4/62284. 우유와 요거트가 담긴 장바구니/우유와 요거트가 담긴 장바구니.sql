SELECT CART_ID
FROM CART_PRODUCTS
WHERE NAME IN ('Milk', 'Yogurt')
GROUP BY CART_ID
HAVING COUNT(DISTINCT NAME) = 2
ORDER BY CART_ID
# WHERE절로 NAME을 한 번 필터링 후 
# 거기서 그룹화하여 중복없이 NAME의 개수 카운트하여 2개인지 확인