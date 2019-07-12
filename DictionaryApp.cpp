#include "Dictionary.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <locale>

using namespace std;

int main(int argc,char *argv[]){
	Dictionary a;
	if(argc!=1){
		ifstream read;
		string s;
		locale loc;
		read.open(argv[1]);
		if(!read.is_open()){
			cout << "Unable to open file\n";
			return 1;
		}
		read >> s;
		while(!read.eof()){
			stringstream ss;
			while(s.find("'")!=string::npos)
				s.replace(s.find("'"),1,"");
			for(string::size_type i=0; i<s.length(); ++i){
				ss << tolower(s[i],loc);
			}
			s = ss.str();
			a.addWord(s); 
			read >> s;
		}
		read.close();
	}else{
		cout <<"Please enter a file name\n";
		return 2;
	}
	
	char option;
	string choice;
	cout << "Select Option:\n(R) Find Word\n(W) Word of the Day\n(Q) quit\n\n";
	cin >> choice;
	while(choice.compare("Q") != 0){
		
		if(choice.compare("R") == 0){
			if(a.getNumberOfWords() == 0)
				cout << "\nNo words in the dictionary to choose from\n\n";
			else{
				int rank;
				cout << "\nInput the rank of your word\n\n";
				cin >> rank;
				if(rank<=0 || a.getNumberOfWords()<rank)
					cout << "\nInvalid rank\n\n";
				else
					cout << endl << "Your word is: " << a.getWordOfDay(rank) << endl << endl;
			}
		}
		else if(choice.compare("W") == 0){
			if(a.getNumberOfWords() == 0)
				cout << "\nNo words in the dictionary to choose from\n\n";
			else{
				srand((unsigned)time(NULL));//rng
				cout << "\nWord of the Day: " << a.getWordOfDay(rand()%a.getNumberOfWords()+1) << endl <<endl;
			}			
		}
		else
			cout << "\nInvalid choice\n\n";
			
		cout << "Select Option:\n(R) Find Word\n(W) Word of the Day\n(Q) Quit\n\n";
		cin >> choice;
		
	}
	
	
	return 0;
}
