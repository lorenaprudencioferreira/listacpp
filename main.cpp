/*Cabecalho
 Nome do aluno: lorena prudencio ferreira

 Objetivo do programa: o objetivo eh criar uma função capaz de ordenar os elementos inseridos em ordem alfabetica, independente
 da posicao que foram inseridos. ao exibir os elementos da lista eles devem estar em ordem alfabetica. a ordenacao eh feita de
 forma automatica pela funcao.

 Como deve ser feita a entrada de dados: o usuario deve escolher uma das opcoes do menu abaixo, a primeira opcao que eh a que
 vai alimentar a nova funcao implementada, ele deve inserir quantos elemetos(string) quiser mas uma palavra por vez, ao inserir uma,
 deve escolher a opcao de inserir uma palavra novamente e entao inserir a proxima string. e assim sucessivamente...

 Resultado da execução do programa: o esperado eh que ao exibir todos os elemetos da lista, eles estejam todos ordenados
 em ordem alfabetica.
 */





#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

#include "Lista.h"

using namespace std;

int main() {
    string x; // Variável utilizada para receber o valor digitado do usuário e colocar na Lista
    int opcao; // Variável utilizada no Menu
    int posicao; // Variável utilizada para retornar a posição onde o elemento foi encontrado

    Lista_Construtor(); // Para iniciar a Lista

    do {
        // Menu com opções para testar a implementação da Lista

        cout << "Programa para uso da Lista Singularmente Encadeada\n\n";
        cout << "Escolha uma das opcoes abaixo.\n";
        cout << "Menu: \n";
        cout << "1 - Inserir uma palavra\n";
        cout << "2 - Remover no inicio\n";
        cout << "3 - Remover no fim\n";
        cout << "4 - Remover dado em uma posicao\n";
        cout << "5 - Elemento no inicio\n";
        cout << "6 - Elemento no fim\n";
        cout << "7 - Procurar elemento\n";
        cout << "8 - Numero de elementos na lista\n";
        cout << "9 - Exibir elemento em uma posicao\n";
        cout << "10 - Exibir elementos da Lista\n"; // serao exibidos em ordem
        cout << "11 - Remover e exibir todos os elementos\n";
        cout << "12 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "\nDigite a palavra: ";
                cin.ignore();  // limpar o buffer
                getline(cin, x);

                if (Lista_Inserir_Ordenado_Sem_Repeticao(x))
                    cout << "\nPalavra inserida com sucesso.\n";
                else
                    cout << "\nPalavra ja existe na lista.\n";

                break;

            case 2:
                if (Lista_Remover_Inicio(x))
                    cout << "\nPalavra '" << x << "' removida\n\n";
                else
                    cout << "Erro. Lista vazia.\n\n";
                break;

            case 3:
                if (Lista_Remover_Fim(x))
                    cout << "\nPalavra removida: " << x << "\n";
                else
                    cout << "\nErro. Lista vazia.\n";
                break;

            case 4:
                cout << "\nDigite a posicao para remover: ";
                cin >> posicao;

                if (Lista_Remover(x, posicao))
                    cout << "\nPalavra removida: " << x << "\n";
                else
                    cout << "\nErro. Posicao invalida ou lista vazia.\n";
                break;

            case 5:
                if (Lista_Inicio(x))
                    cout << "\nPalavra no inicio: " << x << "\n";
                else
                    cout << "\nLista vazia.\n";
                break;

            case 6:
                if (Lista_Fim(x))
                    cout << "\nPalavra no fim: " << x << "\n";
                else
                    cout << "\nLista vazia.\n";
                break;

            case 7:
                cout << "\nDigite a palavra para procurar: ";
                cin.ignore();  //limpar o buffer
                getline(cin, x);

                if (Lista_BuscarPeloElemento(x, posicao))
                    cout << "\nPalavra encontrada na posicao: " << posicao << "\n";
                else
                    cout << "\nPalavra nao encontrada.\n";
                break;

            case 8:
                cout << "\nNumero de palavras na lista: " << Lista_Tamanho() << "\n";
                break;

            case 9:
                cout << "\nDigite a posicao desejada: ";
                cin >> posicao;

                if (Lista_BuscarPelaPosicao(x, posicao))
                    cout << "\nPalavra na posicao " << posicao << ": " << x << "\n";
                else
                    cout << "\nPosicao invalida ou lista vazia.\n";
                break;

            case 10:
                cout << "\nPalavras na lista:\n";
                posicao = 0;
                while (Lista_BuscarPelaPosicao(x, posicao)) {
                    cout << "Posicao " << posicao << ": " << x << "\n";
                    posicao++;
                }
                cout << "\n";
                break;

            case 11:
                cout << "\nRemovendo todas as palavras:\n";
                while (Lista_Remover_Inicio(x)) {
                    cout << "Palavra removida: " << x << "\n";
                }
                cout << "\nLista esvaziada.\n";
                break;

            case 12:
                Lista_Destrutor();
                cout << "\nPrograma encerrado.\n";
                break;

            default:
                cout << "\nOpcao invalida.\n";
        }

        cout << "\n";
    } while (opcao != 12);

    return 0;
}
