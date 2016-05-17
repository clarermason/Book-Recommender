//Clare Mason
//10/7/15
// PA 1: Recommendations

#include <iostream>
#include "Book.h"
using namespace std;

Book :: Book(){
  bookinfo.author="";
  bookinfo.title="";
  bookinfo.ISBN = 0;
  bookinfo.date=0;
  size = 60;
  numberOfbooks= -1;
  booklist= new bookstruct[size];
}

Book::Book(const Book& rhs)
{
  bookinfo.author= rhs.bookinfo.author;
  bookinfo.title = rhs.bookinfo.title;
  bookinfo.ISBN= rhs.bookinfo.ISBN;
  bookinfo.date=rhs.bookinfo.date;
  size = rhs.size;
  booklist= new bookstruct[rhs.size];
  for(int i=0; i<rhs.size; i++){
	booklist[i]= rhs.booklist[i];
  }
}

Book& Book::operator=(const Book& rhs)
{
  if( this != &rhs){
	bookinfo.author = rhs.bookinfo.author;
	bookinfo.title = rhs.bookinfo.title;
	bookinfo.ISBN = rhs.bookinfo.ISBN;
	bookinfo.date= rhs.bookinfo.date;
	size=rhs.size;
	booklist = new bookstruct[rhs.size];
	for (int i=0; i<rhs.size; i++){
	  booklist[i]= rhs.booklist[i];
	}
  }
  return *this;
}

Book::~Book(){
  delete[] booklist;
}

int Book::getISBN(int num){
  return booklist[num].ISBN;
}

string Book::getTitle(int num){
  return booklist[num].title;
}


string Book::getAuthor(int num){
  return booklist[num].author;
}

int Book::getDate(int num){
  return booklist[num].date;
}

void Book::setISBN(int num){
  bookinfo.ISBN = num;
  
}

void Book::setTitle(string tit){
  bookinfo.title = tit;
}

void Book::setAuthor(string auth){
  bookinfo.author = auth;
}

void Book::setDate(int dat){
  bookinfo.date = dat;
}


void Book::addBook(int isbn, int dat, string auth, string tit){
  bookinfo.author=auth;
  bookinfo.title=tit;
  bookinfo.date=dat;
  bookinfo.ISBN=isbn;
  if(numberOfbooks == size){ //resize
	  bookstruct *temp;
	  temp= new bookstruct[size*2];
	  for(int i=0; i<size+1; i++){
	   temp[i]=booklist[i];
	  }
	  delete [] booklist;
	  booklist = temp;
	  numberOfbooks++;
	  size= size*2;
  }
  
  else{
	booklist[numberOfbooks+1]=bookinfo;
	numberOfbooks++;
  }
  
  

}
