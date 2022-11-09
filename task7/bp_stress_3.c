#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RDRAND
#define LCG_A   1103515245
#define LCG_C   22345
#define LCG_M   2147483648
#define ULL64   volatile unsigned long long

ULL64 generated;

ULL64 rand_lcg(ULL64 seed)
{
    return rand();
}

ULL64 rand_rec1()
{
    generated = rand_lcg(generated) % 1024;

    if (generated < 512)
        return generated;
    else return rand_rec1();
}

ULL64 rand_rec2()
{
    generated = rand_lcg(generated) % 1024;

    if (!(generated >= 512))
        return generated;
    else return rand_rec2();
}

#define BROP(num, sum)                  \
    num = rand_lcg(generated);          \
    if (num % 2)                        \
        sum += rand_rec1();             \
    else                                \
        sum -= rand_rec2();

#define BROP5(num, sum)     BROP(num, sum) BROP(num, sum) BROP(num, sum) BROP(num, sum) BROP(num, sum)
#define BROP25(num, sum)    BROP5(num, sum) BROP5(num, sum) BROP5(num, sum) BROP5(num, sum) BROP5(num, sum)
#define BROP100(num, sum)   BROP25(num, sum) BROP25(num, sum) BROP25(num, sum) BROP25(num, sum)

int main()
{
    int i = 0;
    int iterations = 500000;    
    ULL64 num = 0;
    ULL64 sum = 0;

    generated = rand_lcg(0) % 54321;

    for (i = 0; i < iterations; i++)
    {
        //1
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);


                BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);

        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);

        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);

        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);

        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);

        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);

        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);

        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);

        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        //2
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //3
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //4
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //5
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //6
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //7
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //8
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //9
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
       //10
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);
        BROP100(num, sum);

        // ... repeat the line above 10 times
    }

    printf("Sum = %llu\n", sum);
}