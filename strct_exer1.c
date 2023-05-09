#include <stdio.h>

#ifndef USER_COM_ENA
	#define USER_COM_ENA
#endif

#include "exer_com.h"

int main(int argv, char *argc[])
{
	ST_SMPL	st_val = {'1','2',"Good morning!"};
	ST_SMPL *st_val_p = &st_val;

	printf("*** Init ****\n");

	printf("struct from=%c\n", st_val_p->from);
	printf("struct to=%c\n", st_val_p->to);
	printf("struct msg=%s\n",st_val_p->msg[0]);

	st_val.from = '3';
	st_val.to = '4';

	st_val.msg[0] == "Good afternoon!";

	printf("struct from=%c\n", st_val_p->from);
	printf("struct to=%c\n", st_val_p->to);
	printf("struct msg=%s\n",st_val_p->msg[0]);

	return 0;
}

