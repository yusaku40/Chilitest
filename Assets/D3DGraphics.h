/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.04.24											  *	
 *	D3DGraphics.h																		  *
 *	Copyright 2012 PlanetChili <http://www.planetchili.net>								  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include <d3d9.h>
#include "Utilies.h"

//Simple color system
class Color {		
public:
	Color(int r, int g, int b);

	int r;
	int g;
	int b;
};


class D3DGraphics
{
public:
	D3DGraphics( HWND hWnd );
	~D3DGraphics();
	void PutPixel( int x,int y,int r,int g,int b );
	void PutPixel(int x, int y, Color color);	// simple overload to use Color class
	void DrawLine( int x1,int y1,int x2,int y2,int r,int g,int b );
	void DrawLine(int x1, int y1, int x2, int y2, Color color); // Simple overload to use Color class
	void DrawLine(Vec2 v1, Vec2 v2, Color color);	// Overload to use Vec2s and Color
	void DrawCircle( int cx,int cy,int radius,int r,int g,int b );
	void DrawDisc( int cx,int cy,int r,int rd,int g,int b );
	void DrawFilledRect(int x1, int y1, int x2, int y2, Color color);
	void BeginFrame();
	void EndFrame();
private:
	IDirect3D9*			pDirect3D;
	IDirect3DDevice9*	pDevice;
	IDirect3DSurface9*	pBackBuffer;
	D3DLOCKED_RECT		backRect;
};