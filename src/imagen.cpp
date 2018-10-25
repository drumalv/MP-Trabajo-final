#include <iostream>
#include "imagen.h"
#include "byte.h"
#include "pgm.h"

using namespace std;

Imagen::Imagen()
{
    datos = 0;
    nfilas =0;
    ncolumnas=0;
}

Imagen::Imagen (int filas, int columnas)
{
    
    crear(filas,columnas);
}

void Imagen::crear (int filas, int columnas)
{
    destruir();
    datos = new Byte*[filas];
    datos[0]=new Byte[filas*columnas];
    for(int i = 1;i<filas;i++){
        datos[i]=datos[i-1]+columnas;
    }
    nfilas=filas;
    ncolumnas=columnas;
    
    for(int i=0; i<filas; i++){
        for(int j=0;j<columnas; j++){
            offByte(datos[i][j]);
        }
    }
}

Imagen& Imagen::operator=(const Imagen &im){
    if(&im!=this){

        crear(im.filas(), im.columnas());
        for(int i=0; i<nfilas; i++){
            for(int j=0;j<ncolumnas; j++){
                this->datos[i][j]=im.get(i,j);
            }
        }
        
    }
    return *this;
}


Imagen::Imagen(const Imagen &im){
    crear(im.filas(), im.columnas());
    for(int i=0; i<nfilas; i++){
        for(int j=0;j<ncolumnas; j++){
            datos[i][j]=im.get(i,j);
        }
    }
    
}

void Imagen::destruir(){
    if(datos !=0){
        delete[] datos[0];
        delete [] datos;
        datos=0;
    }
    
    nfilas=0;
    ncolumnas=0;
}

Imagen::~Imagen(){
    destruir();
}

int Imagen::filas() const{
	return nfilas;
}	

int Imagen::columnas() const{
	return ncolumnas;
}

void Imagen::set(int f, int c, Byte v){
    if(datos != 0){
        if(f<nfilas && c<ncolumnas)
            datos[f][c]=v;
    }
}

Byte Imagen::get(int f, int c) const{
    if(f<nfilas && c<ncolumnas)
        return datos[f][c];
    else
        return 0;
}


bool Imagen::leerImagen (const char nombreFichero[])
{
	bool exito = false;
	
	
	if(infoPGM( nombreFichero, nfilas, ncolumnas) == IMG_PGM_BINARIO){
            crear(nfilas,ncolumnas);
            exito = leerPGMBinario (nombreFichero, datos[0], nfilas, ncolumnas);
            
	}	
	if(infoPGM( nombreFichero, nfilas, ncolumnas) == IMG_PGM_TEXTO){
            crear(nfilas,ncolumnas);
            exito = leerPGMTexto (nombreFichero, datos[0], nfilas, ncolumnas);
	}
	
	return exito;
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario) const
{
	bool exito = false;
        if (datos!=0){
            if(esBinario)
            	exito = escribirPGMBinario(nombreFichero, datos[0], filas(), columnas());
            else
		exito = escribirPGMTexto(nombreFichero, datos[0], filas(), columnas());
        }
        return exito;
}

Imagen Imagen::plano (int k) const{
	Imagen im(nfilas,ncolumnas);
	for(int i=0; i<nfilas*ncolumnas; i++){
		offByte(im.datos[0][i]);
	}	
	for(int i=0; i<nfilas*ncolumnas; i++){		
		if(getBit(datos[0][i],k)==true)
			onBit(im.datos[0][i],7);
		else
			offBit(im.datos[0][i],7);
	}
	return im;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong) const{
	int componentes_grises = 0;
	int i;
	while(grises[componentes_grises]!='\0')
		componentes_grises++;
	int posicion;
	bool comprobacion=false;
	if(nfilas*ncolumnas+nfilas+1 <= maxlong){
		for(i=0; i<(nfilas*ncolumnas); i++){
			posicion=datos[0][i]*componentes_grises/256;			
			if(i<maxlong){
				if(i%ncolumnas!=0)			
					arteASCII[i]=grises[posicion];
				else
					arteASCII[i]='\n';
			comprobacion=true;
			}
		}
		arteASCII[i]='\n';
                arteASCII[i+1]='\0';   /// Falta el \0 justo detrás de lo de antes
	}
	return comprobacion;
}














