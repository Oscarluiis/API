//
// Created by @Oscarluiis on 8/1/18.
//

#include "DataFile.h"
//#include <cstring>



DataFile::DataFile() {

}

void DataFile::open(char *path) {

    this->file = new fstream(path, ios::in | ios::out | ios::binary);
}

void DataFile::close() {

    this->file->close ();
}

void DataFile::write(char *data, unsigned int pos, unsigned int length) {

    this->file->seekp(pos);
    this->file->write (data,length);

}

char* DataFile::read(unsigned int pos, unsigned int size) {
    char* lecture = new char [size];
    this->file->seekp(pos);
    this->file->read(lecture,size);
    return lecture;
}

