#include <iostream>

int main()
{
// set up width and length
 unsigned short width = 5, length,height;
 length = 10;
 height = 15;
 // create an unsigned short initialized with the
 // result of multiplying width by length
 unsigned short area = width * length * height;

 std::cout << "Width: " << width << "\n";
 std::cout << "Length: " << length << "\n";
 std::cout << "height: " << height << "\n";
 std::cout << "Area:" << area << "\n";
 return 0;
}