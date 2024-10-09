//Bibliotecas necessárias
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "Lista.h"


TipoCelula *Frente, *Tras;

int Contador;


void Lista_Construtor() {


    Frente = Tras = NULL;
    Contador = 0;
}


void Lista_Destrutor() {


    TipoCelula *Temp;

    while (Frente != NULL) {
        Temp = Frente;
        Frente = Frente->Prox;

        Temp->Prox = NULL;
        free(Temp);
    }

    Tras = NULL;
    Contador = 0;
}


bool Lista_Vazia() {

    return Tras == NULL;
}


int Lista_Tamanho() {
    return Contador;
}
//para converter string para minuscula
std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool Lista_Inserir_Ordenado_Sem_Repeticao(std::string Elemento) {
    Elemento = toLower(Elemento); // para ignorar as letras maiusculas ou minusculas

    //verificar se ja possui o elemnto digitado
    TipoCelula *Temp = Frente;

    while (Temp != NULL) {
        if (toLower(Temp->Item) == Elemento) {

            return false;
        }

        Temp = Temp->Prox;

    }

    //cria uma nova celula
    TipoCelula *Novo = (TipoCelula*)malloc(sizeof(TipoCelula));
    if (Novo == NULL){
        return false;
    }

    Novo->Item = Elemento;
    Novo->Prox = NULL;

    //insere na posicao correta, ordenada
    if (Lista_Vazia() || toLower(Frente->Item) > Elemento) {

        // insere no inicio
        Novo->Prox = Frente;
        Frente = Novo;

        if (Tras == NULL) {
            Tras = Novo;
        }
    }else{
        //insere no meio ou no fim
            TipoCelula *Antes = Frente;
            TipoCelula *Agora = Frente->Prox;

        while (Agora!= NULL && toLower(Agora->Item) < Elemento){
            Antes = Agora;
            Agora = Agora->Prox;
        }

        Novo->Prox = Agora;
        Antes->Prox = Novo;

        if (Agora == NULL) {  // se for inserido no final
            Tras = Novo;
        }
    }

    Contador++;

    return true;
}


bool Lista_Inserir_Inicio(std::string Elemento) {

    TipoCelula *Novo;
    Novo = (TipoCelula *) malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;
    } else {
        Novo->Item = Elemento;
        Novo->Prox = Frente;


        if (Lista_Vazia())
            Tras = Novo;


        Frente = Novo;
        Contador++;

        return true;
    }
}


bool Lista_Inserir_Fim(std::string Elemento) {

    TipoCelula *Novo;

    Novo = (TipoCelula *) malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;
    } else {
        Novo->Item = Elemento;
        Novo->Prox = NULL;

        if (Lista_Vazia())
            Frente = Novo;
        else Tras->Prox = Novo;


        Tras = Novo;
        Contador++;

        return true;
    }
}


bool Lista_Inserir(std::string Elemento, int Posicao) {

    TipoCelula *Novo;
    TipoCelula *Temp;

    Novo = (TipoCelula *) malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;
    } else {

        if (Posicao < 0 || Posicao >= Contador) return false;

        Temp = Frente;

        for (int i = 0; i < Posicao; i++) {

            Temp = Temp->Prox;
        }

        Novo->Item = Temp->Item;
        Temp->Item = Elemento;
        Novo->Prox = Temp->Prox;
        Temp->Prox = Novo;


        if (Tras == Temp) Tras = Novo;

        Contador++;

        return true;
    }
}


bool Lista_Remover_Inicio(std::string &Elemento) {

    if (!Lista_Vazia()) {

        TipoCelula *Temp = Frente;

        Elemento = Frente->Item;
        Frente = Frente->Prox;
        Temp->Prox = NULL;

        free(Temp);

        if (Frente == NULL)
            Tras = NULL;

        Contador--;

        return true;
    } else
        return false;
}


bool Lista_Remover_Fim(std::string &Elemento) {

    if (!Lista_Vazia()) {

        TipoCelula *Temp = Frente;

        if (Frente == Tras) {

            Elemento = Tras->Item;
            Contador--;
            free(Tras);
            Frente = Tras = NULL;
            return true;
        }

        while (Temp->Prox != Tras) {

            Temp = Temp->Prox;
        }


        Elemento = Tras->Item;
        Tras = Temp;
        Temp = Temp->Prox;
        Tras->Prox = NULL;

        free(Temp);
        Contador--;

        return true;
    } else
        return false;
}


bool Lista_Remover(std::string &Elemento, int Posicao) {

    TipoCelula *Temp, *Temp2;

    if (!Lista_Vazia()) {

        if (Posicao < 0 || Posicao >= Contador) return false;


        if (Frente == Tras) {

            Elemento = Tras->Item;
            Contador--;
            free(Tras);
            Frente = Tras = NULL;
            return true;
        }

        Temp = Frente;

        for (int i = 0; i < Posicao; i++) {

            Temp2 = Temp;
            Temp = Temp->Prox;
        }


        if (Frente == Temp)
            Frente = Frente->Prox;
        else
            Temp2->Prox = Temp->Prox;

        if (Tras == Temp)
            Tras = Temp2;
        else
            Temp->Prox = NULL;


        Elemento = Temp->Item;
        free(Temp);
        Contador--;
        return true;
    }
    return false;
}


bool Lista_Inicio(std::string &Elemento) {


    if (!Lista_Vazia()) {
        Elemento = Frente->Item;
        return true;
    } else
        return false;
}


bool Lista_Fim(std::string &Elemento) {


    if (!Lista_Vazia()) {

        Elemento = Tras->Item;
        return true;
    } else
        return false;
}


bool Lista_BuscarPeloElemento(std::string Elemento, int &Posicao) { // 50


    TipoCelula *Temp = Frente;
    int i = 0;

    if (!Lista_Vazia()) {

        while (Temp != NULL && Temp->Item != Elemento) {

            i++;
            Temp = Temp->Prox;
        }

        if (Temp != NULL) {

            Posicao = i;
            return true;
        } else
            return false;
    } else
        return false;
}


bool Lista_BuscarPelaPosicao(std::string &Elemento, int Posicao) {


    TipoCelula *Temp = Frente;
    int i = 0;

    if (!Lista_Vazia()) {


        if (Posicao < 0 || Posicao >= Contador) return false;

        while (i < Posicao) {

            i++;
            Temp = Temp->Prox;
        }


        Elemento = Temp->Item;
        return true;
    } else
        return false;
}
