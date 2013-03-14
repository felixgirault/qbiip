#include "exception.h"



/**
 *	Constructor.
 */

Exception::Exception( const QString& message ) :
	_message( message ) {

}



/**
 *
 */

QString Exception::message( ) const {

	return _message;
}
