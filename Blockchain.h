#include<iostream>
#include<string>

using namespace std;

class Blockchain{

	public:
		string data;
		Blockchain *next;
		long int hash ;

		Blockchain( string data = ""){
			this->data = data;
			this->next = NULL;
		}

};

