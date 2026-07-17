#include <string.h>
#include <assert.h>

#include "screen.h"
#include "tty_driver.h"

#define SCREEN_MAX_LINE_LENGTH  (16U)

#define SCREEN_LINE_1_PREFIX    "LN1="
#define SCREEN_LINE_2_PREFIX    "LN2="

#define BUF_SIZE                (32U)

static char dump_buf[BUF_SIZE] = {0};

void screen_clear(void) {
    // Clear line 1
    tty_write(SCREEN_LINE_1_PREFIX);
    tty_write("\r");
    tty_read(dump_buf, BUF_SIZE);

    // Clear line 2
    tty_write(SCREEN_LINE_2_PREFIX);
    tty_write("\r");
    tty_read(dump_buf, BUF_SIZE);
}

void screen_display(screen_line_t line, char * msg) {
    assert(line < SCREEN_LINE_MAX);
    assert(strlen(msg) <= SCREEN_MAX_LINE_LENGTH);

    if(line == SCREEN_LINE_1) {
        tty_write(SCREEN_LINE_1_PREFIX);
    } else {
        tty_write(SCREEN_LINE_2_PREFIX);
    }

    tty_write(msg);
    tty_write("\r");
    tty_read(dump_buf, BUF_SIZE);
}