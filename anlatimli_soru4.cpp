#include<stdio.h>
#include<conio.h>
#include<string.h>


int main(){
	
	char metin[100] , degisen_metin[100];
	int metin_boyutu = 0;
	
	printf("DEGISTIRILECEK OLAN METNI GIRINIZ !!! \n");  //ekrana bilgi yazd�k
	gets(metin); // kullan�c�dan metin ald�K  ---- 2.ad�m
	
	printf("KULLANICININ GIRDIGI METIN = %s \n\n",metin);  //ekrana bilgi yazd�k
	
/*---- GIRILEN METNIN BOYUTUNU BULMA ----*/
	for(int i=0;metin[i]!=NULL;i++){ // ---- 3.ad�m
		metin_boyutu++;
	}
	
	/*---- GIRILEN METINDEKI HARFLERI DEGISTIRME ----*/
	for(int i=0;i<=metin_boyutu;i++){ // ---- 4.ad�m
		
		if(metin[i]>=65 && metin[i]<=90){ // harf degi�ikli�i �art� ---- 5.ad�m
			degisen_metin[i] = metin[i]+32; // harf de�i�tirerek yeni diziye atad�k ---- 5.ad�m
		}
		else{
			degisen_metin[i] = metin[i]-32; // harf de�i�tirerek yeni diziye atad�k
		}
	}
	
	
	printf("DUZENLENMIS METIN !!! \n"); //ekrana bilgi yazd�k
	for(int i=0;i<metin_boyutu;i++){
		printf("%c",degisen_metin[i]); // deg�sm�s d�z�y� yazd�rd�k
	}
	
	
	
	getch();
	return 0;
}
