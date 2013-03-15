#include <QDebug>

#include "consoleplayer.h"



/**
 *
 */

void ConsolePlayer::play( const Note& note ) {

	qDebug( ) << note.frequency << ":" << note.duration;
}
