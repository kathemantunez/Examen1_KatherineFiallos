#include "examen1.h"
#include <iostream>


using namespace std;
using std::cout;
using std::cin;
using std::endl;



bool juego(char signo,int fila, int columna){
	//jugador 1
	


}
//validar origen
bool examen1::validar_origen(char signo,int fila,int columna){
 	if(signo=='o'){

		if(tablero[fila][columna]=='o'){
			return true;
		}else{
			return false;
		}
	}
	if(signo=='x'){
		if(tablero[fila][columna]=='x'){
			return true;
		}else{
			return false;
		}
	}
	
}

//validar movimiento
bool examen1::validar_move(char signo,int fila,int columna){
	bool estado=false;
	if(signo=='o' || signo=='O'){
		
		estado=juego(signo,fila,columna);
		if(estado=true){
			return true;
		}else{
			return false;
		}
	}

	if(signo=='x' || signo=='X'){
		estado=juego(signo,fila,columna);
		if(estado=true){
			return true;
		}else{
			return false;
		}


	}

}

//crear matrix
char** examen1::createMatrix(){
	char char1='x';
	char char2='0';

	char ** retval=new char*[SIZE];
	for(int i=0;i<SIZE;i++){
		retval[i]=new char[SIZE];

	}

	//asignar valores
	//
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if(i!=3 || i!=4){
		
			//jugador 1
				if(i==0|| i==2){
					if(j%2!=0 ){
						retval[i][j]='x';
					}else{
						retval[i][j]=' ';
					}
				}
				if(i==1){
					if(j%2==0){
						retval[i][j]='x';
					}else{
					        retval[i][j]=' ';
					}

				}
			//jugador 2
				if(i==5|| i==7){
					if(j%2==0){
						retval[i][j]='o';
					}else{
						retval[i][j]=' ';
					}
				}
				if(i==6){
					if(j%2!=0){
						retval[i][j]='o';
					}else{
						retval[i][j]=' ';
					}
				}
			}



			if(i==3 || i==4){
				retval[i][j]=' ';
			}
			
		}
	}

	return retval;
}


//imprimr matrix;
void examen1::printMatrix(char** matrix){
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			cout<<"["<<matrix[i][j]<<"]";
		}
		cout<<endl;
	}
}


// metodo contructor
examen1::examen1(){
	createStructures();
}

void examen1::createStructures(){
	//liberar memoria
	freeMatrix();
	tablero=createMatrix();

	cout<<endl;


}


//liberar memoria
void examen1::freeMatrix(){

	if(tablero!=0){

		for(int i=0;i<SIZE;i++){
			delete[]tablero[i];
			tablero[i]=0;
		}
		delete[]tablero;
		tablero=0;
	}
}

//metodo para imprimir siempre
void examen1::printBoard(){

	printMatrix(tablero);
}
//destructor
examen1::~examen1(){
	freeMatrix();
	cout<<"memoria LIberada"<<endl;
}
