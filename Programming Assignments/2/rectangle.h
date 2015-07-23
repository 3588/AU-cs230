/* 
 * File:   rectangle.h
 * Author: huangjunjun
 *
 * Created on 2011年9月19日, 下午5:29
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H
class Rectangle
{
public:
	bool CheckInput();
	void SetData(int ,int , int , int , int , int ,int, int);
	void GetData();//test
	bool Getlarger();
	void GetDataLength(char);//length. It returns the larger of the two dimensions as the length.  
	void GetDataWidth(char);//width. It returns the smaller of the two dimensions as the width.  
	void GetDataPerimeter();//perimeter. It calculates the perimeter of the rectangle.  
	void GetDataArea();//	area. It calculates the area of the rectangle.  
	bool IfDataSquare();//	square. It determines if the rectangle is a square.  
	void GetDataDraw(char);//	draw. It displays the rectangle inside a 25-by-25 box enclosing the portion of the first quadrant.  
	void setFillCharacter();//	setFillCharacter. It specifies the character out of which the body of the rectangle will be drawn.  
	void setPerimeterCharacter();//setPerimeterCharacter. It specifies the character that will be used to draw the border of the rectangle.  
private:
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;

};
#endif

