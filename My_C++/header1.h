#ifndef BOX_H
#define BOX_H

class Box {
private:
	double length{ 1.0 };
	double width{ 1.0 };
	double height{ 1.0 };
public:
	double volume(double num=1);
	double diagonal();
	Box() = default;
	Box(double lengthVal, double widthVal, double heightVal);
};

#endif