#include <stdbool.h>
#include <stdio.h>

#include "tty_driver.h"
#include "screen.h"

int main() {
    // bool keep_alive = true;

    // Setup serial port to controller
    tty_configure();

    // Display Screen Info
    screen_clear();
    screen_display(SCREEN_LINE_1, " Jordan's NASty ");
    screen_display(SCREEN_LINE_2, "     Server     ");

    // Shut it down
    tty_close();

    return 0;
}