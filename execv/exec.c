/*************************************************************************
	> File Name: exec.c
	> Author: Xixi
	> Mail: 985632368@qq.com 
	> Created Time: Sat 31 Oct 2015 12:12:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define FILE_NAME "log"
int main(int argc,char* argv[])
{
	pid_t id =fork();
	if(id<0)
	{
		perror("fork");
		exit(1);
	}
	else if(id ==0)
	{
		char* my_env[]={"PATH:/home/lau/project/10_31/execv",NULL};
		sleep(3);
		//execl("/bin/ls","ls","-l",NULL);
		//execl("/bin/touch","touch",FILE_NAME,NULL);
		//execle("print","print",NULL,my_env);
		char* my_arg[]={"ls","-l",NULL};
		//execv("/bin/ls",my_arg);
		execvp("ls",my_arg);
	}
	else
	{
		printf("father begin wait... \n");
		pid_t childid=waitpid(id,NULL,0);
		if(childid == id)
		{
			printf("wait succeed\n");
		}
		else
		{
			printf("wait failed\n");
		}
	}
	printf("you should not run here\n");
	return 0;
}

