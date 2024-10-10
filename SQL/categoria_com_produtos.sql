SELECT c.name
FROM products p
INNER JOIN categories c ON c.id = p.id_categories
WHERE p.amount > 100 and c.id AND
c.id IN (1,2,3,6,9)
ORDER BY c.id ASC