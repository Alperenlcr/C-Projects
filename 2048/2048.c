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
int yone_gore_islemler(char,int [][4],int* scoreF,int* high_scoreF,int [][4]);
int her_turda_yeni_sayi_ekleme(int [][4]);
int baslangic_random(int [][4]);
int output(int [][4]);
int geri_alma(int [][4],int[][4],int* scoreF,int* score_yedekF);
int yedekleme(int [][4],int[][4],int* scoreF,int* score_yedekF);
int oyun_bitti_mi(int [][4],int* scoreF,int* durumF);
int hamle_yapildiginda_degisiklik_oluyor_mu(int [][4],int[][4]);
//hamle yapıldıgında degisiklik oluyor mu?
time_t t;
int high_score=0; //global
//!!!!!!!!!!
//https://www.onlinegdb.com/online_c_compiler burdan calistirilirsa hic bir sorun yasanmaz  !!!!!!!!!onemli!!!!!!!!!!
//!!!!!!!!!!
//baska platformlarda ufak sikintilar olabilir kod icinde belirttim
int main()
{
    int mtr[4][4],mtr_yedek[4][4],score=0,score_yedek,durum=2;char way;
    baslangic_random(mtr);
    printf("\nyon tusları:a,s,d,w\tgeri alma:g\tbastan baslama:r    cıkıs:e\n\n");
    printf("   2048 elde etme oyununa hos geldiniz!!!\n");  
    printf("_______________________________________________\n\tscore:%d    high score:%d\n",score,high_score);
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
        yone_gore_islemler(way,mtr,&score,&high_score,mtr_yedek);
        printf("\n_______________________________________\n\tscore:%d      high score:%d\n",score,high_score);
        output(mtr);
        oyun_bitti_mi(mtr,&score,&durum);
        if(durum==1)
        {
            printf("\nTEBRiKLER OYUNU BiTiRDiNiZ!!!\n");  //emojiler platformdan platforma farklilik gosterebilir.
            break;
        }
        else if(durum==0)
        {
            printf("\nOyunu kaybettiniz.\n");
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
        printf("\ngorusmek uzere.\n");
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
int yone_gore_islemler(char yon,int mtrF[][4],int* scoreF,int* high_scoreF,int mtr_yedekF[][4])
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
    if(*scoreF>*high_scoreF) //high score update
        *high_scoreF = *scoreF;
    if (yon!='g') //geri alindiginda yaziyi yadirmamasi icin
    {
        if(yon!='e') //oyun bitirilmek istendiginde yaziyi yazmamak icin
        {
            int degisiklik=hamle_yapildiginda_degisiklik_oluyor_mu(mtrF,mtr_yedekF);
            if (degisiklik==1)
            {
                her_turda_yeni_sayi_ekleme(mtrF);
            }
            else
            {
                printf("\nyaptıgınız hamle degisiklik olusturmadigi icin gecersizdir.\n");
                printf("o yuzden yeni sayi eklenmemistir.Baska hamle deneyiniz.\n");
            }   
        }
    }
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
            //18432 minumum bitiris skoru
            if(*scoreF>=18432&&mtrF[i][j]==2048)
                basardi=1;
        }
    }
    if(basardi==1)
        *durumF=1;
    if (kaybetti==16)
    {
        //yapilabilir hamle var mi?
        int yapilabilir_hamle_var_mi=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<3;j++)
            {
                if(mtrF[i][j]==mtrF[i][j+1])
                {
                    yapilabilir_hamle_var_mi++;
                    break;
                }
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<4;j++)
            {
                if(mtrF[i][j]==mtrF[i+1][j])
                {
                    yapilabilir_hamle_var_mi++;
                    break;
                }
            }
        }
        if(yapilabilir_hamle_var_mi==0)
            *durumF=0;
    }
}
int hamle_yapildiginda_degisiklik_oluyor_mu(int mtrF[][4],int mtr_yedekF[][4])
{
    int sayac=0,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if (mtr_yedekF[i][j]==mtrF[i][j])
            {
                sayac++;
            }
        }
    }
    if(sayac==16)
        return 0;
    else
        return 1;
}
