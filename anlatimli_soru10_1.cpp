#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // dosyaya yazma i�in gerekli k�t�phane 
#include<time.h> // random say� i�in gerekli olan k�t�pahen

FILE *dosya , *dosya1; // dosyalama i�in gerekli olan pointerlar�m�z� (i�aret�iler) tan�mlad�k. 



/*--- DOSYAYA VER� YAZAN FONKS�YONUMUZ ---*/
void File_Write(int yaz){

	dosya = fopen("sayilar.txt","a+"); // dosyay� yazma modunda a�t�k.
	if(dosya==NULL) // dosya pointer� nullsa yani dosya yoksa
	printf("DOSYA MEVCUT DEG�L"); // ekrana bilgi yazd�k.
	fprintf(dosya,"%d\n",yaz); // dosyaya say�lar� yazd�k. ---- 5. ad�m.
	fclose(dosya); // dosyay� kapatt�k. 
}



/*--- RANDOM (RASTGELE) SAYILARI �RETEN FONKS�YONUMUZ ---*/
void Random_Value(){
	
	int randomvalue = 0; // random (rastgele) say�y� tutacak de�i�ken
	srand(time(NULL)); // random zaman de�i�keni.
	
	for(int i=0;i<100;i++){ // 100 defa ger�ekle�ecek d�ng�. ---- 3. ad�m.
		randomvalue = rand()%1000; // random say� �retrip de�i�kenimize atad�k. ---- 4. ad�m.
		File_Write(randomvalue); // dosyaya yazmak i�in dosyaya yazma fonksiyonumuzu �a��rd�k. ---- 4. ad�m.
		printf("\n --- %d",randomvalue); // ekrana rastgele �retilen say�y� yazd�rd�k. ---- 6. ad�m.
	}
}



/*--- ANA FONKS�YONUMUZ ---*/
int main(){
	
	printf("\n SAYILAR DOSYAYA YAZILIYOR. LUTFEN BEKLEYINIZ!!!\n"); // ekrana bilgi yaz�dk.

	Random_Value(); // rastgele (random) say� �reten fonksiyonumuzu �a��rd�k. ---- 2. ad�m.
	
	printf("\n\n SAYILAR DOSYAYA YAZILDI. CIKIS ICIN ENTER' A BASINIZ!!!"); // ekrana bilgi yazd�k.
	
	
	
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A A�TT�R.
// KOPYALANMASI VEYA �O�ALTILMASI YASAKTIR.
