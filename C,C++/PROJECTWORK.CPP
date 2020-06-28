//This program is done for computer practical 2016-17.
#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
#include<graphics.h>
#include<time.h>
#include<shivam01.h> // Header file defined by me

class User
{
	char Uname[20], Upassword[20];
	public:
	char* GetUname(){	return Uname;	}
	char* GetUpassword(){	return Upassword;	}
	void Assign(char id[], char password[] )
	{
	    strcpy(Uname,id);
	    strcpy(Upassword,password);
	}
	void ModifyUname()
	{
		strcat(Uname, ".dat");
	}
};

class AccessFile
{
	char name[20], dob[11], sex[7], acno[11], mail[30], phone[13];
	public:
	void Enter()
	{
		cout << endl;
		cout << "Name: ";
		gets(name);
		cout << "Date of birth(DOB): ";
		gets(dob);
		cout << "Gender (Male/Female): " ;
		gets(sex);
		cout << "Account Number: ";
		gets(acno);
		cout << "Mail: ";
		gets(mail);
		cout << "Phone Number: ";
		gets(phone);
	}
	void Show();

};
void AccessFile::Show()
{
	cout << "\nName: ";
	puts(name);
	cout << "Date of birth(DOB): ";
	puts(dob);
	cout << "Gender (Male/Female): ";
	puts(sex);
	cout << "Account Number: ";
	int len = strlen(acno)-4;
	for(int i = 0; i < len; i++)
		cout << "*";
	for(;i < strlen(acno); i++)
		cout << acno[i];
	cout << "\nMail: ";
	puts(mail);
	cout << "Phone Number: ";
	puts(phone);
}
class Mail
{
	char ch[300], uid[20];
	public:
	void Assign(char* id)
	{
		stpcpy(uid,id);
	}
	void Enter()
	{
		cout << "\nEnter the mail (max 300): ";
		gets(ch);
	}
	void Display();

};
void Mail::Display()
{
	cout << "\nU ID: ";
	puts(uid);
	cout << "Message -> ";
	for(int i = 0; i < strlen(ch); i++)
		cout << ch[i];
	cout << endl;
}

void SelectUser();
void Nuser();
void Euser();
void Admn();
void CreateAccount();
int  Checkid(char*);
int  Checkpass(char*);
void Access(char*, char*);
void Menu();
void hack();
void Smile();
void Starting();
void Admin();

void main()
{
	clrscr();
	Starting();
	Intro();
	SelectUser();
	Smile();
}
void ModifyAc(char*, char*);
void DeleteAc(char*, char*);
void ChangePass(char*, char*);
void MailAd(char*, char*);
void Show(char*, char*);

void Menu()
{
	beg:
	clrscr();
	cout << "\t\t\t  WELCOME TO DATA-THEORY\n";
	cout << "\t\t\t  ----------------------\n";
	int op = 0;
	cout << "Open your Account\n";
	char id[20], pass1[20], c[1];
	int count = 0, allow = 0;
	x:
	cout << "Enter your username: ";
	gets(id);
	int check = Checkid(id); // if found then 0 else 1....
	if(check == 1)
	{
		clrscr();
		allow++;
		cout << "Enter your username: ";
		puts(id);
		cout << "\tX(invalid id)\n";
		if(allow == 3)
		{
			char ch;
			cout << "Account has not been detected hence server blocked you\n";
			cout << "\nYou have Entered Wrong Password for 3 times\n";
			cout << "Do you want to relogin(y/n): ";
			cin >> ch;
			if(ch == 'y' || ch == 'Y')
				goto beg;
			else
				return;
		}
		delay(1500);
		goto x;
	}
	lb:
	if(count == 3)
	{
		char wrong[] = {"Your Account Has Been Blocked By the "
			"Admin for 1 Minute. As you entered 3 times worng Password"};
		for(int i = 0;i < strlen(wrong); i++)
		{
			cout << wrong[i];
			delay(20);
		}
		cout << "\n";
		system("pause");
		hack();
		char ch = 'n';
		clrscr();
		cout << "Do you want to relogin(y/n): ";
		cin >> ch;
		if(ch == 'y' || ch == 'Y')
			goto beg;
		else
			return;
	}
	strcpy(pass1, "\0");
	c[0] = '\0';
	cout << "Enter an Password: ";
	count++;
	while(c[0] != (char)13)
	{
		c[0] = getch();
		if(c[0] != (char)13)
		{
			cout << "*";
			c[1] = '\0';
			strcat(pass1,c);
			strcat(pass1,"\0");
		}
	}
	check = 1;
	check = Checkpass(pass1);
	if(check == 1)
	{
		cout << " (Password incorrect)\n";
		goto lb;

	}
	delay(1500);
	clrscr();
	cout << "\t\t\t  WELCOME TO DATA-THEORY\n";
	cout << "\t\t\t  ----------------------\n";
	cout << "\nChoose from the below options\n";
	do
	{
		cout << "1.Modify Your Account\n";
		cout << "2.Delete Your Account\n";
		cout << "3.Change Your Password\n";
		cout << "4.Mail Administrator\n";
		cout << "5.Show Your Account\n";
		cout << "6.Simply Exit\n";
		cout << "-> ";
		cin >> op;
		if(op < 0 || op > 6)
		{
			cout << "Oops!!! Worng option";
			delay(1500);
			clrscr();
		}
	}while(op < 0 || op > 6);
	switch(op)
	{
		case 1: ModifyAc(id,pass1);
			break;
		case 2: DeleteAc(id,pass1);
			break;
		case 3: ChangePass(id,pass1);
			break;
		case 4: MailAd(id,pass1);
			break;
		case 5: Show(id,pass1);
		default:
			return;
	}
}
void ModifyAc(char* id, char* pass)
{
	User U1;
	ifstream fin("User.dat",ios::binary);
	if(!fin) // ACCESS FILE OF THE USER.....
	{
		cout << "File not found!!!!";
		delay(1500);
		return;
	}
	while(fin.read((char*)&U1, sizeof(U1)))
	{
		if(strcmp(U1.GetUpassword(),pass) == 0 && strcmp(U1.GetUname(),id) == 0)
			break;

	}
	U1.ModifyUname();
	fstream f(U1.GetUname(),ios::binary|ios::app);
	AccessFile A1;
	char ch;
	cout << "Do u really want to modify your account (y/n): ";
	cin >> ch;
	if(ch == 'n' || ch == 'N')
		return;
	A1.Enter();
	ofstream fout("temp.dat",ios::binary);
	fout.write((char*)&A1, sizeof(A1));
	fout.close();
	f.close();
	remove(U1.GetUname());
	rename("temp.dat",U1.GetUname());
	cout << "\nCongratulation!! Your Account has been Modified\n";
	cout << "Do you wan to print and check the change (y/n): ";
	cin >> ch;
	if(ch == 'n' || ch == 'N')
		return;
	A1.Show();
	cout << "\nDo u want to end this program(y/n): ";
	cin >> ch;
	if (ch == 'n' || ch == 'N')
		Menu();
}
void DeleteAc(char* id, char* pass)
{
	User U1;
	ifstream fin("User.dat",ios::binary);
	ofstream fout("temp.dat",ios::binary);
	if(!fin) // ACCESS FILE OF THE USER.....
	{
		cout << "File not found!!!!";
		delay(1500);
		return;
	}
	while(fin.read((char*)&U1, sizeof(U1)))
	{
		if(strcmp(U1.GetUpassword(),pass) == 0 && strcmp(U1.GetUname(),id) == 0);
		else
			fout.write((char*)&U1, sizeof(U1));
	}
	char ch = 'n';
	cout << "Do u really want to delete your account (y/n): ";
	cin >> ch;
	if(ch == 'n' || ch == 'N')
	{
		fout.close();
		fin.close();
		remove("temp.dat");
		return;
	}
	fout.close();
	fin.close();
	remove("User.dat");
	rename("temp.dat","User.dat");
	cout << "\nCongratulation!! Your Account has been Deleted\n";
	cout << "Thankyou for being our Precious User..\n";
	cout << "\nDo u want to end this program(y/n): ";
	cin >> ch;
	if (ch == 'n' || ch == 'N')
		Menu();
}
void ChangePass(char* id, char* pass)
{
	User U1;
	fstream fin("User.dat",ios::binary|ios::app);
	ofstream fout("temp.dat",ios::binary);
	if(!fin) // ACCESS FILE OF THE USER.....
	{
		cout << "File not found!!!!";
		delay(1500);
		return;
	}
	while(fin.read((char*)&U1, sizeof(U1)))
	{
		if(strcmp(U1.GetUpassword(),pass) == 0 && strcmp(U1.GetUname(),id) == 0);
		else
			fout.write((char*)&U1, sizeof(U1));

	}
	char ch;
	cout << "Do u really want to change your Password (y/n): ";
	cin >> ch;
	if(ch == 'n' || ch == 'N')
	{
		fout.close();
		fin.close();
		remove("temp.dat");
		return;
	}
	char pass1[20], c[1];
	strcpy(pass1, "\0");
	c[0] = '\0';
	cout << "Enter your new Password: ";
	while(c[0] != (char)13)
	{
		c[0] = getch();
		if(c[0] != (char)13)
		{
			cout << "*";
			c[1] = '\0';
			strcat(pass1,c);
			strcat(pass1,"\0");
		}
	}
	U1.Assign(id,pass1);
	fout.write((char*)&U1, sizeof(U1));
	fout.close();
	fin.close();
	remove("User.dat");
	rename("temp.dat","User.dat");
	cout << "\nCongratulation!! Your Password has been Changed\n";
	cout << "\nDo u want to end this program(y/n): ";
	cin >> ch;
	if (ch == 'n' || ch == 'N')
		Menu();
}
void SelectUser()
{
	int op = 0;
	do
	{
		cout << "Choose from the below optios:\n";
		cout << "\t1.New User\n";
		cout << "\t2.Existing User\n";
		cout << "------> ";
		cin >> op;
		if(op > 2 || op < 1)
			cout << "Oops Wrong choise!!\n";
	}while(op > 2 || op < 0);
	switch(op)
	{
		case 1: Nuser();
			break;
		case 2: Menu();
			break;
		case 0: Admin();
			break;
		default:
			getch();
	}
}
void Nuser()
{
	cout << "INTRODUCTION\n";
	cout << "------------\n";
	char str[] = { "This is program called DATA-THEORY based on "
	"the concept of SKYNET which enables  you to mannage your account "
	"under high security, and privillence of administrator "
	"Here you are provided all the access execpt peeping into "
	"others account.."};
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		cout << str[i];
		delay(20);
	}
	cout << endl << endl;
	system("pause");
	clrscr();
	char ch;
	cout << "Do you want to create a new acount(y/n)\n-----> ";
	cin >> ch;
	if(ch == 'n' || ch == 'N')
	{
		cout << "Thanks for giving your precious time to us, "
			"with regards -SKYNET";
		getch();
		exit(0);
	}
	else if(ch == 'y' || ch == 'Y')
		CreateAccount();
}
void CreateAccount()
{
	x:
	clrscr();
	char id[20], pass1[20], c[1];
	cout << "Enter an username: ";
	gets(id);
	int check = Checkid(id); // if found then 1 else 0....
	if(check == 0)
	{
		clrscr();
		cout << "Enter an username: ";
		puts(id);
		cout << " X(Username already exist)\n";
		delay(1500);
		goto x;
	}
	strcpy(pass1, "\0");
	c[0] = '\0';
	cout << "Enter an Password: ";
	while(c[0] != (char)13)
	{
		c[0] = getch();
		if(c[0] != (char)13)
		{
			cout << "*";
			c[1] = '\0';
			strcat(pass1,c);
			strcat(pass1,"\0");
		}
	}
	for(int i = 0; i < 100; i++)
	{
		cout << i+1 << "%";
		delay(20);
		clrscr();
	}
	User U1;
	U1.Assign(id, pass1);
	ofstream fout("User.dat",ios::binary);
	fout.write((char*)&U1, sizeof(U1));
	cout << "\nYour Account is created\n";
	U1.ModifyUname();
	ofstream f(U1.GetUname(),ios::binary);
	AccessFile A1;
	A1.Enter();
	f.write((char*)&A1, sizeof(A1));
	fout.close();
	f.close();
	cout << "\nNow connecting to the main Server\n";
	Menu();
}
int Checkid(char *id)
{
	User U1;
	ifstream fin("User.dat",ios::binary);
	while(fin.read((char*)&U1, sizeof(U1)))
	{
		if(strcmpi(U1.GetUname(),id) == 0)
			return 0;
	}
	return 1;
}
int Checkpass(char *pass)
{
	User U1;
	ifstream fin("User.dat",ios::binary);
	while(fin.read((char*)&U1, sizeof(U1)))
	{
		if(strcmp(U1.GetUpassword(),pass) == 0)
			return 0;
	}
	return 1;
}
void MailAd(char* id, char* pass)
{
	User U1;
	ifstream fin("User.dat",ios::binary);
	if(!fin) // ACCESS FILE OF THE USER.....
	{
		cout << "File not found!!!!";
		delay(1500);
		return;
	}
	while(fin.read((char*)&U1, sizeof(U1)))
	{
		if(strcmp(U1.GetUpassword(),pass) == 0 && strcmp(U1.GetUname(),id) == 0)
			break;

	}

	ofstream("Mail.dat",ios::app);
	char ch, show[] = {"Now you mail your administrator for any change or any remark in the SKYNET: "};
	for(int i = 0; i < strlen(show); i++)
	{
		cout << show[i];
		delay(20);
	}
	cout << endl << "----> ";
	Mail M1;
	M1.Assign(id);
	M1.Enter();
	ofstream fout("Mail.dat", ios::binary);
	fout.write((char*)&M1, sizeof(M1));
	fin.close();
	fout.close();
	cout << "\nDo u want to end this program(y/n): ";
	cin >> ch;
	if (ch == 'n' || ch == 'N')
		Menu();
}
void Show(char *id, char* pass)
{
	User U1;
	int flag = 0;
	char ch;
	ifstream fin("User.dat",ios::binary);
	if(!fin) // ACCESS FILE OF THE USER.....
	{
		cout << "File not found!!!!";
		delay(1500);
		return;
	}
	while(fin.read((char*)&U1, sizeof(U1)))
	{
		if(strcmp(U1.GetUpassword(),pass) == 0 && strcmp(U1.GetUname(),id) == 0)
		{
			flag = 1;
			break;
		}

	}
	if(!flag)
	{
		fin.close();
		cout << "Sorry User ID don't exist\n";
		return;
	}
	U1.ModifyUname();
	ifstream f(U1.GetUname(),ios::binary);
	AccessFile A1;
	while(f.read((char*)&A1, sizeof(A1)))
	{
		A1.Show();
	}
	cout << "\nDo u want to end this program(y/n): ";
	cin >> ch;
	if (ch == 'n' || ch == 'N')
		Menu();
}
void hack()
{
	clrscr();
	int gd = DETECT;
	int gm, error;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	error = graphresult();
	if(error != grOk)
	{
		cout << "graphics error ";
		getch();
		return;
	}
	time_t rawTime;
	struct tm* currentTime;
	char a[100];
	for(int i = 0; i < 60; i++)   // for -- seconds...
	{
	rawTime = time(NULL);
	currentTime = localtime(&rawTime);

	//for time
	strftime(a, 100, "%I:%M:%S", currentTime);
	setcolor(11);
	settextstyle(3, HORIZ_DIR, 10);
	outtextxy(40, 100, a);

	//for am and for pm.....
	strftime(a, 100, "%p", currentTime);
	settextstyle(3, HORIZ_DIR, 2);
	outtextxy(600, 8, a);

	//for date, month and year
	strftime(a, 100, "%a, %d, %b, %Y", currentTime);
	settextstyle(3, HORIZ_DIR, 5);
	outtextxy(100, 310, a);
	delay(1000);
	cleardevice();
	}
	closegraph();
	Menu();
}
void Smile()
{
   int gd = DETECT, gm, area, temp1, temp2, left = 25, top = 75;
   void *p;

   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

   setcolor(YELLOW);
   circle(50,100,25);
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(50,100,YELLOW);

   setcolor(BLACK);
   setfillstyle(SOLID_FILL,BLACK);
   fillellipse(44,85,2,6);
   fillellipse(56,85,2,6);

   ellipse(50,100,205,335,20,9);
   ellipse(50,100,205,335,20,10);
   ellipse(50,100,205,335,20,11);

   area = imagesize(left, top, left + 50, top + 50);
   p = malloc(area);

   setcolor(WHITE);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   outtextxy(200,451,"Code Represented by Shivam.");

   setcolor(BLUE);
   rectangle(0,0,639,449);

   while(!kbhit())
   {
      temp1 = 1 + random ( 588 );
      temp2 = 1 + random ( 380 );

      getimage(left, top, left + 50, top + 50, p);
      putimage(left, top, p, XOR_PUT);
      putimage(temp1 , temp2, p, XOR_PUT);
      delay(500);
      left = temp1;
      top = temp2;
   }

   getch();
   closegraph();
}
void Starting()
{
   int gd = DETECT, gm, i;
   char a[5];

   initgraph( &gd, &gm, "C:\\TURBOC3\\BGI");

   setcolor(-5);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
   outtextxy(160,200,"Starting Project\n");
   delay(500);
   outtextxy(300,260,"IN");
   delay(3000);

   cleardevice();
   settextjustify( CENTER_TEXT, CENTER_TEXT );
   settextstyle(DEFAULT_FONT,HORIZ_DIR,50);
   setcolor(RED);
   for (i = 10; i >=0; i--)
   {
      sprintf(a,"%d",i);
      outtextxy(getmaxx()/2, getmaxy()/2, a);
      delay(1000);

      if ( i == 0 )
	 break;
      cleardevice();
   }
   closegraph();
   delay(500);
}

void Admin()
{
	clrscr();
	cout << "\nHi Shivam \n";
	cout << "You got few of the mails, do you want to see them(y/n): ";
	char ch;
	cin >> ch;
	Mail M1;
	if( ch == 'n' || ch == 'N')
		cout << "Okey not showing your mails, but make sure to check them soon\n";
	else
	{
		ifstream fin("Mail.dat", ios::binary);
		fin.read((char*)&M1, sizeof(M1));
		M1.Display();
	}
	cout << "\nOkey you have seen those mails, do you want to delete them:(y/n) ";
	cin >> ch;
	if(ch == 'y' || ch == 'Y')
		remove("Mail.dat");
	cout << "Now all task completed, logging you out\n";
	system("pause");

	int gd = DETECT, gm, i;
	char a[5];

	initgraph( &gd, &gm, "C:\\TURBOC3\\BGI");

	setcolor(-5);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
	outtextxy(160,200,"BYE\n");
	delay(500);
	setcolor(-5);
	outtextxy(300,260,"Shivam");
	delay(3000);

	closegraph();
	delay(500);
}