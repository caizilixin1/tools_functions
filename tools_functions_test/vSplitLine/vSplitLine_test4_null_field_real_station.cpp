#include <Windows.h>
#include <vector>
#include <iostream>
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 

struct resSomeStruct
{
	char sFieldOne[100 + 1]; //为了简单起见每个字段都赋值100，后面的1是用来放'\0'的
	char sFieldTwo[100 + 1];//如果你的第一个字段长度为15，那么最好写成char sFieldOne[15 + 1]
	char sFieldThree[100 + 1];
	char sFieldFour[100 + 1];
	char sFieldFive[100 + 1];
	char sFieldSix[100 + 1];
	char sFieldSeven[100 + 1];
	char sFieldEight[100 + 1];
	char sFieldNine[100 + 1];
	char sFieldTen[100 + 1];
};

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


	resSomeStruct pSomeStruct;
	memset(&pSomeStruct, '\0', sizeof(pSomeStruct));//这一句最好加上，避免以后处理的时候麻烦，其实不写是可以的

	strncpy_s(pSomeStruct.sFieldOne,		101,		vResult[0],		strlen(vResult[0]) - 1);//之所以减去1是因为，要去掉加的空格呀
	strncpy_s(pSomeStruct.sFieldTwo,		101,		vResult[1],		strlen(vResult[1]) - 1);
	strncpy_s(pSomeStruct.sFieldThree,	101,		vResult[2],		strlen(vResult[2]) - 1);
	strncpy_s(pSomeStruct.sFieldFour,		101,		vResult[3],		strlen(vResult[3]) - 1);
	strncpy_s(pSomeStruct.sFieldFive,		101,		vResult[4],		strlen(vResult[4]) - 1);
	strncpy_s(pSomeStruct.sFieldSix,		101,		vResult[5],		strlen(vResult[5]) - 1);
	strncpy_s(pSomeStruct.sFieldSeven,	101,		vResult[6],		strlen(vResult[6]) - 1);
	strncpy_s(pSomeStruct.sFieldEight,	101,		vResult[7],		strlen(vResult[7]) - 1);
	strncpy_s(pSomeStruct.sFieldNine,		101,		vResult[8],		strlen(vResult[8]) - 1);
	strncpy_s(pSomeStruct.sFieldTen,		101,		vResult[9],		strlen(vResult[9]) - 1);

	std::cout << pSomeStruct.sFieldOne		<< "----------" << std::endl;//加--------为了看看打印是否有多余空格
	std::cout << pSomeStruct.sFieldTwo		<< "----------" << std::endl;
	std::cout << pSomeStruct.sFieldThree	<< "----------" << std::endl;
	std::cout << pSomeStruct.sFieldFour		<< "----------" << std::endl;
	std::cout << pSomeStruct.sFieldFive		<< "----------" << std::endl;
	std::cout << pSomeStruct.sFieldSix		<< "----------" << std::endl;
	std::cout << pSomeStruct.sFieldSeven	<< "----------" << std::endl;
	std::cout << pSomeStruct.sFieldEight		<< "----------" << std::endl;
	std::cout << pSomeStruct.sFieldNine		<< "----------" << std::endl;
	std::cout << pSomeStruct.sFieldTen		<< "----------" << std::endl;

	system("pause");
	return 0;
}
