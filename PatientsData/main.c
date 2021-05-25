#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patients.h"
#include "database.h"

extern int lastId;
int exitPressed;

int main()
{
	exitPressed = 0;
	initDatabase();
	//clearDatabase();
	addPatient("Emre", "Dincel", "14/05/1989","dincele@hotmail.com.tr", "Immunology");
	addPatient("Cansu", "Kaya", "31/09/1994","deneme03@gmail.com.", "Pathology");
	addPatient("Ahmet", "Gungor", "02/12/1972","deneme01@hotmail.com.", "Cardiology");
	addPatient("Mahmut", "Karadag", "30/03/1987","deneme@gmail.com", "Cardiology");
	addPatient("Kaan", "Kaya", "11/02/1983","kaya@deneme.com", "Microbiology");
	Patient* patients = getPatients();
	

	int userSelection;
	printf("0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
	printf("Please select an option ");
	

	
	
	while(exitPressed < 1)
	{

		scanf("%d", &userSelection);
	

		if(userSelection == 0)
		{
			exitPressed = 1;
		}
		else if(userSelection == 1)
		{
			printf("PATIENT RECORDS: \n");
			for(int i=0;i<getPatientNumber();i++)
			{
			Patient patient = patients[i];
		
			printf("%d", (patient.id +1 ));
			printf("        %s", patient.name);
			printf("        %s", patient.surname);
			printf("        %s", patient.birthday);
			printf("        %s", patient.email);
			printf("        %s", patient.department);
			printf("\n");		
			}
		}
		else if(userSelection == 2)
		{
			int n = 0;
			int m = 0;
			int surnameLength = 50;
			char surname[surnameLength]; 
			printf("Patient Surname: ");
			scanf("%d %s",strlen(surname), surname[surnameLength]);
			int length = strlen(surname);			

			for(int i=0; i<getPatientNumber();i++)
			{

				Patient patient = patients[i];
				if(surname[n] == patient.surname[m]) 
				{     
				// if first character of search string matches, keep on searching
         			while(surname[n] == patient.surname[m]  && surname[n] !='\0')
					{
            			n++;
            			m++;
        			}
        			// if we sequence of characters matching with the length of searched string
            		if(m == length && (surname[surnameLength] == ' ' || surname[surnameLength] == '\0')) 
					{
						printf("%d", (patient.id +1 ));
						printf("        %s", patient.name);
						printf("        %s", patient.surname);
						printf("        %s", patient.birthday);
						printf("        %s", patient.email);
						printf("        %s", patient.department);
						printf("\n");			
           	      		// BINGO!! we find our search string.
					}	
				}
			}

		}
		else
		{
			printf("PLEASE ENTER A VALID VALUE! \n");
			printf("0: Exit | 1: Show All Records | 2: Search Patient | 3: New Patient \n");
			printf("Please select an option ");
			scanf("%d", &userSelection);
		}
	}

	closeDatabase();
}
