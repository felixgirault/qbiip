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

				enum Type {
					Integer,
					String,
					Path
				};

			public:

				Option(
					const QString& name,
					const QString& description,
					Type type
				);

			public:

				QString name;
				QString description;
				Type type;

		};

		typedef QList< Option > OptionList;

	public:

		Configurable(QObject* parent = 0);
		virtual ~Configurable();

		virtual OptionList options() const;
		virtual void configure(const QVariantMap& options);

};

#endif // CONFIGURABLE_H
