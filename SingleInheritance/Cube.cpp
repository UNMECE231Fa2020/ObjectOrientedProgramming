#include <iostream>
#include "cube.hpp"


Cube::Cube() : Rectangle(), _depth{1}, 
		_surface_area{6}, _volume{1} { 
}

Cube::Cube(int length, int width, int depth) : 
		Rectangle(length, width), _depth{1} {
	set_depth(depth);
	calculate_surface_area();
	calculate_volume();
}

Cube::Cube(const Cube &c) : Rectangle(c._length, c._width), 
		_depth{c._depth},
		_surface_area{c._surface_area}, 
		_volume{c._volume} { 
}

Cube::~Cube() { }

int Cube::depth() const {
	return _depth;
}

int Cube::surface_area() const {
	return _surface_area;
}

int Cube::volume() const {
	return _volume;
}

void Cube::set_length(int length) {
	Rectangle::set_length(length);
	calculate_surface_area();
	calculate_volume();
}

void Cube::set_width(int width) {
	Rectangle::set_width(width);
	calculate_surface_area();
	calculate_volume();
}

void Cube::set_depth(int depth) {
	if (depth > 0) {
		_depth = depth;
	}
	calculate_surface_area();
	calculate_volume();
}

void Cube::calculate_surface_area() {
	_surface_area = 2 * (area()) \
		+ 2 * (length() * depth()) \
		+ 2 * (width() * depth());
}

void Cube::calculate_volume() {
	_volume = length() * width() * depth();
}

void Cube::print() const {
	std::cout << length() << ' ' << width() << ' ';
	std::cout << depth() << ' ';
	std::cout << surface_area() << ' ' << volume() << '\n';
}

Cube Cube::operator+(const Cube &c) {
	Cube temp;
	temp._length = length() + c.length();
	temp._width = width() + c.width();
	temp.set_depth(depth() + c.depth());
	return temp;
}

Cube Cube::operator*(int i) {
	Cube temp;
	temp.set_length(length() * i);
	temp.set_width(width() * i);
	temp.set_depth(depth() * i);
	return temp;
}

Cube &Cube::operator=(const Cube &c) {
	_length = c.length();
	_width = c.width();
	set_depth(c.depth());
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Cube &c) {
	out << c._length << ' ' << c._width << ' ';
	out << c._depth << ' ';
	out << c._surface_area << ' ' << c._volume;
	return out;
}
