SELECT c.name, r.rentals_date
FROM customers c, rentals r
WHERE r.id_customers = c.id AND
r.rentals_date BETWEEN '2016-09-01' AND '2016-09-30';