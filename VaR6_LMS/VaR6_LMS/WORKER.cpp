#include "WORKER.h"
#include <cstring>

WORKER::WORKER(const char* n, const char* r, int y) 
{
	strcpy_s(name, 50, n);
	strcpy_s(role, 50, r);
	ICS = y;
}

WORKER::WORKER()
{
	name[0] = '\0';
	role[0] = '\0';
	ICS = 0;
}
WORKER::WORKER(const WORKER& w)
{
	strcpy_s(name, 50, w.name);
	strcpy_s(role, 50, w.role);
	ICS = w.ICS;
}
WORKER::~WORKER() {}

bool WORKER::operator>(const WORKER& w)
{
	return strcmp(this->name, w.name) > 0;
}

WORKER& WORKER ::operator=(const WORKER& w)
{
	strcpy_s(name, 50, w.name);
	strcpy_s(role, 50, w.role);
	ICS = w.ICS;
	return *this;
}

int WORKER::GetICS() const
{
	return ICS;
}

const char* WORKER::getName() const
{
	return name;
}