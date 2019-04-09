import socket
import json
import sys
import cv2
import numpy as np

UDP_IP = "127.0.0.1"
UDP_PORT = 5555

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))
sock.settimeout(1)

while True:
    try:
        data, addr = sock.recvfrom(4096) # buffer size is 4096 bytes
    except socket.timeout:
        continue
    data = json.loads(data.decode('utf-8'))
    head_pose =  data['head_pose']

    # Create a black image
    h, w = 512, 512
    img = np.zeros((h, w, 3), np.uint8)


    # Draw a diagonal blue line with thickness of 5 px

    img = cv2.circle(img,
                    (w//2, h//2),
                    80+10,
                    (0,255,0),
                    10)

    
    if (abs(head_pose['x']) + abs(head_pose['y']) + abs(200+int(-0.3*head_pose['z']) - 80)) < 10:
        color = (200, 255, 0)
    else:
        color = (0, 0, 255)


    img = cv2.circle(img,
                    (int(-head_pose['x']) + h//2, w//2+int(head_pose['y'])),
                    200+int(-0.3*head_pose['z']),
                     color, -1)

    cv2.imshow('frame',img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()