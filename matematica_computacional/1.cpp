#include <bits/stdc++.h>

using namespace std;

const int MAX_ALUNOS = 1000;

int main()
{
	int i, indice_melhor, n;
	int turma=1;

	typedef struct aluno
	{
	    int codigo, media;
	} aluno;

	// le numero de alunos da primeira turma
	cin >> n;
    aluno alunos[MAX_ALUNOS];
	while (n > 0)
	{
		// le dados dos alunos
		for (i = 0; i < n; i++)
			cin >> alunos[i].codigo >> alunos[i].media;
		// procura aluno de maior media
		indice_melhor = 0;
		for (i = 1; i < n; i++)
			if (alunos[i].media > alunos[indice_melhor].media)
		        indice_melhor = i;

        vector<aluno> melhores;
        for (i = 1; i < n; i++){
			if (alunos[i].media == alunos[indice_melhor].media){
                melhores.push_back(alunos[i]);
            }
        }
		// escreve resposta
		cout << "Turma " << turma++ << "\n";
        for(i = 0;i< (int) melhores.size(); i++){
            cout << melhores[i].codigo << ' ';
        }

		cout << "\n\n";
		// le numero de alunos da proxima turma
		cin >> n;
	}
	return 0;
}
