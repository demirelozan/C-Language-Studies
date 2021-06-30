#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int CheckCredentials(char* email[], char pw[]);

int main()
{
	char* email[100];
	char password[50];
    printf("Enter your email\n");
    scanf("%s",email);
	
	printf("Enter your password\n");
    scanf("%s",password);
    
    CheckCredentials(email, password);
}





int CheckCredentials(char* email[], char pw[])
{

	
	int     creditential;
    char    *pos1, *pos2, *pos3, *ptr;
	
	 while (1) {
 	int creditential = 0;
        for (ptr = email; *ptr; *ptr++) 
		{
                if (*ptr == '@') {
                    pos1 = ptr;  //stores the adress of @
                    creditential++;
                }
                if(*ptr == '.')
                {
                	pos2 = ptr; //stores the adress of .
                	creditential++;
				}
        }
            pos3 = ptr;//stores the end ("/0")
            
        	if(pos1 > pos2)
        	{
        		printf("'.' cannot be before '@'! \n");
        		return 0;
			}
			//while(pos1 - email && ptr - pos1 > 1)
			//{
				int lower_case_count = 0;
     			int upper_case_count = 0;
     			int digit_count = 0;
     			int i;
     			int passwordLength;
				passwordLength = sizeof(pw -1);
     			
				for (i = 0; i < passwordLength; i++) 
				{
          			if (pw[i] >= 'a' && pw[i] <= 'z')
					{
				  		lower_case_count++;
					} 
          			if (pw[i] >= 'A' && pw[i] <= 'Z') 
          			{
          				upper_case_count++;
					}
					if (pw[i] >= '0' && pw[i] <= '9')
					{
						digit_count++;
					}
     			}			    
     			if (lower_case_count > 0 && upper_case_count > 0 && digit_count > 0)
				{
          			printf("Email and Password are applicable \n");
					return 1;		
     			}
				else
				{
					printf("Password does not contain applicable characters! \n");		
					return 0;		
				}				
			}	

        //}


}

