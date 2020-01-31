#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<time.h>
#include "Hilmys.h"

int main(){
	Person Hilmys; activities Act; 
	init(&Hilmys, &Act,  5); //mungkin nilai inisialisasinya bisa di random dari 1 <= nilai <= 10
	/* Bagian Awal atau Keindahan Program */
	//Mulai
		printf("|========================================= Selamat datang di Hilmys's Life ===============================================|\n");
		printf("| Tujuan game ini adalah membuat semua stat Hilmys menjadi 100                                                            |\n");
		printf("| Pada awalnya, semua stat Hilmys akan bernilai 5, kecuali uang yang awalnya 50 koin jadi gunakan dengan baik             |\n");
		printf("| Setiap kegiatan memiliki 'Harga' yang harus dibayar, jika kegiatan tersebut berhasil dilakukan maka stat akan bertambah |\n");
		printf("| Disaat salah satu stat anda bernilai 0, anda akan langsung kalah                                                        |\n");
		printf("| [Catatan : Durasi game ini adalah 15 menit setelah 15 menit Hilmys akan meninggal dunia dan Anda otomatis akan kalah!]  |\n");
		printf("|=========================================================================================================================|\n\n");
		printf("Press Any Key to Continue...");
		getchar();
	//Selesai
		printf("GAME DIMULAI!!!!!\n\n");
		pilihKegiatan(&Hilmys, &Act);
		printf("Terimakasih telah bermain Hilmys's Game\n");
		printf("===========================================================================================================================\n");
		getchar();
	//Selesai
	return 0;
}
