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

