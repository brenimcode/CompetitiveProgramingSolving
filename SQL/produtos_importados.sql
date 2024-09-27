
SELECT p.name , f.name, c.name
FROM products p, providers f, categories c
WHERE p.id_providers = f.id AND p.id_categories = c.id AND
f.name = 'Sansul SA' AND c.name=  'Imported'