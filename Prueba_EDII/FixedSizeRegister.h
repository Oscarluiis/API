#pragma once
#include "DataFile.h"
using namespace std;

class FixedSizeRegister
{

private:
	DataFile * file;
	int code; //edad
	char* name; //30 nombre
	double salary; //edad
	char*job; //20 apellido


public:
	FixedSizeRegister();
	~FixedSizeRegister();
	void print_register();
	char* toChar();
	void fromChar(char*);
	void open_file();
	void read_from_file();
	void write_into_file();
	void close_file();
	int get_size();
};

