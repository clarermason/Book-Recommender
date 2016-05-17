//Clare Mason
//10/2/15
// PA 1 interface
// given .txt and a username will return an array of ratings

#include <string>
using namespace std;
#ifndef RATING_H
#define RATING_H

class Rating{
private:
  int numberofratings;
  int sizeofarray;
  int *array;
  
 public:
  Rating();
  Rating(const Rating& rhs);
  Rating& operator=(const Rating& rhs);
  ~Rating();
  int getrating(int isbn);
  void setrating(int isbn, int rate);
  void addrating(int rate, int isbn);
};

#endif
