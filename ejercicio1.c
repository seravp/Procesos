#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
if(argc != 2){
	perror("No ha introducido un numero: ejercicio1 <numero>");
	exit (-1);
}

pid_t pid;
int numero = atoi(argv[1]);

printf ("numero: %d\n", numero);

if( (pid=fork())<0) {
	perror("\nError en el fork");
	exit(-1);
}
else    if(pid==0) {  //proceso hijo ejecutando el programa
			if(numero % 2 ==0){
				printf ("Soy el hijo: El numero es par\n");
			}else
				printf ("Soy el hijo: El numero es impar\n");
	    }else{ //proceso padre ejecutando el programa
			if(numero % 4 == 0)
				printf("Soy el padre: El numero es divisible entre 4\n");
			else 
				printf("Soy el padre: El numero no es divisible entre 4\n");	
	  	}
exit(0);

}