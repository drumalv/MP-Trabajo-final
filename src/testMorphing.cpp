#include <iostream>
#include "imagen.h"
#include "byte.h"
#include "pgm.h"
#include "lista.h"
#include <cstring>
#include <stdlib.h>
#include<cstdio>

using namespace std;

int main(int argc, char *argv[]){
    if(argc==5){
        
        Lista lista;
        Imagen origen, imagen2;
        Byte pixel;
        
        if (!origen.leerImagen(argv[1])){
		cerr << "error leyendo " << argv[1] << endl;
                
		return 1;
	}
        
        if (!imagen2.leerImagen(argv[2])){
		cerr << "error leyendo " << argv[2] << endl;

		return 1;
	}
        
        for(int k = 0; k<=atoi(argv[3]); k++){
            Imagen img(origen.filas(),origen.columnas());
            //Imagen *im=new Imagen;
            //*im=img;
            

            
            for(int i=0;i<origen.filas(); i++){
                for(int j=0;j<origen.columnas();j++){
                    pixel=origen.get(i,j) +k*((imagen2.get(i,j)-origen.get(i,j))/atoi(argv[3]));
                    img.set(i,j,pixel);
                }
            }
            
           lista.insertarFinal(img);
           //im->destruir();
        }
        for(int i=0;i<lista.longitud();i++){ /// Ojo: debería ser de =0 a <long())
            char nombre_fichero [100]=""; ///= argv[4]; /// strcpy()
            char num[100];
            sprintf(num,"%d",i);
            strcpy(nombre_fichero, argv[4]); /// Tambien valdría strcat())
            strcat(nombre_fichero,num);
            strcat(nombre_fichero,".pgm");
           
            Imagen *p =lista.get(i+1); 
            if(p)
                if (p->escribirImagen(nombre_fichero,true))
                    cout<<nombre_fichero <<"\n";
                else
                    cout<<"Error en la escritura";
            else
                cout << " Error al acceder a la imagen " << i << endl;
            
            
                
        }
        
    }else
        cout <<"Número de parámetros incorrecto";
}