#include <iostream>

std::string DEC_to_BIN(int number);


int main() {
  int a = 681;
  std::cout <<"a (#10) = " << a 
    << "\na (#2) = "<< DEC_to_BIN(a) << "\n";

  return 0;
}


std::string DEC_to_BIN(int number) {
  std::string result = "";  
  
  while (number != 0) {
    if (number & 1) 
      result += "1";
    else 
      result += "0";

    number = (number >> 1);
  }
  
  // reversing string
  for (int i = 0; i < int(result.size() / 2); i++)
    std::swap(result[i], result[result.size() - i - 1]);
  
  return result;
}

