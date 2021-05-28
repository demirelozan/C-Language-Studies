#include "patients.h"

Patient createPatient(int birthday, char* name, char* email, char* department)
{
	Patient patient;
	patient.id = 0;
	patient.birthday = birthday;
	strcpy(patient.name, name);
	strcpy(patient.email, email);
	strcpy(patient.department, department);
	return patient;
}
Patient* createPatientDynamic(int birthday, char* name, char* email, char* department)
{
	Patient* patient = (Patient*) malloc(sizeof(Patient));
	patient->id = 0;
	patient->birthday = birthday;
	strcpy(patient->name, name);
	strcpy(patient->email, email);
	strcpy(patient->department, department);
	return patient;
}
void stringfyPatient(Patient patient, char* buffer)
{
	sprintf(buffer,"%d %d %s %s %s",patient.id, patient.birthday, patient.name, patient.email, patient.department);
}
