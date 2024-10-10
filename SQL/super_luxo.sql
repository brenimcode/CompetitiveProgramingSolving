SELECT p.name , r.name, p.price
FROM products p, providers r, categories c
WHERE p.id_providers = r.id AND p.id_categories = c.id AND
WHERE p.price > 1000 AND c.name = 'Super Luxury';
