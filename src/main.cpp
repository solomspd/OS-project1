//
// Created by solom on 3/28/20.
//

#include <iostream>

#include <gtkmm.h>
#include "node.h"

int main(int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv,"org.gtkmm.examples.base");

	Gtk::Window window;
	window.set_default_size(200, 200);

	node *start = new node("/");
	start->traverse(start);

	return app->run(window);
}