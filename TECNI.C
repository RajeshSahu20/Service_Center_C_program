//#include"main_menu.c"
struct service
{
    int id;
    char name[30];
    char type[30];
    char sp[30];

}tech;
struct complain
{
    int id;
    char name[30];
    char device[20];
    char issue[20];
    char add[50];
    char num[15];
    char status[20];
    int fees;
    char tech_name[40];
}cus;

void show_cus();
void add_tech();
void udt_cus();
void add_customer();
void sach_cus();
void udt_tech() ;
void show_tech();
void paysilp();
//tech  menu function
void tech_menu()
{
	int choice;
	clrscr();
	heading();
	printf("1. Add Technician\n");
	printf("2. Show All Tecnician\n");
	printf("3. Update Technician\n");
	printf("4.Back to Main Menu\n");
	printf("Enter A Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: add_tech();break;
		case 2: show_tech();break;
		case 3: udt_tech();break;
		case 4: break;
		default:printf("invaild value try again!!");
		getch();
	}
}
void cus_menu()
{
	int choice;
	clrscr();
	heading();
       // exit1();
       while(1){
	printf("1. Update Customer\n");
	printf("2. Show All Customer\n");
	printf("3. Search Customer\n");
	printf("4.Back to Main Menu\n");
	printf("Enter a Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: udt_cus();break;
		case 2: show_cus();break;
		case 3: sach_cus();break;
		case 4: exit(0);break;
	}
	}
}

 //"1. Add Technician\n"
void add_tech()
{
    FILE *fp;
    int id=1;
    char ch;
    char more[3];
    fp=fopen("service.txt","r");
    while(1)
    {
	ch = fgetc(fp);
	if(ch=='\n')
	{
		id++;
	}
	else if(ch==EOF)
	{
		break;
	}
    }
    fclose(fp);

    fp= fopen("service.txt","a");
    tech.id=id;
	printf("Enter A Technician Name:\n");
	scanf("%s",tech.name);
	printf("Enter A Technician Type:\n");
	scanf("%s",tech.type);
	printf("Enter A Technician Speciality:\n");
	scanf("%s",tech.sp);
	printf("Technician Detalies Added sussfully !! ");
	fprintf(fp,"%d  %s  %s  %s\n",tech.id,tech.name,tech.type,tech.sp);
    fclose(fp);
}
void cus_data()
{
    int cus_choi;
    clrscr();
    heading();

    printf("1. Add Customer Detalies\n");
    printf("2. Show Payment Slip\n");
    printf("3. Back To Menu\n");
    printf("Enter Your Choice : ");
    scanf("%d",&cus_choi);
    switch(cus_choi)
    {
      case 1:add_customer();break;
      case 2:paysilp();break;
      case 3: break;
    }
    /*if(cus_choi==1)
       add_customer();

    if(cus_choi==3)
    */


}
//add customer detailes
void add_customer()
{
    FILE *fp;
    int id=1;
    char ch;
    char neadd;
    fp=fopen("cus_comp.txt","r");
    while(1)
    {
	ch = fgetc(fp);
	if(ch=='\n')
	{
		id++;
	}
	else if(ch==EOF)
	{
		break;
	}
    }
    fclose(fp);

    fp= fopen("cus_comp.txt","a");
    cus.id=id;
    fflush(stdin);
    printf("Enter customer Name: ");
    scanf("%s",cus.name);
	fflush(stdin);
    printf("Enter device: ");
    scanf("%s",cus.device);
	fflush(stdin);
    printf("Enter customer issue: ");
    scanf("%s",cus.issue);
	fflush(stdin);
    printf("Enter customer address: ");
    scanf("%s",cus.add);
	fflush(stdin);
    while(1)
    {
	printf("Enter customer contact number: ");
	scanf("%s",cus.num);
	if(strlen(cus.num)==10)
	{
		break;
	}
	else
	{
		printf("\n\tInvalide Phone no..!!! Please Enter Only 10 Digit Phone no..!!!\n");
	}
    }
	fflush(stdin);
    strcpy(cus.status,"Panding");
	fflush(stdin);
    strcpy(cus.tech_name,"none");
    fflush(stdin);
    cus.fees=0;
    printf("\nyour detailes sucessfull added\n\n");
    fprintf(fp,"%d %s  %s  %s  %s  %s  %s  %s  %d\n",cus.id,cus.name,cus.device,cus.issue,cus.add,cus.num,cus.status,cus.tech_name,cus.fees);
    fclose(fp);
}
//update customer
void udt_cus()
{
    FILE *fptr;
    FILE *fptr1;
    int id2;
    int tech_found=0;
    int lbl;
    FILE *fp = fopen("cus_comp.txt", "r");
    FILE *temp = fopen("temp.txt","w");
    int id, found = 0;


    printf("Enter Customer ID to update: ");
    scanf("%d",&id);

    printf("\n\t\tShow Technician Details");
    printf("\n\t----------------------------------------------------------");
    printf("\n| %-5s | %-10s | %-10s | %-20s |\n", "ID", "Name", "Type", "Specility");



   while (fscanf(fp,"%d%s%s%s%s%s%s%s%d\n", &cus.id,cus.name,cus.device,cus.issue,cus.add,cus.num,cus.status,cus.tech_name,&cus.fees)!= EOF)
   {

	if (cus.id == id)
	{
		fptr = fopen("service.txt","r");
		while(fscanf(fptr,"%d%s%s%s\n",&tech.id,tech.name,tech.type,tech.sp)!=EOF)
		{
			printf("%d  %s  %s  %s\n",tech.id,tech.name,tech.type,tech.sp);
		}
		fclose(fptr);
		fptr1 = fopen("service.txt","r");
			lbl:
			printf("\n\tEnter tech id for Assign Technician");
			scanf("%d",&id2);
		while(fscanf(fptr,"%d%s%s%s\n",&tech.id,tech.name,tech.type,tech.sp)!=EOF)
		{
			//printf("%d  %s  %s  %s\n",tech.id,tech.name,tech.type,tech.sp);

			if(tech.id==id2)
			{
				fflush(stdin);
				strcpy(cus.tech_name,tech.name);
				fflush(stdin);
				tech_found=1;
				break;
			}
		}
		if(tech_found==0)
		{
			printf("\n\t\tTechnician Id is Not Found...!!!!\n");
			goto lbl;
		}
		fclose(fptr1);
	    fflush(stdin);
	    printf("\n\tEnter a Status: ");
	    scanf("%s",cus.status);
	    fflush(stdin);
	    printf("\n\tEnter a Resolving Fees : ");
	    scanf("%d",&cus.fees);
	    found = 1;
	    //break;
	}

    fprintf(temp,"%d %s  %s  %s  %s  %s  %s  %s  %d\n",cus.id,cus.name,cus.device,cus.issue,cus.add,cus.num,cus.status,cus.tech_name,cus.fees);
    }

    fclose(fp);
    fclose(temp);

    if (found)
    {
	printf("Customer updated successfully.\n");
	remove("cus_comp.txt");
	rename("temp.txt", "cus_comp.txt");
	remove("temp.txt");
    }
    else
	printf("Customer not found.\n");

}
/*show all tecnician*/
void show_tech()
{
       FILE *fp;
       clrscr();
       heading();
	printf("\n| %-5s | %-10s | %-10s | %-20s |\n", "ID", "Name", "Type", "Specility");
	fp= fopen("service.txt", "r");
	while (fscanf(fp,"%d %s %s %s\n",&tech.id,tech.name,tech.type,tech.sp)!=EOF)
	 {
		printf("| %-5d | %-10s | %-10s | %-20s |\n",tech.id,tech.name,tech.type,tech.sp);
	 }
	 close(fp);
    getch();
}

/*teniction update function    */
void udt_tech()
{
    FILE *fp = fopen("service.txt","r");
    FILE *temp = fopen("temp.txt", "w");
    int id, found = 0;

    printf("Enter Technician ID To Update: ");
    scanf("%d", &id);


    while (fscanf(fp,"%d%s%s%s",&tech.id,tech.name,tech.type,tech.sp)!= EOF)
   {

	if (tech.id == id)
	{
	    printf("Enter a Name: ");
	    scanf("%s",tech.name);
	    printf("Enter a Type: ");
	    scanf("%s",tech.type);
	    printf("Enter a Speciality: ");
	    scanf("%s",tech.sp);
	    found = 1;
	    //break;
	}
       fprintf(temp,"%d %s  %s  %s \n",tech.id,tech.name,tech.type,tech.sp);
    }


    fclose(fp);
    fclose(temp);


    if (found)
    {
	printf("Tecnician Deatlies updated successfully.\n");
	remove("service.txt");
	rename("temp.txt", "service.txt");
	remove("temp.txt");
    }
    else
	printf("Tecnician not found.\n");

}
/* view history   */
void show_cus()
{
    FILE *fp;
    int ch,lbl;
     clrscr();
     heading();
     lbl:
     printf("\n\t\t1. Show All Deatils ");
     printf("\n\t\t2. Show Panding Deatils ");
     printf("\n\t\t3. Show Resolved Deatils ");
     printf("\n\t\t4. Exit ");
     printf("\n\t\tEnter Your Choise : ");
     fflush(stdin) ;
     scanf("%d",&ch);
     printf("\n|%-5s|%-7s|%-7s|%-7s|%-7s|%-10s|%-8s|%-8s|%-5s|\n", "ID", "Name", "Device", "Issue","Add.","C.Num","Status","Tech.Name","Fees");
       fflush(stdin);
	//if(strcmp(cus.status,"Panding")==0)
	switch(ch)
	{
		case 1:
		 clrscr();
		 heading();
		 heading2();
		 fp= fopen("cus_comp.txt", "r");
		 while (fscanf(fp,"%d %s %s %s %s %s %s %s %d\n",&cus.id,cus.name,cus.device,cus.issue,cus.add,cus.num,cus.status,cus.tech_name,&cus.fees)!=EOF)
		 {
			printf("\t|%-5d|%-7s|%-7s|%-7s|%-7s|%-10s|%-8s|%-8s|%-5d\n",cus.id, cus.name, cus.device, cus.issue, cus.add, cus.num,cus.status,cus.tech_name,cus.fees);
		 }
		 fclose(fp);
		 goto lbl;
		break;

		case 2:
		clrscr();
		heading();
		heading2();
		 fp= fopen("cus_comp.txt","r");
		 while (fscanf(fp,"\t%d %s %s %s %s %s %s %s %d\n",&cus.id,cus.name,cus.device,cus.issue,cus.add,cus.num,cus.status,cus.tech_name,&cus.fees)!=EOF)
		 {
			if(strcmp(cus.status,"Panding")==0)
			{
			  // printf("%-5d %-7s %-7s %-7s %-7s %-10s %-8s %-8s %-5d\n",cus.id, cus.name, cus.device, cus.issue, cus.add, cus.num,cus.status,cus.tech_name,cus.fees);
			  printf("\t|%-5d|%-7s|%-7s|%-7s|%-7s|%-10s|%-8s|%-8s|%-5d\n",cus.id, cus.name, cus.device, cus.issue, cus.add, cus.num,cus.status,cus.tech_name,cus.fees);

			}
		 }
		 fclose(fp);
		 goto lbl;
		break;

		case 3:
		clrscr();
		heading();
		heading2();
		 fp= fopen("cus_comp.txt", "r");
		 while (fscanf(fp,"\t%d %s %s %s %s %s %s %s %d\n",&cus.id,cus.name,cus.device,cus.issue,cus.add,cus.num,cus.status,cus.tech_name,&cus.fees)!=EOF)
		 {
			if(strcmp(cus.status,"Resolved")==0)
			{
			  // printf("%-5d %-7s %-7s %-7s %-7s %-10s %-8s %-8s %-5d\n",cus.id, cus.name, cus.device, cus.issue, cus.add, cus.num,cus.status,cus.tech_name,cus.fees);
			  printf("\t|%-5d|%-7s|%-7s|%-7s|%-7s|%-10s|%-8s|%-8s|%-5d\n",cus.id, cus.name, cus.device, cus.issue, cus.add, cus.num,cus.status,cus.tech_name,cus.fees);

			}
		 }
		 fclose(fp);
		 goto lbl;
		break;

		case 4:
		exit(0);
		break;
	}
	 //delay(4000);
    getch();
}
/*search customer */
void sach_cus()
{
    FILE *fp = fopen("cus_comp.txt", "r");
    int id, found = 0;

    printf("Enter customer ID to search: ");
    scanf("%d", &id);
    printf("\n%-5s %-7s %-7s %-7s %-7s %-10s %-8s %-8s %-5s\n", "ID", "Name", "Device", "Issue","Add.","C.Num","Status","Tech.Name","Fees");
    while (fscanf(fp,"%d %s %s %s %s %s %s %s %d\n",&cus.id, cus.name, cus.device, cus.issue, cus.add, cus.num,cus.status,cus.tech_name,&cus.fees)!=EOF)
   {
	if (cus.id == id)
	{
	   // printf("\n%-5d %-7s %-7s %-7s %-7s %-10s %-8s %-8s %-5d\n",cus.id, cus.name, cus.device, cus.issue, cus.add, cus.num,cus.status,cus.tech_name,cus.fees);
	   printf("\t|%-5d|%-7s|%-7s|%-7s|%-7s|%-10s|%-8s|%-8s|%-5d\n",cus.id, cus.name, cus.device, cus.issue, cus.add, cus.num,cus.status,cus.tech_name,cus.fees);

	    found = 1;
	    break;
	}
    }

    if (found==0)
    {
	printf("customer detailes not found !!.\n");
	//exit(0);
    }

    fclose(fp);
}
void paysilp()
{
	FILE *fp;
	int id,found=0;
		clrscr();
		  printf("\n\tEnter customer ID to Show Payment Slip : ");
		  scanf("%d", &id);
		fp = fopen("cus_comp.txt","r");
		while(fscanf(fp,"%d %s %s %s %s %s %s %s %d\n",&cus.id, cus.name, cus.device, cus.issue, cus.add, cus.num,cus.status,cus.tech_name,&cus.fees)!=EOF)
	     {
			if (cus.id == id)
			{
	     printf("\n\n\n\n\n\n\n");
	       printf("                   **************************************\n");
	       printf("                  (<------------SERVICE CENTER---------->)\n");
	       printf("                   **************************************\n");
	       printf("                   |-------------PAYMENT SILIP-----------|\n");
	       printf("                   |        ID       : %-2d            |\n",cus.id);
	       printf(" 	           |       Customer Name     : %-15s        |\n",cus.name);
	       printf("                   |        Device   : %-15s        |\n",cus.device);
	       printf("                   |        Address.     : %-15s        |\n",cus.add);
	       printf("                   |        Phone no. : %-15s       |\n",cus.num);
	       printf("                   |        Tecnician Name: %-15s        |\n",cus.tech_name);
	       printf("                   |-------------------------------------|\n");
	       printf("                   |        TOTAL PAYMENT:%-15d               |\n",cus.fees);
	       printf("                   ---------------------------------------");
	       found=1;
	       break;
	       }
	     }
	      if (found==0)
	      {
		printf("customer detailes not found !!.\n");
	//exit(0);
	      }

   fclose(fp);
   getch();
}

