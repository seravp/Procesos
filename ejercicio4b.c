#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int i;
	int hijos_vivos = 0;
	int estado;
	int hijo;
	pid_t id_actual;
	pid_t pidpadre = getpid();
	
	for(i = 0; i < 5; i++)
	{
		if(pidpadre == getpid())
		{
			if((id_actual = fork()) < 0)
			{
				perror("\nError en el fork");
				exit(-1);
			}
			else
				hijos_vivos++;
		}
	}
	
	if(getpid() != pidpadre)
	{
		printf("Soy el hijo %d\n", getpid());
	}
	else
	{
		sleep(1);
		while(hijos_vivos != 0)
		{
			if((hijo = wait(&estado)) < 0)
			{
				perror("\nError en wait");
				exit(-1);
			}
			else
			{
				printf("\nAcaba de finalizar mi hijo con %d\n", hijo);
				hijos_vivos--;
				printf("Sólo me quedan %d hijos vivos\n", hijos_vivos);
			}
		}
	}
	
	return 0;
}
