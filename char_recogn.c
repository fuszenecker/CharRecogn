#include <fann.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  PIXMAP_WIDTH   16
#define  PIXMAP_HEIGHT  16
#define  INPUTS         (PIXMAP_WIDTH * PIXMAP_HEIGHT)
#define  OUTPUTS        32
#define  HIDDEN_NEURONS 0           // még enélkül is megy!!!
#define  MAX_LINE_LEN   1024

int load_pixmap(char *pixmap_name, fann_type pixmap[PIXMAP_HEIGHT][PIXMAP_WIDTH]) {
    int pcx, pcy;
    int w, h, colors;
    char pixel, line[MAX_LINE_LEN];
    FILE *pixmap_file;

    pixmap_file = fopen(pixmap_name, "r");

    if (!pixmap_file)
        return 1;
   
    fgets(line, MAX_LINE_LEN, pixmap_file);
    // Result should be: /* XPM */

    if (strncmp(line, "/* XPM */", 9))
        return 2;

    fgets(line, MAX_LINE_LEN, pixmap_file);
    // Result should be: static char * a00_xpm[] = {

    fgets(line, MAX_LINE_LEN, pixmap_file);
    // Result should be: "16 16 14 1"
 
    sscanf(line+1, "%d %d %d", &w, &h, &colors);

    if (w != PIXMAP_WIDTH || h != PIXMAP_HEIGHT)
        return 3;

    // Skipping color map definition
    for (pcx = 0; pcx < colors; pcx++)
        fgets(line, MAX_LINE_LEN, pixmap_file);

    // Loading the "real" pixmap
    for (pcy = 0; pcy < PIXMAP_HEIGHT; pcy++) {
        fgets(line, MAX_LINE_LEN, pixmap_file);
        // Result, for example: " $+     ;#+$   +",
        for (pcx = 0; pcx < PIXMAP_WIDTH; pcx++) {
            pixel = line[pcx+1];
            pixmap[pcy][pcx] = ((pixel == ' ') ? 0.0 : 1.0);
        }
    }

    fclose(pixmap_file);
    return 0;
}

void print_pixmap(fann_type pixmap[PIXMAP_HEIGHT][PIXMAP_WIDTH]) {
    int lcx, lcy, ch;

    for (lcy = 0; lcy < PIXMAP_HEIGHT; lcy++) {
        for (lcx = 0; lcx < PIXMAP_WIDTH; lcx++) {
            ch = ((pixmap[lcy][lcx] > 0.5) ? 'X' : ' ');
            putchar(ch);
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    struct fann *neural_net;
    fann_type input_value[INPUTS], *result;
    int cx, cy;
    struct fann_error neural_net_error;

    if (argc < 2) {
        fprintf(stderr, "Too few arguments. Argument 1 must be a file name.\n");
        exit(3);
    }

    fann_type pixmap[PIXMAP_HEIGHT][PIXMAP_WIDTH];

    char *char_encode[] = {"a", "b", "c", "d", "e", "f", "g", "h", 
                            "i", "j", "k", "l", "m", "n", "o", "p",
                            "q", "r", "s", "t", "u", "v", "w", "x", 
                            "y", "z", "á", "é", "ó", "ö", "ú", "ü"};

    printf("Loading neural network from file... ");
    neural_net = fann_create_from_file("char_recogn.net");
    fann_set_error_log(&neural_net_error, NULL);

    if (!neural_net) {
        fprintf(stderr, "Failed: %s\n", fann_get_errstr(&neural_net_error));
        exit(1);
    } else
        printf("Ok.\n");    

    if (load_pixmap(argv[1], pixmap)) {
        fprintf(stderr, "Unable to load pixmap.\n");
        exit(2);
    }

    for (cy = 0; cy < PIXMAP_HEIGHT; cy++)
        for (cx = 0; cx < PIXMAP_WIDTH; cx++)
            input_value[cy * PIXMAP_WIDTH + cx] = pixmap[cy][cx];

    putchar('\n');
    print_pixmap(pixmap);
    putchar('\n');

    result = fann_run(neural_net, input_value);

    putchar('\n');

    for (cx = 0; cx < OUTPUTS; cx++)
        if (result[cx] > 0)
            printf("OUTPUT (%s):    %0.8f %s\n", char_encode[cx], result[cx], result[cx] >= 0.5 ? "****" : "");

    fann_destroy(neural_net);
    return 0;
}
