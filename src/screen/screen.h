typedef enum {
    SCREEN_LINE_1 = 0,
    SCREEN_LINE_2,
    SCREEN_LINE_MAX
} screen_line_t;

void screen_clear(void);
void screen_display(screen_line_t line, char * msg);