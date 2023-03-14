#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <fcntl.h>
pthread_mutex_t lock;
int start=0;
//dilonume tis  global metavlites oi opoies einai prosvasimes padou

int fds[3];
int global[26];
const char *semName = "asd";
sem_t *sem_filelock;
void* func(void *arg);
char randomchar()
{
char randChar =' ';
int counter = 0;
int randNum = 0;
int status;
randNum=26*(rand()/(RAND_MAX+1.0));
randNum= randNum + 97;
randChar=(char)randNum;
return randChar;
}



int main()

{
sem_filelock = sem_open(semName, O_CREAT, 0600, 1);



int fd = open("data.txt",O_CREAT|O_RDWR|O_APPEND|O_TRUNC,00700);



    int pid=fork();
    if (pid!=0){

        //perimenoume to paidi na ektelestei
        int status;

        waitpid(pid,&status,0);
        if(WIFEXITED(status))
        {
        printf("ekteleite i diergasia anagnosis\n");
         close(fd);
        int fdi;

         fdi=open("data.txt",O_RDONLY,00700);

        int fds[4];

        for(int i =0;i<4;i++)
        {
            fds[i]=dup(fdi);
        }
close(fdi);



sem_wait(sem_filelock);
int tmp;
pthread_t threads[3];
pthread_attr_t attr;

for(int i=0;i<4;i++)
{


  tmp=pthread_create(&threads[i],NULL,&func,&fds[i]);

  sleep(3);
if(tmp!=0)                                                         //dimiourgia kai ektelesi ton threads
{
fprintf(stderr,"failed to create thread %d\n",i);
}
else{
printf("thread executed %d \n",i);
}

pthread_join(threads[i],NULL);

}
int sum=0;

for(int i=0;i<26;i++)
{
printf("to gramma %c emfanistike %d fores \n",i+97,global[i]);
sleep(1);
}








sem_post(sem_filelock);


        printf("klinoume tous simaforous..\n");

pthread_mutex_destroy(&lock);                   //klinoume tous simaforous

sem_close(sem_filelock);
}
else
{
printf("wait failed");
}

    } else {
    printf("ekteleite i diergasia eggrafis\n");
        srand(time(NULL));
char buff[1999];

for(int i=0;i<1999;i++)
{
    buff[i]=randomchar();
}
sem_wait(sem_filelock);
write(fd,buff,strlen(buff));
sem_post(sem_filelock);

    sleep(10);}

        return 0;
}



void* func(void *arg)
{

char buff[500];
int *fd=arg;


int local[26]={0};
lseek(*fd,start,SEEK_SET);
int temp;
pthread_mutex_lock(&lock);


read(*fd,&buff,sizeof(buff));
int sum=0;
for(int i=0;i<500;i++)
{
temp=(int)buff[i];
                                       //prosthetoume sta local ta stixeia tou nimatos
local[temp-97]=local[temp-97]+1;

}

for(int i=0;i<26;i++)
{

// prosthetoume stin kedriki domi ta apotelesmata tou nimatos

global[i]=global[i]+local[i];
}



pthread_mutex_unlock(&lock);
start=start+499;
close(*fd);
}


