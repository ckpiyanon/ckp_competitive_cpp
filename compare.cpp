#include <cstdio>
#include <cstring>

int main()
{
	char f1[] = "out.txt",f2[] = "test.txt";
	char s1[100000],s2[100000];
	FILE* file1 = fopen(f1,"r");
	FILE* file2 = fopen(f2,"r");
	while(!feof(file1) && !feof(file2))
	{
		fscanf(file1,"%s",s1);
		fscanf(file2,"%s",s2);
		if(strcmp(s1,s2))
		{
			printf("Wrong Answer\n");
			return 0;
		}
	}
	if(feof(file1) == feof(file2))	printf("Accepted\n");
	else printf("Wrong Answer\n");

	return 0;
}
