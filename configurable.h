#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H

#include <QObject>
#include <QMap>



/**
 *	The Configurable class.
 */

class Configurable : public QObject {

	Q_OBJECT

	public:

		Configurable( QObject* parent = 0 );
		virtual ~Configurable( );

		virtual void configure( const QVariantMap& options );

};

#endif // CONFIGURABLE_H
