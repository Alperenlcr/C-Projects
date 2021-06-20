#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15

void driver(int text_len, double time[SIZE], double complexity_array[SIZE], int index);
double KMPSearch(char* pattern, char* text, int M, int N);
double values_array(char* pattern, int M, int* values);
char* random_string_create(int len);
int get_base(int base, int ex);
void output(double time[SIZE], double complexity_array[SIZE]);
void sharp_digits(double number);

int main()
{
    srand(time(NULL));
    double time[SIZE], complexity_array[SIZE];  // algoritmanin zaman ve karmasiklik analizlerini saklamak icin
    driver(2, time, complexity_array, 0);
    output(time, complexity_array); // algoritmanin zaman ve karmasiklik analizlerini yaziyor
    return 0;
}

// algoritmayi yoneten fonksiyon
void driver(int text_len, double time[SIZE], double complexity_array[SIZE], int index)
{
    /*
    random olusturulan icinde arama yapilacak stringler 10^2 10^3 10^4 10^5 10^6 uzunluklarinda
    random olusturulan aranacak stringler 10^1 10^2 10^3 10^4 10^5 uzunluklarinda
    substring aramayi textlerden kisa butun patternler icin yapacagiz
    */
    int pattern_len;
    if (text_len == 7)      // rekursifligin durma kosulu
        return;
    char* text;
    char* pattern;
    text = random_string_create(get_base(10, text_len));        // text olusturma
    for ( pattern_len = 1; pattern_len < text_len; pattern_len++)   // text'den kisa butun patternleri okumak icin dongu
    {
        pattern = random_string_create(get_base(10, pattern_len));     // pattern olusturma
        clock_t tic = clock();      // zaman sayaci baslatma
        complexity_array[index] = KMPSearch(pattern, text, get_base(10, pattern_len), get_base(10, text_len));     // stringleri ve uzunluklarini algoritmaya gonderme ve complexity donutunu alma
        clock_t toc = clock();      // zaman sayaci bitirme
        time[index++] = (double)(toc - tic) / CLOCKS_PER_SEC;   // zamani kaydetme
    }
    driver(text_len+1, time, complexity_array, index);   // bir sonraki test icin fonksiyonu tekrarlama
}

// algoritma
double KMPSearch(char* pattern, char* text, int M, int N)
{
    // M -> pattern uzunlugu        N -> text uzunlugu
    double complexity;
    int i = 0; // text'in indexi
    int j = 0; // pattern'in indexi
    int counter = 0;    // kac kere tekrar ettigini bulmak icin
    int* values;
    values = malloc(M * sizeof(int));   // bu dizi patterndeki prefix suffix durumlarina gore deger tutacak
    complexity = values_array(pattern, M, values);  // values dizisini doldurma, complexity'i de donduruyor
    printf("pattern uzunlugu -> %d   text uzunlugu --> %d",M, N);
    printf("\n");
    while (i < N)   // text'de ilerleme
    {
        complexity ++;
        if (pattern[j] == text[i])  // ayniysa i ve j artiyor
        {
            j++;
            i++;
        }

        if (j == M)     // patternin son elemanina kadar ayni gittiyse substring bulmus oluyoruz
        {
            //printf("Found pattern at index %d \n", i - j);
            counter ++;
            j = values[j - 1];      // mesela text'imiz ABABABAB ve pattern'imiz ABAB ise prefix ve suffix ayniligindan dolayi j'yi values'daki indexe esitleyip ayniligin oldugu yere kadar tekrar kontrol etmiyoruz
        }

        // j ve i eslestikten sonra birer artmis haliyle eslememe durumu
        else if (pattern[j] != text[i] && i < N)
        {
            // j yi bir onceki prefix'in baslangicina aktarma
            if (j != 0)
                j = values[j - 1];
            else
                i = i + 1;
        }
    }
    printf("Found %d times.\n", counter);
    return complexity;
}

// values'u verilen pattern gore dolduruyor
// pattern'in icindeki tekrarlari saklamak icin yapiyoruz.
double values_array(char* pattern, int M, int* values)
{
    // en sonki en uzun prefix ve suffix'in uzunlugu
    int len = 0;
    double complexity=0;
    values[0] = 0;  // 0 olmak zorunda

    // patterndeki tekrarlarin yerlerini saklamak icin gerekli bilgilerin values dizisine dolduruldugu dongu
    int i = 1;
    while (i < M)
    {
        complexity ++;
        if (pattern[i] == pattern[len]) // substring in kaldigimiz yerindeki yeni harfi stringde kaldigimiz yerdeki harfle ayni mi
        {
            len++;
            values[i] = len;        // KMP search'te mesela patternin sonuna kadar geldigimizde ve eslesmediginde, pattern'in basina donmek yerine eslesmeyen harfin values'daki index degerine geri donucez pattern'de
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = values[len - 1];      // eslesme olmadi ama len'nin icindeki tekrara gore len'i guncelliyoruz
                // i'yi arttirmiyoruz
            }
            else // if (len == 0)
            {
                values[i] = 0;      // herhangi bir benzerlik durumu kalmadiginda
                i++;                // pattern bitene kadar devam
            }
        }
    }
    return complexity;
}

// ust alma fonksiyonu
int get_base(int base, int ex)
{
    if (ex == 0)
        return 1;
    else if (ex % 2)
        return base * get_base(base, ex - 1);
    else
    {
        int temp = get_base(base, ex / 2);
        return temp * temp;
    }
}

// Algoritmamizi uzun stringler ile siniyoruz ve bunlari random olusturuyoruz.
// fonksiyona gonderilen parametreye gore farkli uzunlunluklarda dinamik string olusturup geri donduruyor.
char* random_string_create(int len)
{
    char* string;
    int i, temp;
    string = malloc(len*sizeof(char)); // yer acma
    for ( i = 0; i < len; i++)
    {
        /*
        temp = rand()%52;
        if (rand()%2==0)    // buyuk kucuk harf icin
            string[i] = 'a' + temp/2;
        else
            string[i] = 'A' + temp/2;
        */
        string[i] = 'A' + rand()%2;
        // bulmasi icin 2 yaptim
        // yoksa nadiren buluyor
    }
    return string;
}

// tablo yazdirma
void output(double time[SIZE], double complexity_array[SIZE])
{
    printf("\n\t\tN\t\t\t  M\n");
    int i, j, index = 0;
    for ( i = 2; i < 7; i++)
    {
        for ( j = 1; j < i; j++)
        {
            printf("TEXT length : 10^%d     PATTERN length : 10^%d      RUNTIME (seconds) : %f    COMPLEXITY : %7d       HISTOGRAM(digits) : ", i, j, time[index], (int)complexity_array[index]);
            sharp_digits(complexity_array[index]);  // complexity'nin basamak sayisi ile histogram olusturuyoruz.
            printf("\n");
            index ++;
        }
    }
}

// verilen sayinin basamak sayisi kadar '#' yazdiran fonksiyon
void sharp_digits(double number)
{
    int digits = 0;
    while (number > 1)
    {
        number /= 10;
        digits ++;
    }
    for (; digits > 0; digits--)
        printf("#");
}
