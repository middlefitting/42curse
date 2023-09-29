#include "Typetoi.hpp"

Typetoi::Typetoi() {}

Typetoi::~Typetoi() {}

Typetoi::Typetoi(const Typetoi &src) { (void)src; }

Typetoi &Typetoi::operator=(const Typetoi &src) {
  (void)src;
  return *this;
}

t_type Typetoi::findType(const std::string &str) {
  t_info info_dts;

  initInfo(str, &info_dts);
  signAppender(&info_dts);
  numberAppender(&info_dts);
  dotAppender(&info_dts);
  dicimalAppender(&info_dts);
  floatAppender(&info_dts);
  calcType(&info_dts);
  return info_dts.result;
}

void Typetoi::initInfo(const std::string &str, t_info *info_dts) {
  info_dts->idx = 0;
  info_dts->str_len = str.length();
  info_dts->raw_string = str;
  info_dts->dot_flag = false;
  info_dts->dicimal_flag = false;
  info_dts->float_flag = false;
  info_dts->result = NONE;
};

void Typetoi::signAppender(t_info *info_dts) {
  if (info_dts->raw_string[info_dts->idx] == '-' ||
      info_dts->raw_string[info_dts->idx] == '+')
    ++info_dts->idx;
}

void Typetoi::numberAppender(t_info *info_dts) {
  while (std::isdigit(info_dts->raw_string[info_dts->idx])) ++info_dts->idx;
}

void Typetoi::dotAppender(t_info *info_dts) {
  if (info_dts->raw_string[info_dts->idx] == '.') {
    info_dts->dot_flag = true;
    ++info_dts->idx;
  }
}

void Typetoi::dicimalAppender(t_info *info_dts) {
  while (std::isdigit(info_dts->raw_string[info_dts->idx])) {
    info_dts->dicimal_flag = true;
    ++info_dts->idx;
  }
}

void Typetoi::floatAppender(t_info *info_dts) {
  if (info_dts->raw_string[info_dts->idx] == 'f') {
    info_dts->float_flag = true;
    ++info_dts->idx;
  }
}

void Typetoi::calcType(t_info *info_dts) {
  charSetter(info_dts);
  intSetter(info_dts);
  floatSetter(info_dts);
  doubleSetter(info_dts);
}

void Typetoi::charSetter(t_info *info_dts) {
  if (info_dts->str_len == 1 && std::isprint(info_dts->raw_string[0]) &&
      !std::isdigit(info_dts->raw_string[0]))
    info_dts->result = CHAR;

  if (info_dts->str_len == 1 && !std::isprint(info_dts->raw_string[0]))
    throw std::runtime_error("Non displayable char");
}

void Typetoi::intSetter(t_info *info_dts) {
  if (info_dts->idx == info_dts->str_len && !info_dts->dot_flag &&
      !info_dts->float_flag)
    info_dts->result = INT;
}

void Typetoi::floatSetter(t_info *info_dts) {
  if (info_dts->idx == info_dts->str_len && info_dts->dot_flag &&
      info_dts->dicimal_flag && info_dts->float_flag)
    info_dts->result = FLOAT;

  if (info_dts->raw_string == "nanf" || info_dts->raw_string == "inff" ||
      info_dts->raw_string == "+inff" || info_dts->raw_string == "-inff")
    info_dts->result = FLOAT;
}

void Typetoi::doubleSetter(t_info *info_dts) {
  if (info_dts->idx == info_dts->str_len && info_dts->dot_flag &&
      info_dts->dicimal_flag && !info_dts->float_flag)
    info_dts->result = DOUBLE;

  if (info_dts->raw_string == "nan" || info_dts->raw_string == "inf" ||
      info_dts->raw_string == "+inf" || info_dts->raw_string == "-inf")
    info_dts->result = DOUBLE;
}
