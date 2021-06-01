#ifndef PATIENTS_H
#define PATIENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PatientStruct Patient;
struct PatientStruct
{
	int id;
	char name[50];
	char surname[50];
	char birthday[50];
	char email[100];
	char department[50];
};

Patient createPatient(char* name, char* surname, char* birthday, char* email, char* department);
Patient* createPatientDynamic(char* name, char* surname, char* birthday,char* email, char* department);
void stringfyPatient(Patient patient, char* buffer);

#endif
