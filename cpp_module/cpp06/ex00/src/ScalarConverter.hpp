#pragma once

#include <math.h>

#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

#include "CoutUtil.hpp"
#include "Typetoi.hpp"

typedef enum e_convert_status {
  SUCCESS,
  OVERFLOWED,
  NON_DISPLAYABLE,
  NOT_SUPPORTED
} t_convert_status;

typedef struct cast_value {
  char cast_char;
  int cast_int;
  float cast_float;
  double cast_double;
} t_cast_value;

typedef struct s_converter_info {
  std::string raw_string;
  t_type type;
  t_cast_value cast_value;
  e_convert_status status[4];
} t_converter_info;

class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(const ScalarConverter &src);
  static void initConverterInfo(t_converter_info *info_dts,
                                const std::string &str);
  static void initType(t_converter_info *info_dts);
  static void converter(t_converter_info *info_dts);

  static void charConverter(t_converter_info *info_dts);
  static void convertFromChar(t_converter_info *info_dts);

  static void intConverter(t_converter_info *info_dts);
  static void convertFromInt(t_converter_info *info_dts);

  static void floatConverter(t_converter_info *info_dts);
  static void convertFromFloat(t_converter_info *info_dts);

  static void doubleConverter(t_converter_info *info_dts);
  static void convertFromDouble(t_converter_info *info_dts);

  static bool errnoOverflowChecker();
  static bool intRangeChecker(long value);
  static bool floatRangeChecker(double value);

  static void printer(t_converter_info *info_dts);
  static void printChar(t_converter_info *info_dts);
  static void printInt(t_converter_info *info_dts);
  static void printFloat(t_converter_info *info_dts);
  static void printDouble(t_converter_info *info_dts);

 public:
  static void convert(const std::string &str);
};
