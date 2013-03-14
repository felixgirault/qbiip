#include <iostream>

#include "console.h"



/**
 *
 */

void Console::output( const Note& note ) {

	std::cout << note.frequency << ":" << note.duration;
}
