

// Clare Mason
//10/2/15
//PA 1 Interface

#include <string>
using std::string;
#ifndef BOOK_H
#define BOOK_H

class Book{
 private:
  struct bookstruct {
	string author;
	string title;
	int ISBN;
	int date;
  };
  bookstruct *booklist;
  int size;
  bookstruct bookinfo;
  int numberOfbooks;
 public:
  Book();
  Book( const Book& rhs);
  Book& operator=(const Book& rhs);
  ~Book();

  void addBook(int isbn, int dat, string auth, string tit);
  
  int getISBN(int num);
  string getTitle(int num);
  string getAuthor(int num);
  int getDate(int num);
  void setISBN(int num);
  void setTitle(string tit);
  void setAuthor(string auth);
  void setDate(int dat);

};
#endif
