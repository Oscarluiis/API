//
// Created by @Oscarluiis on 8/1/18.
//

#ifndef API_DATAFILE_H
#define API_DATAFILE_H

#include <fstream>
#include <cstring>
using namespace std;


class DataFile {

private:

    fstream *file;
    char *path;

public:

    //Cons
    DataFile();
    void open(char* path);
    void close();
    void write(char *data, unsigned int pos, unsigned int length);
    char *read(unsigned int pos, unsigned int size);
};





#endif //API_DATAFILE_H
