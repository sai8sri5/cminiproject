#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void scheme();
void login();
void rent();  
void view();
void edit();  
void delete1();
void search();
struct CustomerDetails   
{
	int bikenumber;
	char name[20];
	char address[20];
	char phonenumber[15];
	char nationality[15];	
	char email[35];
	int period;
}s;

int main()   
{
	int i=0;
	
	time_t t;
	time(&t);  
	printf("\t\t       WELCOME TO BIKE RENTAl SYSTEM            \n");
	printf("\t\t       -----------------------------           \n");
	printf("\t\t                 ROYAL ENFIELD                   \n");
	printf("\t\t                   ELURU                        \n");
	printf("\t\t          CONTACT US:8179503154                \n");
	printf("\n\t\t------------------------------------------------");
	printf("\nCurrent date and time : %s",ctime(&t));
	printf("\n\t\t------------------------------------------------");
	printf(" \n Press any key to continue:");	
	getch();	
    login();
    scheme();
}
void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="sai";
    char pass[10]="password";
    do
{
	
    printf("\n ------------------------  LOGIN FORM  ----------------------  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	
	i=0;

		if(strcmp(user,uname)==0&&strcmp(pass,pword)==0)
	{
	printf("  \n\n\n       NOW YOU ARE LOGGED IN. WELCOME TO OUR SYSTEM !!");
	printf("\n\n         Press any key to continue     ");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}	
}


void scheme()
{
	int i=0;
	
	time_t t;
	time(&t);
	char customername;
	char choice;
	while (1)      
	{
		 for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ----------------------  MAIN MENU  ------------------------ \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t Select and Enter Your Choice From Menu:");
		printf("\n");
		printf(" \n Enter 1 -  Rent a bike");
		printf("\n");
		printf(" \n Enter 2 -  View Rental Record");
		printf("\n");
		printf(" \n Enter 3 -  Remove Rental Record");
		printf("\n");
		printf(" \n Enter 4 -  Search Rental Record");
		printf("\n");
		printf(" \n Enter 5 -  Edit Record");
		printf("\n");
		printf(" \n Enter 6 -  Exit");
		printf("\n");
		printf("\n \n");
		for(i=0;i<80;i++)
		printf(" ");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf(" ");
		printf("\n enter your choice");
        choice=getche();
		choice=toupper(choice);
		switch(choice)          
		{	
			case '1':
				rent();break;
			case '2':
				view();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				printf("\n\n\t ------THANK YOU-------");
				printf("\n\t FOR USING OUR SERVICE");
				exit(0);
				break;
			default:
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}
void rent()
{
	FILE *f;
	int bikenumber, n, i, valid=0;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	printf("\n Enter Customer Details:");
	printf("\n-------------------------");
	
	if((f = fopen("add.txt","r+"))!=NULL)
	{
		RENT:
		printf("\n Enter bike number\t: ");
		scanf(" %d",&bikenumber);
		while(fscanf(f,"%d %s %s %s %s %s %d\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
	    {
	    	if(bikenumber == s.bikenumber)
	    	{
	    		printf("\n\tTHIS BIKE IS ALREADY ON RENT.");
	    		goto RENT;
			}
		}
		s.bikenumber == bikenumber;
		NAME:
		printf("\n Enter Name\t\t: ");
		fflush(stdin);
		gets(s.name);
		if(strlen(s.name)>20||strlen(s.name)<2)
		{
			printf("\nInvalid!!\n\t the entered name is faulty\n");
			goto NAME;
		}
		else
		{
			for (i=0;i<strlen(s.name);i++)
			{
				if(isalpha(s.name[i]))
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\nName contains invalid characters, Please enter again.\n");
				goto NAME;
			}
		}
		do
		{
			A:
			printf("\n Enter Address\t\t:");
			scanf("%s",s.address);
			if(strlen(s.address)>20 || strlen(s.address)<2)
			{
				printf("\nInvalid!!\n\tThe maximum number for customer's address is faulty\n");
				goto A;
			}
			else
			{
				for (i=0;i<strlen(s.address); ++i)
				{
					if(isalpha(s.address[i]))
					{
						valid = 1;
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					printf("\nName contain invalid character. Please enter again.\n");
				}
				}
		}while(!valid);
		do
		{
			P:
			printf("\n Enter Phone Number\t: ");
			scanf("%s",s.phonenumber);		
			if (strlen(s.phonenumber)!=10 || strlen(s.phonenumber)>10)
			{
				printf("\nPhone number should be of 10 numbers from 0-9. Please, enter valid number.\n");
				goto P;
			}
			for(i=0;i<strlen(s.phonenumber); i++)
			{
				if(!isalpha(s.phonenumber[i]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\nThe phone number is invalid, Please enter valid number .\n");
			}
		}while(!valid);
		do
		{
			X:
			printf("\nEnter Nationality\t: ");		
			scanf("%s",s.nationality);
			if(strlen(s.nationality)>10 || strlen(s.nationality)<2)
			{
				printf("\nInvalid!!\n\tThe maximum name can be upto 15 and and more than 1.\n");
				goto X;
			}
			for(i=0;i<strlen(s.nationality); i++)
			{
				if(isalpha(s.nationality[i]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\nThe nationality name contains only character. Please, enter again.\n");
			}
		}while(!valid);
		do
		{  y:
			printf("\nEnter Email\t\t: ");
			scanf(" %s",s.email);
			if(strlen(s.email)>35||strlen(s.email)<10)
			{
				printf("\nInvalid!!\n\tThe maximum number for customer's email is faulty\n");
				goto y;
			}
			
		}while(strlen(s.email)>35||strlen(s.email)<2);	
		do
		{
			printf("\nEnter Time Period(\'x\'days)\t: ");
			scanf("%i",&s.period);
			if(s.period>10 || s.period<=0)
			{
				printf("\tInvalid!!\n\tThe maximum bike rental days for customer  is upto 10 days .\n");
			}
		}while(s.period>10 || s.period<=0);
		
		
		fprintf(f,"%d %s %s %s %s %s %d\n", s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
		printf("\n\n the Bike  you wanted is rented successfully!!");
		fclose(f);
	}
	printf("\n Press esc key to exit,  any other key to add another customer detail:");
	test=getche();
	if(test==27)
		scheme();
	else
		rent();
}

void view()
{
	FILE *f;
	int i, q;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	printf("\nBIKENUMBER\n ");
	printf("\nNAME\n ");
	printf("\nADDRESS\n ");
	printf("\nPHONENUMBER\n ");
	printf("\nNATIONALITY\n ");
	printf("\nEMAIL\n ");
	printf("\nTIME PERIOD \n");
	
	for(i=0;i<110;i++)
	{
		printf("-");
	}
	q=9;
	while(fscanf(f,"%d %s %s %s %s %s %d\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
	{
		printf("\n%d",s.bikenumber);
		printf("\n%s",s.name);
		printf("\n%s",s.address);
		printf("\n%s",s.phonenumber);
		printf("\n%s",s.nationality);
		printf("\n%s",s.email);
		printf("\n%d",s.period);
		q++;
	}
	printf("\n");
	for(i=0;i<110;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=0;
	int bikenumb;
	t=fopen("temp.txt","w");
	if ((f=fopen("add.txt","r"))==NULL)
	{
		printf("NO RECORD ADDED.");
		scheme();
	}
	else
	{
		printf("Enter the Bike Number to be deleted from the database: ");
		fflush(stdin);
		scanf("%d",&bikenumb);
		while(fscanf(f,"%d %s %s %s %s %s %d\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
		{
			if(bikenumb != s.bikenumber)
			{
				fprintf(t,"%d %s %s %s %s %s %d\n", s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
			}
			else
			{
				i=1;
			}
		}
		if(!i)
		{
			printf("\n\n Records of Customer in this  bike number not found!!");
			getch();
			fclose(f);
			fclose(t);
			scheme();
		}
		else
		{
			printf("\n\tSuccessfully deleted.\n");
		}
		fclose(f);
		fclose(t);
		remove("add.txt");
		rename("temp.txt","add.txt");
		getch();
	}
}

void search()
{
	FILE *f;
	int bikenumber;
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
	{
		printf("NO RECORD ADDED.");
		scheme();
	}
	else
	{
		fflush(stdin);
		printf("Enter bike number of the customer to search its details: \n");
		scanf("%s", &bikenumber);
		while(fscanf(f,"%d %s %s %s %s %s %d\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
		{
			if(bikenumber==s.bikenumber)
			{
				flag=0;
				printf("\n\tRecord Found\n");
				printf("\nBike Number\t: %d",s.bikenumber);
				printf("\nName\t\t: %s",s.name);
				printf("\nAddress\t\t: %s",s.address);
				printf("\nPhone number\t: %s",s.phonenumber);
				printf("\nNationality\t: %s",s.nationality);
				printf("\nEmail\t\t: %s",s.email);
				printf("\nPeriod\t\t: %d",s.period);
				break;
			}
		}
		if(flag==1){	
			printf("\n\tRequested Customer could not be found!");
		}
		getch();
		fclose(f);
		scheme();
	}
	
}

void edit()
{
	FILE *f, *r;
	int k=0;
	char ed;
	int bikenumber;
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		scheme();
	}
	else
	{
		r = fopen("temp.txt","a");
		printf("Enter bike number of the customer to edit:\n\n");
		scanf("%s",&bikenumber);
		fflush(stdin);
		while(fscanf(f,"%d %s %s %s %s %s %d\n", &s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, &s.period)!=EOF)
		{
			if(bikenumber==s.bikenumber)
			{
				
				k=1;
				printf("\n\t*** Existing Record ***");
				printf("\nBike Number\t: %d",s.bikenumber);
				printf("\nName\t\t: %s",s.name);
				printf("\nAddress\t\t: %s",s.address);
				printf("\nPhone number\t: %s",s.phonenumber);
				printf("\nNationality\t: %s",s.nationality);
				printf("\nEmail\t\t: %s",s.email);
				printf("\nPeriod\t\t: %d",s.period);
				printf("\n\n\t*** New Record ***");
				printf("\nEnter New Name           : ");
				fflush(stdin);
				scanf("%s",s.name);
				printf("\nEnter New Address        : ");
				scanf("%s",s.address);
				printf("\nEnter New Phone number   : ");
				scanf("%s",s.phonenumber);
				printf("\nEnter New Nationality    : ");
				scanf("%s",s.nationality);
				printf("\nEnter New Email          : ");
				scanf("%s",s.email);
				printf("\nEnter New Period         : ");
				scanf("%d",&s.period);
				printf("Press 'm' to edit the existing record or any key to cancel...");
				ed=getche();
				if(ed=='m' || ed=='M')
				{
					fprintf(r,"%d %s %s %s %s %s %i\n", s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
					fflush(stdin);
					printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
				}
			}
			else
			{
				fprintf(r,"%d %s %s %s %s %s %d\n", s.bikenumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period);
				fflush(stdin);
			}
			
		}
		if(!k)
		{
			printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		}
		fclose(r);
		fclose(f);
		remove("add.txt");
		rename("temp.txt","add.txt");
		getch();
	}
	scheme();
}

