#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

FILE *arsene_lupen , *prf_longdon; // .txt format�nda bulunan dosyarlar�m�z� a�mak i�in gerekli olan FILE t�r�nden pointer lar�m�z� tan�mlad�k.


typedef struct Cift_Yonlu_Bagli_Liste{ // �ift y�nl� ba�l� listeyi tan�mlad�k.
	int value; // d���m�n tutaca�� integer de�er.
	struct Cift_Yonlu_Bagli_Liste *right , *left; // d���m�n tutaca�� �nceki ve sonraki d���mlerin adresleri
}Liste; // kullan�m a��s�ndan kolayl�k i�in �ift y�nl� ba�l� listenin isim k�saltmas�.

Liste *first = NULL , *added = NULL , *gecici = NULL , *previous = NULL , *end = NULL; // yap�lacak i�lemler i�in gerekli olan de�i�kenleri tan�mlad�k.


/*
# first = ba�l� listenin ilk eleman�n� tutmak i�in kullan�l�r.
# added = eklenecek olan yeni gelen eleman� tutmak i�in kullan�l�r.
# gecici = her yerde kullan�lan joker eleman.:D
# previous = s�ral� eklemede bir �nceki de�eri tuttmak i�in kullan�l�r.
# end = tersten yazd�rma durumunda son eleman� tutmak i�in kullan�l�r.
*/



/*---- ��FT Y�NL� BA�LI L�STEYE SIRALI ELEMAN EKLEYEN FONKS�YON ----*/
void Add_To_List(int value){
	
	added = (Liste*)malloc(sizeof(Liste)); // gelen say�y� eklemek i�in yeni bir d���m olu�turduk.
	added->value = value; // d���me say�y� ekledik.
	added->right = NULL; // d���m�n sonraki de�erini null yapt�k.
	added->left = NULL; // d����m�n �nceki de�erini null yapt�k.
	
	
	if(first == NULL){ // e�er ba�l� listede hi� eleman yoksa.
		first = added; // ilk eleman yeni gelen eleman ayni added .
	
	}
	else{ // e�er ba�l� listede elemanlar d���mler varsa
	
		if(first->value > added->value){ // yeni gelen eleman�n say�s� ilk eleman�n say�s�ndan k���kse.
			added->right = first; // gerekli olan �nceki, sonraki ba� e�itlemelerini yapt�k.
			first->left = added;
			first = added;
		}
			
		else{ // yeni gelen eleman�n say�s� ilk eleman�n say�s�ndan k���k de�ilse.
		
		previous = first; // onceki eleman� ilk e e�itledik
		gecici = first->right; // gecici ilk elemandan 1 sonraki elemana e�itledik
		
		while(gecici != NULL){ // gecici null olmad��� s�rece cal��an bir d�ng� kurduk.
			
			if(gecici->value < added->value){ // e�er gecicinin de�eri yeni de�erden k���kse
				previous = previous->right; // �ncekinin g�sterdi�i de�eri ilerlettik.
				gecici = gecici->right; // ge�icinin g�sterdi�i de�eri ilerlettik.
			}
			else{
				break;
			}
		}
		
		if(gecici == NULL){ // e�er gecici null a e�it ise
			previous->right = added; // e�itlemeleri yapt�k
			added->left = previous;
		}
		
		else{ // de�ilse 
			previous->right = added; // gelmesi gerekne yere uygun �ekilde e�itlemeleri yapt�k.
			added->left = previous;
			added->right = gecici;
			gecici->left = added;
		}
		}	
	}
	
	
}




/*---- DOSYADAN SIRLI �EK�LDE OKUMA YAPAN FONKS�YON ----*/
void File_Read(){
	
	int read;
	arsene_lupen = fopen("sayilar.txt","r+"); // say�lar dosyas�n� okuma modunda a�t�k.
	
	if(arsene_lupen == NULL) // e�er dosya  a��lmad�ysa veya dosya yoksa.
	printf("DOSYA MEVCUT DEG�L");
	
	while(!feof(arsene_lupen)){ // dosyan�n sonuna kadar giden d�ng� olu�turduk
	fscanf(arsene_lupen,"%d",&read); // dosyadan s�ral� �ekilde say�lar� okuduk
	printf("\t %d \n",read); // dosyadan okunan say�lar� ekrana bast�k.
	Add_To_List(read); // dosyadan okunan say�lar� ba�l� listeye eklemek i�in yollad�k.
	}
	fclose(arsene_lupen);// dosyay� kapatt�k.
}	




/*---- DOSYAYA SIRALI �EK�LDE YAZMA YAPAN FONKS�YON ----*/
void File_Write(int write){
	
	prf_longdon = fopen("sayilarters.txt","a+"); // say�larters dosyas�n� yazma modunda a�t�k.
	
	if(prf_longdon==NULL) // e�er dosya a��lamad�ysa veya dosya yoksa.
	printf("DOSYA MEVCUT DEG�L");
	fprintf(prf_longdon,"%d\n",write); // dosyaya fonksiyona gelen say�y� yazd�k.
	fclose(prf_longdon); // dosya ile i�lemlerimiz bitince dosyay� kapatt�k.

}




/*---- ��FT Y�NL� BA�LI L�STEY� EKRANA BASTIRAN FONKS�YON ----*/
void Print_To_List(){
	gecici = first;
	while(gecici != NULL){ // ge�ici null olmayana kadar devam eden d�ng� olu�turduk
	end = gecici; // ayr�ca tersten dosyaya yazd�rmak i�in kullanaca��m�z end de�i�kenini son elemana e�itledik.
	printf(" <-(%d)-> ",gecici->value); // ge�icinin eleman�n� ekrana yazd�rd�k.
	gecici = gecici->right; // ge�iciyi ilerlettik.
	}
		
}




/*---- ��FT Y�NL� BA�LI L�STEY� TERSTEN YOLLAYAN FONKS�YON ----*/
void Tersten_Yolla(){

	while(end != NULL){ // end null olmaya kadar devam eden d�ng� olu�turduk.
		printf("\t %d\n ",end->value); // endin eleman�n� ekrana yazd�rd�k.
		File_Write(end->value); // dosyaya yazmak i�in endin eleman�n� yollad�k.
		end = end->left; // endi first e yani sondan ilk elemana kadar gerileme yapt�k.
	}
}




/*---- ANA FONKS�YONUMUZ ----*/
int main(){
	
	printf("****** DOSYADA BULUNAN INTEGER SAYILAR OKUNUYOR !!! ****** \n");
	
	File_Read(); // dosyadan okuma yap�p ba�l� listeye y�nlendiren fonksiyonumuzu �a��rd�k.
	
	printf("\n");
	printf("\n");
	printf("****** OKUNAN SAYILAR CIFT YONLU BAGLI LISTEYE EKLENDI !!! ****** \n");
	
	printf("\n");
	printf("\n");
	
	printf("****** OLUSTURULAN CIFT YONLU BAGLI LISTE !!! ****** \n");
	Print_To_List(); // olu�turulan ba�l listeyi ekrana yazd�ran fonksiyonumuzu �a��rd�k.
	
	printf("\n");
	printf("\n");	
	
	printf("****** CIFT YONLU BAGLI LISTENIN TERSTEN SIRALANISI !!! ****** \n");

	Tersten_Yolla(); // ba�l� listemizi dosyaya yazmak i�in tersten yollayan ve ba�l� listeyi tersten ekrana yazd�ran fonksiyonumuzu �a��rd�k.
	
	printf("\n");
	printf("\n");
	
	printf("****** CIFT YONLU BAGLI LISTE TERSTEN OLARAK DOSYAYA YAZILDI !!! ****** \n");

	printf("\n");
		
	printf("****** PROGRAMIN CALISMASI BITMISTIR! ****** \n");
	printf("****** CIKIS ICIN LUTFEN 'ENTER' TUSUNA BASINIZ! ****** \n");
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A A�TT�R.
// KOPYALANMASI VEYA �O�ALTILMASI YASAKTIR.
