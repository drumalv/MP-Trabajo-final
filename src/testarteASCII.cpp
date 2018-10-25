/**
   @file testarteASCII.cpp
   @brief lee imagenes/gio.pgm y la convierte en ascii con los caracteres "@%#*+=-:. "
   @author MP-DGIM - Grupo A

**/
#include<iostream>
#include<imagen.h>
#include<fstream>
#include<cstring>

using namespace std;

int main(int argc, char*argv[]){
	
    if(argc == 4){
        const int MAX=4500;
        char arteASCII[MAX+1]; // 4500 + el \0    
        Imagen origen;
     
        ifstream fentrada;
        ofstream fsalida;
        int num_cadenas;
        char cadena1[MAX];
        char cadena2[MAX];
        char cadena3[MAX];
        char cadena4[MAX];

        

        if (!origen.leerImagen(argv[1])){
               cerr << "error leyendo "<< argv[1] << endl;

               return 1;
        }else
                    cout<<"Imagen le�da correctamente\n";



          

            fentrada.open(argv[2]);
            if (fentrada){
                    fentrada >> num_cadenas;
                    fentrada >> cadena1;
                    fentrada >> cadena2;
                    fentrada >> cadena3;
                    fentrada >> cadena4;
                    if(!fentrada){
                            cerr<<"error de lectura del fichero\n";
                    }
                    fentrada.close();
            }
            else{
                    cerr<<"error de apertura del fichero\n";
            }

            fsalida.open(argv[3]);
            if (fsalida){

                    fsalida << "\nLa imagen en arte ASCII 1 es:\n";
                    if(origen.aArteASCII(cadena1, arteASCII, MAX))
                        fsalida << arteASCII;
                    else
                        fsalida << "La conversi�n no ha sido posible" << endl; 

                    fsalida << "\nLa imagen en arte ASCII 2 es:\n";
                    if(origen.aArteASCII(cadena2, arteASCII, MAX))
                        fsalida << arteASCII;
                    else
                        fsalida << "La conversi�n no ha sido posible" << endl;  

                    fsalida << "\nLa imagen en arte ASCII 3 es:\n";
                    if(origen.aArteASCII(cadena3, arteASCII, MAX))
                        fsalida << arteASCII;
                    else
                        fsalida << "La conversi�n no ha sido posible" << endl; 

                    fsalida << "\nLa imagen en arte ASCII 4 es:\n";
                    if(origen.aArteASCII(cadena4, arteASCII, MAX))
                        fsalida << arteASCII;
                    else
                        fsalida << "La conversi�n no ha sido posible" << endl;



                    fsalida.close();
            }else
                    cout <<"Error con el fichero de salida " << endl;

    }else{
        cout<<"Número de parámetros incorrecto\n";
        cout <<"testarteASCII <imagen> <grises> <salida>\n";
    }
    
       
	
}
