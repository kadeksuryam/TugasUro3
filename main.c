#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<time.h>
#include "Hilmys.h"

int main(){
	Person Hilmys; activities Act; time_t start, end;
	init(&Hilmys, &Act,  5); //mungkin nilai inisialisasinya bisa di random dari 1 <= nilai <= 10
	/* Bagian Awal atau Keindahan Program */
	//Mulai
		printf("===========================\n");
		printf("Selamat datang di Hilmys's Life\n");
		printf("Tujuan game ini adalah membuat semua stat Hilmys menjadi 100\n");
		printf("Pada awalnya, semua stat Hilmys akan bernilai 5, jadi gunakan dengan baik\n");
		printf("Setiap kegiatan memiliki stats yang harus dibayar, jika kegiatan tersebut berhasil dilakukan maka stat akan bertambah\n");
		printf("Disaat salah satu stat anda bernilai 0, anda akan langsung kalah\n");
		printf("Catatan : Durasi game ini adalah 15 menit setelah 15 menit Hilmys akan meninggal dunia dan Anda otomatis akan kalah!\n");
		printf("Press Any Key to Continue...");
		getchar();
		start = time(NULL);
		while(!cekWinning(&Hilmys)){
			int pil;
			printf("Silahkan pilih kegiatan yang ingin dilakukan: \n");
			printf("1. Tidur	2. Makan\n");
			printf("3. Mandi	0. Stats\n");
			printf("-1. Poin untuk setiap kegiatan\n");
			printf("Pilihan Anda [dalam angka diatas]: ");
			scanf("%d", &pil);
			if(cekLosing(&Hilmys)){
				printf("Anda Kalah :( \n");
				break;
			}
			if(pil == 1){
				doTidur(&Hilmys, &Act);
				printf("Tidur sudah Selesai\n");
			}
			else if(pil == 0){
				printStat(&Hilmys, &Act);
			}
			else printf("Pilihan yang anda masukkan salah silahkan pilih kegiatan kembali\n");
			end = time(NULL);
			if(difftime(end, start) == 900){
				printf("Hilmys sudah meninggal, Anda Kalah!\n");
				break;
			}
		}
		printf("Terimakasih telah bermain Hilmys's Game, Semoga Setelah Mencapai Stat tersebut kehidupan Hilmys menjadi lebih baik :)\n");
		printf("============================\n");
		getchar();
	//Selesai
	return 0;
}
