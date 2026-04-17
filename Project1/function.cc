// Copyright 2026 kkilborn lleita
#include<cmath>
#include<cstdlib>
#include"function.h"
// Random Number Function
int RandomNumber(int x, int y) {
  int small = (x < y ? x : y);
  int big = (x > y ? x : y);
  return rand() % ( big - small + 1 ) + small;
}
// Math function
int math(char op, int one, int two) {
  int beg;
  switch (op) {
    case '+':
      beg = one + two;
      break;
    case '*':
      beg = one * two;
      break;
    case '-':
      beg = one - two;
      break;
    case '%':
      beg = one % two;
      break;
    case '^':
      beg = static_cast<int>(pow(one, two));
      break;
    case '/':
      beg = one / two;
      break;
    default:
      return 0;
  }
  return beg;
}
