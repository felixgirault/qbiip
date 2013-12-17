#ifndef STREAM_H
#define STREAM_H

#include <QObject>
#include <QVariant>



/**
 *	The Stream class.
 */

class Stream : public QObject {

	Q_OBJECT

	public:

		class Option {

			public:

				enum Type {
					Integer,
					String,
					Path
				};

			public:

				Option(
					Type type,
					const QString& name,
					const QString& description = QString( ),
					const QVariant& value = QVariant( )
				);

			public:

				Type type;
				QString name;
				QString description;
				QVariant value;

		};

		typedef QList< Option > OptionList;

	public:

		Stream( QObject* parent = 0 );
		virtual ~Stream( );

		virtual OptionList options( ) const;
		virtual void start( const QVariantMap& options );

};

#endif // STREAM_H
