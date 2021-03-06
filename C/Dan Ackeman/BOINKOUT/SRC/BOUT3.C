/********************************************
*		bout3.c								*
*											*
*		Based Upon code by					*
*		Samuel Streeper 90/02/26			*
*											*
*	Original Version						*
*	Copyright 1990 by Antic Publishing Inc.	*
*											*
*	miscellaneous boink data and bitmaps	*
*											*
********************************************/

/********************************************
*	monochrome images						*
********************************************/

int monoballs[] = {
0x0070, 0x0007, 0x0000, 0x7000, 0x0700, 0x0070, 0x0007, 0x0000, 0x7000,
0x03dc, 0x003d, 0xc003, 0xec00, 0x3fc0, 0x03bc, 0x003b, 0xc003, 0xfc00,
0x0f8f, 0x00fc, 0x700d, 0xf300, 0xcfb0, 0x0e3f, 0x00f1, 0xf00f, 0xff00,
0x1f0f, 0xc1fc, 0x3c13, 0xf1c1, 0x1f8c, 0x1c3e, 0xc1e1, 0xfc1f, 0xffc0,
0x1fff, 0xe1ff, 0xfe1f, 0xffe1, 0xfffe, 0x1fff, 0xe1ff, 0xfe1f, 0xffe0,
0x23fc, 0x2307, 0xf23c, 0x0fe3, 0xe03e, 0x3fc1, 0xe27f, 0x063f, 0xffe0,
0x23fc, 0x1207, 0xf938, 0x0fd3, 0xe03f, 0x3fc0, 0xf2ff, 0x033f, 0xfff0,
0x43fc, 0x1607, 0xf978, 0x0ff7, 0xe03f, 0x5fc0, 0xf4ff, 0x037f, 0xfff0,
0x43fc, 0x1607, 0xf978, 0x0ff7, 0xe03f, 0x5fc0, 0xf4ff, 0x037f, 0xfff0,
0xc3fc, 0x1e07, 0xf9f8, 0x0fff, 0xe03f, 0xdfc0, 0xfcff, 0x01ff, 0xfff8,
0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xfff8,
0xfe03, 0xfdfc, 0x07cf, 0xf03c, 0x3fc1, 0xe03f, 0x9f80, 0xfdff, 0xfff8,
0x7e03, 0xf5fc, 0x074f, 0xf034, 0x3fc1, 0x603f, 0x9780, 0xfd7f, 0xfff0,
0x7e03, 0xf5fc, 0x074f, 0xf034, 0x3fc1, 0x603f, 0x9780, 0xfd7f, 0xfff0,
0x3e03, 0xf2fc, 0x0f2f, 0xf072, 0x3fc1, 0x303f, 0x9380, 0xfd3f, 0xfff0,
0x3e03, 0xe3fc, 0x0e27, 0xf062, 0x3fc2, 0x303f, 0x23c0, 0xfa3f, 0xffe0,
0x1fff, 0xe1ff, 0xfe1f, 0xffe1, 0xfffe, 0x1fff, 0xe1ff, 0xfe1f, 0xffe0,
0x11f8, 0xc183, 0xec1e, 0x1fc1, 0xf07c, 0x1fc3, 0xc13f, 0x1c1f, 0xffc0,
0x0cfb, 0x00e3, 0xf00f, 0x1f00, 0xf8f0, 0x0fc7, 0x00df, 0x300f, 0xff00,
0x03fc, 0x003b, 0xc003, 0x9c00, 0x3dc0, 0x03dc, 0x003e, 0xc003, 0xfc00,
0x0070, 0x0007, 0x0000, 0x7000, 0x0700, 0x0070, 0x0007, 0x0000, 0x7000
	};

int monobricks[] = {
0x7fff,0xffff,0xff00,0x7bfb,0xfbfb,0xfb00,
		0x71f1,0xf1f1,0xf100,0x60e0,0xe0e0,0xe000,
0xffff,0xffff,0xff80,0xf7f7,0xf7f7,0xf780,
		0xe3e3,0xe3e3,0xe380,0xc1c1,0xc1c1,0xc100,
0xffff,0xffff,0xffa0,0xefef,0xefef,0xefa0,
		0xcfef,0xefef,0xefa0,0x8b8b,0x8b8b,0x8b80,
0xffff,0xffff,0xffd0,0xdfdf,0xdfdf,0xdfd0,
		0x9fdf,0xdfdf,0xdfd0,0x1717,0x1717,0x1710,
0xffff,0xffff,0xffa0,0xbfbf,0xbfbf,0xbfa0,
		0x1fbf,0xbfbf,0xbfa0,0x0e2e,0x2e2e,0x2e20,
0xffff,0xffff,0xffd0,0x7f7f,0x7f7f,0x7f50,
		0x3f7f,0x7f7f,0x7f50,0x1c5c,0x5c5c,0x5c40,
0xffff,0xffff,0xffa0,0xfefe,0xfefe,0xfea0,
		0x7efe,0xfefe,0xfea0,0x38b8,0xb8b8,0xb880,
0xffff,0xffff,0xffd0,0xfdfd,0xfdfd,0xfdc0,
		0xfdfd,0xfdfd,0xfdc0,0x7171,0x7171,0x7100,
0xffff,0xffff,0xffa0,0xfbfb,0xfbfb,0xfb80,
		0xfbfb,0xfbfb,0xfb80,0xe2e2,0xe2e2,0xe280,
0xffff,0xffff,0xffd0,0xf7f7,0xf7f7,0xf7d0,
		0xf7f7,0xf7f7,0xf790,0xc5c5,0xc5c5,0xc580,
0xffff,0xffff,0xffa0,0xefef,0xefef,0xefa0,
		0xcfef,0xefef,0xefa0,0x8b8b,0x8b8b,0x8b80,
0xffff,0xffff,0xffd0,0xdfdf,0xdfdf,0xdfd0,
		0x9fdf,0xdfdf,0xdfd0,0x1717,0x1717,0x1710,
0xffff,0xffff,0xffa0,0xbfbf,0xbfbf,0xbfa0,
		0x1fbf,0xbfbf,0xbfa0,0x0e2e,0x2e2e,0x2e20,
0x7fff,0xffff,0xff50,0x7f7f,0x7f7f,0x7f50,
		0x3f7f,0x7f7f,0x7f50,0x1c5c,0x5c5c,0x5c40,
0x0aaa,0xaaaa,0xaaa0,0x02a2,0xa2a2,0xa2a0,
		0x02a2,0xa2a2,0xa2a0,0x0080,0x8080,0x8080,
0x0555,0x5555,0x5540,0x0545,0x4545,0x4540,
		0x0545,0x4545,0x4540,0x0101,0x0101,0x0100
	};

int mono_perm_bricks[] = {
0x7fff,0xffff,0xff00,0x7fff,0xffff,0xff00,
		0x7fff,0xffff,0xff00,0x6fff,0xffff,0xff00,
0xffff,0xffff,0xff80,0xffff,0xffff,0xff80,
		0xffff,0xffff,0xff80,0xefff,0xffff,0xff80,
0xffff,0xffff,0xffa0,0xffff,0xffff,0xffa0,
		0xefff,0xffff,0xffa0,0xefff,0xffff,0xffa0,
0xff9f,0xfffc,0xffd0,0xefff,0xffff,0xffd0,
		0xc7ff,0xffff,0xffd0,0x01ff,0xffff,0xffd0,
0xfe07,0xfff0,0x3fa0,0xff0f,0xfff8,0x7fa0,
		0xef9f,0xfffc,0xffa0,0xefff,0xffff,0xffa0,
0xfe97,0xfff4,0xbfd0,0xfe97,0xfff4,0xbfd0,
		0xff0f,0xfff8,0x7fd0,0xef9f,0xfffc,0xffd0,
0xfc63,0xffe3,0x1fa0,0xfe67,0xfff3,0x3fa0,
		0xfe67,0xfff3,0x3fa0,0xef6f,0xfffb,0x7fa0,
0xfc63,0xffe3,0x1fd0,0xfe67,0xfff3,0x3fd0,
		0xfe67,0xfff3,0x3fd0,0xff6f,0xfffb,0x7fd0,
0xfe97,0xfff4,0xbfa0,0xfe97,0xfff4,0xbfa0,
		0xff0f,0xfff8,0x7fa0,0xff9f,0xff7c,0xffa0,
0xfe07,0xfff0,0x3fd0,0xff0f,0xfff8,0x7fd0,
		0xff9f,0xfffc,0xffd0,0xffff,0xff7f,0xffd0,
0xff9f,0xfffc,0xffa0,0xffff,0xffff,0xffa0,
		0xffff,0xff7f,0xffa0,0xffff,0xff7f,0xffa0,
0xffff,0xffff,0xffd0,0xffff,0xff7f,0xffd0,
		0xffff,0xfe3f,0xffd0,0xffff,0xf80f,0xffd0,
0xffff,0xffff,0xffa0,0xffff,0xffff,0xffa0,
		0xffff,0xff7f,0xffa0,0xffff,0xff7f,0xffa0,
0x7fff,0xffff,0xff50,0x7fff,0xffff,0xff50,
		0x7fff,0xffff,0xff50,0x7fff,0xff7f,0xff50,
0x0aaa,0xaaaa,0xaaa0,0x0aaa,0xaaaa,0xaaa0,
		0x0aaa,0xaaaa,0xaaa0,0x0aaa,0xaa2a,0xaaa0,
0x0555,0x5555,0x5540,0x0555,0x5555,0x5540,
		0x0555,0x5555,0x5540,0x0555,0x5555,0x5540
	};

int monopaddle[] = {
0x7fff, 0xffff, 0xfffe, 0x0000,
0xffff, 0xffff, 0xffff, 0x0000,
0xffff, 0xffff, 0xffff, 0x4000,
0xffff, 0xffff, 0xffff, 0xa000,
0xffff, 0xffff, 0xffff, 0x5000,
0x7fff, 0xffff, 0xfffe, 0xa000,
0x7fd5, 0x5555, 0x57ff, 0x5000,
0x3fea, 0xaaaa, 0xaffe, 0xa000,
0x1ffc, 0x0000, 0x1ffd, 0x4000,
0x0ffe, 0x0000, 0x7ffa, 0x8000,
0x07ff, 0x8001, 0xfff5, 0x0000,
0x03ff, 0xffff, 0xffea, 0x0000,
0x01ff, 0xffff, 0xffd4, 0x0000,
0x007f, 0xffff, 0xfea8, 0x0000,
0x001f, 0xffff, 0xfd50, 0x0000,
0x0007, 0xffff, 0xeaa0, 0x0000,
0x0001, 0x7fff, 0x5500, 0x0000,
0x0000, 0x2aaa, 0xaa00, 0x0000,
0x0000, 0x0555, 0x4000, 0x0000
	};

int mono_fuji[] = {
0x05a0,0x07e0,0x07e0,0x03e0,0x01e0,0x01e0,0x01e0,
0x05a0,0x07e0,0x07e0,0x03e0,0x01e0,0x01e0,0x01e0,
0x05a0,0x07e0,0x07e0,0x03e0,0x01e0,0x01e0,0x01e0,
0x05a0,0x07e0,0x07e0,0x03e0,0x01e0,0x01e0,0x01e0,
0x0db0,0x0ff0,0x07e0,0x03e0,0x03f0,0x01e0,0x01e0,
0x0db0,0x0ff0,0x0ff0,0x07f0,0x03f0,0x03f0,0x01e0,
0x1db8,0x1ff8,0x0ff0,0x07f0,0x03f0,0x03f0,0x01e0,
0x399c,0x1db8,0x1ff8,0x0ff8,0x07f8,0x03f0,0x01e0,
0x799e,0x3dbc,0x1ff8,0x0ff8,0x07f8,0x03f0,0x01e0,
0x718e,0x399c,0x1db8,0x0ff8,0x07f8,0x03f0,0x01e0,
0x718e,0x399c,0x1db8,0x0ff8,0x07f8,0x03f0,0x01e0,
0x6186,0x318c,0x1998,0x0ff8,0x07f8,0x03f0,0x01e0,
0x4182,0x318c,0x1998,0x0dd8,0x07f8,0x03f0,0x01e0,
	};

int monofuji_mask[] = {
0x0ff0,0x0ff0,0x0ff0,0x07f0,0x03f0,0x03f0,0x03f0,
0x0ff0,0x0ff0,0x0ff0,0x07f0,0x03f0,0x03f0,0x03f0,
0x0ff0,0x0ff0,0x0ff0,0x07f0,0x03f0,0x03f0,0x03f0,
0x0ff0,0x0ff0,0x0ff0,0x07f0,0x03f0,0x03f0,0x03f0,
0x0ff0,0x0ff0,0x0ff0,0x07f0,0x03f0,0x03f0,0x03f0,
0x1ff8,0x1ff8,0x0ff0,0x07f0,0x07f8,0x03f0,0x03f0,
0x1ff8,0x1ff8,0x1ff8,0x0ff8,0x07f8,0x07f8,0x03f0,
0x3ffc,0x3ffc,0x1ff8,0x0ff8,0x07f8,0x07f8,0x03f0,
0x7ffe,0x3ffc,0x3ffc,0x1ffc,0x0ffc,0x07f8,0x03f0,
0xffff,0x7ffe,0x3ffc,0x1ffc,0x0ffc,0x07f8,0x03f0,
0xfbdf,0x7ffe,0x3ffc,0x1ffc,0x0ffc,0x07f8,0x03f0,
0xfbdf,0x7ffe,0x3ffc,0x1ffc,0x0ffc,0x07f8,0x03f0,
0xf3cf,0x7bde,0x3ffc,0x1ffc,0x0ffc,0x07f8,0x03f0,
0xe3c7,0x7bde,0x3ffc,0x1ffc,0x0ffc,0x07f8,0x03f0,
0xe3c7,0x7bde,0x3ffc,0x1ffc,0x0ffc,0x07f8,0x03f0,
	};

int mono_eye[] = {
0x0070,0x0007,0x0000,0x7000,0x0700,0x0070,0x0007,0x0000,0x7000,
0x03ac,0x003a,0xc003,0xac00,0x3ac0,0x03ac,0x003a,0xc003,0xfc00,
0x0d57,0x00d5,0x700d,0x5700,0xd570,0x0d57,0x00d5,0x700f,0xff00,
0x1aaa,0xc1aa,0xac1a,0xaac1,0xaaac,0x1aaa,0xc1aa,0xac1f,0xffc0,
0x17ff,0x617f,0xf617,0xff61,0x7ff6,0x17ff,0x617f,0xf61f,0xffe0,
0x2fff,0xa2ff,0xfa2f,0xffa2,0xfffa,0x2fff,0xa2ff,0xfa3f,0xffe0,
0x3efb,0xd3ef,0xbd3e,0xbbd3,0xfffd,0x3fff,0xd3ff,0xfd3f,0xfff0,
0x79fc,0xf79b,0xcf79,0xbcf7,0xffff,0x7fff,0xf7ff,0xff7f,0xfff0,
0x73be,0x7731,0xe772,0x0e77,0xfbff,0x7fff,0xf7ff,0xff7f,0xfff0,
0xa3fe,0x2a3b,0xe2a3,0xbe2a,0x3fe2,0xbfff,0xebff,0xfeff,0xfff8,
0xc3fe,0x1c3f,0xe1c3,0xbe1c,0x3fe1,0xffff,0xffff,0xffff,0xfff8,
0xa3fe,0x2a3f,0xe2a3,0xfe2a,0x3fe2,0xa3fe,0x2bff,0xfeff,0xfff8,
0x53fe,0x553f,0xe553,0xfe55,0x3fe5,0x53fe,0x553f,0xe57f,0xfff0,
0x69fc,0xb69f,0xcb69,0xfcb6,0x9fcb,0x69fc,0xb69f,0xcb7f,0xfff0,
0x36fb,0x536f,0xb536,0xfb53,0x6fb5,0x36fb,0x536f,0xb53f,0xfff0,
0x2bfe,0xa2bf,0xea2b,0xfea2,0xbfea,0x2bfe,0xa2bf,0xea3f,0xffe0,
0x1555,0x6155,0x5615,0x5561,0x5556,0x1555,0x6155,0x561f,0xffe0,
0x1aaa,0xc1aa,0xac1a,0xaac1,0xaaac,0x1aaa,0xc1aa,0xac1f,0xffc0,
0x0d57,0x00d5,0x700d,0x5700,0xd570,0x0d57,0x00d5,0x700f,0xff00,
0x03ac,0x003a,0xc003,0xac00,0x3ac0,0x03ac,0x003a,0xc003,0xfc00,
0x0070,0x0007,0x0000,0x7000,0x0700,0x0070,0x0007,0x0000,0x7000
	};

int mono_twobrick[] = {
0x0fff,0xffff,0xf800,0x0fff,0xffff,0xf800,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x3fff,0xffff,0xfe00,0x3fff,0xffff,0xfe00,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x7fff,0xffff,0xff00,0x7fff,0xffff,0xff00,
	0x0fff,0xffff,0xf800,0x0000,0x0000,0x0000,
0x7fff,0xffff,0xff40,0x7fff,0xffff,0xff40,
	0x3fff,0xffff,0xfe00,0x0000,0x0000,0x0000,
0xfe73,0x9ce7,0x3fa0,0xffff,0xffff,0xffa0,
	0x7fff,0xffff,0xff00,0x3fff,0xffff,0xfe00,
0xfe23,0x88e2,0x3fc0,0xffff,0xffff,0xffc0,
	0xffff,0xffff,0xffc0,0xffff,0xffff,0xff80,
0xff07,0xc1f0,0x7fa0,0xff00,0x0000,0x7fa0,
	0xf800,0x0000,0x0fa0,0xe000,0x0000,0x0380,
0xff8f,0xe3f8,0xffd0,0xff00,0x0000,0x7fd0,
	0xf800,0x0000,0x0fd0,0xe000,0x0000,0x03d0,
0xff07,0xc1f0,0x7fa0,0xffff,0xffff,0xffa0,
	0xffff,0xffff,0xffa0,0xffff,0xffff,0xffa0,
0xfe23,0x88e2,0x3fd0,0xffff,0xffff,0xffd0,
	0x7fff,0xffff,0xff50,0x3fff,0xffff,0xfe50,
0x7e73,0x9ce7,0x3fa0,0x7fff,0xffff,0xffa0,
	0x3fff,0xffff,0xfea0,0x0aaa,0xaaaa,0xaaa0,
0x7fff,0xffff,0xff50,0x7fff,0xffff,0xff50,
	0x07ff,0xffff,0xfd40,0x0555,0x5555,0x5540,
0x3fff,0xffff,0xfea0,0x3fff,0xffff,0xfea0,
	0x02aa,0xaaaa,0xaa80,0x0000,0x0000,0x0000,
0x0fff,0xffff,0xfd40,0x0fff,0xffff,0xfd40,
	0x0055,0x5555,0x5500,0x0000,0x0000,0x0000,
0x02aa,0xaaaa,0xaa80,0x02aa,0xaaaa,0xaa80,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0155,0x5555,0x5500,0x0155,0x5555,0x5500,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	};

int mono_digits[] = {
0x7c30,0x7878,0xc0f8,0x30fe,0x7c7c,
0xfe70,0xfc7c,0xccf8,0x70fe,0xfefe,
0xc670,0xcc0c,0xccc0,0xe006,0xc6c6,
0xc630,0x0c0c,0xccc0,0xc006,0xc6c6,
0xc630,0x0c0c,0xccf8,0xc00c,0xc6c6,
0xc630,0x1c38,0xccfc,0xfc0c,0x7cfe,
0xc630,0x183c,0xcc0e,0xfe18,0x7c7e,
0xc630,0x380e,0xfc06,0xc618,0xc606,
0xc630,0x7006,0x7c06,0xc618,0xc606,
0xc630,0xe0c6,0x0cce,0xc618,0xc60e,
0xfefc,0xfefe,0x0cfc,0xfe18,0xfe1c,
0x7cfc,0xfe7c,0x0c78,0x7c18,0x7c18
	};

int mono_leveltext[] = {
0xc0f8,0xc6f8,0xc000,
0xc0f8,0xc6f8,0xc000,
0xc0c0,0xc6c0,0xc000,
0xc0c0,0xc6c0,0xc000,
0xc0c0,0xc6c0,0xc000,
0xc0f8,0xc6f8,0xc000,
0xc0f8,0xc6f8,0xc000,
0xc0c0,0xc6c0,0xc000,
0xc0c0,0x6cc0,0xc000,
0xe0e0,0x7ce0,0xe000,
0xfefe,0x38fe,0xfe00,
0x7e7e,0x387e,0x7e00
	};


/*********************************************
	color images
*********************************************/

int medballs[] = {
0x03dc,0x03dc,0x003d,0x003d,0xc003,0xc003,0xec00,0xec00,
	0x3fc0,0x3fc0,0x03bc,0x03bc,0x003b,0x003b,0xc003,0xc003,
	0xfc00,0xfc00,
0x1f0f,0x1f0f,0xc1fc,0xc1fc,0x3c13,0x3c13,0xf1c1,0xf1c1,
	0x1f8c,0x1f8c,0x1c3e,0x1c3e,0xc1e1,0xc1e1,0xfc1f,0xfc1f,
	0xffc0,0xffc0,
0x23fc,0x23fc,0x2307,0x2307,0xf23c,0xf23c,0x0fe3,0x0fe3,
	0xe03e,0xe03e,0x3fe1,0x3fe1,0xe27f,0xe27f,0x863f,0x863f,
	0xffe0,0xffe0,
0x43fc,0x43fc,0x1607,0x1607,0xf978,0xf978,0x0ff7,0x0ff7,
	0xe03f,0xe03f,0x5fe0,0x5fe0,0xf4ff,0xf4ff,0x837f,0x837f,
	0xfff0,0xfff0,
0xc3fc,0xc3fc,0x1e07,0x1e07,0xf9f8,0xf9f8,0x0fff,0x0fff,
	0xe03f,0xe03f,0xdfe0,0xdfe0,0xfcff,0xfcff,0x81ff,0x81ff,
	0xfff8,0xfff8,
0xfe03,0xfe03,0xfdfc,0xfdfc,0x07cf,0x07cf,0xf83c,0xf83c,
	0x3fc1,0x3fc1,0xe03f,0xe03f,0x9f80,0x9f80,0xfdff,0xfdff,
	0xfff8,0xfff8,
0x7e03,0x7e03,0xf5fc,0xf5fc,0x074f,0x074f,0xf834,0xf834,
	0x3fc1,0x3fc1,0x603f,0x603f,0x9780,0x9780,0xfd7f,0xfd7f,
	0xfff0,0xfff0,
0x3e03,0x3e03,0xe3fc,0xe3fc,0x0e27,0x0e27,0xf862,0xf862,
	0x3fc2,0x3fc2,0x303f,0x303f,0x23c0,0x23c0,0xfa3f,0xfa3f,
	0xffe0,0xffe0,
0x11f8,0x11f8,0xc183,0xc183,0xec1e,0xec1e,0x1fc1,0x1fc1,
	0xf07c,0xf07c,0x1fc3,0x1fc3,0xc13f,0xc13f,0x1c1f,0x1c1f,
	0xffc0,0xffc0,
0x03fc,0x03fc,0x003b,0x003b,0xc003,0xc003,0x9c00,0x9c00,
	0x3dc0,0x3dc0,0x03dc,0x03dc,0x003e,0x003e,0xc003,0xc003,
	0xfc00,0xfc00,
};

int medbricks[] = {
0x7fff,0x7fff,0xffff,0xffff,0xff80,0xff80,0x77f7,0x77f7,
	0xf7f7,0xf7f7,0xf780,0xf780,0x67e7,0x67e7,0xe7e7,0xe7e7,
	0xe780,0xe780,0x41c1,0x41c1,0xc1c1,0xc1c1,0xc100,0xc100,
0xffff,0xffff,0xffff,0xffff,0xffd0,0xffd0,0xdfdf,0xdfdf,
	0xdfdf,0xdfdf,0xdfd0,0xdfd0,0x9f9f,0x9f9f,0x9f9f,0x9f9f,
	0x9f90,0x9f90,0x1717,0x1717,0x1717,0x1717,0x1710,0x1710,
0xffff,0xffff,0xffff,0xffff,0xffd0,0xffd0,0x7f7f,0x7f7f,
	0x7f7f,0x7f7f,0x7f50,0x7f50,0x3e7e,0x3e7e,0x7e7e,0x7e7e,
	0x7e50,0x7e50,0x1c5c,0x1c5c,0x5c5c,0x5c5c,0x5c40,0x5c40,
0xffff,0xffff,0xffff,0xffff,0xffd0,0xffd0,0xfdfd,0xfdfd,
	0xfdfd,0xfdfd,0xfdc0,0xfdc0,0xf9f9,0xf9f9,0xf9f9,0xf9f9,
	0xf9c0,0xf9c0,0x7171,0x7171,0x7171,0x7171,0x7100,0x7100,
0xffff,0xffff,0xffff,0xffff,0xffd0,0xffd0,0xf7f7,0xf7f7,
	0xf7f7,0xf7f7,0xf7d0,0xf7d0,0xe7e7,0xe7e7,0xe7e7,0xe7e7,
	0xe790,0xe790,0xc5c5,0xc5c5,0xc5c5,0xc5c5,0xc580,0xc580,
0xffff,0xffff,0xffff,0xffff,0xffd0,0xffd0,0xdfdf,0xdfdf,
	0xdfdf,0xdfdf,0xdfd0,0xdfd0,0x9f9f,0x9f9f,0x9f9f,0x9f9f,
	0x9fd0,0x9fd0,0x1717,0x1717,0x1717,0x1717,0x1710,0x1710,
0x7fff,0x7fff,0xffff,0xffff,0xff50,0xff50,0x7f7f,0x7f7f,
	0x7f7f,0x7f7f,0x7f50,0x7f50,0x3e7e,0x3e7e,0x7e7e,0x7e7e,
	0x7f50,0x7f50,0x1c5c,0x1c5c,0x5c5c,0x5c5c,0x5c40,0x5c40,
0x0555,0x0555,0x5555,0x5555,0x5540,0x5540,0x0545,0x0545,
	0x4545,0x4545,0x4540,0x4540,0x0545,0x0545,0x4545,0x4545,
	0x4540,0x4540,0x0101,0x0101,0x0101,0x0101,0x0100,0x0100,
};

int medpaddle[] = {
0x7fff,0x7fff,0xffff,0xffff,0xfffe,0xfffe,0x0000,0x0000,
0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x4000,0x4000,
0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0x5000,0x5000,
0x7fd5,0x7fd5,0x5555,0x5555,0x57ff,0x57ff,0x5000,0x5000,
0x1ffc,0x1ffc,0x0000,0x0000,0x1ffd,0x1ffd,0x4000,0x4000,
0x07ff,0x07ff,0x8001,0x8001,0xfff5,0xfff5,0x0000,0x0000,
0x01ff,0x01ff,0xffff,0xffff,0xffd4,0xffd4,0x0000,0x0000,
0x001f,0x001f,0xffff,0xffff,0xfd50,0xfd50,0x0000,0x0000,
0x0001,0x0001,0x7fff,0x7fff,0x5500,0x5500,0x0000,0x0000,
0x0000,0x0000,0x0555,0x0555,0x4000,0x4000,0x0000,0x0000,
};

int med_fuji[] = {
0x05a0,0x05a0,0x07e0,0x07e0,0x07e0,0x07e0,0x03e0,0x03e0,
	0x01e0,0x01e0,0x01e0,0x01e0,0x01e0,0x01e0,
0x05a0,0x05a0,0x07e0,0x07e0,0x07e0,0x07e0,0x03e0,0x03e0,
	0x01e0,0x01e0,0x01e0,0x01e0,0x01e0,0x01e0,
0x0db0,0x0db0,0x0ff0,0x0ff0,0x0ff0,0x0ff0,0x07f0,0x07f0,
	0x03f0,0x03f0,0x03f0,0x03f0,0x01e0,0x01e0,
0x3dbc,0x3dbc,0x1db8,0x1db8,0x1ff8,0x1ff8,0x0ff8,0x0ff8,
	0x07f8,0x07f8,0x03f0,0x03f0,0x01e0,0x01e0,
0x799e,0x799e,0x399c,0x399c,0x1db8,0x1db8,0x0ff8,0x0ff8,
	0x07f8,0x07f8,0x03f0,0x03f0,0x01e0,0x01e0,
0x6186,0x6186,0x318c,0x318c,0x1998,0x1998,0x0ff8,0x0ff8,
	0x07f8,0x07f8,0x03f0,0x03f0,0x01e0,0x01e0,
};

int medfuji_mask[] = {
0x0ff0,0x0ff0,0x0ff0,0x0ff0,0x0ff0,0x0ff0,0x07f0,0x07f0,
	0x03f0,0x03f0,0x03f0,0x03f0,0x03f0,0x03f0,
0x0ff0,0x0ff0,0x0ff0,0x0ff0,0x0ff0,0x0ff0,0x07f0,0x07f0,
	0x03f0,0x03f0,0x03f0,0x03f0,0x03f0,0x03f0,
0x1ff8,0x1ff8,0x1ff8,0x1ff8,0x1ff8,0x1ff8,0x0ff8,0x0ff8,
	0x07f8,0x07f8,0x07f8,0x07f8,0x03f0,0x03f0,
0x7ffe,0x7ffe,0x3ffc,0x3ffc,0x3ffc,0x3ffc,0x1ffc,0x1ffc,
	0x0ffc,0x0ffc,0x07f8,0x07f8,0x03f0,0x03f0,
0xffff,0xffff,0x7ffe,0x7ffe,0x3ffc,0x3ffc,0x1ffc,0x1ffc,
	0x0ffc,0x0ffc,0x07f8,0x07f8,0x03f0,0x03f0,
0xffff,0xffff,0x7ffe,0x7ffe,0x3ffc,0x3ffc,0x1ffc,0x1ffc,
	0x0ffc,0x0ffc,0x07f8,0x07f8,0x03f0,0x03f0,
0xffff,0xffff,0x7ffe,0x7ffe,0x3ffc,0x3ffc,0x1ffc,0x1ffc,
	0x0ffc,0x0ffc,0x07f8,0x07f8,0x03f0,0x03f0,
0xf3cf,0xf3cf,0x7bde,0x7bde,0x3ffc,0x3ffc,0x1ffc,0x1ffc,
	0x0ffc,0x0ffc,0x07f8,0x07f8,0x03f0,0x03f0,
};

int med_perm_bricks[] = {
0x7fff,0x7fff,0xffff,0xffff,0xff80,0xff80,0x7fff,0x7fff,
	0xffff,0xffff,0xff80,0xff80,0x6fff,0x6fff,0xffff,0xffff,
	0xff80,0xff80,0x6fff,0x6fff,0xffff,0xffff,0xff80,0xff80,
0xff9f,0xff9f,0xfffc,0xfffc,0xffd0,0xffd0,0xefff,0xefff,
	0xffff,0xffff,0xffd0,0xffd0,0xc7ff,0xc7ff,0xffff,0xffff,
	0xffd0,0xffd0,0x01ff,0x01ff,0xffff,0xffff,0xffd0,0xffd0,
0xfe97,0xfe97,0xfff4,0xfff4,0xbfd0,0xbfd0,0xfe97,0xfe97,
	0xfff4,0xfff4,0xbfd0,0xbfd0,0xef9f,0xef9f,0xfffc,0xfffc,
	0xffd0,0xffd0,0xefdf,0xefdf,0xfffe,0xfffe,0xffd0,0xffd0,
0xfc63,0xfc63,0xffe3,0xffe3,0x1fd0,0x1fd0,0xfe67,0xfe67,
	0xfff3,0xfff3,0x3fd0,0x3fd0,0xfe67,0xfe67,0xfff3,0xfff3,
	0x3fd0,0x3fd0,0xefaf,0xefaf,0xff7d,0xff7d,0x7fd0,0x7fd0,
0xfe97,0xfe97,0xfff4,0xfff4,0xbfd0,0xbfd0,0xfe97,0xfe97,
	0xfff4,0xfff4,0xbfd0,0xbfd0,0xff9f,0xff9f,0xff7c,0xff7c,
	0xffd0,0xffd0,0xffdf,0xffdf,0xff7e,0xff7e,0xffd0,0xffd0,
0xff9f,0xff9f,0xfffc,0xfffc,0xffd0,0xffd0,0xffff,0xffff,
	0xff7f,0xff7f,0xffd0,0xffd0,0xffff,0xffff,0xfe3f,0xfe3f,
	0xffd0,0xffd0,0xffff,0xffff,0xf80f,0xf80f,0xffd0,0xffd0,
0x7fff,0x7fff,0xffff,0xffff,0xff50,0xff50,0x7fff,0x7fff,
	0xffff,0xffff,0xff50,0xff50,0x7fff,0x7fff,0xff7f,0xff7f,
	0xff50,0xff50,0x7fff,0x7fff,0xff7f,0xff7f,0xff50,0xff50,
0x0555,0x0555,0x5555,0x5555,0x5540,0x5540,0x0555,0x0555,
	0x5555,0x5555,0x5540,0x5540,0x0555,0x0555,0x5555,0x5555,
	0x5540,0x5540,0x0555,0x0555,0x5555,0x5555,0x5540,0x5540,
};

int med_twobrick[] = {
0x0fff,0x0fff,0xffff,0xffff,0xf800,0xf800,0x0fff,0x0fff,
	0xffff,0xffff,0xf800,0xf800,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x7fff,0x7fff,0xffff,0xffff,0xff00,0xff00,0x7fff,0x7fff,
	0xffff,0xffff,0xff00,0xff00,0x0fff,0x0fff,0xffff,0xffff,
	0xf800,0xf800,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0xfe73,0xfe73,0x9ce7,0x9ce7,0x3fa0,0x3fa0,0xffff,0xffff,
	0xffff,0xffff,0xffa0,0xffa0,0x7fff,0x7fff,0xffff,0xffff,
	0xff00,0xff00,0x3fff,0x3fff,0xffff,0xffff,0xfe00,0xfe00,
0xff07,0xff07,0xc1f0,0xc1f0,0x7fa0,0x7fa0,0xff00,0xff00,
	0x0000,0x0000,0x7fa0,0x7fa0,0xf800,0xf800,0x0000,0x0000,
	0x0fa0,0x0fa0,0xe000,0xe000,0x0000,0x0000,0x0380,0x0380,
0xff07,0xff07,0xc1f0,0xc1f0,0x7fa0,0x7fa0,0xffff,0xffff,
	0xffff,0xffff,0xffa0,0xffa0,0xffff,0xffff,0xffff,0xffff,
	0xffa0,0xffa0,0x3fff,0x3fff,0xffff,0xffff,0xfe20,0xfe20,
0x7e73,0x7e73,0x9ce7,0x9ce7,0x3fa0,0x3fa0,0x7fff,0x7fff,
	0xffff,0xffff,0xffa0,0xffa0,0x3fff,0x3fff,0xffff,0xffff,
	0xfea0,0xfea0,0x0aaa,0x0aaa,0xaaaa,0xaaaa,0xaa80,0xaa80,
0x3fff,0x3fff,0xffff,0xffff,0xfea0,0xfea0,0x3fff,0x3fff,
	0xffff,0xffff,0xfea0,0xfea0,0x02aa,0x02aa,0xaaaa,0xaaaa,
	0xaa80,0xaa80,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x02aa,0x02aa,0xaaaa,0xaaaa,0xaa80,0xaa80,0x02aa,0x02aa,
	0xaaaa,0xaaaa,0xaa80,0xaa80,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

int med_digits[] = {
0x7c30,0x7c30,0x7878,0x7878,0xc0f8,0xc0f8,0x30fe,0x30fe,0x7c7c,0x7c7c,
0xc670,0xc670,0xcc0c,0xcc0c,0xccc0,0xccc0,0xe006,0xe006,0xc6c6,0xc6c6,
0xc630,0xc630,0x0c0c,0x0c0c,0xccf8,0xccf8,0xc00c,0xc00c,0xc6c6,0xc6c6,
0xc630,0xc630,0x183c,0x183c,0xcc0e,0xcc0e,0xfe18,0xfe18,0x7c7e,0x7c7e,
0xc630,0xc630,0x7006,0x7006,0x7c06,0x7c06,0xc618,0xc618,0xc606,0xc606,
0xfefc,0xfefc,0xfefe,0xfefe,0x0cfc,0x0cfc,0xfe18,0xfe18,0xfe1c,0xfe1c,
};

int med_leveltext[] = {
0xc0f8,0xc0f8,0xc6f8,0xc6f8,0xc000,0xc000,
0xc0c0,0xc0c0,0xc6c0,0xc6c0,0xc000,0xc000,
0xc0f8,0xc0f8,0xc6f8,0xc6f8,0xc000,0xc000,
0xc0c0,0xc0c0,0xc6c0,0xc6c0,0xc000,0xc000,
0xe0e0,0xe0e0,0x7ce0,0x7ce0,0xe000,0xe000,
0x7e7e,0x7e7e,0x387e,0x387e,0x7e00,0x7e00,
};

int med_eye[] = {
0x03ac,0x03ac,0x003a,0x003a,0xc003,0xc003,0xac00,0xac00,
	0x3ac0,0x3ac0,0x03ac,0x03ac,0x003a,0x003a,0xc003,0xc003,
	0xfc00,0xfc00,
0x1aaa,0x1aaa,0xc1aa,0xc1aa,0xac1a,0xac1a,0xaac1,0xaac1,
	0xaaac,0xaaac,0x1aaa,0x1aaa,0xc1aa,0xc1aa,0xac1f,0xac1f,
	0xffc0,0xffc0,
0x2fff,0x2fff,0xa2ff,0xa2ff,0xfa2f,0xfa2f,0xffa2,0xffa2,
	0xfffa,0xfffa,0x2fff,0x2fff,0xa2ff,0xa2ff,0xfa3f,0xfa3f,
	0xffe0,0xffe0,
0x79fc,0x79fc,0xf79f,0xf79f,0xcf79,0xcf79,0xbcf7,0xbcf7,
	0xffff,0xffff,0x7fff,0x7fff,0xf7ff,0xf7ff,0xff7f,0xff7f,
	0xfff0,0xfff0,
0xa3fe,0xa3fe,0x2a3b,0x2a3b,0xe2a3,0xe2a3,0x1e2a,0x1e2a,
	0x3fe2,0x3fe2,0xbfff,0xbfff,0xebff,0xebff,0xfeff,0xfeff,
	0xfff8,0xfff8,
0xa3fe,0xa3fe,0x2a3f,0x2a3f,0xe2a3,0xe2a3,0xbe2a,0xbe2a,
	0x3fe2,0x3fe2,0xa3fe,0xa3fe,0x2bff,0x2bff,0xfeff,0xfeff,
	0xfff8,0xfff8,
0x69fc,0x69fc,0xb69f,0xb69f,0xcb69,0xcb69,0xfcb6,0xfcb6,
	0x9fcb,0x9fcb,0x69fc,0x69fc,0xb69f,0xb69f,0xcb7f,0xcb7f,
	0xfff0,0xfff0,
0x2bfe,0x2bfe,0xa2bf,0xa2bf,0xea2b,0xea2b,0xfea2,0xfea2,
	0xbfea,0xbfea,0x2bfe,0x2bfe,0xa2bf,0xa2bf,0xea3f,0xea3f,
	0xffe0,0xffe0,
0x1aaa,0x1aaa,0xc1aa,0xc1aa,0xac1a,0xac1a,0xaac1,0xaac1,
	0xaaac,0xaaac,0x1aaa,0x1aaa,0xc1aa,0xc1aa,0xac1f,0xac1f,
	0xffc0,0xffc0,
0x03ac,0x03ac,0x003a,0x003a,0xc003,0xc003,0xac00,0xac00,
	0x3ac0,0x3ac0,0x03ac,0x03ac,0x003a,0x003a,0xc003,0xc003,
	0xfc00,0xfc00,
};
	
