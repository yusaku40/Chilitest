/****************************************************************************************** 
Font Lib test

 ******************************************************************************************/
#include "Font.h"
#include "D3DGraphics.h"

Font::Font()

{}

bool Font::PrintGlyph(D3DGraphics& gRef,int glyph,int startX,int startY)
{
	if (glyph = 65) { // cap A
		gRef.DrawLine(startX, startY, startX + 5, startY - 10, 0, 255, 0);
		gRef.DrawLine(startX + 5, startY - 10, startX + 10, startY , 0, 255, 0);
		gRef.DrawLine(startX + 3, startY - 5, startX + 7, startY - 5, 0, 255, 0);
	
		return true;
	}
	else {
		return false;
	}
	
	
	
}
