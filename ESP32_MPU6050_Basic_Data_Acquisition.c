/*
Project: Machine Learning Technique for Body Movement Recognition

File: ESP32_MPU6050_Data_Acquisition.c

Description:
This program acquires motion data from the MPU6050 sensor using an
ESP32 development board. The MPU6050 provides accelerometer and
gyroscope readings, which are collected in real time and transmitted
for further processing and analysis.


The acquired sensor data is used for Human Activity Recognition (HAR)
applications, including the classification of activities such as
walking, standing, sitting, and sleeping.

This code represents the data acquisition stage of the project and
demonstrates sensor interfacing.

Developed as part of the B.Tech Minor Project:
"Machine Learning Technique for Body Movement Recognition"

Author(s): Blessy Smitha Das and Team
*/


#include <Wire.h>

const int MPU_ADDR = 0x68; // I2C address of the MPU-6050

// Offset variables for calibration
float ax_offset = 0, ay_offset = 0, az_offset = 0;
float gx_offset = 0, gy_offset = 0, gz_offset = 0;

void setup() {
  Serial.begin(115200);
  
  // Initialize I2C for ESP32. Default SDA = 21, SCL = 22
  Wire.begin(21, 22); 
  
  // Wake up MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0);    // Set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  Serial.println("Calibrating MPU6050... Please keep the sensor stationary.");
  calibrateMPU6050();
  Serial.println("Calibration complete! All axes zeroed out.");
}

void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // Starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true); // Request a total of 14 registers
  
  // Read raw values
  int16_t ax = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  int16_t ay = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  int16_t az = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  int16_t temp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  int16_t gx = Wire.read() << 8 | Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  int16_t gy = Wire.read() << 8 | Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  int16_t gz = Wire.read() << 8 | Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  // Apply calibration offsets to zero out initial readings
  float cal_ax = ax - ax_offset;
  float cal_ay = ay - ay_offset;
  float cal_az = az - az_offset;
  float cal_gx = gx - gx_offset;
  float cal_gy = gy - gy_offset;
  float cal_gz = gz - gz_offset;

  // Print results
  Serial.println("----- Sensor Data -----");
  Serial.print("Accel (x,y,z): ");
  Serial.print(cal_ax); Serial.print(", ");
  Serial.print(cal_ay); Serial.print(", ");
  Serial.println(cal_az);
  
  Serial.print("Gyro (x,y,z):  ");
  Serial.print(cal_gx); Serial.print(", ");
  Serial.print(cal_gy); Serial.print(", ");
  Serial.println(cal_gz);
  
  Serial.println();
  
  delay(4000); // Wait 4 seconds interval as requested
}

void calibrateMPU6050() {
  long sum_ax = 0, sum_ay = 0, sum_az = 0;
  long sum_gx = 0, sum_gy = 0, sum_gz = 0;
  int num_samples = 1000;
  
  // Read 1000 samples to find the average initial values
  for (int i = 0; i < num_samples; i++) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_ADDR, 14, true);
    
    sum_ax += (Wire.read() << 8 | Wire.read());
    sum_ay += (Wire.read() << 8 | Wire.read());
    sum_az += (Wire.read() << 8 | Wire.read());
    Wire.read(); Wire.read(); // skip temp
    sum_gx += (Wire.read() << 8 | Wire.read());
    sum_gy += (Wire.read() << 8 | Wire.read());
    sum_gz += (Wire.read() << 8 | Wire.read());
    
    delay(3);
  }
  
  // Set the offsets to the average values
  ax_offset = (float)sum_ax / num_samples;
  ay_offset = (float)sum_ay / num_samples;
  az_offset = (float)sum_az / num_samples;
  gx_offset = (float)sum_gx / num_samples;
  gy_offset = (float)sum_gy / num_samples;
  gz_offset = (float)sum_gz / num_samples;
}
