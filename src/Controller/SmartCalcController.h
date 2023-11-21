#ifndef S21_SMART_CALC_2_SRC_CONTROLLER_SMART_CALC_CONTROLLER_H
#define S21_SMART_CALC_2_SRC_CONTROLLER_SMART_CALC_CONTROLLER_H

#include "../Model/SmartCalcModel.h"

namespace s21 {
class SmartCalcController {
 private:
  s21::SmartCalcModel model;

 public:
  int Validator(const char* str, double num) {
    model = s21::SmartCalcModel(str, num);
    return model.Validator();
  }

  double Calculate(const char* str, double num) {
    model = s21::SmartCalcModel(str, num);

    double result = model.SmartCalc();

    return result;
  }
};
}  // namespace s21
#endif  // S21_SMART_CALC_2_SRC_CONTROLLER_SMART_CALC_CONTROLLER_H