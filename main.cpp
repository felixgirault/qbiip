#include <QCoreApplication>

#include "biip.h"



/**
 *	Entry point of the application.
 *
 *	@param argc Argument count
 *	@param argv Arguments
 *	@return Execution status
 */

int main( int argc, char* argv[ ]) {

	QCoreApplication app( argc, argv );

	Biip biip;
	biip.exec( );
	
	return app.exec( );
}
