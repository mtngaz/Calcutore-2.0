#include "SmartCalcModel.h"

double s21::SmartCalcModel::Result(
    std::stack<s21::SmartCalcModel::leksem> pol_not, double num) {
  double res = 0;
  double res_1 = 0;
  double res_2 = 0;
  double x_1 = num;
  std::stack<leksem> number;
  std::stack<leksem> oper_func;
  while (!pol_not.empty()) {
    if (OperatorStack(pol_not) || Func(pol_not)) {
      oper_func.push(
          {pol_not.top().arr, pol_not.top().prioritet, pol_not.top().type});
    }
    if (pol_not.top().prioritet == 0) {
      if (pol_not.top().type == 0) {
        number.push(
            {pol_not.top().arr, pol_not.top().prioritet, pol_not.top().type});
      } else if (pol_not.top().type == zero) {
        number.push(
            {pol_not.top().arr, pol_not.top().prioritet, pol_not.top().type});
      } else if (pol_not.top().type == X) {
        number.push({x_1, pol_not.top().prioritet, pol_not.top().type});
      }
    }
    if (!oper_func.empty()) {
      if (OperatorStack(pol_not)) {
        res_2 = number.top().arr;
        number.pop();
        res_1 = number.top().arr;
        number.pop();
        res = Calc(res_1, res_2, oper_func);
        number.push({res, 0, 0});
        oper_func.pop();
      }
    }
    if (!oper_func.empty()) {
      if (Func(pol_not)) {
        res_1 = number.top().arr;
        number.pop();
        res = Calc(res_1, 0, oper_func);
        number.push({res, 0, 0});
        oper_func.pop();
      }
    }
    pol_not.pop();
  }
  if (oper_func.empty()) {
    res = number.top().arr;
  }
  return res;
}