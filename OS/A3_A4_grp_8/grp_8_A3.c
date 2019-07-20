#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
#include<error.h>

#define RED     		"\x1b[31m"
#define GREEN   		"\x1b[32m"
#define YELLOW  		"\x1b[33m"
#define BLUE    		"\x1b[34m"
#define MAGENTA 		"\x1b[35m"
#define CYAN    		"\x1b[36m"
#define RESET_Color 	"\x1b[0m"

#define	MaxServiceMan	100

int Max_Processes=5,Max_ArrivalTime=15,Max_BurstTime=5,MaxServicemen=2;
int CurrentServiceMan=0;
int StatusServicemen[MaxServiceMan];

struct Item
{
	char Name[20];
	int BurstTime;
	int ArrivalTime;
	pthread_mutex_t lockItem;
	struct Item *Next;
}*Front=NULL,*TotalFront=NULL,*Rare=NULL,*TotalRare=NULL;

void Insert(char *n,int BT,int AT)
{
	struct Item *temp;
	if(CountItems() == Max_Processes)
	{
		printf(YELLOW "Maximum Item Count Reached\nCan not add new Item\nDropping %s --> %d \tProcess",n,BT);
		printf(RESET_Color "\n\n");
	}
	else if(CountItems() > Max_Processes)
	{
		printf(RED "Unreachable Branch In Execution Please Rerun the Code" RESET_Color "\n\n");
		exit(-1);
	}
	else
	{
		temp=(struct Item*)malloc(sizeof(struct Item));
		strcpy(temp->Name,n);
		temp->BurstTime=BT;
		temp->ArrivalTime=AT;
		temp->lockItem=(pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		temp->Next=NULL;
		
		if(Front==NULL)
		{
			Front=temp;
			Rare=temp;
		}
		else
		{
			Rare->Next=temp;
			Rare=temp;
		}
		printf(GREEN);
		printf("\n%s(ArrivalTime:%d) --> \t%d\t Added in Service Queue\n",temp->Name,temp->ArrivalTime,temp->BurstTime);
		printf(RESET_Color "\n");
	}
	
}

void InsertInWaitingQueue(char *n)
{
	struct Item *temp;
	temp=(struct Item*)malloc(sizeof(struct Item));
	strcpy(temp->Name,n);
	temp->BurstTime=rand()%Max_BurstTime;
	temp->ArrivalTime=rand()%Max_ArrivalTime;
	temp->Next=NULL;
	if(temp->ArrivalTime==0)
	{
		Insert(temp->Name,temp->BurstTime,temp->ArrivalTime);
		free(temp);
	}
	else
	{
		if(TotalFront==NULL)
		{
			TotalFront=temp;
			TotalRare=temp;
		}
		else
		{
			TotalRare->Next=temp;
			TotalRare=temp;
		}
		printf("\n%s(ArrivalTime:%d) --> \t%d\t Added in Non-Arrived(Future Process) Queue\n",temp->Name,temp->ArrivalTime,temp->BurstTime);
	}	
}

void RemoveInWaitingQueue(char *n)
{
	struct Item *temp,*t;
	temp=TotalFront;
	
	if(TotalFront==NULL)
	{
		printf(RED "Unreachable Branch(1) In Execution Please Rerun the Code" RESET_Color "\n\n");
		exit(-1);
	}
	else if(TotalFront==TotalRare && strcmp(temp->Name,n)==0)
	{
		TotalFront=NULL;
		TotalRare=NULL;
		free(temp);
	}
	else if(strcmp(TotalFront->Name,n)==0)
	{
		TotalFront=TotalFront->Next;
		free(temp);
	}
	else
	{
		while(temp!=NULL && strcmp(temp->Next->Name,n)!=0 && temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		if(temp->Next==NULL && strcmp(temp->Name,n)==0)
		{
			printf(RED "Unreachable Branch(2) In Execution Please Rerun the Code" RESET_Color "\n\n");
			exit(-1);
		}
		else
		{
			t=temp->Next;
			temp->Next=t->Next;
			free(t);
		}
	}
}

void Remove()
{
	struct Item *temp;
	if(Front==NULL)
	{
		printf(RED "Some Issue Happened Please Re-run the Code" RESET_Color "\n\n");
		exit(-1);
	}
	else if(Front==Rare)
	{
		temp=Front;
		Front=NULL;
		Rare=NULL;
		free(temp);
	}
	else
	{
		temp=Front;
		Front=Front->Next;
		free(temp);
	}
}

void RemoveRandom(char *Na)
{
	struct Item *temp,*t;
	temp=Front;
	
	if(Front==NULL)
	{
		printf(RED "Unreachable Branch(3) In Execution Please Rerun the Code" RESET_Color "\n\n");
		exit(-1);
	}
	else if(Front==Rare && strcmp(temp->Name,Na)==0)
	{
		Front=NULL;
		Rare=NULL;
		free(temp);
	}
	else if(strcmp(Front->Name,Na)==0)
	{
		Front=Front->Next;
		free(temp);
	}
	else
	{
		while(temp!=NULL && strcmp(temp->Next->Name,Na)!=0 && temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		if(temp->Next==NULL && strcmp(temp->Name,Na)==0)
		{
			printf(RED "Unreachable Branch(4) In Execution Please Rerun the Code" RESET_Color "\n\n");
			exit(-1);
		}
		else
		{
			t=temp->Next;
			temp->Next=t->Next;
			free(t);
		}
	}
}

int CountItems()
{
	int r=0;
	struct Item *temp;
	
	temp=Front;
	while(temp!=NULL)
	{
		temp=temp->Next;
		r++;
	}
	
	return r;
}

void Display()
{
	struct Item *temp;
	if(Front!=NULL)
	{
		printf(BLUE "Current Queue:" RESET_Color "\n");
		temp=Front;
		while(temp!=NULL)
		{
			printf(BLUE "\t %s -->  %d ",temp->Name,temp->BurstTime);
			printf(RESET_Color "\n");
			temp=temp->Next;
		}
		printf("\n");
	}
	else
	{
		printf(BLUE "All ServiceMen Sleeping No New Process Arrived" RESET_Color "\n");
	}
}

void SearchItem(char *name)
{
	struct Item *temp;
	temp=Front;
	while(temp!=NULL && strcmp(temp->Name,name)!=0)
	{
		temp=temp->Next;
	}
	if(temp==NULL)
		printf(YELLOW "No Such Process In The Service Queue" RESET_Color "\n");
	else
	{
		printf(BLUE);
		printf("%s --> %d",temp->Name,temp->BurstTime);
		printf(RESET_Color"\n");
	}
}

void printInstructions()
{
	printf("Following Commands Will Be used in this Assignment:\n\n");
	printf("syntax: Add <Process_Name>\n\te.g.: Add T1\t:This will Add A Process With Name T1 and random Burst and Arrival Time\n");
	printf("syntax: Status <-all/-system/Process_Name>\n\te.g.: Status -all\t:This Will Show the status of all the process in the Queue With Current Service Time Required\n\t");
	printf("e.g.: Status T1\t\t:This will show the status of Process T1 only else will show unavailability if not in service Queue\n");
	printf("\te.g.: Status -system\t:This Will Show all the Current Default Variables like MaxArrivalTime,MaxBurstTime etc.\n");
	printf("syntax: MaxCustomer <Number>\n\te.g.: MaxCustomer 10\t:This will Make the system to hold maximum 10 Processes in the Queue\n");
	printf("\tNote: If the new MaxCustomer is less than the current Number of Processes in the Queue, this command will not Run\n");
	printf("syntax: ServiceMen <Number>\n\te.g.: MaxServicemen 2\t:This will Make No Of MaxServicemen as 2\n");
	printf("systax: MaxArrivalTime <Time>\n\te.g.: MaxArrivalTime 20 :This will assign vale of MaxArrivalTime as 20\n");
	printf("systax: MaxBurstTime <Time>\n\te.g.: MaxBurstTime 20 \t:This will assign vale of MaxBurstTime as 20\n");
	printf("systax: Help -info\n\te.g.: Help -info\t:This will Print This Info\n");
}

void DefaultValueDisplay()
{
	printf("\n\nMaxCustomer:\t%d\nServiceMen:\t%d\nMaxArrivalTime:\t%d\nMaxBurstTime:\t%d\n\n",
				Max_Processes,MaxServicemen,Max_ArrivalTime,Max_BurstTime);
}

void *UpdateQueue(void *vargp)
{
	struct Item *temp;
	while(1)
	{
		sleep(1);
		if(TotalFront==NULL)
		{
			
		}
		else
		{
			temp=TotalFront;
			while(temp!=NULL)
			{
				temp->ArrivalTime--;
				if(temp->ArrivalTime==0)
				{
					Insert(temp->Name,temp->BurstTime,temp->ArrivalTime);
					RemoveInWaitingQueue(temp->Name);
				}
				temp=temp->Next;
			}
		}
	}
}

void *ReadCommandLine(void *vargp)
{
	char Operater[10],Operand1[20];
	int Operand2;
	int isOperationWrong=0;
	
	while(1)
	{
		isOperationWrong=1;
		scanf("%s", Operater);
		if( strcmp(Operater, "Add") == 0 )
		{
			isOperationWrong=0;
			scanf("%s",Operand1);
			printf("%s %s\n",Operater,Operand1);
			
			InsertInWaitingQueue(Operand1);	
		}
		else if( strcmp(Operater,"Status")==0)
		{
			isOperationWrong=0;
			scanf("%s",Operand1);
			printf("%s %s\n",Operater,Operand1);
			if(strcmp(Operand1,"-all")==0)
			{
				Display();
			}
			else if(strcmp(Operand1,"-system")==0)
			{
				DefaultValueDisplay();
			}
			else
			{
				SearchItem(Operand1);
			}
		}
		
		else if(strcmp(Operater,"MaxCustomer")==0)
		{
			isOperationWrong=0;
			scanf("%d",&Operand2);
			printf("%s %d\n",Operater,Operand2);
			if(Operand2<1)
			{
				printf(YELLOW "MaxCustomer can't be les than 1" RESET_Color"\n");
			}
			else if(CountItems()>Operand2)
			{
				printf(RED "No Of Process in Queue is more than the value entered" RESET_Color"\n");
				isOperationWrong=1;
			}
			else
			{
				Max_Processes=Operand2;
			}
		}
		else if(strcmp(Operater,"ServiceMen")==0)
		{
			isOperationWrong=0;
			scanf("%d",&Operand2);
			printf("%s %d\n",Operater,Operand2);
			if(Operand2<1)
			{
				printf(YELLOW "MaxServicemen can't be les than 1" RESET_Color"\n");
			}
			if(Operand2>MaxServiceMan)
			{
				printf(RED "No Of Serviceman can't be more than MaxServiceMan(Update Source Code If required More)" RESET_Color"\n");
			}
			else if(Operand2<CurrentServiceMan)
			{
				printf(YELLOW);
				printf("Current Running Service Men is more than New Value\n%d Service man will go Out after Servicing Current Processes",Operand2-CurrentServiceMan);
				printf(RESET_Color"\n");
				MaxServicemen=Operand2;
			}
			else
			{
				MaxServicemen=Operand2;
			}
		}
		else if(strcmp(Operater,"MaxArrivalTime")==0)
		{
			isOperationWrong=0;
			scanf("%d",&Operand2);
			printf("%s %d\n",Operater,Operand2);
			if(Operand2<1)
			{
				printf(YELLOW "MaxArrivalTime can't be les than 1" RESET_Color"\n");
			}
			else
			{
				Max_ArrivalTime=Operand2;	
			}
		}
		else if(strcmp(Operater,"MaxBurstTime")==0)
		{
			isOperationWrong=0;
			scanf("%d",&Operand2);
			printf("%s %d\n",Operater,Operand2);
			if(Operand2<1)
			{
				printf(YELLOW "MaxBurstTime can't be les than 1" RESET_Color"\n");
			}
			else
			{
				Max_BurstTime=Operand2;	
			}
		}
		else if(strcmp(Operater,"Help")==0)
		{
			isOperationWrong=0;
			scanf("%s",Operand1);
			printf("%s %s\n",Operater,Operand1);
			
			if(strcmp(Operand1,"-info")==0)
			{
				printInstructions();
			}
			else
			{
				isOperationWrong=1;
			}
		}
		else
		{
			scanf("%s",Operand1);
		}
		
		if(isOperationWrong==1)
		{
			printf(RED "Not a Correct Input\n Type \"Help -info\" to know more" RESET_Color "\n\n");
		}
	}
}

void *RunningItem(void *SerManID)
{
	long SId = (long)SerManID;
	printf(CYAN "\t %ld: ServiceMan WokeUp",SId);
	printf(RESET_Color "\n");
	while(1)
	{
		if(StatusServicemen[SId]==1)
		{
			sleep(1);
			if(Front==NULL)
			{
				printf(CYAN "\t %ld: ServiceMan Going To Sleep",SId);
				printf(RESET_Color "\n");
				CurrentServiceMan--;
				StatusServicemen[SId]=0;
			}
			else
			{
				struct Item *temp;
				temp=Front;
				while(temp!=NULL && pthread_mutex_trylock(&temp->lockItem)!=0)
					temp=temp->Next;
				
				if(temp==NULL)
				{
					printf(CYAN "\t %ld: ServiceMan Going To Sleep",SId);
					printf(RESET_Color "\n");
					CurrentServiceMan--;
					StatusServicemen[SId]=0;
				}
				else
				{
					printf(CYAN "\t %ld: Started Processing %s",SId,temp->Name);
					printf(RESET_Color "\n");
					while(temp->BurstTime>0)
					{
						sleep(1);
						temp->BurstTime--;
					}
					printf(CYAN "\t %ld: Finished Processing %s; Removing from Queue",SId,temp->Name);
					printf(RESET_Color "\n");
					pthread_mutex_unlock(&temp->lockItem);
					RemoveRandom(temp->Name);
				}
			}
		}
		else if(StatusServicemen[SId]==0)
		{
			sleep(1);
		}
		else
		{
			break;
		}
	}
	printf(CYAN "\t %ld: ServiceCounter Going To Close(No of Serviceman Reduced)",SId);
	printf(RESET_Color "\n");
}

void *HandlingServiceMan(void *vargp)
{
	int NoOfActiveServiceMen=0;
	long NoOfAliveServiceMen=0;
	int TotalProcessNo;
	int i;
	pthread_t SId[MaxServiceMan];
	pthread_attr_t attr;
    pthread_attr_init(&attr);
	
	for(i=0;i<MaxServiceMan;i++)
	{
		StatusServicemen[i]=-1;
	}
	
	while(1)
	{
		sleep(1);
		TotalProcessNo=CountItems();
		while(NoOfAliveServiceMen< MaxServicemen && TotalProcessNo > NoOfAliveServiceMen)
		{
			pthread_create(SId+NoOfAliveServiceMen, &attr, RunningItem, (void *)NoOfAliveServiceMen);
			StatusServicemen[NoOfAliveServiceMen]=1;
			NoOfAliveServiceMen++;
			CurrentServiceMan++;
		}
		while(MaxServicemen<NoOfAliveServiceMen)
		{
			NoOfAliveServiceMen--;
			CurrentServiceMan--;
			StatusServicemen[NoOfAliveServiceMen]=-1;
			pthread_join(SId+NoOfAliveServiceMen,NULL);
		}
		while(NoOfAliveServiceMen>CurrentServiceMan && TotalProcessNo>CurrentServiceMan)
		{
			for(i=0;i<NoOfAliveServiceMen;i++)
			{
				if(StatusServicemen[i]==0)
				{
					printf(CYAN "\t %d: ServiceMan Waking Up",i);
					printf(RESET_Color "\n");
					StatusServicemen[i]=1;
					CurrentServiceMan++;
					break;
				}
			}
		}
	}
}

int main()
{
	int t=0;
	pthread_t tid, t1id,t2id;
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);
	
	pthread_create(&tid, &attr, ReadCommandLine, NULL);
	pthread_create(&t1id, &attr, UpdateQueue, NULL);
	pthread_create(&t2id, &attr, HandlingServiceMan, NULL);
    
	DefaultValueDisplay();
	printInstructions();
    pthread_join(tid, NULL);
    pthread_join(t1id, NULL);
    exit(0);
	
	return 0;
}
