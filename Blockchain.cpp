#include<iostream>
#include"Blockchain.h"
#include "SHA512.cpp"

using namespace std;

Blockchain * takeInput(){ // It will return The head i.e address of first block in the blockchain.

	string data;
	Blockchain *head = NULL; // First block in Blockchain
	Blockchain *node = NULL; // Intermediate block of blockchain
	cout <<"Please enter data, press 'q' to quit/stop"<<endl;
	cin >> data;

	while ( data.compare("q") ){
		Blockchain *block = new Blockchain(data); // Creating a block
		cout << "New Block Created \n";
		if ( head == NULL){
			head  = block; // First block
			head->hash = ""; // Hash of first block initialised to 0
			node = head; 
		}
		else{
			//block->hash = gethash(node); // Storing hash of previous block in Current Block
			block->hash = sha(node->data); // Storing hash of previous block in Current Block
			node->next = block;
			node = node->next;
		}
		cin>>data; 
	}

	return head; // Returning address of first block of Blockchain
	
}

string toUpper(string data)
{
	char DATA[data.length()+1];
	int i = 0;
	for ( ; i < data.length(); i ++){
		DATA[i] = char(int(data[i]) + 65 -97 );
	}
	DATA[i] = '\0';
	string str_DATA(DATA);
	return str_DATA;
}


int main(){

	/*cout <<"It will ask user to enter a value and then it will create a block having 3 values namely"
		"\n\t1. Value at that Node"
		"\n\t2. Hash value of previous block"
		"\n\t3. Address of next block"<<endl<<endl;
	*/
	cout << "\tSimpleBlockhain in C++ \n";
	cout <<"Whenever a user press 'q' it will quit the program and display the content of Blockchain.\n"<<endl;

	Blockchain *block = takeInput();
	cout << "Now printing the Blockchain"<<endl<<endl;

	int count = 1 ; 
	while ( block != NULL){
		cout <<count<<". Address of Current Block : "<<block<<endl;
		cout <<"\tBlock data: " << toUpper(block->data)<<endl;
		cout <<"\tHash of Previous Block : " << block->hash<<endl;
		cout <<"\tAddress of next Block : " << block->next<<endl<<endl;
		block = block ->next;
		count++;
	}
	return 0;
}











