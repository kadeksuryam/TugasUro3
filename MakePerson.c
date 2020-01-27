#include<stdio.h>
#include<stdlib.h>
#include "MakePerson.h"

void makePerson(Person *Unnamed){
	printf("Silahkan masukkan nama karakter:	(panjang karakter dari 1 sampai 100)\n");
	scanf("%s", GetName(*Unnamed));
}

