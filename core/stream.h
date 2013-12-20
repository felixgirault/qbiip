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
		void configure( const QVariantHash& options );
		void configure( const QString& name, const QVariant& value );

		template< typename Type >
		Type option( const QString& name, const Type& defaultValue = Type( )) const {

			QVariant variant = _options.value( name );

			if ( !variant.isNull( ) && variant.canConvert< Type >( )) {
				return variant.value< Type >( );
			}

			return defaultValue;
		}

		virtual void start( );
		virtual void stop( );

	protected:

		QVariantHash _options;

};

#endif // STREAM_H
