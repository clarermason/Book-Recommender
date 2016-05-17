//Clare Mason
// 10/2/15
// PA 1 interface
#include <string>
#include "Member.h"
#include <iostream>
using namespace std;


Member::Member(){
  membersize = 5;
  numberOfmembers= 0;
  
  memberlist= new memberstruct[membersize];
  
  for (int i=0; i<membersize; i++){
	memberlist[i].ID=0;
	memberlist[i].memberName="";
  }
	
}

Member::Member(const Member &rhs)
{
  membersize=rhs.membersize;
  numberOfmembers=rhs.numberOfmembers;
  
  memberlist = new memberstruct[membersize];
  
  for(int i=0; i<membersize; i++){
	memberlist[i].memberName = rhs.memberlist[i].memberName;
	memberlist[i].ID=rhs.memberlist[i].ID;
	memberlist[i].rateobject=rhs.memberlist[i].rateobject;
	
  }

}

Member& Member::operator=(const Member& rhs)
{
  if(this != &rhs){
	
	numberOfmembers=rhs.numberOfmembers;
	membersize=rhs.membersize;

	memberlist= new memberstruct[membersize];
	
	for(int i=0; i<membersize; i++){
	  memberlist[i].memberName = rhs.memberlist[i].memberName;
	  memberlist[i].ID=rhs.memberlist[i].ID;
	  memberlist[i].rateobject=rhs.memberlist[i].rateobject;
	
	}
  }
	return *this;
}

Member::~Member(){
  delete[] memberlist;
}
  
  
string Member::getName(int num)
{
  return memberlist[num].memberName;
}
 
 int Member::getID(int num)
 {
  return memberlist[num].ID;
 }
 
void Member::setName(string nam)
{
  memberinfo.memberName = nam;
}

void Member::setID(int num){
  memberinfo.ID = num;
}

void Member::setMemberRating(Rating object, int id){
  memberlist[id].rateobject = object;
}

Rating Member::getMemberRating(int id){
  
  return memberlist[id].rateobject;
  
  
}

void Member::newMember( string name, int id){

  
  if(numberOfmembers==membersize){
	memberstruct *temp;
	temp = new memberstruct[membersize*2];
	for(int i=0; i<membersize; i++){ //resize
	  temp[i].memberName=memberlist[i].memberName;
	  temp[i].ID=memberlist[i].ID;
	  temp[i].rateobject=memberlist[i].rateobject;
	}
	delete [] memberlist;
	memberlist=temp;
	numberOfmembers++;
	membersize= membersize*2;
  }
  else{
	memberlist[id].memberName=name;
	memberlist[id].ID=id;

	
	numberOfmembers++;
  }
}


