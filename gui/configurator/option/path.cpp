#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
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

	QHBoxLayout* layout = new QHBoxLayout( _widget );
	layout->addWidget( _path );
	layout->addWidget( _browse );
}



/**
 *
 */

QVariant PathConfiguratorOption::value( ) const {

	QLineEdit* input = qobject_cast< QLineEdit* >( _widget );
	return QVariant( input->text( ));
}



/**
 *
 */

void PathConfiguratorOption::browse( ) {

	QFileDialog dialog( _widget );

	if ( dialog.exec( )) {
		_path->setText( dialog.selectedFiles( ).first( ));
	}
}
