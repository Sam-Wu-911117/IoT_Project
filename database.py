from firebase import firebase
import serial 
import time 

url = 'https://iot-project-efb90-default-rtdb.firebaseio.com/'
firebase = firebase.FirebaseApplication(url, None)


ser = serial.Serial('/dev/ttyAMA0',115200 ,timeout=1.0)
ser.reset_input_buffer()

try:
    while True:
        while ser.in_waiting >= 0:
            read = ser.read(1024).decode('utf-8').rstrip()
            
            try:
                data = read.split('\n')
                sensor_data = {}
                for item in data:
                  sensor, value = item.split(':')
                  sensor_data[sensor] = int(value)
               
            except ValueError:
                   print(f"{item}")
                   continue
            print(sensor_data,end="")
              
            firebase.put_async('/','number',{
                'can1':sensor_data['Pressure0'],
                'can2':sensor_data['Pressure1'],
                'can3':sensor_data['Pressure2'],
                'can4':sensor_data['Pressure3'],
                'NowAt':sensor_data['NowAt4']
            })
except KeyboardInterrupt:
        print("Close Serial communication")

