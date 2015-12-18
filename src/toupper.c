#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i, n;
    char* upper;
    if (argc != 2)
	{
	    return -1;
	}
	n = strlen(argv[1]);
	upper = (char*)malloc(n+1);
    for(i=0; i<n; ++i)
    {
	    upper[i] = toupper(argv[1][i]);
	}
	upper[n] = '\0';
	printf("%s", upper);
    return 0;
}