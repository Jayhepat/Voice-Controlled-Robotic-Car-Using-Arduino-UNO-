
# Voice-Controlled-Robotic-Car


The Voice Controlled Robotic Car is a project developed using the Arduino UNO platform that enables users to control a robotic vehicle through spoken commands. By integrating voice recognition technology and natural language processing, the system translates speech into directional movement, offering a hands-free interface for robot navigation. This compact, cost-effective, and accessible solution demonstrates the practical application of human-machine interaction and serves educational, experimental, and surveillance purposes. Future enhancements aim to integrate machine learning and advanced sensors for increased adaptability and autonomy.

## Objective
To design a voice-controlled robotic car using Arduino UNO that responds to spoken commands for movement. The project aims to create an affordable, user-friendly system that enhances human-robot interaction using speech recognition and enables hands-free control for increased accessibility and safety.

## Components Used
- **Arduino UNO** – Main microcontroller for controlling the system

- **Voice Recognition V3 Module** – Captures and processes voice commands

- **L298N Motor Driver** – Controls motor direction and speed

- **Gear Motors & Wheels** – Provides movement to the car

- **TPA4056 Charging Module** – Used for safe battery charging

- **LiPo & 3.7V Batteries** – Power source for the car

- **Chassis** – Structural base of the robotic car

- **Jumper Wires & A-to-B Cable** – Electrical connectivity between components

- **Electric Switches & LEDs** – Interface and indicators


## How It Works
The system consists of three main units working together to achieve voice-controlled motion:

1. **Input Unit**
   - Voice Recognition V3 Module:
     Captures and interprets voice commands.
2. **Processing Unit**
   - Arduino UNO (ATmega328P):
     Processes voice input and sends control signals to the motor driver.

3. **Output Unit**
   - L298N Motor Driver + Gear Motors:
     Drives the car based on processed commands.

   - Wheels, LEDs, Switches:
     Facilitate motion and provide feedback.

4. **Power Supply**
   - LiPo / 3.7V Batteries + TPA4056 Module:
     Powers the entire system with safe charging.



## Installation and Setup

**TRAINING CODE Highlights**
*Core Logic:*
- Uses SoftwareSerial to communicate with the voice module:
- Sends command bytes to the voice module to:
  - *Load group*
  - *Train new commands*
  - *Verify if training is successful*
- Commands It Likely Trains:
  - *forward*, *backward*, *left*, *right*

- Example Structure (from training code):
```bash
mySerial.write(0xAA); // Start byte
mySerial.write(0x37); // Command to train
mySerial.write(0x01); // Train command 1
```

**TESTING CODE Highlights**
 *Core Logic:*
- Reads recognized voice commands from the voice module
- Based on the received index (e.g., 0x01 for "forward"), drives the motors
  accordingly
- Uses L298N Motor Driver to send direction and speed signals
- Example Command Mapping:
```bash
if (val == 0x01) {
  forward();
}
else if (val == 0x02) {
  backward();
}
```
-  Motor Control Functions:
```bash
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
```
## Future Scope / Work
The future scope of this project includes several potential enhancements:

- **Integration of Machine Learning Algorithms**
  To improve adaptability and responsiveness to diverse voice commands.

- **Advanced Sensor Integration**
  For enabling autonomous navigation in complex environments.

- **Cloud Computing Capabilities**
  To allow remote control, data storage, and analysis.

- **Expanded Command Vocabulary**
  With Natural Language Processing (NLP) to handle more complex human interactions.

- **Applications in Search and Rescue or Environmental Monitoring**
  Where the robot could operate in inaccessible or hazardous area

## Conclusion
The "Voice Controlled Interactive Robotic Vehicle" project serves as a stepping stone into a future where voice-controlled robotic vehicles play an increasingly integral role in our daily lives.
By harnessing the power of voice commands, the project unlocks a range of possibilities:

- Enhancing accessibility for individuals with disabilities

- Revolutionizing surveillance and reconnaissance tasks

- Showcasing the feasibility of integrating speech recognition with robotics using readily available components

The project demonstrates that voice-controlled navigation is possible and practical using a basic microcontroller like the Arduino UNO and affordable sensors.

## 📚 References

1. **Aditya Chaudhry**, **Manas Batra**, **Prakhar Gupta**, **Sahil Lamba**, **Suyash Gupta**.  
   *Arduino Based Voice Controlled Robot*.  
   *International Conference on Computing, Communication, and Intelligent Systems (ICCCIS)*, 2019.

2. **Ms. Quanitah Shaikh**, **Mr. Rohit Halankar**, **Mr. Akshay Kadle**.  
   *Voice Assisted and Gesture Controlled Companion Robot*.  
   *IEEE Xplore*, Part Number: CFP20K74-ART, ISBN: 978-1-7281-4876-2, 2020.

3. **Dola Sainath Reddy**, **Raynak Vignesh Chowdary**, **Bellam Naveen Kumar**, **M Sai Charan**, **G Vighnesh**.  
   *Voice Control Based Robotic Car Using Arduino Uno*.  
   *International Journal of Novel Research and Development (IJNRD)*, Volume 7, Issue 12, December 2022.  
   ISSN: 2456-4184 | [www.ijnrd.org](https://www.ijnrd.org)

4. **Shubh Srivastava**, **Rajanish Singh**.  
   *Voice Controlled Robot Car Using Arduino*.  
   *International Research Journal of Engineering and Technology (IRJET)*, e-ISSN: 2395-0056, May 2020.
## Data Flow Summary:
```mermaid
flowchart TD
    A[Start] --> B[Power ON]
    B --> C[System Initialization]
    C --> D{Voice Detected?}
    D -- Yes --> E[Process Voice Command]
    E --> F{Valid Command?}
    F -- Yes --> G[Execute Command]
    G --> H[END]
'''
