#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,*vet,i,*algarismos,len;
    string str = " ";
    cin >> n;
    vet = new int[n];
    algarismos = (int *) calloc(10,sizeof(int));
    for (i = 0; i < n; i++)
    {
        cin >> vet[i];
        str += to_string(vet[i]);
    }

    len = str.size();

    for (i = 0; i < len; i++)
    {
        if(str[i] == '0'){
            algarismos[0]++;
        }
        else if(str[i] == '1'){
            algarismos[1]++;
        }
        else if(str[i] == '2'){
            algarismos[2]++;
        }
        else if(str[i] == '3'){
            algarismos[3]++;
        }
        else if(str[i] == '4'){
            algarismos[4]++;
        }
        else if(str[i] == '5'){
            algarismos[5]++;
        }
        else if(str[i] == '6'){
            algarismos[6]++;
        }
        else if(str[i] == '7'){
            algarismos[7]++;
        }
        else if(str[i] == '8'){
            algarismos[8]++;
        }
        else if(str[i] == '9'){
            algarismos[9]++;
        }
    }
    for (i = 0; i < 10; i++)
    {
        cout << i << " - " << algarismos[i] << endl;
    }
    free(algarismos);
    delete(vet);
}