#include "examen1.h"
#include <iostream>


using namespace std;
using std::cout;
using std::cin;
using std::endl;

int examen1::ganador_x(){
//probar si ya no hay o en el tablero
	int cont=0;
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if(tablero[i][j]=='o'){
				cont++;
			}
		}
	}
	return cont;

}

int examen1::ganador_o(){
	//probar si ya no hay x en el tablero
	int cont=0;
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if(tablero[i][j]=='x'){
				cont++;
			}
		}
	}
	return cont;
}

bool examen1:: juegos(char signo,int x2, int y2,int x1,int y1){
	//jugador 1
	if(signo=='o'){
		//move izquierda
		if(tablero[x2][y2]==tablero[x1-1][y1-1] ){
			//valdiar espacios ocupados
			if(tablero[x2][y2]==' '){
				tablero[x2][y2]='o';
				tablero[x1][y1]=' ';
				return true;
			}else{
				return false;
			}
			//espacio con x
			if(tablero[x2][y2]=' ' && tablero[x2+1][y2+1]=='x'){
				tablero[x2][y2]='o';
				tablero[x2+1][y2+1]=' ';
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}

		//move derecha
		if(tablero[x2][y2]==tablero[x1-1][y1+1]){
			//espacios ocupaods
			if(tablero[x2][y2]==' '){
				tablero[x2][y2]='o';
				tablero[x1][y1]=' ';
				return true;
			}else{
				return false;
			}
			//espacio con x
			if(tablero[x2][y2]==' ' && tablero[x2+1][y2-1]=='x'){
				tablero[x2][y2]='o';
				tablero[x2+1][y2-1]=' ';
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}



	


	//juador_2
	if(signo=='x'){

		//move izquierda
		if(tablero[x2][y2]==tablero[x1+1][y1-1]){
			//espacio vacio
			if(tablero[x2][y2]==' '){
				tablero[x2][y2]='x';
				tablero[x1][y1]=' ';
				return true;
			}else{
				return false;
			}
			//Espacio con o
			if(tablero[x2][y2]==' ' && tablero[x2-1][y2+1]=='o'){
				tablero[x2][y2]=='x';
				tablero[x2-1][y2+1]==' ';
				return true;
			}else{
				return false;

			}


		}else{
			return false;
		}


		//move derecha
		//
		if(tablero[x2][y2]==tablero[x1+1][y1+1]){
			//Espacios vacio
			if(tablero[x2][y2]==' '){
				tablero[x2][y2]='x';
				tablero[x1][y1]=' ';
				return true;
			}else{
				return false;
			}


			//espacio con o
			//
			if(tablero[x2][y2]==' ' && tablero[x2-1][y2-1]=='o'){
				tablero[x2][y2]='x';
				tablero[x2-1][y2-1]=' ';
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}


	

		


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
/*
//validar movimiento
bool examen1::validar_move(char signo,int x2,int y2,int x1,int y1){
	bool estado=false;
	if(signo=='o' || signo=='O'){
		
		estado=juego(signo,x2,y2,x1,y1);
		if(estado==true){
			return true;
		}else{
			return false;
		}
	}

	if(signo=='x' || signo=='X'){
		estado=juego(signo,x2,y2,x1,y1);
		if(estado==true){
			return true;
		}else{
			return false;
		}


	}

}
*/
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
