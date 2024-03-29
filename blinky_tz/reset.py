import serial
import sys

# Get the input port from the command line argument
port_name = sys.argv[1]

# Create a serial port object
port = serial.Serial(port_name, 115200)

port.write(b"\x00")

port.close()