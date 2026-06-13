Software Used

Overview
The Body Movement Recognition System integrates IoT, cloud computing, data processing, machine learning, and web-based deployment technologies. Multiple software platforms were utilized for data collection, storage, preprocessing, model training, and testing.

---

1. Arduino IoT Cloud

Arduino IoT Cloud was used as the central platform for collecting and storing sensor data transmitted by the ESP32.

Functions
- Real-time sensor data collection
- Cloud-based data storage
- Device monitoring
- Data management

Purpose in the Project

The ESP32 continuously uploaded motion sensor readings to the Arduino IoT Cloud, enabling centralized and organized data collection for machine learning analysis.

---

2. Python

Python served as the primary programming language for data processing, machine learning model development, and activity classification.

Functions
- Data processing
- Data analysis
- Machine learning implementation
- Activity prediction

Advantages
- Extensive machine learning libraries
- Easy integration with cloud platforms
- Efficient data handling capabilities

---

3. Google Colab

Google Colab was utilized for machine learning model development and training.

Functions
- Cloud-based model training
- Dataset processing
- Performance evaluation
- Experiment management

Purpose in the Project
Using Google Colab enabled access to cloud computing resources without requiring dedicated local hardware, allowing efficient model training and testing.

---

4. JSON Data Processing

Sensor data collected from the Arduino IoT Cloud was extracted and converted into JSON format.

Functions
- Structured data storage
- Dataset generation
- Data transfer between platforms

Purpose in the Project
The generated JSON files served as the input dataset for machine learning preprocessing and training workflows.

---

5. Machine Learning Framework

Machine learning techniques were employed to classify human activities based on sensor-generated motion data.

Functions
- Feature extraction
- Pattern recognition
- Activity classification
- Performance evaluation

Activities Classified
- Walking
- Standing
- Sitting
- Sleeping

Performance
The trained model achieved an average classification accuracy of approximately 72%.

---

6. Gradio

Gradio was used for testing and demonstrating the trained machine learning model through a web-based user interface.

Functions
- Interactive user interface
- Real-time prediction testing
- Web deployment

Purpose in the Project

The trained model was deployed through a Gradio interface, allowing users to interact with the system and validate activity recognition results through a publicly accessible link.

---

Software Workflow

Sensors
↓
ESP32
↓
Arduino IoT Cloud
↓
JSON Dataset Generation
↓
Python Data Processing
↓
Google Colab Model Training
↓
Machine Learning Model
↓
Gradio User Interface
↓
Activity Prediction

---

Summary

The software architecture combines IoT cloud services, data processing tools, machine learning frameworks, and web-based deployment platforms to create a complete Human Activity Recognition system. This integrated workflow enables efficient data collection, cloud-based model training, and real-time activity classification.
