//* Assigning max resources required for each process ,condition 1.max resources is between 1,p *//
//*Given that condition 2.smax<p+q *//
//*Generating test cases which saticifies both conditions*//
#include<stdio.h>
void main()
{
int q,p,smax,sflag=0;
int i=0,j,flag[10],n=0,kill=0,sum=0,available=0;
int ui[10];
int max[10],alloc[10],need[10];
printf("Enter the no of processes:"); //q is no.of processes
scanf("%d",&q);
printf("Enter the no of resources:");//p is no.of resources
scanf("%d",&p);
smax=p+q;

for(i=0;i<q;i++)
{
//sum of all max[i]<p+q;
if(i==0)
{
max[i]=p-1;//random value which statisfies 2 conditions
}
else
{
max[i]=1;
}
}

//allocate resources to processes
for(i=0;i<q;i++)
{
if(i==0)
{
alloc[i]=p-2; //based on bankers algo to avoid deadlock
}
else
{alloc[i]=0;}
}

for(i=0;i<q;i++)
{
sum=alloc[i]+sum;
}
available=q-sum;

for(i=0;i<q;i++)
{
need[i]=max[i]-alloc[i];
}

while(n<=q)
{
for(i=0;i<q;i++)
{
if(need[i]<available)
{
available=available+need[i];
flag[i]=1;
n=n+1;
}

else
{flag[i]=0;}
}
for(i=0;i<q;i++)
{
if(flag[i]==1)
sflag=sflag+1;
}
if(sflag==0)
{
n=q+1;
kill=1;
}
}

if(kill==1){printf("Deadlock Occurred");}

else
{
	printf("Safe State");
}
}
