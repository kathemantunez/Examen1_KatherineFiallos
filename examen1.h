#ifndef EXAMEN1_H
#define EXAMEN1_H


#define CONT_1 12
#define CONT_2 12
#define SIZE 8
#define player1 'x'
#define player2 'o'

class examen1{
	
	private : char** tablero;
		  char** createMatrix();
		  void printMatrix(char**);
		 // bool juego(char,int,int,int,int);

		  
		  
	public:
		  examen1();//ctor por defecto
		  void createStructures();
		  void printBoard();
		  void freeMatrix();//liberar memoria
		  bool juegos(char,int,int,int,int);
		  bool validar_origen(char,int,int);
		  bool validar_move(char,int,int,int,int);
		  int ganador_o();
		  int ganador_x();
		
		  ~examen1();//DEstructorº

};
#endif
