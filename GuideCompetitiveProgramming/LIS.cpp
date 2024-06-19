

int LIS(vector<int> seq) {
    // vetor para armazenar a subsequência crescente
    vector<int> lis;

    for (int i = 0; i < seq.size(); ++i) {
        // encontra a posição onde seq[i] pode ser inserido para manter lis ordenada
        auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
        
        // se o iterador it aponta para o fim do vetor, adicionamos seq[i] no final
        if (it == lis.end()) {
            lis.push_back(seq[i]);
        } else {
            // caso contrário, substituímos o elemento apontado por it com seq[i]
            *it = seq[i];
        }
    }
    return lis.size(); // resposta
}