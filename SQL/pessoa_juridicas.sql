SELECT c.name
FROM customers c
LEFT JOIN legal_person l ON c.id = l.id_customers
WHERE l.id_customers IS NULL