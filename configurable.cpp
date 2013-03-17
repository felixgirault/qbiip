#include "configurable.h"



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

void Configurable::configure( const QVariantMap& options ) {

	Q_UNUSED( options );
}

