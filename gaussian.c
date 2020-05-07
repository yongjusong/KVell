#include "headers.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned long gaussDistributeRand(unsigned long begin, unsigned long end, int detail) {
		unsigned long r = 0;
		for(int i = 0; i < detail; i++)
				r += (unsigned long)rand()%RAND_MAX;
		r /= (unsigned long)detail;

		//		return (r*(end-begin)+begin)%(unsigned long)1000000;
		return ((r*(end-begin)+begin)%(unsigned long)1000000);
}
/*
   unsigned long gaussDistributeUL(double begin, double end, int detail) {
   unsigned long r = 0;
   for(int i=0; i<detail; i++)
   r += (unsigned long)rand()/(unsigned long)100000000;
   r /= (unsigned long)detail;

   return r*(end-begin)+begin;
   }
   */
/* xorshf96 */
static unsigned long x=123456789, y=362436069, z=521288629;
unsigned long xorshf96(void) {          //period 2^96-1
		unsigned long t;
		x ^= x << 16;
		x ^= x >> 5;
		x ^= x << 1;

		t = x;
		x = y;
		y = z;
		z = t ^ x ^ y;

		return z%1000000;
}


void main() {
		int i;

		printf("gauss\n");
		for (i = 0; i < 10; i++)
				printf("%lu\n", (unsigned long)(gaussDistributeRand(0,1,100)));
		printf("xorshf\n");
		for (i = 0; i < 10; i++)
				printf("%lu\n", xorshf96());
}
