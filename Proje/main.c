/*
Bu program ile belirlediðiniz bir metnin içerisindeki tanımlı biagram ve trigramların frekanslarını bulabilir ve sonuç olarak bu metnin
dilinin Almanca mı İngilizce mi olduðunu görebilirsiniz.

Saba ÜRGÜP
Selin Esra ÖZ
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>   //Kütüphanelerimizi giriyoruz.


const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};

const char languages[2][8]={"english", "german"};

//İngilizce dilinin frekans değerleri
 const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
 //Almanca dilinin frekans değerleri
 const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];
float distances [2]={0,0};


void filter_str(char str[]);                    // Filtreleme fonksiyon prototipi
void calculate_frequencies_bi(char str[]);      // Biagram frekansı hesaplama prototipi
void calculate_frequencies_tri(char str[]);     // Trigram frekansı hesaplama prototipi

void calculate_distances();                     // Frekanslar arası uzaklık hesaplama prototipi
void detect_lang();                             // Kullanıcıdan alınan metnin dilini thamnin prototipi


int main()                                      //Ana fonksiyonumuzu açtık.
{
printf("Bu uygulama girdiginiz bir metnin Ingilizce dilinde mi yoksa Almanca dilinde mi oldugunu gosterir.");

    printf("\n ===================================\n");

  	char str[1000000];
  	int i;
	printf("\n Metni giriniz: ");
	gets(str);

    filter_str(str);                             //Fitreleme fonksiyonumuzu çağırıyoruz.

    printf("\n Girilen metin temizleniyor..\n Metin: \t");
    puts(str);

    calculate_frequencies_bi(str);              // Biagram ve Trigram frekanslarını hesaplamak için fonksiyonlarımızı çağırıyoruz.
    calculate_frequencies_tri(str);

    printf("\n Girilen metnin frekanslari hesaplaniyor..\n Frekanslar: \n");

    for(i=0;i<10;i++)       //For döngüsüyle, hesaplanmış frekanslarımızın bulunduğu dizi elemanlarının girişini yapıyoruz.
    {
         printf("%s : %.1f\n",matrix_bigram_strings[i],calculated_frequencies[i]);
		 printf(" \t\t\t %s : %.1f\n",matrix_trigram_strings[i],calculated_frequencies[i+10]);
    }
    calculate_distances();                      //Frekanslar arası uzaklık hesaplama fonksiyonumuzu çağırıyoruz.
    detect_lang();                              //Hangi dile mensup olduğunu seçen fonksiyonumuzu çağırıyoruz.
    return 0;

	}

void filter_str(char str[])     //Yardımcı fitreleme fonksiyonumuzu açıyoruz.
{   int i;

    for(i=0;i<strlen(str);i++){
            str[i]=tolower(str[i]);         //Kullanıcının girdiği metinde yer alan karakterleri küçük harfe çevirir.
               if(str[i]<97 || str[i]>122)
                str[i]=32;                  //Metin for döngüsü ile taranarak metindeki karakterler, a dan z ye kadar olan karakterlerine (küçük harf) ve boşluk karakteri dışındaki diğer tüm karakterler boşluk karakteriyle değiştirildi.
    }
}

void calculate_frequencies_bi(char str[])        //Yardımcı biagram frekans hesaplama fonksiyonumuzu açıyoruz.
{   printf("\n ===================================\n");
    int x,y,z,a;                                 // Döngüler için gerekli parametreleri tanımladık.
    for(z=0;z<strlen(str)-1;z++){                //For döngüleriyle metnin tüm karakterlerini tek tek tarar ve  tanımlanmış biagramlarla eşleşip eşleşmediğine bakar.
        for(x=0;x<10;x++){
            for(a=0;a<1;a++){
                if(str[z]==matrix_bigram_strings[x][a] && str[z+1]==matrix_bigram_strings[x][a+1]){     // Eşleşme sağlandığında ilgili biagramın frekansını bir arttırır.
                    calculated_frequencies[x]=calculated_frequencies[x]+1;
                    //printf("\n \"%s\" metni icinde %c%c biagrami %f frekansina sahiptir..",str, matrix_bigram_strings[x][a],matrix_bigram_strings[x][a+1], calculated_frequencies[x]);
                }
            }
        }
    }
}

void calculate_frequencies_tri(char str[])      //Yardımcı trigram frekans hesaplama fonksiyonumuzu açıyoruz.
{
    int x,y,z,a;                                // Döngüler için gerekli parametreleri tanımladık.
    for(z=0;z<strlen(str)-1;z++){               //For döngüleriyle metnin tüm karakterlerini tek tek tarar ve  tanımlanmış trigramlarla eşleşip eşleşmediğine bakar.
        for(x=0;x<10;x++){
            for(a=0;a<1;a++){
                if(str[z]==matrix_trigram_strings[x][a] && str[z+1]==matrix_trigram_strings[x][a+1] && str[z+2]==matrix_trigram_strings[x][a+2]){       // Eşleşme sağlandığında ilgili trigramın frekansını bir arttırır.
                    calculated_frequencies[x+10]=calculated_frequencies[x+10]+1;
                   // printf("\n \"%s\" metni icinde %c%c%c trigrami %f frekansina sahiptir..",str, matrix_trigram_strings[x][a],matrix_trigram_strings[x][a+1],matrix_trigram_strings[x][a+2],calculated_frequencies[x+10]);
                }
            }
        }
    }
}

void calculate_distances()                         //Frekanslar arası uzaklık hesaplayan yardımcı fonksiyonumuzu açıyoruz.
{   printf("\n ===================================\n");
float step1 =0;
float step2 =0;
 float m1[20],m2[20] ;

int x,y;
    for(x=0;x<20;x++){
        {
           m1[x]=     pow(frequency_eng[x]-calculated_frequencies[x],2);        //Öklid uzaklık hesabı için gerekli olan üs alma fonksiyonumuzu, pow, kullandık.
           m2[x]=     pow(frequency_germ[x]-calculated_frequencies[x],2);       /* for döngüsüyle verilmiş İngilizce frekanslardan metinden bulduğumuz frekansları çıkardık ve karesini aldık ve m1 dizisine atadık.
                                                                                    ve verilmiş Almanca frekanslardan metinden bulduğumuz frekansları çıkardık ve karesini aldık ve m2 dizisine atadık.*/
        }
}

 for(y=0;y<20;y++){                       //Buradaki for döngüsüyle atadığımız m1 ve m2 dizisindeki elamanları kendi dizilerinde topladık ve kendi dizilerine atadık.
    step1+=m1[y];
    step2+=m2[y];
}
//printf("%f %f toplamlar\n",stepl,step2);

distances [0] =sqrt(step1);                   //Öklid hesabının son adımı olarak topladığımız dizi elemanlarının karekökünü alıyoruz ve tanımlı distances[2] dizisine sırasıyla atıyoruz.
distances [1] =sqrt(step2);

/* printf("%f %f  koku\n",step1,step2);
Programı yazım aşamasında 'printf' fonksiyonu yardımıyla adımlarızın doğruluğunu komut isteminde kontrol ettik */

printf(" %f: Ingilizce frekans uzakligi \n %f: Almanca frekans uzakligi \n",distances[0],distances[1]);


}

void detect_lang()                               //Hangi dile mensup olduğunu seçen yardımcı fonksiyonumuzu açıyoruz.
{   printf("\n ========Tahmin Yukleniyor...========\n");
    while(1){
    sleep(3);
        if(distances [0]<distances [1])             //Program if-else bloklarıyla, distances dizisinin ilk değeri ikinci değerinden küçükse İngilizce; büyükse Almanca diline yönlendiriyor.
        printf("%s",languages[0]);
        else
        printf("%s",languages[1]);
    break;                                      //sleep komutuyla 3 saniye beklemeye aldığımız while döngüsünü break komutuyla kırdık.
    }
}

