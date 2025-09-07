#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <stdlib.h>

#pragma comment(lib, "user32.lib") // либы 
#pragma comment(lib, "gdi32.lib")  // необходимые дл€ компил€ции

namespace Project1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    int WIDTH = 200;
    int HEIGHT = 200;

    int xposition = 960;
    int yposition = 100;

    int Zoom = 3;
    int FPS = 15;

    void GetParamets(HDC hWndDC) {
        HWND hDesktop = GetDesktopWindow();
        HDC hDesktopDC = GetDC(hDesktop);

        int screenW = GetSystemMetrics(SM_CXSCREEN);
        int screenH = GetSystemMetrics(SM_CYSCREEN);

        int srcW = WIDTH / Zoom;
        int srcH = HEIGHT / Zoom;

        int x = (screenW - srcW) / 2;
        int y = (screenH - srcH) / 2;

        SetStretchBltMode(hWndDC, HALFTONE); // сглаживание но всЄ равно пиксели.
        StretchBlt(hWndDC, 0, 0, WIDTH, HEIGHT, hDesktopDC, x, y, srcW, srcH, SRCCOPY);

        ReleaseDC(hDesktop, hDesktopDC);
    }

    LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        switch (msg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            GetParamets(hdc);
            EndPaint(hwnd, &ps);
            break;
        }
        case WM_TIMER:
            InvalidateRect(hwnd, NULL, FALSE);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        }
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    void launch() {
        WNDCLASS wc = {};
        wc.lpfnWndProc = WndProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = L"MyCenterCaptureClass";
        RegisterClass(&wc);

        static HWND hwnd = NULL;
        if (hwnd != NULL) {
            DestroyWindow(hwnd);
        }

        hwnd = CreateWindowEx(
            WS_EX_TOPMOST | WS_EX_TOOLWINDOW,
            L"MyCenterCaptureClass",
            L"Center Capture",
            WS_POPUP,
            xposition, yposition, WIDTH, HEIGHT,
            NULL, NULL, wc.hInstance, NULL
        );
        ShowWindow(hwnd, SW_SHOW);

        SetTimer(hwnd, 1, 1000 / FPS, NULL);

        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TrackBar^ trackBar1;

    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Button^ button1;








    private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
    private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
    private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
    private: System::Windows::Forms::NumericUpDown^ numericUpDown4;
    private: System::Windows::Forms::NumericUpDown^ numericUpDown5;



    private: System::Windows::Forms::GroupBox^ groupBox2;
    private: System::Windows::Forms::GroupBox^ groupBox3;
    private: System::Windows::Forms::GroupBox^ groupBox4;

    private: System::Windows::Forms::GroupBox^ groupBox6;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::GroupBox^ groupBox1;
    private: System::Windows::Forms::GroupBox^ groupBox5;
    private: System::Windows::Forms::LinkLabel^ linkLabel1;




    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
            this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
            this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
            this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
            this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
            this->groupBox2->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->groupBox4->SuspendLayout();
            this->groupBox6->SuspendLayout();
            this->groupBox1->SuspendLayout();
            this->groupBox5->SuspendLayout();
            this->SuspendLayout();
            // 
            // trackBar1
            // 
            this->trackBar1->Location = System::Drawing::Point(6, 16);
            this->trackBar1->Maximum = 8;
            this->trackBar1->Minimum = 1;
            this->trackBar1->Name = L"trackBar1";
            this->trackBar1->Size = System::Drawing::Size(268, 45);
            this->trackBar1->TabIndex = 0;
            this->trackBar1->Value = 3;
            this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(6, 17);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(35, 13);
            this->label2->TabIndex = 6;
            this->label2->Text = L"Width";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(6, 59);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(38, 13);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Height";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(8, 16);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(14, 13);
            this->label4->TabIndex = 8;
            this->label4->Text = L"X";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(8, 60);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(14, 13);
            this->label5->TabIndex = 9;
            this->label5->Text = L"Y";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(6, 34);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(124, 47);
            this->button1->TabIndex = 10;
            this->button1->Text = L"Apply";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // numericUpDown1
            // 
            this->numericUpDown1->Location = System::Drawing::Point(8, 34);
            this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
            this->numericUpDown1->Name = L"numericUpDown1";
            this->numericUpDown1->Size = System::Drawing::Size(120, 20);
            this->numericUpDown1->TabIndex = 20;
            this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
            this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
            // 
            // numericUpDown2
            // 
            this->numericUpDown2->Location = System::Drawing::Point(9, 77);
            this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
            this->numericUpDown2->Name = L"numericUpDown2";
            this->numericUpDown2->Size = System::Drawing::Size(120, 20);
            this->numericUpDown2->TabIndex = 21;
            this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
            this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
            // 
            // numericUpDown3
            // 
            this->numericUpDown3->Location = System::Drawing::Point(9, 33);
            this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
            this->numericUpDown3->Name = L"numericUpDown3";
            this->numericUpDown3->Size = System::Drawing::Size(120, 20);
            this->numericUpDown3->TabIndex = 22;
            this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 960, 0, 0, 0 });
            this->numericUpDown3->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown3_ValueChanged);
            // 
            // numericUpDown4
            // 
            this->numericUpDown4->Location = System::Drawing::Point(9, 77);
            this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
            this->numericUpDown4->Name = L"numericUpDown4";
            this->numericUpDown4->Size = System::Drawing::Size(120, 20);
            this->numericUpDown4->TabIndex = 23;
            this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
            this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown4_ValueChanged);
            // 
            // numericUpDown5
            // 
            this->numericUpDown5->Location = System::Drawing::Point(6, 20);
            this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
            this->numericUpDown5->Name = L"numericUpDown5";
            this->numericUpDown5->Size = System::Drawing::Size(120, 20);
            this->numericUpDown5->TabIndex = 24;
            this->numericUpDown5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
            this->numericUpDown5->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown5_ValueChanged);
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->label3);
            this->groupBox2->Controls->Add(this->label2);
            this->groupBox2->Controls->Add(this->numericUpDown2);
            this->groupBox2->Controls->Add(this->numericUpDown1);
            this->groupBox2->Location = System::Drawing::Point(7, 76);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(136, 105);
            this->groupBox2->TabIndex = 27;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Window Size";
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->label5);
            this->groupBox3->Controls->Add(this->label4);
            this->groupBox3->Controls->Add(this->numericUpDown4);
            this->groupBox3->Controls->Add(this->numericUpDown3);
            this->groupBox3->Location = System::Drawing::Point(149, 75);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(136, 105);
            this->groupBox3->TabIndex = 28;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"Position";
            // 
            // groupBox4
            // 
            this->groupBox4->Controls->Add(this->numericUpDown5);
            this->groupBox4->Location = System::Drawing::Point(7, 181);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(136, 52);
            this->groupBox4->TabIndex = 29;
            this->groupBox4->TabStop = false;
            this->groupBox4->Text = L"Fps";
            // 
            // groupBox6
            // 
            this->groupBox6->Controls->Add(this->label12);
            this->groupBox6->Controls->Add(this->label11);
            this->groupBox6->Controls->Add(this->label10);
            this->groupBox6->Controls->Add(this->label9);
            this->groupBox6->Controls->Add(this->label8);
            this->groupBox6->Controls->Add(this->label7);
            this->groupBox6->Controls->Add(this->label1);
            this->groupBox6->Controls->Add(this->trackBar1);
            this->groupBox6->Location = System::Drawing::Point(7, 1);
            this->groupBox6->Name = L"groupBox6";
            this->groupBox6->Size = System::Drawing::Size(278, 74);
            this->groupBox6->TabIndex = 31;
            this->groupBox6->TabStop = false;
            this->groupBox6->Text = L"Zoom";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Location = System::Drawing::Point(253, 52);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(18, 13);
            this->label12->TabIndex = 34;
            this->label12->Text = L"8x";
            this->label12->Click += gcnew System::EventHandler(this, &MyForm::label12_Click);
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(219, 52);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(18, 13);
            this->label11->TabIndex = 34;
            this->label11->Text = L"7x";
            this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(184, 52);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(18, 13);
            this->label10->TabIndex = 34;
            this->label10->Text = L"6x";
            this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(150, 52);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(18, 13);
            this->label9->TabIndex = 34;
            this->label9->Text = L"5x";
            this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(115, 52);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(18, 13);
            this->label8->TabIndex = 34;
            this->label8->Text = L"4x";
            this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(81, 52);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(18, 13);
            this->label7->TabIndex = 34;
            this->label7->Text = L"3x";
            this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(11, 51);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(18, 13);
            this->label1->TabIndex = 32;
            this->label1->Text = L"1x";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(53, 53);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(18, 13);
            this->label6->TabIndex = 33;
            this->label6->Text = L"2x";
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->button1);
            this->groupBox1->Location = System::Drawing::Point(149, 181);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(136, 93);
            this->groupBox1->TabIndex = 34;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Click the button to open the window";
            // 
            // groupBox5
            // 
            this->groupBox5->Controls->Add(this->linkLabel1);
            this->groupBox5->Location = System::Drawing::Point(7, 235);
            this->groupBox5->Name = L"groupBox5";
            this->groupBox5->Size = System::Drawing::Size(136, 39);
            this->groupBox5->TabIndex = 35;
            this->groupBox5->TabStop = false;
            this->groupBox5->Text = L"Info";
            // 
            // linkLabel1
            // 
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Location = System::Drawing::Point(8, 18);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(68, 13);
            this->linkLabel1->TabIndex = 0;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Source code";
            this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabel1_LinkClicked_1);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(294, 284);
            this->Controls->Add(this->groupBox5);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->groupBox6);
            this->Controls->Add(this->groupBox4);
            this->Controls->Add(this->groupBox3);
            this->Controls->Add(this->groupBox2);
            this->Name = L"MyForm";
            this->Text = L"Focus-View";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            this->groupBox3->ResumeLayout(false);
            this->groupBox3->PerformLayout();
            this->groupBox4->ResumeLayout(false);
            this->groupBox6->ResumeLayout(false);
            this->groupBox6->PerformLayout();
            this->groupBox1->ResumeLayout(false);
            this->groupBox5->ResumeLayout(false);
            this->groupBox5->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
        Zoom = Convert::ToInt32(trackBar1->Value);
    }
    private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
        WIDTH = Convert::ToInt32(numericUpDown1->Value);
    }
    private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
        HEIGHT = Convert::ToInt32(numericUpDown2->Value);
    }
    private: System::Void numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
        xposition = Convert::ToInt32(numericUpDown3->Value);
    }
    private: System::Void numericUpDown4_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
        yposition = Convert::ToInt32(numericUpDown4->Value);
    }
    private: System::Void numericUpDown5_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
        FPS = Convert::ToInt32(numericUpDown5->Value);
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        launch();    
    }
public: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
}
private: System::Void linkLabel1_LinkClicked_1(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    System::Diagnostics::Process::Start("https://github.com/Fae1337/Focus-View-v2");
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}