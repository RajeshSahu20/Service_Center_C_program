#include"tecni.c"
/* 1. admin */
void admin()
{
	char user[20];
	char password[9];
	char c;
	int i,ch;
	clrscr();
	heading();
	printf("\n                         Enter username : ");
	scanf("%s",user);
	printf("\n                         Enter a Password : ");
	for(i=0;i<8;i++)
	{
		c=getch();
		printf("*");
		password[i]=c;
	}
	password[i]='\0';
	if(strcmp(user,"rajesh")==0 && strcmp(password,"12345678")==0)
	{
	       //	while(1){
		printf("\n1. Technician Details");
		printf("\n2. Customer Details");
		printf("\n3. Back to Main Menu");
		printf("\n Enter A Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:tech_menu();break;
			case 2:cus_menu();break;
			case 3:break;
			default :printf("invaild value try aganin later!!");
		}
		//}
	}
	else
	{
		printf("\n                         invaild user and password try again later !!");
	}
}
