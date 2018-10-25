#include <iostream>
#include "imagen.h"
#include "byte.h"
#include "pgm.h"
#include "lista.h"

using namespace std;

Celda::Celda(){
    img=0;
    sig=0;
}

Celda::~Celda(){
    if(img!=0){
        delete img;
        img=0;
    }
    
}

void Celda::setImagen(const Imagen& img){
/*    Imagen imagen(img);
    Imagen *pt=new Imagen;
    *pt = imagen; */
    if (this->img == NULL) this->img = new Imagen();
    *(this->img)=img;
}

Imagen* Celda::getImagen() const{
    Imagen* ptr=0;
    ptr = img;
    return ptr;
}

void Celda::setSiguiente(Celda* next){
    sig=next;
}

Celda* Celda::getSiguiente() const{
    Celda* ptr=0;
    ptr=sig;
    return ptr;
}

Lista::Lista(){
    lista=0;
}

Lista::~Lista(){
    while (lista != 0) {
        Celda* aux = lista;
        lista = aux->getSiguiente();
        delete aux;
    }
}

void Lista::insertarPrincipio(const Imagen& img){
    Celda* aux = new Celda;
    aux->setImagen(img);
    aux->setSiguiente(lista);
    lista = aux;
}

void Lista::insertarFinal(const Imagen& img){
    if(lista==0)
        insertarPrincipio(img);
    else{
        Celda* aux=lista;
        while(aux->getSiguiente()!=0){
            aux=aux->getSiguiente();    
        }
        Celda* aux2 = new Celda;
        aux->setSiguiente(aux2);
        aux2->setSiguiente(0);
        aux2->setImagen(img);
    }
}

int Lista::longitud() const{
    int longit;
    if(lista==0)
        longit = 0;
    else{
        longit=1;
        Celda* aux=lista;
        while(aux->getSiguiente()!=0){
            aux=aux->getSiguiente();
            longit++;
        }
    }
    return longit;
}

Imagen* Lista::get(int pos) const{
    Imagen* ptr;
    int contador=1;
    if(longitud()<pos)
        ptr=0;
    else{
        if(lista==0)
            ptr=0;
        else{
            Celda* aux=lista;
            while(contador<pos){
                aux=aux->getSiguiente(); 
                contador++;
            }

            ptr=aux->getImagen();
        }
    }
    return ptr;
}