#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>

#include "mainwindow.h"
#include "../core/factory.h"
#include "../core/configurable.h"



/**
 *
 */

MainWindow::MainWindow( QWidget* parent ) :
	QMainWindow( parent ),
	_layout( new QHBoxLayout( )) {

	setup( );
}



/**
 *
 */

void MainWindow::setup( ) {

	QWidget* widget = new QWidget( );
	widget->setLayout( _layout );

	setWindowTitle( "QBiip" );
	setCentralWidget( widget );

	buildSelector< Input >( "Input" );
	buildSelector< Output >( "Output" );
}



/**
 *
 */

template< class Type >
void MainWindow::buildSelector( const QString& title ) const {

	Informations informations = Factory< Type >::informations( );
	InformationsIterator it( informations );

	QComboBox* combo = new QComboBox( );
	OptionList options;

	while ( it.hasNext( )) {
		it.next( );

		try {
			Type* object = Factory< Type >::create( it.key( ));
			combo->addItem( it.key( ), qVariantFromValue(( void* )object ));
		} catch ( ... ) {
			//
		}
	}

	QVBoxLayout* layout = new QVBoxLayout( );
	layout->addWidget( new QLabel( title ));
	layout->addWidget( combo );

	QVBoxLayout* optionsLayout = new QVBoxLayout( );

	_layout->addLayout( layout );
}
