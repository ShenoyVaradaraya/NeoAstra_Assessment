/*
 * Elem.h
 *
 *  Created on: 08-Feb-2021
 *      Author: varad
 */
#ifndef ELEM_H_
#define ELEM_H_ 1
#include <iostream>
#define MAX_VALUE 65536
template<class T,class KEY>
struct Elem{
	KEY key;
	T data;
	Elem *left;
	Elem *right;
	bool rightThread,leftThread;
	int size;
};
Elem<int,int> *root;
template<class T,class KEY>
class RTBT{
public:
	bool insert(Elem<int,int> *& root, const KEY &key, const T &data, Elem<int,int> *lastLeft){
		lastLeft = root;
		for(;;){
			if(lastLeft->key < key ){
				if(lastLeft->rightThread)
					break;
				lastLeft = lastLeft->right;
			}
			else if(lastLeft->key >key){ // move to left thread
				if(lastLeft->leftThread)
					break;
				lastLeft = lastLeft->left;
			}
			else
				return false;
			}
		Elem<int,int> *temp = new Elem<int,int>();
		temp ->key = key;
		temp ->rightThread = temp->leftThread = true;
		if(lastLeft->key <key){
			temp->right = lastLeft->right;
			temp->left= lastLeft;
			lastLeft->right = temp;
			lastLeft->rightThread= false;
		}
		else {
				temp->right = lastLeft;
				temp->left = lastLeft->left;
				lastLeft->left = temp;
				lastLeft->leftThread = false;
		   	   }
		}
	void printTree(std::ostream& out, int level, Elem<int,int> *p){
		   for (;;) {
		      p = p->right;
		      if (!p->rightThread) {
		         while (!p->leftThread) {
		            p= p->left;
		         }
		      }
		      if (p== root)
		         break;
		      out<<p->key<<" ";
		   }
		   out<<std::endl;
	}
	void destructCode(Elem<int,int> *& p){
		p= new Elem<int,int>();
		p->right = p->left = p;
		p->rightThread = true;
		p->key = MAX_VALUE;
	}
};
#endif /* ELEM_H_ */
