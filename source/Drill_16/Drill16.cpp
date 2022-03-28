/*
	g++ Drill16.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill16 `fltk-config --ldflags --use-images`
*/
#include "Graph.h"
#include "Lines_window.h"

int main(){
try {
		Lines_window win { Point { 100, 100 }, 600, 400, "Lines"};
		return gui_main();
	}


catch (exception& e){
		cerr << e.what() << endl;
		return 1;
	}

catch (...){
		cerr << "Unknown error" << endl;
		return 2;
	}
}