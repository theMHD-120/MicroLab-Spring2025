# MicroLab-Spring2025
>>> Microcontrollers Laboratory - Spring 2025

||| In the name of Allah ||| <br />
Contents presented in the Microcontrollers Laboratory course at the Department of Computer Science Engineering (CSE), Shiraz University, Spring 2025. <br />
The main objective of this course is to review basic topics in microcontrollers, familiarize with microcontroller programming, and provide a basic understanding of their various applications in the electronics industry (such as the Internet of Things (IoT), Quadcopter (helishot, ...) control, etc.); the main focus is on programming and coding microcontrollers (high-level instructions) for computational and control tasks. 

**Note: this repository only contains the programs written for each test and to access educational materials (slides, videos, etc.), visit the following links ...**

**Course Features:**
- The Arduino framework (the <code>Arduino.h</code> library) is used to program both Arduino-based and ESP32-based development boards.
- In the first five sections,  fundamental microcontroller concepts are explored using the Arduino Uno R3 development board, which is based on the ATmega328P microcontroller.
- Also, in the final two sections, more practical microcontroller topics (Internet connection and communication) are explored using the ESP32-WROOM-32 module, integrated on the DOIT ESP32 DEVKIT V1 development board.

**Professor:**
- Dr. Farshad Khunjush
  
**Providers (TAs):**
- Sepehr Azhdari ([@azhdarii](https://github.com/azhdarii))
- Seyed Mahdi Mahdavi Mortazavi ([@theMHD-120](https://github.com/theMHD-120))

<br />

## Arduino UNO R3 

<br />![Arduino Get Started](https://github.com/theMHD-120/MicroLab-Spring2025/blob/276a47a9f6e14d625762c3d178d1a7aba0759d9d/Arduino%20(UNO%20R3)/arduino-get-started-logo.svg)
<br />
#### Arduino UNO R3 Datasheet [link](https://drive.google.com/file/d/1qiaowyIxvhFONQLKYifag1sKoz3MPgxr/view?usp=sharing)
<br />

### Section 1 - Arduino intro & General IO devices
**Content provided:**
- Basic videos:
  - PlatformIO installation link
  - Course introduction [link](https://drive.google.com/file/d/1NQF94yWUDEyneCfP4RTmwCZSdzIJdG-n/view?usp=sharing)
- Introduction to Arduino UNO:
  - Canva publick view [link](https://www.canva.com/design/DAGhLHhtPn8/tj5uUmWQ1uDRQcbmH4uYIA/view?utm_content=DAGhLHhtPn8&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h2e096e47c3)
  - PDF [link](https://drive.google.com/file/d/1hW_fd6I6SuSR0mSpq4YUz-pJHqwpwPDm/view?usp=sharing)
- Main content    
  - Canva publick view [link](https://www.canva.com/design/DAGg3OlQojs/r9zFD8eU16jt_K4U1MJPjA/view?utm_content=DAGg3OlQojs&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h7513a31bfc)
  - PDF [link](https://drive.google.com/file/d/1BeGIuFjDldeWwSbn1EGWh3k3h2_FfQ01/view?usp=sharing)

**Test performed:**
- Turning ON an LED with a push-button & pull-down resistor

<br />

### Section 2 - Push button states & PWM
**Content provided:**
- Canva publick view [link](https://www.canva.com/design/DAGjRY4AkSE/RXoEpOyIN_eVSMBpDlvxmA/view?utm_content=DAGjRY4AkSE&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=hf274450b30#7)
- PDF [link](https://drive.google.com/file/d/1xAgcppeKe8aA__9eMCbrW22busO3XQQ4/view?usp=sharing)

**Tests performed:**
- Toggle the LED state and modifying (correcting) its functionality using <code>delay()</code> instruction & Two flags
  - The best delay value is achieved through trial and error (due to the spring structure of the push-button, its value may vary)
  - Two flags for previous & current state of push-button
  - This method works for push-button with both types of resistors (pull-up and pull-down); you can check  
- Design a three-bit counter that counts with each click on the push-button
  - Using previous push-button modifications (delay and flags)
- Adjusting LED brightness using Pulse-Width-Modulation (PWM as a timer/counter mode)
  - The output is based on the duty cycle (to adjust LED brightness, armature speed, or...)

<br />

### Section 3 - The Serial communication feature
**Content provided:**
- Canva publick view [link](https://www.canva.com/design/DAGkIHUE7HI/ufmnT9i3kL-Z994-q75gwA/view?utm_content=DAGkIHUE7HI&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=habdb5c5a64)
- PDF [link](https://drive.google.com/file/d/1iLs9HTNM4fbQ4QSHL8McAJpe4orvyfSD/view?usp=sharing)
- Review of UART protocol commands:
  - Video [link](https://drive.google.com/file/d/1yyAbaujDyBLNi8c2ACwc9cjFka41WoFP/view?usp=sharing) 

**Tests performed:**
- Adjusting LED brightness using PWM whose value is determined by serial input
  - Displaying PWM waveforms on the oscilloscope with different duty-cycles (watch here)
- Duplex communication (chat) between two computers (systems) using two Arduino UNO boards
  - One Arduino as the transmitter and another Arduino as the receiver (and vice versa)
  - Serial.h: The main serial interface for communication between Arduino and our systems
  - SoftwareSerial.h: The virtual serial interface for communication between two Arduino boards
  - Note: To connect two Arduino boards, they must have a common ground

<br />

### Section 4 - RGB LED interfacing (ADC preview)
**Content provided:**
- Canva publick view [link](https://www.canva.com/design/DAGmabzd5tY/C6HXeW7UTUQ9xxLqCyyEdA/view?utm_content=DAGmabzd5tY&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h8520a416c3)
- PDF [link](https://drive.google.com/file/d/10idQ2qDbPSuzAQTr09sa5DSXeG2Rogu4/view?usp=sharing)

**Tests performed:**
- Switching between Red-Green-Blue colors and their paired-combinations, like a 3-bit counter
- Switching between Red-Green-Blue colors and their paired-combinations, using a Potentiometer
  - Using a Potentiometer to get analog input
  - Input range value (as digital value): 0-1023 

<br />

### Section 5 - ADC & Analog processing
**Content provided:**
- Canva publick view [link](https://www.canva.com/design/DAGniUkalic/gdKrg_XEj5Rqw-2wJF7-Vg/view?utm_content=DAGniUkalic&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h5093af7813)
- PDF [link](https://drive.google.com/file/d/1HC2sMnRcytwEDai-5GOHIn-vSsIpwtmD/view?usp=sharing)

**Tests performed:**
- Switching between RGB colors with fading (using a potentiometer as in section 4)
- Setting up the duty cycle for an output device (LED, armature or ...) using a Photocell and monitoring the input voltage & digital value
  - Using Photocell (in code) is like using Potentiometer (both as analog inputs)

<br />

### UNO R3 Pinuot

![UNO R3 Schematic](https://github.com/theMHD-120/MicroLab-Spring2025/blob/52e60a5b85a50e0807ed637e16060c56cc4d795f/Arduino%20(UNO%20R3)/UNO%20R3%20Pinout.png)

<br />

## DOIT ESP32 DEVKIT V1

<br /> <img src="https://github.com/theMHD-120/MicroLab-Spring2025/blob/2c358aa393cb4bf46045a379d26bb7e93572e47d/ESP32%20(DOIT%20DEVKIT%20V1)/espressif-logo.svg" width=650>
<br />
#### DOIT ESP32 DEVKIT V1 Datasheet [link](https://drive.google.com/file/d/1TWnD6fC4lQlYcwXiGL_oT-lg1jtFSdB1/view?usp=sharing)
<br />

### Section 6 - Getting started with ESP32 & WiFi connection
**Content provided:**
- Introduction to ESP32:  
  - Canva publick view [link](https://www.canva.com/design/DAGoEsV-TJ0/_Als3Q9kh6-sl3G9EnTFXA/view?utm_content=DAGoEsV-TJ0&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h9c4477d0a2#2)
  - PDF [link](https://drive.google.com/file/d/1tunYROoizPLknInCQAwf1X-i60jwagSf/view?usp=sharing)
- Main content:
  - Canva publick view [link](https://www.canva.com/design/DAGoReAoYPw/NQ2DqZ6t-h50hczArSH8Kg/view?utm_content=DAGoReAoYPw&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=hb5c019d11c)
  - PDF [link](https://drive.google.com/file/d/1lLBe-Mp9HOVXGCtDRKtXYO_soDVtKfgi/view?usp=sharing)

**Test performed:**
- Sending GET and POST requests to a desired server (ESP32 as a client)
  - GET request: A GET request in simple terms is a way to get data from a data source (server) over the internet
  - POST request: A POST request in HTTP is used to send data to a server typically to create or update a resource

<br />

### Section 7 - Build your own Web Server
**Content provided:**
- Main content:
  - Canva publick view [link](https://www.canva.com/design/DAGow1au9-4/WGTHUWFKQZgF3xll34tsZw/view?utm_content=DAGow1au9-4&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=hbcae30fb4d#7)
  - PDF [link](https://drive.google.com/file/d/1BS5zDQfUwJELRzmX5GoEdEer1q-YwTaz/view?usp=sharing)
- Basic introduction to ***Quadcopters*** (for acquaintance):
  - Description link (voice)
  - Featured website link (in voice)

**Tests performed:**
- Running a web server on the ESP32 board (web server initialization)
  - Using <code>WebServer.h</code> library
- RGB lighting with user-controlled remote control
  - Remote control is done via an HTML page
  - ESP32 as a web server can be in Access Point (AP) and Station modes
  - To view the output result of this test, click here

<br />

### DOIT DEVKIT V3 Pinuot

![DOIT DEVKIT V1 Schematic](https://github.com/theMHD-120/MicroLab-Spring2025/blob/8420930aceae44de168c0906e810150dc6ea5f32/ESP32%20(DOIT%20DEVKIT%20V1)/DOIT%20DEVKIT%20V1%20Pinout.png)
