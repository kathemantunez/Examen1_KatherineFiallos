#include <iostream>
#include "examen1.h"
#include <string>
#include <cstring>


using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main(){
	string jugador1;
	string jugador2;
	int turno=0;
	int x1,x2,y2,y1;
	bool estado=false;//estado de juego... para saber si gano alguien o no
	bool estado_origen=false;
	bool estado_move=false;
	char p1='o';
	char p2='x';
	examen1* juego=new examen1();
	cout<<"Tablero inicial"<<endl;
	juego->printBoard();


	cout<<"BIENVENIDO A ORACLE CORPORATION\nCraftStar:XCOM"<<endl;
	cout<<"Ingrese el nombre del Jugador 1 (o)"<<endl;
	cin>>jugador1;
	cout<<"Ingrese el nombre del Jugador 2 (x)"<<endl;
	cin>>jugador2;
	


	//juego
	while(estado==false){//cambiar estado==false
		
		if(turno%2==0){//turno jugador1

			cout<<"Turno de "<<jugador1<<" (o)"<<endl;

			while(estado_origen==false){
			cout<<"ingrese las cordenadas de la pieza que desea mover"<<endl;
			cout<<"x1:"<<endl;
			cin>>x1;
			while(x1<0 || x1>7){
				cout<<"error\nx1:"<<endl;
				cin>>x1;
			}
			cout<<"y1:"<<endl;
			cin>>y1;
			while(y1<0||y1>7){
				cout<<"erros\ny2:"<<endl;
				cin>>y1;
			}

			estado_origen=juego->validar_origen(p1,x1,y1);
			}//fin while

			
			while(estado_move==false){
			cout<<"ingrese las cordenadas a donde desea mover la pieza"<<endl;
			cout<<"x2:"<<endl;
			cin>>x2;
			while(x2<0||x2>7){
				cout<<"error\nx2:"<<endl;
				cin>>x2;
			}

			cout<<"y2:"<<endl;
			cin>>y2;
			while(y2<0|| y2>7){
				cout<<"error\ny2:"<<endl;
				cin>>y2;
			}
			estado_move=juego->validar_move(p1,x2,y2);
			}//fin while


			turno++;

		}else{
			//turno jugador2
			cout<<"Turno de "<<jugador2<<" (x)"<<endl;
			while(estado_origen==false){
			cout<<"ingrese las cordenads de la pieza que desea mover"<<endl;
			cout<<"x1:"<<endl;
			cin>>x1;
			while(x1<0||x1>7){
				cout<<"error\nx1:"<<endl;
				cin>>x1;
			}
			cout<<"y1:"<<endl;
			cin>>y1;
			while(y1<0||y1>7){
				cout<<"erroe\ny1:"<<endl;
				cin>>y1;
			}
			estado_origen=juego->validar_origen(p2,x1,y1);
			}//fin while



			while(estado_move==false){
			cout<<"ingrese las cordenadas a donde desea mover la pieza"<<endl;
			cout<<"x2:"<<endl;
			cin>>x2;
			while(x2<0||x2>7){
				cout<<"error\nx2:"<<endl;
				cin>>x2;
			}
			cout<<"y2:"<<endl;
			cin>>y2;
			while(y2<0||y2>7){
				cout<<"error\ny2:"<<endl;
				cin>>y2;
			}
			estado_move=juego->validar_move(p2,x2,y2);
			}//fin while

			turno++;

		}
		


	}









	delete juego;
	return 0;
}

