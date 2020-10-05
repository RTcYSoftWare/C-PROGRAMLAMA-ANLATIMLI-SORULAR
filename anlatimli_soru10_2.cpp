#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // dosyaya yazma i�in gerekli k�t�phane
#include<time.h> // random say� i�in gerekli olan k�t�pahen



FILE *dosya , *dosya1; // dosyalama i�in gerekli olan pointerlar�m�z� (i�aret�iler) tan�mlad�k.



/*--- ASAL SAYI BULAN FONKS�YONUMUZ ---*/
void Find_Prime(int value); // fonksiyonlar�n farkl� �e�itle tan�mlamas�d�r. bu �ekilde �stte tan�mlay�p daha sonra farkl� yerde detayl� yazabiliriz.



/*--- DOSYADAN VER� OKUYAN FONKS�YONUMUZ ---*/
void File_Read(){
	
	int read; // okunan say�y� tutmas� i�in de�i�ken tan�mlad�k.
	dosya = fopen("sayilar.txt","r+"); // dosyay� okuma modunda a�t�k.
	if(dosya==NULL) // dosya pointer� nullsa yani dosya yoksa.
	printf("DOSYA MEVCUT DEG�L"); // ekrana bilgi yazd�k.
	while(!feof(dosya)){ // dosyan�n sonuna kadar giden d�ng� tan�mlad�k. ---- 3. ad�m.
	fscanf(dosya,"%d",&read); // dosyadan s�ral� olarak say�lar� okuduk. ---- 4. ad�m.
	Find_Prime(read); // asal say�y� bulmas� i�in fonksiyonumuzu �a��rd�k. ---- 4. ad�m.
	}
	
}	



/*--- DOSYAYA VER� YAZAN FONKS�YONUMUZ ---*/
void File_Write(int write){
	
	dosya1 = fopen("sayilar2.txt","a+"); // dosyay� yazma modunda a�t�k.
	if(dosya==NULL) // dosya pointer� nullsa yani dosya yoksa.
	printf("DOSYA MEVCUT DEG�L"); // ekrana bilgi yazd�k.
	fprintf(dosya1,"%d\n",write); // dosyaya say�lar� yazd�k. ---- 6. ad�m.
	printf(" --- %d \n",write);
	fclose(dosya1);	// dosyay� kapatt�k.

}



/*--- ASAL SAYI BULAN FONKS�YONUMUZ ---*/
void Find_Prime(int value){
	
	int flag=0; // asal say� kontrol� yapan de�i�kenimizi tan�mlad�k.
	for(int i=2;i<value;i++){ // 2 den ba�lay�p gelen say�ya kadar d�nen d�ng� olu�turduk. 
		if(value%i==0){ // e�er say� mod i s�f�rsa.
			flag++; // kontrol de�i�kenimizi artt�rd�k.
			break; // d�ng�y� k�rd�k.
		}
		if(flag==0){ // e�er kontrol de�i�keni s�f�rsa.
			File_Write(value); // dosyaya yazan yonksiyonumuzu �a��rd�k. ---- 5. ad�m.
			break; // d�ng�y� k�rd�k.
		}
	}
}



/*--- ANA FONKS�YONUMUZ ---*/
int main(){

	printf("ASAL SAYILAR ARANIYOR!!!\n"); // ekrana bilgi yazd�k.
	
	File_Read(); // dosyadan okuma yapan fonksiyonumuzu �a��rd�k. ---- 2. ad�m.
	
	printf("ASAL SAYILAR SAYILAR2 DOSYASINA YAZILDI. CIKIS ICIN ENTER A BASIN!!!"); // ekrana bilgi yazd�k.
	

	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A A�TT�R.
// KOPYALANMASI VEYA �O�ALTILMASI YASAKTIR.
