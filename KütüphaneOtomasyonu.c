

// PROGRAMIN GÝRÝÞ ÞÝFRESÝ 2020'DÝR.


#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>


// FONKSÝYONLAR

void sifre(); 
void ana_menu(); 
void kitap_ekleme();
void kitap_silme();
void kitap_duzenleme(); 
void kitap_arama(); 
void kitap_listeleme();
void kitap_odunc_alma();


// GLOBAL DEÐÝÞKENLER
int i=0, uyum=0, bulundu=0;      
char karar=0;					 

// KÝTAP BÝLGÝLERÝNÝ TUTMAK ÝÇÝN STRUCT
struct kitaplar             
{							 
	int kitap_id;            
	char kitap_adi[20];
	char yazar_adi[20];
	char aKisi_adi[20];
	char kitapTur[15];
	int gun;	
	
}kitapEklemeBilgileri;

void yerxy(short x, short y)  
{							  
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main() 
{	
	system("color a");
	sifre();
}





// ÞÝFRE 
void sifre()
{
	yerxy(30,1);
	printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
	yerxy(45,3);
	printf("KUTUPHANE SISTEMINE HOS GELDINIZ!");
	yerxy(30,5);
	printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
	int sifre= 2020;
	int gsifre;
	
	yerxy(45,10);
	printf("Lutfen Sifrenizi Giriniz: ");
	scanf("%d", &gsifre);  
	yerxy(45,12);
	

	if (gsifre == 2020 ) {
	yerxy(30,14);
	printf("------------------------------------------------------------------");
	yerxy(50,16);
	printf("Girdiginiz Sifre Dogru!\n");
	yerxy(40,18);
	printf("Devam Etmek Icin Herhangi Bir Tusa Basiniz!\n");
	yerxy(30,20);
	printf("------------------------------------------------------------------");
	yerxy(60,22);
	getch();	
	ana_menu();	
	}
	
	
	else {
	int tekrarDeneGirdi;
	yerxy(45,14);
	printf("----------------------------------");
	yerxy(45,16);		
	printf("Girdiginiz sifre yanlis.\n");
	yerxy(45,18);
	printf("Tekrar denemek icin 1'e basiniz.\n");
	yerxy(45,20);
	printf("Cikis yapmak icin 0'a basiniz.\n");
	yerxy(45,22);
	
	switch (getch()) {     
					       
		case '1': {
			system("cls");
			main();
			break;
		}		
		
		case '0': {
			system("cls");
			yerxy(45,10);
			printf("Program sonlandi.");
			break;
		}			
		
	}
	
}
	
}




// ANA MENÜ
void ana_menu(void){
	
	int karar = 1;
	do{	
	system("cls");
	yerxy (40,3);
	printf("ANA MENU");
	yerxy (40,4);
	printf("__________________________________________________");
	yerxy (40,7);
	printf("1. Kitap Listesini Listeleme");
	yerxy (40,8);
	printf("-------------------------------------------------");
	yerxy (40,9);
	printf("2. Kitap Arama");
	yerxy (40,10);
	printf("-------------------------------------------------");
	yerxy (40,11);
	printf("3. Kitap Ekle");
	yerxy (40,12);
	printf("-------------------------------------------------");
	yerxy (40,13);
	printf("4. Kitap Bilgilerini Duzenleme");
	yerxy (40,14);
	printf("-------------------------------------------------");
	yerxy (40,15);
	printf("5. Kitap Silme");
	yerxy (40,16);
	printf("-------------------------------------------------");
	yerxy (40,17);
	printf("6. Kitap Odunc Alma");
	yerxy (40,18);
	printf("-------------------------------------------------");
	yerxy (40,19);
	printf("7. Cikis Yapmak Icin 7'ye Basiniz");
	yerxy (40,20);
	printf("--------------------------------------------------");
	yerxy (40,25);
	printf("Atakan Bayrak  Mustafa Berberler  Mehmet Umit Acik");
	yerxy (40,26);
	printf("__________________________________________________");
	
	
	
	switch (getch()) {	
		
		case '1': {
			kitap_listeleme();			
			break;
		}
		case '2': {
			kitap_arama();
			break;
		}
		case '3': {
			kitap_ekleme();
			break;
		}
		case '4': {
			kitap_duzenleme();
			break;
		}
		case '5': {
			kitap_silme();
			break;
		}
		case '6': {
			kitap_odunc_alma();
			break;
		}		
		case '7': {
			karar = 0;
			break;
		}
		default: {
			ana_menu();
			break;
		}
	
	}
							
	}while (karar != 0);		
}






// KÝTAP LÝSTELEME
void kitap_listeleme()
{	
	int j=11;
	FILE*fpointer;  
	system("cls");
	fpointer=fopen("kitapKayit.txt","r");  
	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******      KITAP LISTESINI GORUNTULUYORSUNUZ      ******");
	yerxy(30,5);
	printf("*********************************************************");
	
	if(fpointer==NULL)  
	{
		yerxy(30,10);	
		printf("Dosya Acma Islemi Basarisiz.");
		getch();
	}
	else
	{
			
		
		while(fscanf(fpointer,"%i %s %s %s %s %i\n\n",&kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,&kitapEklemeBilgileri.gun)!=EOF)
		{
			yerxy(30,j);
			printf("---------------------------------------------------------");
			j = j+2;	
			yerxy(40,j);
			printf("Kitap ID: ");
			printf("%i",kitapEklemeBilgileri.kitap_id);
			j = j+2;
			yerxy(40,j);
			printf("Kitap Adi: ");
			printf("%s",kitapEklemeBilgileri.kitap_adi);
			j = j+2;
			yerxy(40,j);
			printf("Yazar Adi: ");
			printf("%s",kitapEklemeBilgileri.yazar_adi);
			j = j+2;
			yerxy(40,j);
			printf("Alan Kisinin Adi: ");
			printf("%s",kitapEklemeBilgileri.aKisi_adi);
			j = j+2;
			yerxy(40,j);
			printf("Kitap Turu: ");
			printf("%s",kitapEklemeBilgileri.kitapTur);
			j = j+2;
			yerxy(40,j);
			printf("Alinan Gun: ");
			printf("%i",kitapEklemeBilgileri.gun);
			j = j+2;
			yerxy(30,j);
			printf("---------------------------------------------------------");					
			j = j+2;			
		}		
	}
	j = j + 3;
	yerxy(30,j);	
	printf("Ana Menuye Donmek Icin Herhangi Bir Tusa Basiniz...");
	
	fclose(fpointer);   
	getch();
	ana_menu();


}




// KÝTAP ARAMA
void kitap_arama()
{
	int cikis;
	int bulundu=0;
	char ad[40];
	FILE *fpointer;   
	system("cls");  
	fpointer=fopen("kitapKayit.txt","rb");    
	yerxy(30,1); 
	printf("*********************************************************");
	yerxy(30,3);
	printf("******      KITAP ARAMA EKRANINA HOS GELDINIZ      ******");
	yerxy(30,5);
	printf("*********************************************************");
	yerxy(37,7);
	printf("Bulmak Istediginiz Kitabin Adini Giriniz: ");
	fflush(stdin);	 
					 
					 
	scanf("%s",ad);
	ad[0]=toupper(ad[0]);   
		
	
	while(fscanf(fpointer,"%i %s %s %s %s %i\n\n",&kitapEklemeBilgileri.kitap_id, kitapEklemeBilgileri.kitap_adi, kitapEklemeBilgileri.yazar_adi, kitapEklemeBilgileri.aKisi_adi, kitapEklemeBilgileri.kitapTur, &kitapEklemeBilgileri.gun)!=EOF)
	{
		if(strcmp(ad,kitapEklemeBilgileri.kitap_adi)==0)   
		{												  
			yerxy(40,9);								   
			printf("----------------------------------"); 
			bulundu=1;									  
			yerxy(30,11);	
			printf("Kitap ID: ");
			printf("%i",kitapEklemeBilgileri.kitap_id);
			yerxy(30,13);
			printf("Kitap Adi: ");
			printf("%s",kitapEklemeBilgileri.kitap_adi);
			yerxy(30,15);
			printf("Yazar Adi: ");
			printf("%s",kitapEklemeBilgileri.yazar_adi);
			yerxy(30,17);
			printf("Alan Kisinin Adi: ");
			printf("%s",kitapEklemeBilgileri.aKisi_adi);
			yerxy(30,19);
			printf("Kitap Turu: ");
			printf("%s",kitapEklemeBilgileri.kitapTur);
			yerxy(30,21);
			printf("Alinan Gun: ");
			printf("%i",kitapEklemeBilgileri.gun);
			break;
		}
	}
		yerxy(30,23);
		if(!bulundu) printf("Boyle Bir Kitap Bulunmamaktadir");
		fclose(fpointer);  
		
		yerxy(30,25);	
		printf("Tekrar Arama Yapmak Icin 1, Cikis Icin 0\n");
		yerxy(30,26);	
		
		do{
		switch (getch()){
		case '1':{
			kitap_arama();
			cikis = 3;
			break;
		}
		case '0':{
			ana_menu();
			cikis = 3;
			break;
		}
		default: cikis = 4;
	}
	}while (cikis != 3);
	
}





// KÝTAP EKLEME
void kitap_ekleme()
{
	
	system("cls");
	FILE *fpointer;   
	fpointer = fopen("kitapKayit.txt","a");
	int karar,cikis,karar2;
	int gun;
		
	// --------------- //
	
	do{		
	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******      KITAP EKLEME EKRANINA HOS GELDINIZ     ******");
	yerxy(30,5);
	printf("*********************************************************");
	yerxy(30,7);
	printf("Eklemeye Gecmek Icin 1 / Ana Menu Icin 0");
	yerxy(30,9);	
	fflush(stdin);
	
	switch (getch()){
		case '1':{
			karar =2;
			break;
		}
		case '0':{
			ana_menu();
			break;
		}
		default: karar = 3;
	}
	}while(karar != 2);
	
	// ------------------- // Döngü
	system("cls");
	yerxy(30,11);
	printf("ADIM 1");	
	yerxy(30,13);
	printf("ONEMLI VERILERI GIRINIZ");
	yerxy(30,15);
	printf("------------------------------");	
	yerxy(30,17);
	printf("Kitap ID Numarasi: ");
	fflush(stdin);
	scanf("%i",&kitapEklemeBilgileri.kitap_id);
	system("cls");
	
	do
	{	
		yerxy(30,11);
		printf("ADIM 2");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Kitap Adi: ");
		fflush(stdin);		
		gets(kitapEklemeBilgileri.kitap_adi);  
		system("cls");
		kitapEklemeBilgileri.kitap_adi[0]=toupper(kitapEklemeBilgileri.kitap_adi[0]); 
		for (i=0;i<strlen(kitapEklemeBilgileri.kitap_adi); ++i)   
		{														 
			if(isalpha(kitapEklemeBilgileri.kitap_adi[i]))   
			{												 
				uyum = 1;
			}
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{	
			yerxy(30,8);
			printf("!Kitabin Adi Sayi Iceremez!");
		}
	}while(!uyum);
	do
	{
		yerxy(30,11);
		printf("ADIM 3");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Yazarin Adi: ");
		fflush(stdin);
		gets(kitapEklemeBilgileri.yazar_adi);
		system("cls");
		kitapEklemeBilgileri.yazar_adi[0]=toupper(kitapEklemeBilgileri.yazar_adi[0]);
		for (i=0;i<strlen(kitapEklemeBilgileri.yazar_adi); ++i)
		{
			if(isalpha(kitapEklemeBilgileri.yazar_adi[i]))
				uyum = 1;
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{
			yerxy(30,8);
			printf("!Yazarin Adi Sayi Iceremez!");
			
		}
	}while(!uyum);
	do
	{
		yerxy(30,11);
		printf("ADIM 4");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ:");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Alan Kisinin Adi: ");
		fflush(stdin);
		gets(kitapEklemeBilgileri.aKisi_adi);
		system("cls");
		kitapEklemeBilgileri.aKisi_adi[0]=toupper(kitapEklemeBilgileri.aKisi_adi[0]);
		for (i=0;i<strlen(kitapEklemeBilgileri.aKisi_adi); ++i)
		{
			if(isalpha(kitapEklemeBilgileri.aKisi_adi[i]))
				uyum = 1;
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{
			yerxy(30,8);
			printf("Alan Kisinin Adi Sayi Iceremez!");
			
		}
	}while(!uyum);
		do
			{
				yerxy(30,11);
				printf("ADIM 5");
				yerxy(30,13);
				printf("ONEMLI VERILERI GIRINIZ:");
				yerxy(30,15);
				printf("------------------------------");
				yerxy(30,17);
				printf("Kitabin Turu: ");
				fflush(stdin);
				gets(kitapEklemeBilgileri.kitapTur);
				system("cls");
				kitapEklemeBilgileri.kitapTur[0]=toupper(kitapEklemeBilgileri.kitapTur[0]);
				for (i=0;i<strlen(kitapEklemeBilgileri.kitapTur); ++i)
				{
					if(isalpha(kitapEklemeBilgileri.kitapTur[i]))
					uyum = 1;
					else
					{
						uyum = 0;
						break;
					}
				}
				if (!uyum)
				{
					yerxy(30,8);
					printf("!Kitabin Turu Sayi Iceremez!");
					
				}
			}while(!uyum);
			kitapEklemeBilgileri.gun = 0;
			
	
	fprintf(fpointer,"%i %s %s %s %s %i\n\n",kitapEklemeBilgileri.kitap_id, kitapEklemeBilgileri.kitap_adi, kitapEklemeBilgileri.yazar_adi, kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,kitapEklemeBilgileri.gun);
	fclose(fpointer);   
	// --------- // Kitap Kayit Sonu
	system("cls");
	yerxy(30,8);
	printf("Kitap Basarili Bir Sekilde Kaydedildi");	
	yerxy(30,11);
	printf("Baska Bir Kitap Kayit Etmek Istiyor Musunuz:");
	yerxy(30,13);
	printf("Kayida Devam Etmek Icin 1, Cikis Icin 0");
	yerxy(30,15);
	
	
	do{
	switch (getch()){
		case '1':{
			kitap_ekleme();
			cikis = 3;
			break;
		}
		case '0':{
			ana_menu();
			cikis = 3;
			break;
		}
		default: cikis = 4;
	}
	}while (cikis != 3);
	
}






// KÝTAP DÜZENLEME
void kitap_duzenleme()
{
  int i,bulundu,duzenlenecekKitap_id,cikis;
  char ch;
  int kitap_id;
  FILE *fpointer, *duzenleme;  
  system("cls");			   
  	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******    KITAP DUZENLEME EKRANINA HOS GELDINIZ    ******");
	yerxy(30,5);
	printf("*********************************************************");

   fpointer=fopen("kitapKayit.txt","rb+");  
   if(fpointer==NULL)
   {
   		yerxy(30,7);
		printf("Dosya Acma Islemi Basarisiz");
		getch();
		ana_menu();
   }
   yerxy(30,9);
   printf("Duzenlenecek Kitabin ID'sini Giriniz");
   scanf("%i",&duzenlenecekKitap_id);
   yerxy(30,11);
   duzenleme=fopen("geciciKayit.txt","a+");  
   if (duzenleme==NULL)
   {
   	yerxy(30,13);
   	printf("Dosya Acma Islemi Basarisiz");
	yerxy(30,14);   	
   	printf("Ana Menuye Donmek Icin Bir Tusa Basiniz");
   	ana_menu();
   }
   else
   {
   	while(fscanf(fpointer,"%i %s %s %s %s %i\n",&kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,&kitapEklemeBilgileri.gun)!=EOF)
   	{
   		if(kitapEklemeBilgileri.kitap_id==duzenlenecekKitap_id)  
   		{														
   			bulundu=1;
   			yerxy(30,15);   
			printf("Ilgili Kitap Kutuphanede Bulundu. Duzenleme Islemine Baslayabilirsiniz!");
			yerxy(30,17);   
			printf("Duzenleme Islemine Baslamak Icin 1'e basiniz - Ana Menu Icin 0'a basiniz");
			
			// KARAR DÖNGÜSÜ
			do{
			switch (getch()){
			case '1':{			
			cikis = 3;
			system("cls");
			break;
			}
			case '0':{
			ana_menu();
			cikis = 3;
			break;
			}
			default: cikis = 4;
			}
			}while (cikis != 3);
			
			
   			do
			{	
			yerxy(30,11);
			printf("ADIM 1");
			yerxy(30,13);
			printf("ONEMLI VERILERI GIRINIZ:");
			yerxy(30,15);
			printf("------------------------------");
			yerxy(30,17);
			printf("Kitap Adi: ");
			fflush(stdin);		
			gets(kitapEklemeBilgileri.kitap_adi);
			system("cls");
			kitapEklemeBilgileri.kitap_adi[0]=toupper(kitapEklemeBilgileri.kitap_adi[0]);
			for (i=0;i<strlen(kitapEklemeBilgileri.kitap_adi); ++i)
			{
			if(isalpha(kitapEklemeBilgileri.kitap_adi[i]))
			{
				uyum = 1;
			}
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{	
			yerxy(30,8);
			printf("!Kitabin Adi Sayi Iceremez!");
		}
	}while(!uyum);
	do
	{
		yerxy(30,11);
		printf("ADIM 2");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ:");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Yazar Adi: ");
		fflush(stdin);
		gets(kitapEklemeBilgileri.yazar_adi);
		system("cls");
		kitapEklemeBilgileri.yazar_adi[0]=toupper(kitapEklemeBilgileri.yazar_adi[0]);
		for (i=0;i<strlen(kitapEklemeBilgileri.yazar_adi); ++i)
		{
			if(isalpha(kitapEklemeBilgileri.yazar_adi[i]))
				uyum = 1;
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{
			yerxy(30,8);
			printf("!Yazarin Adi Sayi Iceremez!");
			
		}
	}while(!uyum);
	do
	{
		yerxy(30,11);
		printf("ADIM 3");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ:");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Alan Kisinin Adi: ");
		fflush(stdin);
		gets(kitapEklemeBilgileri.aKisi_adi);
		system("cls");
		kitapEklemeBilgileri.aKisi_adi[0]=toupper(kitapEklemeBilgileri.aKisi_adi[0]);
		for (i=0;i<strlen(kitapEklemeBilgileri.aKisi_adi); ++i)
		{
			if(isalpha(kitapEklemeBilgileri.aKisi_adi[i]))
				uyum = 1;
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{
			yerxy(30,8);
			printf("Alan Kisinin Adi Sayi Iceremez!");
			
		}
	}while(!uyum);
		do
			{
				yerxy(30,11);
				printf("ADIM 4");
				yerxy(30,13);
				printf("ONEMLI VERILERI GIRINIZ:");
				yerxy(30,15);
				printf("------------------------------");
				yerxy(30,17);
				printf("Kitap Turu:");
				fflush(stdin);
				gets(kitapEklemeBilgileri.kitapTur);
				system("cls");
				kitapEklemeBilgileri.kitapTur[0]=toupper(kitapEklemeBilgileri.kitapTur[0]);
				for (i=0;i<strlen(kitapEklemeBilgileri.kitapTur); ++i)
				{
					if(isalpha(kitapEklemeBilgileri.kitapTur[i]))
					uyum = 1;
					else
					{
						uyum = 0;
						break;
					}
				}
				if (!uyum)
				{
					yerxy(30,8);
					printf("!Kitabin Turu Sayi Iceremez!");
					
				}
			}while(!uyum);			
			
			kitapEklemeBilgileri.gun = 0;

			
			fprintf(duzenleme,"%i %s %s %s %s %i",kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,kitapEklemeBilgileri.gun);
			fflush(stdin);
			yerxy(30,8);
			printf("Kitap Bilgileri Guncellemesi Kaydedildi");
			
	   }
	   yerxy(30,15);
	   if(!bulundu)printf("Boyle Bir Kitap Bulunmamaktadir");
	   fclose(duzenleme); 
	   fclose(fpointer);
	   remove("kitapKayit.txt");  
	   rename("geciciKayit.txt","kitapKayit.txt"); 
	  
    	
   }
}
		yerxy(30,25);	
		printf("Kitap Duzenlemeye Devam Etmek Icin 1 / Cikis Icin 0");
		yerxy(30,26);	
		
		do{
		switch (getch()){
		case '1':{
			kitap_duzenleme();
			cikis = 3;
			break;
		}
		case '0':{
			ana_menu();
			cikis = 3;
			break;
		}
		default: cikis = 4;
	}
	}while (cikis != 3);	
}





// KÝTAP SÝLME
void kitap_silme()
{
	
	int silinecekKitap_id,bulundu;
	system("cls");
	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******      KITAP SILME EKRANINA HOS GELDINIZ      ******");
	yerxy(30,5);
	printf("*********************************************************");
	FILE *fpointer,*fpointer2;     
	fpointer=fopen("kitapKayit.txt","r");  
	yerxy(30,9);
	printf("Silinecek Kitabin Id'sini Giriniz: ");
	scanf("%i",&silinecekKitap_id);
	fpointer2=fopen("geciciKayit.txt","w+");  
	if(fpointer==NULL)
	{
		yerxy(30,11);
		printf("Boyle Bir Kitap Bulunmamaktadir!");
		yerxy(30,13);
		printf("Ana Menuye Yonlendiriliyorsunuz");		
		ana_menu();
	}
	else
	{
		while(fscanf(fpointer,"%i %s %s %s %s %i\n",&kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,&kitapEklemeBilgileri.gun)!=EOF)
		{
			if(silinecekKitap_id!=kitapEklemeBilgileri.kitap_id)
			{
				fprintf(fpointer2,"%i %s %s %s %s %i\n",kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,kitapEklemeBilgileri.gun);
			}
			else
			{
				bulundu=1;
			}
		}
		if(!bulundu)
		{
			yerxy(30,11);
			printf("Boyle Bir Kitap Bulunmamaktadir!");
		}
		else
		{
			yerxy(30,13);
			printf("Silme Islemi Basari Ile Gerceklestirildi");
		}
		fclose(fpointer);  
		fclose(fpointer2);
		remove("kitapKayit.txt"); 
		rename("geciciKayit.txt","kitapKayit.txt");  
	}
	getch();
	ana_menu();
}




// KÝTAP ÖDÜNÇ ALMA
void kitap_odunc_alma()
{
  	int i,bulundu,oduncKitap_id,cikis;
  	char ch;
  	int kitap_id;
  	FILE *fpointer, *duzenleme;  
  	system("cls");
  	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******    KITAP ODUNC ALMA EKRANINA HOS GELDINIZ    *****");
	yerxy(30,5);
	printf("*********************************************************");

   fpointer=fopen("kitapKayit.txt","rb+");  
   if(fpointer==NULL)
   {
   		yerxy(30,10);
		printf("Dosya acma islemi basarisiz");
		yerxy(30,12);
		printf("Ana Ekrana Yonlendiriliyorsunuz");	
		yerxy(30,14);
		printf("Herhangi Bir Tusa Basiniz");
		getch();	
		ana_menu();
   }
   yerxy(30,9);
   printf("Odunc Alinacak Kitabin ID'sini Giriniz ");
   scanf("%i",&oduncKitap_id);    
   yerxy(30,11);
   duzenleme=fopen("geciciKayit.txt","a+"); 
   if (duzenleme==NULL)
   {
   	yerxy(30,13);
   	printf("Dosya Acma Islemi Basarisiz");
	yerxy(30,14);   	
   	printf("Ana Menuye Donmek Icin Bir Tusa Basiniz");
   	ana_menu();
   }
   else
   {
   	while(fscanf(fpointer,"%i %s %s %s %s %i\n",&kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,&kitapEklemeBilgileri.gun)!=EOF)
   	{
   		if(kitapEklemeBilgileri.kitap_id==oduncKitap_id)  
   		{												  
   			bulundu=1;
   			yerxy(30,15);   
			printf("Ilgili Kitap Kutuphanede Bulundu. Odunc Alma Islemine Baslayabilirsiniz!");
			yerxy(30,17);   
			printf("Odunc Alma Islemine Baslamak Icin 1'e basiniz - Ana Menu Icin 0'a basiniz");
			
			// KARAR DÖNGÜSÜ
			do{
			switch (getch()){
			case '1':{			
			cikis = 3;
			system("cls");
			break;
			}
			case '0':{
			ana_menu();
			cikis = 3;
			break;
			}
			default: cikis = 4;
			}
			}while (cikis != 3);
				
			
			yerxy(30,17);
			printf("Kitabi Kac Gun Almak Istediginizi Giriniz\n");
			
			do
			{
				yerxy(30,11);
				printf("ADIM 1");
				yerxy(30,13);
				printf("ONEMLI VERILERI GIRINIZ:");
				yerxy(30,15);
				printf("------------------------------");
				yerxy(30,19);
				printf("En fazla 30 gune kadar kitabi odunc alabilirsiniz\n");
				yerxy(30,21);
				printf("Karar: ");
				scanf("%i",&kitapEklemeBilgileri.gun);  
				system("cls");							
				if(kitapEklemeBilgileri.gun<1 || kitapEklemeBilgileri.gun>30)
				{
					yerxy(30,8);
					printf("!30 Gunden Fazla Alamazsin!");
					
				}
			}while(kitapEklemeBilgileri.gun<1 || kitapEklemeBilgileri.gun>30);    
																				  
																				  
				
				fprintf(duzenleme,"%i %s %s %s %s %i",kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,kitapEklemeBilgileri.gun);
				fflush(stdin);
				yerxy(30,8);
				printf("Kitap Bilgileri Guncellemesi Kaydedildi");
			
	   }
	   yerxy(30,15);
	   if(!bulundu)printf("Boyle Bir Kitap Bulunmamaktadir");  
	   														  
	   fclose(duzenleme); 
	   fclose(fpointer);  
	   remove("kitapKayit.txt");  
	   rename("geciciKayit.txt","kitapKayit.txt");  
	  
    	
   }
}
		yerxy(30,12);	
		printf("Kitap Odunc Almaya Devam Etmek Icin 1 / Cikis Icin 0");
		yerxy(30,14);	
		
		do{
		switch (getch()){
		case '1':{
			kitap_odunc_alma();
			cikis = 3;
			break;
		}
		case '0':{
			ana_menu();
			cikis = 3;
			break;
		}
		default: cikis = 4;
	}
	}while (cikis != 3);	
}

