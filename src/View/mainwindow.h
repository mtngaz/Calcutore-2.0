#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// #include <QMainWindow>
// #include <QVector>
// #include <QtMath>

#include "../Controller/SmartCalcController.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  s21::SmartCalcController Calc;
  double h, X;
  QVector<double> x, y;

 private slots:
  void digits_numbers();
  void on_pushButton_AC_clicked();
  void math_opearations();
  void number_x();
  void bracket();
  void graf();
  void on_pushButton_equals_clicked();
  void on_pushButton_dot_clicked();
};
#endif  // MAINWINDOW_H
