def trabalho_do_papa(caixas):
    # Ordena as caixas pelo peso máximo que podem suportar
    caixas.sort(key=lambda x: x[1])
    
    # Inicializa a variável para contar o número de caixas empilhadas
    num_caixas_empilhadas = 0
    
    # Inicializa a variável para acompanhar o peso total na pilha
    peso_total = 0
    
    # Percorre as caixas
    for caixa in caixas:
        peso, resistencia = caixa
        
        # Verifica se é possível empilhar a caixa atual sem exceder a resistência
        if peso_total + peso <= resistencia:
            num_caixas_empilhadas += 1
            peso_total += peso
    
    return num_caixas_empilhadas

# Exemplo de uso
caixas = [(43, 60), (47, 100), (3, 2)]
print("Número máximo de caixas empilhadas:", trabalho_do_papa(caixas))
