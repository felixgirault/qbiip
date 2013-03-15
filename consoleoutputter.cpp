#include <iostream>

#include "consoleoutputter.h"



/**
 *
 */

void ConsoleOutputter::output( const Note& note ) {

	std::cout << note.frequency << ":" << note.duration;
}
