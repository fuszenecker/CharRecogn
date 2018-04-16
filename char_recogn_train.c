#include <fann.h>
#include <stdio.h>
#include <stdlib.h>

#define  PIXMAP_WIDTH   16
#define  PIXMAP_HEIGHT  16
#define  LETTER_SHIFT   4

#define  INPUTS         (PIXMAP_WIDTH * PIXMAP_HEIGHT)
#define  OUTPUTS        32
#define  HIDDEN_NEURONS OUTPUTS * (1 << LETTER_SHIFT) 
//#define  HIDDEN_NEURONS OUTPUTS * 4

#define  TEACHINGS      1000000
#define  MODULUS        1000

#include "pixmaps/a00.xpm"
#include "pixmaps/a01.xpm"
#include "pixmaps/a02.xpm"
#include "pixmaps/a03.xpm"
#include "pixmaps/a04.xpm"
#include "pixmaps/a05.xpm"
#include "pixmaps/a06.xpm"
#include "pixmaps/a07.xpm"
#include "pixmaps/a10.xpm"
#include "pixmaps/a11.xpm"
#include "pixmaps/a12.xpm"
#include "pixmaps/a13.xpm"
#include "pixmaps/a14.xpm"
#include "pixmaps/a15.xpm"
#include "pixmaps/a16.xpm"
#include "pixmaps/a17.xpm"

#include "pixmaps/b00.xpm"
#include "pixmaps/b01.xpm"
#include "pixmaps/b02.xpm"
#include "pixmaps/b03.xpm"
#include "pixmaps/b04.xpm"
#include "pixmaps/b05.xpm"
#include "pixmaps/b06.xpm"
#include "pixmaps/b07.xpm"
#include "pixmaps/b10.xpm"
#include "pixmaps/b11.xpm"
#include "pixmaps/b12.xpm"
#include "pixmaps/b13.xpm"
#include "pixmaps/b14.xpm"
#include "pixmaps/b15.xpm"
#include "pixmaps/b16.xpm"
#include "pixmaps/b17.xpm"

#include "pixmaps/c00.xpm"
#include "pixmaps/c01.xpm"
#include "pixmaps/c02.xpm"
#include "pixmaps/c03.xpm"
#include "pixmaps/c04.xpm"
#include "pixmaps/c05.xpm"
#include "pixmaps/c06.xpm"
#include "pixmaps/c07.xpm"
#include "pixmaps/c10.xpm"
#include "pixmaps/c11.xpm"
#include "pixmaps/c12.xpm"
#include "pixmaps/c13.xpm"
#include "pixmaps/c14.xpm"
#include "pixmaps/c15.xpm"
#include "pixmaps/c16.xpm"
#include "pixmaps/c17.xpm"
                  
#include "pixmaps/d00.xpm"
#include "pixmaps/d01.xpm"
#include "pixmaps/d02.xpm"
#include "pixmaps/d03.xpm"
#include "pixmaps/d04.xpm"
#include "pixmaps/d05.xpm"
#include "pixmaps/d06.xpm"
#include "pixmaps/d07.xpm"
#include "pixmaps/d10.xpm"
#include "pixmaps/d11.xpm"
#include "pixmaps/d12.xpm"
#include "pixmaps/d13.xpm"
#include "pixmaps/d14.xpm"
#include "pixmaps/d15.xpm"
#include "pixmaps/d16.xpm"
#include "pixmaps/d17.xpm"

#include "pixmaps/e00.xpm"
#include "pixmaps/e01.xpm"
#include "pixmaps/e02.xpm"
#include "pixmaps/e03.xpm"
#include "pixmaps/e04.xpm"
#include "pixmaps/e05.xpm"
#include "pixmaps/e06.xpm"
#include "pixmaps/e07.xpm"
#include "pixmaps/e10.xpm"
#include "pixmaps/e11.xpm"
#include "pixmaps/e12.xpm"
#include "pixmaps/e13.xpm"
#include "pixmaps/e14.xpm"
#include "pixmaps/e15.xpm"
#include "pixmaps/e16.xpm"
#include "pixmaps/e17.xpm"
                  
#include "pixmaps/f00.xpm"
#include "pixmaps/f01.xpm"
#include "pixmaps/f02.xpm"
#include "pixmaps/f03.xpm"
#include "pixmaps/f04.xpm"
#include "pixmaps/f05.xpm"
#include "pixmaps/f06.xpm"
#include "pixmaps/f07.xpm"
#include "pixmaps/f10.xpm"
#include "pixmaps/f11.xpm"
#include "pixmaps/f12.xpm"
#include "pixmaps/f13.xpm"
#include "pixmaps/f14.xpm"
#include "pixmaps/f15.xpm"
#include "pixmaps/f16.xpm"
#include "pixmaps/f17.xpm"

#include "pixmaps/g00.xpm"
#include "pixmaps/g01.xpm"
#include "pixmaps/g02.xpm"
#include "pixmaps/g03.xpm"
#include "pixmaps/g04.xpm"
#include "pixmaps/g05.xpm"
#include "pixmaps/g06.xpm"
#include "pixmaps/g07.xpm"
#include "pixmaps/g10.xpm"
#include "pixmaps/g11.xpm"
#include "pixmaps/g12.xpm"
#include "pixmaps/g13.xpm"
#include "pixmaps/g14.xpm"
#include "pixmaps/g15.xpm"
#include "pixmaps/g16.xpm"
#include "pixmaps/g17.xpm"
                  
#include "pixmaps/h00.xpm"
#include "pixmaps/h01.xpm"
#include "pixmaps/h02.xpm"
#include "pixmaps/h03.xpm"
#include "pixmaps/h04.xpm"
#include "pixmaps/h05.xpm"
#include "pixmaps/h06.xpm"
#include "pixmaps/h07.xpm"
#include "pixmaps/h10.xpm"
#include "pixmaps/h11.xpm"
#include "pixmaps/h12.xpm"
#include "pixmaps/h13.xpm"
#include "pixmaps/h14.xpm"
#include "pixmaps/h15.xpm"
#include "pixmaps/h16.xpm"
#include "pixmaps/h17.xpm"

#include "pixmaps/i00.xpm"
#include "pixmaps/i01.xpm"
#include "pixmaps/i02.xpm"
#include "pixmaps/i03.xpm"
#include "pixmaps/i04.xpm"
#include "pixmaps/i05.xpm"
#include "pixmaps/i06.xpm"
#include "pixmaps/i07.xpm"
#include "pixmaps/i10.xpm"
#include "pixmaps/i11.xpm"
#include "pixmaps/i12.xpm"
#include "pixmaps/i13.xpm"
#include "pixmaps/i14.xpm"
#include "pixmaps/i15.xpm"
#include "pixmaps/i16.xpm"
#include "pixmaps/i17.xpm"
                  
#include "pixmaps/j00.xpm"
#include "pixmaps/j01.xpm"
#include "pixmaps/j02.xpm"
#include "pixmaps/j03.xpm"
#include "pixmaps/j04.xpm"
#include "pixmaps/j05.xpm"
#include "pixmaps/j06.xpm"
#include "pixmaps/j07.xpm"
#include "pixmaps/j10.xpm"
#include "pixmaps/j11.xpm"
#include "pixmaps/j12.xpm"
#include "pixmaps/j13.xpm"
#include "pixmaps/j14.xpm"
#include "pixmaps/j15.xpm"
#include "pixmaps/j16.xpm"
#include "pixmaps/j17.xpm"

#include "pixmaps/k00.xpm"
#include "pixmaps/k01.xpm"
#include "pixmaps/k02.xpm"
#include "pixmaps/k03.xpm"
#include "pixmaps/k04.xpm"
#include "pixmaps/k05.xpm"
#include "pixmaps/k06.xpm"
#include "pixmaps/k07.xpm"
#include "pixmaps/k10.xpm"
#include "pixmaps/k11.xpm"
#include "pixmaps/k12.xpm"
#include "pixmaps/k13.xpm"
#include "pixmaps/k14.xpm"
#include "pixmaps/k15.xpm"
#include "pixmaps/k16.xpm"
#include "pixmaps/k17.xpm"
                  
#include "pixmaps/l00.xpm"
#include "pixmaps/l01.xpm"
#include "pixmaps/l02.xpm"
#include "pixmaps/l03.xpm"
#include "pixmaps/l04.xpm"
#include "pixmaps/l05.xpm"
#include "pixmaps/l06.xpm"
#include "pixmaps/l07.xpm"
#include "pixmaps/l10.xpm"
#include "pixmaps/l11.xpm"
#include "pixmaps/l12.xpm"
#include "pixmaps/l13.xpm"
#include "pixmaps/l14.xpm"
#include "pixmaps/l15.xpm"
#include "pixmaps/l16.xpm"
#include "pixmaps/l17.xpm"

#include "pixmaps/m00.xpm"
#include "pixmaps/m01.xpm"
#include "pixmaps/m02.xpm"
#include "pixmaps/m03.xpm"
#include "pixmaps/m04.xpm"
#include "pixmaps/m05.xpm"
#include "pixmaps/m06.xpm"
#include "pixmaps/m07.xpm"
#include "pixmaps/m10.xpm"
#include "pixmaps/m11.xpm"
#include "pixmaps/m12.xpm"
#include "pixmaps/m13.xpm"
#include "pixmaps/m14.xpm"
#include "pixmaps/m15.xpm"
#include "pixmaps/m16.xpm"
#include "pixmaps/m17.xpm"
                  
#include "pixmaps/n00.xpm"
#include "pixmaps/n01.xpm"
#include "pixmaps/n02.xpm"
#include "pixmaps/n03.xpm"
#include "pixmaps/n04.xpm"
#include "pixmaps/n05.xpm"
#include "pixmaps/n06.xpm"
#include "pixmaps/n07.xpm"
#include "pixmaps/n10.xpm"
#include "pixmaps/n11.xpm"
#include "pixmaps/n12.xpm"
#include "pixmaps/n13.xpm"
#include "pixmaps/n14.xpm"
#include "pixmaps/n15.xpm"
#include "pixmaps/n16.xpm"
#include "pixmaps/n17.xpm"

#include "pixmaps/o00.xpm"
#include "pixmaps/o01.xpm"
#include "pixmaps/o02.xpm"
#include "pixmaps/o03.xpm"
#include "pixmaps/o04.xpm"
#include "pixmaps/o05.xpm"
#include "pixmaps/o06.xpm"
#include "pixmaps/o07.xpm"
#include "pixmaps/o10.xpm"
#include "pixmaps/o11.xpm"
#include "pixmaps/o12.xpm"
#include "pixmaps/o13.xpm"
#include "pixmaps/o14.xpm"
#include "pixmaps/o15.xpm"
#include "pixmaps/o16.xpm"
#include "pixmaps/o17.xpm"
                  
#include "pixmaps/p00.xpm"
#include "pixmaps/p01.xpm"
#include "pixmaps/p02.xpm"
#include "pixmaps/p03.xpm"
#include "pixmaps/p04.xpm"
#include "pixmaps/p05.xpm"
#include "pixmaps/p06.xpm"
#include "pixmaps/p07.xpm"
#include "pixmaps/p10.xpm"
#include "pixmaps/p11.xpm"
#include "pixmaps/p12.xpm"
#include "pixmaps/p13.xpm"
#include "pixmaps/p14.xpm"
#include "pixmaps/p15.xpm"
#include "pixmaps/p16.xpm"
#include "pixmaps/p17.xpm"

#include "pixmaps/q00.xpm"
#include "pixmaps/q01.xpm"
#include "pixmaps/q02.xpm"
#include "pixmaps/q03.xpm"
#include "pixmaps/q04.xpm"
#include "pixmaps/q05.xpm"
#include "pixmaps/q06.xpm"
#include "pixmaps/q07.xpm"
#include "pixmaps/q10.xpm"
#include "pixmaps/q11.xpm"
#include "pixmaps/q12.xpm"
#include "pixmaps/q13.xpm"
#include "pixmaps/q14.xpm"
#include "pixmaps/q15.xpm"
#include "pixmaps/q16.xpm"
#include "pixmaps/q17.xpm"
                  
#include "pixmaps/r00.xpm"
#include "pixmaps/r01.xpm"
#include "pixmaps/r02.xpm"
#include "pixmaps/r03.xpm"
#include "pixmaps/r04.xpm"
#include "pixmaps/r05.xpm"
#include "pixmaps/r06.xpm"
#include "pixmaps/r07.xpm"
#include "pixmaps/r10.xpm"
#include "pixmaps/r11.xpm"
#include "pixmaps/r12.xpm"
#include "pixmaps/r13.xpm"
#include "pixmaps/r14.xpm"
#include "pixmaps/r15.xpm"
#include "pixmaps/r16.xpm"
#include "pixmaps/r17.xpm"

#include "pixmaps/s00.xpm"
#include "pixmaps/s01.xpm"
#include "pixmaps/s02.xpm"
#include "pixmaps/s03.xpm"
#include "pixmaps/s04.xpm"
#include "pixmaps/s05.xpm"
#include "pixmaps/s06.xpm"
#include "pixmaps/s07.xpm"
#include "pixmaps/s10.xpm"
#include "pixmaps/s11.xpm"
#include "pixmaps/s12.xpm"
#include "pixmaps/s13.xpm"
#include "pixmaps/s14.xpm"
#include "pixmaps/s15.xpm"
#include "pixmaps/s16.xpm"
#include "pixmaps/s17.xpm"
                  
#include "pixmaps/t00.xpm"
#include "pixmaps/t01.xpm"
#include "pixmaps/t02.xpm"
#include "pixmaps/t03.xpm"
#include "pixmaps/t04.xpm"
#include "pixmaps/t05.xpm"
#include "pixmaps/t06.xpm"
#include "pixmaps/t07.xpm"
#include "pixmaps/t10.xpm"
#include "pixmaps/t11.xpm"
#include "pixmaps/t12.xpm"
#include "pixmaps/t13.xpm"
#include "pixmaps/t14.xpm"
#include "pixmaps/t15.xpm"
#include "pixmaps/t16.xpm"
#include "pixmaps/t17.xpm"

#include "pixmaps/u00.xpm"
#include "pixmaps/u01.xpm"
#include "pixmaps/u02.xpm"
#include "pixmaps/u03.xpm"
#include "pixmaps/u04.xpm"
#include "pixmaps/u05.xpm"
#include "pixmaps/u06.xpm"
#include "pixmaps/u07.xpm"
#include "pixmaps/u10.xpm"
#include "pixmaps/u11.xpm"
#include "pixmaps/u12.xpm"
#include "pixmaps/u13.xpm"
#include "pixmaps/u14.xpm"
#include "pixmaps/u15.xpm"
#include "pixmaps/u16.xpm"
#include "pixmaps/u17.xpm"
                  
#include "pixmaps/v00.xpm"
#include "pixmaps/v01.xpm"
#include "pixmaps/v02.xpm"
#include "pixmaps/v03.xpm"
#include "pixmaps/v04.xpm"
#include "pixmaps/v05.xpm"
#include "pixmaps/v06.xpm"
#include "pixmaps/v07.xpm"
#include "pixmaps/v10.xpm"
#include "pixmaps/v11.xpm"
#include "pixmaps/v12.xpm"
#include "pixmaps/v13.xpm"
#include "pixmaps/v14.xpm"
#include "pixmaps/v15.xpm"
#include "pixmaps/v16.xpm"
#include "pixmaps/v17.xpm"

#include "pixmaps/w00.xpm"
#include "pixmaps/w01.xpm"
#include "pixmaps/w02.xpm"
#include "pixmaps/w03.xpm"
#include "pixmaps/w04.xpm"
#include "pixmaps/w05.xpm"
#include "pixmaps/w06.xpm"
#include "pixmaps/w07.xpm"
#include "pixmaps/w10.xpm"
#include "pixmaps/w11.xpm"
#include "pixmaps/w12.xpm"
#include "pixmaps/w13.xpm"
#include "pixmaps/w14.xpm"
#include "pixmaps/w15.xpm"
#include "pixmaps/w16.xpm"
#include "pixmaps/w17.xpm"
                  
#include "pixmaps/x00.xpm"
#include "pixmaps/x01.xpm"
#include "pixmaps/x02.xpm"
#include "pixmaps/x03.xpm"
#include "pixmaps/x04.xpm"
#include "pixmaps/x05.xpm"
#include "pixmaps/x06.xpm"
#include "pixmaps/x07.xpm"
#include "pixmaps/x10.xpm"
#include "pixmaps/x11.xpm"
#include "pixmaps/x12.xpm"
#include "pixmaps/x13.xpm"
#include "pixmaps/x14.xpm"
#include "pixmaps/x15.xpm"
#include "pixmaps/x16.xpm"
#include "pixmaps/x17.xpm"

#include "pixmaps/y00.xpm"
#include "pixmaps/y01.xpm"
#include "pixmaps/y02.xpm"
#include "pixmaps/y03.xpm"
#include "pixmaps/y04.xpm"
#include "pixmaps/y05.xpm"
#include "pixmaps/y06.xpm"
#include "pixmaps/y07.xpm"
#include "pixmaps/y10.xpm"
#include "pixmaps/y11.xpm"
#include "pixmaps/y12.xpm"
#include "pixmaps/y13.xpm"
#include "pixmaps/y14.xpm"
#include "pixmaps/y15.xpm"
#include "pixmaps/y16.xpm"
#include "pixmaps/y17.xpm"
                  
#include "pixmaps/z00.xpm"
#include "pixmaps/z01.xpm"
#include "pixmaps/z02.xpm"
#include "pixmaps/z03.xpm"
#include "pixmaps/z04.xpm"
#include "pixmaps/z05.xpm"
#include "pixmaps/z06.xpm"
#include "pixmaps/z07.xpm"
#include "pixmaps/z10.xpm"
#include "pixmaps/z11.xpm"
#include "pixmaps/z12.xpm"
#include "pixmaps/z13.xpm"
#include "pixmaps/z14.xpm"
#include "pixmaps/z15.xpm"
#include "pixmaps/z16.xpm"
#include "pixmaps/z17.xpm"

#include "pixmaps/aa00.xpm"
#include "pixmaps/aa01.xpm"
#include "pixmaps/aa02.xpm"
#include "pixmaps/aa03.xpm"
#include "pixmaps/aa04.xpm"
#include "pixmaps/aa05.xpm"
#include "pixmaps/aa06.xpm"
#include "pixmaps/aa07.xpm"
#include "pixmaps/aa10.xpm"
#include "pixmaps/aa11.xpm"
#include "pixmaps/aa12.xpm"
#include "pixmaps/aa13.xpm"
#include "pixmaps/aa14.xpm"
#include "pixmaps/aa15.xpm"
#include "pixmaps/aa16.xpm"
#include "pixmaps/aa17.xpm"
                  
#include "pixmaps/ee00.xpm"
#include "pixmaps/ee01.xpm"
#include "pixmaps/ee02.xpm"
#include "pixmaps/ee03.xpm"
#include "pixmaps/ee04.xpm"
#include "pixmaps/ee05.xpm"
#include "pixmaps/ee06.xpm"
#include "pixmaps/ee07.xpm"
#include "pixmaps/ee10.xpm"
#include "pixmaps/ee11.xpm"
#include "pixmaps/ee12.xpm"
#include "pixmaps/ee13.xpm"
#include "pixmaps/ee14.xpm"
#include "pixmaps/ee15.xpm"
#include "pixmaps/ee16.xpm"
#include "pixmaps/ee17.xpm"

#include "pixmaps/oo00.xpm"
#include "pixmaps/oo01.xpm"
#include "pixmaps/oo02.xpm"
#include "pixmaps/oo03.xpm"
#include "pixmaps/oo04.xpm"
#include "pixmaps/oo05.xpm"
#include "pixmaps/oo06.xpm"
#include "pixmaps/oo07.xpm"
#include "pixmaps/oo10.xpm"
#include "pixmaps/oo11.xpm"
#include "pixmaps/oo12.xpm"
#include "pixmaps/oo13.xpm"
#include "pixmaps/oo14.xpm"
#include "pixmaps/oo15.xpm"
#include "pixmaps/oo16.xpm"
#include "pixmaps/oo17.xpm"
                  
#include "pixmaps/ue00.xpm"
#include "pixmaps/ue01.xpm"
#include "pixmaps/ue02.xpm"
#include "pixmaps/ue03.xpm"
#include "pixmaps/ue04.xpm"
#include "pixmaps/ue05.xpm"
#include "pixmaps/ue06.xpm"
#include "pixmaps/ue07.xpm"
#include "pixmaps/ue10.xpm"
#include "pixmaps/ue11.xpm"
#include "pixmaps/ue12.xpm"
#include "pixmaps/ue13.xpm"
#include "pixmaps/ue14.xpm"
#include "pixmaps/ue15.xpm"
#include "pixmaps/ue16.xpm"
#include "pixmaps/ue17.xpm"

#include "pixmaps/uu00.xpm"
#include "pixmaps/uu01.xpm"
#include "pixmaps/uu02.xpm"
#include "pixmaps/uu03.xpm"
#include "pixmaps/uu04.xpm"
#include "pixmaps/uu05.xpm"
#include "pixmaps/uu06.xpm"
#include "pixmaps/uu07.xpm"
#include "pixmaps/uu10.xpm"
#include "pixmaps/uu11.xpm"
#include "pixmaps/uu12.xpm"
#include "pixmaps/uu13.xpm"
#include "pixmaps/uu14.xpm"
#include "pixmaps/uu15.xpm"
#include "pixmaps/uu16.xpm"
#include "pixmaps/uu17.xpm"
                  
#include "pixmaps/oe00.xpm"
#include "pixmaps/oe01.xpm"
#include "pixmaps/oe02.xpm"
#include "pixmaps/oe03.xpm"
#include "pixmaps/oe04.xpm"
#include "pixmaps/oe05.xpm"
#include "pixmaps/oe06.xpm"
#include "pixmaps/oe07.xpm"
#include "pixmaps/oe10.xpm"
#include "pixmaps/oe11.xpm"
#include "pixmaps/oe12.xpm"
#include "pixmaps/oe13.xpm"
#include "pixmaps/oe14.xpm"
#include "pixmaps/oe15.xpm"
#include "pixmaps/oe16.xpm"
#include "pixmaps/oe17.xpm"

void prepare_pixmap(char **char_pixmap, fann_type pixmap[PIXMAP_HEIGHT][PIXMAP_WIDTH]) {
    int pcx, pcy;
    int w, h, colors;
    char pixel;
    
    sscanf(char_pixmap[0], "%d %d %d", &w, &h, &colors);

    for (pcy = 0; pcy < PIXMAP_HEIGHT; pcy++) {
        for (pcx = 0; pcx < PIXMAP_WIDTH; pcx++) {
            pixel = char_pixmap[pcy+colors+1][pcx];
            pixmap[pcy][pcx] = ((pixel == ' ') ? 0.0 : 1.0);
        }
    }
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

int main() {
    struct fann *neural_net;
    fann_type input_value[INPUTS], desired_value[OUTPUTS], *result;
    int count, pixmap_index, cx, cy;

    fann_type pixmap[PIXMAP_HEIGHT][PIXMAP_WIDTH];

    char **pixmaps[] = {
        a00_xpm, a01_xpm, a02_xpm, a03_xpm, a04_xpm, a05_xpm, a06_xpm, a07_xpm,
        a10_xpm, a11_xpm, a12_xpm, a13_xpm, a14_xpm, a15_xpm, a16_xpm, a17_xpm,

        b00_xpm, b01_xpm, b02_xpm, b03_xpm, b04_xpm, b05_xpm, b06_xpm, b07_xpm,
        b10_xpm, b11_xpm, b12_xpm, b13_xpm, b14_xpm, b15_xpm, b16_xpm, b17_xpm,

        c00_xpm, c01_xpm, c02_xpm, c03_xpm, c04_xpm, c05_xpm, c06_xpm, c07_xpm,
        c10_xpm, c11_xpm, c12_xpm, c13_xpm, c14_xpm, c15_xpm, c16_xpm, c17_xpm,

        d00_xpm, d01_xpm, d02_xpm, d03_xpm, d04_xpm, d05_xpm, d06_xpm, d07_xpm,
        d10_xpm, d11_xpm, d12_xpm, d13_xpm, d14_xpm, d15_xpm, d16_xpm, d17_xpm,

        e00_xpm, e01_xpm, e02_xpm, e03_xpm, e04_xpm, e05_xpm, e06_xpm, e07_xpm,
        e10_xpm, e11_xpm, e12_xpm, e13_xpm, e14_xpm, e15_xpm, e16_xpm, e17_xpm,

        f00_xpm, f01_xpm, f02_xpm, f03_xpm, f04_xpm, f05_xpm, f06_xpm, f07_xpm,
        f10_xpm, f11_xpm, f12_xpm, f13_xpm, f14_xpm, f15_xpm, f16_xpm, f17_xpm,

        g00_xpm, g01_xpm, g02_xpm, g03_xpm, g04_xpm, g05_xpm, g06_xpm, g07_xpm,
        g10_xpm, g11_xpm, g12_xpm, g13_xpm, g14_xpm, g15_xpm, g16_xpm, g17_xpm,

        h00_xpm, h01_xpm, h02_xpm, h03_xpm, h04_xpm, h05_xpm, h06_xpm, h07_xpm,
        h10_xpm, h11_xpm, h12_xpm, h13_xpm, h14_xpm, h15_xpm, h16_xpm, h17_xpm,

        i00_xpm, i01_xpm, i02_xpm, i03_xpm, i04_xpm, i05_xpm, i06_xpm, i07_xpm,
        i10_xpm, i11_xpm, i12_xpm, i13_xpm, i14_xpm, i15_xpm, i16_xpm, i17_xpm,

        j00_xpm, j01_xpm, j02_xpm, j03_xpm, j04_xpm, j05_xpm, j06_xpm, j07_xpm,
        j10_xpm, j11_xpm, j12_xpm, j13_xpm, j14_xpm, j15_xpm, j16_xpm, j17_xpm,

        k00_xpm, k01_xpm, k02_xpm, k03_xpm, k04_xpm, k05_xpm, k06_xpm, k07_xpm,
        k10_xpm, k11_xpm, k12_xpm, k13_xpm, k14_xpm, k15_xpm, k16_xpm, k17_xpm,

        l00_xpm, l01_xpm, l02_xpm, l03_xpm, l04_xpm, l05_xpm, l06_xpm, l07_xpm,
        l10_xpm, l11_xpm, l12_xpm, l13_xpm, l14_xpm, l15_xpm, l16_xpm, l17_xpm,

        m00_xpm, m01_xpm, m02_xpm, m03_xpm, m04_xpm, m05_xpm, m06_xpm, m07_xpm,
        m10_xpm, m11_xpm, m12_xpm, m13_xpm, m14_xpm, m15_xpm, m16_xpm, m17_xpm,

        n00_xpm, n01_xpm, n02_xpm, n03_xpm, n04_xpm, n05_xpm, n06_xpm, n07_xpm,
        n10_xpm, n11_xpm, n12_xpm, n13_xpm, n14_xpm, n15_xpm, n16_xpm, n17_xpm,

        o00_xpm, o01_xpm, o02_xpm, o03_xpm, o04_xpm, o05_xpm, o06_xpm, o07_xpm,
        o10_xpm, o11_xpm, o12_xpm, o13_xpm, o14_xpm, o15_xpm, o16_xpm, o17_xpm,

        p00_xpm, p01_xpm, p02_xpm, p03_xpm, p04_xpm, p05_xpm, p06_xpm, p07_xpm,
        p10_xpm, p11_xpm, p12_xpm, p13_xpm, p14_xpm, p15_xpm, p16_xpm, p17_xpm,

        q00_xpm, q01_xpm, q02_xpm, q03_xpm, q04_xpm, q05_xpm, q06_xpm, q07_xpm,
        q10_xpm, q11_xpm, q12_xpm, q13_xpm, q14_xpm, q15_xpm, q16_xpm, q17_xpm,

        r00_xpm, r01_xpm, r02_xpm, r03_xpm, r04_xpm, r05_xpm, r06_xpm, r07_xpm,
        r10_xpm, r11_xpm, r12_xpm, r13_xpm, r14_xpm, r15_xpm, r16_xpm, r17_xpm,

        s00_xpm, s01_xpm, s02_xpm, s03_xpm, s04_xpm, s05_xpm, s06_xpm, s07_xpm,
        s10_xpm, s11_xpm, s12_xpm, s13_xpm, s14_xpm, s15_xpm, s16_xpm, s17_xpm,

        t00_xpm, t01_xpm, t02_xpm, t03_xpm, t04_xpm, t05_xpm, t06_xpm, t07_xpm,
        t10_xpm, t11_xpm, t12_xpm, t13_xpm, t14_xpm, t15_xpm, t16_xpm, t17_xpm,

        u00_xpm, u01_xpm, u02_xpm, u03_xpm, u04_xpm, u05_xpm, u06_xpm, u07_xpm,
        u10_xpm, u11_xpm, u12_xpm, u13_xpm, u14_xpm, u15_xpm, u16_xpm, u17_xpm,

        v00_xpm, v01_xpm, v02_xpm, v03_xpm, v04_xpm, v05_xpm, v06_xpm, v07_xpm,
        v10_xpm, v11_xpm, v12_xpm, v13_xpm, v14_xpm, v15_xpm, v16_xpm, v17_xpm,

        w00_xpm, w01_xpm, w02_xpm, w03_xpm, w04_xpm, w05_xpm, w06_xpm, w07_xpm,
        w10_xpm, w11_xpm, w12_xpm, w13_xpm, w14_xpm, w15_xpm, w16_xpm, w17_xpm,

        x00_xpm, x01_xpm, x02_xpm, x03_xpm, x04_xpm, x05_xpm, x06_xpm, x07_xpm,
        x10_xpm, x11_xpm, x12_xpm, x13_xpm, x14_xpm, x15_xpm, x16_xpm, x17_xpm,

        y00_xpm, y01_xpm, y02_xpm, y03_xpm, y04_xpm, y05_xpm, y06_xpm, y07_xpm,
        y10_xpm, y11_xpm, y12_xpm, y13_xpm, y14_xpm, y15_xpm, y16_xpm, y17_xpm,

        z00_xpm, z01_xpm, z02_xpm, z03_xpm, z04_xpm, z05_xpm, z06_xpm, z07_xpm,
        z10_xpm, z11_xpm, z12_xpm, z13_xpm, z14_xpm, z15_xpm, z16_xpm, z17_xpm,

        aa00_xpm, aa01_xpm, aa02_xpm, aa03_xpm, aa04_xpm, aa05_xpm, aa06_xpm, aa07_xpm,
        aa10_xpm, aa11_xpm, aa12_xpm, aa13_xpm, aa14_xpm, aa15_xpm, aa16_xpm, aa17_xpm,

        ee00_xpm, ee01_xpm, ee02_xpm, ee03_xpm, ee04_xpm, ee05_xpm, ee06_xpm, ee07_xpm,
        ee10_xpm, ee11_xpm, ee12_xpm, ee13_xpm, ee14_xpm, ee15_xpm, ee16_xpm, ee17_xpm,

        oo00_xpm, oo01_xpm, oo02_xpm, oo03_xpm, oo04_xpm, oo05_xpm, oo06_xpm, oo07_xpm,
        oo10_xpm, oo11_xpm, oo12_xpm, oo13_xpm, oo14_xpm, oo15_xpm, oo16_xpm, oo17_xpm,

        oe00_xpm, oe01_xpm, oe02_xpm, oe03_xpm, oe04_xpm, oe05_xpm, oe06_xpm, oe07_xpm,
        oe10_xpm, oe11_xpm, oe12_xpm, oe13_xpm, oe14_xpm, oe15_xpm, oe16_xpm, oe17_xpm,

        uu00_xpm, uu01_xpm, uu02_xpm, uu03_xpm, uu04_xpm, uu05_xpm, uu06_xpm, uu07_xpm,
        uu10_xpm, uu11_xpm, uu12_xpm, uu13_xpm, uu14_xpm, uu15_xpm, uu16_xpm, uu17_xpm,

        ue00_xpm, ue01_xpm, ue02_xpm, ue03_xpm, ue04_xpm, ue05_xpm, ue06_xpm, ue07_xpm,
        ue10_xpm, ue11_xpm, ue12_xpm, ue13_xpm, ue14_xpm, ue15_xpm, ue16_xpm, ue17_xpm
    };


    char *char_encode[] = {"a", "b", "c", "d", "e", "f", "g", "h", 
                            "i", "j", "k", "l", "m", "n", "o", "p",
                            "q", "r", "s", "t", "u", "v", "w", "x", 
                            "y", "z", "á", "é", "ó", "ö", "ú", "ü"};

    printf("Loading neural network from file... ");
    neural_net = fann_create_from_file("char_recogn.net");

    if (!neural_net) {
        printf("Failed.\n");    
        neural_net = fann_create_standard(3, INPUTS, HIDDEN_NEURONS, OUTPUTS);
        fann_randomize_weights(neural_net, -1, 1);
        // fann_set_activation_function_hidden(neural_net, FANN_LINEAR_PIECE_SYMMETRIC);
        // fann_set_activation_function_output(neural_net, FANN_LINEAR_PIECE_SYMMETRIC);
        // fann_set_activation_function_hidden(nn, FANN_LINEAR);
        // fann_set_activation_function_output(nn, FANN_LINEAR);
        // fann_set_activation_function_hidden(neural_net, FANN_SIGMOID_SYMMETRIC);
        // fann_set_activation_function_output(neural_net, FANN_SIGMOID_SYMMETRIC);
        // fann_set_activation_function_hidden(neural_net, FANN_SIGMOID);
        // fann_set_activation_function_output(neural_net, FANN_SIGMOID);
        // fann_set_activation_function_hidden(neural_net, FANN_GAUSSIAN);
        // fann_set_activation_function_output(neural_net, FANN_GAUSSIAN);
        // fann_set_activation_function_hidden(neural_net, FANN_ELLIOT);
        // fann_set_activation_function_output(neural_net, FANN_ELLIOT);
        fann_set_activation_function_hidden(neural_net, FANN_LINEAR_PIECE);
        fann_set_activation_function_output(neural_net, FANN_LINEAR_PIECE);
        // fann_set_cascade_weight_multiplier(neural_net, 1.0);
    } else
        printf("Ok.\n");    

    fann_print_connections(neural_net);
    fann_print_parameters(neural_net);

    for (count = 0; count <= TEACHINGS; count++) {
        pixmap_index = rand() & (OUTPUTS*(1 << LETTER_SHIFT)-1);
        prepare_pixmap(pixmaps[pixmap_index], pixmap);

        for (cy = 0; cy < PIXMAP_HEIGHT; cy++)
            for (cx = 0; cx < PIXMAP_WIDTH; cx++)
                input_value[cy * PIXMAP_WIDTH + cx] = pixmap[cy][cx];

        for (cx = 0; cx < OUTPUTS; cx++)
            desired_value[cx] = ((pixmap_index >> LETTER_SHIFT) == cx) ? 1 : 0;

        if (!(count % (MODULUS))) {
            putchar('\f');
            printf("--------------------------------------------------------------\n");
            printf("TEACHING:      %d\n\n", count);
            result = fann_run(neural_net, input_value);
            printf("PIXMAP INDEX:  %d    (LETTER: %d - %s)\n", pixmap_index, pixmap_index >> LETTER_SHIFT, char_encode[pixmap_index >> LETTER_SHIFT]);

            for (cx = 0; cx < OUTPUTS; cx++)
                if (result[cx] > 0 || desired_value[cx] > 0)
                    printf("OUTPUT (%s):    %0.8f  (DESIRED: %0.8f)\n", char_encode[cx], result[cx], desired_value[cx]);

            printf("MEAN SQ. ERR.: %2.2f%%\n\n", 100.0 * fann_get_MSE(neural_net));
            print_pixmap(pixmap);
            printf("\n\n");
            fann_save(neural_net, "char_recogn.net");
        }    

        fann_train(neural_net, input_value, desired_value);
    }

    printf("Saving file...\n");
    fann_save(neural_net, "char_recogn.net");
    fann_print_connections(neural_net);
    fann_destroy(neural_net);

    return 0;
}
