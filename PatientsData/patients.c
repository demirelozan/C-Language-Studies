#include "patients.h"

Patient createPatient(char* name, char* surname, char* birthday, char* email, char* department)
{
	Patient patient;
	patient.id = 0;
	strcpy(patient.name, name);
	strcpy(patient.surname, surname);
	strcpy(patient.birthday, birthday);
	strcpy(patient.email, email);
	strcpy(patient.department, department);
	return patient;
}
Patient* createPatientDynamic(char* name, char* surname, char* birthday, char* email, char* department)
{
	Patient* patient = (Patient*) malloc(sizeof(Patient));
	patient->id = 0;
	strcpy(patient->name, name);
	strcpy(patient->surname, surname);
	strcpy(patient->birthday, birthday);
	strcpy(patient->email, email);
	strcpy(patient->department, department);
	return patient;
}
void stringfyPatient(Patient patient, char* buffer)
{
	sprintf(buffer,"%d %s %s %s %s %s",patient.id, patient.name, patient.surname, patient.birthday ,patient.email, patient.department);
}
