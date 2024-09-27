SELECT c.name , SUM(p.amount) AS total_amount
FROM products p, categories c
WHERE p.id_categories = c.id
GROUP by c.name