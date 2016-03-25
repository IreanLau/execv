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
	int i=0;
	for(;i<3;i++)
	{
		pid_t id=fork();
		if(id==0)
			printf("%d child\n",i);
		else
			printf("%d father\n",i);
	}
	return 0;
}
/*共14次，三次for的执行，相当与，第i+1次的for在第i次下执行，三次的fork嵌套，fork下的会执行两次；因此i==0的child ，father各一次，i==1各两次，i==2各四次*/
