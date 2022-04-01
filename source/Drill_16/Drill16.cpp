//g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o drill16 `fltk-config --ldflags --use-images`

#include "Lines_window.h"
#include "Graph.h"
int main()
{
	try
	{
		Lines_window ablak {Point{100,100},1000,800,"lines"};
		return gui_main();
	}	
catch (exception&e)
{
	cerr<<"error: "<<e.what()<<'\n';
	return 1;
}
catch(...)
{
	cerr<<"Unknow error."<<'\n';
	return 2;
}
}
