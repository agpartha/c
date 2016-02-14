
#include <stdio.h>

int bsearch (int data[], int size, int val)
{
	static int recurs = 0;
	int s, m, e;

	s = 0;
	e = s + size - 1;
	m = (s + e) / 2 ;

	printf ("recurs(%d): start %d mid %d end %d, val %d\n", recurs, s, m, e, val);

	// check and return if we have the match
	if (data[m] == val) {
		recurs--;
		return m;
	}

	// if we are the single element, 
	if (s == e) {
		recurs--;
		return -1;
	}

	// If data is less than mod, go search from left section
	// Cannot add if the index was negative still.
	if (val < data[m]) {
		int r;

		recurs++;
		r =  bsearch(&data[s], (m - s), val);
		if (r >= 0)
			return s + r;
	}  

	// data must be greater than mid value and so look in the right side.
	if (val > data[m]) {
		int r;

		recurs++;
		r =  bsearch(&data[m + 1], (e - m), val);
		if (r >= 0)
			return m + 1 + r;
	}  

	return -1;
}


void main (void)
{
	int data[] = { 10, 20, 30, 400, 533, 789, 1000, 2000, 2011};
	int i, val, size = sizeof(data)/sizeof(data[0]);
	
	i = 0;
	while (i < size) {
		printf("Data[%2d] : %3d\n", i, data[i]);
		i++;
	}

	printf("\n\nPlease Enter the number to search in the above data ? \n");
	scanf("%d", &val);

	printf("\n\nSearching %d ....\n\n", val);

	i = bsearch(data, size, val);

	if (i < 0)
		printf("\n\nCould not find %d ....\n\n", val);
	else 
		printf("\n\nFound %d at position %d\n\n", val, i);
}