#ifndef PATIENTS_H
#define PATIENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PatientStruct Patient;
struct PatientStruct
{
	int id;
	int birthday;
	char name[50];
	char email[50];
	char department[50];
	//int orders[10];
};

Patient createPatients(int birthday, char* name, char* email, char* department);
Patient* createPatientDynamic(int birthday, char* name, char* email, char* department);
void stringfyPatient(Patient patient, char* buffer);

#endif
