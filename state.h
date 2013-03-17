#ifndef STATE_H
#define STATE_H

#include <QObject>



/**
 *	The State class.
 */

class State : public QObject {

	Q_OBJECT

	public:

		virtual ~State( ) { }

	public:

		virtual void exec( ) = 0;

};

#endif // STATE_H
