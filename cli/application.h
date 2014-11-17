#ifndef Q_BIIP_H
#define Q_BIIP_H

#include <QCoreApplication>
#include <QStringList>
#include <QVariantMap>

#include "../core/factory.h"

class Input;
class Output;



/**
 *	The QBiip class.
 */
class Application : public QCoreApplication {

	Q_OBJECT

	public:

		Application(int argc, char* argv[]);

	public slots:

		int exec();

	private:

		void parseArguments();

		template< class Type >
		void printInformations(const QString& typeName) const;

		template< class Type >
		Type* create(const QString& typeName) const;

	private:

		QVariantMap _options;

		Input* _input;
		Output* _output;

};

#endif // Q_BIIP_H
