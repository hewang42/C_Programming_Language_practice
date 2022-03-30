// exercise 1-13 1-14
// 输出单词的水平和竖直直方图

#include<stdio.h>
#define MAXLENGTH 10 //单词最大长度
#define IN 1
#define OUT 0
#define MAXHIST 10 // 直方图最大计数量

int main() {
  int c;
  int state;
  int wordCount[MAXLENGTH];
  int count;
  int len;

  count = 0;
  state = OUT;
  len = MAXHIST;

  for (int i = 0; i < MAXLENGTH; i++) {
    wordCount[i] = 0;
  }

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        state = OUT;
        wordCount[count - 1]++;
        count = 0;
      }
      else {
        count = 0;
      }
    }
    else if (state == OUT) {
      state = IN;
      count ++;
    }
    else {
      count ++;
    }
  }

// 水平输出直方图
  for (int i = 0; i < MAXHIST; i++) {
    for (int i = 0; i < MAXLENGTH; i++) {
      if (len - wordCount[i] > 0) {
        printf("   ");
      }
      else {
        printf("*  ");
      }
    }
    len--;
    printf("\n");
  }

  for (int i = 0; i < MAXLENGTH; i++) {
    printf("%d  ", wordCount[i]);
  }
  printf("\n");
  for (int i = 0; i < MAXLENGTH; i++) {
    printf("%d  ", i+1);
  }
printf("\n");
printf("-----------------------------------\n");
// 竖直输出直方图
  for (int i = 0; i < MAXLENGTH; i++) {
    printf("%d %d  ", i + 1, wordCount[i]);
    if (wordCount[i] > 0) {
      for (int j = 0; j < wordCount[i]; j++) {
        printf("* ");
      }
    }
    printf("\n");
  }
}


// exercise 1-15
// 将 1.2 的温度转换改为函数调用
#include<stdio.h>
float temperatureTrans(float);

int main() {
    float fahr;
    float upper, lower,step;
    upper = 300;
    lower = 0;
    step = 20;
    fahr = 0;
    while(fahr <= upper) {
        printf("%3.0f\t%6.1f\n", fahr, temperatureTrans(fahr));
        fahr += step;
    }
}

float temperatureTrans(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}

// exercise 1-16
// 修改打印最长文本行的程序，使其可以打印任意长度的输入行的长度，并尽可能多地打印文本。

#include<stdio.h>
#define MAXLINE 1000

int getLine(char[], int);
void copy(char[], char[]);

int main() {
    int len; // 当前行长度
    int max; // 最大行长度
    char line[MAXLINE]; // 当前行内容
    char longest[MAXLINE]; // 最大行内容

    max = 0;

    while((len = getLine(line, MAXLINE)) > 0) {
        printf("长度为 %d, 内容为 %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getLine(char line[], int lim) {
    int i, c;
    
    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;    
}

void copy(char to[], char from[]) {
    int i = 0;

    while((to[i] = from[i]) != '\0')
        i++;
}

// exercise 1-17
// 编写一个程序，打印长度大于80个字符的所有输入行。
#include<stdio.h>
#define MAXLINE 1000
#define MAXINPUT 100 // 最多输入多少行
#define LENGTHOVER 80

int getLine(char[], int);
void copy(char[], char[]);

int main() {
    int len; // 当前行长度
    char line[MAXLINE]; // 当前行内容
    char lineOver80[MAXINPUT][MAXLINE]; // 存大于 80 的输入
    int inputOverCount80 = 0; // 大于 80 的行数量

    while((len = getLine(line, MAXLINE)) > 0 && inputOverCount80 < MAXINPUT) {       
            if (len > LENGTHOVER) {
                copy(lineOver80[inputOverCount80], line);
                inputOverCount80++;
            }
    }
    // 将lineOver80 没用完的空间填充成 '\0',方便判断不输出
    for(int i = inputOverCount80 + 1; i < MAXINPUT; i++) {
        lineOver80[i][0] = '\0';
    }

    printf("-----------------\n");
    for(int i = 0; i < MAXINPUT && lineOver80[i][0] != '\0'; i++) {
        printf("%s", lineOver80[i]);
    }
    return 0;
}

int getLine(char line[], int lim) {
    int i, c;
    
    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;    
}

void copy(char to[], char from[]) {
    int i = 0;

    while((to[i] = from[i]) != '\0')
        i++;
}