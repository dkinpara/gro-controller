#include "actuator_relay.h"

//--------------------------------------------------PUBLIC-------------------------------------------//
ActuatorRelay::ActuatorRelay(int pin, String instruction_code, int instruction_id) {
 pin_ = pin;
 instruction_code_ = instruction_code;
 instruction_id_ = instruction_id;
}

void ActuatorRelay::begin(void) {
 pinMode(pin_,OUTPUT);
 turnOff();
}

String ActuatorRelay::get(void) {
  // Initialize Message
  String message = "";

  // Append Actuator State
  message += "\"";
  message += instruction_code_;
  message += " ";
  message += instruction_id_;
  message += "\":";
  message += value_;
  message += ",";

  // return "";
  return message;
}

String ActuatorRelay::set(String instruction_code, int instruction_id, String instruction_parameter) {
  if ((instruction_code == instruction_code_) && (instruction_id == instruction_id_)) {
    if (instruction_parameter.toInt() == 1) {
      turnOn();
      return "";
    }
    else if(instruction_parameter.toInt() == 0) {
      turnOff();
      return "";
    }
  }
  return "";
}

//-------------------------------------------------PRIVATE-------------------------------------------//
void ActuatorRelay::turnOn(void){
  digitalWrite(pin_, LOW); // active low relay
  value_ = 1;
}

void ActuatorRelay::turnOff(void){
  digitalWrite(pin_, HIGH);
  value_ = 0;
}