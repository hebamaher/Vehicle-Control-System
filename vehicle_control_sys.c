#include <stdio.h>
#include <stdlib.h>

#define OFF 0
#define ON 1

void Menu();
void SensorsSetMenu();
void SetTrafficLight();
void VehicleSpeed(int num);
void SetRoomTemp();
void SetEngineTemp();
void Display();

struct Vehicle{
	int vehicle_speed;
	float room_temp;
	float eng_temp;
	char ac_state;
	char eng_temp_controller;
	char eng_state;
}V;


void Menu(){
	char menu_option;
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	fflush(stdout);
	scanf(" %c",&menu_option);
	switch(menu_option){
	case 'a':
		V.eng_state = ON;
		printf("Turn on the vehicle engine\n");
		SensorsSetMenu();
		break;
	case 'b':
		V.eng_state = OFF;
		printf("Turn off the vehicle engine\n");
		Menu();
		break;
	case 'c':
		printf("Quit the system\n");
		exit(0);
		break;
	}
}

void SensorsSetMenu(){
	char sensors_menu_option;
	printf("a.Turn off the engine\n");
	printf("b.Set the traffic light color\n");
	printf("c.Set the room temperature\n");
	printf("d.Set the engine temperature\n");
	fflush(stdout);
	scanf(" %c",&sensors_menu_option);
	switch(sensors_menu_option){
	case 'a':
		V.eng_state = OFF;
		printf("a.Turn off the engine\n");
		Menu();
		break;
	case 'b':
		SetTrafficLight();
		Display();
		SensorsSetMenu();
		break;
	case 'c':
		SetRoomTemp();
		Display();
		SensorsSetMenu();
		break;
	case 'd':
		SetEngineTemp();
		Display();
		SensorsSetMenu();
		break;
	}
}


void SetTrafficLight(){
	char traffic_option;
	printf("Enter the required color\n");
	fflush(stdout);
	scanf(" %c",&traffic_option);
	switch(traffic_option){
	case 'G':
	case 'g':
		VehicleSpeed(100);
		break;
	case 'O':
	case 'o':
		VehicleSpeed(30);
		break;
	case 'R':
	case 'r':
		VehicleSpeed(0);
		break;
	}
}

void VehicleSpeed(int num){
	V.vehicle_speed = num;
	if(num == 30){
			V.ac_state = ON;
			V.room_temp = V.room_temp * (5.0/4) + 1;

			V.eng_temp_controller = ON;
			V.eng_temp = V.eng_temp * (5.0/4) + 1;

	}
}

void SetRoomTemp(){
	printf("Enter the required room temperature\n");
	fflush(stdout);
	scanf(" %f",&V.room_temp);

	if(V.vehicle_speed == 30){
		VehicleSpeed(30);
		return;
	}
	if(V.room_temp < 10 || V.room_temp > 30){
		V.ac_state = ON;
		V.room_temp = 20;
	}
	else{
		V.ac_state = OFF;
	}
}

void SetEngineTemp(){
	printf("Enter the required engine temperature\n\n");
	fflush(stdout);
	scanf(" %f",&V.eng_temp);

	if(V.vehicle_speed == 30){
		VehicleSpeed(30);
		return;
	}
	if(V.eng_temp < 100 || V.eng_temp > 150){
		V.eng_temp_controller = ON;
		V.eng_temp = 125;
	}
	else{
		V.eng_temp_controller = OFF;
	}
}

void Display(){
	if(V.eng_state == ON){
		printf("Engine state: ON\n");
	}
	else{
		printf("Engine state: OFF\n");
	}
	if(V.ac_state == ON){
		printf("AC state: ON\n");
	}
	else{
		printf("AC state: OFF\n");
	}
	printf("Vehicle Speed: %d\n",V.vehicle_speed);
	printf("Room Temperature: %f\n",V.room_temp);
	if(V.eng_temp_controller == ON){
		printf("Engine Temperature Controller State: ON\n");
	}
	else{
		printf("Engine Temperature Controller State: OFF\n");
	}
	printf("Engine Temperature: %f\n",V.eng_temp);
}

int main(void) {
	V.vehicle_speed = 0;
	V.room_temp = 26;
	V.eng_temp = 30;
	V.ac_state = OFF;
	V.eng_temp_controller = OFF;
	V.eng_state = OFF;
	
	Menu();
	
}
