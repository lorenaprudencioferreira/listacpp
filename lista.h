#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <string>

typedef std::string TipoDado; //Define o tipo de dado que será armazenado na Lista

struct TipoCelula{

   TipoDado Item;
   TipoCelula *Prox;
};

void Lista_Construtor();
void Lista_Destrutor();
bool Lista_Vazia();
int Lista_Tamanho();
bool Lista_Inserir_Ordenado_Sem_Repeticao(std::string Elemento);
bool Lista_Inserir_Inicio(std::string Elemento);
bool Lista_Inserir_Fim(std::string Elemento);
bool Lista_Inserir(std::string Elemento, int Posicao);
bool Lista_Remover_Inicio(std::string &Elemento);
bool Lista_Remover_Fim(std::string &Elemento);
bool Lista_Remover(std::string &Elemento, int Posicao);
bool Lista_Inicio(std::string &Elemento);
bool Lista_Fim(std::string &Elemento);
bool Lista_BuscarPeloElemento(std::string Elemento, int &Posicao);
bool Lista_BuscarPelaPosicao(std::string &Elemento, int Posicao);

#endif // LISTA_H_INCLUDED
