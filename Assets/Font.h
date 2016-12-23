#pragma once

#include "D3DGraphics.h"


class Color {
public:
	Color(int r, int g, int b);

	int r;
	int g;
	int b;
};

class Vec2 {
public:
	Vec2();
	Vec2(int a, int b);
	int a;
	int b;
};

class GlyphVector {
public:
	GlyphVector(int lcount);
	int linecount;
	Vec2 points[10];

};

class Font {
public:				//public methods
	Font();
	
	bool PrintGlyph(D3DGraphics& gRef, int glyph,int startX,int startY,Color color);

private:			//private vars
	

public:				//public vars
	


};

