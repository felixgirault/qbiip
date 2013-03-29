#include <QApplication>

#include "mainwindow.h"



/**
 *	Entry point of the application.
 *
 *	@param argc Argument count
 *	@param argv Arguments
 *	@return Execution status
 */

int main( int argc, char* argv[ ]) {

	QApplication app( argc, argv );

	MainWindow window;
	window.show( );

	return app.exec( );
}
