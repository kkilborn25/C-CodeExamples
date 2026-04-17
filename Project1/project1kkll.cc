// Copyright 2026 Lleita Kkilborn
// include standard libraries
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include "function.h"
using std::cout;
using std::cin;
using std::endl;

// main method
int main() {
  int rounds = 0;
  char again = 'y';
  while (again == 'y') {
    srand(time(0));
    cout << "Welcome to the mental arithmetic tester." << endl;
    int express;
    cout << "How many expressions would you like to evaluate?" << endl;
    cin >> express;
    int goalTime;
    cout << "Great! What's your goal time (in seconds)?" << endl;
    cin >> goalTime;
    // takes in start time
    time_t start = time(0);
    int count = 0;
    int right = 0;
    // makes the numbers random
    while (count < express) {
      int a = RandomNumber(0, 9);
      int b = RandomNumber(0, 9);
      int c = RandomNumber(0, 9);
      int opChoose = RandomNumber(0, 5);
      // cout << a << b << c << endl;
      char op;
      // randomizes operator number one
      switch (opChoose) {
        case 0: op = '+'; break;
        case 1: op = '*'; break;
        case 2: op = '/'; break;
        case 3: op = '-'; break;
        case 4: op = '%'; break;
        case 5: op = '^'; break;
      }
      // randomizes operator number two
      int opChoose2 = RandomNumber(0, 5);
      char op2;
      switch (opChoose2) {
        case 0: op2 = '+'; break;
        case 1: op2 = '*'; break;
        case 2: op2 = '/'; break;
        case 3: op2 = '-'; break;
        case 4: op2 = '%'; break;
        case 5: op2 = '^'; break;
      }
      int oplevel = 1;
      int oplevel2 = 1;
      // operator precidence
      if (op2 == '^') {
        oplevel2 = 3;
      }
      if (op2 == '/' || op2 == '*' || op2 == '%') {
        oplevel2 = 2;
      }
      if (op == '^')
        oplevel = 3;
      if (op == '/' || op == '*' || op == '%')
        oplevel = 2;
      if (op == '/') {
        b = RandomNumber(1, 9);
        a = b * RandomNumber(0, 9);
      }
      // ensures that division and mod equations don't produce incorrect results
      if (op == '%')
        b = RandomNumber(1, 9);
      if (op2 == '/') {
        c = RandomNumber(1, 9);
        int partOneTry;
        if (oplevel2 > oplevel) {
          partOneTry = b;
        } else {
          partOneTry = a;
        }
        if (partOneTry % c != 0) {
          continue;
        }
      }
      if (op2 == '%') {
        c = RandomNumber(1, 9);
        int partOneTry;
        if (oplevel2 > oplevel)
          partOneTry = b;
        else
          partOneTry = a;
        if (partOneTry < c)
          continue;
      }
      int partOne = 0;
      int num = 0;
      // follows PEMDAS rules to complete math
      if (oplevel2 > oplevel) {
        partOne = math(op2, b, c);
        if (op == '/' && partOne !=0 && a % partOne != 0)
          continue;
        // calls math function
        num = math(op, a, partOne);
      } else {
        partOne = math(op, a, b);
        if (op2 == '/' && c !=0 && partOne % c != 0)
          continue;
        num = math(op2, partOne, c);
      }
      // makes sure that the final result isn't too large
      if (num > 100 || num < -25) {
        // cout << "big num" << endl;
        continue;
      }
      int input;
      // writes the next equation and how many seconds it took to
      // solve the previous equation
      cout << "Expression " << count+1 << " (seconds passed "
           << time(0)-start << "):" << endl;
      cout << a << op << b << op2 << c << "=" << endl;
      cin >> input;
      // checks if the user's answer is correct or incorrect
      if (input == num)  {
        cout << "correct!" << endl;
        // counts the number of correct answers
        right += 1;
      } else {
        // cout << "Incorrect the answer is " << num << endl;
        if (oplevel == oplevel2) {
          // produces the correct answer and how it was found
          // also says which operator has a higher precedence
          cout << op << " is on the same precedence level as "
               << op2 << "." << endl;
          cout << "The expression evaluates as follows " << endl;
          cout << "(" << a << op << b << ")" << op2 << c << endl;
          cout << math(op, a, b) << op2 << c << endl;
          cout << num <<  endl;
        } else if (oplevel > oplevel2) {
          cout << op << " has higher precedence than " << op2 << "." << endl;
          cout << "The expression evaluates as follows " << endl;
          cout << "(" << a << op << b << ")" << op2 << c << endl;
          cout << math(op, a, b) << op2 << c << endl;
          cout << num <<  endl;
        } else {
          cout << op2 << " has higher precedence than " << op << "." << endl;
          cout << "The expression evaluates as follows " << endl;
          cout << a << op << "(" << b << op2 << c << ")" << endl;
          cout << a << op << math(op2, b, c) << endl;
          cout << num <<  endl;
        }
      }
      // cout << num << endl;
      count += 1;
    }
    // says how many questions they answered correctly out of the total
    // number and the time it took
    int stopTime = time(0) - start;
    cout << "You correctly answered " << right << " of " << express
         << " questions correctly in " << stopTime << " seconds." << endl;
    if (stopTime > goalTime) {
      if (stopTime - goalTime == 1) {
        cout << "You exceeded your goal time by "
             << stopTime - goalTime << " second." << endl;
      } else {
        cout << "You exceeded your goal time by "
             << stopTime - goalTime << " seconds." << endl;
        }
    } else if (stopTime < goalTime) {
      if (goalTime - stopTime == 1) {
        cout << "You beat your goal time by "
             << abs(stopTime - goalTime) << " second!" << endl;
      } else {
        cout << "You beat your goal time by "
             << abs(stopTime - goalTime) << " seconds!" << endl;
        }
      } else {
        cout << "You met your goal time!" << endl;
      }
    // keeps track of total questions and total correct questions answered
    int totalRight;
    totalRight += right;
    int totalQuestions;
    totalQuestions += express;
    // asks if the user wants to play another round
    cout << "Do you want to play again? "
         << "(Please enter 'y' for yes or 'n' for no)" << endl;
    cin >> again;
    rounds += 1;
    // if they are done playing and they have played more than one round it
    // will provide the total number of correct questions and total questions
    if (again == 'n' && rounds > 1) {
      cout << "You answered " << totalRight << " of "
           << totalQuestions << " questions right in total!" << endl;
    }
  }
  cout << "Thanks for playing!" << endl;
  // completes program
  return 0;
}

