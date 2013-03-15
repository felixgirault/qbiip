#include <iostream>

#include "consoleplayer.h"



/**
 *
 */

void ConsolePlayer::play( const Note& note ) {

	std::cout << note.frequency << ":" << note.duration;
}
