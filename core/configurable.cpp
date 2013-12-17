#include <QVariant>
#include <QMap>

#include "configurable.h"



/**
 *
 */

Configurable::Option::Option(
	const QString& name,
	const QString& description,
	Type type
) :
	name( name ),
	description( description ),
	type( type ) {

}



/**
 *
 */

Configurable::Configurable( QObject* parent ) :
	QObject( parent ) {

}



/**
 *
 */

Configurable::~Configurable( ) {

}



/**
 *
 */

Configurable::OptionList Configurable::options( ) const {

	return OptionList( );
}



/**
 *
 */

void Configurable::configure( const QString& name, const QVariant& value ) {

	Q_UNUSED( name );
	Q_UNUSED( value );
}



/**
 *
 */

void Configurable::configure( const QVariantMap& options ) {

	QMapIterator< QString, QVariant > it( options );

	while ( it.hasNext( )) {
		it.next( );
		configure( it.key( ), it.value( ));
	}
}

