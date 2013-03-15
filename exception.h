#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>



/**
 *	The Exception class.
 */

class Exception {

	public:

		Exception( const QString& message );
		~Exception( ) throw ( ) { }

		QString message( ) const;

	private:

		QString _message;

};

#endif // EXCEPTION_H
