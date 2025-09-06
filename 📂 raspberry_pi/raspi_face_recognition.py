import cv2
import face_recognition
import firebase_admin
from firebase_admin import credentials, db
import datetime

# Firebase setup
cred = credentials.Certificate("firebase-key.json")
firebase_admin.initialize_app(cred, {
    'databaseURL': "https://your-database.firebaseio.com/"
})

# Load camera
video_capture = cv2.VideoCapture(0)

# Load known images (replace with actual path)
known_image = face_recognition.load_image_file("patient.jpg")
known_encoding = face_recognition.face_encodings(known_image)[0]

while True:
    ret, frame = video_capture.read()
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    face_locations = face_recognition.face_locations(rgb_frame)
    face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)

    for encoding in face_encodings:
        matches = face_recognition.compare_faces([known_encoding], encoding)
        name = "Unknown"
        if True in matches:
            name = "Patient"

            # Send log to Firebase
            ref = db.reference("logs")
            ref.push({
                "name": name,
                "time": str(datetime.datetime.now())
            })

        cv2.putText(frame, name, (50, 50),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    cv2.imshow("Robo_Care - Face Recognition", frame)

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

video_capture.release()
cv2.destroyAllWindows()
