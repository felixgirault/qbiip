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

		class Option {

			public:

				Option(
					const QString& name,
					const QString& description,
					int type
				);

			public:

				QString name;
				QString description;
				int type;

		};

		typedef QList< Option > OptionList;

	public:

		Configurable( QObject* parent = 0 );
		virtual ~Configurable( );

		virtual OptionList options( ) const;
		virtual void configure( const QVariantMap& options );

};

#endif // CONFIGURABLE_H
