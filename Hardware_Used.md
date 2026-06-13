Hardware Used

Overview:
The Body Movement Recognition System was developed using wearable sensing hardware capable of capturing human motion data in real time. The collected sensor information was transmitted through an ESP32-based acquisition system and later processed using machine learning techniques for activity recognition.

1. ESP32 Development Board
The ESP32 served as the primary data acquisition and communication unit of the system.

Functions
- Collection of sensor data
- Wireless data transmission
- Communication with Arduino IoT Cloud
- Real-time monitoring support

Key Features:
- Built-in Wi-Fi and Bluetooth
- Low power consumption
- High processing capability
- Suitable for IoT applications

Purpose in the Project:
The ESP32 continuously acquired motion data from the connected sensors and uploaded the information to the cloud platform for further processing and analysis.

2. Accelerometer Sensor
The accelerometer was used to measure linear acceleration along multiple axes.

Functions:
- Detection of body movement
- Motion tracking
- Activity monitoring

Parameters Measured:
- X-Axis Acceleration
- Y-Axis Acceleration
- Z-Axis Acceleration

Purpose in the Project
The accelerometer data provided information about movement intensity and direction, enabling the machine learning model to distinguish between different physical activities.

3. Gyroscope Sensor
The gyroscope was used to measure angular velocity and rotational movement.

Functions:
- Orientation tracking
- Motion analysis
- Rotational movement detection

Parameters Measured:
- Roll
- Pitch
- Yaw

Purpose in the Project:
Gyroscope readings complemented the accelerometer data, improving activity recognition accuracy by capturing rotational body movements.

4. Wearable Sensor Unit
The sensing components were integrated into a compact wearable configuration to enable continuous monitoring of user activities.

Functions:
- Real-time motion sensing
- Portable operation
- Continuous activity monitoring

Advantages:
- Lightweight design
- Easy deployment
- User-friendly implementation

5. Power Supply System
A regulated power source was used to ensure stable operation of the sensing and communication hardware.

Functions
Powering the ESP32
Supporting continuous sensor operation
Maintaining reliable data acquisition
Hardware Workflow
Accelerometer + Gyroscope
            │
            ▼
         ESP32
            │
            ▼
   Arduino IoT Cloud
            │
            ▼
      Data Storage

Summary:
The hardware architecture combines wearable motion sensors with an ESP32-based IoT platform to enable real-time acquisition and transmission of human activity data. This lightweight and portable design forms the foundation of the machine learning-based activity recognition system.
