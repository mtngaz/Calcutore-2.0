#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(math_opearations()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(math_opearations()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(number_x()));
  connect(ui->pushButton_Lbrack, SIGNAL(clicked()), this, SLOT(bracket()));
  connect(ui->pushButton_Rbrack, SIGNAL(clicked()), this, SLOT(bracket()));
  connect(ui->pushButton_graf, SIGNAL(clicked()), this, SLOT(graf()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  double all_number = 0;
  QString new_label;
  if (ui->lineEdit_input_result->text().contains("Error") ||
      ui->lineEdit_input_result->text().contains("Incorrect input")) {
    ui->lineEdit_input_result->setText("");
  }
  if (ui->lineEdit_input_result->text().contains(".") &&
      button->text() == "0") {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("+")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("-")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("/")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("*")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("^")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("mod")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("(")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains(")")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("sin")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("cos")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("tan")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("asin")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("acos")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("atan")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("log")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("ln")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("sqrt")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else if (ui->lineEdit_input_result->text().contains("x")) {
    new_label = ui->lineEdit_input_result->text() + button->text();
  } else {
    all_number =
        (ui->lineEdit_input_result->text() + button->text()).toDouble();
    new_label = QString::number(all_number, 'g', 15);
  }
  ui->lineEdit_input_result->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked() {
  ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() + ".");
}

void MainWindow::math_opearations() {
  QPushButton *button = (QPushButton *)sender();
  if (ui->lineEdit_input_result->text().contains("Error") ||
      ui->lineEdit_input_result->text().contains("Incorrect input")) {
    ui->lineEdit_input_result->setText("");
  }
  if (button->text() == "+") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() + "+");
  } else if (button->text() == "-") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() + "-");
  } else if (button->text() == "*") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() + "*");
  } else if (button->text() == "/") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() + "/");
  } else if (button->text() == "^") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() + "^");
  } else if (button->text() == "mod") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "mod");
  } else if (button->text() == "sqrt") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "sqrt");
  } else if (button->text() == "log") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "log");
  } else if (button->text() == "ln") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "ln");
  } else if (button->text() == "sin") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "sin");
  } else if (button->text() == "cos") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "cos");
  } else if (button->text() == "tan") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "tan");
  } else if (button->text() == "asin") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "asin");
  } else if (button->text() == "acos") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "acos");
  } else if (button->text() == "atan") {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() +
                                       "atan");
  }
}

void MainWindow::on_pushButton_AC_clicked() {
  ui->lineEdit_input_result->setText("");
}

void MainWindow::number_x() {
  QPushButton *button = (QPushButton *)sender();
  if (ui->lineEdit_input_result->text().contains("Error") ||
      ui->lineEdit_input_result->text().contains("Incorrect input")) {
    ui->lineEdit_input_result->setText("");
  }
  if (button->text() == 'x') {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() + "x");
  }
}

void MainWindow::bracket() {
  QPushButton *button = (QPushButton *)sender();
  if (ui->lineEdit_input_result->text().contains("Error") ||
      ui->lineEdit_input_result->text().contains("Incorrect input")) {
    ui->lineEdit_input_result->setText("");
  }
  if (button->text() == '(') {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() + "(");
  } else if (button->text() == ')') {
    ui->lineEdit_input_result->setText(ui->lineEdit_input_result->text() + ")");
  }
}

void MainWindow::on_pushButton_equals_clicked() {
  QPushButton *button = (QPushButton *)sender();
  char num_1[1000] = {0};
  QString str = ui->lineEdit_input_result->text();
  double num = ui->lineEdit_x->text().toDouble();
  if (button->text() == "=") {
    ui->lineEdit_x->setText("");
  }
  if (!Calc.Validator(str.toStdString().c_str(), num)) {
    double res = Calc.Calculate(str.toStdString().c_str(), num);
    sprintf(num_1, "%.7lf", res);
    ui->lineEdit_input_result->setText(num_1);
  } else {
    ui->lineEdit_input_result->setText("Incorrect input");
  }
}

void MainWindow::graf() {
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "graf") {
    ui->widget->clearGraphs();
    ui->widget->clearItems();
  }
  if (ui->lineEdit_input_result->text().contains("Error") ||
      ui->lineEdit_input_result->text().contains("Incorrect input")) {
    ui->lineEdit_input_result->setText("");
  }
  double xMin = ui->lineEdit_x_min->text().toDouble();
  double xMax = ui->lineEdit_x_max->text().toDouble();
  double yMin = ui->lineEdit_y_min->text().toDouble();
  double yMax = ui->lineEdit_y_max->text().toDouble();
  h = 0.0001;
  if (xMin >= xMax || yMin >= yMax || xMin < -1000000 || xMax > 1000000 ||
      yMin < -1000000 || yMax > 1000000) {
    ui->lineEdit_input_result->setText("Error");
  } else {
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin, yMax);
    QString str = ui->lineEdit_input_result->text();
    if (!Calc.Validator(str.toStdString().c_str(), X)) {
      for (X = xMin; X <= xMax; X += h) {
        x.push_back(X);
        double value_1 = Calc.Calculate(str.toStdString().c_str(), X);
        y.push_back(value_1);
      }
    } else {
      ui->lineEdit_input_result->setText("Incorrect input");
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
    ui->widget->replot();
    ui->widget->replot();
    x.clear();
    y.clear();
    if (button->text() == "graf") {
      ui->lineEdit_x_min->setText("");
      ui->lineEdit_x_max->setText("");
      ui->lineEdit_y_min->setText("");
      ui->lineEdit_y_max->setText("");
      ui->lineEdit_input_result->setText("");
    }
  }
}
