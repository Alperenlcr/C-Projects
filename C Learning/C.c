/*#include <stdio.h>
int main() {
    int a = 10;
    int b = 5;
    int c = 2;
    int x;
    printf("a:%d, b:%d, c:%d",a, b, c);
    printf("\n lütfen bir sayi giriniz:");
    scanf("\n %d",&x);
    printf("\n sayiniz:%d",x);
    float y=-3.14;
    printf("%9.3f", y);
    
}*/
/*#include<stdio.h>
int main() {
    printf("tam sayi ile kesirli bir sayi toplama!!");
    int sayi1;
    float kesir1;
    printf("\nsayi1 i belirleyiniz:");
    scanf("\n  %d", &sayi1);
    printf("\n sayi1:%d", sayi1);
    printf("kesir1 i belirleyiniz:");
    scanf("\n  %f", &kesir1);
    float sayi1artikesir1 = sayi1 + kesir1;
    printf("\n sayi1+kesir1= %1.1f", sayi1artikesir1);
}*/
/*
#include<stdio.h>
int main(){
    int x= 2;
    int y= 3;
    int z= 17;
    printf("\n%d",x+y);
    printf("\n%d",x+y-z);
    printf("\n%d",x<<2);
    printf("\n%d",x<3);
    printf("\n%d",z>>2);
    printf("\n%d",z%4);
    printf("\n%d",x==y);
    printf("\n%d",x++);
    printf("\n%d",++x);
}
*/  /*
#include<stdio.h>
int main(){
    int a = 2;
    int b = 5;
    int c = 18;
    int d = 255;
    printf("%d",a&b);
    printf("\n%d",a|b);
    printf("\n%d",c&d);
    printf("\n%d",c|d);
    int e = c|d;
    printf("\n%d",e);
    printf("\n%d",a<5&&a>0);
    printf("\n%d",a>5||a>3||a==2&&a>1);
}*/  /*
#include<stdio.h>
int main(){
    int a = 3;
    int b = 8;
    int c = 12;

}
*/  /*
#include<stdio.h>
int main(){
    int t;
    int y;
    printf("kacinci yildayiz? ");
    scanf("%d",&t);
    printf("\nkac yasindasiniz? ");
    scanf("%d",&y);
    printf("\ndogum yiliniz = %d",t-y);
}*/  /*
#include<stdio.h>
int main(){
    int a,b,c;
    printf("a^2+b^2+3c hesaplamak icin degerler giriniz.");
    printf("\na=");
    scanf("%d",&a);
    printf("\nb=");
    scanf("%d",&b);
    printf("\nc=");
    scanf("%d",&c);
    printf("cevap = %d",a*a+b*b+3*c);
    
}*/ /*
#include<stdio.h>
int main(){
    int x,y;
    printf("buyukluk kiyaslamak icin 2 sayi giriniz.\n ");
    scanf("%d%d",&x,&y);
    if(x>y){
        printf("\nbuyuk olan sayi= %d",x);
    }
    else if(x==y){
        printf("birbirine esit sayi girdiniz.");
    }
    else{
        printf("\nbuyuk olan sayi= %d",y);
    }
} */  /*
#include<stdio.h>
int main(){
    int t;
    printf("alperenin sirketindeki gunluk maasinizi ogrenmek icin gunluk calisma saatinizi giriniz= ");
    scanf("%d",&t);
    if(t<=10){
        printf("\ngunluk maasiniz = %d",t*50);
    }
    else if(10<t<=20){
        printf("\ngunluk maasiniz = %d",500+(t-10)*30);
    }
    else{
        printf("\ngunluk maasiniz = %d",800+(t-20)*20);
    }
} */  /*
#include<stdio.h>
int main() {
    printf("100 uzerinden notunuzun harf uzerinden karsiligini almak icin notunuzu giriniz = ");
    int note;
    scanf("%d",&note);
    if(note>=90)
        printf("AA");
    else if(note>=80)
        printf("BA");
    else if(note>=70)
        printf("BB");
    else
        printf("F");
    printf("\nyeni baslangiclara...");            
} */  /*
#include<stdio.h>
#include<math.h>
int main (){
    printf("dik bir ucgenin hipotenusunun uzunlugunu bulmak icin diger kenar uzunluklarini giriniz=");
    float x,y;
    scanf("%f",&x);
    printf(" , ");
    scanf("%f",&y);
    printf("\nhipotenus uzunlugu = %.3f",sqrt(x*x+y*y));
}   */  /*
#include<stdio.h>
int main(){
    printf("20 ile 50 arasi tek sayilar=");
for(int i =20;i<=50;i++){
    if(i%2==1){
        printf(" %d",i);
} }
    
}*/ /*

#include<stdio.h>
int main(){
    printf("100'den 20'ye kadar , 3'e ve 7'e tam bolunen sayilari buyukten kucuge yazalim= ");
    int i = 100;
    while (i>=20){
        if(i%3==0&&i%7==0){
            printf(" %d",i);
        //  i--;  hatalı
        }
        i--;
    }
    
}*/
/* 
#include<stdio.h>
int main () {
    printf("en buyugunu bulmak icin 3 pozitif sayi giriniz= ");
    int girilen;
    int eb = 0;
for(int i=0;i<3;i++){
    scanf(" %d",&girilen);
        if(girilen>eb)
            eb = girilen;
}   
printf("en buyuk sayi = %d",eb);
}   */  /*
#include<stdio.h>
int main(){
    printf("siz -1 girine kadar yazacaginiz tam sayilarin en buyugunu size soyleyecegim.");
    printf("\n lutfen sayi giriniz = ");
    int eb = -999999;
    int girilen = 0;
        while(girilen!=-1){
            scanf("%d",&girilen);
                if(girilen>eb){
                    eb = girilen;
                }
        printf("en buyuk sayi= %d \n",eb);
        }
} */    /*
#include<stdio.h>
int main(){
    printf("siz -1 girene kadar gireceginiz sayilarin ortalamasini bulacagim.");
    printf("lutfen tam sayilar giriniz. ");
    int toplam = 0;
    int n = 0;
    int i = 0;
    float ort;
        while(i!=-1){
            scanf("%d",&i);
            n++;
            toplam = toplam + i;
        }
    toplam++;
    n--;
    ort = toplam / n;
    printf("kac sayi girildi = %d , ortalama = %.2f\n",n,ort);
}  */  /*
#include<stdio.h>
int main(){
    printf("bir sayinin asal olup olmagini bulmam icin bir sayi giriniz = ");
    int sayi;
    scanf("%d",&sayi);
    int i;
    for(i=2;sayi>i;i++)
    {
        if(sayi%i==0)
            printf("%d asal degildir.\n",sayi);
        if(sayi%i==0) break;
    }
    if(sayi==i){
        printf("%d asaldir\n",sayi);
        i++;
    }
}   */ /*
#include<stdio.h>
int main(){
    printf("bir sayinin asal olup olmagini bulmam icin bir sayi giriniz = ");
    int a=1,b,flag=0;
    scanf("%d",&b);
    while (b>a)
    {
        a++;
        if(b%a==0)
        flag = 1;break;
    }
    if(flag==1)
        printf("%d asal degildir.",b);
    if(flag==0)
        printf("%d asaldir.",b);} 
*/  /*
#include<stdio.h>
int main(){
    printf("carpim tablosu\n");
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            printf("%d ",i*j);
        }
        printf("\n");
    }
} */ /*
#include<stdio.h>
int main(){
    printf("dik ucgen yildizlar ile\n");
    for(int i=1;i<=8;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
} */    /*
#include<stdio.h>
int main(){
    printf("dik ucgen -ters- yildizlar ile\n");
    for(int i=8;i>0;i--){
        for (int j=1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }   
} */ /*
#include<stdio.h>
int main(){
    printf("ucgen\n");
    for(int i=1;i<=8;i++){
        for(int j=1;j<=i;j++){
            printf(" ");
        }
        for(int k=8;k>=i;k--){
            printf("*");
        }
    printf("\n");    
    }
}   */ /*
#include<stdio.h>
int main(){
    printf("deneme\n");
    for (int i = 0; i < 10; i++)
    {
        //if(i==6) break;
        if (i==6)continue;
        printf("%d ",i);
    }
} */    /*
#include<stdio.h>
int main(){
    printf("(0,100)araligindaki asal sayilar= 2,");
    for(int i=1;i<100;i++){
        for(int j=2;j<i;j++){
            if(i%j==0)
            break;
            if(i==j+1)
            printf(" %d,",i);
        }
    }
}   */ /*
#include<stdio.h>
int fact(int);
int main(){
    printf("faktoriyeli bulunacak tam sayiyi giriniz = ");
    int x;
    scanf("%d",&x);
    printf("%d'in faktoriyeli = %d",x,fact(x));
}
int fact(int x){
    int sonuc=1;
    int i;
    for (int i=1; i <=x; i++)
    {
        sonuc *=i;
    }
    return sonuc;
} */ /*
#include<stdio.h>
int com(int,int);
int fact(int);
int main(){
    int x,y;
    printf("C(x,y) olucak sekilde iki sayinin kombinasyonunu hesaplamak icin iki sayi giriniz.");
    scanf("%d %d",&x,&y);
    printf("C(%d,%d) = %d",x,y,com(x,y));
}
int fact(int y){
    int fa=1;
    for(int i=1;i<=y;i++){
        fa *= i;
    }
    return fa;
}
int com(int x,int y){
    int sonuc; // !!!!!!!!!!
    int ust=1;
    for(int j=y;j>0;j--){
        ust *= x;
        x--;
    }
    sonuc = ust/fact(y);
    return sonuc; 
} */ /*
#include<stdio.h>
int fact(int);
int main(){
    printf("faktoriyeli bulunacak tam sayiyi giriniz = ");
    int n;
    scanf("%d",&n);
    printf("%d'in faktoriyeli = %d\n",n,fact(n));
}
int fact(int n){
    if(n==0)
    return 1;
    return n*fact(n-1);
} */ /*
#include<stdio.h>
int F(int);
int main(){
    int n;
    printf("kacinci fibonacci sayisini ogrenmek istersiniz =");
    scanf("%d",&n);
    printf("%d. fibonacci sayisi= %d",n,F(n));
}
int F(int n){
    if(n==0)
    return 1;
    if(n==1)
    return 1;
    return F(n-1)+F(n-2);
} */
// {} değisikligi
/*
#include<stdio.h>
int square(int);
int main()
{	
	int x;
	printf("Enter a number : ");
	scanf("%d",&x);
	printf("%d\n",square(x));
}
int square(int x)
{
	int i,t=0;
	for(i=x;i>0;i--)
	{
		t=t+(i*i);
	}
	return t;
} */ /*
#include <stdio.h>
int karesayisi(int);
int main()
{
	int n;
	scanf("%d",&n);
	printf("kare sayisi %d",karesayisi(n));
}
int karesayisi(int n){
	int sonuc=0; 	
	for(n;n>=1;n--)
    {
	    sonuc +=n*n;
    }
	return sonuc;
}*/ /*
#include<stdio.h>
int f(int x)
{
    return 3*x;
}
int main()
{
    int i;
    scanf("%d",&i);
    printf("%d",f(i));
}*/ /*
#include<stdio.h>
int main()
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            if((i+j)%2==0)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
} */ /*
#include<stdio.h>
int main()
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            if(i==j||i+j==10)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
} */ /*
#include<stdio.h>
int main()
{
    //n!=nf r!=rf (n-r)=nrf
    int x;
    printf("binom ucgeni:\n");
    scanf("%d",&x);
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=i;j++)
        {
            int nf=1,rf=1,nrf=1;
            for(int x=1;x<=i;x++)
            {
                nf=nf*x;
            }
            for(int y=1;y<=j;y++)
            {
                rf=rf*y;
            }
            for(int z=1;z<=i-j;z++)
            {
                nrf=nrf*z;
            }
            printf("%d ",nf/(rf*nrf));
        }
        printf("\n");
    }
} */ /*
#include<stdio.h>
int fib(int);
int main()
{
    int t=5;
    while (t==5)
    {
        int secim,n;
        printf("asagidan merak ettiginiz sayi dizisini seciniz:\n");
        printf("1-ucgensel sayi dizisi\n2-karesel sayi dizisi\n3-fibonacci sayi dizisi\n4-pascal ucgeni sayi dizisi\n");
        scanf("%d",&secim);
        printf("peki kac terimini gormek istersiniz?\n");
        scanf("%d",&n);
        t++;
    
        if(secim==1)
        {
            int u=0;
            for(int i = 1; i <=n; i++)
            {
                u +=i;
                printf("%d ",u);
            }    
        }
        else if(secim==2)
        {
            int k,i=1;
            while (i<=n)
            {
                k = i*i;
                i++;
                printf("%d ",k);
            }
        }
        else if(secim==3)
        {
            for(int i=1;i<=n;i++)
            {
                printf("%d ",fib(i));    
            }
        }
        else if(secim==4)
        {
            if(n>=14)
            {
                printf("uzgunum 14 ve uzeri satirlari hesaplayamiyorum ):\n");
                break;
            }
            for(int i=0;i<=n-1;i++)
            {
                for(int j=0;j<=i;j++)
                {
                    int nf=1,rf=1,nrf=1;
                    for(int x=1;x<=i;x++)
                    {
                        nf *= x;
                    }
                    for(int y=1;y<=j;y++)
                    {
                        rf *= y;
                    }
                    for(int z=1;z<=i-j;z++)
                    {
                        nrf *= z;
                    }
                    printf("%d ",nf/(rf*nrf));
                }
                printf("\n");
            }
        }
        else
        {
            printf("are you kidding me!!");
        }
        printf("\ntekrar denemek icin 5 rakami,cikis icin herhangi bir sey giriniz =\n");
        scanf("%d",&t);
    }
    printf("thank you for your time\n");
}
int fib(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return 1;
    }
    return fib(n-1)+fib(n-2);
} */ /* 
#include<stdio.h>
int main ()
{
    int A[10];
    for(int i=0;i<10;i++)
    {
        A[i]=i+1;
        printf("%d ",A[i]);
    }
    int gecici=0;
    for(int i=0;i<5;i++)
    {
        gecici=A[i];
        A[i]=A[9-i];
        A[9-i]=gecici;
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",A[i]);
    }
} */  /* 
#include<stdio.h>
int F(int);
int main()
{
    for(int i=0;i<=19;i++)
    {
        printf("%d ",F(i));
    }
    int f[19];
    for(int j=0;j<20;j++)
    {
        f[j]=F(j);
        printf("%d ",f[j]);
    }
}
int F(int i)
{
    if(i==1)
    return 1;
    if(i==0)
    return 1;
    return F(i-1)+F(i-2);
} */ /*
#include<stdio.h>
int main()
{
    int notlar[9];
    int toplam=0;
    printf("10 adet not giriniz.\n");
    for(int i=0;i<10;i++)
    {
        int x;
        scanf("%d",&x);
        notlar[i]=x;
        toplam+=x;
    }
    printf("Notlarin ortalamasi = %d\n",toplam/10);
    int flag=1;
    int k=3;
    int EnBuyuk=0;
    for(int i=0;i<10;i++)
    {
        if(EnBuyuk<notlar[i])
        {
            EnBuyuk = notlar[i];
        }
    }
    for(int i=0;i<10;i++)
    {
        flag=0;
        for(int j=0;j<10;j++)
        {
            if(i!=j)
            {
                if(notlar[i] < notlar[j])
                {
                    k=notlar[i];
                    flag=1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }   
        }
        if(flag==1)
        {
            break;
        }
    }
    if(flag==1)
    {
        printf("en dusuk not = %d\n",k);
    }
    else
    {
        printf("notlar esit\n");
    }
    printf("en yuksek not = %d\n",EnBuyuk);
    for(int i=0;i<10;i++)
    {
        printf("%d ",notlar[i]);
    }
} */ /*    
#include<stdio.h>
int main()
{
    printf("gireceginiz degerleri kucukten buyuge siralayacagim.\n");
    printf("kac deger giriceksiniz?\n");
    int n;
    scanf("%d",&n);
    int d[n-1];
    printf("degerleri giriniz:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d)",i+1);
        scanf("%d",&d[i]);
    }
    printf("girdiginiz sayilar = ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",d[i]);
    }
    int EnBuyuk=-999;
    for(int c=0;c<n;c++)
    {
        if(EnBuyuk<d[c])
        {
            EnBuyuk=d[c];
        }
    }
    int x=-1;
    printf("\nsayilarin kucukten buyuge siralanisi = ");
    for(int j=0;j<n;j++)
    {
        int EnKucuk=999999999;
        for(int i=0;i<n;i++)
        {
            if(EnKucuk>d[i])
            {
                EnKucuk=d[i];
                x=i;
            }
        }
        int g=0;
        g=d[0];
        d[0]=d[x];
        d[x]=g;
        for(int z=0;z<n;z++)
        {
            d[z]=d[z+1];
            d[n-1]=EnBuyuk;
        }
        printf("%d ",EnKucuk);
    }
    
}*/  /*
#include<stdio.h>
int main()
{
    printf("gireceginiz degerleri kucukten buyuge siralayacagim.\n");
    printf("kac deger giriceksiniz?\n");
    int n;
    scanf("%d",&n);
    int d[(n-1)];
    printf("degerleri giriniz:\n");
    for(int i=0;i<n;i++)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        printf("%d) ",i+1);
        scanf("%d",&d[i]);        
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(d[i]<d[j])
            {
                int gecici=0;
                gecici=d[i];
                d[i]=d[j];
                d[j]=gecici;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",d[i]);
    }
} */
/* Parametre tanimlamasi yaparken, iki boyutlu dizinin 
   satir boyutunu girmemize gerek yoktur. Ancak sutun 
   boyutunu girmek gerekir. 
*/  /*
#include<stdio.h>
#include<limits.h>
#include<float.h>
int main( void )
{	
	printf( "\nTIP\t\t  BOYUT\t\t MIN\t \tMAX\n" );
	printf("==============================================================\n");
	printf( "char\t\t: %d byte(s)\t%d\t\t%d\n", sizeof(char),CHAR_MIN,CHAR_MAX );
	printf( "short\t\t: %d byte(s)\t%d\t\t%d\n", sizeof(short), SHRT_MIN, SHRT_MAX );
	printf( "int\t\t: %d byte(s)\t%d\t%d\n", sizeof(int), INT_MIN, INT_MAX );
	printf( "unsigned int\t: %d byte(s)\t\t\t%u\n",sizeof(unsigned),UINT_MAX );
	printf( "long\t\t: %d byte(s)\t%ld\t%ld\n", sizeof(long), LONG_MIN, LONG_MAX );
	printf( "float\t\t: %d byte(s)\t%e\t%e\n", sizeof(float), FLT_MIN, FLT_MAX );
	printf( "double\t\t: %d byte(s)\t%e\t%e\n\n", sizeof(double), DBL_MIN, DBL_MAX );

	return 0;
} */    /*
#include<stdio.h>
int main()
{
    int not;
    printf("100 uzerinden not giriniz: ");
    scanf("%d",&not);
    switch (not/10)
    {
    case 10:printf("A aldiniz.");break;
    case 9:printf("A aldiniz.");break;
    case 8:printf("B aldiniz.");break;
    case 7:printf("C aldiniz.");break;
    case 6:printf("D aldiniz.");break;
    case 5:printf("F aldiniz.");break;
    case 4:printf("F aldiniz.");break;
    case 3:printf("F aldiniz.");break;
    case 2:printf("F aldiniz.");break;
    case 1:printf("F aldiniz.");break;
    case 0:printf("F aldiniz.");break;
    default:
        printf("gecersiz not değeri girdiniz.");
        break;
    }
} */  /* 
#include<stdio.h>
int main()
{
    int x;
    printf("sayi giriniz: ");
    scanf("%d",&x);
    (x<=22)    ?    printf("22den kucuk veya esit\n"):
        printf("22den buyuk\n");
} */   /*
// int i = rand() % x     i ye (0,x] aralığında sayi atar 
#include<stdio.h>
int main( void )
{
	int i = 0;
	// baslangic_noktasi adinda bir etiket koyuyoruz.
	// i degiskeni 10 degerine ulasmadigi surece, 
	// program buraya donecektir. 
	baslangic_noktasi:
	printf( "Merhaba Dünya\n" );
	// i degerini arttiriyoruz.
	i++;
	// i degeri kontrol ediliyor. Sayet 10'dan kucukse, 
	// en basa donuyor.
	if( i<10 ) goto baslangic_noktasi;
	return 0;
} */ /*
#include<stdio.h>
int main()
{
    int sayi;
    printf("(0,1000) araliğinda bir tamsayi giriniz. ");
    scanf("%d",&sayi);
    if(sayi<1000&&sayi>0)
    {
        printf("%d sayisinin yazilisi = ",sayi);
        switch (sayi/100)
        {
        case 9:printf("dokuzyuz");break;
        case 8:printf("sekizyuz");break;
        case 7:printf("yediyuz");break;
        case 6:printf("altiyuz");break;
        case 5:printf("besyuz");break;
        case 4:printf("dortyuz");break;
        case 3:printf("ucyuz");break;
        case 2:printf("ikiyuz");break;
        case 1:printf("biryuz");break;
        default:
            break;
        }
        switch ((sayi%100)/10)
        {
        case 9:printf("doksan");break;
        case 8:printf("seksen");break;
        case 7:printf("yetmis");break;
        case 6:printf("altmis");break;
        case 5:printf("elli");break;
        case 4:printf("kirk");break;
        case 3:printf("otuz");break;
        case 2:printf("yirmi");break;
        case 1:printf("on");break;
        default:
            break;
        }
        switch (sayi%10)
        {
        case 9:printf("dokuz");break;
        case 8:printf("sekiz");break;
        case 7:printf("yedi");break;
        case 6:printf("alti");break;
        case 5:printf("bes");break;
        case 4:printf("dort");break;
        case 3:printf("uc");break;
        case 2:printf("iki");break;
        case 1:printf("bir");break;
        default:
            break;
        }
    }
    else
    {
        printf("HATA\n");
    }
    
}*/ /*
//Dört basamaklı bir sayının rakamları ters yazılıp,
//4 ile çarpılırsa, çıkan sonuç, kendisiyle aynıdır.
//Dört basamaklı bu sayıyı bulunuz.
#include<stdio.h>
int main()
{
    for(int i=1000;i<10000;i++)
    {
        int a=i/1000;
        int b=(i%1000)/100;
        int c=(i%100)/10;
        int d=i%10;
        int x=1000*d + 100*c +10*b + a;
        if(4*x==i)
        {
            printf("%d",i);
            break;
        }
    }
} */ /*
//Soru 7: Verilecek kenar uzunluğuna göre,
//yıldız (*) işareti kullanarak kare çizen, bir program yazınız.
#include<stdio.h>
int main()
{
    int n;
    printf("karenin kenar uzunlugunu giriniz.\n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        for(int j=1 ; j<=n ;j++)
        {
            if(j==1||j==n)
            {
            printf("* ");
            }
            else if(i==1||i==n)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
            
        }
        printf("\n");
    }
    
}*/ /*
#include<stdio.h>
int main()
{
    int buyukluk;
    printf("eskenar dortgenin buyuklugunu giriniz. ");
    scanf("%d",&buyukluk);
    int y=1;
    int b=(buyukluk-1);
    for(int i=1;i<=buyukluk;i++)
    {
        for(int j=1;j<=b;j++)
        {
            printf(" ");
        }
        for(int k=1;k<=y;k++)
        {
            printf("*");
        }
        for(int j=1;j<=b;j++)
        {
            printf(" ");
        }
        b=b-1;
        y=y+2;
        printf("\n");
    }
    int a=1;
    int c=(buyukluk-1)*2-1;
    for(int l=1;l<=buyukluk;l++)
    {
        for(int h=1;h<=a;h++)
        {
            printf(" ");
        }
        for(int g=1;g<=c;g++)
        {
            printf("*");
        }
        for(int h=1;h<=a;h++)
        {
            printf(" ");
        }
        a++;
        c-=2;
        printf("\n");
    }
} */ /*
//Soru 9: Hipotenus'u 500 birime kadar olan dik üçgenlerin,
//kenar uzunluklarını gösteren bir program yazınız.
//Kenar uzunlukları, sadece tam sayı olacaktır.
#include<stdio.h>
int main()
{
    int UcgenSayisi=0;
    int a,b,c;
    for(a=1;a<100;a++)
    {
        for(b=1;b<=a;b++)
        {
            for(c=1;c<=b;c++)
            {
                if(a<b+c||c>a-b)
                {
                    if(a*a==b*b+c*c)
                    {
                        printf("en kisa kenar=%d\nortanca kenar=%d\nhipotenus=%d\n\n",c,b,a);
                        UcgenSayisi++;
                    }
                }
            }
        }
    }
    printf("Ucgen sayisi = %d \n",UcgenSayisi);
} */ /*    
#include<stdio.h>
int main()
{  
    int i,j;
    int d[3][4]={{1,2,3,4}, 1,2,3,4, 1,2,3,4};      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
        printf("%3d",d[i][j]); 
        }
        printf("\n");       
    }
} */ /*
#include<stdio.h>
int main()
{
    int d[10]={1,2,3,4,5,6,7,8,9,10,11},*p;
    p=d;
    printf("%d\n",p);
    printf("%d\n",&d[0]);
    printf("%d\n",&d[1]);
    printf("%d\n",(p+1));
    for(int i=0;i<10;i++)
    {
        printf("%d",*(p+i));
        printf("%15d",(p+i));
        printf("%30d\n",&d[i]);
    }
}*/ /* 
#include<stdio.h>
#include<stdlib.h>
int g(int);
int f(int *);
int main(void)
{
    printf("dizinin uzunlugu=");
    int a;
    scanf("%d",&a);
    int *p=(int*)malloc(sizeof(int)*a);
    for(int i=0;i<a;i++)
    {
        p[i] =i;
        printf("%d ",p[i]);
    }
    printf("\n");
    int x=2;
    g(x);
    printf("x %d",x);
    f(&x);
    printf("\nx %d",x);
}
int g(int x)  // call by value
{
    x=3;
}
int f(int * x) //call by reference
{
    *x=4;
}*/ /*
#include<stdio.h>
#include<stdlib.h>
typedef enum 
{
    erkek,
    kadin
}cinsiyet;
typedef struct
{
    int yas;
    char *isim;
    cinsiyet c;
}insan;
int main()
{
    insan ali;
    ali.yas=10;
    ali.c=kadin;
    insan *veli;
    veli = (insan*) malloc(sizeof(insan));
    veli->yas=30;
    printf("%d %u",ali.yas,ali.c);
    printf("\n");
    printf("%d\n",veli->yas);
} */ /*
#include<stdio.h>
typedef struct
{
    int boy;
    int kilo;
    int ogrencinum;
}insan;
int main()
{
        insan sayi;
        printf("ogrenci numarasi, boyu, kilosu giriniz.\n");
        scanf("%d%d%d",&sayi.ogrencinum,&sayi.boy,&sayi.kilo);
        printf("ogrenci numarasi=%d\nboyu=%d\nkilosu=%d\n",sayi.ogrencinum,sayi.boy,sayi.kilo);
} */ /*
#include<stdlib.h>
#include<stdio.h>
typedef enum
{
    erkek,
    kadin
}cinsiyet;
typedef enum 
{
    gazidegil,
    gazi
}gazilik;
typedef struct
{
    cinsiyet c;
    gazilik g;
    int yas;
}insan;
int emeklilik(insan *birey)
{
    if(birey->c==0) //erkek
    {
        if(birey->g==0) //gazi değilse
        {
            if(birey->yas>=60)
            {
                return 1;
            }
            else
            return 0;
        }
        else
        {
            if(birey->yas>=45)
            return 1;
            else
            {
                return 0;
            }
            
        }   
    }
    else if(birey->c==1) //kadın
    {
        if(birey->yas>=50)
        return 1;
        else
        return 0;
    }
}
int main()
{
    printf("bu programda hayir=0, evet=1 olmak üzere tanimlidir.\n");
    printf("emekliliginizin gelip gelmedigini ogrenmek icin sorulari yanıtlayiniz.\n");
    insan *birey;
    birey = (insan*) malloc(sizeof(insan));
    printf("yasinizi giriniz.\n");
    scanf("%d",&birey->yas);
    printf("kadin misiniz?\n");
    scanf("%u",&birey->c);
    if(birey->c==0)
    {
        printf("gazi misiniz?\n");
        scanf("%u",&birey->g);
    }
    if(emeklilik(birey)==1)
    {
        printf("emekliliginiz geldi");
    }
    else
    {
        printf("emekliliginiz gelmedi.");
    }
} */ /*
#include<stdio.h>
int main()
{
    char a[15];
    char *b;
    b= (char *) malloc(sizeof(char)*15);
    printf(" ad :\n");
    scanf("%s",a);
    printf("\n soyad : ");
    scanf("%s",b);
    printf("\nadiniz : %s soyadiniz: %s",a,b);
    printf("\n3. harleri %c %c",a[2],b[2]);
} */ /*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char ilkstring[20]= "hello world!";
    char ikincistring[19]= "hello universe!!!";
    char *ilk= ilkstring;
    char *iki= ikincistring;
    printf("%s -sorry- %s\n",ilk,iki);
    //ilk = iki;
    printf("%d\n%d\n",strlen(ilkstring),strlen(ikincistring));
    int i=0;
    char c=iki[i];
//    while (c!='\0')
//    {
  //      ilk[i]=iki[i];
    //    i++;
      //  c = iki[i];
   // }   
    strcpy(ilk,iki);
    printf("%s -sorry- %s\n",ilk,iki);
    ilk[3]='x';
    iki[5]='x';
    printf("%s -sorry- %s\n",ilk,iki);
    printf("%d\n%d\n",strlen(ilkstring),strlen(ikincistring));
} *//*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char siralama(char[15],char[15],char[15]);
char isimyazdirma(char[15]);
int uzunluk(char[15]);
int main()
{
    char ilkisim[15];
    char ikinciisim[15];
    char ucuncuisim[15];
    char *ilk = ilkisim;
    char *iki = ikinciisim;
    printf("uzunluklari farkli uc ad giriniz.\n");
    scanf("%s",ilk);
    scanf("%s",iki);
    scanf("%s",ucuncuisim);
    printf("isimlerin sirasiyla uzunluklari\n"); 
    uzunluk(ilk),uzunluk(iki),uzunluk(ucuncuisim);
    printf("\nkisadan uzuna siralanmis hali");
    siralama(ilk,iki,ucuncuisim);
    printf("\n");    
}
int uzunluk(char isim[15])
{
    int ilkisimuzunlugu = strlen(isim);
    printf("%d ",ilkisimuzunlugu); 
}
char siralama(char first[15],char second[15],char third[15])
{
    int a=strlen(first);
    int b=strlen(second);
    int c=strlen(third);
    if(a<b&&b<c)
        isimyazdirma(first),isimyazdirma(second),isimyazdirma(third);
    if(a<c&&c<b)
        isimyazdirma(first),isimyazdirma(third),isimyazdirma(second);
    if(b<a&&a<c)
        isimyazdirma(second),isimyazdirma(first),isimyazdirma(third);
    if(b<c&&c<a)
        isimyazdirma(second),isimyazdirma(third),isimyazdirma(first);
    if(c<b&&b<a)
        isimyazdirma(third),isimyazdirma(second),isimyazdirma(first);
    if(c<a&&a<b)
        isimyazdirma(third),isimyazdirma(first),isimyazdirma(second);
}
char isimyazdirma(char yazdirilacak[15])

{
        printf("\n");
        char x = yazdirilacak[0];
        int a = 1;
        while(x!='\0')
        {
            printf("%c",x);
            x = yazdirilacak[a];
            a++;
        }
} */ /*
#include <stdio.h> 
#include<string.h>
int main() 
{ 
    int i,N;
    printf("kac isim girilicek?\n");
    scanf("%d",&N); 
    printf("isimleri giriniz:\n");
    char array[N][20];
    for (i = 0; i < N; i++) 
    {
        scanf("%s",array[i]); 
    }
    printf("isimler:\n");
    for (i = 0; i < N; i++) 
    {
        printf("%s\n", array[i]); 
    }
    printf("kisadan uzuna siralanisi\n");
    for (int j = 0; j < N-1; j++)
    {
        for (int z = j+1; z < N; z++)
        {
            if(strlen(array[z])<strlen(array[j]))
            {
                strcpy(array[N],array[j]);
                strcpy(array[j],array[z]);
                strcpy(array[z],array[N]);
            }
        }
    }
    for (i = 0; i < N; i++) 
    {
        printf("%s\n", array[i]); 
    }
} *//*
#include <stdio.h>
#include <string.h>
int main ()
{
    printf("giriceginiz isimleri alfabetik siralayacagim.\n");
    printf("lutfen isimleri bosluk,virgul,nokta,kisa cizgi ile ayiriniz.\n");
    char str[50];
    char isimler[10][20];
    scanf("%[^\n]%*c",str);
    char* pch;
    pch = strtok (str," ,.-");
    int i=0;
    while (pch != NULL)
    {
        //printf ("%s\n",pch);
        strcpy(isimler[i],pch);
        pch = strtok (NULL, " ,.-");
        i++;
    }
    //artık isimler ile isimiz var
    for(int j=0; j<i;j++)
    {
        for(int z=0;z<i;z++)
        {
            if(strcmp(isimler[j],isimler[z])>0)
            {
                //printf("%s %s\n",isimler[j],isimler[z]);
                strcpy(isimler[10],isimler[j]);
                strcpy(isimler[j],isimler[z]);
                strcpy(isimler[z],isimler[10]);
            }
        }
    }
    for (int s = i-1; s >=0; s--)
    {
        printf("%s \n",isimler[s]);
    }   
}*/ /*
#include<stdio.h>
#include<string.h>
int main()
{
    char str[5][10]={"alperen","kerim","sumeyra","a","b","dd"};
    for(int i=0;i<=5;i++)
    {
        for(int j=0;j<=5;j++)
        {
            int a= strcmp(str[i],str[j]);
            printf("%s --- %s -------->>>>> a = %d\n",str[i],str[j],a);
        }
    }
}*/
//scanf("%[^\n]%*c", s)
/*
#include<stdio.h>
#include<string.h>
int main()
{
    //girilen kelimeyi saklamak için string kelime[]
    char kelime[100];
    printf("kelime veya cümle giriniz : ");
    scanf("%[^\n]%*c", kelime);
    //farkli harf sayisi için
    int AyniHarfSayisi = 0; int i=0;
    while (kelime[i]!='\0')
    {
        int j = i+1;
        while (kelime[j]!='\0')
        {
            if(kelime[i]==kelime[j])
            {
                AyniHarfSayisi++;
                break;
            }
            j++;
        }
        i++;
    }
    int FarkliHarfSayisi = i-AyniHarfSayisi;
    //farklı harler için string
    char FarkliHarfler[FarkliHarfSayisi-1];
    //tekrar dizisinin bütün elemanlarını 1 yapıyoruz.
    int tekrar[FarkliHarfSayisi-1];
    for(int q=0;q<FarkliHarfSayisi;q++)
    {
        tekrar[q]=1;
    }
    //kelimedeki harf farkliharflerde yoksa oraya ekleme islemi
    int z=1;int index=0;
    FarkliHarfler[0]=kelime[0];
    while (kelime[z]!='\0')
    {
        int ayniyoksaBir=1;int a=0;
        while (a<z)
        {
            if(kelime[z]==FarkliHarfler[a])
            {
                ayniyoksaBir=0;
                tekrar[a]++;
                break;
            }
            a++;
        }
        if(ayniyoksaBir==1)
        {
            index++;
            FarkliHarfler[index]=kelime[z];
        }
        z++;
    }
    printf("%s , %d\n",FarkliHarfler,FarkliHarfSayisi);
    //son output neye benzeyecek
    //farklı harf sayisi kadar satir "kelimede" 'de "x" harfinden "count" kadar var
    for(int w=0;w<FarkliHarfSayisi;w++)
    {
        printf("  %s yazisinda %c harfinden %d adet vardir.\n",kelime,FarkliHarfler[w],tekrar[w]);
    }
}   */ /*
#include <stdio.h> // Main Library
#include <math.h>  // For sqrt function
int main()
{
    float a, b, c;    // Coefficients
    float disc;        // Discriminant
    float x1, x2;     //Real roots
    float x1_im, x1_re, x2_im, x2_re; //complex roots
    printf("Finding the quadratic equation roots such as a*x^2 + b*x + c\n");
    printf("Enter coefficients (a, b , c)  :");
    do{
    	printf("\nenter a :");
        scanf("%f", &a);
        if(a==0) // a can not be zero 
        {
		    printf("a can not equal to 0");
		}    
    }while(a==0);
    printf("enter b :");
    scanf("%f",&b);
    printf("enter c :");
    scanf("%f",&c);
    disc = b * b - 4 * a * c; // Calculating discriminant 
    if (disc < 0)
	{
        printf("THERE ARE NO REAL ROOTS \n");
        printf("Discriminant is %.0f\n",disc);
        x1_re = -b/(2*a); //Calculating real part of X1  root
        x2_re = x1_re; // Real parts of X1 and X2 are the same
        x1_im = sqrt(-disc)/(2*a); // Calculating imaginary part of X1
        x2_im = -x1_im; //  Imaginary parts of X1 and X2 are the same but negative.
        printf("x1_re : %.3f\tx1_im : %.3f\n x2_re : %.3f\tx2_im : %.3f\n",x1_re,x1_im,x2_re,x2_im);
    }
    else if(disc==0)
    {
        x1 = (-b + sqrt(disc)) / (2 * a); //Calculating  X1  root
        printf("Discriminant is %.0f",disc);
        printf("\nTHERE ARE TWO REAL, IDENTICAL ROOTS \n x1 = x2 = %.3f\n",x1);
    }
    else 
    {
        x1 = (-b + sqrt(disc)) / (2 * a); //Calculating  X1  root
        x2 = (-b - sqrt(disc)) / (2 * a); //Calculating  X2  root
        printf("Discriminant is %.0f",disc);
        printf("\nTHERE ARE TWO REAL ROOTS \nx1 = %.3f and x2 = %.3f\n",x1,x2);
    }
    printf("To terminate the program press any button on your keyboard !");
    getch(); //Terminating the program
}*/ /*
#include<stdio.h>
int main()
{
    int degerler[6]={3,4,5,2,6,4};
    //en büyük değeri bulup asagıda 10 yerine yazabilirsin
    printf("1\t2\t3\t4\t5\t6\n^\t^\t^\t^\t^\t^\n");
    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=5;j++)
        {
            //satırları sayaç olarak kullanıyoruz (i leri)
            if(degerler[j]>i)
            {
                printf("*\t");
            }
            else
            {
                printf(" \t");
            }   
        }
        printf("\n");
    }
    return 0;
}*/ /*
#include<stdio.h>
int power(int,int);
int main(){
    int base,exponent;
    printf("base = ");
    scanf("%d",&base);
    printf("exponent = ");
    scanf("%d",&exponent);
    printf("the result of (%d^%d) = %d\n",base,exponent,power(base,exponent));
    return 0;
}
int power(int base,int exponent){
    if(exponent==0)
        return 1;
    return base*power(base,(exponent-1));
} *//*
#include<stdio.h>
#include <math.h>
int sum(int,int);
int main(){
    int base,exponent;
    printf("base = ");
    scanf("%d",&base);
    printf("exponent = ");
    scanf("%d",&exponent);
    printf("the result of sum(%d^%d) = %d\n",base,exponent,sum(base,exponent));
    return 0;
}
int sum(int base,int exponent){
    if(exponent==1)
        return base;
    return pow(base,exponent)+sum(base,(exponent-1));
}
//sum(3^4) = 3^1+3^2+3^3+3^4 3+9+27+81=120 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7
#define SIZE2 12

void odd_dice(unsigned int frequency[ SIZE ],unsigned int frequency_sum[ SIZE2 ]);
void draw_graph1(unsigned int frequency[ SIZE ]);
void draw_graph2(unsigned int frequency_sum[ SIZE2 ]);

int main( void )
{
	unsigned int frequency[ SIZE ] = { 0 };  
	unsigned int frequency_sum[ SIZE2 ] = { 0 };
	int style = 0 ;
	int erase,erase2;
	
	do{
	odd_dice(frequency,frequency_sum);
	printf("Please enter your graph style with dice(1 or 2):");
	scanf("%d",&style);
	
	if (style ==1)
	{
		draw_graph1(frequency);
	
	for (erase = 1;erase<8;erase++)
	{
		frequency[ erase ] =  0 ; 
	}
	
	for (erase2 = 1;erase2<13;erase2++)
	{
		frequency_sum[ erase2 ] =  0 ; 
	}
	}
	else if (style == 2)
	{
	
		draw_graph2(frequency_sum);
	
		for (erase = 1;erase<8;erase++)
		{
			frequency[ erase ] =  0 ; 
		}
	
		for (erase2 = 1;erase2<13;erase2++)
		{
			frequency_sum[ erase2 ] =  0 ; 
		}
	}	
	}while(style==1 || style ==2);
	
	return 0;
}

void odd_dice(unsigned int frequency[ SIZE ],unsigned int frequency_sum[ SIZE2 ])
{
	int face,face2; // random die value 1 - 6
	unsigned int roll; // roll counter 1-10,000

	srand( time( NULL ) ); // seed random number generator

	// roll die 10,000 times


	for ( roll = 1; roll <= 10000; ++roll ) 
	{
		face = 1 + rand() % 6;
		face2= 1 + rand() % 6;
		++frequency[ face ]; 
		++frequency_sum[ face+face2 ];
	}
}

void draw_graph1(unsigned int frequency[ SIZE ])
{
	int i,j;
	
	for(i=20;i>=1;i--)
	{
		for(j=1;j<=6;j++)
		{
			if(frequency[j]/100>=i)
			{	
				printf("*\t");
			}
			else
			{
				printf(" \t");
			}   
		}
		printf("\n");
	}			
		printf("^\t^\t^\t^\t^\t^\n1\t2\t3\t4\t5\t6\n");	
}

void draw_graph2(unsigned int frequency_sum[ SIZE2 ])
{
	int i,j;
   
    for(i=40;i>=1;i--)
    {
        for(j=2;j<=12;j++)
        {            
            if(frequency_sum[j]/50>=i)
            {
                printf("*\t");
            }
            else
            {
                printf(" \t");
            }   
        }
        printf("\n");
    }
	
	printf("^\t^\t^\t^\t^\t^\t^\t^\t^\t^\t^\n2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\n");	
} */ /*
#include<stdio.h>
#include<string.h>
int main()
{
	char Shift[5],ilk[100],Son[100];
	int X,yon;
	printf("Sifrelemek istediginiz yaziyi giriniz : ");
	gets(ilk);
	printf("Ne tarafa kaydırma ? Enter left or right please.\n");
	scanf("%s",Shift);
	if (strcmp(Shift, "right") == 0)
		yon = 1;
	else
		yon = -1;
	printf("kac kez kaydırma ?\n");
	scanf("%d",&X);
	int i=0,deger;
	while(ilk[i]!='\0')	
	{
		deger = ilk[i] + (yon*X);
		if(ilk[i]>='a'&&ilk[i]<='z') 				//kücük harf mi ?
		{
			if(deger <'a'||deger>'z')		//periyodik tur atacak mı ?
			{
				if(yon==1)					//z den mi a ya ?
				{
					Son[i] = 'a'-1+X-('z'-ilk[i]);
				}
				else						//a dan z ye
				{
					Son[i] = 'z'+1-X+(ilk[i]-'a');
				}
			}
			else
			{
				Son[i] = deger;
			}
		}
		else if(ilk[i]>='A'&&ilk[i]<='Z')			//büyük harf mi ?
		{
			if(deger<'A'||deger>'Z')		//periyodik tur atacak mı ?
			{
				if(yon==1)					//Z den A ya mı ?
				{
					Son[i] = 'A'-1+X-('Z'-ilk[i]);
				}
				else						//A dan Z ye
				{
					Son[i] = 'Z'+1-X+(ilk[i]-'A');
				}
			}
			else
			{
				Son[i] = deger;
			}
		}
		else										//harf değil
		{
			Son[i] = ilk[i];
		}
		i++;
	}
	printf("Sifrelenmis hali : \n");
	puts(Son);
	return 0;
}*/ /*
#include<stdio.h>

int length(char[], int);
void polindrome(char[], int);
void main()
{
    int count,length_input;
    char input[100];
    gets(input);
    int i=0;
    while (input[i] != '\0')
    {
        printf("%c ",input[i]);
        i++;
    }
    count = 0;
    length_input = length(input,count);
    printf("\nthe length of the giving string is : %d\n",length_input);
    polindrome(input,length_input);
}
int length(char string[], int count)
{
    if(string[count] == '\0')
        return count;       
    else                    
    {
        count++;
        length(string, count);
    }
}
void polindrome(char string[], int len)
{
    int flag = 1;
    for (int i = 0; i < len/2; i++)
    {
        if(string[i] != string[len-i-1])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        printf("The entered word is a polindrome.");
    else
        printf("The entered word is not a polindrome.");
}   */
/*
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void draw_butterfly(int n);
int main ()
{
    srand(time(NULL));
    int choice,n;
    printf("Write '1' for user defined size \n");
    printf("Write '2' for random size \n");
    scanf("%d",&choice);
    while(!(choice == 1 || choice == 2))
    {
        printf("Erroneous number!! Try again\n");
        scanf(" %d",&choice);
    }
    if (choice == 1)
    {
        printf("Write the size it should be 5<n<51 and an even number : ");
        scanf("%d",&n);
        while(!((n % 2 == 0) && (n > 5) && (n < 51)))
        {
        printf("The size should be an even number and should be 5<n<51 !!!!\n");
        scanf(" %d",&n);
        }
    }
    else
    {
        n = (rand() % 90) + 12;
        n = n/2;
    }
    draw_butterfly(n);
    return 0;
}
void draw_butterfly(int n)
{
    int i,j;
    for ( i = 1; i <= n/2; i++)
    {
        for ( j = 1; j <= i; j++)
            printf("2");
        for ( j = n-2*i; j > 0; j-=2)
            printf("  ");
        for ( j = 1; j <= i; j++)
            printf("1");
        printf("\n");
    }
    for ( i = n/2; i > 0; i--)
    {
        for ( j = i; j >= 1; j--)
            printf("3");
        for ( j = n-2*i; j > 0; j-=2)
            printf("  ");
        for ( j = i; j >= 1; j--)
            printf("4");
        printf("\n");
    }
}
*/
/*
#include<stdio.h>
#include<string.h>
void DisplayBitsAsCharacters(unsigned short);
unsigned short ConvertToDecimal(char*);
char binary_str[16];
int main ()
{
    //Program must take unsigned short integer (16-bit) from the user 
    //write the corresponding binary number into char array by using the bit shift operations.
    //Print the Number of Digits not zero 
    printf("Enter -1 to quit.\n");
    unsigned short number = 0,decimal;

    while (number != -1)
    {
        printf("Enter 16-bit : ");
        scanf("%hd",&number);
        DisplayBitsAsCharacters(number);
        printf("%s\n",binary_str);
        decimal = ConvertToDecimal(binary_str);
        printf("decimal = %hd\n",decimal);
        //number of digits
        //ConvertToDecimal
    }

}
void DisplayBitsAsCharacters(unsigned short number)
{
    char str[16];
    int c, k;
    for (c = 15; c >= 0; c--)
    {
        k = number >> c;

        if (k & 1)
        {
            printf("1");
            str[15-c] = '1';
        }
        else
        {
            printf("0");
            str[15-c] = '0';
        }
    }
    
    int i = 0,j;
    while (str[i] == '0')
        i++;
    char str_new[16-i];
    for ( j = 0; j < 16-i; j++)
    {
        str_new[j] = str[i+j];
    }
    
    printf("\n");
    printf("%s = %hd\n",str_new,number);
    printf("Number of digits = %d\n",16-i);
    strcpy(binary_str,str);
    
}
unsigned short ConvertToDecimal(char* string)
{
    unsigned short val=0;
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i]< '2' && string[i]>= '0' )
        {
            val = 2 * val + (string[i] - '0');
        }
        i++;
    }
    return val;
}
*/
//yeni backup_2 and c_2.c