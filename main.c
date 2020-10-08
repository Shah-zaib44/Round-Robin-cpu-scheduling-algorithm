            #include<stdio.h>
struct process
{
int name;
int at,bt,wt,tt,rt;
int completed;
int response;
float ntt;
}p[100];
int n;
int q[100];
  int k[100];
  int m[100];
  int z[100];
int front=-1,rear=-1;
int front1=-1,rear1=-1;
int front2=-1,rear2=-1;
int front3=-1,rear3=-1;
void enqueuepid(int t)
{
if(rear3==100-1)
printf("overflow");
rear3++;
z[rear3]=t;
if(front3==-1)
front3=0;
}
void displaytime()
{
    int l;
    if (front2 == - 1)
        printf("Queue is empty \n");
    else
    {
        for (l = front2; l <= rear2;l++ )
        {
             printf("[%d]-", m[l]);
if(z[l] == 33)
{

    printf("[--]-");
}
else{
    printf("[P%d]-", z[l]);
}
        }
        }
        }
void enqueuetime(int l)
{
if(rear2==100-1)
printf("overflow");
rear2++;
m[rear2]=l;
if(front2==-1)
front2=0;
}
void enqueueinq(int j)
{
if(rear1==100-1)
printf("overflow");
rear1++;
k[rear1]=j;
if(front1==-1)
front1=0;
}
void dequeueinq()
{

if(front1==rear1)
front1=rear1=-1;
else
front1++;
}
void displayq()
{
    int j;
    if (front1 == - 1)
        printf("Queue is empty");
    else
    {
        for (j = front1; j <= rear1; j++)
            printf("P%d,", k[j]);
    }
    printf("\n");
}
void enqueue(int i)
{
if(rear==100-1)
printf("overflow");
rear++;
q[rear]=i;
if(front==-1)
{


front=0;
}
printf("tum:%d",q[front]);
}
int dequeue()
{
if(front==-1)
return 24;
int temp=q[front];
if(front==rear)
front=rear=-1;
else
front++;
return temp;
}
int isInQueue(int i)
{int k;
for(k=front;k<=rear;k++)
{
if(q[k]==i)
return 1;
}
return 0;
}void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
if(p[i].at>p[j].at)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
void main()
{

int i,j,L,time=0,sum_bt=0,tq;
int c;
char rqueue[10];
        float avgwt=0;
 printf("Enter no of processes:");
 scanf("%d",&n);
 for(i=0,c=0;i<n;i++,c++)
 {
 p[i].name=c;
 printf("\nEnter the arrival time and burst time of process P%d: ",p[i].name);
 scanf("%d%d",&p[i].at,&p[i].bt);
 p[i].rt=p[i].bt;
 p[i].completed=0;
 sum_bt+=p[i].bt;
 p[i].response=-1;
}
int diff=1;
printf("\nEnter the time quantum:");
scanf("%d",&tq);
sortByArrival();
enqueue(0);
enqueueinq(0);
printf("QUEUE\n");
for(time=p[0].at;time<sum_bt+diff;)
{
displayq();

    i=dequeue();
    dequeueinq();
    if(p[i].response==-1)
{
    p[i].response=time;
}
    enqueuetime(time);
    if(i==24)
{
enqueuepid(33);
    i=L+1;
     if(p[i].completed==1)
     {
        while(p[i].completed==1)
        {
            i++;
     }
     }
while(p[i].at!=time)
{
time++;
diff++;
}
enqueuetime(time);
enqueue(i);
enqueueinq(i);
displayq();
i=dequeue();
 dequeueinq();
}
if(p[i].rt<=tq)
{
time+=p[i].rt;
p[i].rt=0;
p[i].completed=1;
 enqueuepid(p[i].name);
    rqueue[i]= p[i].name;
            p[i].wt=time-p[i].at-p[i].bt;
            p[i].tt=time-p[i].at;
             L=i;
            for(j=0;j<n;j++)
            {
            if(p[j].at<=time && p[j].completed!=1&& isInQueue(j)!=1)
            {
enqueue(j);
enqueueinq(j);
            }
           }
        }
    else
    {
    time+=tq;
    p[i].rt-=tq;
    enqueuepid(p[i].name);
    for(j=0;j<n;j++)
            {
            if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue(j)!=1)
             {
enqueue(j);
enqueueinq(j);
            }
           }
enqueue(i);
enqueueinq(i);
    }

}

printf("\n");
printf("GANTT CHART\n");
displaytime();
printf("[%d]",time);
float avgtt=0;
printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\tResponse Time");
for(i=0;i<n;i++)
{avgwt+=p[i].wt;
avgtt+=p[i].tt;
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt,p[i].response);
}
printf("\nAverage waiting time:%f\n",avgwt/n);
printf("\nAverage turnaround time time:%f\n",avgtt/n);
}




