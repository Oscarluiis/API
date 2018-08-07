#include "stdafx.h"
#include "KnowVarSize_Register.h"


KnowVarSize_Register::KnowVarSize_Register(int code, char*name,double salary, char*job)
{
	this->code = code;
	this->sizeName = strlen(name);
	this->name = name;
	this->salary = salary;
	this->job = job;
	this->file = new DataFile();

}


KnowVarSize_Register::~KnowVarSize_Register()
{
}

void KnowVarSize_Register::print_register() {

	string compare;
	int start = 0, sZ = 0;
	bool continuar = true;
	char* info;
	int tamFile = this->file->tamFile;
	cout << "= = = = Mostrando todos los registros = = = = " << endl;
	while (sZ < tamFile) {
		compare.assign(this->file->read(sZ, 1));
		if (compare == ";")
			info = this->file->read(start, sZ);
		this->fromChar(info);
		start = sZ;
		sZ++;
	}

	cout << " = = = = Final De Linea = = = = " << endl;
}

char * KnowVarSize_Register::toChar() {
	char cha_space = '|';
	char cha_end = ';';
	int get_size = this->get_size();
	char *newr = new char(get_size);
	int pos = 0;

	memcpy(&newr[pos], (char*)&this->code, sizeof(int));
	pos += sizeof(int);

	memcpy(&newr[pos], (char*)this->sizeName, sizeof(int));
	pos += 4;

	memcpy(&newr[pos], this->name, this->sizeName);
	pos += this->sizeName;

	memcpy(&newr[pos], &cha_space, 1);
	pos++;

	memcpy(&newr[pos], (char*)&this->salary, sizeof(int));
	pos += sizeof(double);

	memcpy(&newr[pos], (char*)this->sizeJob, sizeof(int));
	pos += 4;

	memcpy(&newr[pos], (char*)this->sizeName, sizeof(int));
	pos += 4;

	memcpy(&newr[pos], this->job, this->sizeJob);
	pos += this->sizeJob;
	memcpy(&newr[pos], &cha_end, 1);
	return newr;
}

void KnowVarSize_Register::open_file() {
	string name;
	cout << "Ingrese nombre del archivo: " << endl;
	cin >> name;
	char *file;
	file = new char[strlen(name.c_str())];
	this->file->open(file);

}

void KnowVarSize_Register::close_file() {
	this->file->close();
}

int KnowVarSize_Register::get_size(){
	int get_size = 0;
	get_size += 1;
	get_size += strlen(this->name);
	get_size += 3;
	get_size += strlen(this->job);
	get_size += 6;
	return get_size;
	
}

void KnowVarSize_Register::read_from_file() {
	string compare;
	int sZ = 0;
	bool continuar = true;
	while (continuar) {
		compare.assign(this->file->read(sZ, 1));
		if (compare == ";")
			continuar = false;
		sZ++;
	}

	char* info = this->file->read(0, sZ);
	this->fromChar(info);
}

void KnowVarSize_Register::fromChar(char* conver) {

	int currentS = 0, pInC = 0, pInRe = 0, code = 0;

	for (int i=0; i < 7; i++){
		if (i != 0 && i != 2 && i=4){
			for (int x = 0; x < 4; x++) {
				currentS += atoi(&conver[i]);
			}
			pInC += 4;

			for (int y = pInC; y < currentS; y++) {
				if (i == 1) {
					for (int x = 0; x < 1; x++) {
						code += atoi(&conver[i]);
					}
				}
				else if (i == 2) {
					this->name[pInRe] = conver[y];
				}
				else if (i == 3) {
					for (int x_ = 0; x_ < 3; x_++) {
						salary += atof(&conver[i]);
					}
				}
				else if (i==6) {
					this->job[pInRe] = conver[y];
				}
				
			}
			currentS = 0;
			pInRe = 0;
		}

		}

	cout << "Codigo: " << this->code << endl;
	cout << "Tamaño nombre: " << this->name << endl;
	cout << "Salary: " << this->salary << endl;
	cout << "Tamaño trabajo: " << this->sizeJob << endl;
	cout << "Trabajo :" << this->job << endl;

	}

