#ifndef TRIM_H_
#define TRIM_H_

#include <vector>

// handler for a triangular matrix from a linear 1d array
class trim
{
 private:
  int base;
  int size;
  std::vector<double> content;
 public:
  trim(const int n);
  double linearread(const int element);
  void linearwrite(const int element, const double value);
  void linearprint();
  double rcread(const int r, const int c);
  void rcwrite(const int r, const int c, const double value);
  void print2d();
};

#endif
