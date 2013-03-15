#include <QtGlobal>

#if defined( Q_OS_UNIX )
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#elif defined( Q_OS_WIN )
#include <windows.h>
#endif

#include "speakeroutputter.h"
#include "exception.h"



/**
 *
 */

SpeakerOutputter::SpeakerOutputter( ) {

#ifdef Q_OS_UNIX
	_console = open( "/dev/console", O_WRONLY );

	if ( _console == -1 ) {
		throw new Exception(
			"Unable to use the speaker, try to run biip as root."
		);
	}
#endif
}



/**
 *
 */

SpeakerOutputter::~SpeakerOutputter( ) {

#ifdef Q_OS_UNIX
	close( _console );
#endif
}



/**
 *
 */

void SpeakerOutputter::output( const Note& note ) {

#if defined( Q_OS_UNIX )
	ioctl( _console, KIOCSOUND, ( int )( TICK / note.frequency ));
	usleep( note.duration * 1000 );
	ioctl( _console, KIOCSOUND, 0 );
#elif defined( Q_OS_WIN )
	Beep( note.frequency, note.duration );
#else
	Q_UNUSED( note );
#endif
}
