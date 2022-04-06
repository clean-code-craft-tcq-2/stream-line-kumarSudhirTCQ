import random
import time

# simulates the sensor
def SimulateSensor(min_val, max_val):
    return random.randint(min_val, max_val)

# calibrates the sensor data
def Calibrate_Sensor_Data(data2Calibrate, sensorMaxVal, max_bit_val):
    return round(data2Calibrate * sensorMaxVal / max_bit_val)

def Get_CurrentInAmps(sensorMaxVal, max_bit_val):

    # simulate current sensor
    sensorReading = SimulateSensor(0, max_bit_val)
    
    # calibrate the sensor values
    return Calibrate_Sensor_Data(sensorReading, sensorMaxVal, max_bit_val)

def Get_TemperatureInDegC():

    # simulate Temperature sensor
    return SimulateSensor(0, 100)

def send_data_to_console():
    for line in range(50):
        print(f'Amps: {Get_CurrentInAmps(10, 4094)}, Temp: {Get_TemperatureInDegC()}')
        time.sleep(1) # Sleep for 1 seconds


if __name__ == "__main__":
    send_data_to_console()