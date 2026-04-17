// Copyright kkilborn lleita 2026
#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include<iostream>
using std::ostream;

class DynamicArray {
  // friend of class
  friend ostream& operator << (ostream&, const DynamicArray&);
  // accessible outside of the class
 public:
  // DynamicArray Constructor
  explicit DynamicArray(int size = 1);
  // DynamicArray Copy Constructor
  DynamicArray(const DynamicArray& other);
  // DynamicArray Assignment Operator
  DynamicArray& operator = (const DynamicArray& other);
  // Dynamic Array Destructor
  ~DynamicArray();

  // version that allows one to use the operator in a non-constant setting
  // to update the values in the array
  int& operator[](int i) {
    if ( i >= 0 && i < size_ ) return values_[i];
    if ( i < 0 ) return values_[0];
    return values_[size_ - 1];
  }

  // version that allows one to use the operator on a constant array
  // returning copies of a value in the array
  int operator[](int i) const {
    if ( i >= 0 && i < size_ ) return values_[i];
    if ( i < 0 ) return values_[0];
    return values_[size_ - 1];
  }
  // additional operator
  DynamicArray& operator+=(int val);

  // setters
  static void SetDelimiter(char out);
  static void SetDelimeter(char out);
  void SetSize(int s, bool cop = true);
  // getters
  static char GetDelimiter() { return delimiter_; }
  int GetSize() const { return size_; }
  // equals operator
  bool operator==(const DynamicArray& right) const;
  // other functions
  bool AllUnique() const;
  int RemoveAll(int occ);
  int FindAndReplace(int rep1, int rep2);
  void RemoveDuplicates();
  void Sort(bool sorted = false);
  // additional functions
  int CountLessThan(int val) const;
  void KeepOdds();
  void KeepEvens();

  // accessible inside the class only
 private:
  int size_;
  int * values_;
  static char delimiter_;  // (for separator used by <<)
};
#endif

