#include "projekt15.h"


int main ( int narg, char* argv[] )
{
/***  gib ggf. Usage aus  ***/

	if ( narg < 2 )
	{
		cout << "Usage: " << argv[ 0 ] << " dateiName"        << endl ;
		cout << "       dateiName: Name einer Quelltextdatei" << endl ;
		cout << "Die Datei wird geoeffnet und auf korrekte"   << endl ;
		cout << "Klammerungen geprueft."                      << endl ;

		return 0 ;
	}

/***  �ffne Datei  ***/

	char const* dateiName = argv[ 1 ] ;
	ifstream    datei( dateiName ) ;

	if ( ! datei )
	{
		cerr << "Kann Datei " << dateiName << " nicht oeffnen!" << endl ;
		return -1 ;		// Fehler aufgetreten
	}
	
/***  pr�fe Klammerungen  ***/

	if ( klammerung( datei ) )
		cout << "Klammerungen sind korrekt!"  << endl ;
	else
		cout << "Eine Klammerung ist falsch!" << endl ;

/***  r�ume auf  ***/

	// schlie�e Datei
	datei.close() ;

	return 0 ;

}  // main()
