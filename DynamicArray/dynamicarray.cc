// Copyright kkilborn lleita 2026

// includes the header file code
#include"dynamicarray.h"

// ouput character between each pair of values for ostream operator
char DynamicArray::delimiter_ = ' ';

// ostream output operator
ostream& operator << (ostream& whereto, const DynamicArray& arr) {
  for (int i = 0; i < arr.size_; ++i) {
    whereto << arr.values_[i];
    if (i < arr.size_ - 1) {
      whereto << DynamicArray::delimiter_;
    }
  }
  return whereto;
}

// Constructor
DynamicArray::DynamicArray(int s) {
  if (s < 1) {
    s = 1;
  }
  size_ = s;
  values_ = new int[size_];
  for (int i = 0; i < size_; ++i) {
    values_[i] = 0;
  }
}

// Copy Constructor
DynamicArray::DynamicArray(const DynamicArray& other) {
  size_ = other.size_;
  values_ = new int[size_];
  for (int i = 0; i < size_; ++i) {
    values_[i] = other.values_[i];
  }
}

// Assignment Operator
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
  if (this != &other) {
    int* newValues = new int[other.size_];
    for (int i = 0; i < other.size_; ++i) {
      newValues[i] = other.values_[i];
    }
    delete[] values_;
    size_ = other.size_;
    values_ = newValues;
  }
  return *this;
}

// equals operator
bool DynamicArray::operator==(const DynamicArray& right) const {
  if (size_ != right.size_) {
    return false;
  }
  for (int i = 0; i < size_; ++i) {
    if (values_[i] != right.values_[i]) {
      return false;
    }
  }
  return true;
}

// Adds to current array - can add values this way
DynamicArray& DynamicArray::operator+=(int val) {
  // creates larger array
  int* tempValues = new int[size_ + 1];
  // copies values
  for (int i = 0; i < size_; ++i) {
    tempValues[i] = values_[i];
  }
  tempValues[size_] = val;
  // ensures no memory leaks
  delete[] values_;
  values_ = tempValues;
  ++size_;
  return *this;
}

// Destructor
DynamicArray::~DynamicArray() {
  delete[] values_;
}

// Static set delimiter
void DynamicArray::SetDelimeter(char out) {
  delimiter_ = out;
}
void DynamicArray::SetDelimiter(char out) {
  delimiter_ = out;
}

// Static get delimiter
/*char DynamicArray::GetDelimiter() {
  return delimiter;
}*/

// sets new array size
void DynamicArray::SetSize(int s, bool par) {
  if (s < 1) {
    s = 1;
  }
  int* newValues = new int[s];
  if (par == true) {
    // checks if the new size is less than the old
    if (s < size_) {
      for (int i = 0; i < s; ++i) {
        newValues[i] = values_[i];
      }
    } else {
      for (int i = 0; i < size_; ++i) {
        newValues[i] = values_[i];
      }
      for (int i = size_; i < s; ++i) {
        newValues[i] = 0;
      }
    }
  } else {
    for (int i = 0; i < s; ++i) {
      newValues[i] = 0;
    }
  }
  delete[] values_;
  values_ = newValues;
  size_ = s;
}

/*int DynamicArray::GetSize() const {
  return size_;
}
static char GetDelimiter() {
  return GetDelimiter();
}*/

// checks to see if the entire array has none-repeated values
bool DynamicArray::AllUnique() const {
  for (int i = 0; i < size_; ++i) {
    for (int j = i + 1; j < size_; ++j) {
      if (values_[i] == values_[j]) {
        return false;
      }
    }
  }
  return true;
}

// removes all occurances of the int parameter and resizes the array
int DynamicArray::RemoveAll(int occ) {
  int count = 0;
  // counts how many instancese there are of the int parameter
  for (int i = 0; i < size_; ++i) {
    if (values_[i] == occ) {
      ++count;
    }
  }
  if (count == 0) {
    return 0;
  }
  if (count == size_) {
    delete[] values_;
    size_ = 1;
    values_ = new int[1];
    values_[0] = 0;
    return count;
  }
  int changeSize = size_ - count;
  int* newValues = new int[changeSize];
  int arrayPos = 0;
  for (int i = 0; i < size_; ++i) {
    if (values_[i] != occ) {
      newValues[arrayPos] = values_[i];
      ++arrayPos;
    }
  }
    delete[] values_;
    values_ = newValues;
    size_ = changeSize;
    return count;
}

// finds the first parameter and replaces it with the second
int DynamicArray::FindAndReplace(int rep1, int rep2) {
  int count = 0;
  for (int i = 0; i < size_; ++i) {
    if (values_[i] == rep1) {
      values_[i] = rep2;
      count += 1;
    }
  }
  return count;
}

// removes any duplicate values
void DynamicArray::RemoveDuplicates() {
  // int* tempValues = new int[size_];
  int unique = 0;
  // bool dup = false;
  for (int i = 0; i < size_; ++i) {
    bool seenBefore = false;
    for (int j = 0; j < i; ++j) {
      if (values_[i] == values_[j]) {
        seenBefore = true;
      }
    }
    if (seenBefore == false) {
      unique += 1;
    }
  }
  // creates temporary array
  int* tempValues = new int[unique];
  int arrayPos = 0;
  for (int i = 0; i < size_; ++i) {
    bool seenBefore = false;
    for (int j = 0; j < i; ++j) {
      if (values_[i] == values_[j]) {
        seenBefore = true;
      }
    }
    if (seenBefore == false) {
      tempValues[arrayPos] = values_[i];
      arrayPos += 1;
    }
  }
  delete[] values_;
  values_ = tempValues;
  size_ = unique;
}

// sorts array in ascneding by default
void DynamicArray::Sort(bool sort) {
  for (int i = 0; i < size_ - 1; ++i) {
    int cur = i;
    for (int j = i + 1; j < size_; ++j) {
      // if sort is true it sorts in descending order
      if (sort == false) {
        if (values_[j] < values_[cur]) {
          cur = j;
        }
      } else {
        if (values_[j] > values_[cur]) {
          cur = j;
        }
      }
    }
    if (cur != i) {
      int temp = values_[i];
      values_[i] = values_[cur];
      values_[cur] = temp;
    }
  }
}
// counts how many values are less than the int parameter
int DynamicArray::CountLessThan(int val) const {
  int count = 0;
  for (int i = 0; i < size_; ++i) {
    if (values_[i] < val) {
      ++count;
    }
  }
  return count;
}

// modifies the array to only keep the odd values
void DynamicArray::KeepOdds() {
  int count = 0;
  // counts number of odd numbers
  for (int i = 0; i < size_; ++i) {
    if (values_[i] % 2 != 0) {
      ++count;
    }
  }
  if (count == 0) {
    delete[] values_;
    values_ = new int[1];
    values_[0] = 0;
    size_ = 1;
    return;
  }
  int* tempValues = new int[count];
  int arrayPos = 0;
  // copies values over
  for (int i = 0; i < size_; ++i) {
    if (values_[i] % 2 != 0) {
      tempValues[arrayPos] = values_[i];
      ++arrayPos;
    }
  }
  delete[] values_;
  values_ = tempValues;
  size_ = count;
}

// modifies the array to only keep the even values
void DynamicArray::KeepEvens() {
  int count = 0;
  // counts number of even numbers
  for (int i = 0; i < size_; ++i) {
    if (values_[i] % 2 == 0) {
      ++count;
    }
  }
  if (count == 0) {
    delete[] values_;
    values_ = new int[1];
    values_[0] = 0;
    size_ = 1;
    return;
  }
  int* tempValues = new int[count];
  int arrayPos = 0;
  // copies values over
  for (int i = 0; i < size_; ++i) {
    if (values_[i] % 2 == 0) {
      tempValues[arrayPos] = values_[i];
      ++arrayPos;
    }
  }
  delete[] values_;
  values_ = tempValues;
  size_ = count;
}

