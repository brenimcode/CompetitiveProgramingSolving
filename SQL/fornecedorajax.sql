SELECT p.name, f.name
FROM products p, providers f
WHERE p.id_providers  = f.id
AND f.name = 'Ajax SA';