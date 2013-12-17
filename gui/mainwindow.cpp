#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

#include "mainwindow.h"
#include "selector.h"



/**
 *
 */

MainWindow::MainWindow( QWidget* parent ) :
	QMainWindow( parent ),
	_layout( new QGridLayout( )),
	_start( new QPushButton( "Start" )) {

	connect( _start, &QPushButton::clicked, this, &MainWindow::start );
	setup( );
}



/**
 *
 */

void MainWindow::start( ) {


}



/**
 *
 */

void MainWindow::setup( ) {

	QWidget* widget = new QWidget( );
	widget->setLayout( _layout );

	setWindowTitle( "QBiip" );
	setCentralWidget( widget );

	_layout->addWidget( new QLabel( "Input" ), 0, 0 );
	_layout->addWidget( new Selector< Input >( ), 1, 0 );

	_layout->addWidget( new QLabel( "Output" ), 0, 1 );
	_layout->addWidget( new Selector< Output >( ), 1, 1 );

	_layout->addWidget( _start, 2, 0, 2, 0 );
}
