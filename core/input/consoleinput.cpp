#include <iostream>

#include "consoleinput.h"
#include "../exception.h"
#include "../factory.h"



/**
 *
 */

REGISTER_PRODUCT(
	Input,
	ConsoleInput,
	"console",
	"Reads notes from the standard input."
)



/**
 *
 */

ConsoleInput::ConsoleInput( QObject* parent ) :
	Input( parent ) {

}



/**
 *
 */

void ConsoleInput::start( ) {

	Note note;
	std::string track;
	std::string name;

	std::cout << "track: ";
	std::cin >> track;
	note.track = QString::fromStdString( track );

	std::cout << "duration: ";
	std::cin >> note.duration;

	while ( 1 ) {
		try {
			std::cout << "note: ";
			std::cin >> name;

			note.frequency = _frequencies.frequency(
				QString::fromStdString( name )
			);

			emit played( note );
		} catch ( const Exception& e ) {
			std::cerr << e.message( ).toStdString( ) << std::endl;
		}
	}
}



/**
 *
 */

void ConsoleInput::stop( ) {

}
