#pragma once
#include "DataFile.h"
using namespace std;
class DelimiterVarSize_Register
{

private:
	DataFile * file;
	int code;
	char* name;
	double salary;
	char* job;



public:
	DelimiterVarSize_Register();
	~DelimiterVarSize_Register();
	void print_register();
	char * toChar();
	void fromChar(char*);
	void openfile();
	void read_file();
	void write_file();
	void close_file();
	int get_size();
};

