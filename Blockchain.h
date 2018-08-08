#include<iostream>

using namespace std;

class Blockchain{

	public:
		string data;
		Blockchain *next;
		string hash ;

		Blockchain( string data = ""){
			this->data = data;
			this->next = NULL;
			this->hash = "" ;
		}

};

