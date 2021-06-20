#include <stdio.h>
#include <math.h>

// fonksiyonlarin prototipleri
void BirinciCozum();    // 1. soru cozumu
void IkinciCozum(); // 2. soru cozumu
void UcuncuCozum(); // 3. soru cozumu
float DorduncuCozumDenklem(float);  // 4. soru yardimci fonksiyonu
float DorduncuCozumDenklemTurevi(float);    // 4. soru yardimci fonksiyonu
void DorduncuCozum();   // 4. soru cozumu
void BesinciCozum();    // 5. soru cozumu
void Aciklamalar(int);  // Soru aciklamalarini yazdiran fonksiyon
void AciklamalarMenusu();   // Aciklamalar menusu
void Giris();   // Ilk gozukecek ekran
void menu();    // Menu

int main(){
    Giris();
    menu();
    return 0;
}

void menu(){
    printf("      PROJE MENUSU\n");
    printf("(Seciminizi yapip yanindaki numarayi giriniz.)\n");
    printf("1 ) 0 dereceden 90 dereceye kadar acilarin, onar artimli olarak sin, cos, tan, cotan degerlerini iceren bir matrisi olusturan C programi.\n");
    printf("2 ) y=(x^5+4)/(x^3+2) fonksiyon degerlerini x=(-40,40) araligi icin birer artimla hesaplayan ve bu aralik icin fonksiyonun maximum ve minimum degerlerini bulan C programi.\n");
    printf("3 ) Bir kare matrisin esas kosegeni uzerindeki elemanlarinin toplamini ve diger kosegen uzerindeki elemanlarinin carpimini en az islem sayisi ve en az cevrimle hesaplatan C programi.\n");
    printf("4 ) y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlarinin varsa kesim noktalarindan birini bulan C programi.\n");
    printf("5 ) prim hesaplama C programi.\n");
    printf("6 ) Gelistirilen kod ile ilgili aciklamalar.\n");
    printf("7 ) Cikis\n\n");

    int sec, bitti = 0;
    scanf("%d", &sec);

    switch (sec){
    case 1:
        BirinciCozum();
        break;
    case 2:
        IkinciCozum();
        break;
    case 3:
        problem_3();
        break;
    case 4:
        DorduncuCozum();
        break;
    case 5:
        BesinciCozum();
        break;
    case 6:
        AciklamalarMenusu();
        break;
    case 7:
        bitti = 1;
        break;
    default:
        printf("\n\nYanlis deger girdiniz.\n");
        // yanlis girildigi gozukmesi icin biraz bekletiyoruz.
        printf("\nHerhangi bir tusa basiniz..\n");
        getchar();getchar();
        break;
    }
    if ( bitti == 0 ){
        printf("\nHerhangi bir tusa basiniz..\n");
        getchar();getchar();
        system("cls");
        menu();
    }
}

void Giris(){
    printf("\n\n      ***Gazi Universitesi***\n\n   Algoritmalar ve Yapisal Programlamaya Giris\n\n      Kadir Emre Orenli\n\n         PROJE\n\n\n");
    printf("\n\nHerhangi bir tusa basiniz..\n");
    getchar();
    system("cls");
}

void Aciklamalar(int SoruSayisi){
    
    if(SoruSayisi == 1)
        printf("\n\nSORU 1 \n \n- derece degiskeni 0-10-20-30-40-50-60-70-80-90 olarak dongude arttiriliyor, radyana donusturuluyor ve sin cos tan fonksiyonlari kullaniliyor.\n\n- 0-10-20-30-40-50-60-70-80-90 aci derecelerinin radyan karsiliklarinin istenilen trigonometrik fonksiyonlarindaki ciktilari yazdiriliyor.\n\n- Tabloda degerler yazdiriliyor.\n\n");

    if(SoruSayisi == 2)
        printf("\n\nSORU 2 \n \n- sec yazdirmak durumunu soruyor, x 1'er 1'er artiyor, MinimumX en kucuk degerin ciktigi x degerini tutuyor, MaximumX en buyuk degerini x degerini tutuyor, deger denklemden gelen degeri tutuyor, min en kucuk goruntusunu tutuyor, max en buyuk goruntusunu tutuyor.\n\n- dongu icinde x degerleri [-40,40] araliginda 1'er 1'er arttiriliyor. Her yeni dongude degiskenler kiyaslaniyor ve degistirilebiliyor.\n\n- Kullanican gelen istege gore x ve fonksiyondaki degeri yazdirilabiliyor. max, MaximumX ve min, MinimumX degiskenleri yazdiriliyor.\n\n");

    if(SoruSayisi == 3)
        printf("\n\nSORU 3 \n \n- Matris degiskenini max boyut olarak 50 yaptim, toplam ve carpim hesaplanan sonuclari tutuyor, uzunluk dongu tur sayisini belirliyor kullanicidan aliniyor.\n\n- Matris eleman sayisi kadar  donulen dongude matrisler okunuyor. Ikinci kez matris eleman sayisi kadar  donulen dongude ise matris yazdiriliyor ve hesaplamalar yaptiriliyor.\n\n- Girilen matris ve problemin sonucu yazdiriliyor.\n\n");

    if(SoruSayisi == 4)
        printf("\n\nSORU 4 \n \n- KiyaslanacakHata kullanicidan aliniyor, x0 kullanicidan aliniyor, x1Ciktisi x1 in denklemdeki degeri, x1 x(n+1) oluyor ama her dongude x0 x1 e esitleniyor sonra yeni x1 degeri uretiliyor, Hata hesaplanan hata oluyor. DorduncuCozumDenklem ve DorduncuCozumDenklemTurevi fonksiyonlarini kullaniyor.\n\n- Newton-Rapshon metodu ile soru cozulmustur.\n\n- Kullanicinin istegine bagli islemler yapilirken her turdaki bilgiler yazdirilabilir. Tanimsizlik durumlarinda uyari verilir sonra tekrar bastan fonksiyona girilir. Cevap tur sayisi ile beraber yazdirilir.\n\n");

    if(SoruSayisi == 5)
        printf("\n\nSORU 5 \n \n- SatisMiktari girilen degeri tutuyor, IkiBucuk 2.5 ile carpilacak sayiyi tutuyor, Iki 2 ile carpilacak sayiyi tutuyor, BirBucuk 1.5 ile carpilacak sayiyi tutuyor.\n\n- SatisMiktari na bagli if kosullarinda atamalar yapiliyor. Sonra carpilip yazdiriliyor.\n\n- SatisMiktari na bagli yapilan hesaplama bir cumlede aciklaniyor ve hesaplanan prim yazdiriliyor.\n\n");

    if(SoruSayisi == 6)
        printf("\n\nGenel Aciklamalar\n \nKodda fonksiyonlara isler yaptiriliyor. Ana fonksiyonlardan diger fonksiyonlar calistiriliyor.\n\n");
}

void AciklamalarMenusu(){
    system("cls");
    printf("\n\n1) SORU 1      2) SORU 2      3) SORU 3\n\n\n4) SORU 4      5) SORU 5      6) Genel\n\n");

    int SoruSayisi;
    printf("\n\nLUTFEN ACIKLAMASINI GORUNTULEMEK ISTEDIGINIZ BOLUMUN NUMARISINI GIRINIZ. ANA MENU ICIN 9 GIRINIZ\n");
    scanf("%d", &SoruSayisi);

    if( SoruSayisi == 9 ){
        return;
    }
    printf("\nHerhangi bir tusa basiniz..\n");
    getchar();getchar();
    AciklamalarMenusu();
}

void BirinciCozum(){
    printf("Problem 1\n---------\n0-10-20-30-40-50-60-70-80-90 dereceleri icin sin, cos, tan, cotan degerlerini iceren bir matris olusturan C programi...\n\n");
    printf("            ACI VE TRIGONOMETRİK DEGERLERİ\n\n");
    printf("ACI      SIN      COS      TAN      COTAN\n");

    int i;
    float derece, radyan;
    for ( i = 0; i < 5; i++){
        printf("***********   ");
    }
    printf("\n");
    for ( i = 0; i <= 9; i++){
        derece = 10 * i;
        radyan = (derece*3.14)/180;
        printf("%f   ", derece);
        printf("%f   ", sin(radyan));
        printf("%f   ", cos(radyan));

        // ayricalikli durumlar        
        if (derece == 90)
            printf("INFINITY      ");
        else
            printf("%f   ", tan(radyan));
            
        if (derece == 0)
            printf("INFINITY\n");
        else
            printf("%f\n", 1/tan(radyan));

    }
    
}

void IkinciCozum(){
    float deger, min = 10000, max = -10000;
    int x, MinimumX, MaximumX;
    char sec;
    printf("\n\nProblem 2\n---------\ny=(x^5+4)/(x^3+2) fonksiyon degerlerini x=(-40,40) araligi icin birer artimla hesaplayan ve bu aralik icin fonksiyonun maximum ve minimum degerlerini bulan C programi\n\n");
    printf("x=(-40,40) Araligindaki y degerleri goruntulensin mi (E/H) : ");
    scanf(" %c", &sec);
    
    for ( x = -40; x < 41; x++){
        deger = ((x*x*x*x*x+4) / (x*x*x+2));

        if (sec == 'e'){
            printf("(x = %d    y = %f)\n", x, deger);
        }
        if (max < deger){
            max = deger;
            MaximumX = x;
        }
        if (min > deger){
            min = deger;
            MinimumX = x;
        }
    }
    printf("\n\nFonksiyon, bu aralikta en kucuk (x= %d) icin %f degerini almaktadir.\n", MinimumX, min);
    printf("Fonksiyon, bu aralikta en buyuk (x= %d) icin %f degerini almaktadir.\n", MaximumX, max);
}

void UcuncuCozum(){
    int matris[50][50], i, j, toplam=0, carpim=1, uzunluk;
    printf("\nProblem 3\n---------\nBir kare matrisin esas kosegeni uzerindeki elemanlarinin toplamini ve diger kosegen uzerindeki elemanlarin carpimini hesaplatan C programi\n\n");    
    printf("\nGirilecek kare matrisin bir kenarininda kac eleman var : ");
    scanf("%d", &uzunluk);

    printf("\nMatris elemanlarini 1'er 1'er giriniz.\n");
    for ( i = 0; i < uzunluk; i++){
        for ( j = 0; j < uzunluk; j++){
            scanf("%d", &matris[i][j]);
        }
    }

    printf("\n");

    for ( i = 0; i < uzunluk; i++){
        for ( j = 0; j < uzunluk; j++){
            printf("%d   ", matris[i][j]);
            if (uzunluk == i + j + 1){
                carpim *= matris[i][j];
            }            
            if (j == i){
                toplam += matris[i][j];
            }
        }
        printf("\n");
    }

    printf("\n\nMatrisin esas kosegeni uzerindeki sayilarin toplami = %d", toplam);
    printf("\nMatrisin diger kosegeni uzerindeki sayilarin carpimi = %d\n", carpim);
}

float DorduncuCozumDenklem(float x){
    return x*x*x - x*x - x + 2;
}

float DorduncuCozumDenklemTurevi(float x){
    return 3*x*x - 2*x - 1;
}

void DorduncuCozum(){
    printf("Problem 4\n---------\nVerilen y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlarinin varsa kesim noktalarini bulan C programi.\n\n");
    
    float KiyaslanacakHata, x0, x1Ciktisi, x1, Hata=1000;;
    printf("\nKiyaslanacak hata miktari giriniz : ");
    scanf("%f", &KiyaslanacakHata);
    printf("\nIlk x degerini giriniz : ");
    scanf("%f", &x0);

    int i=0;
    char sec;
    if (DorduncuCozumDenklemTurevi(x0) == 0){
        printf("\nGirdiginiz baslangic degeri Newton-Rapshon Metodu'nu belirsizlige goturuyor!\nLutfen yeni bir baslangic degeri saglayin!\n\n");
        DorduncuCozum();
    }
    else{
        printf("Hesaplama asamasi ekranda gosterilsin mi? (E/H) : ");
        scanf(" %c", &sec);
        while ( KiyaslanacakHata < Hata ){
            i++;
            x1 = x0 - (DorduncuCozumDenklem(x0) / DorduncuCozumDenklemTurevi(x0));
            x1Ciktisi = DorduncuCozumDenklem(x1);
            Hata =  x1Ciktisi;
            if (Hata < 0)
                Hata *= -1;
            
            if (sec != 'h'){
                printf("\n %d. Tur >> Hata miktari %f iken bulunan deger : f(%f) = %f \n", i, Hata, x1, x1Ciktisi);
            }
            x0 = x1;
        }
        if (sec == 'h'){
            printf("\n %d. Tur >> Hata miktari %f iken bulunan deger : f(%f) = %f \n", i, Hata, x1, x1Ciktisi);
        }
    }
}

void BesinciCozum(){
    int IkiBucuk, Iki, BirBucuk, SatisMiktari;
    printf("Problem 5\n---------\nBir satis elemani asagidaki kurallara gore prim almaktadir:\nSatis <= 50 ise Prim = Satis * 1.5$\nSatis <= 100 ise Prim = 50 * 1.5$ + (Satis-50) * 2$\nSatis > 100 ise Prim = 50 * 1.5$ + 50 * 2$ + (Satis-100) * 2.5$\n\nBu kurallara gore bir satis elemaninin alacagi primi hesaplayan C programi...\n\nHesaplamalar\n------------\nSatis miktarini giriniz : ");
    scanf("%d", &SatisMiktari);

    if(SatisMiktari <= 50){
        IkiBucuk = 0;
        Iki = 0;
        BirBucuk = SatisMiktari;
        printf("Satis elemaninin yaptigi satisin %d parcalik kismi icin prim 1.5$'dir", BirBucuk);
    }    
    if (SatisMiktari > 50 && SatisMiktari < 100){
        IkiBucuk = 0;
        Iki = SatisMiktari - 50;
        BirBucuk = 50;
        printf("Satis elemaninin yaptigi satisin 50 parcalik kismi icin prim 1.5$, diger %d parcalik kismi icin prim 2$'dir", Iki);
    }
    if (SatisMiktari >= 100){
        IkiBucuk = SatisMiktari - 100;
        Iki = 50;
        BirBucuk = 50;
        printf("Satis elemaninin yaptigi satisin 50 parcalik kismi icin prim 1.5$, diger 50 parcalik kismi icin prim 2$, geri kalan %d parcalik kismi icin ise 2.5$'dir", IkiBucuk);
    }
    printf("\n\nHesaplanan Prim = %f $\n\n", (BirBucuk*1.5 + Iki*2.0 + IkiBucuk*2.5));
}
