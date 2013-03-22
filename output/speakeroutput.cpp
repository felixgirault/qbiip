#include <QtGlobal>

#if defined( Q_OS_UNIX )
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#elif defined( Q_OS_WIN )
#include <windows.h>
#endif

#include "speakeroutput.h"
#include "exception.h"
#include "factory.h"



/**
 *
 */

REGISTER_PRODUCT(
	Output,
	SpeakerOutput,
	"speaker",
	"Plays notes with the motherboard speaker."
)



/**
 *
 */

SpeakerOutput::SpeakerOutput( QObject* parent ) :
	Output( parent ) {

#ifdef Q_OS_UNIX
	_console = open( "/dev/console", O_WRONLY );

	if ( _console == -1 ) {
		throw Exception(
			"Unable to use the speaker, please run qbiip as root."
		);
	}
#endif
}



/**
 *
 */

SpeakerOutput::~SpeakerOutput( ) {

#ifdef Q_OS_UNIX
	close( _console );
#endif
}



/**
 *
 */

void SpeakerOutput::play( const Note& note ) {

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
