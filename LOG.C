





#include"work.c"
void heading()
{
	printf("                !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("                *                                                 *\n");
	printf("                *         SERVICE CENTER MANAGEMENT SYSTEMS       *\n");
	printf("                *                                                 *\n");
	printf("                !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
	getch();
}
void main_Menu()
{
	int choice;
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
		case 2://customercomplian();
		break;
		case 3:exit(0);break;
		default:printf("You Are Wrong Choice Try Again !!");
	}
}