#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include "Hilmys.h"

int mini(int a, int b){
	if(a <= b) return a;
	else return b;
}

void pilihKegiatan(Person *Hilmys, activities *Act){
	time_t start = time(NULL);
		while(!cekWinning(Hilmys)){
		//=====input kegiatan oleh user====
			int pil; bool cekTidur = true, cekMakan = true, cekMCK = true; time_t snt_tidur=start, snt_makan=start, snt_mck=start;
			printf("\nSilahkan pilih kegiatan yang ingin dilakukan: \n");
			printf("1. Tidur	2. Makan\n");
			printf("3. Mandi	0. Stats\n");
			printf("-1. Aturan Poin untuk setiap kegiatan\n");
			printf("Pilihan Anda [dalam angka diatas]: ");
			scanf("%d", &pil);
			
		//=============If else berbagai kegiatan=========
			if(cekLosing(Hilmys)){
				printf("Anda Kalah :( \n");
				break;
			}
			if(pil == 1){
				doTidur(Hilmys, Act);
				if(!cekTidur) cekTidur = true;
				snt_tidur = time(NULL);
				printf("Tidur sudah Selesai\n");
			}
			else if(pil == 2){
				doMakan(Hilmys, Act);
				if(!cekMakan) cekMakan = true;
				snt_makan = time(NULL);
				printf("Makan sudah selesai\n");
			}
			else if(pil == 3){
				doMCK(Hilmys, Act);
				if(!cekMCK) cekMCK = true;
				snt_mck = time(NULL);
				printf("MCK sudah selesai\n");
			}
			else if(pil == 0){
				printStat(Hilmys, Act);
			}
			else if(pil == -1){
				//Dokumentasi aturan poin
			}
			else printf("Pilihan yang anda masukkan salah silahkan pilih kegiatan kembali\n");
			
			//======Pegecekan berbagai prasyarat===========
			time_t end = time(NULL);
		//================PRASYARAT UNTUK TIDUR===================
			//Jika sudah durasi sebelum tidur sudah 5 menit Hilmys harus tidur
			if(((int)difftime(end, snt_tidur))%300 == 0){
				char pil;
				printf("%d%s", (int)difftime(end, start)/60, " menit sudah lewat, Hilmys mengantuk dan perlu tidur untuk kesehatannya!\n");
				printf("Jika tidak tidur tingkat kesehatan hilmy akan berkurang 1 setiap detiknya!\n");
				printf("Pilih Y jika setuju untuk tidur dan N untuk tidak \n");
				scanf("%c", &pil);
				if(pil == 'Y') doTidur(Hilmys, Act);
				else{
					 snt_tidur = time(NULL);
					 cekTidur = false;
				}
			}
			//Jika tidak tidur setiap <= menit, Health hilmy akan berkurang 1 setiap detiknya	
			if(!cekTidur) (*Hilmys).health -= difftime(end, snt_tidur);
			
			
		//=================PRASYARAT UNTUK MAKAN=======================
			//Jika durasi sebelum makan sudah 3 menit maka Hilmys harus makan
			if(((int)difftime(end, snt_makan))%180 == 0){
				char pil;
				printf("%d%s", (int)difftime(end, start)/60, " menit sudah lewat, Hilmys mengantuk dan perlu tidur untuk kesehatannya!\n");
				printf("Jika tidak tidur tingkat kesehatan hilmy akan berkurang 1 setiap detiknya!\n");
				printf("Pilih Y jika setuju untuk tidur dan N untuk tidak \n");
				scanf("%c", &pil);
				if(pil == 'Y') doMakan(Hilmys, Act);
				else{
					 snt_makan = time(NULL);
					 cekMakan = false;
				}
			}
			//Jika makan tidur setiap <= menit, Health hilmy akan berkurang 1 setiap detiknya
			if(!cekMakan) (*Hilmys).health -= difftime(end, snt_makan);
		//=================PRASYARAT UNTUK MCK=======================
			//Jika durasi sebelum makan sudah 4 menit maka Hilmys harus makan
			if(((int)difftime(end, snt_mck))%240 == 0){
				char pil;
				printf("%d%s", (int)difftime(end, start)/60, " menit sudah lewat, Hilmys mengantuk dan perlu tidur untuk kesehatannya!\n");
				printf("Jika tidak tidur tingkat kesehatan hilmy akan berkurang 1 setiap detiknya!\n");
				printf("Pilih Y jika setuju untuk tidur dan N untuk tidak \n");
				scanf("%c", &pil);
				if(pil == 'Y') doMCK(Hilmys, Act);
				else{
					 snt_mck = time(NULL);
					 cekMCK = false;
				}
			}
			//Jika makan tidur setiap <= menit, Health hilmy akan berkurang 1 setiap detiknya
			if(!cekMakan) (*Hilmys).health -= difftime(end, snt_mck);
		//=================PRASYARAT WAKTU BERMAIN=================
			//Jika waktu bermain user sudah 15 menit otomatis kalah
			if(difftime(end, start) == 900){
				printf("Hilmys sudah meninggal, Anda Kalah!\n");
				break;
			}
		}
		
}

void doTidur(Person *Hilmys, activities *Act){
	bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).Tidur.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).Tidur.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).Tidur.hygienicReq) && isEnoughStat(Money(*Hilmys), (*Act).Tidur.moneyReq));
	if(canIt) tambahStat(Hilmys, 5, 0, 0, 0);
	return;	 	 
}

void doMakan(Person *Hilmys, activities *Act){
	int pil; 
	printf("Pilih makanan yang akan dimakan Hilmys. Silahkan pilih sesuai nomor yang tertera.\n");
	printf("[Catatan : Harga berbanding lurus dengan pertambahan Health Hilmys]\n");
	printf("======Daftar Harga Makanan=======\n");
	printf("|   Makanan     |      Harga    |\n");
	printf("| 1. Mie Instan	|      5 Koin   |\n");
	printf("| 2. Pizza      |     15 Koin   |\n");
	printf("| 3. Ramen      |     20 Koin   |\n");
	scanf("%d", &pil);
	if(pil == 1){
		bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).Makan.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).Makan.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).Makan.hygienicReq) && isEnoughStat(Money(*Hilmys), 5));
		if(!canIt) printf("Stat anda tidak mencukupi, silahkan sesuaikan dengan syarat yang diberikan\n");
		else kurangStat(Hilmys, (*Act).Makan.healthReq , (*Act).Makan.socialReq, (*Act).Makan.hygienicReq, 5);
		
	}
	else if(pil == 2){
		bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).Makan.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).Makan.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).Makan.hygienicReq) && isEnoughStat(Money(*Hilmys), 15));
		if(!canIt) printf("Stat anda tidak mencukupi, silahkan sesuaikan dengan syarat yang diberikan\n");
		else kurangStat(Hilmys, (*Act).Makan.healthReq , (*Act).Makan.socialReq, (*Act).Makan.hygienicReq, 15);
	}
	else if(pil == 3){
		bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).Makan.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).Makan.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).Makan.hygienicReq) && isEnoughStat(Money(*Hilmys), 20));
		if(!canIt) printf("Stat anda tidak mencukupi, silahkan sesuaikan dengan syarat yang diberikan\n");
		else kurangStat(Hilmys, (*Act).Makan.healthReq , (*Act).Makan.socialReq, (*Act).Makan.hygienicReq, 20);
	}
	return;	
}

void doMCK(Person *Hilmys, activities *Act){
	
	bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).MCK.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).MCK.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).MCK.hygienicReq) && isEnoughStat(Money(*Hilmys), (*Act).MCK.moneyReq));
	if(canIt){
		kurangStat(Hilmys, (*Act).MCK.healthReq , (*Act).MCK.socialReq, (*Act).MCK.hygienicReq, (*Act).MCK.moneyReq);
		tambahStat(Hilmys, 5, 0, 20, 0);
	}
	return;
} 

