#include <iostream>
#include "byte.h"

using namespace std;

void onBit(Byte &b, int pos){
	Byte mask = 1;
	mask = mask << pos;
	b = b|mask;
}

void offBit(Byte &b, int pos){
	Byte mask = 1;
	mask = mask << pos;
	mask = ~mask;
	b = b&mask;
}

bool getBit(Byte b, int pos){	
	Byte mask = 1;
	mask = mask << pos;
	b = b&mask;
	return b > 0;	
}

void imprimirByte(Byte b){
	for(int i=7; i>=0; i--){
		cout << getBit(b,i);
	}
}

void onByte(Byte &b){
	for(int i=7; i>=0; i--){
		onBit(b,i);
	}
}

void offByte(Byte &b){
	for(int i=7; i>=0; i--){
		offBit(b,i);
	}
}

void asignarByte(Byte &b, const bool v[]){
	int j = 7;	
	for(int i=0; i<=7; i++){
		if(v[i]==true){
			onBit(b,j);
			j--;
		}
		else{
			offBit(b,j);
			j--;
		}	
	}
}

void volcarByte(Byte b, bool v[]){
	for(int i=7; i>=0; i--){
		if(getBit(b,i)==true)
			v[i]=true;
		else
			v[i]=false;
	}
}

void encendidosByte(Byte b, int posic[], int &cuantos){
	int j = 0;
	cuantos = 0;	
	for(int i=0; i<=7; i++){
		if(getBit(b,i)==true){
			posic[j]=i;
			j++;
			cuantos++;
		}
	}
}

		
			
				
				
	

