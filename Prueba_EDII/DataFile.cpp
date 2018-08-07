#include "stdafx.h"
#include "DataFile.h"


DataFile::DataFile()
{
}


void DataFile::open(char *path) {
	this->file = new fstream(path, ios::in | ios::out | ios::binary);
}

void DataFile::close() {
	this->file->close();
}

char* DataFile::read(unsigned int pos, unsigned int size) {
	char* leer = new char[size];
	this->file->seekp(pos);
	this->file->read(leer, size);
	return leer;

	}

void DataFile::write(char *data, unsigned int pos, unsigned int length) {
	this->file->seekp(pos);
	this->file->write(data, length);
}

int DataFile::tamFile() {
	return this->file->tellg();
}