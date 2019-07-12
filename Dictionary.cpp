#include "Dictionary.h"
#include <string>
#include <iostream>
#include <queue>

Dictionary::Dictionary(){
	root = NULL;
}

Dictionary::~Dictionary(){
	makeEmpty(root);
}
void Dictionary::makeEmpty(node *& k){
	if(k!=NULL){
		makeEmpty(k->left);
		makeEmpty(k->right);
		delete k;
	}
	k = NULL;
}

int Dictionary::height(node *k) const{
	int l, r;
	l=r=0;
	if(k==NULL)
		return -1;
	if(k->left != NULL)
		l = k->left->height;
	if(k->right != NULL)
		r = k->right->height;
	return 1+max(l,r);
}
void Dictionary::addWord(std::string &word){
	this->insert(word, root);
}
int Dictionary::getNumberOfWords(){
	if(root == NULL)
		return 0;
	return root->size;
}

const std::string Dictionary::getWordOfDay(int x){
	if(x<0 || root->size<x){
		std::string msg = "Invalid rank";
		return msg;
	}
	return getWordOfDay(x, root);
}
std::string Dictionary::getWordOfDay(int x, node *k){
	
	int m=updateSize(k->left)+1;
	if(m==x)
		return k->data;
	if(m>x)
		return getWordOfDay(x, k->left);
	return getWordOfDay(x-m, k->right);

}
int Dictionary::updateSize(node *k){
	if(k==NULL)
		return 0;
	int l, r;
	l = r = 0;
	if(k->left != NULL)
		l = k->left->size;
	if(k->right != NULL)
		r = k->right->size;
	return 1+l+r;
}
void Dictionary::insert(std::string &data, node *& k){
	if(k == NULL){
		k=new node;
		k->data=data;
		k->left = k->right = NULL;
		k->height = 0;
		k->size = 1;
	}
	else if(data.compare(k->data)<0){
		insert(data, k->left);
	}else if(k->data.compare(data)<0){
		insert(data, k->right);
	}
	this->balance(k);
	k->size = updateSize(k);		
}

void Dictionary::balance(node *& k){
	if(k==NULL)
		return;
	if(height(k->left)-height(k->right) > 1){
		if(height(k->left->left) >= height(k->left->right))
			RLC(k);
		else{
			RRC(k->left);
			RLC(k);
		}
	}
	else{
		if(height(k->right)-height(k->left)>1){
			if(height(k->right->right)>=height(k->right->left))
				RRC(k);
			else{
				RLC(k->right);
				RRC(k);
			}
		}
	}
	k->height = max(height(k->left), height(k->right))+1;
}
void Dictionary::RLC(node *& k2){
	node *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right))+1;
	k1->height = max(height(k1->left), k2->height)+1;
	k1->size = updateSize(k1);
	k2->size = updateSize(k2);
	k2=k1;
}

void Dictionary::RRC(node *& k2){
	node *k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->left), height(k2->right))+1;
	k1->height = max(height(k1->left), k2->height)+1;
	k1->size = updateSize(k1);
	k2->size = updateSize(k2);
	k2=k1;
}
void Dictionary::traverse(node *root){
    std::queue<node*> q;
    if(root==NULL) {
        return;
    }
    for (q.push(root); !q.empty(); q.pop()) {
        const node * const temp_node = q.front();
        std::cout<<temp_node->data<<"\n";

        if (temp_node->left) {
            q.push(temp_node->left);
        }
        if (temp_node->right) {
            q.push(temp_node->right);
        }
    }
}

void Dictionary::traverse(){
	traverse(root);
}
int Dictionary::max(int a, int b) const{
	if(a>b)
		return a;
	return b;
}
