/*
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int saga_gotur(int [][4]);
int sagda_topla(int [][4],int* scoreF);
int sola_gotur(int [][4]);
int solda_topla(int [][4],int* scoreF);
int asagi_gotur(int [][4]);
int asagida_topla(int [][4],int* scoreF);
int yukari_gotur(int [][4]);
int yukarida_topla(int [][4],int* scoreF);
int yone_gore_islemler(char,int [][4],int* scoreF,int* high_scoreF);
int her_turda_yeni_sayi_ekleme(int [][4]);
int baslangic_random(int [][4]);
int output(int [][4]);
int geri_alma(int [][4],int[][4],int* scoreF,int* score_yedekF);
int yedekleme(int [][4],int[][4],int* scoreF,int* score_yedekF);
int oyun_bitti_mi(int [][4],int* scoreF,int* durumF);
time_t t;
int high_score=0; //global
//https://www.onlinegdb.com/online_c_compiler burdan calistirilirsa hic bir sorun yasanmaz
//baska platformlarda ufak sikintilar olabilir kod icinde belirttim
int main()
{
    int mtr[4][4],mtr_yedek[4][4],score=0,score_yedek,durum=2;char way;
    baslangic_random(mtr);
    printf("\nyon tusları:a,s,d,w\tgeri alma:g\tbastan baslama:r    cıkıs:e\n\n");
    printf("    2048 elde etme oyununa hos geldiniz!!!\n");
    printf("_________________________________________\n\tscore:%d    high score:%d\n",score,high_score);
    output(mtr);
    do{
        printf("\n\t    your move : ");
        scanf(" %c",&way);
        if(way=='g')
        {
            geri_alma(mtr,mtr_yedek,&score,&score_yedek);
        }
        system("clear");        //Using clrscr() #include <conio.h> ^for clrscr()^ - For TurboC Compiler //Using system("cls")  - For TurboC Compiler //Using system("clear") - For gcc/g++ compiler in Linux
        printf("\t    last position\n");
        output(mtr);
        yedekleme(mtr,mtr_yedek,&score,&score_yedek);
        yone_gore_islemler(way,mtr,&score,&high_score);
        printf("\n_______________________________________\n\tscore:%d      high score:%d\n",score,high_score);
        output(mtr);
        oyun_bitti_mi(mtr,&score,&durum);
        if(durum==1)
        {
            printf("\nTEBRiKLER OYUNU BiTiRDiNiZ!!!\n");
            break;
        }
        else if(durum==0)
        {
            printf("\nOyunu kaybettiniz\n");
            break;
        }
    }while(way != 'r'&&way!='e');
    if(way=='r')
    {
        system("clear");  //https://www.includehelp.com/c-programming-questions/how-to-clear-output-screen-in-c.aspx
        return main();
    }
    else if(way=='e')
    {
        printf("\ngorusmek uzere...\n");
    }
}
int baslangic_random(int mtrF[][4])
{
    int i,j,yeni_sayi;
    srand((unsigned) time(&t));
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            yeni_sayi = rand() % 5;
            if(yeni_sayi==1||yeni_sayi==3)  //0'lar daha cok olmali
                yeni_sayi = 0;
            mtrF[i][j] = yeni_sayi;
        }
    }
}
int saga_gotur(int mtrF[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=3;j>0;j--)
        {
            if(mtrF[i][j]==0)
            {
                mtrF[i][j] = mtrF[i][j-1];
                if(j==2)
                    mtrF[i][j-1] = mtrF[i][j-2];
                if(j==3)
                {
                    mtrF[i][j-1] = mtrF[i][j-2];
                    mtrF[i][j-2] = mtrF[i][j-3];
                }
                mtrF[i][0] = 0;
            }
        }
    }
}
int sagda_topla(int mtrF[][4],int* scoreF)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=3;j>0;j--)
        {
            if(mtrF[i][j]==mtrF[i][j-1])
            {
                mtrF[i][j] *=2;
                *scoreF += mtrF[i][j];                
                mtrF[i][j-1] = 0;
            }
        }
    }
    saga_gotur(mtrF);
}
int sola_gotur(int mtrF[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(mtrF[i][j]==0)
            {
                mtrF[i][j] = mtrF[i][j+1];
                if(j==1)
                    mtrF[i][j+1] = mtrF[i][j+2];
                if(j==0)
                {
                    mtrF[i][j+1] = mtrF[i][j+2];
                    mtrF[i][j+2] = mtrF[i][j+3];
                }
                mtrF[i][3] = 0;
            }
        }
    }
}
int solda_topla(int mtrF[][4],int* scoreF)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(mtrF[i][j]==mtrF[i][j+1])
            {
                mtrF[i][j] *=2;
                *scoreF += mtrF[i][j];
                mtrF[i][j+1] = 0;
            }
        }
    }
    sola_gotur(mtrF);
}
int asagi_gotur(int mtrF[][4])
{
    int i,j;
    for(j=0;j<4;j++)
    {
        for(i=3;i>0;i--)
        {
            if(mtrF[i][j]==0)
            {
                mtrF[i][j] = mtrF[i-1][j];
                if(i==2)
                    mtrF[i-1][j] = mtrF[i-2][j];
                if(i==3)
                {
                    mtrF[i-1][j] = mtrF[i-2][j];
                    mtrF[i-2][j] = mtrF[i-3][j];
                }
                mtrF[0][j] = 0;
            }
        }
    }
}
int asagida_topla(int mtrF[][4],int* scoreF)
{
    int i,j;
    for(j=0;j<4;j++)
    {
        for(i=3;i>0;i--)
        {
            if(mtrF[i][j]==mtrF[i-1][j])
            {
                mtrF[i][j] *=2;
                *scoreF += mtrF[i][j];
                mtrF[i-1][j] = 0;
            }
        }
    }
    asagi_gotur(mtrF);
}
int yukari_gotur(int mtrF[][4])
{
    int i,j;
    for(j=0;j<4;j++)
    {
        for(i=0;i<3;i++)
        {
            if(mtrF[i][j]==0)
            {
                mtrF[i][j] = mtrF[i+1][j];
                if(i==1)
                    mtrF[i+1][j] = mtrF[i+2][j];
                if(i==0)
                {
                    mtrF[i+1][j] = mtrF[i+2][j];
                    mtrF[i+2][j] = mtrF[i+3][j];
                }
                mtrF[3][j] = 0;
            }
        }
    }
}
int yukarida_topla(int mtrF[][4],int* scoreF)
{
    int i,j;
    for(j=0;j<4;j++)
    {
        for(i=0;i<3;i++)
        {
            if(mtrF[i][j]==mtrF[i+1][j])
            {
                mtrF[i][j] *=2;
                *scoreF += mtrF[i][j];
                mtrF[i+1][j] = 0;
            }
        }
    }
    yukari_gotur(mtrF);
}
int her_turda_yeni_sayi_ekleme(int mtrF[][4])
{
    int yeni_sayi_2 = rand() %2;int kacinci_satir,kacinci_sutun;
    do{
        srand((unsigned) time(&t));
        kacinci_satir = rand() % 4;
        kacinci_sutun = rand() % 4;
    }while(mtrF[kacinci_satir][kacinci_sutun] != 0);    //rastgele sirayla bos yeri bulma
    if(yeni_sayi_2==0)
    yeni_sayi_2 = 2;
    mtrF[kacinci_satir][kacinci_sutun] = yeni_sayi_2*2; //rastgele 2 veya 4 atama
}
int yone_gore_islemler(char yon,int mtrF[][4],int* scoreF,int* high_scoreF)
{   
    int i,j;
    if(yon == 'w')
    {
        yukari_gotur(mtrF);
        yukarida_topla(mtrF,scoreF);
    }
    else if(yon == 's')
    {
        asagi_gotur(mtrF);
        asagida_topla(mtrF,scoreF);
    }
    else if(yon == 'a')
    {
        sola_gotur(mtrF);
        solda_topla(mtrF,scoreF);
    }
    else if(yon == 'd')
    {
        saga_gotur(mtrF);
        sagda_topla(mtrF,scoreF);
    }
    if(*scoreF>*high_scoreF)
        *high_scoreF = *scoreF;
    her_turda_yeni_sayi_ekleme(mtrF);
}
int output(int mtrF[][4])
{
    char* output[4][4][5];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            switch (mtrF[i][j])
            {
            case 0:
                *output[i][j]="    ";
                break;
            case 2:
                *output[i][j]="  2 ";
                break;
            case 4:
                *output[i][j]="  4 ";
                break;
            case 8:
                *output[i][j]="  8 ";
                break;
            case 16:
                *output[i][j]=" 16 ";
                break;
            case 32:
                *output[i][j]=" 32 ";
                break;
            case 64:
                *output[i][j]=" 64 ";
                break;
            case 128:
                *output[i][j]=" 128";
                break;
            case 256:
                *output[i][j]=" 256";
                break;
            case 512:
                *output[i][j]=" 512";
                break;
            case 1024:
                *output[i][j]="1024";
                break;
            case 2048:
                *output[i][j]="2048";
                break;    
            default:
                break;
            }
        }
    }
    printf("\t_____________________\n\t|%s|%s|%s|%s|\n\t---------------------\n\t|%s|%s|%s|%s|\n\t---------------------\n\t|%s|%s|%s|%s|\n\t---------------------\n\t|%s|%s|%s|%s|\n\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n",*output[0][0],*output[0][1],*output[0][2],*output[0][3],*output[1][0],*output[1][1],*output[1][2],*output[1][3],*output[2][0],*output[2][1],*output[2][2],*output[2][3],*output[3][0],*output[3][1],*output[3][2],*output[3][3]);
    //ust tireyi okuyamayabilir kullanılan platforma gore 
}
int geri_alma(int mtrF[][4],int mtr_yedekF[][4],int* scoreF,int* score_yedekF)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            mtrF[i][j]=mtr_yedekF[i][j];
        }
    }
    *scoreF = *score_yedekF;        
}
int yedekleme(int mtrF[][4],int mtr_yedekF[][4],int* scoreF,int* score_yedekF)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            mtr_yedekF[i][j]=mtrF[i][j];
        }
    }
    *score_yedekF = *scoreF; 
}
int oyun_bitti_mi(int mtrF[][4],int* scoreF,int* durumF)
{
    int i,j,kaybetti=0,basardi=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(mtrF[i][j]!=0)
                kaybetti++;
            //18432 min bitiris skoru
            if(*scoreF>=18432&&mtrF[i][j]==2048)
                basardi=1;
        }
    }
    if(basardi==1)
        *durumF=1;
    if (kaybetti==15)
        *durumF=0;
}
*//*
#include <stdio.h>
int FindIndexOfMaximumElementOfArray(int Array[],int NumberOfElementsOfArray);
float AverageOfArray(int Array[],int NumberOfElementsOfArray);
int main()
{
    int NumberOfElementsOfArray;
    printf("How many students?\n");
    scanf("%d",&NumberOfElementsOfArray);
    int Array[NumberOfElementsOfArray-1];
    int i;
    printf("\nenter your student's grades please.\n");
    for(i=0;i<NumberOfElementsOfArray;i++)
    {
        printf("\n%d. student)",i+1);
        scanf("%d",&Array[i]);
    }
    printf("\nMax grade:%d",FindIndexOfMaximumElementOfArray(Array,NumberOfElementsOfArray));
    printf("\nAverage of class:%.2f",AverageOfArray(Array,NumberOfElementsOfArray));
}
int FindIndexOfMaximumElementOfArray(int Array[],int NumberOfElementsOfArray)
{
    int max=0;
    int j;
    for(j=0;j<NumberOfElementsOfArray-1;j++)
    {
        if(max<Array[j])
        {
            max=Array[j];
        }
    }
    return max;
}
float AverageOfArray(int Array[],int NumberOfElementsOfArray)
{
    int sum=0,k,average;
    for (k = 0; k < NumberOfElementsOfArray-1; k++)
    {
        sum = sum + Array[k];
    }
    average=sum/NumberOfElementsOfArray;
    return average;
}   *//*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {

    char input[1000];
    char numbers[10]={'0','1','3','4','5','6','7','8','9'};
    int numbers_int[10]={0,0,0,0,0,0,0,0,0,0};
    gets(input);
    int i;
    for (i=0; i<10; i++) 
    {
        int j;
        for (j = 0; j < strlen(input); j++)
        {
            char temp=numbers[i];
            if(input[j]==temp)
            {
                numbers_int[i]++;
            }
        }
        printf("%d ",numbers_int[i]); 
    }
    // Enter your code here. Read input from STDIN. Print output to STDOUT
        return 0;
}*/
/*#include<stdio.h>
#define PI 3.14
int main( void )
{
	// Tanımlı PI değeri, tanımsız hâle getiriliyor. 
    //Önişlemci Komutları
	#undef PI
    #ifdef PI
        printf("lalala");
    #endif
    #ifndef PI		
		#define PI 3.14
    #endif
	int yaricap;
	float alan;
	printf( "Çemberin yarı çapını giriniz> " );
	scanf( "%d", &yaricap );

	// PI değerinin tanımlı olup olmadığı kontrol ediliyor.
	#ifdef PI
		//PI tanımlıysa, daire alanı hesaplanıyor.
		alan = PI * yaricap * yaricap;
		printf( "Çember alanı: %.2f\n", alan );
	#else
		//PI değeri tanımsızsa, HATA mesajı veriliyor.
		printf("HATA: Alan değeri tanımlı değildir.\n");
	#endif
	return 0;
} */    /*
#include<stdio.h>
#define HASSASLIK_DERECESI 2
int main( void )
{
	int yaricap;
	float alan;
	printf( "Çemberin yarı çapını giriniz> " );
	scanf( "%d", &yaricap );

	// Hassaslık derecesi, pi sayısının virgülden kaç 
	// basamak sonrasının hesaba katılacağını belirtir.
	// Eğer hassaslık derecesi bunlara uymuyorsa, alan 
	// değeri -1 yapılır.
	
	#if ( HASSASLIK_DERECESI == 0 )
		alan = 3 * yaricap * yaricap;
	#elif ( HASSASLIK_DERECESI == 1 )
		alan = 3.1 * yaricap * yaricap;
	#elif ( HASSASLIK_DERECESI == 2 )
		alan = 3.14 * yaricap * yaricap;
	#else
		alan = -1;
	#endif

	printf( "Çember alanı: %.2f\n", alan );
	return 0;
}*/     /*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(void) 
{
    //ust : bas,orta,son
    int n;int azalma=0;
    printf("sekil buyuklugu [1,9] aralıgında : ");
    scanf("%d", &n);
    for (int tane = 2*n-1; tane>0; tane-=2)
    {
        //bas
        int basa = (2*n-1-tane)/2;
        for (int i = 0; i < basa; i++)
        {
            int yazilacak_basa = n;
            printf("%d ",yazilacak_basa-i);
        }
        //orta
        for (int j = tane; j > 0; j--)
        {
            printf("%d ",n-azalma);
        }
        azalma++;
        //son
        int sona = (2*n-1-tane)/2;
        for (int i = sona; i > 0; i--)
        {
            int yazilacak_sona = n-i+1;
            printf("%d ",yazilacak_sona);
        }
        printf("\n");
    }
    //alt:bas,orta,son
    int tane_2=1,ortaya_yazilacak_sayi=2;
    for (int k = n-1; k >0; k--)
    {
        //bas
        int basa_2 = k;
        int azalma_2=0;
        for (int i = basa_2; i>0; i--)
        {
            int yazilacak_basa_2 = n;
            printf("%d ",yazilacak_basa_2-azalma_2);
            azalma_2++;
        }
        //orta
        for (int j = 0; j<tane_2; j++)
        {
            printf("%d ",ortaya_yazilacak_sayi);
        }
        tane_2+=2;
        ortaya_yazilacak_sayi++;
        //son
        int yazilacak_sona_2 = ortaya_yazilacak_sayi-1;
        for (int i = k; i>0; i--)
        {
            printf("%d ",yazilacak_sona_2);
            yazilacak_sona_2++;
        }
        printf("\n");
    }
    return 0;
}   */

//file tutorial begins

/*
#include<stdio.h>
int main(void)
{
    FILE *outfile, *infile;
    int b =5,f;
    float a= 1.2,c=3.4,e,g;
    outfile = fopen("test","w");
    fprintf(outfile,"%f\n%d %f",a,b,c);
    fclose(outfile);
    infile = fopen("test","r");
    fscanf(infile,"%f %d %f",&e,&f,&g);
    fclose(infile);
    printf("%f %d %f\n",a,b,c);
    printf("%f %d %f\n",e,f,g);
} */    /*
#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("test_2","w");
    fprintf(fp,"Alperen Olcer");
    fclose(fp);
    fp = fopen("test_2","r");
    char ch;
    while (!feof(fp))
    {
        ch = getc(fp);
        printf("%c\n",ch);
    }
    fclose(fp);
}   */  /*
#include<stdio.h>
void main ()
{
    //open file and write in it
    FILE *fp;
    fp = fopen("test_3","w");
    fprintf(fp,"hello there");
    fclose(fp);

    //read from file but limited read (first 5 char)
    char buffer[5];
    fp = fopen("test_3","r");
    fread(buffer,1,5,fp);
    // size_t fread(void *ptr, size_t length, size_t count, FILE *filename);
    //ptr verinin içine okunacagi blok
    //size her blogun boyutu
    //n kac tane okunacagi
    fclose(fp);
    printf("file's first five character : %s\n",buffer);
}   */  /*
#include<stdio.h>
void main(void)
{
    //writing an array into a file
    char array[10] = {'0','1','2','3','4','5','6','7','8','9'};
    FILE *fp;
    fp = fopen("test_4","w");
    fwrite(array,1,10,fp); //explanation is at 46 (familiar)
    fclose(fp);
    //testing if it worked
    char reading_array[10];
    fp = fopen("test_4","r");
    fread(reading_array,1,10,fp);
    fclose(fp);
    printf("%s",reading_array);
    printf("\n");
}   */ /*
#include<stdio.h>
FILE *fp;
int main()
{
    //opening and filling file
    fp = fopen("test_5","w");
    fprintf(fp,"helloalperen");
    fclose(fp);
    //reading
    char read[40];
    fp = fopen("test_5","r");
    fscanf(fp,"%s",read);
    fclose(fp);
    printf("%s\n",read);
    //changing file
    fp = fopen("test_5","w");
    fseek(fp, 6,SEEK_SET);   //SEEK_SET (FROM BEGINNNIG),SEEK_CUR (FROM WHERE CURSOR İS),SEEK_END (FROM END OF THE FILE)
    fputs(" sumeyra",fp);
    fclose(fp);
    //reading
    char read_2[40];
    fp = fopen("test_5","r");
    fscanf(fp,"%s",read_2);
    fclose(fp);
    printf("%s\n",read_2);
} */    /*
#include<stdio.h>
int main()
{
    //simple reading example
    FILE *fp;
    fp = fopen("test_4","r");
    char read[10];
    fscanf(fp,"%s",read);
    printf("%s",read);
    fclose(fp);
} */    /*
#include<stdio.h>
FILE *fp;
int main()
{
    //changing
    fp = fopen("test_6","w");
    fputs("helloalperen",fp);
    fseek(fp, 5,SEEK_SET);   //SEEK_SET (FROM BEGINNNIG),SEEK_CUR (FROM WHERE CURSOR İS),SEEK_END (FROM END OF THE FILE)
    fputs("sumeyra",fp);
    fclose(fp);
    //reading
    char read_2[40];
    fp = fopen("test_6","r");
    fscanf(fp,"%s",read_2);
    fclose(fp);
    printf("%s\n",read_2);
}   */  /*
#include<stdio.h>
void main()
{
    //ftell how many char in file
    FILE *fp;
    fp = fopen("test_7","w");
    fprintf(fp,"how is it going?");
    printf("file lenght : %ld \n",ftell(fp));
    fclose(fp);
}   */

//file tutorial ends

//https://www.programiz.com/c-programming/c-dynamic-memory-allocation

/*                  BAZI FONKSIYONLAR       ( math.h ) 
double ceil( double n ) : Virgüllü n sayısını, kendisinden büyük olan ilk tam sayıya tamamlar. Örneğin ceil(51.4) işlemi, 52 sonucunu verir.
double floor( double n ) : Virgüllü n sayısının, virgülden sonrasını atarak, bir tam sayıya çevirir. floor(51.4) işlemi, 51 sayısını döndürür.
double fabs( double n ) : Verilen n sayısının mutlak değerini döndürür. fabs(-23.5), 23.5 değerini verir.
double fmod( double a, double b ) : a sayısının b sayısına bölümünden kalanı verir. (Daha önce gördüğümüz modül (%) operatörü, sadece tam sayılarda kullanılırken, fmod fonksiyonu virgüllü sayılarda da çalışır.)
double pow( double a, double b ) : Üstel değer hesaplamak için kullanılır; ab değerini verir.
double sqrt( double a ) : a'nın karekökünü hesaplar.
*/  /*
#include<stdio.h>
#include<math.h>
void main(void)
{
    int n;
    printf("enter an number : ");
    scanf("%d",&n);
    if (n%2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i==floor(n/2))
                {
                    printf(" 1 ");
                }
                else
                {
                    if (j==floor(n/2))
                    {
                        printf(" 1 ");
                    }
                    else
                    {
                        printf(" 0 ");
                    }
                }
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i==floor(n/2)||i==floor(n/2)-1)
                {
                    printf(" 1 ");
                }
                else
                {
                    if (j==floor(n/2)||j==floor(n/2)-1)
                    {
                        printf(" 1 ");
                    }
                    else
                    {
                        printf(" 0 ");
                    }
                }
            }
            printf("\n");
        }
    }
}       */  /*
#include<stdio.h>
int main()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);
    int flag=1;
    while (flag)
    {
        n++;
        int i;
        for (i = 2; i <=n; i++)
        {
            if((n%i)==0)
            {
                break;
            }
        }
        if (i==n)
            flag=0;
    }
    printf("higher than your number and asal=%d\n",n);
}   */  /*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);
    int **mtr;
    mtr=(int **)malloc(n*sizeof(int *));
    for( int i = 0; i < n; i++ ) {
		mtr[i] = malloc( n * sizeof(int) );
	}
    mtr[0][0]=1;
    mtr[1][0]=1;
    mtr[0][1]=1;
    for (int k = 2; k < n; k++)
    {
        mtr[0][k]= mtr[0][k-2] + mtr[0][k-1];
        mtr[k][0]= mtr[k-2][0] + mtr[k-1][0];
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            mtr[i][j]= mtr[i-1][j-1] + mtr[i][j-1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ",mtr[i][j]);
        }
        printf("\n");
    }
    free(mtr);
}   */  /*
// for running gcc -g denemeee.c -lm -o denemeee 
#include <stdio.h>
#include <math.h>
#define PI  3.14159
double fac(int);
double Sinus(double,double);
double Kuvvet(double,int );
double Cosinus(double,double);
int main()
{
    float precision,Q;
    double i;
    printf("precision : ");
    scanf("%f",&precision);
    
    for (Q = 0 ; Q <= 360.0;Q+=30)
        {
            i=Q*(PI/180);
            printf("degree:%.1f\tradian:%f\tcos(x):%f\tsin(x):%f\t\n",Q,i,Cosinus(i,precision),Sinus(i,precision));
        }

    return 0;
}
double fac(int x)
{
    int i,fac=1;
    for(i=1;i<=x;i++)
    {
        fac=fac*i;
    }
    return fac;
}
double Sinus(double x,double precision)
{
    double sonuc=0,sonuc_yedek=0;
    int i;

    for (i=0;i<10;i++)
    {
        sonuc_yedek=sonuc;
        sonuc += Kuvvet(-1,i) * Kuvvet(remainder(x,PI),2*i+1) / fac(2*i+1);
        if(precision>fabs(sonuc-sonuc_yedek))
        {
            break;
        }
    }
    return sonuc;
}
double Kuvvet(double taban,int us)
{
    double sonuc=1;
    int i;
    for (i=1;i<=us;i++)
    {
       sonuc*=taban;
    }
    return sonuc;
}
double Cosinus(double x,double precision)
{
    double sonuc=0,sonuc_yedek=0;
    int i;
    for (i=0;i<20;i++)
    {
        sonuc_yedek=sonuc;
        sonuc += Kuvvet(-1,i) * Kuvvet(remainder(x,PI),2*i) / fac(2*i);
        if(precision>fabs(sonuc-sonuc_yedek))
        {
            break;
        }
    }
    return sonuc;
}   */      /*

//  HACKER_RANK  Sorting Array of Strings (dynamic arrays) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort( char* a,  char* b) {
    if(strcmp(a,b)>0)
    {
        return 1;
    }
    return 0;
}

int lexicographic_sort_reverse( char* a,  char* b) {
    
    if(strcmp(a,b)<0)
    {
        return 1;
    }
    return 0;
}
int distinct(const char* str){
    int alphabet[26]={0};
    for(int i=0;str[i] != '\0'; i++){
        alphabet[str[i] - 'a']++;
    }
    int count = 0;
    for(int i=0;i<26;i++){
        if(alphabet[i] >= 1)
            count++;
    }
    return count;
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int d1=distinct(a),d2=distinct(b);
    if (d1>d2) {
        return 1;
    }
    else if (d1==d2&&strcmp(a,b)>0) {
        return 1;
    }
    return 0;
}


int sort_by_length(const char* a, const char* b) {
    if(strlen(a)>strlen(b))
    {
        return 1;
    }
    else if (strlen(a)==strlen(b)&&strcmp(a,b)>0) {
        return 1;
    }
    return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i = 0; i < len; i++)
    {
        for (int j=0; j<len-1; j++) 
        {
            if (cmp_func(*(arr+j),*(arr+j+1)))
            {
                char *temp;
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }   
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}   */  /*
#include<stdio.h>
#include<string.h>
int main()
{
    char hexadecimal[10],count[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int hexLength;
    printf("Enter a hexadecimal number : ");
    scanf("%s",&hexadecimal);
    if (hexadecimal[0] == '0')
    {
        printf("0 for all number bases");
        return 0;
    }
    else if(hexadecimal[0] == '-')
    {
        printf("Only positive numbers.");
        return 0;
    }
    hexLength = strlen(hexadecimal);
    printf("hexLength = %d\n",hexLength);
    printf("Given hexadecimal number : %s\n",hexadecimal);
    // converting hexadecimal to decimal
    int decimal = 0,step = 1;
    int i,j;
    for ( i = hexLength-1; i >= 0; i--)
    {
        j = 0;
        while (hexadecimal[i] != count[j])
        {
            j++;
        }
        decimal += step*j;
        step *= 16;
    }
    printf("Decimal equivalent : %d\n",decimal);
    //converting decimal to binary
    long step_binary = 1;
    int remain;
    char binary[100];
    int k = 0;
    while (decimal!=0)
    {
        remain = decimal%2; 
        decimal = decimal / 2;
        if (remain == 1)
            binary[k] = '1';
        else
            binary[k] = '0';
        k++;
        step_binary = step_binary * 10; 
    }
    //reversing binary string digits
    char tmp_char;
    for ( i = 0; i < k/2; i++)
    {
        tmp_char = binary[i];
        binary[i] = binary[k-1-i];
        binary[k-1-i] = tmp_char;
    }
    printf("binary : %s\n",binary);
    return 0;  
}   */
// dinamik bellek kullanimi
//isaretci_adi = calloc( eleman_sayisi, her_elemanin_boyutu );  //yer ayirir ve 0 atar          her_elemanin_boyutu --> sizeof(int or vs.)
//isaretci_adi = malloc( eleman_sayisi * her_elemanin_boyutu ); //yer ayirir ve 0 atar
//malloc(  ) fonksiyonu, calloc(  ) gibi dinamik bellek ayrımı için kullanılır. calloc(  ) fonksiyonundan farklı olarak ilk değer ataması yapmaz. 
//free( )
//matrisler icin ornek kullanim
/*
#include<stdio.h>
#include<stdlib.h>
int main( void )
{
	int **matris;
	int satir_sayisi, sutun_sayisi;
	int i, j;
	printf( "Satır sayısı giriniz> " );
	scanf( "%d", &satir_sayisi );
	printf( "Sütun sayısı giriniz> " );
	scanf( "%d", &sutun_sayisi );

	// Once satir sayisina gore hafizada yer ayiriyoruz. 
	// Eger gerekli miktar yoksa, uyari veriliyor.
	matris = (int **)malloc( satir_sayisi * sizeof(int) );
	if( matris == NULL )
		printf( "Yetersiz bellek!" );

	// Daha sonra her satirda, sutun sayisi kadar hucrenin 
	// ayrilmasini sagliyoruz.
	for( i = 0; i < satir_sayisi; i++ ) {
		matris[i] = malloc( sutun_sayisi * sizeof(int) );
		if( matris[i] == NULL )
			printf( "Yetersiz bellek!" );
	}

	// Ornek olmasi acisindan matris degerleri 
	// gosteriliyor. Dizilerde yaptiginiz butun 
	// islemleri burada da yapabilirsiniz.
	for( i = 0; i < satir_sayisi; i++ ) {
		for( j = 0; j < sutun_sayisi; j++ )
			printf( "%d ", matris[i][j] );
		printf( "\n" );
	}

	// Bu noktada matris ile isimiz bittiginden 
	// hafizayi bosaltmamiz gerekiyor. Oncelikle
	// satirlari bosaltiyoruz. 
	for( i = 0; i < satir_sayisi; i++ ) {
		free( matris[i] );
	}
	// Satirlar bosaldiktan sonra, matrisin 
	// bos oldugunu isaretliyoruz.
	free( matris );

	return 0;
}
*/      /*
#include<stdio.h>
int main( int argc, int *arg[] )
{
	int i;
	for( i = 1; i < argc; i++ ) {
		printf( "%d. argüman: %s\n", i, arg[i] );
	}
	return 0;
}   */  /*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main( int argc, char *arg[] )
{
	// Eger eksik arguman soz konusuysa, 
	// program calismamalidir.
	if( argc < 4 ) {
		printf( "Hata: Eksik argüman!\n");
		return;
	}

	float sayi_1, sayi_2;
	char islem_tipi[2];
	sayi_1 = atof( arg[1] );
	strcpy(	islem_tipi, arg[2] );
	sayi_2 = atof( arg[3] );

	// Verilen sembolun neye esit oldugu asagidaki 
	// if-else if merdiveniyle saptaniyor.
	if( !strcmp( islem_tipi, "+" ) )
		printf( "Toplam: %.2f\n", sayi_1 + sayi_2 );
	else if( !strcmp( islem_tipi, "-" ) )
		printf( "Fark: %.2f\n", sayi_1 - sayi_2 );
	else
		  printf( "Hatalı işlem!\n" );
	return 0;
}   */
/*
#include<stdio.h>
#include<math.h>

int main()
{
    float values[12];
    char months[12][20];
    int i,j;
    for ( i = 0; i < 3; i++)
    {
        printf("Enter the month name and rainfall amount : ");
        scanf("%s %f",months[i],&values[i]);
    }
    
    printf("=======================================\n");
    printf("Month Name\t\tRainfall Amount\n");
    printf("=======================================\n");

    for ( i = 0; i < 3; i++)
    {
        printf("%s\t\t\t\t\t",months[i]);
        for ( j = 1; j <= values[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
*/
/*
#include <stdio.h>
#include <string.h>

int count_char_in_str(char* , char);

int main()
{
    char STR[40],CH;
    printf("\nEnter string : ");
    scanf("%[^\n]%*c",STR);
    
    printf("\nEnter character : ");
    scanf("%c",&CH);

    printf("\nIn { %s } %d times %c\n", STR, count_char_in_str(STR, CH), CH);

    return 0;
}
int count_char_in_str(char* string, char ch)
{
    int i,count = 0;
    for ( i = 0; i < strlen(string); i++)
    {
        if(string[i] == ch)
            count ++;
    }
    return count;
}

*/
/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void column_min(int [10][8], int [8]);

int main()
{
    srand(time(NULL));
    int A[10][8], B[8], i, j;
    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 8; j++)
        {
            
            A[i][j] = rand() % 98 + 2;
        }
    }
    column_min(A, B);
    
    return 0;
}

void column_min(int matrix[10][8], int array[8])
{
    
    int min, i, j;
    for ( j = 0; j < 8; j++)
    {
        min = 100;
        for ( i = 0; i < 10; i++)
        {
            if (min > matrix[i][j])
                min = matrix[i][j];
        }
        array[j] = min;
    }
    
    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 8; j++)
            printf("%d ",matrix[i][j]);

        printf("\n");
    }

    printf("\n");

    for ( i = 0; i < 8; i++)
        printf("%d ", array[i]);
    
    printf("\n");
}
*/
/*
#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[30];
    int numeric_grade;
}students;

students student;

int main()
{
    FILE *info;
    FILE *out;
    info = fopen("inf.txt", "r");
    out = fopen("out.txt", "w");
    char letter_grade[5];
    int previous_id = 0;
    
    while (1) //feof(info) != EOF doesn't work for some reason. I overcomed it with another way 
    {
        fscanf(info, "%d %s %d", &student.id, student.name, &student.numeric_grade);
        
        if (previous_id == student.id)
            break;

        previous_id = student.id;
        
        if (student.numeric_grade >= 90)
        {
            strcpy(letter_grade, "AA");
        }
        else if (student.numeric_grade >= 80)
        {
            strcpy(letter_grade, "BB");
        }
        else if (student.numeric_grade >= 70)
        {
            strcpy(letter_grade, "CC");
        }
        else
        {
            strcpy(letter_grade, "FF");
        }
        
        fprintf(out, "%d %s %d %s ", student.id, student.name, student.numeric_grade, letter_grade);

    }

    fclose(info);
    fclose(out);

    return 0;
}
*/
