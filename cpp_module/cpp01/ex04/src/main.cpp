#include "Checker.hpp"
#include "Reader.hpp"
#include "Replacer.hpp"
#include "Saver.hpp"

int	main(int argc, char* argv[]) {
	Checker checker;
	checker.argc_check(argc);
	Reader reader(checker);
	std::string result = reader.read(argv[1]);
	result = Replacer::replace(result, argv[2], argv[3]);
	Saver saver(checker);
	saver.save(argv[1], result);
	return 0;
}
