#include "stdafx.h"
#include "FixedSizeRegister.h"


FixedSizeRegister::FixedSizeRegister() {
	this->code = -1;
	this->name = new char[30];
	this->salary = salary;
	this->job = new char[20];
	this->file = new DataFile();

}
void FixedSizeRegister::print_register() {
	string name = "", salary="", job = "";
}

char *FixedSizeRegister::toChar(){
	char *newr = new char[54];
	for (int i = 0; i < 30; i++)
	{
		newr[i] = code;
		newr[i+30] = this->name[i+30];
		newr[i + 20] = this->job[i + 20];

	}
	newr[50] = this->salary;
	return newr;
}

void FixedSizeRegister::fromChar(char *conver) {
	for (int i = 0; i < 30; i++){
		this->code = code;
		this->name[i+30] = conver[i+30];
		this->job[i + 50] = conver[i + 50];

	}

	this->salary = conver[58];
}

void FixedSizeRegister::open_file() {
	string name;
	cout << "= = = = Ingrese nombre del archivo = = = = = : "<< endl;
	cin >> name;
	char*file;
	char test[6];
	file = new char[strlen(name.c_str())];
}

FixedSizeRegister::~FixedSizeRegister()
{
}

//PENDIENTES
void FixedSizeRegister::read_from_file() {
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

void FixedSizeRegister::write_into_file(){

}

void FixedSizeRegister::close_file() {
	this->file->close();
}

int FixedSizeRegister::get_size() {
	int get_size = 0;
	get_size += 1;
	get_size += strlen(this->name);
	get_size += 3;
	get_size += strlen(this->job);
	get_size += 6;
	return get_size;
}


