#include <iostream>

#include "consoleoutput.h"
#include "../factory.h"



/**
 *
 */
REGISTER_PRODUCT(
	Output,
	ConsoleOutput,
	"console",
	"Outputs notes to the standard output."
)



/**
 *
 */
ConsoleOutput::ConsoleOutput(QObject* parent) :
	Output(parent)
{}



/**
 *
 */
void ConsoleOutput::play(const Note& note) {
	std::cout << note << std::endl;
}
