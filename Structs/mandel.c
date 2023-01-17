#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define VERBOSE 0
#define HIGHRES 1

#define WIDTH  80
#define HEIGHT (int)(WIDTH * 0.30)
#define WLIM -2
#define OLIM 1
#define NLIM 1
#define SLIM -1
#define ITER 100

struct complex
{
	double re;
	double im;
};

struct complex* crcomp(double re, double im)
{
	struct complex *erg = (struct complex*)malloc(sizeof(*erg));
	erg->re = re;
	erg->im = im;
	return erg;
}

struct complex* mult(struct complex *a, struct complex *b)
{
	struct complex *erg = (struct complex*)malloc(sizeof(*erg));
	erg->re = a->re * b->re - a->im * b->im;
	erg->im = a->re * b->im + a->im * b->re;
	return erg;
}

struct complex* add(struct complex *a, struct complex *b)
{
	struct complex *erg = (struct complex*)malloc(sizeof(*erg));
	erg->re = a->re + b->re;
	erg->im = a->im + b->im;
	return erg;
}

double c_abs(struct complex *a)
{
	return sqrt(a->re * a->re + a->im * a->im);
}


int mandel(struct complex *c)
{
#if VERBOSE
	printf("mandel\n");
#endif
	struct complex *delsave;
	struct complex* z = crcomp(0,0);
	for(int i = 1; i <= ITER; i++)
	{
		delsave = z;
		z = mult(z,z);
#if VERBOSE
		printf("\nZ^2 = %lf + i%lf",z->re,z->im);
#endif
		free(delsave);
		delsave = z;
		z = add(z,c);
#if VERBOSE
		printf("\nZ+C = %lf + i%lf",z->re,z->im);
#endif
		free(delsave);
		if(c_abs(z) > 2)
		{
			return i;
		}
	}
	return 0;
}

int main()
{
/*
	N

W		O

	S
*/

int fraktal[WIDTH][HEIGHT];

double dx = ((double)OLIM - (double)WLIM) / (double)WIDTH;
double dy = ((double)NLIM - (double)SLIM) / (double)(HEIGHT);


struct complex *coord = crcomp(0, 0);

for(int y = 0; y<HEIGHT; y++)
{
	coord->im = NLIM - y * dy;
	for(int x = 0; x<WIDTH; x++)
	{
		coord->re = WLIM + x * dx;
		#if VERBOSE
		printf("Coord: %lf + i%lf\n",coord->re,coord->im);
		#endif
		fraktal[x][y] = mandel(coord);
	}

}
#if HIGHRES
char bright[] = " $@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";
#else
char bright[] = " .:-=+*#%@";
#endif
for(int y = 0; y<HEIGHT; y++)
{
	printf("\n");
	for(int x = 0; x<WIDTH; x++)
	{
		#if HIGHRES
		printf("%c",bright[(fraktal[x][y] * 70) / ITER]);
		#else
		printf("%c",bright[(fraktal[x][y] * 10) / ITER]);
		#endif
	}
}

#if VERBOSE
printf("dx:%lf dy:%lf\n",dx,dy);
#endif

/*
struct complex *tst = crcomp(0,0);

int m = 0;

printf("\n Enter re and im.\n");
scanf("%lf%lf",&(tst->re),&(tst->im));
m = mandel(tst);
printf("\nIterations for %lf + i%lf = %d\n",tst->re, tst->im, m);

free(tst);

*/
printf("\n");
return 0;
}
