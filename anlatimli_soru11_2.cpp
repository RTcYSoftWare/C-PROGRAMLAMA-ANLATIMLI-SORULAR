#include<stdio.h>
#include<stdlib.h> // dosyaya yazma i�in gerekli k�t�phane 
#include<conio.h>
#include<time.h> // random say� i�in gerekli olan k�t�phane



FILE *dosya , *dosya2;  // dosyalama i�in gerekli olan pointerlar�m�z� (i�aret�iler) tan�mlad�k. 



/*--- DOSYAYA YAZAN FONKS�YONUMUZ ---*/
void File_Write(int value, int kontrol){
	
	if(kontrol==1){ // sayilar0 veya sayilar1 dosyalar�ndan hangisine yaz�laca��n� kontrol ettik.
	
	dosya=fopen("sayilar0.txt","a+"); // dosyay� yazma modunda a�t�k.
	if(dosya==NULL) // dosya pointer� nullsa yani dosya yoksa
	printf("Dosya Bulunamadi\n"); // ekrana bilgi yazd�k.
	
	fprintf(dosya,"%d\n",value); // dosyaya say�lar� yazd�k. ---- 5. ad�m.
	fclose(dosya); // dosyay� kapatt�k. 
	}
	
	else{
	
	dosya2=fopen("sayilar1.txt","a+"); // dosyay� yazma modunda a�t�k.
	if(dosya2==NULL) // dosya pointer� nullsa yani dosya yoksa
	printf("Dosya2 Bulunamadi\n"); // ekrana bilgi yazd�k.
	
	fprintf(dosya2,"%d\n",value); // dosyaya say�lar� yazd�k. ---- 5. ad�m.
	fclose(dosya2); // dosyay� kapatt�k. 
	}
}



/*--- ANA FONKS�YONUMUZ ---*/
int main(){
	

	/*short value1=73;   	 		 a = 73 0000 0000 0100 1001 as�l say� */
	short maske = 8;	  	/* maske = 16 0000 0000 0000 1000 birlemek (bitler sa�dan sola 1den ba�lamakta) */ // say�n� 4. bitini birlemek i�in gerekli de�i�ken.
	short maske2 = ~4; 		/* maske2= ~8 1111 1111 1111 1011 s�f�rlamak (bitler sa�don sola 1den ba�lamakta) */ // say�n�n 3. bitini s�f�rlama i�in gerekli de�i�ken.
	int randomvalue=0;		/* val&maske2 0000 0000 0100 1001 */
							/* val|maske  0000 0000 0100 1001*/
	
	srand(time(NULL)); // random de�er i�in zaman.
	for(int i=0;i<100;i++){ // 100 defa d�nen d�ng�.
		randomvalue = rand()%100; // random (rastgele say�) say� olu�turduk.
		if(randomvalue & 1 << 5){ // (5. bit 1) e�er say�n�n 5. biti 1 ise 
			randomvalue &= maske2; // 3. biti s�f�r yapt�k. tan�mad���m�z maskemiz ile "ve" i�lemine soktuk.
			File_Write(randomvalue,0); // dosyaya yazmak i�in fonksiyonu �a��rd�k.
		}
		else{ // (1 de�ilse 0 d�r zaten) say�n�n 5. biti 0 ise.
			randomvalue |= maske; // 4. bii 1 yapt�k. tan�mlad���m maskemiz ile "veya" i�lemine soktuk.
			File_Write(randomvalue,1); // dosyaya yazmak i�in fonksiyonu �a��rd�
		}
	}
	

	printf("SAYILAR DOSYALARA YAZILDI!!!\n"); // ekrana bilgi yazd�rd�k.
	
	
	
	getch();
	return 0;
}



// THIS CODES BELONG TO RTcY SoftWare
