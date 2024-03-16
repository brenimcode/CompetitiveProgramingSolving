def mochila_recursiva(p, v, n, c):
    # Caso base: se não há mais itens ou a capacidade da mochila é 0
    if n == 0 or c == 0:
        return 0
    
    # Se o peso do último item excede a capacidade da mochila, exclua-o
    if p[n - 1] > c:
        return mochila_recursiva(p, v, n - 1, c)
    
    # Caso contrário, retorne o máximo entre INCLUIR ou EXCLUIR o último item
    return max(v[n - 1] + mochila_recursiva(p, v, n - 1, c - p[n - 1]), mochila_recursiva(p, v, n - 1, c))

# Exemplo de uso:
p = [3, 2, 1, 4]  # Pesos dos itens
v = [5, 3, 2, 7]  # Valores dos itens
n = len(p)        # Número de itens
c = 5             # Capacidade da mochila

resultado = mochila_recursiva(p, v, n, c)
print("O valor máximo que pode ser colocado na mochila é:", resultado)
