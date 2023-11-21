#include "SmartCalcModel.h"

double s21::SmartCalcModel::Calc(
    double value_1, double value_2,
    std::stack<s21::SmartCalcModel::leksem> operFunc) {
  long double res = 0;
  if (operFunc.top().type == 2) {
    res = value_1 + value_2;
  } else if (operFunc.top().type == 3) {
    res = value_1 - value_2;
  } else if (operFunc.top().type == 4) {
    res = value_1 * value_2;
  } else if (operFunc.top().type == 5) {
    res = value_1 / value_2;
  } else if (operFunc.top().type == 6) {
    res = fmod(value_1, value_2);
  } else if (operFunc.top().type == 7) {
    res = pow(value_1, value_2);
  } else if (operFunc.top().type == 8) {
    res = cos(value_1);
  } else if (operFunc.top().type == 9) {
    res = sin(value_1);
  } else if (operFunc.top().type == 10) {
    res = tan(value_1);
  } else if (operFunc.top().type == 11) {
    res = acos(value_1);
  } else if (operFunc.top().type == 12) {
    res = asin(value_1);
  } else if (operFunc.top().type == 13) {
    res = atan(value_1);
  } else if (operFunc.top().type == 14) {
    res = sqrt(value_1);
  } else if (operFunc.top().type == 15) {
    res = log(value_1);
  } else if (operFunc.top().type == 16) {
    res = log10(value_1);
  }
  return res;
}

std::stack<s21::SmartCalcModel::leksem> s21::SmartCalcModel::Reverse(
    std::stack<s21::SmartCalcModel::leksem> st) {
  std::stack<leksem> invers;
  while (!st.empty()) {
    invers.push(st.top());
    st.pop();
  }
  return invers;
}

int s21::SmartCalcModel::OperatorStack(
    std::stack<s21::SmartCalcModel::leksem> st) {
  int res = 0;
  if (st.top().type == plus_1) {
    res = 1;
  } else if (st.top().type == minus_1) {
    res = 1;
  } else if (st.top().type == mult_1) {
    res = 1;
  } else if (st.top().type == div_1) {
    res = 1;
  } else if (st.top().type == mod_1) {
    res = 1;
  } else if (st.top().type == pow_1) {
    res = 1;
  }
  return res;
}

int s21::SmartCalcModel::Func(std::stack<s21::SmartCalcModel::leksem> st) {
  int res = 0;
  if (st.top().type == cos_1) {
    res = 1;
  } else if (st.top().type == sin_1) {
    res = 1;
  } else if (st.top().type == tan_1) {
    res = 1;
  } else if (st.top().type == acos_1) {
    res = 1;
  } else if (st.top().type == asin_1) {
    res = 1;
  } else if (st.top().type == atan_1) {
    res = 1;
  } else if (st.top().type == sqrt_1) {
    res = 1;
  } else if (st.top().type == ln_1) {
    res = 1;
  } else if (st.top().type == log_1) {
    res = 1;
  }
  return res;
}

int s21::SmartCalcModel::number_check(char sym) {
  int res = 0;
  if (sym >= '0' && sym <= '9') {
    res = 1;
  }
  return res;
}