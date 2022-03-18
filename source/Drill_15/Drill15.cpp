/*
	g++ Drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill15 `fltk-config --ldflags --use-images`
*/
#include "Graph.h"
#include "Simple_window.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return slope(x) + cos(x); }

int main(){

	using namespace Graph_lib;

	Point tl {100,100};

	Simple_window win {tl, 600, 600, "Function graphs."};

	Axis xa {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels."};
	Axis ya {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels."};

	xa.set_color(Color::red);
	ya.set_color(Color::red);

	const int r_min = -10;
	const int r_max = 11;

	const int num_p = 400;

	const int x_scale = 20;
	const int y_scale = 20;

	const Point orig {300, 300};

	Function f1 {one, r_min, r_max, orig, num_p, x_scale, y_scale};
	Function f2 {slope, r_min, r_max, orig, num_p, x_scale, y_scale};
	Function f3 {square, r_min, r_max, orig, num_p, x_scale, y_scale};
	Function f4 {cos, r_min, r_max, orig, num_p, x_scale, y_scale};
	Function f5 {sloping_cos, r_min, r_max, orig, num_p, x_scale, y_scale};

	Text tf1 {Point(100, num_p-20), "x/2"};
	f4.set_color(Color::blue);

	win.attach(xa);
	win.attach(ya);
	win.attach(f1);
	win.attach(f2);
	win.attach(tf1);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);

	win.wait_for_button();

}