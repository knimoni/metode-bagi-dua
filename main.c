#include <stdio.h>
#include <stdlib.h>
#include <math.h>8
#define f(x) (x*x*x - 4*x*x + 5)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>8
#define f(x) (x*x*x - 2*x*x + 3)
int main()
{
 float a=0,b=0,error=0,e=0.01,c,cmold,sing;
 int i=0;
 printf("Metode Bagi Dua untuk mencari akar persamaan x^3 - 2x^2 + 3 = 0\n");
 printf("Masukkan interval untuk akar: ");
 scanf("%f %f",&a,&b);
 if((f(a)*f(b))>0){
 printf("Interval tidak valid!"); //Untuk menguji pengecekan interval
 exit(1); //ini benar atau tidak
 }
 else if(f(a)==0 || f(b)==0){
 printf("Akar tersebut merupakan salah satu batas interval, yaitu: %f\n",f(a)==0?a:b);
 exit(0);
 }
 printf("Ite\ta\t\tb\t\tc\t\tf(c)\t\tGalat relatif\n");
 do{
 cmold=c;
 c=(a+b)/2;
 printf("%2d\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t",i++,a,b,c,f(c));
 if(f(c)==0){
 printf("Root is %4.6f\n",c);
 }
 else if ((f(a)*f(c))<0){
 b=c;
 }
 else a=c;
 error=fabs(c-cmold);
 if(i==1){
 printf("----\n");
 }
 else printf("%4.6f\n",error);
 }
 while(error>e);
 printf("Hampiran akarnya adalah %4.6f",c);
 //Singularitas
 printf("\nPengecekan Singularitas\n");
 sing=f(b)-f(a);
 if(sing<0){
 sing=sing*-1;
 }
 if (sing>1){

		printf("f(a)= %lf\n",a);
		printf("f(b)= %lf\n",b);
		printf("Divergen, (akar semu)\n");
	}
	else if (sing<1){
		printf("f(a)= %lf\n",a);
		printf("f(b)= %lf\n",b);
		printf("konvergen 0, (akar sejati)\n");
    }
    return 0;
}
