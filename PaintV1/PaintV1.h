#pragma once

namespace PaintV1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// —водка дл€ PaintV1
	/// </summary>
	public ref class PaintV1 : public System::Windows::Forms::Form
	{
	public:
		PaintV1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~PaintV1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ actionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ groupBoxTools;
	private: System::Windows::Forms::GroupBox^ groupBoxBrush;
	private: System::Windows::Forms::CheckBox^ checkBoxFill;

	private: System::Windows::Forms::Button^ buttonBrushColor;

	private: System::Windows::Forms::GroupBox^ groupBoxShape;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownShapeHeight;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownShapeWidth;
	private: System::Windows::Forms::Button^ buttonCircle;
	private: System::Windows::Forms::Button^ buttonTriangle;
	private: System::Windows::Forms::Button^ buttonRectangle;
	private: System::Windows::Forms::Button^ buttonLine;

	private: System::Windows::Forms::GroupBox^ groupBoxPen;
	private: System::Windows::Forms::Button^ buttonClear;

	private: System::Windows::Forms::Button^ buttonPenColor;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->actionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxTools = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxBrush = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxFill = (gcnew System::Windows::Forms::CheckBox());
			this->buttonBrushColor = (gcnew System::Windows::Forms::Button());
			this->groupBoxShape = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDownShapeHeight = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownShapeWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonCircle = (gcnew System::Windows::Forms::Button());
			this->buttonTriangle = (gcnew System::Windows::Forms::Button());
			this->buttonRectangle = (gcnew System::Windows::Forms::Button());
			this->buttonLine = (gcnew System::Windows::Forms::Button());
			this->groupBoxPen = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonPenColor = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBoxTools->SuspendLayout();
			this->groupBoxBrush->SuspendLayout();
			this->groupBoxShape->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownShapeHeight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownShapeWidth))->BeginInit();
			this->groupBoxPen->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->actionToolStripMenuItem,
					this->toolsToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1002, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// actionToolStripMenuItem
			// 
			this->actionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->actionToolStripMenuItem->Name = L"actionToolStripMenuItem";
			this->actionToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->actionToolStripMenuItem->Text = L"Action";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(104, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &PaintV1::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(104, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &PaintV1::saveToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			this->toolsToolStripMenuItem->Click += gcnew System::EventHandler(this, &PaintV1::toolsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &PaintV1::exitToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1002, 611);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->SizeChanged += gcnew System::EventHandler(this, &PaintV1::pictureBox1_SizeChanged);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PaintV1::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PaintV1::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PaintV1::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PaintV1::pictureBox1_MouseUp);
			// 
			// groupBoxTools
			// 
			this->groupBoxTools->Controls->Add(this->groupBoxBrush);
			this->groupBoxTools->Controls->Add(this->groupBoxShape);
			this->groupBoxTools->Controls->Add(this->groupBoxPen);
			this->groupBoxTools->Location = System::Drawing::Point(12, 27);
			this->groupBoxTools->Name = L"groupBoxTools";
			this->groupBoxTools->Size = System::Drawing::Size(358, 138);
			this->groupBoxTools->TabIndex = 2;
			this->groupBoxTools->TabStop = false;
			this->groupBoxTools->Text = L"Tools";
			this->groupBoxTools->Visible = false;
			// 
			// groupBoxBrush
			// 
			this->groupBoxBrush->Controls->Add(this->checkBoxFill);
			this->groupBoxBrush->Controls->Add(this->buttonBrushColor);
			this->groupBoxBrush->Location = System::Drawing::Point(6, 75);
			this->groupBoxBrush->Name = L"groupBoxBrush";
			this->groupBoxBrush->Size = System::Drawing::Size(173, 58);
			this->groupBoxBrush->TabIndex = 2;
			this->groupBoxBrush->TabStop = false;
			this->groupBoxBrush->Text = L"Brush";
			// 
			// checkBoxFill
			// 
			this->checkBoxFill->AutoSize = true;
			this->checkBoxFill->Location = System::Drawing::Point(87, 25);
			this->checkBoxFill->Name = L"checkBoxFill";
			this->checkBoxFill->Size = System::Drawing::Size(56, 17);
			this->checkBoxFill->TabIndex = 7;
			this->checkBoxFill->Text = L"active";
			this->checkBoxFill->UseVisualStyleBackColor = true;
			// 
			// buttonBrushColor
			// 
			this->buttonBrushColor->Location = System::Drawing::Point(6, 21);
			this->buttonBrushColor->Name = L"buttonBrushColor";
			this->buttonBrushColor->Size = System::Drawing::Size(75, 23);
			this->buttonBrushColor->TabIndex = 6;
			this->buttonBrushColor->Text = L"Color";
			this->buttonBrushColor->UseVisualStyleBackColor = true;
			this->buttonBrushColor->Click += gcnew System::EventHandler(this, &PaintV1::buttonBrushColor_Click);
			// 
			// groupBoxShape
			// 
			this->groupBoxShape->Controls->Add(this->numericUpDownShapeHeight);
			this->groupBoxShape->Controls->Add(this->numericUpDownShapeWidth);
			this->groupBoxShape->Controls->Add(this->buttonCircle);
			this->groupBoxShape->Controls->Add(this->buttonTriangle);
			this->groupBoxShape->Controls->Add(this->buttonRectangle);
			this->groupBoxShape->Controls->Add(this->buttonLine);
			this->groupBoxShape->Location = System::Drawing::Point(185, 11);
			this->groupBoxShape->Name = L"groupBoxShape";
			this->groupBoxShape->Size = System::Drawing::Size(169, 121);
			this->groupBoxShape->TabIndex = 1;
			this->groupBoxShape->TabStop = false;
			this->groupBoxShape->Text = L"Shape";
			// 
			// numericUpDownShapeHeight
			// 
			this->numericUpDownShapeHeight->Location = System::Drawing::Point(87, 79);
			this->numericUpDownShapeHeight->Name = L"numericUpDownShapeHeight";
			this->numericUpDownShapeHeight->Size = System::Drawing::Size(75, 22);
			this->numericUpDownShapeHeight->TabIndex = 7;
			// 
			// numericUpDownShapeWidth
			// 
			this->numericUpDownShapeWidth->Location = System::Drawing::Point(6, 79);
			this->numericUpDownShapeWidth->Name = L"numericUpDownShapeWidth";
			this->numericUpDownShapeWidth->Size = System::Drawing::Size(75, 22);
			this->numericUpDownShapeWidth->TabIndex = 6;
			// 
			// buttonCircle
			// 
			this->buttonCircle->Location = System::Drawing::Point(87, 50);
			this->buttonCircle->Name = L"buttonCircle";
			this->buttonCircle->Size = System::Drawing::Size(75, 23);
			this->buttonCircle->TabIndex = 3;
			this->buttonCircle->Text = L"Circle";
			this->buttonCircle->UseVisualStyleBackColor = true;
			this->buttonCircle->Click += gcnew System::EventHandler(this, &PaintV1::buttonCircle_Click);
			// 
			// buttonTriangle
			// 
			this->buttonTriangle->Location = System::Drawing::Point(6, 50);
			this->buttonTriangle->Name = L"buttonTriangle";
			this->buttonTriangle->Size = System::Drawing::Size(75, 23);
			this->buttonTriangle->TabIndex = 2;
			this->buttonTriangle->Text = L"Triangle";
			this->buttonTriangle->UseVisualStyleBackColor = true;
			this->buttonTriangle->Click += gcnew System::EventHandler(this, &PaintV1::buttonTriangle_Click);
			// 
			// buttonRectangle
			// 
			this->buttonRectangle->Location = System::Drawing::Point(87, 21);
			this->buttonRectangle->Name = L"buttonRectangle";
			this->buttonRectangle->Size = System::Drawing::Size(75, 23);
			this->buttonRectangle->TabIndex = 1;
			this->buttonRectangle->Text = L"Rectangle";
			this->buttonRectangle->UseVisualStyleBackColor = true;
			this->buttonRectangle->Click += gcnew System::EventHandler(this, &PaintV1::buttonRectangle_Click);
			// 
			// buttonLine
			// 
			this->buttonLine->Location = System::Drawing::Point(6, 21);
			this->buttonLine->Name = L"buttonLine";
			this->buttonLine->Size = System::Drawing::Size(75, 23);
			this->buttonLine->TabIndex = 0;
			this->buttonLine->Text = L"Line";
			this->buttonLine->UseVisualStyleBackColor = true;
			this->buttonLine->Click += gcnew System::EventHandler(this, &PaintV1::buttonLine_Click);
			// 
			// groupBoxPen
			// 
			this->groupBoxPen->Controls->Add(this->buttonClear);
			this->groupBoxPen->Controls->Add(this->buttonPenColor);
			this->groupBoxPen->Location = System::Drawing::Point(6, 11);
			this->groupBoxPen->Name = L"groupBoxPen";
			this->groupBoxPen->Size = System::Drawing::Size(173, 58);
			this->groupBoxPen->TabIndex = 0;
			this->groupBoxPen->TabStop = false;
			this->groupBoxPen->Text = L"Pen";
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(87, 21);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(75, 23);
			this->buttonClear->TabIndex = 1;
			this->buttonClear->Text = L"clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &PaintV1::buttonClear_Click);
			// 
			// buttonPenColor
			// 
			this->buttonPenColor->Location = System::Drawing::Point(6, 21);
			this->buttonPenColor->Name = L"buttonPenColor";
			this->buttonPenColor->Size = System::Drawing::Size(75, 23);
			this->buttonPenColor->TabIndex = 0;
			this->buttonPenColor->Text = L"Color";
			this->buttonPenColor->UseVisualStyleBackColor = true;
			this->buttonPenColor->Click += gcnew System::EventHandler(this, &PaintV1::buttonPenColor_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// PaintV1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1002, 635);
			this->Controls->Add(this->groupBoxTools);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PaintV1";
			this->Text = L"PaintV1";
			this->Load += gcnew System::EventHandler(this, &PaintV1::PaintV1_Load);
			this->SizeChanged += gcnew System::EventHandler(this, &PaintV1::PaintV1_SizeChanged);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBoxTools->ResumeLayout(false);
			this->groupBoxBrush->ResumeLayout(false);
			this->groupBoxBrush->PerformLayout();
			this->groupBoxShape->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownShapeHeight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownShapeWidth))->EndInit();
			this->groupBoxPen->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Graphics^ canvas;
		List <Point>^ points;
		array<Bitmap^>^ bitmaps;
		Pen^ pen;
		SolidBrush^ brush;
		bool draw;
		Bitmap^ bitmap;
		float size;
		bool clearAll;
		String^ filename;
		int statePen;
	
	private: System::Void PaintV1_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBox1_SizeChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PaintV1_SizeChanged(System::Object^ sender, System::EventArgs^ e) {}

	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttonPenColor_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonBrushColor_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttonLine_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonRectangle_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonTriangle_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCircle_Click(System::Object^ sender, System::EventArgs^ e);
	private: void SwitchShape(int idShape);

	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

	private: void DrawBitmap();
	private: void AddCtrlZ();
};
}
