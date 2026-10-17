#include"login.c"
#include"checkpas.c"
void main_menu()
{
	int choice;
	clrscr();
	while(1){
	clrscr();
	heading();
	printf("1. Admin\n");
	printf("2. Customer\n");
	printf("3. Exit\n");
	printf("enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:admin();break;
		case 2:cus_data();break;
		case 3:exit(0);break;
		default:printf("You Are Wrong Choice Try Again !!");
	}
	}
	getch();
}