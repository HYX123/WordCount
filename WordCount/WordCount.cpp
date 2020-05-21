#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char *argv[])
{
	//读取文件
	FILE *file = fopen(argv[2], "r");
	if (!file) {
		printf("文件读取失败");
		return -1;
	}

	//计算字符数
	if (!strcmp(argv[1], "-c")) {		//空格，水平制表符，换行符均算字符
		char temp;
		int num = 0;
		temp = fgetc(file);
		while (temp != EOF) {
			temp = fgetc(file);
			num++;
		}
		printf("字符数：%d\n", num);
	}

	//计算单词数
	else if (!strcmp(argv[1], "-w")) {
		int num1 = 1;
		char temp1 = fgetc(file);
		while (temp1 != EOF) {           
			if (temp1 == ' ' || temp1 == ',') {					//由空格或逗号分割开的都视为单词
				while (temp1 == ' ' || temp1 == ',') {
					temp1 = fgetc(file);
				}
				num1++;
				temp1 = fgetc(file);

			}
			else
				temp1 = fgetc(file);

		}
		printf("单词数：%d\n", num1);
	}
	return 0;
}