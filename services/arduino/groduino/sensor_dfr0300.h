// http://www.dfrobot.com/wiki/index.php/Analog_EC_Meter_SKU:DFR0300

#ifndef SENSOR_DFR0300_H
#define SENSOR_DFR0300_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "support_one_wire.h"
#include "support_moving_average.h"

class SensorDfr0300 {
  public:
    // Public Functions
    SensorDfr0300(int temperature_pin, int ec_pin, int ec_enable_pin, String temperature_instruction_code, int temperature_id, String ec_instruction_code, int ec_id); 
    void begin(void);
    String get(void);
    String set(String instruction_code, int instruction_id, String instruction_parameter);

    // Public Variables
    float temperature; //degrees C
    float ec; //uS/cm
    float ec_avg; //uS/cm

  private:
    // Private Functions
    void getSensorData(void);   
    float getTemperature(void);
    void startTempertureConversion(void);
    float getEc(float temperature);
    float TempProcess(bool ch);
  
    // Private Variables
    int temperature_pin_;
    int ec_pin_;
    int ec_enable_pin_;
    String temperature_instruction_code_;
    int temperature_id_;
    String ec_instruction_code_;
    int ec_id_;
    float ec_coefficient_;
    float ec_offset_;
    float offset_;
    
    byte data_[12];
    byte addr_[8];

    OneWire *ds_;
};

#endif // SENSOR_DFR0300_H_
