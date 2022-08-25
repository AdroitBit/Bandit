#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

char *strrev(char *str){
    char *p1, *p2;
    if (! str || ! *str)return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

void reverse(char *string, int begin, int end) {
  char tmp;

  if (begin >= end)
    return;

  tmp = string[begin];
  string[begin] = string[end];
  string[end] = tmp;

  reverse(string, ++begin, --end);
}

int main(void) {
  char a[MAX_SIZE], b[MAX_SIZE];
  char result[MAX_SIZE] = {'\0'};
  scanf("%s %s", a, b);

  int len_a = strlen(a);
  int len_b = strlen(b);
  int len_max = len_a > len_b ? len_a : len_b;

  int i, j, sum, carry = 0;

  strrev(a);
  strrev(b);

  for (i = 0; i < len_max; i++) {
    if (len_a == len_b || (i < len_a && i < len_b)) {
      sum = carry + (a[i] - '0') + (b[i] - '0');
    } else if (i >= len_a) {
      sum = carry + (b[i] - '0');
    } else if (i >= len_b) {
      sum = carry + (a[i] - '0');
    }
    result[i] = sum % 10;
    carry = sum / 10;
  }

  if (carry) {
    result[i] = carry;
    i++;
  }

  for (j = 0; j < i; j++) {
    printf("%d", result[i - j - 1]);
  }
  printf("\n");
  return 0;
}