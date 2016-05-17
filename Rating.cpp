//Clare Mason
//10/2/15
//PA 1 interface

#include <iostream>
#include "Rating.h"
using namespace std;

Rating::Rating(){
  numberofratings=0;
  sizeofarray=60;
  array = new int[sizeofarray];

  for(int i=0; i<sizeofarray; i++){
	array[i]=0;
  }
}

Rating::Rating(const Rating& rhs){
  numberofratings=rhs.numberofratings;
  sizeofarray=rhs.sizeofarray;

  array=new int[rhs.sizeofarray];
  for(int i =0; i< rhs.sizeofarray; i++){
	array[i]=rhs.array[i];
  }
}

Rating& Rating::operator=(const Rating& rhs){
  if(this != &rhs){
	numberofratings=rhs.numberofratings;
	sizeofarray=rhs.sizeofarray;

	array=new int[rhs.sizeofarray];
	for (int i=0; i<rhs.sizeofarray; i++){
	  array[i]=rhs.array[i];
	}
	
	
  }
  return *this;
}

Rating::~Rating(){
  delete [] array;
}


int Rating::getrating(int isbn){
  return array[isbn];
}

void Rating::setrating(int isbn, int rate){
  array[isbn]= rate;
}
void Rating::addrating(int rate, int isbn){
  if(numberofratings == sizeofarray){
	int *temp;
	temp= new int[sizeofarray*2];
	for(int i=0; i<sizeofarray; i++){
	  temp[i]=array[i];
	}
	delete [] array;
	array=temp;
	array[isbn]=rate;
	sizeofarray= sizeofarray*2;
  }
  
  else{
	array[isbn]=rate;
	sizeofarray++;
  }
}
