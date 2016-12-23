/****************************************************************************************** 
Font Lib test

 ******************************************************************************************/
#include "Font.h"
#include "D3DGraphics.h"

Font::Font()

{}

Color::Color(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

Vec2::Vec2()
{
	a = 0;
	b = 0;
}

Vec2::Vec2(int a, int b)
{
	this->a = a;
	this->b = b;
}

GlyphVector::GlyphVector(int lcount)
{
	this->linecount = lcount;
}


bool Font::PrintGlyph(D3DGraphics& gRef,int glyph,int startX,int startY,Color color )
{
	GlyphVector g(4);
	
	switch (glyph){
		case 65 :// cap A
			gRef.DrawLine(startX, startY, startX + 3, startY - 10, color.r, color.g, color.b);
			gRef.DrawLine(startX + 1, startY, startX + 4, startY - 10, color.r, color.g, color.b);
			gRef.DrawLine(startX + 3, startY - 10, startX + 6, startY , color.r, color.g, color.b);
			gRef.DrawLine(startX + 4, startY - 10, startX + 7, startY, color.r, color.g, color.b);
			gRef.DrawLine(startX + 2, startY - 2, startX + 5, startY - 2, color.r, color.g, color.b);
			return true;
			break;
		case 66 :  // B
			gRef.DrawLine(startX, startY, startX , startY - 10, color.r, color.g, color.b);
			gRef.DrawLine(startX , startY - 10, startX + 5, startY - 10, color.r, color.g, color.b);
			gRef.DrawLine(startX + 5, startY -10, startX + 5, startY - 5, color.r, color.g, color.b);
			gRef.DrawLine(startX + 5, startY -5, startX, startY - 5, color.r, color.g, color.b);
			gRef.DrawLine(startX + 5, startY - 5, startX + 5, startY, color.r, color.g, color.b);
			gRef.DrawLine(startX + 5, startY, startX, startY , color.r, color.g, color.b);
			return true;
			break;
		case 67 : //  C
			gRef.DrawLine(startX , startY, startX + 5, startY, color.r, color.g, color.b);
			gRef.DrawLine(startX , startY, startX, startY - 10, color.r, color.g, color.b);
			gRef.DrawLine(startX, startY -10, startX + 5, startY - 10, color.r, color.g, color.b);
			return true;
		case 68 : //  D
			g.linecount = 4;
			g.points[0] = {startX, startY };
			g.points[1] = {startX, startY - 10 };
			g.points[2] = { startX + 5, startY- 10 };
			g.points[3] = { startX + 5, startY };
			g.points[4] = { startX, startY };
			for (int i = 0; i < g.linecount;i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color.r, color.g, color.b);
			}

			
			return true;
			break;

		default:
			return false;
			
	}
		
	
	
	
}

