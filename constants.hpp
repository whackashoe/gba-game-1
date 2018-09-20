#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

using u8    = unsigned char;
using u16   = unsigned short;
using u32   = unsigned int;
using uint  = unsigned int;
using vu8   = volatile unsigned char;
using vu16  = volatile unsigned short;
using vu32  = volatile unsigned int;
using vuint = volatile unsigned int;

constexpr u16 screen_width  = 240;
constexpr u16 screen_height = 160;

vu8 *ioram = reinterpret_cast<u8 *>(0x04000000);
vu16 *vram = reinterpret_cast<u16 *>(0x06000000);

#endif

