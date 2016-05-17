// Clare Mason
// PA 1: Recommendations
//10/7/15

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

#include "Rating.h"
#include "Member.h"
#include "Book.h"

int readBookfile(string file, Book& object);
int readRatingfile(string file, int number, Member& object);
void recommendBooks(int id, Book Bobject, Member object, int numofmem, int numofbook);




int main()
{

  Book bookshelf;
  Member listofmembers;
  string file1;
  string file2;
  int numberofbooks;
  int numberofmembers;
  bool program = false;
  int choice1 = 0;
  int choice2=0;
  bool files=false;

  ///////////// Reading in Files//////////////
  while(files == false)
	{
	  cout << "Please enter books.txt"<< endl;
	  cin >> file1; 
	  cout <<"Please enter ratings.txt"<< endl;
	  cin >> file2;
	  
	  numberofbooks = readBookfile(file1, bookshelf);
	  numberofmembers=readRatingfile(file2, numberofbooks, listofmembers);
	  
	  if(numberofbooks == 0 or numberofmembers == 0)
		{cout << "Unable to read files. Please enter usuable files."<< endl;
		}
	  else
		{
		files =true;
		}
	}

  ///////////////Running Program/////////////
  program = true;
  bool login= false;
  
  while(program == true){
	cout << endl<<"Welcome to the Book Recommender!"<<endl; //Welcome screen
	cout << "Select an opion below:"<<endl;
	cout <<"1) Login:"<<endl<<"2) Add new member:"<<endl<<"3) Add new book:"<< endl << "4) Quit"<<endl;
	cin >> choice1;
	
	while (choice1>4){
	  cout << "Please select a choice from above. Idoit." <<endl;
	  cin >> choice1;}

	
	while(choice1 == 1){//login
	  string name;
	  int ID;
	  Rating rateobject;
	  if(login==false){
	  
	  cout<< "Please enter user ID"<< endl;
	  cin >>ID;

	  while (ID> numberofmembers){
		cout<<"That user doesn't exsist! Please enter a valid user ID."<<endl;
		cin >>ID;
	  }
	  login =true;
		}
	  name= listofmembers.getName(ID);
	  rateobject=listofmembers.getMemberRating(ID);
	  
	  cout << endl<<"Welcome " <<name<< "!"<< endl;
	  cout<< "Select an opion below." << endl;
	  cout<< "1) Rate book"<<endl<<"2) View your ratings"<<endl<<"3) Recommend Books"<<endl<<"4) Logout"<<endl;
	  cin>>choice2;

	  
	  while(choice2 >4){
		cout << "Please select a choice from above like how hard is it come on?"<<endl;
		cin >> choice2;}
	  /////////logged in functions
	  while(choice2 == 1){//rate book
		string YorN= "y";
		int bookchoice=0;
		int bookrate=0;
		while(YorN == "y")
		  {
			cout << "Here are the books avalible to rate:" <<endl;
			for(int i=0; i < numberofbooks; i++){
			  cout<< bookshelf.getISBN(i)<<") "<< bookshelf.getTitle(i)<<endl;
			}
		cout<< "Enter the number of the book to rate: "<< endl;
		cin >> bookchoice;
		cout << "What would you give this book? (-5, -3, 0, 1, 3, 5)"<<endl;
		cin >>bookrate;
		listofmembers.getMemberRating(ID).setrating(bookchoice, bookrate);
		cout<< "Would you like to rate another book?(y/n)"<<endl;
		cin>>YorN;
		  }
		if (YorN != "n"){
		  cout << "Please enter y or n. " << endl;
		  cin >> YorN;
		}
		else{
		  choice2=0;
		}
		  
	  }
	  
	  while(choice2 == 2){// view your ratings
		string whatev;
		cout << "Here are you ratings:" << endl;
		for (int i=0; i<numberofbooks; i++){
		  cout << bookshelf.getTitle(i)<<": "<<rateobject.getrating(i)<< endl;
		}
		cout<< "Enter any key to go back" <<endl;
		cin>>whatev;
		choice2=0;
	  }
	  

	  while(choice2 == 3){//recommend books
		cout<< "Here are some recommendations:"<<endl;
		recommendBooks(ID,bookshelf, listofmembers, numberofmembers,numberofbooks);
		cout<< endl<<"Enter any key to go back."<< endl;
		string whatev;
		cin>>whatev;
		choice2=0;
	  }

	  
	  while(choice2 == 4){//logout
		login = false;
		choice1=0;
		choice2=0;
	  }
	}

	///// logged out functions
	while(choice1 == 2){//add new member
	  string name;
	  string whatev;
	  cin.ignore();
	  cout<< "Please enter your name: "<<endl;
	  getline(cin,name);
	  numberofmembers++;
	  listofmembers.newMember(name, numberofmembers);
	  
	  cout <<"Your user ID is " << numberofmembers<< ". Use it to log in"<< endl;
	  cout<< "Press any key to retun:"<<endl;
	  cin >> whatev;
	  choice1=1;
	}
	while(choice1 == 3){//add new book
	  string booktitle="";
	  string bookauthor="";
	  int bookdate;
	  cin.ignore();
	  cout<<"Please enter the title of the new book:"<<endl;
	  getline(cin, booktitle);
	  cout<<"Please enter the author of the new book:"<<endl;
	  getline(cin, bookauthor);
	  cout<<"Please enter the year the book was publish:" <<endl;
	  cin >> bookdate;
	  numberofbooks++;
	  bookshelf.addBook(numberofbooks, bookdate, bookauthor, booktitle);
	  
	  cout<< "Your book has been added to the library!"<<endl;
	  string whatev;
	  cout<< "Enter any key to return to the main screen"<<endl;
	  cin>>whatev;
	  choice1=0;
	}
   
	while(choice1 == 4){//quit
	  return 0;
	}

  }

  
  
  return 0;
}


//////////Functions

 int readBookfile(string file, Book& object){
  ifstream infile;
  string author;
  string title;
  int count = 0;
  bool opened =false;
  infile.open(file.c_str(), ios::in);
  if(infile){
	opened=true;
	while(getline(infile,author,',')){
	  getline(infile, title,'\n');
	  object.addBook(count, 1998, author, title);
	  count ++;
	}
  }
  
  infile.close();

  if(opened==true){
	return count;
  }
  else{
	return 0;}
 }


int readRatingfile(string file, int number, Member& object){
  fstream infile;
  string name;
  string num;
  int rate;
  int membercount=0;
  int ratingcount=0;
  Rating temp;
  bool opened= false;
  
  infile.open(file.c_str());
  if(infile){
	opened=true;
	while(getline(infile,name,'\n')){
	  object.newMember(name, membercount);
	  ratingcount=0;
	  getline(infile,num,'\n');
	  stringstream stream(num);
	  temp = object.getMemberRating(membercount);
	  while(stream >>rate)
		{
		  temp.addrating(rate, ratingcount);
		  object.setMemberRating(temp, membercount);
		  ratingcount++;
		}
	  
	  membercount++;
	}
  }
  infile.close();
  if(opened ==true){
	return membercount;
  }
  else{
	return 0;
  }
}


void recommendBooks(int id, Book Bobject, Member object, int numofmem, int numofbook){
  Rating ratinglist = object.getMemberRating(id);
  int product=0;
  int sum=0;
  int max=0;
  int match;
  int count=0;
  for(int i=0; i<numofmem; i++){
	if( i != id){
	sum=0;
	for(int j=0; j<numofbook; j++){ 
	  product=ratinglist.getrating(j)* object.getMemberRating(i).getrating(j);
	  sum=product + sum;
	}
	if(sum > max){
	  max=sum;
	  match=i;
	}
	}
  }

  for(int i=0; i<numofmem; i++){
	if (count<3){
	if(ratinglist.getrating(i) == 0)
	  if (object.getMemberRating(match).getrating(i)>= 3){
		cout<< Bobject.getTitle(i)<<endl;
		count= count+1;
	  }
	}
  }
  return;
}
