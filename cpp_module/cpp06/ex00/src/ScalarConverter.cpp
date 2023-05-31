#include "ScalarConverter.hpp"


/*Defaault*/
ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void) src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	(void) src;
	return *this;
}


/*Converter*/
void ScalarConverter::convert(const std::string &str)
{
	t_converter_info info_dts;

	initConverterInfo(&info_dts, str);
	try
	{
		initType(&info_dts);
		converter(&info_dts);
	}
	catch(const std::exception& e)
	{
		CoutUtil::errorCout(e.what());
	}
}

void ScalarConverter::initConverterInfo(t_converter_info *info_dts, const std::string &str)
{
	info_dts->raw_string = str;
	info_dts->type = NONE;
	info_dts->status[CHAR] = SUCCESS;
	info_dts->status[INT] = SUCCESS;
	info_dts->status[FLOAT] = SUCCESS;
	info_dts->status[DOUBLE] = SUCCESS;
}

void ScalarConverter::initType(t_converter_info *info_dts)
{
	info_dts->type = Typetoi::findType(info_dts->raw_string);
	if (info_dts->type == NONE)
		throw std::runtime_error("Unknown type");
}

void ScalarConverter::converter(t_converter_info *info_dts)
{
	switch (info_dts->type)
	{
		case CHAR:
			charConverter(info_dts);
			break;
		case INT:
			intConverter(info_dts);
			break;
		case FLOAT:
			floatConverter(info_dts);
			break;
		case DOUBLE:
			doubleConverter(info_dts);
			break;
		default:
			break;
	}
}

/*Char Converter*/
void ScalarConverter::charConverter(t_converter_info *info_dts)
{
	info_dts->cast_value.cast_char = info_dts->raw_string[0];
	convertFromChar(info_dts);
	printer(info_dts);
}

void ScalarConverter::convertFromChar(t_converter_info *info_dts)
{
	info_dts->cast_value.cast_int = static_cast<int>(info_dts->cast_value.cast_char);
	info_dts->cast_value.cast_float = static_cast<float>(info_dts->cast_value.cast_char);
	info_dts->cast_value.cast_double = static_cast<double>(info_dts->cast_value.cast_char);
}


/*Int Converter*/
void ScalarConverter::intConverter(t_converter_info *info_dts)
{
	long result;

	result = std::strtol(info_dts->raw_string.c_str(), NULL, 10);

	if(!errnoOverflowChecker())
		info_dts->status[INT] = OVERFLOWED;

	if(!intRangeChecker(result))
		info_dts->status[INT] = OVERFLOWED;

	info_dts->cast_value.cast_int = result;
	convertFromInt(info_dts);
	printer(info_dts);
}

void ScalarConverter::convertFromInt(t_converter_info *info_dts)
{
	info_dts->cast_value.cast_char = static_cast<char>(info_dts->cast_value.cast_int);
	info_dts->cast_value.cast_float = static_cast<float>(info_dts->cast_value.cast_int);
	info_dts->cast_value.cast_double = static_cast<double>(info_dts->cast_value.cast_int);

	if (!std::isprint(info_dts->cast_value.cast_int))
		info_dts->status[CHAR] = NON_DISPLAYABLE;

	if (info_dts->cast_value.cast_int < std::numeric_limits<char>::min()
	|| info_dts->cast_value.cast_int > std::numeric_limits<char>::max())
		info_dts->status[CHAR] = OVERFLOWED;

	if (info_dts->status[INT] != SUCCESS)
	{
		info_dts->status[CHAR] = info_dts->status[INT];
		info_dts->status[FLOAT] = info_dts->status[INT];
		info_dts->status[DOUBLE] = info_dts->status[INT];
	}
}


/*Float Converter*/
void ScalarConverter::floatConverter(t_converter_info *info_dts)
{
	double result;

	result = std::strtod(info_dts->raw_string.c_str(), NULL);

	if (!errnoOverflowChecker())
		info_dts->status[FLOAT] = OVERFLOWED;

	if (!floatRangeChecker(result))
		info_dts->status[FLOAT] = OVERFLOWED;

	if (info_dts->raw_string == "nanf"
	|| info_dts->raw_string == "-inff"
	|| info_dts->raw_string == "+inff"
	|| info_dts->raw_string == "inff")
		info_dts->status[FLOAT] = SUCCESS;

	info_dts->cast_value.cast_float = static_cast<float> (result);
	convertFromFloat(info_dts);
	printer(info_dts);
}

void ScalarConverter::convertFromFloat(t_converter_info *info_dts)
{
	info_dts->cast_value.cast_int = static_cast<int>(info_dts->cast_value.cast_float);
	info_dts->cast_value.cast_char = static_cast<char>(info_dts->cast_value.cast_float);
	info_dts->cast_value.cast_double = static_cast<double>(info_dts->cast_value.cast_float);

	if (!std::isprint(static_cast<int> (info_dts->cast_value.cast_float)))
		info_dts->status[CHAR] = NON_DISPLAYABLE;

	if (info_dts->cast_value.cast_float < std::numeric_limits<char>::min()
	|| info_dts->cast_value.cast_float >= std::numeric_limits<char>::max() + 1)
		info_dts->status[CHAR] = OVERFLOWED;

	if (info_dts->cast_value.cast_float < std::numeric_limits<int>::min()
	|| info_dts->cast_value.cast_float >= static_cast<float>(std::numeric_limits<int>::max()) + 1.0f)
		info_dts->status[INT] = OVERFLOWED;

	if (info_dts->raw_string == "nanf"
	|| info_dts->raw_string == "-inff"
	|| info_dts->raw_string == "+inff"
	|| info_dts->raw_string == "inff")
	{
		info_dts->status[CHAR] = NOT_SUPPORTED;
		info_dts->status[INT] = NOT_SUPPORTED;
	}

	if (info_dts->status[FLOAT] != SUCCESS)
	{
		info_dts->status[CHAR] = info_dts->status[FLOAT];
		info_dts->status[INT] = info_dts->status[FLOAT];
		info_dts->status[DOUBLE] = info_dts->status[FLOAT];
	}
}


/*Double Converter*/
void ScalarConverter::doubleConverter(t_converter_info *info_dts)
{
	double result;

	result = std::strtod(info_dts->raw_string.c_str(), NULL);

	if(!errnoOverflowChecker())
		info_dts->status[DOUBLE] = OVERFLOWED;

	if (info_dts->raw_string == "nan"
	|| info_dts->raw_string == "-inf"
	|| info_dts->raw_string == "+inf"
	|| info_dts->raw_string == "inf")
		info_dts->status[DOUBLE] = SUCCESS;

	info_dts->cast_value.cast_double = result;
	convertFromDouble(info_dts);
	printer(info_dts);
}

void ScalarConverter::convertFromDouble(t_converter_info *info_dts)
{
	info_dts->cast_value.cast_int = static_cast<int>(info_dts->cast_value.cast_double);
	info_dts->cast_value.cast_char = static_cast<char>(info_dts->cast_value.cast_double);
	info_dts->cast_value.cast_float = static_cast<double>(info_dts->cast_value.cast_double);

	if (!std::isprint(static_cast<int> (info_dts->cast_value.cast_double)))
		info_dts->status[CHAR] = NON_DISPLAYABLE;

	if (info_dts->cast_value.cast_double < std::numeric_limits<char>::min()
	|| info_dts->cast_value.cast_double >= std::numeric_limits<char>::max() + 1)
		info_dts->status[CHAR] = OVERFLOWED;

	if (info_dts->cast_value.cast_double < std::numeric_limits<int>::min()
	|| info_dts->cast_value.cast_double >= static_cast<double>(std::numeric_limits<int>::max()) + 1.0)
		info_dts->status[INT] = OVERFLOWED;

	if (info_dts->cast_value.cast_double < -3.4 * pow(10.0, 38.0)
	|| info_dts->cast_value.cast_double > std::numeric_limits<float>::max())
		info_dts->status[FLOAT] = OVERFLOWED;

	if (info_dts->raw_string == "nan"
	|| info_dts->raw_string == "-inf"
	|| info_dts->raw_string == "+inf"
	|| info_dts->raw_string == "inf")
	{
		info_dts->status[CHAR] = NOT_SUPPORTED;
		info_dts->status[INT] = NOT_SUPPORTED;
		info_dts->status[FLOAT] = SUCCESS;
	}

	if (info_dts->status[DOUBLE] != SUCCESS)
	{
		info_dts->status[CHAR] = info_dts->status[DOUBLE];
		info_dts->status[FLOAT] = info_dts->status[DOUBLE];
		info_dts->status[INT] = info_dts->status[DOUBLE];
	}
}


/*Checker*/
bool ScalarConverter::errnoOverflowChecker()
{
	if (errno == ERANGE)
		return false;
	return true;
}

bool ScalarConverter::intRangeChecker(long value)
{
	if (static_cast<long> (static_cast<int> (value)) != value)
		return false;
	return true;
}

bool ScalarConverter::floatRangeChecker(double value)
{
	if (value > static_cast<double> (std::numeric_limits<float>::max())
	|| value < static_cast<double> (-3.4 * pow(10.0, 38.0)))
		return false;
	return true;
}


/*Printer*/
void ScalarConverter::printer(t_converter_info *info_dts)
{
	printChar(info_dts);
	printInt(info_dts);
	printFloat(info_dts);
	printDouble(info_dts);
}

void ScalarConverter::printChar(t_converter_info *info_dts)
{
	CoutUtil::regularCoutNoEndl("char: ");
	if (info_dts->status[CHAR] == SUCCESS)
		std::cout << "'" << info_dts->cast_value.cast_char << "'" << std::endl;
	else if (info_dts->status[CHAR] == NON_DISPLAYABLE)
		CoutUtil::regularCout("Non displayable");
	else if (info_dts->status[CHAR] == OVERFLOWED
	|| info_dts->status[CHAR] == NOT_SUPPORTED)
		CoutUtil::regularCout("impossible");
}

void ScalarConverter::printInt(t_converter_info *info_dts)
{
	CoutUtil::regularCoutNoEndl("int: ");
	if (info_dts->status[INT] == SUCCESS)
		std::cout << info_dts->cast_value.cast_int << std::endl;
	else if (info_dts->status[INT] == OVERFLOWED
	|| info_dts->status[INT] == NOT_SUPPORTED)
		CoutUtil::regularCout("impossible");
}

void ScalarConverter::printFloat(t_converter_info *info_dts)
{
	CoutUtil::regularCoutNoEndl("float: ");
	if (info_dts->status[FLOAT] == SUCCESS)
	{
		std::cout << info_dts->cast_value.cast_float;
		if (info_dts->cast_value.cast_float < 1e6f
		&& info_dts->cast_value.cast_float > -1e6f
		&& info_dts->cast_value.cast_float == info_dts->cast_value.cast_int)
			std::cout << ".0";
		std::cout << 'f' << std::endl;
	}
	else if (info_dts->status[FLOAT] == OVERFLOWED
	|| info_dts->status[FLOAT] == NOT_SUPPORTED)
		CoutUtil::regularCout("impossible");
}

void ScalarConverter::printDouble(t_converter_info *info_dts)
{
	CoutUtil::regularCoutNoEndl("double: ");
	if (info_dts->status[DOUBLE] == SUCCESS)
	{
		// 오차 처리 할건지 말건지 결정하기
		// std::cout.setf(std::ios::fixed);
		// std::cout << std::fixed;
    	// std::cout.precision(1);
    	std::cout << info_dts->cast_value.cast_double;
		if (info_dts->cast_value.cast_double < 1e6f
		&& info_dts->cast_value.cast_double > -1e6f
		&& info_dts->cast_value.cast_double == info_dts->cast_value.cast_int)
			std::cout << ".0";
		std::cout << std::endl;
	}
	else if (info_dts->status[DOUBLE] == OVERFLOWED
	|| info_dts->status[DOUBLE] == NOT_SUPPORTED)
		CoutUtil::regularCout("impossible");
}

