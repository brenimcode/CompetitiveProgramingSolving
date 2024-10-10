SELECT c.id , c.name
FROM customers c
LEFT JOIN locations l ON c.id = l.id_customers
WHERE l.id_customers IS NULL
ORDER BY c.id


 -- Para isso devemos usar LEFT JOIN:
 -- LEFT JOIN: Faz um join entre as tabelas customers e locations, 
 -- Todos os registros da tabela customers sejam retornados, mesmo que não tenham correspondência na tabela locations.
 -- Ai onde é NULL ele vai retornar o id e o noem do customer.