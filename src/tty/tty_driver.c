#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

#define TTY_DEVICE  "/dev/ttyS2"

// TTY File Descriptor
static int tty_fd;

void tty_configure(void) {
    int tty_fd = open(TTY_DEVICE, O_RDWR | O_NOCTTY | O_SYNC);
    if (tty_fd < 0) {
        perror("Error opening /dev/ttyS2");
    }
    
    // Configure serial port (9600 baud, 8N1)
    struct termios tty;
    if (tcgetattr(tty_fd, &tty) != 0) {
        perror("Error getting terminal attributes");
    }
    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);
    tty.c_cflag &= ~PARENB; // No parity
    tty.c_cflag &= ~CSTOPB; // 1 stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;     // 8 data bits
    tty.c_cflag &= ~CRTSCTS; // No flow control
    tty.c_cflag |= CREAD | CLOCAL;

    // Set Read Timeout Behavior (VMIN and VTIME)
    tty.c_cc[VMIN] = 0;  // Minimum characters to read (0 = return immediately if no data)
    tty.c_cc[VTIME] = 5; // Timeout in deciseconds (5 = 0.5 second)
    
    if (tcsetattr(tty_fd, TCSANOW, &tty) != 0) {
        perror("Error setting terminal attributes");
    }

    // Clear everything out
    tty_write("\r");

    printf("Serial port /dev/ttyS2 opened successfully.\n");
}

void tty_write(char * msg) {
    write(tty_fd, msg, strlen(msg));
    printf("W:%s",msg);
}

int tty_read(char * buf, int buf_size) {
    int n = read(tty_fd, buf, sizeof(buf_size) - 1);
    return n;
}

void tty_close(void) {
    close(tty_fd);
}