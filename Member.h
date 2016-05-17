 // Clare Mason
// PA 1 interface
// 10/2/15

#include <string>
#include "Rating.h"
#ifndef MEMBER_H
#define MEMBER_H

using namespace std;
class Member{
 private:
  struct memberstruct{
	string memberName;
	int ID;
	Rating rateobject;
  };

  int membersize;
  int numberOfmembers;
  memberstruct memberinfo;
  memberstruct *memberlist;
  
  
 public:
  Member(); //constuctor
  Member(const Member& rhs);
  Member& operator=(const Member& rhs);
  ~Member();// destructor

  void newMember( string name, int ID);
  string getName(int num);
  Rating getMemberRating(int id);
  void setMemberRating(Rating object, int id);
  int getID(int num);
  void setID(int num);
  void setName(string nam);
};

#endif
