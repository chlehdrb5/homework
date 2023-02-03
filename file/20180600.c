#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[]) {
	int linecount = 0, wordcount = 0, charcount = 0;
	int input = 0;
	FILE *fp1;
	FILE *fp2;
	char newfilename[30];

	if (argc != 2) {
		printf("���� : ���α׷��� �����̸��� �Է��Ͻÿ�.\n");
		exit(1);
	}
	if (fopen_s(&fp1, argv[1], "r") != 0) {
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}

	strncpy_s(newfilename, 30, argv[1], 30);
	char *ptr = strrchr(newfilename, '.');
	strncpy_s(ptr + 1, 5, "rev", 5); //Ȯ���� .rev�� �ٲٱ�
	if (fopen_s(&fp2, newfilename, "w") != 0) {
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}

	while (feof(fp1) == 0) {
		input = fgetc(fp1);
		//fputc(input, stdout); // ������ �������� Ȯ��
		if (input != ' '&&input != '\n') 
			charcount++;
		if (input == ' ' || input == '\n') 
			wordcount++;
		if (input == '\n') 
			linecount++;
		if (isalpha(input)) {
			if (islower(input))
				input = toupper(input);
			else if (isupper(input))
				input = tolower(input);
		}
		fputc(input, fp2);
	}
	printf("<Count Result>\n");
	printf("\nLine Count :			%d  ", linecount);
	printf("\nWord Count :			%d  ", wordcount);
	printf("\nCharacter Count :		%d  \n", charcount);
	printf("File saved in %s\n", newfilename);

	fclose(fp1);
	fclose(fp2);

	return 0;
}