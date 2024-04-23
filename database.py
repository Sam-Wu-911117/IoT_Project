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
            
            data = read.split(',')

            
            sensor_data = {}
            for item in data:
              try:
                sensor, value = item.split(':')
                sensor_data[sensor] = int(value)
                firebase.put_async('/', 'number',{sensor, int(value)})
              except:
                      print(item,end="")
            print(sensor_data,end="")
            
           
#            firebase.put_async('/','number',{
#                'can1':5,
#                'can2':7,
#                'can3':2,
#                'can4':1,
#                'now' :read
#            })
except KeyboardInterrupt:
        print("Close Serial communication")