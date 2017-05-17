#include <iostream>
#include "trim.h"

trim::trim(const int n)
{
  base = n;
  size = n*(n+1)/2;
  content.resize(size);
  for(double &i : content){
    i = 0.0;
  }
}

double trim::linearread(const int element)
{
  if(element >= size){
    std::cout << "trim::linearread: out of bounds";
  }
  return(content[element]);
}

void trim::linearwrite(const int element, const double value)
{
  if(element >= size){
    std::cout << "trim::linearwrite: out of bounds";
  }else{
    content[element] = value;
  }
}

void trim::linearprint()
{
  for(double i : content){
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

double trim::rcread(const int r, const int c)
{
  if(r > c){
    std::cout << "trim::rcread: r > c" << std::endl;
  }else if(r >= base){
    std::cout << "trim::rcread: r > base" << std::endl;
  }
  return(content[base*(base+1)/2 - (base-r)*(1+(base-r))/2 - r + c]);
}

void trim::rcwrite(const int r, const int c, const double value)
{
  if(r > c){
    std::cout << "trim::rcread: r > c" << std::endl;
  }else if(r >= base){
    std::cout << "trim::rcread: r > base" << std::endl;
  }
  content[base*(base+1)/2 - (base-r)*(1+(base-r))/2 - r + c] = value;
}

void trim::print2d()
{
  for(int i = 0; i < base; ++i){
    for(int j = 0; j < base; ++j){
      if(i > j){
	std::cout << "   ";
      }else{
	std::cout << rcread(i,j) << " ";
      }
    }
    std::cout << std::endl;
  }
}
