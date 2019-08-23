/*
This project was developed by me during my 3rd semester of engineering for the subject Data Structures and Algorithms.
This is a prototype it can be developed into a full fledged game. Since my knowledge of programming then was restricted to C , 
i have developed this simple code.
Data Structure used-> LINKED LIST
The idea is to develop a game on a famous TV Series called game of thrones. In this game , user actions change the ending of the story. 
If the user has more points user sits on the Iron Throne else the users enemy sit on the throne.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int dragon=0, iron=0, dorn=0, count=0;
struct house
{
	char charname[20];
	char housename[20];
	char gender;
	    int housepower;
	    int totalpower;
	int flag;
	struct house *next;
}*housefirst, *houselast, *temp ;
struct enemy
{
	char charname[20];
	int housepower;
	struct enemy *next;
}*enemyfirst, *enemylast, *temp1, *temp2;
void dragonstone()
{
      printf("Making allies with khaleesi \n");
      getch();
      temp= (struct house*)malloc(sizeof(struct house));
      strcpy(temp->charname,"khaleesi");
      temp->gender='f';
      temp->housepower=10;
      strcpy(temp->housename,"targaryn");
      temp->flag=1;
      houselast->next=temp;
      houselast=temp;
      housefirst->totalpower=housefirst->totalpower+houselast->housepower;
      dragon=1;
      count++;
}
void ironislands()
{
	printf("Defeating Euron \n");
	getch();
	temp1=enemyfirst;
	while(temp1->charname!="euron")
	{
	temp2=temp1;
	temp1=temp1->next;
	}
	temp2->next=temp1->next;
	free(temp1);
	printf("euron defeated: \n");
	getch();
	iron=1;
	count++;
}
void dorne()
{
	printf("Making allies with dorne \n");
      getch();
      temp= (struct house*)malloc(sizeof(struct house));
      strcpy(temp->charname,"aleanna tyrell");
      temp->gender='f';
      temp->housepower=4;
      strcpy(temp->housename,"tyell");
      temp->flag=1;
      houselast->next=temp;
      houselast=temp;
      housefirst->totalpower=housefirst->totalpower+houselast->housepower;
	dorn=1;
	count++;
}
void append(char a[20], int hp)
{
	temp1=(struct enemy*)malloc(sizeof(struct enemy));
	strcpy(temp1->charname, a);
	temp1->housepower=hp;
	enemylast->next=temp1;
	enemylast=temp1;
}
void createenemy()
{
	temp1=(struct enemy*)malloc(sizeof(struct enemy));
	strcpy(temp1->charname,"cersei");
	temp1->housepower=10;
	enemyfirst=temp1;
	enemylast=enemyfirst;
	append("euron",10);
	append("mountain",5);
	temp1=enemyfirst;
	printf("enemylist= \t");
	while(temp1!=NULL)
	{
	printf(" %s \t", temp1->charname);
	temp1=temp1->next;
	}
	getch();
}
void startscreen()
{
	int ch1, enemyhp=0,ch2;
	clrscr();
	while(count<2)
	{
	label101: printf("Lady Mormont: where do you wish to travel, my lord \n");
	getch();
	printf("1. DRAGONSTONE \n 2. IRON ISLANDS \n 3. DORNE \n 4. KINGS LANDING \n");
	scanf("%d", &ch1);
	switch(ch1)
	{
		case 1: if(dragon==1)
			{
				printf("You cannout visit the same place twice: \n");
				getch();
				goto label101;
			}
			dragonstone();
			getch();
			goto label101;
		case 2: if(iron==1)
			{
				printf("You cannout visit the same place twice: \n");
				getch();
				goto label101;
			}
			ironislands();
			getch();
			goto label101;

		case 3: if(dorn==1)
			{
				printf("You cannout visit the same place twice: \n");
				getch();
				goto label101;
			}
			 dorne();
			getch();
			goto label101;

		case 4: while(temp1!=NULL)
			{
				temp1=enemyfirst;
				enemyhp=enemyhp+temp1->housepower;
				temp1=temp1->next;
			}
			if(enemyhp<housefirst->totalpower)
			{
				clrscr();
				printf("Brandon Stark appears in your dream\n");
				getch();
				printf("Brandon: Your army is too weak, try later \n");
				getch();
				printf("You wake up!\n");
				getch();
				printf("Lady Mormont: Are you sure you want to travel to Kings landing so soon?\n");
				printf(" 1 for no\n");
				scanf("%d",&ch2);
				if(ch2==1)
				goto label101;
				else
				{
					label102:
					clrscr();
					printf("You travel to kings landing \n");
					getch();
					printf("You are too weak for cersei \n");
					getch();
					printf("YOU ARE DEAD !! \n");
					getch();
					printf("Game Over \n");
					getch();
					exit(0);
				}
			}
			else
			{
			label103:
				printf("Congratulations!!!, you were strong enough for the battle \n");
				getch();
				printf("you are now the ruler of the seven kingdoms \n");
				getch();
				printf("Game WON \n");
				getch();
				printf("THE END\n");
				getch();
				exit(0);
			}
			break;
		default: goto label101;
	}
	}
	while(temp1!=NULL)
			{
				temp1=enemyfirst;
				enemyhp=enemyhp+temp1->housepower;
				temp1=temp1->next;
			}
	if(count==2&&(enemyhp<housefirst->totalpower))
	{
		goto label102;
	}
	else if(count==2)
	{
		goto label103;
	}
}

void playintro()
{
    int bp=0,choice, ch1,ch2;
    printf("You are %s sitting in the council at your kingdom, Winterfell.\n You just received a raven which tells that Cersai killed half the population of Kings Landing,\n to protect herself from her mistakes\n" , housefirst->charname);
    getch();
    clrscr();
    printf("She is an evil woman who took part in the killing of your father and brother. \n");
    getch();
    clrscr();
    printf("Winter is coming and there is shortage of food in the north.\n  But you need to plan against cersei because if you dont,\n she might attack you anytime and win over your kingdom.\n");
    getch();
    clrscr();
    temp=(struct house*)malloc(sizeof(struct house));
    strcpy(temp->housename, "Stark sub houses");
    strcpy(temp->charname, "Lady Mormont");
    temp->gender='g';
    housefirst->next=temp;
    houselast=temp;
    houselast->flag=1;
    printf("You are about to enter the meeting of your allies.\n Lady Mormont the commander of your army appears. \n");
    getch();
    clrscr();
    printf("Lady Mormont: Good morning , your grace\n");
    getch();
    printf("You: Good Morning, Lady Mormont\n");
    getch();
    printf("Lady Mormont: Any news from kings landing?\n");
    getch();
    ch11: printf("What do you reply? \n 1.	I got a raven from the citadel, cersei blew up the Sept. \n 2.	We can talk about it later, I heard winter is coming and the food is more important \n3.	Nothing that important \n 4.	Prepare and army, we are attacking kings landing, lets leave immediately \n");
    scanf("%d", &choice);
    switch(choice)
    {
	case 1: bp=bp+2;
		clrscr();
		printf("\n Lady Mormont: OH thats bad, the people of Kings Landing need justice. \n;");
		getch();
		getch();
		lab99: printf("What are your plans your grace?\n1.	We should go and attack immediately \n2.	I think we need supplies and also a more stronger army \n3.	No lets let it be , let %s take decision  \n",((housefirst->gender=='b')||(housefirst->gender=='B')?"sansa":"jon"));
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1: bp=bp-1;
			 break;
			 case 2: bp=bp+2;
			break;
			case 3: bp=bp-2;
			break;
			default: goto lab99;

		};
		break;
	case 2: bp=bp+1;
		clrscr();
		printf("Lady Mormont: I agree your grace. But aren’t you going to bring justice to your family \n");
		getch();
		label98: printf("What would you do your grace? \n 1.	Attack immediately \n2.	 Tell her about the sept, ask her to assist in Gathering army and supplies \n3.	I don’t know yet \n");
		scanf("%d", &ch1);
		switch(ch1)
		{
			case 1: bp=bp+0;
				break;
			case 2: bp=bp+2;
				break;
			case 3: bp=bp-1;
				break;
			deault: goto label98;

		}
		break;
	case 3: bp=bp-1;
		printf(" %s : we got a raven which said cersei blew up the sept \n We need to gather allies \n Go and defeat cersei once and for all \n and get justice for the people \n",((housefirst->gender=='b')||(housefirst->gender=='B')?"sansa":"jon"));
		getch();
		break;
	case 4: bp=bp-2;
		printf("\n Lady Mormont: i think its too soon my lord, we need more powerful allies and supplies: \n");
		getch();
		break;
	default: goto ch11;

    }
	if(bp==4)
	houselast->housepower=10;
	else if(bp==3)
	houselast->housepower=8;
	else
	houselast->housepower=6;
	housefirst->totalpower=housefirst->totalpower+houselast->housepower;
       lab123:	clrscr();
	getch();
	printf("\nLady Mormont: What should we do now my lord");
	printf("\n1. Learn about the rulers \n 2. Go and make allies\n");
	scanf("%d", &ch2);
	switch(ch2)
	{
		case 1: printf("1. Dragon stone: \n Home of the dragon queen , aims to conquer the iron throne and defeat cersei \n Name of Ruler: Khaleesi\n");
			printf("2. Iron Islands: \n Home of Euron Greyjoy, on cersei side, \n you are advised to defeat him inorder to defeat cersei\n");
			printf("3. Dorne: Neutral venue \n Try to make allies\n");
			getch();
			clrscr();
			goto lab123;

		case 2: createenemy();
			startscreen();
			break;
		default: goto lab123;

	}

}
void playasjon()
{
	printf("Character Details: \n Name= %s \n House= %s \n",temp->charname, temp->housename);
	printf("introduction to your character:- \n");
	getch();
	printf("You are the only adopted son of Ned Stark \n");
	getch();
	printf("You are the eldest of the stark children \n");
	getch();
	printf("You have three half-brothers: Rick, Robb and Bran \n and two half-sisters: Sansa and arya \n");
	getch();
	printf("Your father was killed by the lannisters \n");
	getch();
	printf("Your aim is to build an army to overthrow the lannisters \n");
	getch();
	printf("they are currently sitting on the iron throne are ruling over the seven kingdoms \n");
	getch();
	printf("You dont have enough men to defeat Cersei (The Queen) \n It is suggested you make allies \n");
	clrscr();
	printf("History of your house: \n");
	getch();
	printf("House: STARK \n Sigil: Direwolf \n Ancestral Home : Winterfell \n");
	getch();
	printf("Present Position: KING IN THE NORTH \n");
	getch();
	printf("Enemies: Cersei who killed your brother, mother and father \n");
	getch();
	printf("Family: \n      \t Last Seen \t realtionship");
	printf("\n Arya \t unknown \t sister \n Bran \t unknown \t brother \n Sansa \t Winterfell \t sister \n Rick \t Dead \t brother  (killed by boltons) \n Ned \t Dead \t father  (killed by cersei lannister) \n Robb \t Dead \t brother  (killed by lannisters) \n Kate \t Dead \t Step mother  (killed by lannisters) \n");
	getch();
	clrscr();
 }
void playassansa()
{
printf("Character Details: \n Name= %s \n House= %s \n",temp->charname, temp->housename);
	printf("introduction to your character:- \n");
	getch();
	printf("You are the daughter of Ned Stark \n");
	getch();
	printf("You have three brothers: Rick, Robb and Bran \n one sister: arya \n and one half brother: jon \n");
	getch();
	printf("Your father was killed by the lannisters \n");
	getch();
	printf("Your half brother jon is currently king in the north\n");
	getch();
	printf("His aim is to build an army to overthrow the lannisters \n");
	getch();
	printf("they are currently sitting on the iron throne are ruling over the seven kingdoms \n");
	getch();
	printf("Your Family doesn't have enough men to defeat Cersei (The Queen) \n You have to help Jon in making allies \n");
	clrscr();
	printf("History of your house: \n");
	getch();
	printf("House: STARK \n Sigil: Direwolf \n Ancestral Home : Winterfell \n");
	getch();
	printf("Present Position: LADY OF WINTERFELL \n");
	getch();
	printf("Enemies: Cersei who killed your brother, mother and father \n");
	getch();
	printf("Family: \n      \t Last Seen \t realtionship");
	printf("\n Arya \t unknown \t sister \n Bran \t unknown \t brother \n Jon  \t Winterfell \t half brother \n Rick \t Dead \t brother  (killed by boltons) \n Ned \t Dead \t father  (killed by cersei lannister) \n Robb \t Dead \t brother  (killed by lannisters) \n Kate \t Dead \t mother  (killed by lannisters) \n");
	getch();
	clrscr();
}
void createstark()
{
	char house[20], chara[20];
	getch();
	clrscr();
	printf("I am also called the three eyed raven \n \n");
	getch();
	clrscr();
	printf("IT MEANS : \n");
	getch();
	printf("No matter what you do \n Where you are \n i can see everything \n");
	getch();
	clrscr();
	printf("I will appear as voices in your head for now \n");
	getch();
	printf("In case if you are lucky,\n you can meet me in this game");
	getch();
	clrscr();
	printf(" \n Be aware of your surroundings \n Dont get yourself killed \n");
	getch();
	temp=(struct house*)malloc(sizeof(struct house));
	if(temp==NULL)
	{
	printf("error in creation: \n");
	getch();
	exit(0);
	}
	labelss:
	clrscr();
	printf("First tell me are you a BOY or GIRL (B/G): \n");
	flushall();
	scanf("%c",&temp->gender);
	strcpy(temp->housename, "stark");
	if(temp->gender=='b'||temp->gender=='B')
	{
	strcpy(temp->charname,"Jon Snow");
	printf("\n You Play as Jon Snow \n Son of Ned Stark \n King in the North \n");
	getch();
	clrscr();
	playasjon();
	}
	else if(temp->gender=='g'||temp->gender=='G')
	{
	strcpy(temp->charname,"Sansa Stark");
	printf("\n You Play as Sansa Stark \n daughter of Ned Stark \n Lady of winterfell \n");
	getch();
	clrscr();
	playassansa();
	}
	else
	{
	printf("Invalid entry try again \n");
	goto labelss;
	}

	housefirst=temp;
	houselast=housefirst;
	housefirst->totalpower=0;
	printf("The rules of this game are simple \n");
	getch();
	printf("This is a story based game \n");
	getch();
	printf("In Every scene, you would have to make choices \n");
	getch();
	printf("those decisions will atler the story line \n");
	getch();
	clrscr();
	getch();
	playintro();
	free(temp);
	free(housefirst);
	free(houselast);
}
void main()
{
	int choice;
	clrscr();
	printf("\n\n\t\t\t\tTRIPLE N STUDIOS PRESENTS\n");
	printf("\n\n\n\t\t\t\t    A GAME OF THRONES\n");
	printf("\n\n\nPress any key to continue \n");
	getch();
	 clrscr();
	label1: printf(" Enter your choice: \n \t 1.NEW GAME \n \t 2.EXIT \n");
	flushall();
	scanf("%d", &choice);
	switch(choice)
	{
		case 1: clrscr();
			printf("Hi, I am Brandon Stark \n Son of Ned Stark \n \n I will be your guide in the game \n i will appear when necessary \n");
			createstark();
			break;
		
		case 2: exit(0);
			break;
		default: clrscr();
			printf("invalid entry.. TRY AGAIN \n");
			goto label1;
	}

}
