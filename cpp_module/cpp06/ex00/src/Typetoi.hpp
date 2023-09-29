#pragma once

#include <iostream>

typedef enum e_type { INT, FLOAT, CHAR, DOUBLE, NONE } t_type;

typedef struct s_info {
  int idx;
  int str_len;
  std::string raw_string;
  bool dot_flag;
  bool dicimal_flag;
  bool float_flag;
  t_type result;
} t_info;

class Typetoi {
 private:
  Typetoi();
  ~Typetoi();
  Typetoi(const Typetoi &src);
  Typetoi &operator=(const Typetoi &src);

  static void initInfo(const std::string &str, t_info *info_dts);
  static void signAppender(t_info *info_dts);
  static void numberAppender(t_info *info_dts);
  static void dotAppender(t_info *info_dts);
  static void dicimalAppender(t_info *info_dts);
  static void floatAppender(t_info *info_dts);
  static void calcType(t_info *info_dts);
  static void charSetter(t_info *info_dts);
  static void intSetter(t_info *info_dts);
  static void floatSetter(t_info *info_dts);
  static void doubleSetter(t_info *info_dts);

 public:
  static t_type findType(const std::string &str);
};
