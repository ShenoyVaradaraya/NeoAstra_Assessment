/*
 * AVLTree.h
 *
 *  Created on: 09-Feb-2021
 *      Author: varad
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_
#include<stack>
#include<iostream>
template <class T,class KEY>
class AVLTree{
struct Elem {
	KEY key;
	T data;
	Elem *left;
	Elem *right;
	int hight;
	bool rightThread;//normal right child link or a threadlink // a dummy root sentinel
public:
	Elem(){
		left(0), right(0), height(-1), rightThread(false);
	}
	bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft){
		if(lastLeft == NULL)
		        {
		            lastLeft = new Elem;
		            lastLeft->data = &data;
		            lastLeft->hight = 0;
		            lastLeft->left = lastLeft->right = NULL;
		        }
		else if(&data < lastLeft->data)
		        {
		            lastLeft->left = insert(&data, lastLeft->left);
		if(height(lastLeft->left) - height(lastLeft->right) == 2)
		            {
		if(&data < lastLeft->left->data)
			lastLeft = singleRightRotate(lastLeft);
		else
			lastLeft = doubleRightRotate(lastLeft);
		            }
		        }
		else if(&data > lastLeft->data)
		        {
			lastLeft->right = insert(&data, lastLeft->right);
		if(height(lastLeft->right) - height(lastLeft->left) == 2)
		            {
		if(&data > lastLeft->right->data)
			lastLeft = singleLeftRotate(lastLeft);
		else
			lastLeft = doubleLeftRotate(lastLeft);
		            }
		        }
		lastLeft->hight = max(height(lastLeft->left), height(lastLeft->right))+1;
		return lastLeft;
		}
	void printTree(std::ostream& out, int level, Elem *p){
		  int i;
		  if (p != NULL) {
		      show(p->right, level+ 1);
		      out<<" ";
		      if (p == right)
		         out << "Root -> ";
		      for (i = 0; i < level&& p != right; i++)
		         out << " ";
		         out << p->d;
		         show(p->left, level + 1);
		   }
		}
	void destructCode(Elem *& p){
		if(p == NULL)
		return;
		makeEmpty(p->left);
		makeEmpty(p->right);
		delete p;
	}
	void rotateRight(Elem *& node){
			Elem* u = node->left;
			node->left = u->right;
			u->right = node;
			node->hight = max(height(node->left), height(node->right))+1;
			u->hight = max(height(u->left), node->height)+1;
			return u;
		}

	void rotateLeft(Elem *& node){
			Elem* u = node->right;
			node->right = u->left;
			u->left = node;
			node->hight = max(height(node->left), height(node->right))+1;
			u->hight = max(height(node->right), node->height)+1 ;
			return u;
		}

	void doubleRotateLeft(Elem *& node){
			node->right = singleRightRotate(node->right);
			return singleLeftRotate(node);
		}
	void doubleRotateRight(Elem *& node){
			node->left = singleLeftRotate(node->left);
			return singleRightRotate(node);
		}
	int balanceFactor(Elem *cur){
				int l_height = height(cur->left);
				int r_height = height(cur->right);
				int b_factor = l_height - r_height;
				return b_factor;
			}

	void balance(Elem*& cur, const KEY &key){
				int bal_factor = balanceFactor(cur);
				   if (bal_factor > 1) {
				      if (balanceFactor(cur->left) > 0)
				         cur = doubleRotateLeft(cur);
				      else
				         cur = rotateLeft(cur);
				   } else if (bal_factor < -1) {
				      if (balanceFactor(cur->right) > 0)
				         cur = rotateRight(cur);
				      else
				         cur = doubleRotateRight(cur);
				   }
		}
	int height(Elem *node){
			return (node == NULL ? -1 : node->hight);
			}
	void updateHeight(Elem*& cur){
			if(cur == NULL)
			return;
			updateHeight(cur->left);
			std::cout << cur->data << std::endl;
			updateHeight(cur->right);
		}
}*root;
};

// helper method for print tree

// common code for deallocation

#endif /* AVLTREE_H_ */
