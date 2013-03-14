#include <QCoreApplication>

#include "biip.h"



/**
 *	Entry point of the application.
 *
 *	@param argc
 *	@param argv
 *	@return
 */

int main( int argc, char* argv[ ]) {

	QCoreApplication app( argc, argv );

	Biip biip;
	biip.wait( );
	
	return app.exec( );
}
