#include<stdio.h>
void main()
{
			int oy;
        	int que[20],n,head,i,j,k,distance=0,range,subtract,store,que1[30],que2[30],store1=0,store2=0;
            float mean;
            range = 5000;
            head  = 143;
            n = 9;
            int h;
            printf("*****************check your disk scheduling***********");
            printf("\nRange of disk cylinder:%d",range);
            printf("\nHead position where the que is serving request:%d",head);
       		printf("\nThe pending request values in given FIFO order:86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130\n");
            int ar[10]= {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
            	for(i=0;i<n;i++)
            	{
                    if(ar[i]>=head)	
                        {
                            que1[store1]=ar[i];
                            store1++;
                        }
                        else
                        {
                            que2[store2]=ar[i];
                            store2++;
                        }
            	}
            	for(i=0;i<store1-1;i++)
            	{
                    for(j=i+1;j<store1;j++)
                        {
                            if(que1[i]>que1[j])
                            {
                                store=que1[i];
                                que1[i]=que1[j];
                                que1[j]=store;
                            }
                        }
            	}
            	for(i=0;i<store2-1;i++)
            	{
                	for(j=i+1;j<store2;j++)
                    {
                        if(que2[i]>que2[j])
                        {
                            store=que2[i];
                            que2[i]=que2[j];
                            que2[j]=store;
                        }
                    }
            	}
            	for(i=1,j=0;j<store1;i++,j++)
            	que[i]=que1[j];
            	que[i]=range;
            	que[i+1]=0;
            	for(i=store1+3,j=0;j<store2;i++,j++)
            	que[i]=que2[j];
            	que[0]=head;
            	for(j=0;j<=n+1;j++)
            	{
                    subtract=abs(que[j+1]-que[j]);
                    distance+=subtract;
                    printf("\n %d -->> %d with the subtract of %d\n",que[j],que[j+1],subtract);
            	}
            	printf("Total distance (in cylinders) that the disk arm moves to satisfy all the pending requests is:%d\n",distance);
			}

