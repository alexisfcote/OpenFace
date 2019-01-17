import socket
import json
import sys

UDP_IP = "127.0.0.1"
UDP_PORT = 5556

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))
sock.settimeout(1)

while True:
    try:
        data, addr = sock.recvfrom(4096) # buffer size is 4096 bytes
    except socket.timeout:
        continue
    print(sys.getsizeof(data))
    print(json.loads(data.decode('utf-8')))
