import socket
import struct
import time

TCP_IP = '192.168.1.115'
TCP_PORT = 8008

buffer_u16 = "H"
buffer_u8 = "b"

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
time.sleep(.1)
message = 50
data = 128
buffer_type = buffer_u8+buffer_u16
buffer = struct.pack('<'+buffer_type,*[message,data])

s.send(buffer)
time.sleep(.1)
s.close()