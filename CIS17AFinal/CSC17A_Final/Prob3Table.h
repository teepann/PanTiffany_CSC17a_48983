/* 
 * File:   Prob3Tables.h
 * Author: Tiffany
 *
 * Created on December 17, 2015, 1:05 AM
 */

#ifndef PROB3TABLE_H
#define	PROB3TABLE_H
#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class Prob3Table{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(char *,int,int);               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		T *getTable()const{return table;};
		T *getRowSum()const{return rowSum;};
		T *getColSum()const{return colSum;};
		T getGrandTotal(){return grandTotal;};
};
template <class T>
Prob3Table<T>::Prob3Table(char* text, int rows, int cols){
  grandTotal=0;
  this->rows=rows;
  this->cols=cols;
  table = new T[rows*cols];
  rowSum = new T[rows];
  colSum = new T[cols];
  //input data
  fstream io;
  int i=0;
  io.open(text, ios::in);
  while(io>>table[i]){i++;}
  io.close();
  int temp=0;
  //cal row sum
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      temp+=table[i*cols+j];
    }
    rowSum[i]=temp;
    temp=0;
  }
  for(int j=0;j<cols;j++){
    for(int i=0;i<rows;i++){
      temp+=table[i*cols+j];
    }
    colSum[j]=temp;
    temp=0;
  }
  calcTable();
}
template <class T>
void Prob3Table<T>::calcTable(){
  for(int i=0;i<rows;i++){
    grandTotal+=rowSum[i];
  }
}

#endif	/* PROB3TABLE_H */