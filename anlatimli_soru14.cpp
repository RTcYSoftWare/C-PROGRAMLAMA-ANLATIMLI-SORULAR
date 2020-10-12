#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>



int edmund[100]; // i�resinde random say� bulunduran 100 elemanl� diziyi tan�mlad�k.
int tek_indis[50] , cift_indis[50]; //tek ve �ift indise g�re say�lar� ay�r�p atayaca��m�z diziler. 



/*---- 0-1000 ARASINDA 100 ADET RANDOM SAYI �RET�P D�Z�YE ATAYAN FONKS�YON ----*/
void Random_Value(){
	
	int random_value = 0;
	srand(time(NULL)); 
	
	for(int i=0;i<100;i++){ // 100 adet random say� olu�turmam�z� sa�layan d�ng�
		random_value = rand()%1000; // random de�er olu�turduk
		edmund[i] = random_value; // de�eri diziye atad�k.
	}
}




/*---- D�Z� ELEMANLARINI SIRALIYACAK OLAN SELECT�ON SORT FONKS�YONU ----*/
void Selection_Sort(){

	int gecici;
	for(int i=0;i<50-1;i++){ // ilk d�ng�m�z 
		for(int j=i+1;j<50;j++){ // ikinci d�ng�m�z
			if(tek_indis[j]<tek_indis[i]){ // e�er ilk eleman ikinci elemandan b�y�kse.
				gecici = tek_indis[i]; // yer de�i�tirme i�lemleri yapt�k
				tek_indis[i] = tek_indis[j];
				tek_indis[j] = gecici;
			}
		}
	}
}



/*---- D�Z� ELEMANLARINI SIRALIYACAK OLAN INSERTION SORT FONKS�YONU ----*/
void Insertion_Sort(){

int gecici , j;
	
	for(int i=0;i<50;i++){ // ilk d�ng�m�z 
		gecici = cift_indis[i];
		j = i-1;
		while(j>-1 && cift_indis[j] < gecici ){ // e�er j indisli eleman ge�iciden k���kse 
			cift_indis[j+1] = cift_indis[j]; // yer de�i�tirme i�lemleri yapt�k.
			j--;
			cift_indis[j+1] = gecici;
		}
	}

}



/*---- INDIS KONTROL� YAPAN ve INDISLERE G�RE 2 AYRI D�Z�YE ATAYAN FONKS�YON ----*/
void Indis_Kontrol(){
	int c_indis = 0 , t_indis = 0;
	
	for(int i=0;i<100;i++){
		
		if(i%2 ==0){ // e�er random say�n�n indisi �ift ise
			cift_indis[c_indis] = edmund[i]; // �ift indis dizisine atad�k.
			c_indis++;
		}
		
		if(i%2 != 0){ // e�er random say�n�n indisi tek ise 
			tek_indis[t_indis] = edmund[i]; // tek indis dizisine atad�k.
			t_indis++;
		}
	}	
}



/*---- ANA FONKS�YONUMUZ ----*/
int main(){
	
	Random_Value(); // rastgele say� �reten fonksiyonumuzu �a��rd�k.
	printf("\t\t ****** RASTGELE SAYILAR OLUSTURULDU ****** \n");
	
	printf("\n");
	printf("\n");
	
	printf("****** RASTGELE SAYILARIN OLDUGU DIZI ****** \n");
	for(int i=0;i<100;i++){ // rastgele say�lardan olu�an diziyi ekrana yazd�rd�k.
		printf("\t %d \n",edmund[i]);
	}
	
	printf("\n");
	printf("\n");	
	
	Indis_Kontrol(); // indis kontrol� yapan fonksiyonumuzu �a��rd�k.
	printf("\t\t ****** INDIS KONTROLU YAPILDI VE INDISLERE GORE SAYILAR AYRILDI ****** \n");
	
	printf("\n");
	printf("\n");
	
	printf("****** AYRILAN TEK INDISLI DIZI ****** \n");
	for(int i=0;i<50;i++){ // tek indisli say�lar�n oldu�u diziyi ekrana yazd�rd�k.
		printf("\t %d \n",tek_indis[i]);
	}
	
	Selection_Sort();// tek indisli say�lar�n bulundu�u dizyi s�ralamas� i�in s�ralama algoritmam�z� �a��rd�k.
	printf("\t\t ****** TEK INDISLI DIZININ SIRALANMASI YAPILDI ****** \n");
		
	printf("\n");
	printf("\n");
	
	printf("****** SIRALANMIS TEK INDISLI DIZI ****** \n");
	for(int i=0;i<50;i++){ // s�ralanm�s tek indisli say�lar�n bulundu�u diziyi ekrana yazd�rd�k.
		printf("\t %d \n",tek_indis[i]);
	}
	
	printf("\n");
	printf("\n");
	
	printf("****** AYRILAN CIFT INDISLI DIZI ****** \n");
	for(int i=0;i<50;i++){ // �ift indisli say�lar�n oldu�u diziyi ekrana yazd�rd�k.
		printf("\t %d \n",cift_indis[i]);
	}
	
	Insertion_Sort(); // �ift indisli say�lar�n oldu�u diziyi s�ralamas� i�in s�ralama algoritmam�z� �a��rd�k.
	printf("\t\t ****** CIFT INDISLI DIZININ SIRALANMASI YAPILDI ****** \n");
	
	printf("\n");
	printf("\n");

	printf("****** SIRALANMIS CIFT INDISLI DIZI ****** \n");
	for(int i=0;i<50;i++){ // s�ralanm�s �ift indisli say�lar�n bulundu�u diziyi ekrana yazd�rd�k.
		printf("\t %d \n",cift_indis[i]);
	}
	
	printf("\n");
	printf("\n");	
	
	printf("****** PROGRAMIN CALISMASI BITMISTIR! ****** \n");
	printf("****** CIKIS ICIN LUTFEN 'ENTER' TUSUNA BASINIZ! ****** \n");
	
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A A�TT�R.
// KOPYALANMASI VEYA �O�ALTILMASI YASAKTIR.
