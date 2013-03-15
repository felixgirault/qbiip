#ifndef NETWORKOUTPUTTER_H
#define NETWORKOUTPUTTER_H

#include "outputter.h"

class Server;



/**
 *	The NetworkOutputterDecorator class.
 */

class NetworkOutputter : public Outputter
{
	public:

		/**
		 *	@brief NetworkOutputterDecorator
		 */

		NetworkOutputter( Server* server );

	public slots:

		/**
		 *
		 */

		void output( const Note& note );

	private:

		Server* _server;

};

#endif // NETWORKOUTPUTTER_H
