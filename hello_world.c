/* hello_world.c */
#include "hello_world.h"

int main(void)
{
	if (hello() ||
		howisitgoing() ||
		cpu_model() ||
		cpu_freq() ||
		goodbye())
		return 1;
	return 0;
}
