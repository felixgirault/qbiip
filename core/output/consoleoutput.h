#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H

#include "../output.h"



/**
 *	The ConsoleOutput class
 */
class ConsoleOutput : public Output {

	public:

		ConsoleOutput(QObject* parent = 0);

	public slots:

		void play(const Note& note);

};

#endif // CONSOLE_OUTPUT_H
