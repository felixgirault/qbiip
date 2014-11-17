#include <QString>
#include <QStringList>

#include <iostream>
#include <iomanip>
#include <string>

#include "application.h"
#include "../core/input.h"
#include "../core/output.h"
#include "../core/streams.h"
#include "../core/exception.h"



/**
 *
 */
Application::Application(int argc, char* argv[]) :
	QCoreApplication(argc, argv) {

	parseArguments();
}



/**
 *
 */
int Application::exec() {
	if (_options.contains("help")) {
		printInformations< Input >("inputs");
		printInformations< Output >("outputs");
		return 0;
	}

	try {
		_input = create< Input >("input");
		_output = create< Output >("output");
	} catch (const Exception& e) {
		std::cerr << e.message() << std::endl;
		return 1;
	}

	connect(
		_input, &Input::played,
		_output, &Output::play
	);

	_input->play();

	return QCoreApplication::exec();
}



/**
 *
 */
void Application::parseArguments() {
	QString currentSwitch;

	foreach(const QString& argument, arguments()) {
		if (argument.startsWith("-")) {
			currentSwitch = argument.right(argument.size() - 1);
		} else if (!currentSwitch.isEmpty()) {
			_options.insert(currentSwitch, argument);
		}
	}
}



/**
 *
 */
template< class Type >
void Application::printInformations(const QString& typeName) const {
	Configurable* configurable = 0;
	Informations informations = Factory< Type >::informations();
	QMapIterator< QString, QString > it(informations);

	std::cout << "Available " << typeName << ":" << std::endl;

	while (it.hasNext()) {
		it.next();

		try {
			configurable = Factory< Type >::create(it.key());
		} catch (const Exception& e) {
			Q_UNUSED(e);
		}

		if (configurable) {
			std::cout << "- " << it.key() << ": " << it.value() << std::endl;

			foreach (const Configurable::Option& option, configurable->options()) {
				std::cout << "\t- " << option.name << ": " << option.description << std::endl;
			}
		}
	}
}



/**
 *
 */
template< class Type >
Type* Application::create(const QString& typeName) const {
	if (!_options.contains(typeName)) {
		throw Exception(
			QString("Please choose an %1 device (-%1 option).").arg(typeName)
		);
	}

	QString inputName = _options.value(typeName).toString();
	Type* object = Factory< Type >::create(inputName);

	if (!object) {
		throw Exception(
			QString("Please choose a valid %1 device (-help for a list).").arg(typeName)
		);
	}

	object->configure(_options);
	return object;
}
