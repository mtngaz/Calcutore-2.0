#ifndef S21_SMART_CALC_2_SRC_MODEL_SMART_CALC_MODEL_H
#define S21_SMART_CALC_2_SRC_MODEL_SMART_CALC_MODEL_H

#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <stdexcept>

namespace s21 {
class SmartCalcModel {
 public:
  SmartCalcModel() {
    str = nullptr;
    num = 0;
  }

  SmartCalcModel(const char* str, double num) {
    this->str = str;
    this->num = num;
  }

  ~SmartCalcModel() {}
  double SmartCalc() {
    Parcer();
    return PolichNotation();
  };
  int Validator();

 private:
  typedef enum {
    zero = -1,
    number = 0,
    X = 1,
    plus_1 = 2,
    minus_1 = 3,
    mult_1 = 4,
    div_1 = 5,
    mod_1 = 6,
    pow_1 = 7,
    cos_1 = 8,
    sin_1 = 9,
    tan_1 = 10,
    acos_1 = 11,
    asin_1 = 12,
    atan_1 = 13,
    sqrt_1 = 14,
    ln_1 = 15,
    log_1 = 16,
    Lbracket_1 = 17,
    Rbracket_1 = 18
  } type_t;

  struct leksem {
    long double arr;
    int prioritet;
    int type;
  };

  const char* str;
  double num;
  std::stack<leksem> str_;

  void Parcer();
  double PolichNotation();
  double Result(std::stack<leksem> pol_not, double num);
  double Calc(double value_1, double value_2, std::stack<leksem> operFunc);
  int OperatorStack(std::stack<leksem> st);
  int Func(std::stack<leksem> st);
  std::stack<leksem> Reverse(std::stack<leksem> st);
  int number_check(char sym);
};
}  // namespace s21

#endif  // S21_SMART_CALC_2_SRC_MODEL_SMART_CALC_MODEL_H