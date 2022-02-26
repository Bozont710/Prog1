/*
	g++ Drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill13 `fltk-config --ldflags --use-images`
*/
#include "Graph.h"
#include "Simple_window.h"


int main(){

	Point tl {100, 100};

	Simple_window win{tl, 800, 1000, "Drill13"};

	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x = x_grid; x<=x_size; x += x_grid )
		grid.add(Point{x,0}, Point{x,y_size});
	for (int y = y_grid; y<=y_size; y += y_grid )
		grid.add(Point{0,y}, Point{x_size,y});

	Vector_ref<Rectangle> rect;

	for( int i = 0; i < 900; i += x_grid )
		for( int j = 0; j < 900; j += y_grid ){
			if(i = j){
				rect.push_back(new Rectangle{Point{i-100, j-100}, 100, 100});
				rect[rect.size()-1].set_fill_color(Color::red);
				win.attach(rect[rect.size()-1]);
			}
	
	}

	Image i1 {Point{0, 200}, "images.jpeg"};
	i1.set_mask(Point{25, 25}, 200, 200);

	Image i2 {Point{200, 0}, "images.jpeg"};
	i2.set_mask(Point{25, 25}, 200, 200);

	Image i3 {Point{400, 0}, "images.jpeg"};
	i3.set_mask(Point{25, 25}, 200, 200);

	Image i4 {Point{0, 0}, "100.jpg"};
	i4.set_mask(Point{100, 100}, 100, 100);


	win.attach(grid);
	win.attach(i1);
	win.attach(i2);
	win.attach(i3);
	win.attach(i4);
	
	for (int y = 0; y < 8; ++y){
		for (int x = 0; x < 8; ++x ){
			win.wait_for_button();
			i4.move(100, 0);
		}
	i4.move(-800, 100);
	}
	
	
}