#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patients.h"
#include "database.h"

extern int lastId;
int exitPressed;
extern int deletedPatients;


int userInterface(int *userSel);
int patientSearch(int *userSel);
void updatePatient(char* name, char* surname, char* birthday, char* email, char* department, int updateId);



int main()
{

	
	exitPressed = 0;
	initDatabase();
	clearDatabase();
	
	addPatient("Emre", "Dincel", "14/05/1989","dincele@hotmail.com.tr", "Immunology");
	addPatient("Cansu", "Kaya", "31/09/1994","deneme03@gmail.com", "Pathology");
	addPatient("Ahmet", "Gungor", "02/12/1972","deneme01@hotmail.com", "Cardiology");
	addPatient("Mahmut", "Karadag", "30/03/1987","deneme@gmail.com", "Cardiology");
	addPatient("Kaan", "Kaya", "11/02/1983","kaya@deneme.com", "Microbiology");
	

	int userSelection;
	printf("\n0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
	printf("Please select an option: ");
	

	
	
	while(exitPressed < 1)
	{

		scanf("%d", &userSelection);
		userInterface(&userSelection);


	}

	closeDatabase();
}

int userInterface(int *userSel)
{
	//printf("HERE\n");
	int userSelection;
	userSelection = *userSel;
	Patient* patients = getPatients();
	
	
	
		if(userSelection == 0)
		{
			exitPressed = 1;
		}
		else if(userSelection == 1) //Show All Records
		{
			printf("PATIENT RECORDS: \n");
			for(int i=0;i<getPatientNumber()-deletedPatients;i++)
			{
		//	printf("getPatientNumber: %d \n", getPatientNumber());
			Patient	patient = patients[i];
		
			printf("%d", (patient.id +1));
			printf("        %s", patient.name);
			printf("        %s", patient.surname);
			printf("        %s", patient.birthday);
			printf("        %s", patient.email);
			printf("        %s", patient.department);
			printf("\n");		
			}
			printf("\n0: Return to Main Menu | 1: Delete Record | 2: Update Record \n");
			printf("Please select an option: ");
			scanf("%d", &userSelection);
			if(userSelection == 0)//Returning to Main Menu
			{
				//Return to Main Menu
				printf("0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
				printf("Please select an option: ");
				scanf("%d", &userSelection);
				return userInterface(&userSelection);
			}
			else if(userSelection == 1)//Delete Patient from Database
			{
				int deleteId;
				printf("Patient Id You Want to Delete: ");
				scanf("%d", &deleteId);
				if(deleteId > getPatientNumber())
				{
					printf("There is no Id as entered\n");
				}
				else
				{
					int j; 
					for(j = deleteId -1; j < getPatientNumber() -1; j++)
					{
						patients[j] = patients[j+1];
						patients[j].id--;
					}
				
					deletedPatients++;
					printf("\nPatient record is deleted... \n");
					printf("\n0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
					printf("Please select an option: ");
				}
			}
			else if(userSelection == 2) //Update Records
			{
				int updateId;
				char updatedName[50];
				char updatedSurname[50];
				char updatedBirthday[50];
				char updatedEmail[100];
				char updatedDepartment[50];
				
				//Getting inputs from user
				printf("Patient's Id you want to update: ");
				scanf("%d", &updateId);
				Patient patient = patients[updateId -1];
				
				printf("Enter Name (Old: %s): ",patient.name);
				scanf("%s", updatedName);
				
				printf("\nEnter Surname (Old: %s): ",patient.surname);
				scanf("%s", updatedSurname);
				
				printf("\nEnter Birthday (Old: %s): ",patient.birthday);
				scanf("%s", updatedBirthday);
				
				printf("\nEnter E-Mail (Old: %s): ",patient.email);
				scanf("%s", updatedEmail);
				
				printf("\nEnter Department(Old: %s): ",patient.department);		
				scanf("%s", updatedDepartment);
				
				//Updating the database
				updatePatient(updatedName, updatedSurname, updatedBirthday, updatedEmail, updatedDepartment, updateId);
				
			
				printf("\n\nPatient record is updated... \n");
				
				printf("\n0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
				printf("Please select an option: ");
				scanf("%d", &userSelection);
				return userInterface(&userSelection);
			}
		}
		else if(userSelection == 2) //Search Patient
		{
			patientSearch(&userSelection);	
		}
		else if(userSelection == 3) //Add Patient
		{
			char userName[50];
			char userSurname[50];
			char userBirthday[50];
			char userEmail[100];
			char userDepartment[50];
			
			printf("Enter Name: ");
			scanf("%s", userName);
			printf("\nEnter Surname: ");
			scanf("%s", userSurname);
			printf("\nEnter Birthday (dd/mm/yyyy): ");
			scanf("%s", userBirthday);
			printf("\nEnter E-mail: ");
			scanf("%s", userEmail);
			printf("\nEnter Department: ");
			scanf("%s", userDepartment);
			
			printf("\nNew Patient has been recorded...\n");
			
			if(deletedPatients > 0)
			{
					addPatient(userName, userSurname, userBirthday, userEmail, userDepartment);			
					patientIndex++;
				//	printf("\npatients number: %d \n", getPatientNumber());
						patients[getPatientNumber()-1 -deletedPatients] = patients[getPatientNumber()-deletedPatients];
					
					//updateDatabase
					printf("0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
					printf("Please select an option: ");
					scanf("%d", &userSelection);
					userInterface(&userSelection);
			}
			else
			{
				addPatient(userName, userSurname, userBirthday, userEmail, userDepartment);			
				patientIndex++;
				//updateDatabase
				printf("0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
				printf("Please select an option: ");
				scanf("%d", &userSelection);
				userInterface(&userSelection);
			}
			
			
		}
		else
		{
			printf("PLEASE ENTER A VALID VALUE! \n");
			printf("0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
			printf("Please select an option: ");
			scanf("%d", &userSelection);
			return userInterface(&userSelection);
		}
}

void updatePatient(char* name, char* surname, char* birthday, char* email, char* department, int updateId)
{
			Patient* patients = getPatients();
			//Creating a Patient with given inputs
			Patient updatedPatient = createPatient(name, surname, birthday, email, department);
			updatedPatient.id = updateId-1;
			//Assigning the patient to the given id which is wanted to upgraded.
			patients[updateId-1] = updatedPatient;
			//Updating the text file(database) with the new patients array.
			clearDatabase();
			rewind(dbFile);
			int i;
			for(i=0;i<getPatientNumber()-deletedPatients;i++)
			{
			Patient patient = patients[i];
			fprintf(dbFile, "%d %s %s %s %s %s\n", patient.id, patient.name, patient.surname, patient.birthday, patient.email, patient.department);
			}//Updated the text file(database) with the new patients list.


}

int patientSearch(int *userSel)
{
			Patient* patients = getPatients();
			int userSelection = *userSel;
			printf("\n0: Return to Main Menu | 1: Search By Id | 2: Search By Name | 3: Search By Surname \n");
			printf("Please select an option: ");
			scanf("%d", &userSelection);
			
			if(userSelection== 0)//Sub menu, Return to Main Menu
			{
				//Return to Main Menu
				printf("\n0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
				printf("Please select an option: ");
				scanf("%d", &userSelection);
				return userInterface(&userSelection);
			}
			else if(userSelection == 1)//Sub menu, Search by User Id
			{
				//Search by Id
				int userSelectionId;
				printf("Patient Id: ");
				scanf("%d", &userSelectionId);
				printf("\n Searching... \n");
				
				if(userSelectionId <= getPatientNumber())
				{
					Patient patient = patients[userSelectionId-1];
					
					printf("\n");
					printf("%d", (patient.id +1));
					printf("        %s", patient.name);
					printf("        %s", patient.surname);
					printf("        %s", patient.birthday);
					printf("        %s", patient.email);
					printf("        %s", patient.department);
					printf("\n");		
					printf("\n Search Completed, 1 Patient Found With Entered Id \n");								
					printf("\n0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
					printf("Please select an option: ");
				}
				else
				{
					printf("You have entered invalid Id! \n");
					printf("Patient Id: ");
					scanf("%d", &userSelectionId);
				}
			}
			else if(userSelection ==2)//Sub menu, Search by User Name
			{
				//Search by Name
				int nameLength = 50;
				int matchedData;
				char name[nameLength]; 
				printf("Please write the first character Upper letter \n");
				printf("Patient Name: ");
				scanf("%s", name);
				printf("\n Searching... \n");
				
				int matchedPatientCount = 0;
				
				for(int i=0; i<=getPatientNumber();)
				{

				Patient patient = patients[i];
			
				matchedData = strcmp(name, patient.name);
					if(matchedData == 0) 
					{     
						printf("\n");
						printf("%d", (patient.id +1));
						printf("        %s", patient.name);
						printf("        %s", patient.surname);
						printf("        %s", patient.birthday);
						printf("        %s", patient.email);
						printf("        %s", patient.department);
						printf("\n");			
           	      	//	printf("Matched Result \n");
						matchedData =1;
						matchedPatientCount++;
						i++;
									
					}
					else
					{
						matchedData=1;
						i++;
					}
				}
				printf("\n Search Completed, %d Patient(s) found... \n", matchedPatientCount);
				printf("\n0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
				printf("Please select an option: ");
			
			}
			else if(userSelection ==3)//Sub menu, Search by User Surname
			{
				//Search by Surname
				int surnameLength = 50;
				int matchedData;
				char surname[surnameLength]; 
				printf("Please write the first character Upper letter \n");
				printf("Patient Surname: ");
				scanf("%s", surname);
				printf("\n Searching... \n");
				int matchedPatientCount = 0;

				for(int i=0; i<=getPatientNumber();)
				{
			
				Patient patient = patients[i];
			
				matchedData = strcmp(surname, patient.surname);
					if(matchedData == 0) 
					{   
						printf("\n");
						printf("%d", (patient.id +1));
						printf("        %s", patient.name);
						printf("        %s", patient.surname);
						printf("        %s", patient.birthday);
						printf("        %s", patient.email);
						printf("        %s", patient.department);
						printf("\n");			
           	      	//	printf("Matched Result \n");
						matchedData =1;
						matchedPatientCount++;
						i++;
					
						
									
					}
					else
					{
						matchedData=1;
						i++;
					}
				}
				printf("\n Search Completed, %d Patient(s) found... \n", matchedPatientCount);
				printf("\n0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
				printf("Please select an option: ");
			
			}
			else
			{
				printf("\nYou have entered invalid value! \n");
				printf("\nTry Again\n");
				return patientSearch(&userSelection);
			}
}


