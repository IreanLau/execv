/*************************************************************************
	> File Name: wait.c
	> Author: Xixi
	> Mail: 985632368@qq.com 
	> Created Time: Sat 31 Oct 2015 10:57:28 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	pid_t id=fork();
	if(id<0)
	{
		perror("id");
		exit(1);
	}
	else if(id==0)
	{
		printf("this is child, pid:>%d ppid:>%d\n",getpid(),getppid());
		sleep(50);
		exit(1);
	}
	else
	{
		printf("this is father, pid:>%d ppid:>%d\n",getpid(),getppid());
		int status;
		//pid_t ret =waitpid(id,&status,0);
		pid_t ret =waitpid(1,&status,0);/*等待异常*/
		if(ret > 0)
		{
			if(WIFEXITED(status))/*正常退出*/
			{
				printf("happy, proc is ok\n");
				int code=WEXITSTATUS(status);
				if(code ==0)
				{printf("proc is success\n");}
				else if (code ==1){printf(" not success\n");}
				else{printf("other error\n");}
			}
			else{
				perror("problem happend");
			}
		//	printf("wait successed\n");
		}
		else
		{
			printf("this is not my son,%d \n",ret);
		}
	}
	return 0;
}

