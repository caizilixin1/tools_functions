/********************************************************************
* Function name:        vSplitLine
* Description:          将一行拆分成不同字段,主要应用场景：将一行按需求拆分出各个字段，然后放入结构体，以方便后续处理
* Input Param:          const char* const sDelim        分割字符或字符串，例如：“;”或者"; *”（分号、空格、星号）
* Output Param:         vector<char *> &result          保存被分割的各个字段的首地址
* InAndOut Param:       char * const sLine              待处理字符串，处理过程中会修改源字符串                      
                                    
* Return Value:
* Note:                 sLine是自己定义的局部字符串或堆上的字符串，不能是常量字符串
*                       可处理任意多个字段的行
*                       该函数对空字段不能处理，可先做预处理再使用该函数（比如在每个字段后加空格）
* Modification Log:
*----------------------------------------------------------------
*    DATE       AUTHOR           DESCRIPTION
* ---------------------------------------------------------------
*  2017/04/22   lixin            Initial Release
********************************************************************/
void vSplitLine(char * const sLine, const char* const sDelim,  vector<char *> &vResult)
{
        char * sTmp;
        char *sNext;

        sTmp = strtok_r(sLine, sDelim, &sNext);
        vResult.push_back(sTmp);

        while ((sTmp = strtok_r(NULL, sDelim, &sNext)) != NULL)
        {
                vResult.push_back(sTmp);
        }
}
