#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QException>
#include <QString>



/**
 *
 */

class Exception : public QException {

	public:

		Exception( const QString& message );
		~Exception( ) throw ( ) { }

		QString message( ) const;

	private:

		QString _message;

};

#endif // EXCEPTION_H
