#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QHBoxLayout;
class Input;
class Output;



/**
 *	The MainWindow class
 */

class MainWindow : public QMainWindow {

	Q_OBJECT

	public:

		MainWindow( QWidget* parent = 0 );

	private:

		void setup( );

		template< class Type >
		void buildSelector( const QString& title ) const;

	private:

		QHBoxLayout* _layout;

		Input* _input;
		Output* _output;

};

#endif // MAINWINDOW_H
