#include <QCoreApplication>

#include "qbiip.h"



/**
 *	Entry point of the application.
 *
 *	@param argc Argument count
 *	@param argv Arguments
 *	@return Execution status
 */

int main( int argc, char* argv[ ]) {

	QBiip qBiip( argc, argv );
	return qBiip.exec( );
}
