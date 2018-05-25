#ifndef EXAMEN1_H
#define EXAMEN1_H


#define CONT_1 0
#define CONT_2 0
#define SIZE 8
#define player1 'x'
#define player2 'o'

class examen1{
	
	private : char** tablero;
		  char** createMatrix();
		  void printMatrix(char**);

		  
		  
	public:
		  examen1();//ctor por defecto
		  void createStructures();
		  void printBoard();
		  void freeMatrix();//liberar memoria
		  bool juego(char,int,int);
		  bool validar_origen(char,int,int);
		  bool validar_move(char,int,int);
		  bool ganador1();
		 bool ganador2();
		  ~examen1();//DEstructorº

};
#endif
