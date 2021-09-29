//program for Movie Ticketing management//
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>//For taking real time Time from System
#include<graphics.h>
void passwordcheck();
void maincontrolmenu();
int menu();
void addmovieentry();
void movielistread();
void editmovieentry();
void deleterecord();
void passwordchange();
void programexit();
void moviechoose();
void timechoose();
void seatchoose1();
void totalmovieoutput();
void ticketsold();
void editseatrecord();
void seatgraphicsprint();
void reservedseat();
struct ticket
{
	char name[20],st[20],seat;
	int id,cp;
}s[20],m;
FILE  *fuser,*fpass,*fmovie1,*fmovie2,*seat1,*seat2;
int p=0,p1=0,choose,movieno,timeno,screenno;
int seat[10][10]={{0}},seatno[64]={0},movieid,numberseats;
void main()
{       static int b=6;       //for the password count
	  maina:  //to move program condition to here
	passwordcheck();
	clrscr();
	if(p==0&p1==0)   //Sales personell Part
	{
		 maincontrolmenu();
	}
     else     //security measure for wrong username or password
     {  clrscr();
	b--;
	for(p=0;p<3;p++)
		printf("\n\n\t\tEnter Valid Username or Password");
		printf("\n\n\t\t %d Chances Left ",b-1);
		getch();
		if(b==1)
			goto endof;
		else
			goto maina;
     }
     programexit();
     getch();
     endof:
}
void passwordcheck()    //Function for checking Password and User Name
{       clrscr();
	char pass1[30],user1[30],pass[30],user[30],c;
	fpass=fopen("Password.txt","r");    //opening password file
	fuser=fopen("user.txt","r");      //opening username file
	while((fscanf(fpass,"%s",&pass))!=EOF);  //taking the password from file
	while((fscanf(fuser,"%s",&user))!=EOF);  //taking the username from file
	fclose(fpass);
	fclose(fuser);
	printf("\n\n\n\t\tUsername: ");
	gets(user1);		       //taking username from user
	printf("\t\tPassword: ");
     //	gets(pass1);

	int index = 0;
	while((c = getch()) != 13)
	{
		if(index < 0)
		index = 0;
		if(c == 8){
			putch('\b');
			putch(NULL);
			putch('\b');
			index--;
			continue;
		}
		pass1[index++] = c;
		putch('*');
	}
	pass1[index] = '\0';     // */
   //taking password from user
	p1=strcmp(user1,user);     //comparing users given username and file username
	p=strcmp(pass1,pass);      //comparing users given password and file password
}
void maincontrolmenu()
{
	mainmenu:
	int a;
	while(a!=4)
	{
		     a=menu(); //switching to main menu box
		     if(a==1)
		     {  switch(choose)
			{
			case 1:
				addmovieentry();
				break;
			case 2:
				movielistread();
				break;
			case 3:
				editmovieentry();
				break;
			case 4:
				deleterecord();
				break;
			case 5:
				passwordchange();
				break;
			case 6:
				goto mainmenu;
				break;
			default:
				printf("Enter valid Number ");
				printf("\n\n\n\t\t\tEnter Valid Decision Only");
			}
		     }
		     else if(a==2)
		     {
			switch(choose)
			{
			case 1:
				int i;
				moviechoose();
				timechoose();
				seatchoose1();
				if(movieno==1)
				{
					seat1=fopen("seatm1.txt","a");
					for(i=1;i<=numberseats;i++)
					fprintf(seat1,"%d\t",seatno[i]);
					fclose(seat1);
				}
				else if(movieno==2)
				{
					seat1=fopen("seatm2.txt","a");
					for(i=1;i<=numberseats;i++)
					fprintf(seat1,"%d\t",seatno[i]);
					fclose(seat1);
				}
				else if(movieno==3)
				{
					seat1=fopen("seatm3.txt","a");
					for(i=1;i<=numberseats;i++)
					fprintf(seat1,"%d\t",seatno[i]);
					fclose(seat1);
				}
				else if(movieno==4)
				{
					seat1=fopen("seatm4.txt","a");
					for(i=1;i<=numberseats;i++)
					fprintf(seat1,"%d\t",seatno[i]);
					fclose(seat1);
				}
				else if(movieno==5)
				{
					seat1=fopen("seatm5.txt","a");
					for(i=1;i<=numberseats;i++)
					fprintf(seat1,"%d\t",seatno[i]);
					fclose(seat1);
				}
				else if(movieno==6)
				{
					seat1=fopen("seatm6.txt","a");
					for(i=1;i<=numberseats;i++)
					fprintf(seat1,"%d\t",seatno[i]);
					fclose(seat1);
				}
				else if(movieno==7)
				{
					seat1=fopen("seatm7.txt","a");
					for(i=1;i<=numberseats;i++)
					fprintf(seat1,"%d\t",seatno[i]);
					fclose(seat1);
				}
				else
				{
					printf("\n No Seats Found Please Choose Another Time or Movie");
					getch();
					goto mainmenu;
				 }
				 clrscr();
				 closegraph();
				totalmovieoutput();
				break;
			case 2:
				ticketsold();
				break;
			case 3:
				editseatrecord();
				break;
			case 4:
				goto mainmenu;
				break;
			default:
				clrscr();
				printf("\n\n\n\t\t\tEnter Valid Decision Only");
			}
		     }
		     else;
	}
}
int menu()     //main menu function
{      	 mainmenu:
	 char date[50],time[50];
	 int a,i=0;
	clrscr();
	fmovie1=fopen("movie.txt","r");//for reading all data from FILE
	while(fscanf(fmovie1,"%d\t\t%s\t\t\t%s\n",&s[i].id,&s[i].name,&s[i].st)!=EOF)
	{
		movieid=s[i].id;
		i++;
	}
	fclose(fmovie1);
	int gd=DETECT,gm,bkcolor;
   //	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	rectangle(40,50,350,155);
	printf("\n\n\n\n\t**********//Welcome//*************");
	printf("\n\tChoose Options");
	printf("\n\t 1. Admin Menu");
	printf("\n\t 2. Ticket Counter Menu");
	printf("\n\t 3. Program Exit\n");
	printf("\n\t");
	scanf("%d",&a);
	closegraph();
	if(a==1)
	{
	   clrscr();
	   int gd=DETECT,gm,bkcolor;
   //	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	rectangle(20,50,380,195);
	   printf("\n\n\n\n\t**********//Admin Menu//*************");
	   printf("\n\t1. New Movies Entries");
	   printf("\n\t2. View Movies Entries");
	   printf("\n\t3. Edit Movies Entries");
	   printf("\n\t4. Delete Movies Entries");
	   printf("\n\t5. Password Change");
	   printf("\n\t6. Exit to main menu");
	   printf("\n\tEnter choice:\n");
	}
	else if(a==2)
	{   	clrscr();
		int gd=DETECT,gm,bkcolor;
	  //	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		rectangle(20,50,400,165);
		printf("\n\n\n\n\t**********//Ticket Counter//*************");
		printf("\n\t1. Choose Movies to Buy Tickets");
		printf("\n\t2. Sold Tickets");
		printf("\n\t3. Cancel Sold Tickets/Seats");
		printf("\n\t4. Exit to main menu");
		printf("\n\tEnter choice:\n");
	}
	else if(a==3)
	{
		programexit();
	}
	else
	{
		clrscr();
		printf("\n\n\n\n\tCHOOSE CORRECT OPTIONS ONLY");
		getch();
		goto mainmenu;
	}
	printf("\n\t");
	scanf("%d",&choose);
	closegraph();
	return(a);
}
void addmovieentry()        //add movierecord function
{
	clrscr();
	int i;
	char choose='y';
	i=movieid+1;
	fmovie1=fopen("movie.txt","a");
	while(choose!='n')
	   {    clrscr();
		printf("\n\t\tEnter Movie Name: ");
		scanf("%s",&m.name);
		printf("\n\t\tEnter Movie Show Times: ");
		printf("\n\t\tFormat(10:45 AM):  ");
		scanf("%s",&m.st);
		fprintf(fmovie1,"%d\t\t%s\t\t\t%s\n",i,m.name,m.st);
		printf("\n\tdo you want to add more book data's(y-yes/n-no): ");
		choose=getche();
		movieid=movieid+1;
		i++;
	   }
	fclose(fmovie1);
	getch();
}
void movielistread()  //record read function
{       int i;
	clrscr();
	fmovie1=fopen("Movie.txt","r");
	printf("\n\n Movies Details from the file\n");
	printf("Movie Id\tMovie Name\t\tShow Times\n");
       for(i=0;i<=100;i++)
       {   while(fscanf(fmovie1,"%d\t\t%s\t\t%s\n",&s[i].id,&s[i].name,&s[i].st)!=EOF)
	   {    printf("%d\t\t%s\t\t\t%s\n",s[i].id,s[i].name,s[i].st);
	   }
       }
       getch();
       fclose(fmovie1);
}

void editmovieentry()        //edit movierecord function
{
     int key,i,j,flag=0;
	clrscr();
	fmovie1=fopen("movie.txt","r");
	printf("\n\n\n\t\tEnter Movie id to Edit movie record: ");
	scanf("%d",&key);
	while(fscanf(fmovie1,"%d\t\t%s\t\t\t%s\n",&s[i].id,&s[i].name,&s[i].st)!=EOF)
	    {
		if(key==s[i].id)
		{
			flag=1;
			break;
		}
		i++;
	    }
       fclose(fmovie1);
	if(flag==0)
	{          clrscr();
		printf("\n\n\n\t\t\t\tThe Movie is unavailable");
	       printf("\n \t\t\tPlease enter valid Movie ID no");
		getch();
	}
    else
      { i=1;
	fmovie1=fopen("movie.txt","r");
	fmovie2=fopen("temp.txt","w");
	while(fscanf(fmovie1,"%d\t\t%s\t\t\t%s\n",&s[i].id,&s[i].name,&s[i].st)!=EOF)
	{
		     if(key==s[i].id)
		     {
			clrscr();
			printf("\n\t\tEnter Movie Name: ");
			scanf("%s",&s[i].name);
			printf("\n\t\tEnter Movie Show Times: ");
			printf("\n\t\tFormat(10:45 AM):  ");
			scanf("%s",&s[i].st);
			fprintf(fmovie2,"%d\t\t%s\t\t\t%s\n",i,s[i].name,s[i].st);
		      }
		     else
		     {
			fprintf(fmovie2,"%d\t\t%s\t\t\t%s\n",i,s[i].name,s[i].st);
		     }
		     i++;
	}
	printf("\n\n\n\t\t\tONE Record Edited");
	fclose(fmovie1);
	fclose(fmovie2);
	remove("movie.txt");
	rename("temp.txt","movie.txt");
	getch();
      }
}
void deleterecord()     //record delete function
{       int key,i,j,flag=0;
	clrscr();
	fmovie1=fopen("movie.txt","r");
	printf("\n\n\n\t\tEnter Movie id to delete movie record: ");
	scanf("%d",&key);
	while(fscanf(fmovie1,"%d\t\t%s\t\t\t%s\n",&s[i].id,&s[i].name,&s[i].st)!=EOF)
	    {
		if(key==s[i].id)
		{
			flag=1;
			break;
		}
		i++;
	    }
       fclose(fmovie1);
	if(flag==0)
	{          clrscr();
		printf("\n\n\n\t\t\t\tThe Movie is unavailable");
	       printf("\n \t\t\tPlease enter valid Movie ID no");
		getch();
	}
    else
      { i=1;
	fmovie1=fopen("movie.txt","r");
	fmovie2=fopen("temp.txt","w");
	while(fscanf(fmovie1,"%d\t\t%s\t\t\t%s\n",&s[i].id,&s[i].name,&s[i].st)!=EOF)
	{
		     if(key==s[i].id)
			continue;
		     else
		     {
			fprintf(fmovie2,"%d\t\t%s\t\t\t%s\n",i,s[i].name,s[i].st);
			i++;
		     }
	}
	printf("\n\n\n\t\t\tONE RECORD DELETED");
	printf("\n\t\t\tSEATS RECORD ALSO DELETED");
	fclose(fmovie1);
	fclose(fmovie2);
	remove("movie.txt");
	rename("temp.txt","movie.txt");
	if(key==1)
	{
		remove("seatm1.txt");       //removing seat of movie 1 since its data is deleted
		rename("seatm2.txt","seatm1.txt");     //renaming movie 2 seat data to 1 and so on
		rename("seatm3.txt","seatm2.txt");
		rename("seatm4.txt","seatm3.txt");
		rename("seatm5.txt","seatm4.txt");
		rename("seatm6.txt","seatm5.txt");
		rename("seatm7.txt","seatm6.txt");
		seat1=fopen("seatm7.txt","w");
		fclose(seat1);
	}
	else if(key==2)
	{
		remove("seatm2.txt");       //removing seat of movie 2 since its data is deleted
		rename("seatm3.txt","seatm2.txt");     //renaming movie 3 seat data to 2 and so on
		rename("seatm4.txt","seatm3.txt");
		rename("seatm5.txt","seatm4.txt");
		rename("seatm6.txt","seatm5.txt");
		rename("seatm7.txt","seatm6.txt");
		seat1=fopen("seatm7.txt","w");
		fclose(seat1);
	}
	else if(key==3)
	{
		remove("seatm3.txt");       //removing seat of movie 3 since its data is deleted
		rename("seatm4.txt","seatm3.txt");    //renaming movie 4 seat data to 3 and so on
		rename("seatm5.txt","seatm4.txt");
		rename("seatm6.txt","seatm5.txt");
		rename("seatm7.txt","seatm6.txt");
		seat1=fopen("seatm7.txt","w");
		fclose(seat1);
	}
	else if(key==4)
	{
		remove("seatm4.txt");       //removing seat of movie 4 since its data is deleted
		rename("seatm5.txt","seatm4.txt");     //renaming movie 5 seat data to 4 and so on
		rename("seatm6.txt","seatm5.txt");
		rename("seatm7.txt","seatm6.txt");
		seat1=fopen("seatm7.txt","w");
		fclose(seat1);
		seat1=fopen("seatm5.txt","w");
		fclose(seat1);
	}

	else if(key==5)
	{
		remove("seatm5.txt");       //removing seat of movie 5 since its data is deleted
		rename("seatm6.txt","seatm5.txt");
		rename("seatm7.txt","seatm6.txt");
		seat1=fopen("seatm7.txt","w");
		fclose(seat1);
	}
	else if(key==6)
	{
		remove("seatm6.txt");       //removing seat of movie 6 since its data is deleted
		rename("seatm7.txt","seatm6.txt");
		seat1=fopen("seatm7.txt","w");
		fclose(seat1);
	}
	else if(key==7)
	{
		remove("seatm7.txt");       //removing seat of movie 7 since its data is deleted
		seat1=fopen("seatm7.txt","w");
		fclose(seat1);
	}
	else;
	getch();
      }
}
void passwordchange()  //password change function
{       int c;
	passwordc:
	clrscr();
	char pas[100],pas1[100];
	fpass=fopen("Password.txt","w");
	printf("\n\n\n\t\t\tEnter New Password: ");
	scanf("%s",pas);
	printf("\n\t\t\tEnter new password again to confirm: ");
	scanf("%s",pas1);
	c=strcmp(pas1,pas);
	if(c==0)
	{       fprintf(fpass,"%s",pas1);
		clrscr();
		printf("\n\n\t\t\tSucess Password Changed");
	}
	else
	{	clrscr();
		printf("\n\n\n\n\t\t\tPassword Change Error Occured\n");
		printf("\n\t\t\tEnter Same Password ");
		printf("\n\t\t\tEnter Same Password ");
		printf("\n\t\t\tEnter Same Password");
		printf("\n\n\t\t\tPress any key to change password Again");
		getch();
	       goto passwordc;

	}
	fclose(fpass);
	getch();
}
void moviechoose()  //this is movie menu
{       moviechoose1:
	int i=1,a;
	clrscr();
	fmovie1=fopen("movie.txt","r");
	printf("\n\n\n\n\t**********//Available Movies //*************");
	while(fscanf(fmovie1,"%d\t\t%s\t\t\t%s\n",&s[i].id,&s[i].name,&s[i].st)!=EOF)
	{
	      printf("\n\t%d\t\t%s",i,s[i].name);
		i++;
	}
	fclose(fmovie1);
	printf("\n\t%d\tExit to main menu",i);
	printf("\n\tselect your choice\n");
	scanf("%d",&movieno);
	if(movieno>=1&movieno<=movieid)
	{

	}
	else if(movieno==i)
	{
		 maincontrolmenu();
	}
	else
	{
		printf("Enter Correct Choice Only");
		getch();
		goto moviechoose1;
	}
}
void timechoose()
{
	timechoose1:
	clrscr();
	int i=1,j=1,a;
	fmovie1=fopen("movie.txt","r");
	while(fscanf(fmovie1,"%d\t\t%s\t\t\t%s\n",&m.id,&m.name,&m.st)!=EOF)
	{
		if(movieno==m.id)
		{
			printf("\n\n\n\n\t**********//Available Time when %s is shown//*************",m.name);
			for(i=1;i<=movieid;i++)
			{
				a=strcmp(s[i].name,m.name);
				if(a==0)
				{
					printf("\n\t%d.\t%s",j,s[i].st);
					j++;
				}
			}
		}
	}
	printf("\n\t%d.\tExit to main menu",j);
	printf("\n\tselect your choice\n");
	scanf("%d",&timeno);
	fclose(fmovie1);
	if(timeno>=1&timeno<j)
	{

	}
	else if(timeno==j)
	{
		 maincontrolmenu();
	}
	else
	{
		clrscr();
		printf("\n\n\n\t\t\t\tThe Movie Time is unavailable");
		printf("\n \t\t\tPlease Select valid Movie Time");
		getch();
		goto timechoose1;
	}
}
void totalmovieoutput()  //This is Output Function It prints the total reasult of the Users Choice on Movies
{       closegraph();
	clrscr();
	int i=0,price=270,ticketsoldnumber=1,page=0;
	char date[20],time[20];
	FILE *fmovie3;      //new file declaration
	fmovie1=fopen("movie.txt","r");
	fmovie2=fopen("Tickets.txt","a");
	fmovie3=fopen("Tickets.txt","r");
	while(fscanf(fmovie3,"%d\t\t%s\t\t%s\t\t%d\t\t%d\t\t%s\t\t%s\n",&ticketsoldnumber,&m.name,&m.st,seatno[i],&price,&date,&time)!=EOF)
	{
		ticketsoldnumber++;
	}       /*This While Statement is only to count
	the total number of sales done in a day to add
	the new serial number to File*/
	fclose(fmovie3);
	int gd=DETECT,gm,bkcolor,a=0;
    //	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	char seata[10];
	while(fscanf(fmovie1,"%d\t\t%s\t\t\t%s\n",&m.id,&m.name,&m.st)!=EOF)
	{
		if(movieno==m.id)
		{
			for(i=1;i<=numberseats;i++)
			{
				_strdate(date);
				_strtime(time);
				rectangle(40,30+a,400,180+a);
				outtextxy(165,55+a,"QFX Movies ");
				outtextxy(55,70+a,m.name);
				outtextxy(55,90+a,"SCREEN");
				outtextxy(55,100+a,"A-1");
				outtextxy(55,120+a,"Price");
				outtextxy(110,120+a,"Date");
				outtextxy(185,120+a,"Programme_Time");
				outtextxy(315,120+a,"Seat No");
				outtextxy(70,150+a,"Ticket Printed Time:");

			outtextxy(55,130+a,"270");
			outtextxy(110,130+a,date);
			outtextxy(210,130+a,m.st);
			sprintf(seata,"%d",seatno[i]);
			outtextxy(320,130+a,seata);
			outtextxy(250,150+a,time);

				fprintf(fmovie2,"%d\t\t%s\t\t%s\t\t%d\t\t%d\t\t%s\t\t%s\n",ticketsoldnumber,m.name,m.st,seatno[i],price,date,time);
				ticketsoldnumber++;
				a=a+160;
				page=page+1;
				if(page==2)
				{
					outtextxy(50,30+a,"Press Enter To see Next Page");
					getch();
					page=0;
					a=0;
					closegraph();
					initgraph(&gd,&gm,"C:\\TC\\BGI");
				}
			}
		}
	}
	fclose(fmovie1);
	fclose(fmovie2);
	getch();
	closegraph();
}
void ticketsold()     //Function to Show the tickets Sold In the Cinema Hall
{       totaldata:
	clrscr();
	int price,ticketsoldnumber=1,i=1,flag=0,v,ta,page=0;
	char tempname[20];
	char date[20],time[20];
	int gd=DETECT,gm,bkcolor;
   //	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	rectangle(40,50,350,155);
	printf("\n\n\n\n\t**********//Welcome//*************");
	printf("\n\tChoose Options");
	printf("\n\t 1. View Whole Record");
	printf("\n\t 2. View Record By Name");
	printf("\n\t 3. Exit to Main Menu\n");
	printf("\n\t");
	scanf("%d",&ta);
	closegraph();
   if(ta==1)
   {
	fmovie2=fopen("Tickets.txt","r");
	printf("Ti/N   Movie Name\tShowTi\tSeatNo\tPrice\tTime\t\tDate\n");
	while(fscanf(fmovie2,"%d\t\t%s\t\t%s\t\t%d\t\t%d\t\t%s\t\t%s\n",&ticketsoldnumber,&m.name,&m.st,&seatno[i],&price,&date,&time)!=EOF)
	{
		printf("%d\t%s\t%s\t%d \t%d\t%s\t%s\n",ticketsoldnumber,m.name,m.st,seatno[i],price,date,time);
		i++;
		page=page+1;
		if(page==20)
		{
			printf("\n\nPress Enter To see Next Page");
			getch();
			page=0;
			clrscr();
			printf("Ti/N   Movie Name\tShowTi\tSeatNo\tPrice\tTime\t\tDate\n");
		}
	}
	getch();
	fclose(fmovie2);
   }
   else if(ta==2)
   {    clrscr();
	fmovie1=fopen("Movie.txt","r");
	printf("\n\nMovie Id\tMovie Name\t\tShow Times\n");
	while(fscanf(fmovie1,"%d\t\t%s\t\t%s\n",&s[i].id,&s[i].name,&s[i].st)!=EOF)
	   {
		printf("%d\t\t%s\t\t\t%s\n",s[i].id,s[i].name,s[i].st);
		i++;
	   }
       fclose(fmovie1);
       printf("\n\n Movies Details from the file\n");
	printf("\nEnter Movie Name to view movie record: ");
	scanf("%s",&tempname);
	fmovie2=fopen("Tickets.txt","r");
	i=1;
	while(fscanf(fmovie2,"%d\t\t%s\t\t%s\t\t%d\t\t%d\t\t%s\t\t%s\n",&ticketsoldnumber,&m.name,&m.st,&seatno[i],&price,&date,&time)!=EOF)
	{
		     v=strcmp(tempname,m.name);
		     i++;
		     if(v==0)
		     {
			flag=1;
		     }
	}
	fclose(fmovie2);
	if(flag==0)
	{          clrscr();
		printf("\n\n\n\t\t\tThe Movie Searched is unavailable");
	       printf("\n\t\t\tPlease enter valid Movie Name no\n");
		getch();
		goto totaldata;
	}
	else
	{
		clrscr();
		page=0;
		fmovie2=fopen("Tickets.txt","r");
		printf("Ti/N   Movie Name\tShowTi\tSeatNo\tPrice\tTime\t\tDate\n");
		while(fscanf(fmovie2,"%d\t\t%s\t\t%s\t\t%d\t\t%d\t\t%s\t\t%s\n",&ticketsoldnumber,&m.name,&m.st,&seatno[i],&price,&date,&time)!=EOF)
		{
		     v=strcmp(tempname,m.name);
		     if(v==0)
		     {
			printf("%d\t%s\t%s\t%d \t%d\t%s\t%s\n",ticketsoldnumber,m.name,m.st,seatno[i],price,date,time);
			page=page+1;
			if(page==20)
			{
				printf("\n\nPress Enter To see Next Page");
				getch();
				page=0;
				clrscr();
				printf("Ti/N   Movie Name\tShowTi\tSeatNo\tPrice\tTime\t\tDate\n");
			}
		     }
		     i++;
		}
		fclose(fmovie2);
		getch();
	}
   }
   else if(ta==3)
   {
	 maincontrolmenu();
   }
   else
   {    printf("\n\n\t\t\tPlease enter valid  no");
	getch();
	goto totaldata;
   }
}
void editseatrecord()        //edit movie seat record function
{
	int key,i=0,j,flag=0,s1;
	char moviename[20],movietime[20];
	clrscr();
	fmovie1=fopen("Movie.txt","r");
	printf("\n\nMovie Id\tMovie Name\t\tShow Times\n");
       while(fscanf(fmovie1,"%d\t\t%s\t\t%s\n",&s[i].id,&s[i].name,&s[i].st)!=EOF)
	   {    printf("%d\t\t%s\t\t\t%s\n",s[i].id,s[i].name,s[i].st);
		i++;
	   }
       fclose(fmovie1);
       printf("\n\n Movies Details from the file\n");
	printf("\nEnter Movie id to Edit Seat record from above records: ");
	scanf("%d",&key);
	for(i=0;i<=100;i++)
	{
		if(key==s[i].id)
		{
			strcpy(moviename,s[i].name);
			strcpy(movietime,s[i].st);
			flag=1;
			break;
		}
	}
       if(flag==0)
	{          clrscr();
			printf("\n\n\n\t\tThe Movie is unavailable");
		 printf("\n\t\tPlease enter valid Movie ID no");
		getch();
		 maincontrolmenu();
	}
 else
 {      i=0,flag=0,j=0;
	if(key==1)
	{
		seat2=fopen("seatm1.txt","r");
	}
	else if(key==2)
	{
		seat2=fopen("seatm2.txt","r");
	}
	else if(key==3)
	{
		seat2=fopen("seatm3.txt","r");
	}
	else if(key==4)
	{
		seat2=fopen("seatm4.txt","r");
	}
	else if(key==5)
	{
		seat2=fopen("seatm5.txt","r");
	}
	else if(key==6)
	{
		seat2=fopen("seatm6.txt","r");
	}
	else if(key==7)
	{
		seat2=fopen("seatm7.txt","r");
	}
	else
	{
		printf("\n No Seats Found Please Choose Another Time or Movie");
		getch();
		maincontrolmenu();
	}
	seat1=fopen("temp.txt","w");
	clrscr();
	for(i=1;i<=10;i++)
	{
		for(j=0;j<=9;j++)
	      {
		   seat[i][j]=0;
	      }
	}
	i=1;
	j=0;
	while(fscanf(seat2,"%d\t",&seat[i][j])!=EOF)
	{
		j++;
		if(j==9)
		{
			i++;
			j=0;
		}
	}
	fclose(seat2);
	seeseats:
	clrscr();
	closegraph();
	//Graphics Function Start
	int gd=DETECT,gm;
	  //	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	outtextxy(200,70,moviename);
	printf("\n********//Available Seats For %s in %s Time//**********",moviename,movietime);
	seatgraphicsprint();   //Calling the function where all seats of hall are stored graphically
	reservedseat();
	outtextxy(20,450,"Press Enter To Continue");
	getch();
	closegraph();
	clrscr();
	printf("\n\n\tEnter 99 to view seats again");
	printf("\n\tEnter 100 to goto main menu");
	printf("\n\tEnter Seat Number To Edit/Remove Seat Booking: ");
	scanf("%d",&s1);
	if(s1==99)
		goto seeseats;
	if(s1==100)
		maincontrolmenu();
	clrscr();
	for(i=1;i<=10;i++)
	{
		for(j=0;j<=9;j++)
	      {

		if(s1==seat[i][j])
		{
			printf("\n\n\t\tOne Seat Record Deleted");
			 flag=1;
		}
		else if(seat[i][j]==0)
		{
		       continue;
		}
		else
		{
			fprintf(seat1,"%d\t",seat[i][j]);
		}
	      }
	}
	fclose(seat1);
	fclose(seat2);
	if(flag==0)
	{
		  clrscr();
		  printf("\n\n\n\t\tThe Seat Entered is unavailable");
		  printf("\n\t\tPlease enter valid Movie ID no");
		  getch();
		  goto seeseats;
	}
	if(key==1)
	{       remove("seatm1.txt");
		rename("temp.txt","seatm1.txt");
	}
	else if(key==2)
	{	remove("seatm2.txt");
		rename("temp.txt","seatm2.txt");
	}
	else if(key==3)
	{
		remove("seatm3.txt");
		rename("temp.txt","seatm3.txt");
	}
	else if(key==4)
	{       remove("seatm4.txt");
		rename("temp.txt","seatm4.txt");
	}
	else if(key==5)
	{       remove("seatm5.txt");
		rename("temp.txt","seatm5.txt");
	}
	else if(key==6)
	{       remove("seatm6.txt");
		rename("temp.txt","seatm6.txt");
	}
	else if(key==7)
	{       remove("seatm7.txt");
		rename("temp.txt","seatm7.txt");
	}
	else
	{
		printf("\n No Seats Found Please Choose Another Time or Movie");
		getch();
		maincontrolmenu();
	}
	getch();
 }
}


void programexit()             //Program Exit
{
		clrscr();
		int gd=DETECT,gm;
	  //	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		rectangle(20,50,400,165);
		rectangle(18,48,402,168);
		printf("\n\n\n\n\t\tThank you For Using Program\n\n");
		printf("\t\tProgram Made by:\n");
		printf("\t\tBiplap Bhattarai\n");
		printf("\t\tSandip Ghimire\n");
		printf("\t\tPrabesh Pradhan");
		getch();
		closegraph();
		exit(0);
}
void seatchoose1()
{
	seatchoose10:
	clrscr();
	closegraph();
	int i=0,j=0,temp;
	int gd=DETECT,gm,bkcolor;
	char moviename[30];
   //	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	fmovie1=fopen("movie.txt","r");
	while(fscanf(fmovie1,"%d\t\t%s\t\t\t%s\n",&m.id,&m.name,&m.st)!=EOF)
	{
		if(movieno==m.id)
		{
			printf("\n   ********//Available Seats For %s in %s Time//**********",m.name,m.st);
			strcpy(moviename,m.name);
		}
	}
	fclose(fmovie1);

	if(movieno==1)
	{
		seat2=fopen("seatm1.txt","r");
	}
	else if(movieno==2)
	{
		seat2=fopen("seatm2.txt","r");
	}
	else if(movieno==3)
	{
		seat2=fopen("seatm3.txt","r");
	}
	else if(movieno==4)
	{
		seat2=fopen("seatm4.txt","r");
	}
	else if(movieno==5)
	{
		seat2=fopen("seatm5.txt","r");
	}
	else if(movieno==6)
	{
		seat2=fopen("seatm6.txt","r");
	}
	else if(movieno==7)
	{
		seat2=fopen("seatm7.txt","r");
	}
	else
	{
		printf("\n No Seats Found Please Choose Another Time or Movie");
		getch();
		menu();
	}
	i=1;
	j=0;
	while(fscanf(seat2,"%d\t",&seat[i][j])!=EOF)
	{
		j++;
		if(j==9)
		{
			i++;
			j=0;
		}
	}
	fclose(seat2);
	//Graphics Function Start
	outtextxy(200,70,moviename);
	seatgraphicsprint();   //Calling the function where all seats of hall are stored graphically
	reservedseat();
	outtextxy(20,450,"Press any key to continue booking...");
	getch();
	closegraph();
	clrscr();
	printf("\n\t\tInsert Only Integer Values");
	printf("\n\t\tEnter 99 to view seats again");
	printf("\n\t\tEnter 100 to Exit to main menu");
	printf("\n\t\tUser Can still use 99 and 100 function in Seat number input");
	printf("\n\t\tEnter Number Of seats Required: ");
	scanf("%d",&numberseats);
	printf("\n\n\t\t");
	int k;
	if(numberseats>=1&numberseats<=60)
	{
		for(i=1;i<=numberseats;i++)    //Loop to clean up Dummy System Value
		{
			seatno[i]=0;
		}
		printf("\n\t\tEnter Seat Numbers\n");
		int l=1;
		for(i=1;i<=numberseats;i++)  //loop to take the Seat Numbers
		{
			scanf("%d",&temp);
			if(temp==99)
			{
				goto seatchoose10;
			}
			if(temp==100)
			{
				maincontrolmenu();
			}
			for(k=0;k<=7;k++)
			{
				for(j=0;j<=9;j++)
				{
				    if(temp==seat[k][j])
				    {
					clrscr();
					printf("\n\nt\t\tSeat Already Taken Please Proceed From First menu Again");
					printf("\n\t\tPlease Select Different Seats and Please view available seats");
					getch();
					goto seatchoose10;
				    }
				}
			}
			for(j=1;j<=numberseats;j++)
			{
				if(seatno[l]==temp)
				    {
					clrscr();
					printf("\n\nt\t\tYou Have Already Taken Please Proceed Again");
					printf("\n\t\tPlease Select Different Seats and Please view available seats");
					getch();
					goto seatchoose10;
				    }
			}
			if(temp<1 || temp>60)
			{  	clrscr();
				printf("\n\n\t\t\tInvalid Seat Taken Please Proceed Again");
				printf("\n\t\tPlease Select Different Seats Also");
				getch();
				goto seatchoose10;
			}
			else
			{
				seatno[l]=temp;
				l++;
			}
		}
		closegraph();
	}
	else if(numberseats==100)
	{
		 maincontrolmenu();
	}
	else if(numberseats==99)
	{
	    goto seatchoose10;
	}
	else
	{       clrscr();
		printf("\n\n\n\tEnter Correct Choice Only");
		printf("\n\nUser Choice Exceeded Seats Or Insufficient Value");
		getch();
		goto seatchoose10;
	}
}
void seatgraphicsprint()
{
		rectangle(0,30,580,430); //Total Hall Rectangle
		rectangle(5,35,575,130);     //movie theatre Rectangle

		rectangle(7,150,148,420); //First Row Rectangle
		rectangle(190,150,375,420); //Second Row Rectangle
		rectangle(415,150,568,420);  //Third Row Rectangle

		rectangle(15,155,50,190);
		outtextxy(30,170,"1");

		rectangle(60,155,95,190);
		outtextxy(75,170,"2");

		rectangle(105,155,140,190);
		outtextxy(120,170,"3");

		rectangle(195,155,230,190);
		outtextxy(210,170,"4");

		rectangle(240,155,275,190);
		outtextxy(255,170,"5");

		rectangle(285,155,320,190);
		outtextxy(300,170,"6");

		rectangle(330,155,365,190);
		outtextxy(345,170,"7");

		rectangle(425,155,460,190);
		outtextxy(440,170,"8");

		rectangle(473,155,508,190);
		outtextxy(488,170,"9");

		rectangle(521,155,556,190);
		outtextxy(533,170,"10");
		//Uptohere First Row Part



		rectangle(15,200,50,235);
		outtextxy(28,215,"11");

		rectangle(60,200,95,235);
		outtextxy(73,215,"12");

		rectangle(105,200,140,235);
		outtextxy(118,215,"13");

		rectangle(195,200,230,235);
		outtextxy(208,215,"14");

		rectangle(240,200,275,235);
		outtextxy(253,215,"15");

		rectangle(285,200,320,235);
		outtextxy(298,215,"16");

		rectangle(330,200,365,235);
		outtextxy(343,215,"17");

		rectangle(425,200,460,235);
		outtextxy(438,215,"18");

		rectangle(473,200,508,235);
		outtextxy(486,215,"19");

		rectangle(521,200,556,235);
		outtextxy(533,215,"20");
		//Uptohere Second Row Part



		rectangle(15,245,50,280);
		outtextxy(28,260,"21");

		rectangle(60,245,95,280);
		outtextxy(73,260,"22");

		rectangle(105,245,140,280);
		outtextxy(118,260,"23");

		rectangle(195,245,230,280);
		outtextxy(208,260,"24");

		rectangle(240,245,275,280);
		outtextxy(253,260,"25");

		rectangle(285,245,320,280);
		outtextxy(298,260,"26");

		rectangle(330,245,365,280);
		outtextxy(343,260,"27");

		rectangle(425,245,460,280);
		outtextxy(438,260,"28");

		rectangle(473,245,508,280);
		outtextxy(486,260,"29");

		rectangle(521,245,556,280);
		outtextxy(533,260,"30");
		//Uptohere Third Row Part



		rectangle(15,290,50,325);
		outtextxy(28,305,"31");

		rectangle(60,290,95,325);
		outtextxy(73,305,"32");

		rectangle(105,290,140,325);
		outtextxy(118,305,"33");

		rectangle(195,290,230,325);
		outtextxy(208,305,"34");

		rectangle(240,290,275,325);
		outtextxy(253,305,"35");

		rectangle(285,290,320,325);
		outtextxy(298,305,"36");

		rectangle(330,290,365,325);
		outtextxy(343,305,"37");

		rectangle(425,290,460,325);
		outtextxy(438,305,"38");

		rectangle(473,290,508,325);
		outtextxy(486,305,"39");

		rectangle(521,290,556,325);
		outtextxy(533,305,"40");
		//Uptohere Fourth Row Part



		rectangle(15,335,50,370);
		outtextxy(28,350,"41");

		rectangle(60,335,95,370);
		outtextxy(73,350,"42");

		rectangle(105,335,140,370);
		outtextxy(118,350,"43");

		rectangle(195,335,230,370);
		outtextxy(208,350,"44");

		rectangle(240,335,275,370);
		outtextxy(253,350,"45");

		rectangle(285,335,320,370);
		outtextxy(298,350,"46");

		rectangle(330,335,365,370);
		outtextxy(343,350,"47");

		rectangle(425,335,460,370);
		outtextxy(438,350,"48");

		rectangle(473,335,508,370);
		outtextxy(486,350,"49");

		rectangle(521,335,556,370);
		outtextxy(533,350,"50");
		//Uptohere Fifth Row Part



		rectangle(15,380,50,415);
		outtextxy(28,395,"51");

		rectangle(60,380,95,415);
		outtextxy(73,395,"52");

		rectangle(105,380,140,415);
		outtextxy(118,395,"53");

		rectangle(195,380,230,415);
		outtextxy(208,395,"54");

		rectangle(240,380,275,415);
		outtextxy(253,395,"55");

		rectangle(285,380,320,415);
		outtextxy(298,395,"56");

		rectangle(330,380,365,415);
		outtextxy(343,395,"57");

		rectangle(425,380,460,415);
		outtextxy(438,395,"58");

		rectangle(473,380,508,415);
		outtextxy(486,395,"59");

		rectangle(521,380,556,415);
		outtextxy(533,395,"60");
		//Uptohere Sixth Row Part
}
void reservedseat()
{       int i,j,total=0;
	for(i=1;i<=7;i++)
	{
		for(j=0;j<=9;j++)
		{
			if(seat[i][j]<=60&seat[i][j]>0)
			{
				total=total+1;
			}

		if(seat[i][j]==1)
		circle(33,173,14);

	       if(seat[i][j]== 2)
		circle(78,173,14);

		if(seat[i][j]== 3)
		circle(123,173,14);

		if(seat[i][j]== 4)
		circle(213,173,14);

		if(seat[i][j]== 5)
		circle(258,173,14);

		if(seat[i][j]== 6)
		circle(303,173,14);

		if(seat[i][j]== 7)
		circle(348,173,14);

		if(seat[i][j]== 8)
		circle(443,173,14);

		if(seat[i][j]== 9)
		circle(491,173,14);

		if(seat[i][j]== 10)
		circle(539,173,14);
		//Uptohere First Row Part



		if(seat[i][j]==11)
		circle(33,218,14);

		if(seat[i][j]== 12)
		circle(78,218,14);

		if(seat[i][j]== 13)
		circle(123,218,14);

		if(seat[i][j]== 14)
		circle(213,218,14);

		if(seat[i][j]== 15)
		circle(258,218,14);

		if(seat[i][j]== 16)
		circle(303,218,14);

		if(seat[i][j]== 17)
		circle(348,218,14);

		if(seat[i][j]== 18)
		circle(443,218,14);

		if(seat[i][j]== 19)
		circle(491,218,14);

		if(seat[i][j]== 20)
		circle(539,218,14);
		//Uptohere Second Row Part



		if(seat[i][j]== 21)
		circle(33,263,14);

		if(seat[i][j]== 22)
		circle(78,263,14);

		if(seat[i][j]== 23)
		circle(123,263,14);

		if(seat[i][j]== 24)
		circle(213,263,14);

		if(seat[i][j]== 25)
		circle(258,263,14);

		if(seat[i][j]==26 )
		circle(303,263,14);

		if(seat[i][j]== 27)
		circle(348,263,14);

		if(seat[i][j]== 28)
		circle(443,263,14);

		if(seat[i][j]== 29)
		circle(491,263,14);

		if(seat[i][j]== 30)
		circle(539,263,14);
		//Uptohere Third Row Part



		if(seat[i][j]== 31)
		circle(33,308,14);

		if(seat[i][j]== 32)
		circle(78,308,14);

		if(seat[i][j]== 33)
		circle(123,308,14);

		if(seat[i][j]== 34)
		circle(213,308,14);

		if(seat[i][j]== 35)
		circle(258,308,14);

		if(seat[i][j]== 36)
		circle(303,308,14);

		if(seat[i][j]== 37)
		circle(348,308,14);

		if(seat[i][j]== 38)
		circle(443,308,14);

		if(seat[i][j]== 39)
		circle(491,308,14);

		if(seat[i][j]== 40)
		circle(539,308,14);
		//Uptohere Fourth Row Part



		if(seat[i][j]== 41)
		circle(33,353,14);

		if(seat[i][j]== 42)
		circle(78,353,14);

		if(seat[i][j]== 43)
		circle(123,353,14);

		if(seat[i][j]== 44)
		circle(213,353,14);

		if(seat[i][j]== 45)
		circle(258,353,14);

		if(seat[i][j]== 46)
		circle(303,353,14);

		if(seat[i][j]== 47)
		circle(348,353,14);

		if(seat[i][j]==48 )
		circle(443,353,14);

		if(seat[i][j]== 49)
		circle(491,353,14);

		if(seat[i][j]== 50)
		circle(539,353,14);
		//Uptohere Fifth Row Part



		if(seat[i][j]== 51)
		circle(33,398,14);

		if(seat[i][j]== 52)
		circle(78,398,14);

		if(seat[i][j]== 53)
		circle(123,398,14);

		if(seat[i][j]== 54)
		circle(213,398,14);

		if(seat[i][j]== 55)
		circle(258,398,14);

		if(seat[i][j]== 56)
		circle(303,398,14);

		if(seat[i][j]== 57)
		circle(348,398,14);

		if(seat[i][j]== 58)
		circle(443,398,14);

		if(seat[i][j]== 59)
		circle(491,398,14);

	       if(seat[i][j]== 60)
		circle(539,398,14);
		//Uptohere Sixth Row Part

	     }
	}
	char totalt[10];
	sprintf(totalt,"%d",60-total);
	outtextxy(20,440,"Total Available Seats= ");
	outtextxy(200,440,totalt);
}