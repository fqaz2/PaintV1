#include "PaintV1.h"

#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace System::Drawing;
using namespace System::Drawing::Imaging;
#pragma comment(lib, "user32.lib")

using namespace System;
using namespace System::Windows::Forms;
class shape {
public:
	void draw();
};


[STAThreadAttribute]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    PaintV1::PaintV1 form;
    Application::Run(% form);
}
struct Vector2D {
    int X,
        Y;
};
Vector2D mousePosition;
System::Void PaintV1::PaintV1::PaintV1_Load(System::Object^ sender, System::EventArgs^ e)
{
	brush = gcnew SolidBrush(Color::Red);

	size = 4;
	pen = gcnew Pen(Color::Red, size);
	points = gcnew List <Point>();
	draw = false;
	statePen = 1;

	buttonLine->BackColor = Color::Green;

	buttonCircle->BackColor = Color::LightGray;
	buttonRectangle->BackColor = Color::LightGray;
	buttonTriangle->BackColor = Color::LightGray;

	Bitmap^ Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	canvas = Graphics::FromImage(Img);
	pictureBox1->Image = Img;
	pictureBox1->BackColor = Color::White;
	bitmap = gcnew Bitmap(pictureBox1->Image, pictureBox1->Width, pictureBox1->Height);

	numericUpDownShapeWidth->Minimum = 10;
	numericUpDownShapeHeight->Minimum = 10;
	numericUpDownShapeWidth->Maximum = GetSystemMetrics(SM_CXSCREEN);
	numericUpDownShapeHeight->Maximum = GetSystemMetrics(SM_CYSCREEN);

	clearAll = false;
	filename = "openFileDialog1";

	buttonPenColor->BackColor = pen->Color;
	buttonBrushColor->BackColor = brush->Color;

	return System::Void();
}
System::Void PaintV1::PaintV1::pictureBox1_SizeChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (pictureBox1->Image) {
		 
		if (bitmap)
			bitmap = gcnew Bitmap(bitmap, pictureBox1->Width, pictureBox1->Height);
		else
			bitmap = gcnew Bitmap(pictureBox1->Image, pictureBox1->Width, pictureBox1->Height);

		/*delete canvas;
		canvas = Graphics::FromImage(bitmap);*/
		pictureBox1->Image = bitmap;
		pictureBox1->Refresh();
		pictureBox1->Invalidate();
	}
}

System::Void PaintV1::PaintV1::pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (statePen == 1) {
		points->Clear();
		points->Add(e->Location);
		draw = true;

		pictureBox1->SizeMode = PictureBoxSizeMode::Normal;
	}
	else {
		mousePosition.X = e->Location.X;
		mousePosition.Y = e->Location.Y;
	}
	pictureBox1->Invalidate();
}
System::Void PaintV1::PaintV1::pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (draw && points->Contains(Point(e->X, e->Y)) == false) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			points->Add(e->Location);
		}
		pictureBox1->Invalidate();
	}
}
System::Void PaintV1::PaintV1::pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	draw = false;
	pictureBox1->Invalidate();

	mousePosition.X = -1;
	mousePosition.Y = -1;
}

struct point {
	int x;
	int y;
};
#pragma unmanaged
extern "C" void __cdecl set_points(std::vector<point> &vec, int x, int y)
{
	point p;
	p.x = x;
	p.y = y;
	vec.push_back(p);
}
std::vector<point> fillRectangle(int width, int height, int mouseX, int mouseY)
{
	std::vector<point> points;
	std::vector<point>* points_ptr = &points;   

	int i = mouseX, j = mouseY;
	_asm {
	l1:
		push j; set_points( x, y)
		push i
		mov ecx, points_ptr
		push ecx
		call set_points
		pop ecx
		pop ecx
		pop ecx
			
		inc j
		mov eax, mouseY
		add eax, height
		cmp j, eax; i <= mouseY + height ? goto l1;
			jle l1

		mov edx, mouseY
		mov j, edx
		
		inc i
		mov eax, mouseX
		add eax, width
		cmp i, eax; i <= mouseY + height ? goto l1;
			jle l1
	}
	return points;
}
std::vector<point> drawRectangle(int width, int height, int mouseX, int mouseY)
{
	std::vector<point> points;
	std::vector<point>* points_ptr = &points;

	int i = mouseX, j = mouseY;
	_asm {
	l1:
		push j
		push i
		mov eax, points_ptr
		push eax
		call set_points
		pop eax
		pop eax
		pop eax

		mov eax, j
		add eax, height

		push eax
		push i
		mov ebx, points_ptr
		push ebx
		call set_points
		pop ebx
		pop ebx
		pop ebx

		inc i
		mov eax, mouseX
		add eax, width
		cmp i, eax; i <= mouseX + width ? goto l1;
			jle l1
		
		mov eax, mouseX
		mov i, eax 

	l2:
		push j
		push i
		mov eax, points_ptr
		push eax
		call set_points
		pop eax
		pop eax
		pop eax

		mov eax, i
		add eax, height

		push j
		push eax
		mov ebx, points_ptr
		push ebx
		call set_points
		pop ebx
		pop ebx
		pop ebx

		inc j
		mov eax, mouseY
		add eax, height
		cmp j, eax; i <= mouseY + height ? goto l2;
			jle l2
	}
	return points;
}
std::vector<point> fillTriangle(int width, int height, int mouseX, int mouseY)
{
	std::vector<point> points;
	std::vector<point>* points_ptr = &points;
	struct point p;
	int i = 0;
	int j = height;
	
	_asm 
	{
	l1:
		mov eax, height
		mov j, eax
	l2:
			mov eax, mouseX
			add eax, i

			mov ebx, mouseY
			add ebx, j

			push ebx; set_points(x, y)
			push eax
			mov edx, points_ptr
			push edx
			call set_points
			pop edx
			pop edx
			pop edx

			dec j
			mov ecx, height
			mov eax, i
			mov ebx, 2
			imul ebx
			imul height
			mov edx, 0
			mov ebx, width
			div ebx
			sub ecx, eax

			cmp j, ecx; j > height - i * 2 * height / width ? goto l2;
				jg l2
			
			mov eax, height
			mov j, eax
	l3:
			mov ecx, mouseX
			add ecx, i
			mov eax, width
			mov edx, 0
			mov ebx, 2
			div ebx
			add ecx, eax
			mov eax, ecx

			mov ebx, mouseY
			add ebx, j

			push ebx; set_points(x, y)
			push eax
			mov edx, points_ptr
			push edx
			call set_points
			pop edx
			pop edx
			pop edx

			dec j
			mov eax, i
			mov ebx, 2
			imul ebx
			imul height
			mov edx, 0
			mov ebx, width
			div ebx

			cmp j, eax; j > i * 2 * height / width ? goto l2;
				jg l3
		inc i
		mov eax, width
		mov edx, 0
		mov ebx, 2
		div ebx
		cmp i, eax; i <= width / 2 ? goto l1;
			jle l1
	}
	/*do
	{
		int j = height;
		do
		{
			p.x = mouseX + i;
			p.y = mouseY + j;
			points.emplace_back(p);
			j--;
		} while (j > height - i * 2 * height / width);
		j = height;
		do
		{
			p.x = mouseX + i + width / 2;
			p.y = mouseY + j;
			points.emplace_back(p);
			j--;
		} while (j > i * 2 * height / width);
		i++;
	} while (i <= width / 2);*/

	return points;
}
std::vector<point> drawTriangle(int width, int height, int mouseX, int mouseY)
{
	std::vector<point> points;
	std::vector<point>* points_ptr = &points;
	struct point p;
	int i = 0, j = 0;
	_asm {
	l1:
		mov ecx, mouseX

		mov eax, width
		mov edx, 0
		mov ebx, 2
		idiv ebx
		add ecx, eax;ecx = mouseX + width / 2

		mov eax, width
		imul j
		mov edx, 0
		mov ebx, 2
		idiv ebx
		mov edx, 0
		mov ebx, height
		idiv ebx
		add ecx, eax; ecx = mouseX + width / 2 + width * j / 2 / height

		mov eax, j
		add eax, mouseY

		push eax; set_points(x, y)
		push ecx
 		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		mov ecx, mouseX

		mov eax, width
		mov edx, 0
		mov ebx, 2
		idiv ebx
		add ecx, eax; ecx = mouseX + width / 2


		mov eax, width
		imul j
		mov edx, 0
		mov ebx, 2
		idiv ebx
		mov edx, 0
		mov ebx, height
		idiv ebx
		sub ecx, eax; ecx = mouseX + width / 2 - width * j / 2 / height

		mov eax, j
		add eax, mouseY

		push eax; set_points(x, y)
		push ecx
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		inc j
		mov eax, height
		cmp j, eax; j <= height ? goto l1;
			jle l1

	l2:
		mov ecx, mouseY
		add ecx, height;ecx = mouseY + height

		mov eax, i
		mov ebx, 2
		imul ebx
		imul height
		mov edx, 0
		mov ebx, width
		div ebx
		sub ecx, eax; mouseY - i * 2 * height / width;

		mov eax, mouseX
		add eax, i

		push ecx; set_points(x, y)
		push eax
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		mov ecx, mouseX
		add ecx, i; ecx = mouseX + i

		mov eax, width
		mov edx, 0
		mov ebx, 2
		div ebx
		add ecx, eax; ecx = mouseX + i + width / 2
		mov j, ecx

		mov ecx, mouseY; ecx = mouseY

		mov eax, i
		mov bx, 2
		mul bx
		imul height
		mov edx, 0
		mov ebx, width
		div ebx
		add ecx, eax

		push ecx; set_points(x, y)
		push j
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		inc i
		mov eax, width
		mov edx, 0
		mov ebx, 2
		idiv ebx
		cmp i, eax; i <= width / 2 ? goto l2;
			jle l2

		mov i, 0
	l3:
		mov eax, mouseX
		add eax, i

		mov ebx, mouseY
		add ebx, height

		push ebx; set_points(x, y)
		push eax
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx
		
		inc i
		mov eax, width
		cmp i, eax; i <= width ? goto l3;
			jle l3
	}
	/*int i = 0, j = 0;
	do
	{
		p.x = mouseX + width / 2 + width * j / 2 / height;
		p.y = mouseY + j;
		points.emplace_back(p);

		p.x = mouseX + width / 2 - width * j / 2 / height;
		p.y = mouseY + j;
		points.emplace_back(p);

		j++;
	} while (j <= height);*/

	/*do
	{
		p.x = mouseX + i;
		p.y = mouseY + height - i * 2 * height / width;
		points.emplace_back(p);

		p.x = mouseX + i + width / 2;
		p.y = mouseY + i * 2 * height / width;
		points.emplace_back(p);
		i++;
	} while (i <= width / 2);*/

	/*i = 0;
	do
	{
		p.x = mouseX + i;
		p.y = mouseY + height;
		points.emplace_back(p);
		i++;
	} while (i <= width);*/

	return points;
}
int temp = 0;
extern "C" void __cdecl CDECLsqrt(int x)
{
	temp = sqrt(x);
}
extern "C" void __cdecl formule(int x, int y, int i)//y * sqrt(x * x / 4 - (i * i)) / x
{		
	temp = y * sqrt(x * x / 4 - (i * i)) / x;

	/*_asm
	{
		mov eax, x; eax = x
		imul x; eax = x * x
		mov edx, 0
		mov ebx, 4
		div ebx; eax = x * x / 4
		mov ecx, eax; ecx = x * x / 4

		mov eax, i
		imul i; i * i

		sub ecx, eax; x* x / (i * i)

		push ecx; CDECLsqrt(x)
		call CDECLsqrt
		pop ecx

		mov eax, y
		imul temp; y * sqrt(x / 2 * x / 2 - (i * i))
		mov edx, 0
		mov ebx, x
		div ebx; eax = y * sqrt(x / 2 * x / 2 - (i * i)) / x

		mov temp, eax
	}*/
}
std::vector<point> drawEllipse(int width, int height, int mouseX, int mouseY) 
{
	std::vector<point> points;
	std::vector<point>* points_ptr = &points;
	struct point p;
	int mw = mouseX + width / 2;
	int mh = mouseY + height / 2;
	int i = 0;
	_asm
	{
	l1:
		;formule(int x, int y, int i) i y x
		mov eax, i; i
		push eax
		mov ebx, height; y
		push ebx
		mov edx, width; x
		push edx
		call formule
		pop eax
		pop ebx
		pop edx

		mov ecx, mw; ecx = mouseX + width / 2
		sub ecx, i; ecx = mouseX + width / 2 - i

		mov eax, mh; mouseY + height / 2
		sub eax, temp; mouseY + height / 2 - height * sqrt(width / 2 * width / 2 - (i * i)) / width

		push eax; set_points(x, y) y x
		push ecx
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		mov ecx, mw; ecx = mouseX + width / 2
		add ecx, i; ecx = mouseX + width / 2 + i

		mov eax, mh; mouseY + height / 2
		sub eax, temp; mouseY + height / 2 - height * sqrt(width / 2 * width / 2 - (i * i)) / width

		push eax; set_points(x, y) y x
		push ecx
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		mov ecx, mw; ecx = mouseX + width / 2
		sub ecx, i; ecx = mouseX + width / 2 - i

		mov eax, mh; mouseY + height / 2
		add eax, temp; mouseY + height / 2 + height * sqrt(width / 2 * width / 2 - (i * i)) / width

		push eax; set_points(x, y) y x
		push ecx
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		mov ecx, mw; ecx = mouseX + width / 2
		add ecx, i; ecx = mouseX + width / 2 + i

		mov eax, mh; mouseY + height / 2
		add eax, temp; mouseY + height / 2 + height * sqrt(width / 2 * width / 2 - (i * i)) / width

		push eax; set_points(x, y) y x
		push ecx
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		inc i
		mov eax, width
		mov edx, 0
		mov ebx, 2
		div ebx
		cmp i, eax; i < width / 2 ? goto l1;
			jl l1

		mov eax,0
		mov i, 0

	l2:
		; formule(int x, int y, int i) i y x
		mov eax, i; i
		push eax
		mov ebx, width; y
		push ebx
		mov edx, height; x
		push edx
		call formule
		pop eax
		pop ebx
		pop edx

		mov ecx, mw; ecx = mouseX + width / 2
		sub ecx, temp; ecx = mouseX + width / 2 - width * sqrt(height / 2 * height / 2 - (i * i)) / height

		mov eax, mh; mouseY + height / 2
		sub eax, i; mouseY + height / 2 - i

		push eax; set_points(x, y) y x
		push ecx
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		mov ecx, mw; ecx = mouseX + width / 2
		sub ecx, temp; ecx = mouseX + width / 2 + width * sqrt(height / 2 * height / 2 - (i * i)) / height

		mov eax, mh; mouseY + height / 2
		add eax, i; mouseY + height / 2 + i

		push eax; set_points(x, y) y x
		push ecx
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		mov ecx, mw; ecx = mouseX + width / 2
		add ecx, temp; ecx = mouseX + width / 2 + width * sqrt(height / 2 * height / 2 - (i * i)) / height

		mov eax, mh; mouseY + height / 2
		sub eax, i; mouseY + height / 2 - i

		push eax; set_points(x, y) y x
		push ecx
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		mov ecx, mw; ecx = mouseX + width / 2
		add ecx, temp; ecx = mouseX + width / 2 + width * sqrt(height / 2 * height / 2 - (i * i)) / height

		mov eax, mh; mouseY + height / 2
		add eax, i; mouseY + height / 2 + i

		push eax; set_points(x, y) y x
		push ecx
		mov edx, points_ptr
		push edx
		call set_points
		pop edx
		pop edx
		pop edx

		inc i
		mov eax, height
		mov edx, 0
		mov ebx, 2
		div ebx
		cmp i, eax; i < width / 2 ? goto l1;
			jl l2
	}
	/*int i = 0;
	do
	{ 
		formule(width, height, i);

		p.x = mouseX + width/2 - i;
		p.y = mouseY + height/2 - temp;
		points.emplace_back(p);

		p.x = mouseX + width / 2 + i;
		p.y = mouseY + height / 2 - temp;
		points.emplace_back(p);

		p.x = mouseX + width / 2 - i;
		p.y = mouseY + height / 2 + temp;
		points.emplace_back(p);

		p.x = mouseX + width / 2 + i;
		p.y = mouseY + height / 2 + temp;
		points.emplace_back(p);
		i++;
	}
	while (i < width/2);
	int j = 0;
	do
	{
		formule(height, width, j);

		p.x = mouseX + width / 2 - temp;
		p.y = mouseY + height / 2 - j;
		points.emplace_back(p);

		p.x = mouseX + width / 2 - temp;
		p.y = mouseY + height / 2 + j;
		points.emplace_back(p);

		p.x = mouseX + width / 2 + temp;
		p.y = mouseY + height / 2 - j;
		points.emplace_back(p);

		p.x = mouseX + width / 2 + temp;
		p.y = mouseY + height / 2 + j;
		points.emplace_back(p);
		j++;
	} 	while (j < height / 2);*/
	return points;
}
std::vector<point> fillEllipse(int width, int height, int mouseX, int mouseY)
{
	std::vector<point> points;
	std::vector<point>* points_ptr = &points;
	struct point p;
	int i = 0;
	int j = 0;
	int mw = mouseX + width / 2;
	int mh = mouseY + height / 2;
	_asm
	{
	l1:
		mov eax, width
		mov edx, 0
		mov ebx, 2
		div ebx;eax = width / 2
		add eax, mouseX;
		sub eax, i; eax = mouseX + width / 2 - i
		mov j, eax

		; formule(int x, int y, int i) i y x
		mov eax, i; i
		push eax
		mov ebx, height; y
		push ebx
		mov edx, width; x
		push edx
		call formule
		pop eax
		pop ebx
		pop edx

		mov eax, mh
		sub eax, temp; mouseY + height / 2 - height * sqrt(width / 2 * width / 2 - (i * i)) / width
		mov j, eax

	l2:
			mov eax, mw
			sub eax, i

			mov ecx, j

			push ecx; set_points(x, y) y x
			push eax
			mov edx, points_ptr
			push edx
			call set_points
			pop edx
			pop edx
			pop edx

			mov eax, mw
			add eax, i

			mov ecx, j

			push ecx; set_points(x, y) y x
			push eax
			mov edx, points_ptr
			push edx
			call set_points
			pop edx
			pop edx
			pop edx

			inc j
			mov eax, height
			mov edx, 0
			mov ebx, 2
			div ebx
			add eax, mouseY;
			add eax, temp; 
			cmp j, eax; j < mouseY + height / 2 + height * sqrt(width / 2 * width / 2 - (i * i)) / width ? goto l3;
				jl l2

		inc i
		mov eax, width
		mov edx, 0
		mov ebx, 2
		div ebx
		cmp i, eax; i < width / 2 ? goto l1;
			jl l1
	}
	/*do
	{
		formule(width, height, i);

		j = mouseY + height / 2 - temp;
		do
		{
			p.x = mouseX + width / 2 - i;
			p.y = j;
			points.emplace_back(p);

			p.x = mouseX + width / 2 + i;
			p.y = j;
			points.emplace_back(p);

			j++;
		} while (j < mouseY + height / 2 + temp);

		i++;
	} 	while (i < width / 2);*/
	return points;
}
#pragma managed
System::Void PaintV1::PaintV1::pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	int width = Convert::ToInt32(numericUpDownShapeWidth->Value);
	int height = Convert::ToInt32(numericUpDownShapeHeight->Value);

	int mouseX = mousePosition.X;
	int mouseY = mousePosition.Y;

	switch (statePen)
	{
	case 1:
		if (points->Count > 1) {
			
			canvas->DrawLines(pen, points->ToArray());
		}
		break;

	case 2:
		if (mousePosition.X != -1 && mousePosition.Y != -1)
		{
			if (checkBoxFill->Checked)
			{
				std::vector<point> points = fillRectangle(width, height, mouseX, mouseY);
				for each (struct point p in points)
				{
					bitmap->SetPixel( p.x, p.y, pen->Color);
				}
			}
			std::vector<point> points = drawRectangle(width, height, mouseX, mouseY);
			for each (struct point p in points)
			{
				bitmap->SetPixel(p.x, p.y, pen->Color);
			}
		}
		break;

	case 3:
		if (mousePosition.X != -1 && mousePosition.Y != -1)
		{
			if (checkBoxFill->Checked)
			{
				std::vector<point> points = fillTriangle(width, height, mouseX, mouseY);
				for each (struct point p in points)
				{
					bitmap->SetPixel(p.x, p.y, pen->Color);
				}
			}
			std::vector<point> points = drawTriangle(width, height, mouseX, mouseY);
			for each (struct point p in points)
			{
				bitmap->SetPixel(p.x, p.y, pen->Color);
			}
			/*if (checkBoxFill->Checked)
				canvas->FillPolygon(brush, curvePoints);
			canvas->DrawPolygon(pen, curvePoints);*/
		}
		break;
	case 4:
		if (mousePosition.X != -1 && mousePosition.Y != -1)
		{
			if (checkBoxFill->Checked)
			{
				std::vector<point> points = fillEllipse(width, height, mouseX, mouseY);
				for each (struct point p in points)
				{
					bitmap->SetPixel(p.x, p.y, pen->Color);
				}
			}
			std::vector<point> points = drawEllipse(width, height, mouseX, mouseY);
			for each (struct point p in points)
			{
				bitmap->SetPixel(p.x, p.y, pen->Color);
			}
		}
		break;
	default:
		break;
	}
	pictureBox1->Image = bitmap;
	if (clearAll) {
		points->Clear();
		canvas->Clear(Color::White);
		clearAll = false;

		mousePosition.X = -1;
		mousePosition.Y = -1;

		DrawBitmap();
	}
}

System::Void PaintV1::PaintV1::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
System::Void PaintV1::PaintV1::saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ fname;
	saveFileDialog1->ShowDialog();
	fname = saveFileDialog1->FileName;

	if (fname == "")
		return;

	Bitmap^ img = gcnew Bitmap(pictureBox1->Image);
	img->Save(fname);

	MessageBox::Show("1 \"" + fname + "\".", "2!");

	return System::Void();
}
System::Void PaintV1::PaintV1::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{

	openFileDialog1->ShowDialog();
	filename = openFileDialog1->FileName;

	if (filename == "openFileDialog1")
		return;

	bitmap = gcnew Bitmap(filename);
	bitmap = gcnew Bitmap(bitmap, Convert::ToInt32(pictureBox1->Width), Convert::ToInt32(pictureBox1->Height));
	this->Width = bitmap->Width;
	this->Height = bitmap->Height;

	canvas = Graphics::FromImage(bitmap);
	pictureBox1->Image = bitmap;

	return System::Void();
}
System::Void PaintV1::PaintV1::toolsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (groupBoxTools->Visible) {
		groupBoxTools->Visible = false;
	}
	else {
		groupBoxTools->Visible = true;
		groupBoxTools->Location = Point(12, 37);
	}

	return System::Void();
}

System::Void PaintV1::PaintV1::buttonPenColor_Click(System::Object^ sender, System::EventArgs^ e)
{
	colorDialog1->ShowDialog();
	Color color = colorDialog1->Color;

	buttonPenColor->BackColor = color;

	if (color == Color::Black) {
		buttonPenColor->ForeColor = Color::White;
	}
	else {
		buttonPenColor->ForeColor = Color::Black;
	}

	pen = gcnew Pen(color, size);

	return System::Void();
}
System::Void PaintV1::PaintV1::buttonBrushColor_Click(System::Object^ sender, System::EventArgs^ e)
{
	colorDialog1->ShowDialog();
	brush->Color = colorDialog1->Color;

	buttonBrushColor->BackColor = brush->Color;

	if (pen->Color == Color::Black) {
		buttonBrushColor->ForeColor = Color::White;
	}
	else {
		buttonBrushColor->ForeColor = Color::Black;
	}
	return System::Void();
}
System::Void PaintV1::PaintV1::buttonClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	clearAll = true;
	pictureBox1->Invalidate();

	return System::Void();
}

System::Void PaintV1::PaintV1::buttonLine_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SwitchShape(1);
}
System::Void PaintV1::PaintV1::buttonRectangle_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SwitchShape(2);
}
System::Void PaintV1::PaintV1::buttonTriangle_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SwitchShape(3);
}
System::Void PaintV1::PaintV1::buttonCircle_Click(System::Object^ sender, System::EventArgs^ e) 
{
	SwitchShape(4);
}
void PaintV1::PaintV1::SwitchShape(int idShape)
{
	statePen = idShape;

	buttonLine->BackColor = Color::LightGray;
	buttonCircle->BackColor = Color::LightGray;
	buttonRectangle->BackColor = Color::LightGray;
	buttonTriangle->BackColor = Color::LightGray;

	switch (statePen)
	{

	case 1:
		buttonLine->BackColor = Color::Green;
		break;
	case 2:
		buttonRectangle->BackColor = Color::Blue;
		break;
	case 3:
		buttonTriangle->BackColor = Color::Aqua;
		break;
	case 4:
		buttonCircle->BackColor = Color::Red;
		break;
	default:
		break;
	}

	return System::Void();
}

void PaintV1::PaintV1::DrawBitmap()
{
	if (filename != "openFileDialog1") {
		bitmap = gcnew Bitmap(filename);
		bitmap = gcnew Bitmap(bitmap, pictureBox1->Width, pictureBox1->Height);
	}
	else
		bitmap = gcnew Bitmap(pictureBox1->Image, pictureBox1->Width, pictureBox1->Height);

	delete canvas;
	canvas = Graphics::FromImage(bitmap);
	pictureBox1->Image = bitmap;
	pictureBox1->Refresh();
	pictureBox1->Invalidate();
}
void PaintV1::PaintV1::AddCtrlZ()
{
	bitmaps;
}