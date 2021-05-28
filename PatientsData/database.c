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
int getPatientsNumber()
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
			int birthday;
			int id;
			char nameBuffer[50];
			char emailBuffer[50];
			char departmentBuffer[50];
			int check = fscanf(dbFile, "%d %s %s %s %d", &id, nameBuffer, emailBuffer, departmentBuffer, &birthday);
			if(check == 5)
			{
				Patient patient = createPatient(birthday, nameBuffer, emailBuffer, departmentBuffer);
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
		fprintf(dbFile, "%d %d %s %s %s\n", patient.id, patient.name, patient.email, patient.department, patient.birthday);
	}
}
int addPatient(int birthday, char* name, char* email, char* department)
{
	//Customer newCustomer = createCustomer(age, name, email);
	Patient newPatient = createPatient(birthday, name, email, department);
	newPatient.id = lastId;
	lastId++;
	patientIndex++;
	printf("Adding to %d\n", patientIndex);
	patients[patientIndex] = newPatient;
	updateDatabase();
	
}

