#include <stdio.h>


void selection_sort(float* dizi, int size)
{
    int i, j, min_id;
    float temp;

    for (i = 0; i < size-1; i++)
    {
        min_id = i;
        for (j = i+1; j < size; j++)
          if (dizi[j] < dizi[min_id])
            min_id = j;

        temp = dizi[min_id];
        dizi[min_id] = dizi[i];
        dizi[i] = temp;
    }
}


int main()
{
    float boylar[30];
    int i;
    printf("30 Ogrencinin boyunu giriniz.\n");
    for ( i = 0; i < 30; i++)
    {
        scanf("%f", &boylar[i]);
    }

    selection_sort(boylar, 30);

    printf("En uzun boy : %.2f\n", boylar[29]);
    printf("En kisa 5 boy : %.2f , %.2f , %.2f , %.2f , %.2f\n", boylar[0], boylar[1], boylar[2], boylar[3], boylar[4]);

    return 0;
}
/*
52
60
101
45
57
67
13
84
63
102
52
22
12
42
74
62
35
82
62
102
52
21
100
44
78
67
36
83
61
102

*/