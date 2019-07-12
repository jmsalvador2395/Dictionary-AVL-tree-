#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <string>
#include <iostream>
struct node{
	std::string data;
	node *left, *right;
	int height, size;
};

class Dictionary{
	public:
		Dictionary();
		~Dictionary();
		void addWord(std::string &word);
		int getNumberOfWords();
		const std::string getWordOfDay(int x);
		void traverse();
	private:
		std::string getWordOfDay(int x, node *k);
		void insert(std::string &str, node *& t);
		void balance(node *& k);
		int height(node *root) const;
		int max(int a, int b) const;
		void RLC(node *& k2);
		void RRC(node *& k2);
		void traverse(node *root);
		void makeEmpty(node *& k);
		int updateSize(node *k);
		node *root;
};

#endif
