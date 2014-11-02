#include <stdio.h>

int main()
{
    double s, t, d, base, irpf;

    scanf("%lf %lf",&s,&d);

    t = s;

    if(s <= 1317.07) s *= (100-8)/100.0;
    else if(s <= 2195.12)s *= (100-9)/100.0;
    else if(s <= 4390.24)s *= (100-11)/100.0;
    else s -= 482.93;

    printf("INSS: R$ %.2f\n",t-s);

    s -=  (179.71)*d;

    base = s;

    printf("Base: R$ %.2f\n",base);

    irpf = 0;

    if (s >= 4463.82)
    {
        s -= 4463.82;
        irpf += s*0.275;
        s = 4463.81;
    }

    if(s <= 4463.82 && s >= 3572.44)
    {
        s -= 3572.44;
        irpf += s*0.225;
        s = 3572.43;
    }

    if(s <= 3572.44 && s >= 2679.30)
    {
        s -= 2679.30;
        irpf += s*0.15;
        s = 2679.29;
    }

    if(s <= 2679.30 && s >= 1787.78)
    {
        s -= 1787.78;
        irpf += s*0.075;
        s = 1787.77;
    }

    printf("IRPF: R$ %.2f\n",irpf);

    return 0;
}
