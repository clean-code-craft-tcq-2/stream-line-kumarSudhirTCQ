import bms_data_streaming_sender
from unittest import mock


class Test_bms_data_streaming_sender:

    # test1: SimulateSensor(min_val, max_val)
    @mock.patch('bms_data_streaming_sender.random.randint')
    def test_SimulateSensor(self, mock_obj):
        mock_obj.return_value = 55
        returned_value = bms_data_streaming_sender.SimulateSensor(0, 4094)
        assert returned_value == 55

    # test2: Calibrate_Sensor_Data(data2Calibrate, sensorMaxVal, max_bit_val)
    @mock.patch('bms_data_streaming_sender.round')
    def test_Calibrate_Sensor_Data(self, mock_obj):
        mock_obj.side_effect = [5, 9]  # used side_effect to return different value from same function for each call.
        returned_value = bms_data_streaming_sender.Calibrate_Sensor_Data(250, 10, 4094)
        assert returned_value == 5
        returned_value = bms_data_streaming_sender.Calibrate_Sensor_Data(550, 10, 4094)
        assert returned_value == 9

    # test3: Get_CurrentInAmps(sensorMaxVal, max_bit_val)
    @mock.patch('bms_data_streaming_sender.Calibrate_Sensor_Data')
    def test_Get_CurrentInAmps(self, mock_obj):
        mock_obj.return_value = 7
        returned_value = bms_data_streaming_sender.Get_CurrentInAmps(10, 4094)
        assert returned_value == 7

    # test4: Get_TemperatureInDegC()
    @mock.patch('bms_data_streaming_sender.SimulateSensor')
    def test_get_temperature(self, mock_obj):
        mock_obj.return_value = 75
        returned_value = bms_data_streaming_sender.Get_TemperatureInDegC()
        assert returned_value == 75
    
    # test5: send_data_to_console()
    @mock.patch('bms_data_streaming_sender.Get_TemperatureInDegC')
    @mock.patch('bms_data_streaming_sender.Get_CurrentInAmps')
    @mock.patch('builtins.print')
    def test_send_data_to_console(self, mock_obj_print, mock_current_amps, mock_obj_temp):
        mock_current_amps.return_value = 5
        mock_obj_temp.return_value = 80
        bms_data_streaming_sender.send_data_to_console()
        mock_obj_print.assert_called_with('Amps: 5, Temp: 80')


# run the test case
#if __name__ == "__main__":
obj = Test_bms_data_streaming_sender()
obj.test_SimulateSensor()
obj.test_Calibrate_Sensor_Data()
obj.test_Get_CurrentInAmps()
obj.test_get_temperature()
obj.test_send_data_to_console()

