#include <stdio.h>
#include <math.h>
#include <stdlib.h> // exit() fonksiyonu icin

// sleep() fonksiyonu icin gereken kutuphaneyi ekleme
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define PI 3.14159265359
#define matris_boyutu 100

// bu fonksiyonun amaci terminal ekranini temizlemektir. Isletim sistemine gore komut degistigi icin kosul kullandim.
void ekran_temizleme()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// bu fonksiyonu ekrandakilerin hizlica gecmemesi icin olusturdum.
void bekletme()
{
    printf("\nGecmek icin enter'a basiniz.\n");
    getchar();
    getchar();
}

void problem_1()
{
    printf("Problem 1\n---------\n0-10-20-30-40-50-60-70-80-90 dereceleri icin sin, cos, tan, cotan degerlerini iceren bir matris olusturan C programi...\n\n");
    printf("\t\t\t\t<<< TABLO >>>\n\n");
    printf("ACI\t\tSIN\t\tCOS\t\tTAN\t\tCOTAN\n");

    int i;
    float aci_derece, aci_radyan;
    for ( i = 0; i < 5; i++)
    {
        printf("-----------\t");
    }
    printf("\n");
    for ( i = 0; i < 10; i++)
    {
        aci_derece = 10 * i;
        aci_radyan = (aci_derece*PI)/180;
        printf("%f\t", aci_derece);
        printf("%f\t", sin(aci_radyan));
        printf("%f\t", cos(aci_radyan));
        
        // PI sayisi sonsuza kadar gittigi icin radyana donusturmede tam olarak PI/2 elde edemiyoruz.
        // bu yuzden de cikti olarak inf cikarmiyor cot(0) da bu durum yasanmiyor cunku 0 elde edilebiliyor.
        if (aci_derece == 90)
            printf("inf\t\t");
        else
            printf("%f\t", tan(aci_radyan));
        printf("%f\n", 1/tan(aci_radyan));
    }
}

float problem_2_denklemi(float x)
{
    return (pow(x,5)+4) / (pow(x,3)+2);
}

void problem_2()
{
    char secim;
    int x, min_x, max_x;
    float deger, min = 9999.0, max = -9999.0;
    printf("\n\nProblem 2\n---------\ny=(x^5+4)/(x^3+2) fonksiyon degerlerini x=(-40,40) araligi icin birer artimla hesaplayan ve bu aralik icin fonksiyonun maximum ve minimum degerlerini bulan C programi\n\n");
    printf("x=(-40,40) Araligindaki y degerleri goruntulensin mi (e/h)?\n");
    scanf(" %c", &secim);
    
    if (secim == 'e')
    {
        for ( x = -40; x <= 40; x++)
        {
            deger = problem_2_denklemi((float)x);

            printf("(x = %3d    y = %11f)\t\t", x, deger);
            if ( (x-1) % 3 == 0)
            {
                printf("\n");
            }
            
            if (max < deger)
            {
                max = deger;
                max_x = x;
            }
            if (min > deger)
            {
                min = deger;
                min_x = x;
            }
        }
    }
    else
    {
        for ( x = -40; x <= 40; x++)
        {
            deger = problem_2_denklemi(x);
            if (max < deger)
            {
                max = deger;
                max_x = x;
            }
            if (min > deger)
            {
                min = deger;
                min_x = x;
            }
        }
    }
    printf("\n\nFonksiyon, bu aralikta en kucuk (x= %d) icin %f degerini almaktadir.\n", min_x, min);
    printf("Fonksiyon, bu aralikta en buyuk (x= %d) icin %f degerini almaktadir.\n", max_x, max);
}

void problem_3()
{
    int matris[matris_boyutu][matris_boyutu];
    int i, j, toplam=0, carpim=1, boyut;
    printf("\nProblem 3\n---------\nBir kare matrisin esas kosegeni uzerindeki elemanlarinin toplamini ve diger kosegen uzerindeki elemanlarin carpimini hesaplatan C programi\n\n");    
    printf("\nGirilecek kare matrisin bir kenar uzunlugu : ");
    scanf("%d", &boyut);

    // matris alma
    printf("\nMatris degerlerini teker teker giriniz.\n");
    for ( i = 0; i < boyut; i++)
    {
        for ( j = 0; j < boyut; j++)
        {
            scanf("%d", &matris[i][j]);
        }
        
    }
    
    //matris yazdirma hesaplamalari yapma
    for ( i = 0; i < boyut; i++)
    {
        for ( j = 0; j < boyut; j++)
        {
            printf("%5d", matris[i][j]);
            if (i == j)
            {
                toplam += matris[i][j];
            }
            if (i + j + 1 == boyut)
            {
                carpim *= matris[i][j];
            }            
        }
        printf("\n");
    }

    printf("\n\nGirdiginiz matrisin esas kosegeni uzerindeki sayilarin toplami = %d", toplam);
    printf("\nGirdiginiz matrisin diger kosegeni uzerindeki sayilarin carpimi = %d\n", carpim);
}

float problem_4_denklem(float x)
{
    // y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) denklemlerinden asagidaki denklem elde edilir.
    return x*x*x - x*x - x + 2;
}

float problem_4_denklemin_turevi(float x)
{
    return 3*x*x - 2*x - 1;
}

void problem_4(int ilk_defa)
{
    if (ilk_defa)
    {
        printf("Problem 4\n---------\nVerilen y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlarinin varsa kesim noktalarini bulan C programi.\n\n");
    }
    // gerekli girdileri alma
    float istenilen_hata_miktari, x0;
    printf("\nIstenilen hata miktari giriniz (0.001 onerilir.) : ");
    scanf("%f", &istenilen_hata_miktari);
    printf("\nBakilacak ilk x degerini giriniz (4 onerilir) : ");
    scanf("%f", &x0);

    // cozum
    int i=0;
    float x1_degeri, x1, hata_miktari=99;
    char secim;
    if (problem_4_denklemin_turevi(x0) == 0)
    {
        printf("\nGirdiginiz baslangic degeri Newton-Rapshon Metodu'nu belirsizlige goturuyor!\nLutfen yeni bir baslangic degeri saglayin!\n\n");
        problem_4(0);
    }
    else
    {
        printf("Hesaplama asamasi ekranda gosterilsin mi? (e/h) : ");
        scanf(" %c", &secim);
        while ( hata_miktari > istenilen_hata_miktari )
        {
            x1 = x0 - (problem_4_denklem(x0) / problem_4_denklemin_turevi(x0));
            x1_degeri = problem_4_denklem(x1);
            hata_miktari =  fabs(x1_degeri);
            i++;
            
            if (secim == 'e')
            {
                printf("\n %d. Iterasyon - Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", i, hata_miktari, x1, x1_degeri);
            }
            x0 = x1;
        }
        if (secim != 'e')
        {
            printf("\n %d. Iterasyon - Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", i, hata_miktari, x1, x1_degeri);
        }
    }
}

void problem_5()
{
    int satis_miktari, elliden_kucuk, elli_yuz, yuzden_buyuk;
    printf("Problem 5\n---------\nBir satis elemani asagidaki kurallara gore prim almaktadir:\n");
    printf("Satis <= 50 ise Prim = Satis * 1.5$\nSatis <= 100 ise Prim = 50 * 1.5$ + (Satis-50) * 2$\nSatis > 100 ise Prim = 50 * 1.5$ + 50 * 2$ + (Satis-100) * 2.5$\n\n");
    printf("Bu kurallara gore bir satis elemaninin alacagi primi hesaplayan C programi...\n\nHesaplamalar\n------------\n");
    printf("Satis miktarini giriniz : ");
    scanf("%d", &satis_miktari);

    if (satis_miktari > 100)
    {
        elliden_kucuk = 50;
        elli_yuz = 50;
        yuzden_buyuk = satis_miktari - 100;
        printf("Satis elemaninin yaptigi satisin 50 parcalik kismi icin prim 1.5$, diger 50 parcalik kismi icin prim 2$, geri kalan %d parcalik kismi icin ise 2.5$'dir", yuzden_buyuk);
    }
    else if (satis_miktari > 50)
    {
        elliden_kucuk = 50;
        elli_yuz = satis_miktari - 50;
        yuzden_buyuk = 0;
        printf("Satis elemaninin yaptigi satisin 50 parcalik kismi icin prim 1.5$, diger %d parcalik kismi icin prim 2$'dir", elli_yuz);
    }
    else
    {
        elliden_kucuk = satis_miktari;
        elli_yuz = 0;
        yuzden_buyuk = 0;
        printf("Satis elemaninin yaptigi satisin %d parcalik kismi icin prim 1.5$'dir", elliden_kucuk);
    }    
    printf("\n\nHesaplanan Prim = %.3f $\n\n", (elliden_kucuk*1.5 + elli_yuz*2.0 + yuzden_buyuk*2.5));
}

// burda problemler icin aciklamalar yazdiriliyor.
void aciklama_yazdir(int problem_numarasi)
{
    switch (problem_numarasi)
    {
    case 1:
        printf("\n\nPROBLEM 1 icin Aciklamalar\n--------------------------\n");
        printf("Degiskenler : aci_derece onar onar arttirilmak icin, aci_radyan math.h kutuphanesi radyan kullandigi icin var.\n\n");
        printf("Yontem : For dongusu icinde derece_aci degiskeni onar onar arttiriliyor. Dongu on kez donuyor. derece_aci yi radyana dondurup derece_radyanda sakliyoruz. math.h kutuphanesinden gelen trigonometrik fonksiyonlari kullanarak sonuclari yazdiriyoruz.\n\n");
        printf("Ekran ciktisi : Matris seklinde bir tabloda degerler yazdiriliyor. Kesirli degerler yazdiriliyor.\n\n");
        break;

    case 2:
        printf("\n\nPROBLEM 2 icin Aciklamalar\n--------------------------\n");
        printf("Degiskenler :           \n\n");
        printf("Yontem :            \n\n");
        printf("Ekran ciktisi :         \n\n");
        break;

    case 3:
        printf("\n\nPROBLEM 2 icin Aciklamalar\n--------------------------\n");
        printf("Degiskenler :           \n\n");
        printf("Yontem :            \n\n");
        printf("Ekran ciktisi :         \n\n");
        break;

    case 4:
        printf("\n\nPROBLEM 2 icin Aciklamalar\n--------------------------\n");
        printf("Degiskenler :           \n\n");
        printf("Yontem :            \n\n");
        printf("Ekran ciktisi :         \n\n");
        break;

    case 5:
        printf("\n\nPROBLEM 2 icin Aciklamalar\n--------------------------\n");
        printf("Degiskenler :           \n\n");
        printf("Yontem :            \n\n");
        printf("Ekran ciktisi :         \n\n");
        break;

    case 6:
        printf("\n\nGenel Aciklamalar\n--------------------------\n");
        printf("        \n\n");
        break;

    default:
        break;
    }
}

// aciklamalar yazdirilmak istendiginde calistirilan menu fonksiyonu
void aciklamalar_menusu()
{
    ekran_temizleme();
    printf("\n\n1) Problem 1\t\t2) Problem 2\t\t3) Problem 3\n\n");
    printf("\n4) Problem 4\t\t5) Problem 5\t\t6) Genel\n\n");

    int problem_numarasi;
    printf("\n\nLUTFEN ACIKLAMASINI GORUNTULEMEK ISTEDIGINIZ BOLUMUN NUMARISINI GIRINIZ. ANA MENU ICIN 9 GIRINIZ\n");
    scanf("%d", &problem_numarasi);

    if (problem_numarasi > 0 && problem_numarasi < 7)
    {
        aciklama_yazdir(problem_numarasi);
    }
    else if( problem_numarasi == 9 )
    {
        return;
    }
    else
    {
        // yanlis deger girilmesi durumunda calisiyor.
        printf("\n\nYanlis girdiniz. Ekran yenilenince tekrar deneyiniz.\n");
        sleep(2);
    }
    bekletme();
    aciklamalar_menusu();
}

// bu fonksiyonun amaci baslangic sayfasindaki yazilari yazdirmaktir.
void baslangic_ekrani()
{
    printf("\n\n\t\t***Gazi Universitesi***\n\n");
    printf("\tAlgoritmalar ve Yapisal Programlamaya Giris\n\n");
    printf("\t\tMetin Seckin Ozturk\n\n");
    printf("\t\t\tPROJE\n\n\n");

    printf("\n\nIlerlemek icin enter'a basiniz.\n");
    getchar();

    ekran_temizleme();
}

// bu fonksiyon menuden secilene gore baska fonksiyonlari calistiriyor.
void menu()
{
    printf("\t\tPROJE MENUSU\n");
    printf("(secmek icin yandaki numaralarini giriniz.)\n");
    printf("1 ) 0 dereceden 90 dereceye kadar acilarin, onar artimli olarak sin, cos, tan, cotan degerlerini iceren bir matrisi olusturan C programi.\n");
    printf("2 ) y=(x^5+4)/(x^3+2) fonksiyon degerlerini x=(-40,40) araligi icin birer artimla hesaplayan ve bu aralik icin fonksiyonun maximum ve minimum degerlerini bulan C programi.\n");
    printf("3 ) Bir kare matrisin esas kosegeni uzerindeki elemanlarinin toplamini ve diger kosegen uzerindeki elemanlarinin carpimini en az islem sayisi ve en az cevrimle hesaplatan C programi.\n");
    printf("4 ) y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlarinin varsa kesim noktalarindan birini bulan C programi.\n");
    printf("5 ) prim hesaplama C programi.\n");
    printf("6 ) Gelistirilen kod ile ilgili aciklamalar.\n");
    printf("7 ) Aciklamalarin kayitli oldugu dosyaya nasil bakabilirim.\n");
    printf("8 ) Cikis\n\n");

    int secim, cikis = 0;
    scanf("%d", &secim);

    switch (secim)
    {
    case 1:
        problem_1();
        break;
    case 2:
        problem_2();
        break;
    case 3:
        problem_3();
        break;
    case 4:
        problem_4(1);
        break;
    case 5:
        problem_5();
        break;
    case 6:
        aciklamalar_menusu();
        break;
    case 7:
        printf("\n\nAciklamalarin kayitli oldugu dosyayi goruntulemek icin bulundugumuz kloserden acabilirsiniz.\n");
        break;
    case 8:
        cikis = 1;
        break;
    default:
        printf("\n\nYanlis deger girdiniz. Ekran yenilenince tekrar deneyiniz.\n");
        // yanlis girildigi gozukmesi icin biraz bekletiyoruz.
        sleep(2);
        break;
    }
    if ( !cikis )
    {
        bekletme();
        ekran_temizleme();
        menu();
    }
}

// projeyi yaparken yapabildigimce moduler yapmaya calistim cunku karmasik bir proje.
int main()
{
    baslangic_ekrani();
    menu();
    return 0;
}
