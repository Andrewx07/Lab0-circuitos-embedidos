#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


typedef struct
{
    uint8_t battery;
    uint16_t temperature;
    int32_t reserve_level;
    int32_t main_level;
    uint16_t checksum;

} Water_variables;


int main()
{
uint8_t receive_data[12] = {0xff, 0x00, 0x1f, 0x00, 0x0f, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}; // 12 bytes of data

    Water_variables data;

data.battery = receive_data[0];
data.temperature = (receive_data[1] << 8) | receive_data[2];
data.reserve_level = (receive_data[3] << 16) | (receive_data[4] << 8) | receive_data[5];
data.main_level = (receive_data[6] << 24) | (receive_data[7] << 16) | receive_data[8] << 8 | receive_data[9];
data.checksum = (receive_data[10] << 8) | receive_data[11];


printf("Battery: %d \n", data.battery);
printf("Temperature: %d\n", data.temperature);
printf("Reserve Level: %d\n", data.reserve_level);
printf("Main Level: %d\n", data.main_level);
printf("Checksum: %d\n", data.checksum);

    return 0;
}
