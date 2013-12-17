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

void Stream::start( const QVariantMap& options ) {

	Q_UNUSED( options );
}

