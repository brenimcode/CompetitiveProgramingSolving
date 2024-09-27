SELECT m.ID, m.name
FROM MOVIES m, PRICES p
WHERE m.id_prices = p.id
AND p.value < 2.00