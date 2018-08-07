#include "stdafx.h"
#include "DelimiterVarSize_Register.h"


DelimiterVarSize_Register::DelimiterVarSize_Register()
{
	this->code = code;
	this->name = name;
	this->salary = salary;
	this->job = job;
	this->file = new DataFile();
}


DelimiterVarSize_Register::~DelimiterVarSize_Register()
{
}

void DelimiterVarSize_Register::print_register() {
	string compare;
	int start = 0, end = 0;
	bool continuar = true;
	
	cout << "= = = = Mostrando Todos Los Registros = = = =" << endl;
	while (continuar) {
		compare.assign(this->file->read(end, 1));
		if (compare == ";") {
			char * info = this->file->read(start, end);
			this->fromChar(info);
		}
		end++;
		if (end > this->file->tamFile) {
			continuar = false;
		}
		else {
			start = end;
		}
	}

	cout << "= = = = Final De Linea = = = =" << endl;
}

char * DelimiterVarSize_Register::toChar() {
	char cha_space = '|';
	char cha_end = ';';
	int get_size = this->get_size();
	char*newr = new char[get_size];
	int pos = 0;

	//Code
	memcpy(&newr[pos], (char*)&this->code, sizeof(int));
	pos++;

	//Escribir el caracter
	memcpy(&newr[pos], &cha_space, 1);
	pos++;
	
	//name
	int tam_name = strlen(this->name);
	memcpy(&newr[pos], this->name, tam_name);
	pos += tam_name;

	//Escribir el caracter
	memcpy(&newr[pos], &cha_space, 1);
	pos++;

	//Salary
	memcpy(&newr[pos], (char*)&this->salary, sizeof(double));
	pos++;

	//Escribir el caracter
	memcpy(&newr[pos], &cha_space, 1);
	pos++;

	//Job
	int tam_job = strlen(this->job);
	memcpy(&newr[pos], this->job, tam_job);
	pos += tam_job;
	memcpy(&newr[pos], &cha_end, 1);
	return newr;

}

void DelimiterVarSize_Register::fromChar(char * conver){

	string tempo = "";
	int i = 0, currentS = 0, currentP = 0;
	bool endLect = false;
	while (!endLect) {
		if (conver[i] == '|') {
			if (currentP == 2) {
				strcpy(this->name, (char*)&tempo);
				currentP++;
			}
			else if (currentP == 4) {
				strcpy(this->job, (char*)&tempo);
				endLect = true;
			}
			tempo = "";
			currentS = 0;
		}

		tempo += conver[i];
		currentS++;
	}
	cout << "Code: " << this->code << endl;
	cout << "Name: " << this->name << endl;
	cout << "Salary: " << this->salary << endl;
	cout << "Job: " << this->job << endl;

	}

void DelimiterVarSize_Register::openfile() {
	string name;
	cout << " Ingrese nombre de archivo: " << endl;
	cin >> name;
	char *file;
	file = new char[strlen(name.c_str())];
	this->file->open(file);
}

void DelimiterVarSize_Register::read_file() {
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

void DelimiterVarSize_Register::close_file(){
	this->file->close();
}

int DelimiterVarSize_Register::get_size() {
	//rS register size
	int rS = 0;
	rS += 1;
	rS += strlen(this->name);
	rS += 3;
	rS += strlen(this->job);
	return rS;

}

//Pendiente el writer
/*
void
write_into_file()
Escribe al final del archivo binario, la estructura de datos actual
*/