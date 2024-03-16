def mochila_booleana(pesos, valores, capacidade):
    n = len(pesos)
    max_valor = 0
    
    # Iterar por todos os subconjuntos possíveis de itens
    for i in range(1 << n):
        peso_atual = 0
        valor_atual = 0
        
        # Calcular peso e valor do subconjunto atual
        for j in range(n):
            if i & (1 << j):
                peso_atual += pesos[j]
                valor_atual += valores[j]
                
        # Verificar se o subconjunto é válido (peso <= capacidade)
        if peso_atual <= capacidade:
            max_valor = max(max_valor, valor_atual)
    
    return max_valor

# Exemplo de uso:
pesos = [2, 3, 1, 4]  # Pesos dos itens
valores = [4, 2, 3, 7]  # Valores dos itens
capacidade = 5  # Capacidade da mochila

resultado = mochila_booleana(pesos, valores, capacidade)
print("O valor máximo que pode ser colocado na mochila é:", resultado)
