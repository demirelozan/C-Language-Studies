#ifndef DATABASE_H
#define DATABASE_H

#include "patients.h"


static FILE* dbFile;
static Patient patients[100];
static int patientIndex = -1;
static int lastId = 0;

int initDatabase();
Patient* getPatients();
void clearDatabase();
void updateDatabase();
void closeDatabase();

//CRUD
int getPatientNumber();
int readPatients();
int addPatient(int birthday, char* name, char* email, char* department);


#endif
