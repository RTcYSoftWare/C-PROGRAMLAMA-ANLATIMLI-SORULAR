#include<stdio.h>
#include<conio.h>


FILE *arsene_lupen; // tan�mlad���m�z dosya pointerlar'�

int dosyadaki_sayilar[100]; // dosyadan okunan verileri s�ralamak i�in atad���m�z dizi


/*--- D�Z�YE OKUNAN SAYILARI EKLEYEN FONKS�YON ---*/
void Diziye_Ekle(int eklenecek);


/*---- DOSYADAN SIRLI �EK�LDE OKUMA YAPAN FONKS�YON ----*/
void File_Read(){
	
	int read;
	arsene_lupen = fopen("sayilar.txt","r+"); // say�lar dosyas�n� okuma modunda a�t�k.
	int dizi_index = 0;
	
	if(arsene_lupen == NULL) // e�er dosya  a��lmad�ysa veya dosya yoksa.
	printf("DOSYA MEVCUT DEG�L");
	
	while(!feof(arsene_lupen)){ // dosyan�n sonuna kadar giden d�ng� olu�turduk
	fscanf(arsene_lupen,"%d",&read); // dosyadan s�ral� �ekilde say�lar� okuduk
	printf("\t %d \n",read); // dosyadan okunan say�lar� ekrana bast�k.
	Diziye_Ekle(read); // dosyadan okunan say�lar� diziye eklemek i�in yollad�k. ---- 3.ad�m
	}
	fclose(arsene_lupen); // dosyay� kapatt�k.
}	




/*--- HIZLI SIRALAMA YAPAN (QUICK SORT) FONKS�YONUMUZ  ---*/
void Hizli_Siralama(int dizi[100] , int sol , int sag){
	
	int i=sol,j=sag,gecici,pivot=dizi[(sol+sag)/2]; // gerekli olan de�i�kenler
	
	while(i<=j){
		while(dizi[i]>pivot)
		i++;
		while(dizi[j]<pivot)
		j--;
		if(i<=j){
			gecici = dizi[i];
			dizi[i] = dizi[j];
			dizi[j] = gecici;
			i++;
			j--;
		}
	}
	
	if(sol<j)
	Hizli_Siralama(dizi,sol,j);
	if(i<sag)
	Hizli_Siralama(dizi,i,sag);
}




/*--- D�Z�YE OKUNAN SAYILARI EKLEYEN FONKS�YON ---*/
void Diziye_Ekle(int eklenecek){
	
	for(int i=0;i<100;i++){ // 100 defa d�nen d�ng�
		if(dosyadaki_sayilar[i] == NULL){ // e�er dizinin i. eleman� bo� ise
			dosyadaki_sayilar[i] = eklenecek; // dizinin bo� olan eleman�na say�y� atad�k.
			break; // d�ng�den ��kt�k.
		}
		
	}
}




/*--- ANA FONKS�YONUMUZ ---*/
int main(){
	
	printf("\t DOSYADA BULUNAN SAYILAR OKUNUYOR !!! \n\n "); // ekrana bilgi yazd�rd�k.
	File_Read(); // doyadan okuma yapan fonksiyonumuzu �a��rd�k. ---- 2.ad�m
	
	printf("\t SAYILAR DIZIYE AKTARILDI !!! \n\n"); // ekrana bilgi yazd�rd�k.
	
	
	printf("\t SAYILAR BUYUKTEN KUCUGE SIRALANIYOR !!! \n\n "); // ekrana bilgi yazd�rd�k.
	Hizli_Siralama(dosyadaki_sayilar,0,100-1); // h�zl� s�ralama (quick sort) yapan fonksiyonumuzu �a��rd�k. ---- 4.ad�m
	
	
	printf("\t SAYILARIN SIRALANMIS HALI !!! \n\n"); // ekrana bilgi yazd�rd�k.
	
	for(int i=0;i<100;i++){ // s�ralanm�� diziyi ekrana yazd�rd�. ---- 5.ad�m
		printf("\t %d \n",dosyadaki_sayilar[i]);
	}
	
	
	getch();
	return 0;
}




// BU KODLAR RIZA TURANCAN YILMAZ'A A�TT�R.
// KOPYALANMASI VEYA �O�ALTILMASI YASAKTIR.
