#include "configurable.h"



/**
 *
 */
Configurable::Option::Option(
	const QString& name,
	const QString& description,
	Type type
) :
	name(name),
	description(description),
	type(type) {

}



/**
 *
 */
Configurable::Configurable(QObject* parent) :
	QObject(parent) {

}



/**
 *
 */
Configurable::~Configurable() {

}



/**
 *
 */
Configurable::OptionList Configurable::options() const {
	return OptionList();
}



/**
 *
 */
void Configurable::configure(const QVariantMap& options) {
	Q_UNUSED(options);
}

