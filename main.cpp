#include "constants.hpp"
// #include "util.hpp"


inline void set_video_mode(u8 mode)
{
	ioram[0] = mode; 
}

inline void enable_bg(u8 layer)
{
	ioram[1] = 1 << layer; // Enable BG2 (BG0 = 1, BG1 = 2, BG2 = 4, ...)
}

inline void draw_pixel(int x, int y, u16 col)
{
    vram[y * screen_width + x] = col;
}

inline void draw_rect(int x, int y, int w, int h, u16 col)
{
    for(int yy=0; yy<h; ++yy) {
        for(int xx=0; xx<w; ++xx) {
            draw_pixel(x+xx, y+yy, col);
        }
    }
}

int main()
{
    set_video_mode(3); // Use video mode 3 (in BG2, a 16bpp bitmap in VRAM)
    enable_bg(2);

    for(int t=0;;++t) {
        for(int y=0; y<screen_height; ++y) {
            for(int x=0; x<screen_width; ++x) {
                u16 col = ((y-x) ^ (y+x)) * t;
                //draw_pixel(x, y, col);
                draw_rect(x, y, 1, 1, col);
            }
        }
    }

    return 0;
}

