#include <mbed.h>
/**
 * Define of the Debug Uart
 */
#define UART_DEBUG_TX                   PA_9
#define UART_DEBUG_RX                   PA_10
#define UART_DEBUG_DATA_RATE            230400

BufferedSerial pc(UART_DEBUG_TX, UART_DEBUG_RX, UART_DEBUG_DATA_RATE);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &pc;
}

Thread thread_consumer(osPriorityNormal, 1024, nullptr, "Consumer");
Thread thread_producer(osPriorityHigh, 1024, nullptr, "Producer");


void consumer(){

    printf("Initializing thread \"consumer\"\n");

    while (1)
    {
        thread_sleep_for(1000);
        printf("CONSUMER\n");
    }
}
void producer(){

    printf("Initializing thread \"producer\"\n");

    while (1)
    {
        thread_sleep_for(1000);
        printf("PRODUCER\n");
    }
    
}
int main()
{
    printf("Init mbed-debug.\n");
    
    thread_consumer.start(callback(&consumer));    
    thread_producer.start(callback(&producer));
    while (1)
    {}
    printf("Should need reach this point\n"); 
    return 0;
}
