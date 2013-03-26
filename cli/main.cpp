#include "application.h"



/**
 *	Entry point of the application.
 *
 *	@param argc Argument count
 *	@param argv Arguments
 *	@return Execution status
 */

int main( int argc, char* argv[ ]) {

	Application app( argc, argv );
	return app.exec( );
}
