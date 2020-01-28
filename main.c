#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include "Hilmys.h"

int main(){
	Person Hilmys;
	init(&Hilmys, 5); //mungkin nilai inisialisasinya bisa di random dari 1 <= nilai <= 10
	/* Bagian Awal atau Keindahan Program */
	//Mulai
		printf("===========================\n");
		printf("Selamat datang di Hilmys's Life\n");
		printf("Nilai semua stat dari Hilmys adalah ");
		printf("%d", Health(Hilmys));
		printf("\n");
		printf("============================\n");
	//Selesai
	return 0;
}
