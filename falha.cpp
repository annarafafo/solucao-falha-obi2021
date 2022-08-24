// este é um programa para resolver o problema Falha de Segurança, da fase 3 do nível 2 da Olimpíada Brasileira de informática ano 2021

#include <iostream>
#include <string>

using namespace std;

// este é o protótipo da função que irá analisar se uma senha contém outra como subcadeia contígua
bool contem(string s1, string s2);

int main()
{
    int n = 0, pares = 0; // n é a variável que receberá o número de usuários e pares o número de pares ordenados que serão formados
    string *s;            // s* é um ponteiro que receberá as senhas
    size_t i, j;          // i e j serão contadores para as repetições

    cin >> n; // o primeiro dado de entrada, o número de usuários, é lido

    s = new string[n]; // é alocado o espaço de memória para um vetor de n posições para armazenar as senhas

    for (i = 0; i < n; i++)
    {
        cin >> s[i];            // são lidas as senhas
        for (j = 0; j < i; j++) // para cada elemento s[i], itera-se do início do vetor até s[i-1]
        {
            if (s[i].size() == s[j].size()) // no caso de senhas A e B terem o mesmo tamanho, há duas opções, são diferentes e não contém uma a outra, ou são iguais
            {
                if (s[i] == s[j])
                {
                    pares += 2; // no caso de as senhas serem iguais, adiciona-se 2 ao número de pares já que haverão os pares (A, B) e (B, A)
                }
            }
            else if (contem(s[i], s[j]))
            {
                pares++; // se a função contem retornar verdadeiro, soma-se um ao numero de pares
            }
        }
    }

    delete[] s; // o espaço alocado para o vetor s é liberado

    cout << pares << endl; // é impresso o valor de pares

    return 0;
}

bool contem(string s1, string s2)
{
    // primeiro determina-se qual das strings é maior, e em seguida verifica-se se é possível encontrar a menor string como substring da maior. Caso possível, a função retorna um verdadeiro e caso não, retorna falso
    if (s1.size() > s2.size() && s1.find(s2) != string::npos)
    {
        return true;
    }
    else if (s1.size() < s2.size() && s2.find(s1) != string::npos)
    {
        return true;
    }

    return false;
}
