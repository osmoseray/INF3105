	#include "Heure_8_A_1.h"
    #include <iostream> 

	// get the trike’s speed
	int Tricycle::getSpeed()
	 {
	 return speed;
	 }
	 // set the trike’s speed
	 void Tricycle::setSpeed(int newSpeed)
	 {
	 if (newSpeed >= 0)
	 {
	 speed = newSpeed;
	 }
	}

	void Tricycle::pedal()
 {
 setSpeed(speed + 1);
 std::cout << “\nPedaling; tricycle speed “ << speed << “ mph\n”;
}

 // apply the brake on the trike
 void Tricycle::brake()
 {
 setSpeed(speed - 1);
 std::cout << “\nBraking; tricycle speed “ << speed << “ mph\n”;
 }

 // create a trike and ride it
 int main()
 {
Tricycle wichita;
 wichita.setSpeed(0);
 wichita.pedal();
 wichita.pedal();
 wichita.brake();
 wichita.brake();
 wichita.brake();
 Tricycle t;
 t.setSpeed(100);
 t.pedal();
 t.pedal();
 t.pedal();
 t.pedal();
 t.brake();
 return 0;
}