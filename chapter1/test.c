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