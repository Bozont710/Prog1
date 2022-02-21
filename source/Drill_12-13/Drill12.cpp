/*
	g++ Drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill12 `fltk-config --ldflags --use-images`
*/
#include "Graph.h"
#include "Simple_window.h"


int main(){

using namespace Graph_lib;


	Point tl {100, 100};

	Simple_window win {tl, 600, 400, "Canvas"};
	
	Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};
	Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};

	ya.set_color(Color::cyan);
	ya.label.set_color(Color::red);

	Polygon poly;
	poly.add(Point{50, 50});
	poly.add(Point{100, 50});
	poly.add(Point{75, 100});

	poly.set_color(Color::dark_red);
	poly.set_fill_color(Color::dark_red);
	poly.set_style(Line_style::dash);

	Circle c1 {Point{63, 50}, 12};
	Circle c2 {Point{88, 50}, 12};

	c1.set_color(Color::dark_red);
	c1.set_fill_color(Color::dark_red);
	c1.set_style(Line_style::dash);

	c2.set_color(Color::dark_red);
	c2.set_fill_color(Color::dark_red);
	c2.set_style(Line_style::dash);

	Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};

	Image i1 {Point{200, 200}, "images.jpeg"};
	Image i2 {Point{400, 400}, "getbaited.gif"};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100, 20}, oss.str()};

	Closed_polyline poly1;

	poly1.add(Point{100, 100});
	poly1.add(Point{100, 200});
	poly1.add(Point{200, 200});
	poly1.add(Point{200, 100});

	poly1.set_style(Line_style::dashdotdot);

	Rectangle r (Point{300, 300}, 100, 50);

	Text t {Point{150, 150}, "I don't know what I'm doing!"};

	Ellipse e {Point{100, 100}, 10, 25};

	win.attach(e);
	win.attach(t);
	win.attach(r);
	win.attach(poly1);
	win.attach(i1);
	win.attach(i2);
	win.attach(sine);
	win.attach(c1);
	win.attach(c2);
	win.attach(poly);
	win.attach(xa);
	win.attach(ya);
	win.attach(sizes);

	win.set_label("Canvas#2");

	win.wait_for_button();


	
}