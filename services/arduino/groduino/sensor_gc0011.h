// Library based off: Cozir Example Sketch from CO2Meter.com
// Library found at: http://www.co2meters.com/Documentation/AppNotes/AN128-%20Cozir_Arduino.pdf
// Component found at: http://www.co2meter.com/products/cozir-0-2-co2-sensor
// Modified by Jake Rye
// July 15, 2015

#ifndef SENSOR_GC0011_H
#define SENSOR_GC0011_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "support_software_serial.h"

class SensorGc0011 {
  public:
    // Public Functions
    SensorGc0011(int rx_pin, int tx_pin, String co2_instruction_code, int co2_instruction_id,String temperature_instruction_code, int temperature_instruction_id,String humidity_instruction_code, int humidity_instruction_id);
    void begin(void);
    String get(void);
    String set(String instruction_code, int instruction_id, String instruction_parameter);

    // Public Variables
    float temperature_;
    float humidity_;
    float co2_;
   
  private:
    // Private Functions
    void getSensorData(void);
    void sendMessage(String message);
    String receiveMessage();
    String floatToString(double val, unsigned int precision);

    // Private Variables
    int rx_pin_;
    int tx_pin_;
    String co2_instruction_code_;
    int co2_instruction_id_;     
    String temperature_instruction_code_;
    int temperature_instruction_id_;   
    String humidity_instruction_code_;
    int humidity_instruction_id_; 
    SoftwareSerial *ss_;
    uint32_t timeout_;
};

#endif // SENSOR_GC0011_H_