#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>

#include "path.h"



/**
 *
 */

PathConfiguratorOption::PathConfiguratorOption( ) :
	ConfiguratorOption( ),
	_path( new QLineEdit( )),
	_browse( new QPushButton( "Browse" )) {

	connect( _browse, &QPushButton::clicked, this, &PathConfiguratorOption::browse );

	_layout->addWidget( _path );
	_layout->addWidget( _browse );
}



/**
 *
 */

QVariant PathConfiguratorOption::value( ) const {

	return QVariant( _path->text( ));
}



/**
 *
 */

void PathConfiguratorOption::browse( ) {

	QFileDialog dialog( this );

	if ( dialog.exec( )) {
		_path->setText( dialog.selectedFiles( ).first( ));
	}
}
