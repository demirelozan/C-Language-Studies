#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patients.h"
#include "database.h"

extern int lastId;

int main()
{
	initDatabase();
	//clearDatabase();
	addPatient(38, "Ali", "asdasd", "department");
	addPatient(39, "Ali", "asdasd", "department" );
	addPatient(40, "Ali", "asdasd", "department");
	addPatient(41, "Ali", "asdasd", "department");
	addPatient(42, "Ali", "asdasd", "department");
	Patient* patients = getPatients();
	for(int i=0;i<getPatientNumber();i++)
	{
		Patient patient = patients[i];
		printf("Patient name %d \n", patient.id);
	}
	closeDatabase();
}
