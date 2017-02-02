#include "mbed.h"
#include "nRF24L01P.h"

Serial pc(USBTX, USBRX); // tx, rx

nRF24L01P nrf(PTD2,PTD3,PTD1,PTD0,PTD5,PTD4);    // mosi, miso, sck, csn, ce, irq
DigitalOut RedLED(LED1);
char datacnt=200;

void setup()
{
    nrf.powerUp();
    nrf.setRfFrequency(2450);
}
int transmitterMode(char Tx)
{
        TxDataCnt = 2;
        nrf.setTransferSize(TxDataCnt);
        nrf.enable();
        return 0;
}
int receiverMode(char Rx)
{        
    my_nrf24l01p.setReceiveMode();
    my_nrf24l01p.enable();

    
int main()
{
    char msg[100];
    char DataCnt=100;
    char temp;


    // Display the (default) setup of the nRF24L01+ chip
    pc.printf( "nRF24L01+ Frequency    : %d MHz\r\n",  my_nrf24l01p.getRfFrequency() );
    pc.printf( "nRF24L01+ Output power : %d dBm\r\n",  my_nrf24l01p.getRfOutputPower() );
    pc.printf( "nRF24L01+ Data Rate    : %d kbps\r\n", my_nrf24l01p.getAirDataRate() );
    pc.printf( "nRF24L01+ TX Address   : 0x%010llX\r\n", my_nrf24l01p.getTxAddress() );
    pc.printf( "nRF24L01+ RX Address   : 0x%010llX\r\n", my_nrf24l01p.getRxAddress() );

    pc.printf( "Simple Transmitter (0 - 9 Counter) \r\n");
    pc.printf("Press '~' to send ");

    while (1) {
        pc.getc(choice);
        
        if(choice=='~')
        {
            transmitterMode(DataCnt);
            
            pc.printf('Akshit:');
            pc.getc(count);
            
        pc.printf( "Sending %d - %d %d\r\n",temp,count[0],count[1]);

        // Toggle LED1 (to help debug Host -> nRF24L01+ communication)
        RedLED = !RedLED;
            
        count[1]++;
        
        wait(1);
    }
}
