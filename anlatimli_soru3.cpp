#include<stdio.h>
#include<conio.h>
#include<string.h>



int main(){
	
	char cumle[100]; // tutaca��m�z c�mle de�i�kenini tan�mlad�k
	int cumle_boyutu = 0; // girilen cimlenin boyutu i�in de�i�ken tan�mlad�k.
	int j=0;
	printf("TERS CEVIRILECEK CUMLEYI GIRINIZ !!! \n"); //ekrana bilgi yazd�k
	gets(cumle); // kullan�c�dan c�mle girdisini ald�k ---- 2.ad�m
	
	printf("KULLANICININ GIRDIGI CUMLE !!!  \n"); //ekrana bilgi yazd�k
	printf("---- %s \n",cumle); // kullan�c�n�n girdi�i c�mleyi ekrana yazd�rd�k
	
	/*---- C�MLE BOYUTUNU BULMA ----*/
	for(int i=1;cumle[i]!=NULL;i++){  
		cumle_boyutu++; // ---- 3.ad�m
	}
	
	/*---- C�MLEY� TERSTEN CUMLE TERS D�Z�S�NE ATAMA ----*/
	char cumle_ters[cumle_boyutu];
	for(int i=cumle_boyutu;i>=0;i--){ // ---- 4.ad�m
		cumle_ters[j] = cumle[i];
		j++;
	}
	
	printf("CUMLENIN TERSTEN YAZIMI !!! \n\n"); //ekrana bilgi yazd�k
	
	for(int i=0;i<cumle_boyutu+1;i++){
		printf("%c",cumle_ters[i]); // ---- 5.ad�m
	}
	
	getch();
	return 0;
}


// THIS CODES BELONG RTcY SOFTWARE
