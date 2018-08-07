#pragma once
#include "DataFile.h"
using namespace std;

class KnowVarSize_Register
{

private:
	DataFile * file;
	int code; //Edad
	int sizeName; //tamano_nombre
	char*name; //nombre
	double salary; //edad
	int sizeJob; //tamano direccion
	char*job; // direccion
public:
	KnowVarSize_Register(int code, char*name,double salary, char*job);
	~KnowVarSize_Register();
	void print_register();
	char * toChar();
	void fromChar(char*);
	void open_file();
	void write_into_field();
	void read_from_file();
	void close_file();
	int get_size();


};

