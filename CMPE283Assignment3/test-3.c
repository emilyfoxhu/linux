#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

static inline void
__cpuid(unsigned int *eax, unsigned int *ebx, unsigned int *ecx, unsigned int *edx)
{
asm volatile("cpuid"
: "=a" (*eax),
"=b" (*ebx),
"=c" (*ecx),
"=d" (*edx)
: "0" (*eax), "1" (*ebx), "2" (*ecx), "3" (*edx));
}

int main(int argc, char *argv[])
{
unsigned int eax, ebx, ecx, edx;

eax=atoi(argv[1]);
__cpuid(&eax, &ebx, &ecx, &edx);
printf("CPUID(0x4FFFFFFE), exit number:%d, exits=%d\n",atoi(argv[1]), (eax));
}
