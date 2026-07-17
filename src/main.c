#include <stdbool.h>

#include "tty_driver.h"
#include "screen.h"

int main() {
    bool keep_alive = true;

    // Setup serial port to controller
    tty_configure();

    screen_clear();

    // Shut it down
    tty_close();

    return 0;
}