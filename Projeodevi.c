#include<stdio.h>
#include<math.h>

/*
NOT:
Berkehan Doðan Algoritma ve Programlama 2 dersi proje ödevidir.
Benim numaram için en büyük asal çarpan:34721
Sezar Atlama miktari:9
*/

//Girilen öðrenci numarasýna göre atlama miktarýný belirleyen fonksiyon
int SezarAtlamaMiktariBulma(int okulNo2)
{
	int sonrakam,birler,onlar,yuzler;
	birler=(((okulNo2%1000)%100)%10);
	onlar=(((okulNo2%100)-birler)/10);
	yuzler=((okulNo2%100)/100);
	if(birler!=0)
	{
		sonrakam=okulNo2%10;
	}
	if(birler==0&&onlar!=0)
	{
		sonrakam=okulNo2%100;
		sonrakam=sonrakam/10;	
	}
	if(birler==0&&onlar==0)
	{
		sonrakam=okulNo2%1000;
		sonrakam=sonrakam/100;
	}
	okulNo2=sonrakam;
	return okulNo2;
}

//Girilen öðrenci numarasýnýn en büyük asal çarpanýný bulma fonksiyonudur.
int EnBuyukAsalCarpan(int okulNo) {
   int x, max = -1;
   while(okulNo % 2 == 0) {
      max = 2;
      okulNo = okulNo/2;
   }
   for(x = 3; x <= sqrt(okulNo); x=x+2){ 
    
      while(okulNo % x == 0) {
         max = x;
         okulNo = okulNo/x;
      }
   }
   if(okulNo > 2) {
      max = okulNo;
   }
   return max;}
//Girilen ismi sezar þifreleme metoduna göre þifreleyen fonksiyondur.Þifrelemeyi a ile z harfi arasýnda tutuyor.
void SezarSifreliIsim(char *borke01,int kaydirma)
{
	int i,ch1;
	for(i = 0; borke01[i] != '\0'; ++i){
ch1 = borke01[i];
if(ch1 >= 'a' && ch1 <= 'z'){
ch1 = ch1 + kaydirma;
if(ch1 > 'z'){
ch1 = ch1 - 'z' + 'a' - 1;
}
borke01[i] = ch1;
}
else if(ch1 >= 'A' && ch1 <= 'Z'){
ch1 = ch1 + kaydirma;
if(ch1 > 'Z'){
ch1 = ch1 - 'Z' + 'A' - 1;
}
borke01[i] = ch1;
}
}
}
//Girilen soyadý sezar þifreleme metoduna göre þifreleyen fonksiyondur.Þifrelemeyi a ile z harfi arasýnda tutuyor.
void SezarSifreliSoyad(char *borke02,int kaydirma)
{
	int i,ch2;
for(i = 0; borke02[i] != '\0'; ++i){
ch2 = borke02[i];
if(ch2 >= 'a' && ch2 <= 'z'){
ch2 = ch2 + kaydirma;
if(ch2 > 'z'){
ch2 = ch2 - 'z' + 'a' - 1;
}
borke02[i] = ch2;
}
else if(ch2 >= 'A' && ch2 <= 'Z'){
ch2 = ch2 + kaydirma;
if(ch2 > 'Z'){
ch2 = ch2 - 'Z' + 'A' - 1;
}
borke02[i] = ch2;
}
}
}
//Girilen ismi sezar þifreleme metoduna göre çözen fonksiyondur.
void sezarAcikIsim(char *borke03,int kaydirma){
int i, ch3;
for(i = 0; borke03[i] != '\0'; ++i){
ch3 = borke03[i];
if(ch3 >= 'a' && ch3 <= 'z'){
ch3 = ch3 - kaydirma;
if(ch3 < 'a'){
ch3 = ch3 + 'z' - 'a' + 1;
}
borke03[i] = ch3;
}
else if(ch3 >= 'A' && ch3 <= 'Z'){
ch3 = ch3 - kaydirma;
if(ch3 < 'A'){
ch3 = ch3 + 'Z' - 'A' + 1;
}
borke03[i] = ch3;
}
}
}
//Girilen soyadý sezar þifreleme metoduna göre çözen fonksiyondur.
void sezarAcikSoyad(char *borke04,int kaydirma){
int i, ch4;
for(i = 0; borke04[i] != '\0'; ++i){
ch4 = borke04[i];
if(ch4 >= 'a' && ch4 <= 'z'){
ch4 = ch4 - kaydirma;
if(ch4 < 'a'){
ch4 = ch4 + 'z' - 'a' + 1;
}
borke04[i] = ch4;
}
else if(ch4 >= 'A' && ch4 <= 'Z'){
ch4 = ch4 - kaydirma;
if(ch4 < 'A'){
ch4 = ch4 + 'Z' - 'A' + 1;
}
borke04[i] = ch4;
}
}
}
//Struct yapýsý ile bilgiler alýnmýþtýr.
 typedef struct 
	{
		int okulNo; //212805009
		int atlanacakmiktar;  
		char isim[50]; //berkehan
		char soyad[50]; //dogan
	} Bilgiler;
int main()
{
	int atlanacakmiktar;
   Bilgiler ogrenci_bilgileri;
   printf("Isminizi giriniz: ");
   scanf("%s",&ogrenci_bilgileri.isim);
   printf("Soyadinizi giriniz: ");
   scanf("%s",&ogrenci_bilgileri.soyad);
   printf("Okul numarasini giriniz:");
   scanf("%d",&ogrenci_bilgileri.okulNo);
   atlanacakmiktar=SezarAtlamaMiktariBulma(ogrenci_bilgileri.okulNo);
   printf("Kaydirma miktariniz:%d\n",atlanacakmiktar);
   SezarSifreliIsim(ogrenci_bilgileri.isim,atlanacakmiktar);  
   SezarSifreliSoyad(ogrenci_bilgileri.soyad,atlanacakmiktar);
   EnBuyukAsalCarpan(ogrenci_bilgileri.okulNo);
//sifrelimetin.txt adlý dosyayý oluþturup açýyoruz.
char *filename ="sifrelimetin.txt";
FILE *fp = fopen(filename, "w");
if (fp == NULL){
	printf("Dosya olusturulamadi %s", filename);
	return -1;
}
//Burada açtýðýmýz dosyaya verilecek öðrenci bilgileri þifrelenerek yazýlmaktadýr.
fprintf(fp,ogrenci_bilgileri.isim);
fprintf(fp, " ");
fprintf(fp,ogrenci_bilgileri.soyad);
fclose(fp);

   int girdi,denemehakki=0;
   printf("3 deneme hakkiniz bulunmaktadir.");
   printf("Ogrenci numarinizin en buyuk asal carpani nedir?\n");//34721
   while(denemehakki<3)
   {
   	printf("Parola:");
   	scanf("%d",&girdi);
   	denemehakki++;
   	if(EnBuyukAsalCarpan(ogrenci_bilgileri.okulNo)==girdi){
   		printf("Parolaniz dogru--->Giris Basarili!<---\n");
   		printf("*******************Ogrenci Bilgileri*******************\n");
   		fopen("sifrelimetin.txt", "r");
   		  while(! feof(fp) ){
    putchar(fgetc(fp));
  }
  fclose(fp);
     sezarAcikIsim(ogrenci_bilgileri.isim,atlanacakmiktar);
     sezarAcikSoyad(ogrenci_bilgileri.soyad,atlanacakmiktar);
fopen("sifrelimetin.txt", "a");
fprintf(fp,"\n");
fprintf(fp,ogrenci_bilgileri.isim);
fprintf(fp, " ");
fprintf(fp,ogrenci_bilgileri.soyad);
fprintf(fp, " ");
fprintf(fp,"%d",ogrenci_bilgileri.okulNo);
printf("\n\nSifresi cozulmus metin:\nOgrenci adi soyadi:%s %s\tNumara:%d",ogrenci_bilgileri.isim,ogrenci_bilgileri.soyad,ogrenci_bilgileri.okulNo);
printf("\n********************************************************");
  break;}
  else{
  	printf("Yanlis parola girdiniz\n");
  }
  if(denemehakki==3)
  {
  	printf("Deneme hakkiniz kalmamistir.Lutfen daha sonra tekrar deneyiniz!\n");
  }
  else{
  	printf("Kalan hakkiniz:%d\n",3-denemehakki);
  }
   }
   return 0;
}

