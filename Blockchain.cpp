
#include<iostream>
#include"Blockchain.h"

using namespace std;

long int gethash( Blockchain *node ){ // Hash

	long int hash = 0;
	string data = node->data;
	int count = 1;
	for ( int i = data.length(); i > -1; i -- ) // Hash value is simply the ASCII value of character multiplied by its index
	{
		hash += count * data[i];
		count *= 10;
	}
	return hash;
}

Blockchain * takeInput(){ // It will return The head i.e address of first block in the blockchain.

	string data;
	Blockchain *head = NULL; // First block in Blockchain
	Blockchain *node = NULL; // Intermediate block of blockchain
	cout <<"Please enter data, press 'q' to quit/stop"<<endl;
	cin>>data;

	while ( data.compare("q") ){
		Blockchain *block = new Blockchain(data); // Creating a block
		cout << "New Block Created \n";
		if ( head == NULL){
			head  = block; // First block
			head->hash = 0; // Hash of first block initialised to 0
			node = head; 
		}
		else{
			block->hash = gethash(node); // Storing hash of previous block in Current Block
			node->next = block;
			node = node->next;
		}
		cin>>data; 
	}

	return head; // Returning address of first block of Blockchain
	
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
		cout <<"\tBlock data: " << block->data<<endl;
		cout <<"\tHash of Previous Block : " << block->hash<<endl;
		cout <<"\tAddress of next Block : " << block->next<<endl<<endl;
		block = block ->next;
		count++;
	}
	return 0;
}











