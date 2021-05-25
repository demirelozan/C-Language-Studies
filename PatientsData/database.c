#include "database.h"

int initDatabase()
{
	dbFile = fopen("./database.txt", "a+");
	if(dbFile == NULL)
	{
		return -1;
	}
	readPatients();
	printf("Ends %d\n", patientIndex);
	return 0;
}

void clearDatabase()
{
	freopen("./database.txt",  "w+", dbFile);
}
void closeDatabase()
{
	fclose(dbFile);
}

Patient* getPatients()
{
	return patients;
}
int getPatientNumber()
{
	return patientIndex;
}
int readPatients()
{
	//First line is the last id
	rewind(dbFile);
	int lineNumber = 0;

	while(!feof(dbFile))
	{	

		if(lineNumber == 0)
		{
			int check = fscanf(dbFile, "%d\n", &lastId); //that \n is needed
			if(check==0)
			{
				lastId = 0; //Couldn't read. Possivle empty file
			}
		}else{
		//	fgets(lineBuffer, 200, dbFile);
			int id;
			char nameBuffer[50];
			char surnameBuffer[50];
			char birthdayBuffer[50];
			char emailBuffer[100];
			char departmentBuffer[50];
			int check = fscanf(dbFile, "%d %s %s %s %s %s", &id, nameBuffer, surnameBuffer, birthdayBuffer, emailBuffer, departmentBuffer);
			if(check == 6)
			{
				Patient patient = createPatient(nameBuffer, surnameBuffer, birthdayBuffer, emailBuffer, departmentBuffer);
				patientIndex++;
				//printf("Adding to %d\n", customerIndex);
				patients[patientIndex] = patient;
			}
		}
		lineNumber++;
	}
}
void updateDatabase()
{
	clearDatabase();
	rewind(dbFile);
	fprintf(dbFile, "%d\n", lastId);
	int i;
	for(i=0;i<patientIndex+1;i++)
	{

		Patient patient = patients[i];
		fprintf(dbFile, "%d %s %s %s %s %s\n", patient.id, patient.name, patient.surname, patient.birthday, patient.email, patient.department);
	}
}
int addPatient(char* name, char* surname, char* birthday, char* email, char* department)
{
	//Customer newCustomer = createCustomer(age, name, email);
	Patient newPatient = createPatient(name, surname, birthday, email, department);
	newPatient.id = lastId;
	lastId++;
	patientIndex++;
	printf("Adding to %d\n", patientIndex);
	patients[patientIndex] = newPatient;
	updateDatabase();
}

