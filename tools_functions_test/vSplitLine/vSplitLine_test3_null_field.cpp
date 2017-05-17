#include <Windows.h>
#include <vector>
#include <iostream>
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 

void vPerFieldAddSpace(char * sResultLine, const char * sLine)
{
	int i = 0;
	int j = 0;
	while (sLine[i] != '\0')
	{
		if (';' == sLine[i])
		{
			sResultLine[j] = ' ';
			j++;
		}
		sResultLine[j] = sLine[i];
		i++;
		j++;
	}
	sResultLine[j] = ' ';//最后一个字段也加上空格
}

void vSplitLine(char * const sLine, const char* const sDelim, std::vector<char *> &vResult)
{
	char * sTmp;
	char *sNext;             

	sTmp = strtok_s(sLine, sDelim, &sNext);//这里把strtok_r（linux下）改成了strtok_s（windows下）因为
	vResult.push_back(sTmp);

	while ((sTmp = strtok_s(NULL, sDelim, &sNext)) != NULL)
	{
		vResult.push_back(sTmp);
	}
}

int main()
{
	char sLine[128] = "G011001201749000198416;ADD;0752;广东-DR;072009;3;;201300000;201700000000;2017002349";//有空字段
	char sResultLine[128] = {};
	vPerFieldAddSpace(sResultLine, sLine);//给每个字段（包括最后一个字段）加一个空格
	
	char* const sDelim = ";";
	std::vector<char *> vResult;
	vSplitLine(sResultLine, sDelim, vResult);
	
	std::vector<char *>::iterator pos;

	for (pos = vResult.begin(); pos != vResult.end(); pos++)
	{
		std::cout << *pos << std::endl;
	}

	system("pause");
	return 0;
}
