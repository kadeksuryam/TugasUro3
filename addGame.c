#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
#include<time.h>
#include "Hilmys.h"

void tebakAngka(Person *Hilmys){
	char pil;
	printf("======Selamat datang di Game Tebak Angka======\n");
	printf("Pada game ini Anda akan menebak angka oleh komputer\n");
	printf("Pada setiap langkahnya anda mencoba menebak angka dengan memasukkan angka dari 1 sampai 10\n");
	printf("Komputer akan merespon 'Angka tersebut kurang tinggi, silahkan pilih angka yang lebih tinggi' atau sebaliknya\n");
	printf("Batas maksimum penebakan angka adalah 4 langkah\n");
	printf("Jika selama game, uang anda kurang, Anda otomatis akan dikeluarkan dari game\n");
	printf("Anda boleh bertaruh uang dari minimum 1 maksimal 20 koin\n");
	printf("Apakah Anda ingin melanjutkan? [Y/N] : ");
	scanf(" %c", &pil);
	printf("\n");
	if(pil == 'Y'){
		int mny;
		srand(time(0));
		int sysNum = (rand()%9) + 1;
		printf("Silahkan masukkan berapa banyak koin yang ingin anda taruhkan: ");
		scanf(" %d", &mny);
		while(mny < 1 || mny > 20){
			printf("Silahkan masukkan nominal uang dengan benar!\n");
			printf("Silahkan masukkan berapa banyak koin yang ingin anda taruhkan: ");
			scanf(" %d", &mny);
		}
		if((*Hilmys).money < mny){
			printf("Maaf uang anda tidak cukup untuk melanjutkan game ini :( \n");
			return;
		}
		int cnt = 4;
		while(cnt){
			printf("Silahkan masukkan angka dari 1 sampai 10: ");
			int num; scanf(" %d", &num);
			if(num == sysNum){
				printf("Anda menang! Anda mendapatkan ");
				printf("%d", mny);
				printf(" koin\n");
				tambahStat(Hilmys, 0, 0, 0, mny, 0);
				return;
			}
			else{
				if(num < sysNum) printf("Angka tersebut kurang tinggi, silahkan pilih angka yang lebih tinggi!\n");
				else printf("Angka tersebut kurang rendah, silahkan pilih angka yang lebih rendah\n");
				cnt--;
			}
		}
		if(cnt == 0){
			printf("Maaf Anda Kalah!");
			kurangStat(Hilmys, 0, 0, 0, mny, 0);
			return;
		}
	}
}

void sticksGame(Person *Hilmys){
	//jumlah stick akan dirandom sesuai pilihan user
	//misalnya user ingin jumlah stick berada pada rentang a b, a <= sticks <= b
	//ini merupakan nim game sehingga ada strategi mutlak untuk menang
	//jika pemain dapat menemukan pola game ini, itu akan menjadi senjata ampuh untuk memenangkan game ini
	char lanjut;
	printf("======Selamat Datang di Game Sticks134======\n");
	printf("Pada game ini anda akan bermain 'Stick' dengan komputer\n");
	printf("Aturan bermainnya adalah sebagai berikut: ");
	printf("Pada setiap rondenya anda akan memilih rentang jumlah stick yang ingin dimainkan\n");
	printf("Misalnya anda memilih : 1 dan 10, yang artinya komputer akan memilih angka dari 1 sampai 10 secara random untuk dijadikan jumlah sticks\n");
	printf("Pada game ini jumlah minimum stick haruslah 10, maksimal 100\n");
	printf("Pada setiap langkahnya anda akan suit dengan komputer untuk menentukan pemain yang melangkah pertama\n");
	printf("Setelah jumlah stick ditentukan, pada setiap langkahnya pemain boleh memilih 1,3, atau 4 stick untuk dibuang\n");
	printf("Pemain pertama yang tidak bisa membuang stick akan kalah\n");
	printf("Anda boleh bertaruh uang dari minimum 1 maksimal 50 koin\n");
	printf("Apakah anda ingin melanjutkan? [Y/N] : ");
	scanf(" %c" , &lanjut);
	if(lanjut == 'Y'){
		int l, r, mny; //rentang, uang
		//==================PENGECEKAN UANG=======================
		printf("Silahkan masukkan berapa banyak koin yang ingin anda taruhkan: ");
		scanf(" %d", &mny);
		while(mny < 1 || mny > 50){
			printf("Silahkan masukkan nominal uang dengan benar!\n");
			printf("Silahkan masukkan berapa banyak koin yang ingin anda taruhkan: ");
			scanf(" %d", &mny);
		}
		if((*Hilmys).money < mny){
			printf("Maaf uang anda tidak cukup untuk melanjutkan game ini :( \n");
			return;
		}
		
	//==================Inisialisasi dan Algoritma komputer bermain=====================
		printf("Silahkan masukkan rentang dari stick [10 sampai 100]: \n");
		do{
			printf("Minimum Stick: ");
			scanf(" %d", &l);
			printf("Maksimum Stick: ");
			scanf(" %d", &r);
			if(l < 10 || r > 100) printf("Silahkan masukkan jumlah stick dengan benar!\n");
		}while(l < 10 || r > 100);
		srand(time(0));
		int jumlah = (rand()%(r-l+1) + l);
		printf("%s%d", "Jumlah stick yang akan dimainkan adalah : ", jumlah); 
		printf("\n");
		//======Algoritma yang digunakan oleh komputer untuk mencapai kemenangan========
		//definisi dp[i] : apakah mungkin mencapai kemenangan saat jumlah stick adalah i
		int stick[3] = {1, 3, 4};
		bool *dp = (bool*)malloc(sizeof(bool)*(jumlah+1)); 
		for(int i=0;i<=jumlah;i++) dp[i] = false;
		dp[1] = true;
		for(int i=2;i<=jumlah;i++){
			for(int j=0;j<3;j++){
				if(i-stick[j] >= 0) if(!dp[i-stick[j]]) dp[i] = true; 
			}
		}
	//==============SUIT KOMPUTER DENGAN USER============
		srand(time(0));
		char pilSuit[3] = {'B', 'K', 'G'};
		char suit;
		printf("Pertama-tama silahkan suit terlebih dahulu dengan komputer\n");
		printf("Silahkan Pilih B untuk Batu, K untuk Kertas, G untuk gunting: ");
		scanf(" %c", &suit);
		printf("Pilihan komputer adalah : ");
		char suitKomputer = pilSuit[rand()%3];
		bool cekSuitUser = false;
		printf("%c", suitKomputer);
		printf("\n");
		if(suitKomputer == 'B'){
			if(suit == 'K') cekSuitUser = true;
		}
		else if(suitKomputer == 'G'){
			if(suit == 'B')	cekSuitUser = true;	
		}
		else{
			if(suit == 'G') cekSuitUser = true;			
		}
		
	//==============================PROSES GAME========================
		if(cekSuitUser){ //Ketika user menang suit
			printf("Anda menang suit! Silahkan memulai terlebih dahulu!\n");
			while(true){
				int stickPil;
				printf("\n=====Giliran Anda====\n");
				printf("Berapa stick yang akan anda buang 1, 3, atau 4?\n");
				scanf("%d", &stickPil);
				if((stickPil == 1 || stickPil == 3 || stickPil == 4) && jumlah-stickPil >= 0){
					jumlah -= stickPil;
					printf("Stick Sekarang adalah : ");
					printf("%d", jumlah);
					if(jumlah == 0){
						printf("\nAnda menang!\n");
						tambahStat(Hilmys, 0, 0, 0, mny, 0);
						break;
					}
					printf("\n====Giliran Komputer====\n");
					bool cekstcKomputer = false;
					for(int i=0;i<3;i++){
						if(jumlah-stick[i] >= 0){
							if(!dp[jumlah-stick[i]]){
								printf("Komputer memilih membuang : ");
								printf("%d%s", stick[i], " stick\n");
								jumlah -= stick[i];
								cekstcKomputer = true;
								break;
							}
						}
						
					}
					if(!cekstcKomputer){
						//jika tidak mungkin menang saat stick jumlah, maka komputer selalu memilih 1
						printf("Komputer memilih membuang : ");
						printf("%d%s", stick[0], " stick\n");
						jumlah -= stick[0];
					}
					printf("Stick Sekarang adalah : ");
					printf("%d", jumlah);
					if(jumlah == 0){
						printf("\nAnda Kalah!\n");
						kurangStat(Hilmys, 0, 0, 0, mny, 0);
						break;
					}
				}
				else printf("Silahkan pilih jumlah stick dengan benar!\n");
			}
		}
		else{ //Ketika user kalah suit
			printf("Anda kalah suit! Silahkan memulai kedua!\n");
			while(true){
				printf("====Giliran Komputer====\n");
				bool cekstcKomputer = false;
				for(int i=0;i<3;i++){
					if(!dp[jumlah-stick[i]]){
						printf("Komputer memilih membuang : ");
						printf("%d%s", stick[i], " stick\n");
						jumlah -= stick[i];
						cekstcKomputer = true;
						break;
					}
				}
				if(!cekstcKomputer){
					//jika tidak mungkin menang saat stick jumlah, maka komputer selalu memilih 1
					printf("Komputer memilih membuang : ");
					printf("%d%s", stick[0], " stick\n");
					jumlah -= stick[0];
				}
				printf("Stick Sekarang adalah : ");
				printf("%d", jumlah);
				printf("\n");
				if(jumlah == 0){
					printf("Anda Kalah!\n");
					kurangStat(Hilmys, 0, 0, 0, mny, 0);
					break;
				}
				int stickPil;
				printf("\n=====Giliran Anda====\n");
				printf("Berapa stick yang akan anda buang 1, 3, atau 4?\n");
				scanf("%d", &stickPil);
				while(!(stickPil == 1 || stickPil == 3 || stickPil == 4) || jumlah-stickPil < 0){
					printf("Silahkan pilih jumlah stick dengan benar!\n");
					printf("Berapa stick yang akan anda buang 1, 3, atau 4?\n");
					scanf("%d", &stickPil);
				}
				jumlah -= stickPil;
				printf("Stick Sekarang adalah : ");
				printf("%d", jumlah);
				printf("\n");
				if(jumlah == 0){
					printf("Anda Menang!\n");
					tambahStat(Hilmys, 0, 0, 0, mny, 0);
					break;
				}
			}
		}
	} 
}

int comb(int n, int k){
	int res = 1;
	if(k == n) return 1;
	else{
		for(int i=n;i>=k+1;i--) res *= i;
		for(int i=1;i<=(n-k);i++) res /= i;
	}
	return res;
}

void soal(Person *Hilmys){
	printf("\nSoal Pertama\n");
	srand(time(0));
	int jumlahBenar=0; int pilSoal2;
	printf(" Pak Zaki memiliki n buah permen yang akan dibagikan kepada 3 orang cucunya, yaitu Abi, ");
	printf("Bibi, dan Cibi.\n Permen yang dibagikan tidak bersisa. Dalam pembagian tersebut bisa saja ada ");
	printf("cucu yang tidak mendapatkan permen sama sekali.\n Tentu saja, satu permen tidak bisa dibagi");
	printf("kepada lebih dari satu orang.\n Karena Cibi merupakan cucu kesayangan Pak Zaki, maka Cibi ");
	printf("selalu mendapat lebih dari 6 permen.\n Berapakah banyak cara Pak Zaki membagikan permen ");
	int jumlah = rand()%4 + 12;
	printf("%s%d%s", "tersebut ke cucu­ cucunya?, jika n bernilai ", jumlah, " : ");
	int ans1user, ans1com = comb(jumlah-7+2, 2);
	scanf(" %d", &ans1user);
	if(ans1user == ans1com){
		printf("Jawaban Anda Benar :) \n");
		jumlahBenar++;
	}
	else printf("Maaf Jawaban Anda Salah :( \n");
	printf("\nSoal Kedua\n");
	printf("Di suatu pulau misterius terdapat 2 macam orang, prajurit dan pencuri.\n");
	printf("Sang prajurit selalu berkata jujur dan sang pencuri selalu berkata bohong.\n");
	printf("Suatu hari Anda bertemu tiga orang yang berkata seperti berikut:\n");
	printf("A: Hanya satu diantara kami yang merupakan prajurit\n");
    printf("B: Setidaknya satu dari antara kita adalah prajurit\n");
    printf("C: A bukanlah prajurit\n");
    printf("Dari ketiga orang tersebut, berapa banyak yang merupakan prajurit? : ");
	scanf(" %d", &pilSoal2);
	if(pilSoal2 == 2){
		printf("Jawaban anda benar :) \n");;
		jumlahBenar++;
	}
	else printf("Jawaban anda Salah :( \n");
	kurangStat(Hilmys, 5, 0, 0, 0, 0); 
	tambahStat(Hilmys, 0, 0, 0, 10*jumlahBenar, 0);
}
