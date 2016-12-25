/****************************************************************************************** 
Font Lib test

 ******************************************************************************************/
#include "Font.h"
#include "D3DGraphics.h"

Font::Font()

{}


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
		case 48 :	// 0
			g.linecount = 5;
			g.points[0] = { startX, startY };
			g.points[1] = { startX, startY - 10 };
			g.points[2] = { startX + 6, startY - 10 };
			g.points[3] = { startX + 6, startY };
			g.points[4] = { startX + 1, startY };
			g.points[5] = { startX + 6, startY - 10 };

			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color);
			}
			return true;
			break;
		case 49:	// 1
			g.linecount = 1;
			g.points[0] = { startX +3, startY };
			g.points[1] = { startX + 3, startY - 10 };

			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color);
			}
			return true;
			break;

		case 50:	//  2
			g.linecount = 4;
			g.points[0] = { startX , startY - 9 };
			g.points[1] = { startX +3 , startY - 10 };
			g.points[2] = { startX +6 , startY - 8 };
			g.points[3] = { startX , startY  };
			g.points[4] = { startX + 6 , startY  };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color);
			}
			return true;
			break;
		case 51:	//  3
			g.linecount = 6;
			g.points[0] = { startX , startY};
			g.points[1] = { startX + 6 , startY };
			g.points[2] = { startX + 6 , startY -4 };
			g.points[3] = { startX , startY -5};
			g.points[4] = { startX + 6 , startY-6 };
			g.points[5] = { startX + 6 , startY -9 };
			g.points[6] = { startX  , startY -10 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color);
			}
			return true;
			break;

		case 52:	// 4
			g.linecount = 3;
			g.points[0] = { startX +4 , startY };
			g.points[1] = { startX +4 , startY -10 };
			g.points[2] = { startX  , startY - 3 };
			g.points[3] = { startX +6  , startY - 3 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color);
			}
			return true;
			break;

		case 58 :	// :
			g.linecount = 1;
			g.points[0] = { startX + 3 , startY -2 };
			g.points[1] = { startX + 3 , startY - 4 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color);
			}
			g.points[0] = { startX + 3 , startY - 6 };
			g.points[1] = { startX + 3 , startY - 8 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color);
			}
			return true;
			break;

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
			gRef.DrawLine(startX + 1, startY, startX+1, startY - 10, color.r, color.g, color.b);
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
			break;
		case 68 : //  D
			g.linecount = 5;
			g.points[0] = {startX, startY };
			g.points[1] = {startX, startY - 10 };
			g.points[2] = { startX + 6, startY- 10 };
			g.points[3] = { startX + 6, startY };
			g.points[4] = { startX + 1, startY };
			g.points[5] = { startX + 1, startY - 10};
			for (int i = 0; i < g.linecount;i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color.r, color.g, color.b);
			}
			return true;
			break;

		case 88 :	//  X
			g.linecount = 4;
			g.points[0] = { startX, startY };
			g.points[1] = { startX + 6, startY - 10 };
			g.points[2] = { startX + 3, startY -5 };
			g.points[3] = { startX , startY -10 };
			g.points[4] = { startX + 6 , startY  };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color.r, color.g, color.b);
			}
			return true;
			break;

		case 89:	//  Y
			g.linecount = 4;
			g.points[0] = { startX + 3, startY };
			g.points[1] = { startX + 3, startY - 5 };
			g.points[2] = { startX , startY - 10 };
			g.points[3] = { startX + 3, startY - 5 };
			g.points[4] = { startX + 6 , startY - 10 };
			for (int i = 0; i < g.linecount; i++) {
				gRef.DrawLine(g.points[i].a, g.points[i].b, g.points[i + 1].a, g.points[i + 1].b, color.r, color.g, color.b);
			}
			return true;
			break;

		default:
			return false;
			
	}
		
	
	
	
}

