#include <Windows.h>
#include <vector>
#include <iostream>
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 


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
	char sLine[128] = "G011001201749000198416;ADD;0752;广东-DR;072009;3;;201300000;201700000000;2017002349";//假设这是待处理的一行，我们要按照分号进行拆分
	char* const sDelim = ";";
	std::vector<char *> vResult;
	vSplitLine(sLine, sDelim, vResult);
	
	std::vector<char *>::iterator pos;

	for (pos = vResult.begin(); pos != vResult.end(); pos++)
	{
		std::cout << *pos << std::endl;
	}

	system("pause");
	return 0;
}
