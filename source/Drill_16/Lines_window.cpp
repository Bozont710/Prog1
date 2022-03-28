#include "Lines_window.h"

struct Lines_window : Window {
    Lines_window (Point xy, int w, int h, const string& title);
    Open_polyline lines;
private:
    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;

    void next();
    void quit();
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy, w, h, title},
    next_button{Point{x_max()-150, 0}, 70, 20, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();},
    quit_button{Point{x_max-70, 0}, 70, 20, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();},
    next_x{Point{x_max-310, 0}, 50, 20, "Next x:"},
    next_y{Point{x_max-210, 0}, 50, 20, "Next y:"},
    xy_out{Point{100,0}, 100, 20, "current(x,y):"},
    color_menu{Point{x_max()-70, 40}, 70, 20, Menu::vertical, "color"},
    style_menu{Point{x_max()-70, 160}, 70, 20, Menu::vertical, "style"},
    color_button{Point{x_max-70, 40}, 70, 20, "Color menu",
        [](Address, Address pw) {reference_to<Lines_window>(pw).cmenu_pressed()};},
    style_button{Point{x_max-70, 160}, 70, 20, "Style menu",
        [](Address, Address pw) {reference_to<Lines_window>(pw).smenu_pressed()};}

{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    color_menu.attach(new Button(Point{0, 0,}, 0, 0, "red"),
        [](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed()};)
    color_menu.attach(new Button(Point{0, 0,}, 0, 0, "blue"),
        [](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed()};)
    color_menu.attach(new Button(Point{0, 0,}, 0, 0, "black"),
        [](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed()};)
    attach(color_menu);
    attach(color_button);
    color_menu.hide();

    style_menu.attach(new Button(Point{0, 0}, 0, 0, "dot"),
        [](Address, Address pw) {reference_to<Lines_window>(pw).dot_pressed()};)
    style_menu.attach(new Button(Point{0, 0}, 0, 0, "dash"),
        [](Address, Address pw) {reference_to<Lines_window>(pw).dash_pressed()};)
    style_menu.attach(new Button(Point{0, 0}, 0, 0, "solid"),
        [](Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed()};)
    attach(style_menu);
    attach(style_button);
    style_menu.hide();
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x, y});

    ostringstream ss;
    ss << "(" << x << "," << y << ")" << endl;
    xy_out.put(ss.str());

    redraw();
}