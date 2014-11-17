#ifndef CONSOLE_INPUT_H
#define CONSOLE_INPUT_H

#include "../input.h"
#include "../frequencies.h"



/**
 *	The ConsoleInput class
 */
class ConsoleInput : public Input {

	public:

		ConsoleInput(QObject* parent = 0);

		void play();
		void stop();

	private:

		Frequencies _frequencies;

};

#endif // CONSOLE_INPUT_H
