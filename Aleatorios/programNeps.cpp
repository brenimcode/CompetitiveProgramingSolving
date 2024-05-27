#include <stdio.h>
#include <stdlib.h>

struct Personagem {
    char nome[50];
    int ataque;
    int defesa;
    int vida;

    bool sobreviveu(int dano) {
        // Calcula o dano recebido pelo personagem após a defesa
        int dano_recebido = dano - defesa;
        // Atualiza a vida do personagem após o golpe
        vida -= dano_recebido;
        // Retorna true se a vida do personagem for maior que 0 (ou seja, ele sobreviveu)
        return vida > 0;
    }

};



int main(){
    Personagem personagem;

    int dano;

    scanf("%s", &personagem.nome);
    scanf("%d", &personagem.ataque);
    scanf("%d", &personagem.defesa);
    scanf("%d", &personagem.vida);

    scanf("%d", &dano);

    if(personagem.sobreviveu(dano)){
        printf("%s sobreviveu!!!", personagem.nome);
    }else{
        printf("%s morreu :(", personagem.nome);
    }
}


