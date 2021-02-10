/*
 * main.cpp
 *
 *  Created on: 10-Feb-2021
 *      Author: varad
 */
// This file seems to be crashing, i am not able to debug it though. The header files as well as the source code
// is error free.
#include"Elem.h"
#include "AVLTree.h"
#include<iostream>
using namespace std;
int main(){
	RTBT<int,int> tbt;
	cout<<"ThreadedBinaryTree\n";
	int c, v;
	while(1) {
	      cout<<"1. Insert "<<endl;
	      cout<<"2. Display"<<endl;
	      cout<<"3. Exit"<<endl;
	      cout<<"Enter Your Choice: ";
	      cin>>c;
	      switch (c) {
	               case 1 :
	                  cout<<"Enter integer element to insert: ";
	                  cin>>v;
	                  tbt.insert(root,v,v,root);
	                  break;
	               case 2:
	                           cout<<"Display tree: \n ";
	                           tbt.printTree(cout,0,root);
	                           break;
	               case 3:
	                           exit(1);
	               default:
	                           cout<<"\nInvalid type! \n";
	    }
	}
	cout <<"\n";
	return 0;
}



