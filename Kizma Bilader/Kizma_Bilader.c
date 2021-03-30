#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char* yazdir(float,int);

int main()
{
    int oyun_tahtasi[9][9]={
    {401,402,999,519,518,517,999,301,302},
    {403,404,999,520,305,516,999,303,304},
    {999,999,999,521,306,515,999,999,999},
    {525,524,523,522,307,514,513,512,511},
    {526,405,406,407,999,207,206,205,510},
    {101,103,529,530,107,506,507,508,509},
    {999,999,999,531,104,505,999,999,999},
    {527,105,999,532,102,504,999,201,202},
    {528,106,999,501,502,503,999,203,204}};
    
    int kalelerin_satirlari[16] = {7,7,8,8,7,7,8,8,0,0,1,1,0,0,1,1};
    int kalelerin_sutunlari[16] = {0,1,0,1,7,8,7,8,7,8,7,8,0,1,0,1};
    int cikis_noktasi_satirlari[4] = {8,5,0,3};
    int cikis_noktasi_sutunlari[4] = {3,8,5,0};
    int cikis_noktasi_degerleri[4] = {501,509,517,525};
    int piyon_degerleri[4][4] = {{101,102,103,104},{201,202,203,204},{301,302,303,304},{401,402,403,404}};
    int piyonun_turlama_sayisi[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int bitti_koordinatlari[4][8] = {{8,4,7,4,6,4,5,4},{4,8,4,7,4,6,4,5},{0,4,1,4,2,4,3,4},{4,0,4,1,4,2,4,3}};
    int oyuncu_sayisi,hamle ,zar ,tur = 0,i,j,k,a,bakilacak_sayi,broke,bitti=0,fark;
    int piyonlarin_yerleri[4][2];
    int oynanabilir[5] = {0,0,0,0,0}, temp, flag, amac;
    float x,y,koordinat;
    char sira[4][20] = {"Sarinin","Kirmizinin", "Yesilin", "Mavinin"};
    char oynanabilirlik[2][15] = {"oynanamaz","oynanabilir"};
    srand(time(NULL));

    printf("Oyunu test icin mi oynamak icin mi actiniz ?\n");
    printf("Testin ozelligi : Zari oynayan belirler. ");
    printf("Test icin actiysaniz 1 giriniz oynamak icin ise 2 giriniz.\n");
    scanf("%d",&amac);

    //oyuncu sayisi alma
    printf("Oyunun donus sirasi : Sari, Kirmizi, Yesil, Mavi\n");
    i=1;
    do
    {   
        if (i!=1)
            printf("Oyun 2 , 3 , 4 kisi oynanabilmektedir.\n");
        i++;
        printf("Kac oyuncu : ");
        scanf("%d",&oyuncu_sayisi);    
    } while (oyuncu_sayisi < 2 || oyuncu_sayisi > 4);
   

    getchar();
    while (!bitti)
    {
        tur++;
        while (tur>oyuncu_sayisi)
            tur -= oyuncu_sayisi;

        //tablo cizdirme
        printf("\t\t\t______________________________________________\n");
        for (i = 0; i < 9; i++)
        {
            printf("\t\t\t|");
            for (j = 0; j < 9; j++)
            {
                x = i;y = j;
                koordinat = x+y/10;
                bakilacak_sayi = oyun_tahtasi[i][j];
                yazdir(koordinat,bakilacak_sayi);
            }
            printf("\n\t\t\t---------------------------------------------\n");
        }

        //zar atma
        if (amac == 1)
        {
            printf("%s zarini belirleyiniz : ",sira[tur-1]);
            scanf("%d",&zar);
            while (zar > 6 || zar < 1)
            {
                printf("Zar [1,6] araliginda olabilir. Tekrar deneyiniz.\n");
                scanf(" %d",&zar);
            }
        }
        else
        {
            zar = (rand() % 6) + 1;
            printf("%s zari : %d\n",sira[tur-1], zar);
        }

        //piyonlarin yerlerini bulma
        broke = 0;
        for (k = 1; k < 5; k++)
        {
            bakilacak_sayi = tur*100 + k;
            i = 0;
            while (i < 9 && broke != 4)
            {
                j = 0;
                while (j < 9 && broke != 4)
                {
                    if (bakilacak_sayi == oyun_tahtasi[i][j])
                    {
                        switch (k)
                        {
                        case 1:
                            piyonlarin_yerleri[0][0] = i;
                            piyonlarin_yerleri[0][1] = j;
                            break;
                        case 2:
                            piyonlarin_yerleri[1][0] = i;
                            piyonlarin_yerleri[1][1] = j;
                            break;
                        case 3:
                            piyonlarin_yerleri[2][0] = i;
                            piyonlarin_yerleri[2][1] = j;
                            break;
                        case 4:
                            piyonlarin_yerleri[3][0] = i;
                            piyonlarin_yerleri[3][1] = j;
                            break;
                        }
                        broke++;
                    }
                    j++;
                }
                i++;
            }
        }
        
        //oynanabilecekleri bulma ve belirtme

        oynanabilir[0] = 0; oynanabilir[1] = 0; oynanabilir[2] = 0; oynanabilir[3] = 0;
        for (hamle = 1; hamle < 5; hamle++)
        {
            //piyon kalede mi?
            if (piyonlarin_yerleri[hamle-1][0] == kalelerin_satirlari[(tur-1)*4+hamle-1] && piyonlarin_yerleri[hamle-1][1] == kalelerin_sutunlari[(tur-1)*4+hamle-1])
            {
                if ( zar==6 )        
                {
                    //cikis noktasi uygun mu?
                    if( oyun_tahtasi [cikis_noktasi_satirlari[tur-1]] [cikis_noktasi_sutunlari[tur-1]] < piyon_degerleri[tur-1][0] || oyun_tahtasi [cikis_noktasi_satirlari[tur-1]] [cikis_noktasi_sutunlari[tur-1]] > piyon_degerleri[tur-1][3] )
                        oynanabilir[hamle-1]++;
                }
            }
            //evde mi?
            else if(oyun_tahtasi [kalelerin_satirlari[(tur-1)*4+hamle-1]] [kalelerin_sutunlari[(tur-1)*4+hamle-1]] >= tur*100+5 && oyun_tahtasi [kalelerin_satirlari[(tur-1)*4+hamle-1]] [kalelerin_sutunlari[(tur-1)*4+hamle-1]] <= tur*100+7)
                continue;
            
            //yolda
            else
            {   
                bakilacak_sayi = oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]][kalelerin_sutunlari[(tur-1)*4+hamle-1]] + zar;      
                if (bakilacak_sayi>532)
                    bakilacak_sayi -= 32;
                //gidecegi yer dolu mu?
                //evine girme alanina gelmis mi?
                fark = bakilacak_sayi-502-(tur-1)*8;
                i = oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]] [kalelerin_sutunlari[(tur-1)*4+hamle-1]];
                if (  piyonun_turlama_sayisi[(tur-1)*4+hamle-1]>0 && fark <= 6 && fark > 0 && ( oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]] [kalelerin_sutunlari[(tur-1)*4+hamle-1]] <= 502+(tur-1)*8 || i == 532 || i == 531 || i == 530 || i == 529) )
                {
                    //girecek mi ve girecegi yer bos mu?
                    if ( fark <= 3 && oyun_tahtasi[bitti_koordinatlari[tur-1][(fark)*2]] [bitti_koordinatlari[tur-1][(fark)*2+1]] == tur*100+4+fark)
                        oynanabilir[hamle-1]++;
                    else
                        continue;
                }
                //siradan ilerleme
                else
                {
                    broke = 0,flag = 0,i = 0;
                    while(i < 9 && !broke)
                    {
                        j = 0;
                        while(j < 9 && !broke)
                        {
                            if (bakilacak_sayi == oyun_tahtasi[i][j])
                            {
                                //gidecegi yerde piyon var mi?
                                a = 0;
                                while (a < 16 && !broke)
                                {
                                    if (i == kalelerin_satirlari[a] && j == kalelerin_sutunlari[a])
                                    {
                                        //kendi piyonu mu?
                                        if (a == (tur-1)*4 || a == (tur-1)*4+1 || a == (tur-1)*4+2 || a == (tur-1)*4+3)
                                            flag = 1;
                                        broke = 1;
                                    }
                                    a++;
                                }
                                broke = 1;
                            }
                            j++;
                        }
                        i++;
                    }
                    if (flag == 0)
                        oynanabilir[hamle-1]++;
                }
            }
        }
        
        //output
        printf("%s 1. piyonu %s , 2. piyonu %s , 3.piyonu %s , 4.piyonu %s.\n",sira[tur-1],oynanabilirlik[oynanabilir[0]] , oynanabilirlik[oynanabilir[1]] , oynanabilirlik[oynanabilir[2]] , oynanabilirlik[oynanabilir[3]]);
        if (oynanabilir[0] == 0 && oynanabilir[1] == 0 && oynanabilir[2] == 0 && oynanabilir[3] == 0)
            {
                printf("Oynanabilecek piyonunuz olmadigi icin siranizi atliyoruz.\n");
                printf("Devam etmek icin enter basiniz.  ");
                if (amac == 1)
                    getchar();
                getchar();
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                if (hamle == 5)
                    hamle = 0;
                printf("\t\t\tGecen turda %s zari %d ve hamlesi %d idi\n",sira[tur-1],zar,hamle);
                printf("\t\t\t______________________________________________\n");
                for (i = 0; i < 9; i++)
                {
                    printf("\t\t\t|");
                    for (j = 0; j < 9; j++)
                    {
                        x = i;y = j;
                        koordinat = x+y/10;
                        bakilacak_sayi = oyun_tahtasi[i][j];
                        yazdir(koordinat,bakilacak_sayi);
                    }
                    printf("\n\t\t\t---------------------------------------------\n");
                }
                continue;
            }
        
        //oynanabilir piyon secene kadar sorma (hepsi oynanamaz ise mesaj verme ve sira atlama)
        i=1;
        while (1)
        {
            if (oynanabilir[hamle-1] == 1) //hamle 5 te kaldigi icin ilk turda sorun yok
                break;
            else
            {
                do
                {   
                    if (i!=1)
                        printf("1 , 2 , 3 , 4 piyonlari vardir. Sectiginiz piyonun oynanabilirligi yoktur.\n");
                    i++;
                    printf("%s oynayacagi piyonu : ",sira[(tur-1) % oyuncu_sayisi]);
                    scanf("%d",&hamle);
                } while (hamle < 1 || hamle > 4);
            }   
        }
        
        //output
        printf("Devam etmek icin enter basiniz.  ");
        getchar();
        getchar();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        if (hamle == 5)
            hamle = 0;
        printf("\t\t\tGecen turda %s zari %d ve hamlesi %d idi\n",sira[tur-1],zar,hamle);
        printf("\t\t\t______________________________________________\n");
        for (i = 0; i < 9; i++)
        {
            printf("\t\t\t|");
            for (j = 0; j < 9; j++)
            {
                x = i;y = j;
                koordinat = x+y/10;
                bakilacak_sayi = oyun_tahtasi[i][j];
                yazdir(koordinat,bakilacak_sayi);
            }
            printf("\n\t\t\t---------------------------------------------\n");
        }
        
        //oynatma
        
        //piyon kalede mi?
        if (piyonlarin_yerleri[hamle-1][0] == kalelerin_satirlari[(tur-1)*4+hamle-1] && piyonlarin_yerleri[hamle-1][1] == kalelerin_sutunlari[(tur-1)*4+hamle-1])
        {
            if ( zar==6 )        
            {
                //cikis noktasi uygun mu?
                if( oyun_tahtasi [cikis_noktasi_satirlari[tur-1]] [cikis_noktasi_sutunlari[tur-1]] < piyon_degerleri[tur-1][0] || oyun_tahtasi [cikis_noktasi_satirlari[tur-1]] [cikis_noktasi_sutunlari[tur-1]] > piyon_degerleri[tur-1][3] )
                {
                    //cikis noktasinda rakip piyon yok mu?
                    if (oyun_tahtasi [cikis_noktasi_satirlari[tur-1]] [cikis_noktasi_sutunlari[tur-1]] == cikis_noktasi_degerleri[tur-1])
                    {
                        oyun_tahtasi [cikis_noktasi_satirlari[tur-1]] [cikis_noktasi_sutunlari[tur-1]] = piyon_degerleri [tur-1] [hamle-1];
                        oyun_tahtasi [kalelerin_satirlari[(tur-1)*4+hamle-1]] [kalelerin_sutunlari[(tur-1)*4+hamle-1]] = cikis_noktasi_degerleri [tur-1];
                    }
                    //piyon kirarak cikacak
                    else
                    {
                        //hangi piyonu kiracak
                        bakilacak_sayi = cikis_noktasi_degerleri[tur-1];
                        broke = 0;
                        i = 0;
                        while (i<9 && !broke)
                        {
                            j = 0;
                            while (j<9 && !broke)
                            {
                                if (bakilacak_sayi == oyun_tahtasi[i][j])
                                    broke = 1;
                                j++;
                            }
                            i++;
                        }  
                        //kirdigi piyonu evine,oynanan piyonu cikis noktasina,kaleye de cikis noktasini atama
                        i--;j--;
                        oyun_tahtasi[i][j] = oyun_tahtasi [cikis_noktasi_satirlari[tur-1]] [cikis_noktasi_sutunlari[tur-1]];
                        oyun_tahtasi [cikis_noktasi_satirlari[tur-1]] [cikis_noktasi_sutunlari[tur-1]] = piyon_degerleri [tur-1] [hamle-1];
                        oyun_tahtasi[piyonlarin_yerleri[hamle-1][0]] [piyonlarin_yerleri[hamle-1][1]] = cikis_noktasi_degerleri[tur-1];
                        bakilacak_sayi = oyun_tahtasi[i][j];
                        broke = 0;
                        for (i = 0; i < 4 && !broke; i++)
                        {
                            for (j = 0; j < 4 && !broke; j++)
                            {
                                if (bakilacak_sayi == piyon_degerleri[i][j])
                                {
                                    piyonun_turlama_sayisi[i*4+j] = 0;
                                    broke = 1;        
                                }
                            }
                        }
                    }
                }
            }
        }
        
        //yolda
        else
        {   
            bakilacak_sayi = oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]][kalelerin_sutunlari[(tur-1)*4+hamle-1]] + zar;      
            if (bakilacak_sayi>532)
                bakilacak_sayi -= 32;
            //gidecegi yer dolu mu?
            //evine girme alanina gelmis mi?
            fark = bakilacak_sayi-502-(tur-1)*8;
            i = oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]] [kalelerin_sutunlari[(tur-1)*4+hamle-1]];
            if (  piyonun_turlama_sayisi[(tur-1)*4+hamle-1]>0 && fark <= 6 && fark > 0 && ( oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]] [kalelerin_sutunlari[(tur-1)*4+hamle-1]] <= 502+(tur-1)*8 || i == 532 || i == 531 || i == 530 || i == 529) )
            {
                //girecek mi?
                if ( fark <= 3 && oyun_tahtasi[bitti_koordinatlari[tur-1][(fark)*2]] [bitti_koordinatlari[tur-1][(fark)*2+1]] == tur*100+4+fark)
                {
                    //piyonun oynamamis yerine yolun degerini geri atamak
                    oyun_tahtasi[piyonlarin_yerleri[hamle-1][0]] [piyonlarin_yerleri[hamle-1][1]] = oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]][kalelerin_sutunlari[(tur-1)*4+hamle-1]];
                    //kaleye evin sayisini vermek
                    oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]] [kalelerin_sutunlari[(tur-1)*4+hamle-1]] = (tur*100+4)+(fark);
                    //piyonu yerine yerlestirmek
                    oyun_tahtasi[bitti_koordinatlari[tur-1][(fark)*2]] [bitti_koordinatlari[tur-1][(fark)*2+1]] = piyon_degerleri[tur-1][hamle-1];
                }
            }
            //ilerleme
            else
            {
                if (piyonun_turlama_sayisi[(tur-1)*4+hamle-1] == 0 && zar != 1)
                    piyonun_turlama_sayisi[(tur-1)*4+hamle-1]++;
                broke = 0,flag = 0,i = 0;
                while(i < 9 && !broke)
                {
                    j = 0;
                    while(j < 9 && !broke)
                    {
                        if (bakilacak_sayi == oyun_tahtasi[i][j])
                        {
                            a = 0;
                            while (a < 16 && !broke)
                            {
                                if (i == kalelerin_satirlari[a] && j == kalelerin_sutunlari[a])
                                {
                                    //kimin piyonunu kiracak ve kacinci
                                    k = 0;
                                    a++;
                                    while(a>0)
                                    {
                                        a -= 4;
                                        k++;
                                    }
                                    a += 4;
                                    //k --> kimin oldugu (tur)
                                    //a --> kacinci oldugu (hamle)
                                    piyonun_turlama_sayisi[(k-1)*4+a-1] = 0;
                                    //oyuncunun piyonunun ilk yerine yolun degerini atama
                                    oyun_tahtasi[piyonlarin_yerleri[hamle-1][0]] [piyonlarin_yerleri[hamle-1][1]] = oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]][kalelerin_sutunlari[(tur-1)*4+hamle-1]];
                                    //oyuncunun tasinin kalesine bakilacak sayiyi atama
                                    oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]][kalelerin_sutunlari[(tur-1)*4+hamle-1]] = bakilacak_sayi;
                                    //tasi kirma
                                    bakilacak_sayi = k*100+a;
                                    i=0;j=9;
                                    while (j == 9 && i < 9)
                                    {
                                        j=0;
                                        while (oyun_tahtasi[i][j] != bakilacak_sayi && j < 9)
                                            j++;
                                        i++;
                                    }
                                    i--;
                                    oyun_tahtasi[i][j] = piyon_degerleri[tur-1][hamle-1];
                                    //kiralani kalesine gonderme
                                    oyun_tahtasi[kalelerin_satirlari[(k-1)*4+a-1]][kalelerin_sutunlari[(k-1)*4+a-1]] = piyon_degerleri[k-1][a-1];
                                    flag = 1;
                                    broke = 1;
                                }
                                a++;
                            }
                            broke = 1;
                        }
                        j++;
                    }
                    i++;
                }
                //siradan ilerleme
                if (flag == 0)
                {
                    i--;j--;
                    temp = oyun_tahtasi[i][j];
                    oyun_tahtasi[i][j] = oyun_tahtasi[piyonlarin_yerleri[hamle-1][0]][piyonlarin_yerleri[hamle-1][1]];
                    oyun_tahtasi[piyonlarin_yerleri[hamle-1][0]][piyonlarin_yerleri[hamle-1][1]] = oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]][kalelerin_sutunlari[(tur-1)*4+hamle-1]];
                    oyun_tahtasi[kalelerin_satirlari[(tur-1)*4+hamle-1]][kalelerin_sutunlari[(tur-1)*4+hamle-1]] = temp;
                }
            }
        }

        //bitti mi?
        for (i = 0; i < 7; i+=2)
        {
            for (j = 1; j < 5; j++)
            {
                if (oyun_tahtasi[bitti_koordinatlari[tur-1][i]] [bitti_koordinatlari[tur-1][i+1]] == (tur*100+j))
                    bitti++;
            }
        }
        if (bitti == 4)
        {
            //output
            printf("\t\t\t______________________________________________\n");
            for (i = 0; i < 9; i++)
            {
                printf("\t\t\t|");
                for (j = 0; j < 9; j++)
                {
                    x = i;y = j;
                    koordinat = x+y/10;
                    bakilacak_sayi = oyun_tahtasi[i][j];
                    yazdir(koordinat,bakilacak_sayi);
                }
                printf("\n\t\t\t---------------------------------------------\n");
            }
            printf("Oyunun kazanani %s ta kendisi. Tebrikler!!!!\n",sira[tur-1]);
            bitti = 1;
        }
        else
            bitti = 0;
        
        /*
        //sayi matrisini gormek icin
        for (i = 0; i < 9; i++)
        {
            printf("\t\t\t|");
            for (j = 0; j < 9; j++)
            {
                printf("%d |",oyun_tahtasi[i][j]);
            }
            printf("\n\t\t\t---------------------------------------------\n");
        }
        */
    }
    return 0;
}

char* yazdir(float koordinatF,int yazilacak)
{
    //unicode uyarli bir platform ise emojili bastirmak icin kontrol
    //linux genelde unicode a sahip ve anladigim kadariyla UNICODE define kontrolu windowsta gecerli
    //o yuzden boyle kullandim oteki isletim sistemleri hakkinda bilmiyorum
    #if defined (linux) || defined (UNICODE)
    //#if 0
    //kalede piyon disinda birsey varsa gostermemek icin
    if ( (koordinatF == 0.0f || koordinatF == 0.1f || koordinatF == 1.0f || koordinatF == 1.1f) && yazilacak > 500 )
            printf(" 🟦 |");
    else if ( (koordinatF == 0.7f || koordinatF == 0.8f || koordinatF == 1.7f || koordinatF == 1.8f) && yazilacak > 500 )
            printf(" 🟩 |");
    else if ( (koordinatF == 7.0f || koordinatF == 7.1f || koordinatF == 8.0f || koordinatF == 8.1f) && yazilacak > 500 )
            printf(" 🟨 |");
    else if ( (koordinatF == 7.7f || koordinatF == 7.8f || koordinatF == 8.7f || koordinatF == 8.8f) && yazilacak > 500 )
            printf(" 🟥 |");
    else
    {
        switch (yazilacak)
        {
        case 999:
            printf(" 🔲 |");break;
        case 501:case 509:case 517: case 525:
            printf(" 🔘 |");break;
        case 502 ... 508:case 510 ... 516: case 518 ... 524: case 526 ... 532: 
            printf(" 🔶 |");break;
        case 105 ... 107:
            printf(" 🟡 |");break;
        case 205 ... 207:
            printf(" 🔴 |");break;
        case 305 ... 307:
            printf(" 🟢 |");break;
        case 405 ... 407:
            printf(" 🔵 |");break;

        case 101:
            printf(" 🟡1|");break;
        case 102:
            printf(" 🟡2|");break;
        case 103:
            printf(" 🟡3|");break;
        case 104:
            printf(" 🟡4|");break;

        case 201:
            printf(" 🔴1|");break;
        case 202:
            printf(" 🔴2|");break;
        case 203:
            printf(" 🔴3|");break;
        case 204:
            printf(" 🔴4|");break;

        case 301:
            printf(" 🟢1|");break;
        case 302:
            printf(" 🟢2|");break;
        case 303:
            printf(" 🟢3|");break;
        case 304:
            printf(" 🟢4|");break;

        case 401:
            printf(" 🔵1|");break;
        case 402:
            printf(" 🔵2|");break;
        case 403:
            printf(" 🔵3|");break;
        case 404:
            printf(" 🔵4|");break;
        }
    } 

	#else

	//kalede piyon disinda birsey varsa gostermemek icin
    if ( (koordinatF == 0.0f || koordinatF == 0.1f || koordinatF == 1.0f || koordinatF == 1.1f) && yazilacak > 500 )
            printf(" M  |");
    else if ( (koordinatF == 0.7f || koordinatF == 0.8f || koordinatF == 1.7f || koordinatF == 1.8f) && yazilacak > 500 )
            printf(" Y  |");
    else if ( (koordinatF == 7.0f || koordinatF == 7.1f || koordinatF == 8.0f || koordinatF == 8.1f) && yazilacak > 500 )
            printf(" S  |");
    else if ( (koordinatF == 7.7f || koordinatF == 7.8f || koordinatF == 8.7f || koordinatF == 8.8f) && yazilacak > 500 )
            printf(" K  |");
    else
    {
        switch (yazilacak)
        {
        case 999:
            printf("    |");break;
        case 501:case 509:case 517: case 525:
            printf(" CN |");break;
        case 502 ... 508:case 510 ... 516: case 518 ... 524: case 526 ... 532: 
            printf(" +  |");break;
        case 105 ... 107:
            printf(" SK |");break;
        case 205 ... 207:
            printf(" KK |");break;
        case 305 ... 307:
            printf(" YK |");break;
        case 405 ... 407:
            printf(" MK |");break;

        case 101:
            printf(" S1 |");break;
        case 102:
            printf(" S2 |");break;
        case 103:
            printf(" S3 |");break;
        case 104:
            printf(" S4 |");break;

        case 201:
            printf(" K1 |");break;
        case 202:
            printf(" K2 |");break;
        case 203:
            printf(" K3 |");break;
        case 204:
            printf(" K4 |");break;

        case 301:
            printf(" Y1 |");break;
        case 302:
            printf(" Y2 |");break;
        case 303:
            printf(" Y3 |");break;
        case 304:
            printf(" Y4 |");break;

        case 401:
            printf(" M1 |");break;
        case 402:
            printf(" M2 |");break;
        case 403:
            printf(" M3 |");break;
        case 404:
            printf(" M4 |");break;
        }
    }  

    #endif
}
