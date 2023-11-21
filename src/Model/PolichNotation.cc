#include "SmartCalcModel.h"

double s21::SmartCalcModel::PolichNotation() {
  str_ = Reverse(str_);
  std::stack<leksem> oper_func;
  std::stack<leksem> polish;
  while (!str_.empty()) {
    if (OperatorStack(str_) || Func(str_)) {
      if (oper_func.empty()) {
        oper_func.push({str_.top().arr, str_.top().prioritet, str_.top().type});
      } else if (oper_func.top().prioritet < str_.top().prioritet ||
                 oper_func.top().type == Lbracket_1) {
        oper_func.push({str_.top().arr, str_.top().prioritet, str_.top().type});
      } else if (oper_func.top().prioritet == str_.top().prioritet) {
        polish.push({oper_func.top().arr, oper_func.top().prioritet,
                     oper_func.top().type});
        oper_func.pop();
        oper_func.push({str_.top().arr, str_.top().prioritet, str_.top().type});
      } else {
        polish.push({oper_func.top().arr, oper_func.top().prioritet,
                     oper_func.top().type});
        oper_func.pop();
        if (polish.top().prioritet >= 2) {
          if (!oper_func.empty()) {
            if (oper_func.top().prioritet >= 1 &&
                oper_func.top().prioritet != 5) {
              polish.push({oper_func.top().arr, oper_func.top().prioritet,
                           oper_func.top().type});
              oper_func.pop();
            }
          }
        }
        oper_func.push({str_.top().arr, str_.top().prioritet, str_.top().type});
      }
    }
    if (str_.top().type == Lbracket_1) {
      oper_func.push({str_.top().arr, str_.top().prioritet, str_.top().type});
    }
    if (str_.top().type == number || str_.top().type == zero ||
        str_.top().type == X) {
      polish.push({str_.top().arr, str_.top().prioritet, str_.top().type});
    }
    if (str_.top().type == Rbracket_1) {
      if (!oper_func.empty()) {
        while (oper_func.top().type != Lbracket_1) {
          polish.push({oper_func.top().arr, oper_func.top().prioritet,
                       oper_func.top().type});
          oper_func.pop();
        }
      }
      oper_func.pop();
    }
    str_.pop();
  }
  while (!oper_func.empty()) {
    polish.push(
        {oper_func.top().arr, oper_func.top().prioritet, oper_func.top().type});
    oper_func.pop();
  }
  polish = Reverse(polish);
  return Result(polish, this->num);
}