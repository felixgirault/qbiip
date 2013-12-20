#include <QVariant>
#include <QMap>

#include "stream.h"



/**
 *
 */

Stream::Option::Option(
	Type type,
	const QString& name,
	const QString& description,
	const QVariant& value
) :
	type( type ),
	name( name ),
	description( description ),
	value( value ) {

}



/**
 *
 */

Stream::Stream( QObject* parent ) :
	QObject( parent ) {

}



/**
 *
 */

Stream::~Stream( ) {

}



/**
 *
 */

Stream::OptionList Stream::options( ) const {

	return OptionList( );
}



/**
 *
 */

void Stream::configure( const QVariantHash& options ) {

	_options = options;
}



/**
 *
 */

void Stream::configure( const QString& name, const QVariant& value ) {

	_options.insert( name, value );
}



/**
 *
 */

void Stream::start( ) {

}



/**
 *
 */

void Stream::stop( ) {

}

