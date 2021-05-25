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
int addPatient(char* name, char* surname, char* birthday, char* email, char* department);


#endif
