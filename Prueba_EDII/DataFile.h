#pragma once
#include<fstream>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

class DataFile
{

private:
	fstream * file;
	char path;


public:
	DataFile();
	void open(char *path);
	void close();
	void write(char *data, unsigned int pos, unsigned int length);
	char *read(unsigned int pos, unsigned int size);
	int tamFile();
};

