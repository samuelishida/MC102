#include <stdio.h>

double raiz(double a)
{
    double b1=0, b2=a, r, erro = 0.001;

    r = (b1+b2)/2;

    while(r*r <= a - erro || r*r >= a + erro)
    {
        if(r*r > a)
            b2 = (b1+b2)/2;
        else
            b1 = (b1+b2)/2;

        r = (b1+b2)/2;
    }

    return r;
}

int main()
{
    double p1,p2,p3,l,p,ma,mh,mg;

    scanf("%lf %lf %lf %lf",&p1,&p2,&p3,&l);

    p = (3*p1+3*p2+4*p3)/10;

    ma = (p+l)/2;

    mh = (2*p*l)/(p+l);

    mg = raiz(p*l);

    printf("Media aritmetica: %.1lf\n", ma);
    printf("Media harmonica: %.1lf\n", mh);
    printf("Media geometrica: %.1lf\n", mg);

    return 0;
}
