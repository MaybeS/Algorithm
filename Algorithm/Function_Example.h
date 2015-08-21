#pragma once

void swap(int * val1, int *val2)
{
	if (*val1 - *val2)
		*val1 ^= *val2 ^= *val1 ^= *val2;
}