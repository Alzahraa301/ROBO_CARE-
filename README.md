 Robo_Care – Assistive System for Alzheimer’s Patients

Robo_Care is a smart assistive system designed to support Alzheimer’s patients by combining **Arduino hardware**, **Raspberry Pi (AI & face recognition)**, and a **mobile app connected with Firebase**.  
The system automates daily routines, monitors vital signs, provides real-time caregiver alerts, and helps patients stay connected with their families.

---

 Core Features
- Routine Scheduling – Arduino + RTC module for daily reminders and servo-controlled tasks.  
- Facial Recognition – Raspberry Pi + OpenCV + `face_recognition` to recognize caregivers/patients.  
- Health Monitoring – Heart rate sensor connected to Arduino, data sent to Raspberry Pi.  
- Mobile App (Thunkable + Firebase) 
  - Medication reminders.  
  - Daily health reports sent to caregivers.  
  - Chat/notification system for emergency updates.  
- Cloud Integration (Firebase) – Secure real-time storage for patient routines, vitals, and reports.  

---

🛠 Hardware Setup
- Arduino Uno (or compatible board)  
- Raspberry Pi (tested on Pi 4, works on Pi 3B+)  
- DS3231 RTC module  
- Heart rate sensor (Pulse sensor or MAX30100)  
- Servo motors + driver  
- Camera module (for Raspberry Pi facial recognition)  
- LCD display (for local info)  


