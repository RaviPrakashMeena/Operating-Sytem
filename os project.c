#include<stdio.h>

#include<conio.h>

#include<string.h>


void main()

{
	char name[10][5];
	char temp[5];
	int i;
	int j;
	int priority1[10];
	int waiting_time[10];
	int totalwt = 0;
	int priority2[10];
	int temp_1;
	int n;
	float averagewt;
	printf("Enter no of students:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("student %d name:",i+1);
  		scanf("%s",&name[i]);
		printf("enter time for P1:");
		scanf("%d",&priority1[i]);
		printf("enter no of gifts:");
		scanf("%d",&priority2[i]);
	}
  	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(priority2[i]>priority2[j])
			{
				temp_1=priority2[i];
				priority2[i]=priority2[j];
				priority2[j]=temp_1;
				temp_1=priority1[i];
				priority1[i]=priority1[j];
				priority1[j]=temp_1;
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	}
	waiting_time[0]=0;
	for(i=1;i<n;i++)
	{
		waiting_time[i]=waiting_time[i-1]+waiting_time[i-1];
		totalwt=totalwt+waiting_time[i];
	}
	averagewt=(float)totalwt/n;
	printf("G_name\t P_time\t No.Gifts\tW_time\n");
	for(i=0;i<n;i++)
	{
	   printf(" %s\t %d\t %d\t \t%d\n" ,name[i],priority1[i],priority2[i],waiting_time[i]);
	}
	printf("total waiting time=%d\navg waiting time=%f",totalwt,averagewt);
	getch();
}

