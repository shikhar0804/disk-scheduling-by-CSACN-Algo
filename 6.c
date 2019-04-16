#include<stdio.h>
#include<conio.h>
void main()
{
 int arriving[100],burst[100],rt[100];
 int t = 3;
 int wait[100],turnaround[100],completion[100];
 int i,j,smallest,starting_process=0,time,n;
 double mean=0,tt=0,end;
 printf("\nEnter the number of Processes: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
   printf("\nEnter arrival time of process %d : ",i+1);
   scanf("%d",&arriving[i]);
 }
 for(i=0;i<n;i++)
 {
   printf("\nEnter burst time of process %d : ",i+1);
   scanf("%d",&burst[i]);
 }
 for(i=0;i<n;i++)
 rt[i]=burst[i];

  burst[99]=9999;
 
 for(time=0;starting_process!=n;time++)
 {
  smallest=99;
  for(i=0;i<n;i++)
  {
   if(arriving[i]<=time && burst[i]<burst[smallest] && burst[i]>0 )
   smallest=i;
  }
    burst[smallest]--;
  if(burst[smallest]==0)
  {
   starting_process++;
   end=time+1;
   completion[smallest] = end;
   time=time+3;
   wait[smallest] = end - arriving[smallest] - rt[smallest];
   turnaround[smallest] = end - arriving[smallest];
  }
 }
 {
 printf("#################################################################\n");
 printf("|  pid\t | burst| arrival|\t wait\t|\tturnaround\t| completion\t|\n");
 printf("|********|$$$$$$|@@@@@@@@|^^^^^^^^^^^^^^^^^^^^^^|&&&&&&&&&&&&&&&&&&&&&&&&|!!!!!!!!!!!!!!!|\n");
 for(i=0;i<n;i++)
 {
   printf("\n|  P%d\t |  %d\t|  %d\t |\t   %d\t\t|\t   %d\t\t| \t%d\t|",i+1,rt[i],arriving[i],wait[i],turnaround[i],completion[i]);
   mean = mean + wait[i];
   tt = tt + turnaround[i];
 }
  printf("\n|________|______|________|______________________|_______________________|_______________|\n");
 printf("\n\nAverage waiting time = %lf\n",mean/n);
 printf("Average Turnaround time = %lf",tt/n);
 getch();
 }
}

