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

/********************************************************************
* Function name:        prepend_args
* Description:          摘自grep源码Main.c，函数名是预先考虑程序的参数，但实际上是一个分割单词的函数，单词划分的标准是空白字符
                        句子依‘\0’结尾，可以处理‘\\’反斜杠，例如'li\ xin'这种格式认为是一个单词。
* Input Param:          char const *options             待处理字符串
* Output Param:         char *buf                       保存处理结果，单词用'\0'分割
* InAndOut param:       char *argv                      保存分割的单词，如果为空不保存分割的单词                       
                                    
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

/* Find the white-space-separated options specified by OPTIONS, and
   using BUF to store copies of these options, set ARGV[0], ARGV[1],
   etc. to the option copies.  Return the number N of options found.
   Do not set ARGV[N] to NULL.  If ARGV is NULL, do not store ARGV[0]
   etc.  Backslash can be used to escape whitespace (and backslashes).  */
static int
prepend_args (char const *options, char *buf, char **argv)
{//找空白分割的选项，返回选项个数
  char const *o = options;
  char *b = buf;
  int n = 0;

  for (;;)
    {
      while (c_isspace ((unsigned char) *o))//gnulib c-ctype.h 判断是否是空白字符
        o++;                                //遇到不是空白就停止，这样的处理主要是为了处理多个空白连续输入的情况
      if (!*o)//到达行尾则返回单词个数
        return n;
      if (argv)//如果非空，argv[0] 保存第一个单词，arg[1]保存第二个单词... 如果为空if失败
        argv[n] = b;
      n++;//遇到一个非空白字符就认为是单词，单词数加一个

      do
        if ((*b++ = *o++) == '\\' && *o)//
          b[-1] = *o++;
      while (*o && ! c_isspace ((unsigned char) *o));//非空白且非结尾（就是非‘\0’）

      *b++ = '\0';//buf中的单词依‘\0’分割
    }
}
