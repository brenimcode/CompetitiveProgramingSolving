def find_final_position(N, M, Xi, Yi, K, L, obstacles):
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # direções: direita, baixo, esquerda, cima
    direction_index = 0  # índice da direção atual (começa virado para a direita)
    x, y = Xi, Yi  # posição inicial de Scrappy

    for _ in range(L):
        # Movimento de Scrappy
        while True:
            new_x = x + directions[direction_index][0]
            new_y = y + directions[direction_index][1]
            if not (1 <= new_x <= N and 1 <= new_y <= M) or (new_x, new_y) in obstacles:
                break  # se for sair do tabuleiro ou encontrar um obstáculo, parar o movimento
            x, y = new_x, new_y  # atualizar a posição
        # Virar 90 graus em sentido horário
        direction_index = (direction_index + 1) % 4

    return x, y

# Leitura de entrada
N, M = map(int, input().split())
Xi, Yi = map(int, input().split())
K, L = map(int, input().split())
obstacles = set(tuple(map(int, input().split())) for _ in range(K))

# Encontrar a posição final de Scrappy
final_x, final_y = find_final_position(N, M, Xi, Yi, K, L, obstacles)

# Saída
print(final_x, final_y)
