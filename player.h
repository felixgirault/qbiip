#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "note.h"



/**
 *	The Player class.
 */

class Player : public QObject {

	Q_OBJECT

	public:

		virtual ~Player( ) { }

	public slots:

		virtual void play( const Note& note ) = 0;

};

#endif // PLAYER_H
