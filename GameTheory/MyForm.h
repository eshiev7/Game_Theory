#pragma once
#include "Python.h"
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

typedef System::Windows::Forms::TextBox^ textBox;

void calc_2x2(textBox pl1s1s1, textBox pl1s1s2, textBox pl2s1s1, textBox pl2s1s2,
	textBox pl1s2s1, textBox pl1s2s2, textBox pl2s2s1, textBox pl2s2s2,
	textBox result_1player, textBox result_2player)
{
	PyObject* pName, * pModule, * pFunc, * pArgs, * pValue;
	pName = PyUnicode_FromString((char*)"calculation");
	pModule = PyImport_Import(pName);
	pFunc = PyObject_GetAttrString(pModule, (char*)"calc");
	pArgs = PyTuple_Pack(8,
		PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s1s1->Text)),
		PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s1s2->Text)),
		PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s2s1->Text)),
		PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s2s2->Text)),
		PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s1s1->Text)),
		PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s1s2->Text)),
		PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s2s1->Text)),
		PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s2s2->Text))
	);
	pValue = PyObject_CallObject(pFunc, pArgs);
	std::string res = _PyUnicode_AsString(pValue);
	auto iter = res.find("],");
	auto iter2 = res.find("]]");
	res.replace(iter2, iter2 + 1, "]");

	std::string res_1_player = res.substr(1, iter);
	std::string res_2_player = res.substr(iter + 2);
	String^ res1_player = gcnew String(res_1_player.c_str());
	String^ res2_player = gcnew String(res_2_player.c_str());
	result_1player->Text = res1_player;
	result_2player->Text = res2_player;
}


void calc_2x3()
{

}

void calc_2x4()
{

}

void calc_3x2()
{

}

void calc_3x3()
{

}

void calc_3x4()
{

}

void calc_4x2()
{

}

void calc_4x3()
{

}

void calc_4x4()
{

}

namespace GameTheory {

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			Py_Initialize();
		}

	protected:
		~MyForm()
		{
			Py_Finalize();
			if (components)
			{
				delete components;
			}
		}
	public: 
		System::Windows::Forms::TextBox^ result_2player;
		System::Windows::Forms::TextBox^ result_1player;
	private:
		// labels
		System::Windows::Forms::Label^ result_player1;
		System::Windows::Forms::Label^ result_player2;
		System::Windows::Forms::Label^ semicolons1s1;
		System::Windows::Forms::Label^ semicolons1s2;
		System::Windows::Forms::Label^ semicolons2s1;
		System::Windows::Forms::Label^ semicolons2s2;
		System::Windows::Forms::Label^ semicolons3s1;
		System::Windows::Forms::Label^ semicolons3s2;
		System::Windows::Forms::Label^ semicolons4s1;
		System::Windows::Forms::Label^ semicolons4s2;
		System::Windows::Forms::Label^ semicolons1s3;
		System::Windows::Forms::Label^ semicolons1s4;
		System::Windows::Forms::Label^ semicolons2s3;
		System::Windows::Forms::Label^ semicolons2s4;
		System::Windows::Forms::Label^ semicolons3s3;
		System::Windows::Forms::Label^ semicolons3s4;
		System::Windows::Forms::Label^ semicolons4s3;
		System::Windows::Forms::Label^ semicolons4s4;
		System::Windows::Forms::Label^ player1_conf;
		System::Windows::Forms::Label^ player2_conf;
		System::Windows::Forms::Label^ description;
		System::Windows::Forms::Label^ stick1s1s1;
		System::Windows::Forms::Label^ stick2s1s1;
		System::Windows::Forms::Label^ stick1s1s2;
		System::Windows::Forms::Label^ stick2s1s2;
		System::Windows::Forms::Label^ stick2s2s1;
		System::Windows::Forms::Label^ stick1s2s1;
		System::Windows::Forms::Label^ stick2s2s2;
		System::Windows::Forms::Label^ stick2s3s1;
		System::Windows::Forms::Label^ stick1s2s2;
		System::Windows::Forms::Label^ stick1s3s1;
		System::Windows::Forms::Label^ stick2s3s2;
		System::Windows::Forms::Label^ stick1s3s2;
		System::Windows::Forms::Label^ stick2s4s1;
		System::Windows::Forms::Label^ stick1s4s1;
		System::Windows::Forms::Label^ stick2s4s2;
		System::Windows::Forms::Label^ stick1s4s2;
		System::Windows::Forms::Label^ stick2s1s3;
		System::Windows::Forms::Label^ stick1s1s3;
		System::Windows::Forms::Label^ stick2s1s4;
		System::Windows::Forms::Label^ stick1s1s4;
		System::Windows::Forms::Label^ stick2s2s3;
		System::Windows::Forms::Label^ stick1s2s3;
		System::Windows::Forms::Label^ stick2s2s4;
		System::Windows::Forms::Label^ stick1s2s4;
		System::Windows::Forms::Label^ stick2s3s3;
		System::Windows::Forms::Label^ stick1s3s3;
		System::Windows::Forms::Label^ stick2s3s4;
		System::Windows::Forms::Label^ stick1s3s4;
		System::Windows::Forms::Label^ stick2s4s3;
		System::Windows::Forms::Label^ stick1s4s3;
		System::Windows::Forms::Label^ stick2s4s4;
		System::Windows::Forms::Label^ stick1s4s4;
		System::Windows::Forms::Label^ player1s1;
		System::Windows::Forms::Label^ player1s2;
		System::Windows::Forms::Label^ player1s3;
		System::Windows::Forms::Label^ player1s4;
		System::Windows::Forms::Label^ player2s1;
		System::Windows::Forms::Label^ player2s2;
		System::Windows::Forms::Label^ player2s3;
		System::Windows::Forms::Label^ player2s4;
		System::Windows::Forms::Label^ player1;
		System::Windows::Forms::Label^ player2;
		System::Windows::Forms::Label^ result;
		System::Windows::Forms::Label^ info;
		
		// buttons
		System::Windows::Forms::Button^ reset_button;
		System::Windows::Forms::Button^ calc_button;
		System::Windows::Forms::Button^ configure;

		// text boxes
		System::Windows::Forms::TextBox^ pl1s1s1;
		System::Windows::Forms::TextBox^ pl2s1s1;
		System::Windows::Forms::TextBox^ pl1s1s2;
		System::Windows::Forms::TextBox^ pl2s1s2;
		System::Windows::Forms::TextBox^ pl2s2s1;
		System::Windows::Forms::TextBox^ pl1s2s1;
		System::Windows::Forms::TextBox^ pl2s2s2;
		System::Windows::Forms::TextBox^ pl1s2s2;
		System::Windows::Forms::TextBox^ pl2s3s1;
		System::Windows::Forms::TextBox^ pl1s3s1;
		System::Windows::Forms::TextBox^ pl2s3s2;
		System::Windows::Forms::TextBox^ pl1s3s2;
		System::Windows::Forms::TextBox^ pl2s4s1;
		System::Windows::Forms::TextBox^ pl1s4s1;
		System::Windows::Forms::TextBox^ pl2s4s2;
		System::Windows::Forms::TextBox^ pl1s4s2;
		System::Windows::Forms::TextBox^ pl2s1s3;
		System::Windows::Forms::TextBox^ pl1s1s3;
		System::Windows::Forms::TextBox^ pl2s1s4;
		System::Windows::Forms::TextBox^ pl1s1s4;
		System::Windows::Forms::TextBox^ pl2s2s3;
		System::Windows::Forms::TextBox^ pl1s2s3;
		System::Windows::Forms::TextBox^ pl2s2s4;
		System::Windows::Forms::TextBox^ pl1s2s4;
		System::Windows::Forms::TextBox^ pl2s3s3;
		System::Windows::Forms::TextBox^ pl1s3s3;
		System::Windows::Forms::TextBox^ pl2s3s4;
		System::Windows::Forms::TextBox^ pl1s3s4;
		System::Windows::Forms::TextBox^ pl2s4s3;
		System::Windows::Forms::TextBox^ pl1s4s3;
		System::Windows::Forms::TextBox^ pl2s4s4;
		System::Windows::Forms::TextBox^ pl1s4s4;

		// combo boxes
		System::Windows::Forms::ComboBox^ comboBox2;
		System::Windows::Forms::ComboBox^ comboBox1;

		// picture boxes
		System::Windows::Forms::PictureBox^ configFrame;
		System::Windows::Forms::PictureBox^ frames1s1;
		System::Windows::Forms::PictureBox^ frames1s2;
		System::Windows::Forms::PictureBox^ frames2s1;
		System::Windows::Forms::PictureBox^ frames2s2;
		System::Windows::Forms::PictureBox^ frames3s1;
		System::Windows::Forms::PictureBox^ frames3s2;
		System::Windows::Forms::PictureBox^ frames4s1;
		System::Windows::Forms::PictureBox^ frames4s2;
		System::Windows::Forms::PictureBox^ frames1s3;
		System::Windows::Forms::PictureBox^ frames1s4;
		System::Windows::Forms::PictureBox^ frames2s3;
		System::Windows::Forms::PictureBox^ frames2s4;
		System::Windows::Forms::PictureBox^ frames3s3;
		System::Windows::Forms::PictureBox^ frames3s4;
		System::Windows::Forms::PictureBox^ frames4s3;
		System::Windows::Forms::PictureBox^ frames4s4;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->result_player2 = (gcnew System::Windows::Forms::Label());
			this->result_player1 = (gcnew System::Windows::Forms::Label());
			this->semicolons1s1 = (gcnew System::Windows::Forms::Label());
			this->semicolons1s2 = (gcnew System::Windows::Forms::Label());
			this->semicolons2s1 = (gcnew System::Windows::Forms::Label());
			this->semicolons2s2 = (gcnew System::Windows::Forms::Label());
			this->semicolons3s1 = (gcnew System::Windows::Forms::Label());
			this->semicolons3s2 = (gcnew System::Windows::Forms::Label());
			this->semicolons4s1 = (gcnew System::Windows::Forms::Label());
			this->semicolons4s2 = (gcnew System::Windows::Forms::Label());
			this->semicolons1s3 = (gcnew System::Windows::Forms::Label());
			this->semicolons1s4 = (gcnew System::Windows::Forms::Label());
			this->semicolons2s3 = (gcnew System::Windows::Forms::Label());
			this->semicolons2s4 = (gcnew System::Windows::Forms::Label());
			this->semicolons3s3 = (gcnew System::Windows::Forms::Label());
			this->semicolons3s4 = (gcnew System::Windows::Forms::Label());
			this->semicolons4s3 = (gcnew System::Windows::Forms::Label());
			this->semicolons4s4 = (gcnew System::Windows::Forms::Label());
			this->player1_conf = (gcnew System::Windows::Forms::Label());
			this->player2_conf = (gcnew System::Windows::Forms::Label());
			this->description = (gcnew System::Windows::Forms::Label());
			this->stick1s1s1 = (gcnew System::Windows::Forms::Label());
			this->stick2s1s1 = (gcnew System::Windows::Forms::Label());
			this->stick1s1s2 = (gcnew System::Windows::Forms::Label());
			this->stick2s1s2 = (gcnew System::Windows::Forms::Label());
			this->stick2s2s1 = (gcnew System::Windows::Forms::Label());
			this->stick1s2s1 = (gcnew System::Windows::Forms::Label());
			this->stick2s2s2 = (gcnew System::Windows::Forms::Label());
			this->stick1s2s2 = (gcnew System::Windows::Forms::Label());
			this->stick2s3s1 = (gcnew System::Windows::Forms::Label());
			this->stick1s3s1 = (gcnew System::Windows::Forms::Label());
			this->stick2s3s2 = (gcnew System::Windows::Forms::Label());
			this->stick1s3s2 = (gcnew System::Windows::Forms::Label());
			this->stick2s4s1 = (gcnew System::Windows::Forms::Label());
			this->stick1s4s1 = (gcnew System::Windows::Forms::Label());
			this->stick2s4s2 = (gcnew System::Windows::Forms::Label());
			this->stick1s4s2 = (gcnew System::Windows::Forms::Label());
			this->stick2s1s3 = (gcnew System::Windows::Forms::Label());
			this->stick1s1s3 = (gcnew System::Windows::Forms::Label());
			this->stick2s1s4 = (gcnew System::Windows::Forms::Label());
			this->stick1s1s4 = (gcnew System::Windows::Forms::Label());
			this->stick2s2s3 = (gcnew System::Windows::Forms::Label());
			this->stick1s2s3 = (gcnew System::Windows::Forms::Label());
			this->stick2s2s4 = (gcnew System::Windows::Forms::Label());
			this->stick1s2s4 = (gcnew System::Windows::Forms::Label());
			this->stick2s3s3 = (gcnew System::Windows::Forms::Label());
			this->stick1s3s3 = (gcnew System::Windows::Forms::Label());
			this->stick2s3s4 = (gcnew System::Windows::Forms::Label());
			this->stick1s3s4 = (gcnew System::Windows::Forms::Label());
			this->stick2s4s3 = (gcnew System::Windows::Forms::Label());
			this->stick1s4s3 = (gcnew System::Windows::Forms::Label());
			this->stick2s4s4 = (gcnew System::Windows::Forms::Label());
			this->stick1s4s4 = (gcnew System::Windows::Forms::Label());
			this->player2s1 = (gcnew System::Windows::Forms::Label());
			this->player2s2 = (gcnew System::Windows::Forms::Label());
			this->player1s1 = (gcnew System::Windows::Forms::Label());
			this->player1s2 = (gcnew System::Windows::Forms::Label());
			this->player1s4 = (gcnew System::Windows::Forms::Label());
			this->player1s3 = (gcnew System::Windows::Forms::Label());
			this->player2s3 = (gcnew System::Windows::Forms::Label());
			this->player2s4 = (gcnew System::Windows::Forms::Label());
			this->player2 = (gcnew System::Windows::Forms::Label());
			this->player1 = (gcnew System::Windows::Forms::Label());
			this->result = (gcnew System::Windows::Forms::Label());
			this->info = (gcnew System::Windows::Forms::Label());
			this->reset_button = (gcnew System::Windows::Forms::Button());
			this->calc_button = (gcnew System::Windows::Forms::Button());
			this->configure = (gcnew System::Windows::Forms::Button());
			this->configFrame = (gcnew System::Windows::Forms::PictureBox());
			this->frames1s1 = (gcnew System::Windows::Forms::PictureBox());
			this->frames1s2 = (gcnew System::Windows::Forms::PictureBox());
			this->frames2s1 = (gcnew System::Windows::Forms::PictureBox());
			this->frames2s2 = (gcnew System::Windows::Forms::PictureBox());
			this->frames3s1 = (gcnew System::Windows::Forms::PictureBox());
			this->frames4s1 = (gcnew System::Windows::Forms::PictureBox());
			this->frames4s2 = (gcnew System::Windows::Forms::PictureBox());
			this->frames1s3 = (gcnew System::Windows::Forms::PictureBox());
			this->frames1s4 = (gcnew System::Windows::Forms::PictureBox());
			this->frames2s3 = (gcnew System::Windows::Forms::PictureBox());
			this->frames2s4 = (gcnew System::Windows::Forms::PictureBox());
			this->frames3s3 = (gcnew System::Windows::Forms::PictureBox());
			this->frames3s4 = (gcnew System::Windows::Forms::PictureBox());
			this->frames4s3 = (gcnew System::Windows::Forms::PictureBox());
			this->frames4s4 = (gcnew System::Windows::Forms::PictureBox());
			this->frames3s2 = (gcnew System::Windows::Forms::PictureBox());
			this->result_2player = (gcnew System::Windows::Forms::TextBox());
			this->result_1player = (gcnew System::Windows::Forms::TextBox());
			this->pl1s1s1 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s1s1 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s1s2 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s1s2 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s2s1 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s2s1 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s2s2 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s2s2 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s3s1 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s3s1 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s3s2 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s3s2 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s4s1 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s4s1 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s4s2 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s4s2 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s1s3 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s1s3 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s1s4 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s1s4 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s2s3 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s2s3 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s2s4 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s2s4 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s3s3 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s3s3 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s3s4 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s3s4 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s4s3 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s4s3 = (gcnew System::Windows::Forms::TextBox());
			this->pl2s4s4 = (gcnew System::Windows::Forms::TextBox());
			this->pl1s4s4 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->configFrame))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames1s1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames1s2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames2s1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames2s2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames3s1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames4s1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames4s2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames1s3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames1s4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames2s3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames2s4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames3s3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames3s4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames4s3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames4s4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames3s2))->BeginInit();
			this->SuspendLayout();
			// 
			// result_player2
			// 
			this->result_player2->AutoSize = true;
			this->result_player2->BackColor = System::Drawing::Color::Transparent;
			this->result_player2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result_player2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->result_player2->Location = System::Drawing::Point(776, 369);
			this->result_player2->Name = L"result_player2";
			this->result_player2->Size = System::Drawing::Size(63, 20);
			this->result_player2->TabIndex = 94;
			this->result_player2->Text = L"Player 2:";
			// 
			// result_player1
			// 
			this->result_player1->AutoSize = true;
			this->result_player1->BackColor = System::Drawing::Color::Transparent;
			this->result_player1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result_player1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->result_player1->Location = System::Drawing::Point(776, 308);
			this->result_player1->Name = L"result_player1";
			this->result_player1->Size = System::Drawing::Size(63, 20);
			this->result_player1->TabIndex = 96;
			this->result_player1->Text = L"Player 1:";
			// 
			// semicolons1s1
			// 
			this->semicolons1s1->AutoSize = true;
			this->semicolons1s1->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons1s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons1s1->Location = System::Drawing::Point(245, 120);
			this->semicolons1s1->Name = L"semicolons1s1";
			this->semicolons1s1->Size = System::Drawing::Size(13, 20);
			this->semicolons1s1->TabIndex = 40;
			this->semicolons1s1->Text = L";";
			// 
			// semicolons1s2
			// 
			this->semicolons1s2->AutoSize = true;
			this->semicolons1s2->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons1s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons1s2->Location = System::Drawing::Point(245, 177);
			this->semicolons1s2->Name = L"semicolons1s2";
			this->semicolons1s2->Size = System::Drawing::Size(13, 20);
			this->semicolons1s2->TabIndex = 52;
			this->semicolons1s2->Text = L";";
			// 
			// semicolons2s1
			// 
			this->semicolons2s1->AutoSize = true;
			this->semicolons2s1->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons2s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons2s1->Location = System::Drawing::Point(384, 120);
			this->semicolons2s1->Name = L"semicolons2s1";
			this->semicolons2s1->Size = System::Drawing::Size(13, 20);
			this->semicolons2s1->TabIndex = 71;
			this->semicolons2s1->Text = L";";
			// 
			// semicolons2s2
			// 
			this->semicolons2s2->AutoSize = true;
			this->semicolons2s2->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons2s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons2s2->Location = System::Drawing::Point(384, 177);
			this->semicolons2s2->Name = L"semicolons2s2";
			this->semicolons2s2->Size = System::Drawing::Size(13, 20);
			this->semicolons2s2->TabIndex = 77;
			this->semicolons2s2->Text = L";";
			// 
			// semicolons3s1
			// 
			this->semicolons3s1->AutoSize = true;
			this->semicolons3s1->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons3s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons3s1->Location = System::Drawing::Point(523, 120);
			this->semicolons3s1->Name = L"semicolons3s1";
			this->semicolons3s1->Size = System::Drawing::Size(13, 20);
			this->semicolons3s1->TabIndex = 83;
			this->semicolons3s1->Text = L";";
			// 
			// semicolons3s2
			// 
			this->semicolons3s2->AutoSize = true;
			this->semicolons3s2->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons3s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons3s2->Location = System::Drawing::Point(523, 177);
			this->semicolons3s2->Name = L"semicolons3s2";
			this->semicolons3s2->Size = System::Drawing::Size(13, 20);
			this->semicolons3s2->TabIndex = 89;
			this->semicolons3s2->Text = L";";
			// 
			// semicolons4s1
			// 
			this->semicolons4s1->AutoSize = true;
			this->semicolons4s1->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons4s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons4s1->Location = System::Drawing::Point(662, 120);
			this->semicolons4s1->Name = L"semicolons4s1";
			this->semicolons4s1->Size = System::Drawing::Size(13, 20);
			this->semicolons4s1->TabIndex = 105;
			this->semicolons4s1->Text = L";";
			// 
			// semicolons4s2
			// 
			this->semicolons4s2->AutoSize = true;
			this->semicolons4s2->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons4s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons4s2->Location = System::Drawing::Point(662, 177);
			this->semicolons4s2->Name = L"semicolons4s2";
			this->semicolons4s2->Size = System::Drawing::Size(13, 20);
			this->semicolons4s2->TabIndex = 111;
			this->semicolons4s2->Text = L";";
			// 
			// semicolons1s3
			// 
			this->semicolons1s3->AutoSize = true;
			this->semicolons1s3->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons1s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons1s3->Location = System::Drawing::Point(245, 234);
			this->semicolons1s3->Name = L"semicolons1s3";
			this->semicolons1s3->Size = System::Drawing::Size(13, 20);
			this->semicolons1s3->TabIndex = 117;
			this->semicolons1s3->Text = L";";
			// 
			// semicolons1s4
			// 
			this->semicolons1s4->AutoSize = true;
			this->semicolons1s4->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons1s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons1s4->Location = System::Drawing::Point(245, 289);
			this->semicolons1s4->Name = L"semicolons1s4";
			this->semicolons1s4->Size = System::Drawing::Size(13, 20);
			this->semicolons1s4->TabIndex = 123;
			this->semicolons1s4->Text = L";";
			// 
			// semicolons2s3
			// 
			this->semicolons2s3->AutoSize = true;
			this->semicolons2s3->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons2s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons2s3->Location = System::Drawing::Point(384, 234);
			this->semicolons2s3->Name = L"semicolons2s3";
			this->semicolons2s3->Size = System::Drawing::Size(13, 20);
			this->semicolons2s3->TabIndex = 129;
			this->semicolons2s3->Text = L";";
			// 
			// semicolons2s4
			// 
			this->semicolons2s4->AutoSize = true;
			this->semicolons2s4->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons2s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons2s4->Location = System::Drawing::Point(384, 289);
			this->semicolons2s4->Name = L"semicolons2s4";
			this->semicolons2s4->Size = System::Drawing::Size(13, 20);
			this->semicolons2s4->TabIndex = 135;
			this->semicolons2s4->Text = L";";
			// 
			// semicolons3s3
			// 
			this->semicolons3s3->AutoSize = true;
			this->semicolons3s3->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons3s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons3s3->Location = System::Drawing::Point(523, 234);
			this->semicolons3s3->Name = L"semicolons3s3";
			this->semicolons3s3->Size = System::Drawing::Size(13, 20);
			this->semicolons3s3->TabIndex = 141;
			this->semicolons3s3->Text = L";";
			// 
			// semicolons3s4
			// 
			this->semicolons3s4->AutoSize = true;
			this->semicolons3s4->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons3s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons3s4->Location = System::Drawing::Point(523, 289);
			this->semicolons3s4->Name = L"semicolons3s4";
			this->semicolons3s4->Size = System::Drawing::Size(13, 20);
			this->semicolons3s4->TabIndex = 147;
			this->semicolons3s4->Text = L";";
			// 
			// semicolons4s3
			// 
			this->semicolons4s3->AutoSize = true;
			this->semicolons4s3->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons4s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons4s3->Location = System::Drawing::Point(662, 234);
			this->semicolons4s3->Name = L"semicolons4s3";
			this->semicolons4s3->Size = System::Drawing::Size(13, 20);
			this->semicolons4s3->TabIndex = 153;
			this->semicolons4s3->Text = L";";
			// 
			// semicolons4s4
			// 
			this->semicolons4s4->AutoSize = true;
			this->semicolons4s4->BackColor = System::Drawing::SystemColors::Window;
			this->semicolons4s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->semicolons4s4->Location = System::Drawing::Point(662, 289);
			this->semicolons4s4->Name = L"semicolons4s4";
			this->semicolons4s4->Size = System::Drawing::Size(13, 20);
			this->semicolons4s4->TabIndex = 159;
			this->semicolons4s4->Text = L";";
			// 
			// player1_conf
			// 
			this->player1_conf->AutoSize = true;
			this->player1_conf->BackColor = System::Drawing::Color::Transparent;
			this->player1_conf->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player1_conf->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player1_conf->Location = System::Drawing::Point(819, 107);
			this->player1_conf->Name = L"player1_conf";
			this->player1_conf->Size = System::Drawing::Size(59, 20);
			this->player1_conf->TabIndex = 165;
			this->player1_conf->Text = L"Player 1";
			// 
			// player2_conf
			// 
			this->player2_conf->AutoSize = true;
			this->player2_conf->BackColor = System::Drawing::Color::Transparent;
			this->player2_conf->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player2_conf->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player2_conf->Location = System::Drawing::Point(819, 146);
			this->player2_conf->Name = L"player2_conf";
			this->player2_conf->Size = System::Drawing::Size(59, 20);
			this->player2_conf->TabIndex = 166;
			this->player2_conf->Text = L"Player 2";
			// 
			// description
			// 
			this->description->AutoSize = true;
			this->description->ForeColor = System::Drawing::SystemColors::Desktop;
			this->description->Location = System::Drawing::Point(830, 46);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(138, 40);
			this->description->TabIndex = 168;
			this->description->Text = L"Select the number of\n player strategies";
			this->description->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// stick1s1s1
			// 
			this->stick1s1s1->AutoSize = true;
			this->stick1s1s1->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s1s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s1s1->Location = System::Drawing::Point(209, 124);
			this->stick1s1s1->Name = L"stick1s1s1";
			this->stick1s1s1->Size = System::Drawing::Size(30, 20);
			this->stick1s1s1->TabIndex = 42;
			this->stick1s1s1->Text = L"___";
			// 
			// stick2s1s1
			// 
			this->stick2s1s1->AutoSize = true;
			this->stick2s1s1->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s1s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s1s1->Location = System::Drawing::Point(264, 124);
			this->stick2s1s1->Name = L"stick2s1s1";
			this->stick2s1s1->Size = System::Drawing::Size(30, 20);
			this->stick2s1s1->TabIndex = 41;
			this->stick2s1s1->Text = L"___";
			// 
			// stick1s1s2
			// 
			this->stick1s1s2->AutoSize = true;
			this->stick1s1s2->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s1s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s1s2->Location = System::Drawing::Point(209, 181);
			this->stick1s1s2->Name = L"stick1s1s2";
			this->stick1s1s2->Size = System::Drawing::Size(30, 20);
			this->stick1s1s2->TabIndex = 54;
			this->stick1s1s2->Text = L"___";
			// 
			// stick2s1s2
			// 
			this->stick2s1s2->AutoSize = true;
			this->stick2s1s2->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s1s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s1s2->Location = System::Drawing::Point(264, 181);
			this->stick2s1s2->Name = L"stick2s1s2";
			this->stick2s1s2->Size = System::Drawing::Size(30, 20);
			this->stick2s1s2->TabIndex = 53;
			this->stick2s1s2->Text = L"___";
			// 
			// stick2s2s1
			// 
			this->stick2s2s1->AutoSize = true;
			this->stick2s2s1->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s2s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s2s1->Location = System::Drawing::Point(403, 124);
			this->stick2s2s1->Name = L"stick2s2s1";
			this->stick2s2s1->Size = System::Drawing::Size(30, 20);
			this->stick2s2s1->TabIndex = 72;
			this->stick2s2s1->Text = L"___";
			// 
			// stick1s2s1
			// 
			this->stick1s2s1->AutoSize = true;
			this->stick1s2s1->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s2s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s2s1->Location = System::Drawing::Point(348, 124);
			this->stick1s2s1->Name = L"stick1s2s1";
			this->stick1s2s1->Size = System::Drawing::Size(30, 20);
			this->stick1s2s1->TabIndex = 73;
			this->stick1s2s1->Text = L"___";
			// 
			// stick2s2s2
			// 
			this->stick2s2s2->AutoSize = true;
			this->stick2s2s2->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s2s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s2s2->Location = System::Drawing::Point(403, 181);
			this->stick2s2s2->Name = L"stick2s2s2";
			this->stick2s2s2->Size = System::Drawing::Size(30, 20);
			this->stick2s2s2->TabIndex = 78;
			this->stick2s2s2->Text = L"___";
			// 
			// stick1s2s2
			// 
			this->stick1s2s2->AutoSize = true;
			this->stick1s2s2->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s2s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s2s2->Location = System::Drawing::Point(348, 181);
			this->stick1s2s2->Name = L"stick1s2s2";
			this->stick1s2s2->Size = System::Drawing::Size(30, 20);
			this->stick1s2s2->TabIndex = 79;
			this->stick1s2s2->Text = L"___";
			// 
			// stick2s3s1
			// 
			this->stick2s3s1->AutoSize = true;
			this->stick2s3s1->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s3s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s3s1->Location = System::Drawing::Point(542, 124);
			this->stick2s3s1->Name = L"stick2s3s1";
			this->stick2s3s1->Size = System::Drawing::Size(30, 20);
			this->stick2s3s1->TabIndex = 84;
			this->stick2s3s1->Text = L"___";
			// 
			// stick1s3s1
			// 
			this->stick1s3s1->AutoSize = true;
			this->stick1s3s1->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s3s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s3s1->Location = System::Drawing::Point(487, 124);
			this->stick1s3s1->Name = L"stick1s3s1";
			this->stick1s3s1->Size = System::Drawing::Size(30, 20);
			this->stick1s3s1->TabIndex = 85;
			this->stick1s3s1->Text = L"___";
			// 
			// stick2s3s2
			// 
			this->stick2s3s2->AutoSize = true;
			this->stick2s3s2->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s3s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s3s2->Location = System::Drawing::Point(542, 181);
			this->stick2s3s2->Name = L"stick2s3s2";
			this->stick2s3s2->Size = System::Drawing::Size(30, 20);
			this->stick2s3s2->TabIndex = 90;
			this->stick2s3s2->Text = L"___";
			// 
			// stick1s3s2
			// 
			this->stick1s3s2->AutoSize = true;
			this->stick1s3s2->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s3s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s3s2->Location = System::Drawing::Point(487, 181);
			this->stick1s3s2->Name = L"stick1s3s2";
			this->stick1s3s2->Size = System::Drawing::Size(30, 20);
			this->stick1s3s2->TabIndex = 91;
			this->stick1s3s2->Text = L"___";
			// 
			// stick2s4s1
			// 
			this->stick2s4s1->AutoSize = true;
			this->stick2s4s1->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s4s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s4s1->Location = System::Drawing::Point(681, 124);
			this->stick2s4s1->Name = L"stick2s4s1";
			this->stick2s4s1->Size = System::Drawing::Size(30, 20);
			this->stick2s4s1->TabIndex = 106;
			this->stick2s4s1->Text = L"___";
			// 
			// stick1s4s1
			// 
			this->stick1s4s1->AutoSize = true;
			this->stick1s4s1->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s4s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s4s1->Location = System::Drawing::Point(626, 124);
			this->stick1s4s1->Name = L"stick1s4s1";
			this->stick1s4s1->Size = System::Drawing::Size(30, 20);
			this->stick1s4s1->TabIndex = 107;
			this->stick1s4s1->Text = L"___";
			// 
			// stick2s4s2
			// 
			this->stick2s4s2->AutoSize = true;
			this->stick2s4s2->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s4s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s4s2->Location = System::Drawing::Point(681, 181);
			this->stick2s4s2->Name = L"stick2s4s2";
			this->stick2s4s2->Size = System::Drawing::Size(30, 20);
			this->stick2s4s2->TabIndex = 112;
			this->stick2s4s2->Text = L"___";
			// 
			// stick1s4s2
			// 
			this->stick1s4s2->AutoSize = true;
			this->stick1s4s2->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s4s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s4s2->Location = System::Drawing::Point(626, 181);
			this->stick1s4s2->Name = L"stick1s4s2";
			this->stick1s4s2->Size = System::Drawing::Size(30, 20);
			this->stick1s4s2->TabIndex = 113;
			this->stick1s4s2->Text = L"___";
			// 
			// stick2s1s3
			// 
			this->stick2s1s3->AutoSize = true;
			this->stick2s1s3->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s1s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s1s3->Location = System::Drawing::Point(264, 238);
			this->stick2s1s3->Name = L"stick2s1s3";
			this->stick2s1s3->Size = System::Drawing::Size(30, 20);
			this->stick2s1s3->TabIndex = 118;
			this->stick2s1s3->Text = L"___";
			// 
			// stick1s1s3
			// 
			this->stick1s1s3->AutoSize = true;
			this->stick1s1s3->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s1s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s1s3->Location = System::Drawing::Point(209, 238);
			this->stick1s1s3->Name = L"stick1s1s3";
			this->stick1s1s3->Size = System::Drawing::Size(30, 20);
			this->stick1s1s3->TabIndex = 119;
			this->stick1s1s3->Text = L"___";
			// 
			// stick2s1s4
			// 
			this->stick2s1s4->AutoSize = true;
			this->stick2s1s4->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s1s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s1s4->Location = System::Drawing::Point(264, 293);
			this->stick2s1s4->Name = L"stick2s1s4";
			this->stick2s1s4->Size = System::Drawing::Size(30, 20);
			this->stick2s1s4->TabIndex = 124;
			this->stick2s1s4->Text = L"___";
			// 
			// stick1s1s4
			// 
			this->stick1s1s4->AutoSize = true;
			this->stick1s1s4->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s1s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s1s4->Location = System::Drawing::Point(209, 293);
			this->stick1s1s4->Name = L"stick1s1s4";
			this->stick1s1s4->Size = System::Drawing::Size(30, 20);
			this->stick1s1s4->TabIndex = 125;
			this->stick1s1s4->Text = L"___";
			// 
			// stick2s2s3
			// 
			this->stick2s2s3->AutoSize = true;
			this->stick2s2s3->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s2s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s2s3->Location = System::Drawing::Point(403, 238);
			this->stick2s2s3->Name = L"stick2s2s3";
			this->stick2s2s3->Size = System::Drawing::Size(30, 20);
			this->stick2s2s3->TabIndex = 130;
			this->stick2s2s3->Text = L"___";
			// 
			// stick1s2s3
			// 
			this->stick1s2s3->AutoSize = true;
			this->stick1s2s3->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s2s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s2s3->Location = System::Drawing::Point(348, 238);
			this->stick1s2s3->Name = L"stick1s2s3";
			this->stick1s2s3->Size = System::Drawing::Size(30, 20);
			this->stick1s2s3->TabIndex = 131;
			this->stick1s2s3->Text = L"___";
			// 
			// stick2s2s4
			// 
			this->stick2s2s4->AutoSize = true;
			this->stick2s2s4->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s2s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s2s4->Location = System::Drawing::Point(403, 293);
			this->stick2s2s4->Name = L"stick2s2s4";
			this->stick2s2s4->Size = System::Drawing::Size(30, 20);
			this->stick2s2s4->TabIndex = 136;
			this->stick2s2s4->Text = L"___";
			// 
			// stick1s2s4
			// 
			this->stick1s2s4->AutoSize = true;
			this->stick1s2s4->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s2s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s2s4->Location = System::Drawing::Point(348, 293);
			this->stick1s2s4->Name = L"stick1s2s4";
			this->stick1s2s4->Size = System::Drawing::Size(30, 20);
			this->stick1s2s4->TabIndex = 137;
			this->stick1s2s4->Text = L"___";
			// 
			// stick2s3s3
			// 
			this->stick2s3s3->AutoSize = true;
			this->stick2s3s3->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s3s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s3s3->Location = System::Drawing::Point(542, 238);
			this->stick2s3s3->Name = L"stick2s3s3";
			this->stick2s3s3->Size = System::Drawing::Size(30, 20);
			this->stick2s3s3->TabIndex = 142;
			this->stick2s3s3->Text = L"___";
			// 
			// stick1s3s3
			// 
			this->stick1s3s3->AutoSize = true;
			this->stick1s3s3->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s3s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s3s3->Location = System::Drawing::Point(487, 238);
			this->stick1s3s3->Name = L"stick1s3s3";
			this->stick1s3s3->Size = System::Drawing::Size(30, 20);
			this->stick1s3s3->TabIndex = 143;
			this->stick1s3s3->Text = L"___";
			// 
			// stick2s3s4
			// 
			this->stick2s3s4->AutoSize = true;
			this->stick2s3s4->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s3s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s3s4->Location = System::Drawing::Point(542, 293);
			this->stick2s3s4->Name = L"stick2s3s4";
			this->stick2s3s4->Size = System::Drawing::Size(30, 20);
			this->stick2s3s4->TabIndex = 148;
			this->stick2s3s4->Text = L"___";
			// 
			// stick1s3s4
			// 
			this->stick1s3s4->AutoSize = true;
			this->stick1s3s4->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s3s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s3s4->Location = System::Drawing::Point(487, 293);
			this->stick1s3s4->Name = L"stick1s3s4";
			this->stick1s3s4->Size = System::Drawing::Size(30, 20);
			this->stick1s3s4->TabIndex = 149;
			this->stick1s3s4->Text = L"___";
			// 
			// stick2s4s3
			// 
			this->stick2s4s3->AutoSize = true;
			this->stick2s4s3->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s4s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s4s3->Location = System::Drawing::Point(681, 238);
			this->stick2s4s3->Name = L"stick2s4s3";
			this->stick2s4s3->Size = System::Drawing::Size(30, 20);
			this->stick2s4s3->TabIndex = 154;
			this->stick2s4s3->Text = L"___";
			// 
			// stick1s4s3
			// 
			this->stick1s4s3->AutoSize = true;
			this->stick1s4s3->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s4s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s4s3->Location = System::Drawing::Point(626, 238);
			this->stick1s4s3->Name = L"stick1s4s3";
			this->stick1s4s3->Size = System::Drawing::Size(30, 20);
			this->stick1s4s3->TabIndex = 155;
			this->stick1s4s3->Text = L"___";
			// 
			// stick2s4s4
			// 
			this->stick2s4s4->AutoSize = true;
			this->stick2s4s4->BackColor = System::Drawing::SystemColors::Window;
			this->stick2s4s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick2s4s4->Location = System::Drawing::Point(681, 293);
			this->stick2s4s4->Name = L"stick2s4s4";
			this->stick2s4s4->Size = System::Drawing::Size(30, 20);
			this->stick2s4s4->TabIndex = 160;
			this->stick2s4s4->Text = L"___";
			// 
			// stick1s4s4
			// 
			this->stick1s4s4->AutoSize = true;
			this->stick1s4s4->BackColor = System::Drawing::SystemColors::Window;
			this->stick1s4s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stick1s4s4->Location = System::Drawing::Point(626, 293);
			this->stick1s4s4->Name = L"stick1s4s4";
			this->stick1s4s4->Size = System::Drawing::Size(30, 20);
			this->stick1s4s4->TabIndex = 161;
			this->stick1s4s4->Text = L"___";
			// 
			// player2s1
			// 
			this->player2s1->AutoSize = true;
			this->player2s1->BackColor = System::Drawing::Color::Transparent;
			this->player2s1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player2s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player2s1->Location = System::Drawing::Point(98, 119);
			this->player2s1->Name = L"player2s1";
			this->player2s1->Size = System::Drawing::Size(71, 20);
			this->player2s1->TabIndex = 6;
			this->player2s1->Text = L"Strategy 1";
			this->player2s1->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// player2s2
			// 
			this->player2s2->AutoSize = true;
			this->player2s2->BackColor = System::Drawing::Color::Transparent;
			this->player2s2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player2s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player2s2->Location = System::Drawing::Point(98, 178);
			this->player2s2->Name = L"player2s2";
			this->player2s2->Size = System::Drawing::Size(71, 20);
			this->player2s2->TabIndex = 7;
			this->player2s2->Text = L"Strategy 2";
			this->player2s2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// player1s1
			// 
			this->player1s1->AutoSize = true;
			this->player1s1->BackColor = System::Drawing::Color::Transparent;
			this->player1s1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player1s1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player1s1->Location = System::Drawing::Point(209, 66);
			this->player1s1->Name = L"player1s1";
			this->player1s1->Size = System::Drawing::Size(71, 20);
			this->player1s1->TabIndex = 1;
			this->player1s1->Text = L"Strategy 1";
			// 
			// player1s2
			// 
			this->player1s2->AutoSize = true;
			this->player1s2->BackColor = System::Drawing::Color::Transparent;
			this->player1s2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player1s2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player1s2->Location = System::Drawing::Point(348, 66);
			this->player1s2->Name = L"player1s2";
			this->player1s2->Size = System::Drawing::Size(71, 20);
			this->player1s2->TabIndex = 2;
			this->player1s2->Text = L"Strategy 2";
			// 
			// player1s4
			// 
			this->player1s4->AutoSize = true;
			this->player1s4->BackColor = System::Drawing::Color::Transparent;
			this->player1s4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player1s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player1s4->Location = System::Drawing::Point(626, 66);
			this->player1s4->Name = L"player1s4";
			this->player1s4->Size = System::Drawing::Size(71, 20);
			this->player1s4->TabIndex = 162;
			this->player1s4->Text = L"Strategy 4";
			// 
			// player1s3
			// 
			this->player1s3->AutoSize = true;
			this->player1s3->BackColor = System::Drawing::Color::Transparent;
			this->player1s3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player1s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player1s3->Location = System::Drawing::Point(487, 66);
			this->player1s3->Name = L"player1s3";
			this->player1s3->Size = System::Drawing::Size(71, 20);
			this->player1s3->TabIndex = 67;
			this->player1s3->Text = L"Strategy 3";
			// 
			// player2s3
			// 
			this->player2s3->AutoSize = true;
			this->player2s3->BackColor = System::Drawing::Color::Transparent;
			this->player2s3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player2s3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player2s3->Location = System::Drawing::Point(98, 234);
			this->player2s3->Name = L"player2s3";
			this->player2s3->Size = System::Drawing::Size(71, 20);
			this->player2s3->TabIndex = 163;
			this->player2s3->Text = L"Strategy 3";
			this->player2s3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// player2s4
			// 
			this->player2s4->AutoSize = true;
			this->player2s4->BackColor = System::Drawing::Color::Transparent;
			this->player2s4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player2s4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player2s4->Location = System::Drawing::Point(98, 288);
			this->player2s4->Name = L"player2s4";
			this->player2s4->Size = System::Drawing::Size(71, 20);
			this->player2s4->TabIndex = 164;
			this->player2s4->Text = L"Strategy 4";
			this->player2s4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// player2
			// 
			this->player2->AutoSize = true;
			this->player2->BackColor = System::Drawing::Color::Transparent;
			this->player2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player2->Location = System::Drawing::Point(20, 207);
			this->player2->Name = L"player2";
			this->player2->Size = System::Drawing::Size(70, 23);
			this->player2->TabIndex = 9;
			this->player2->Text = L"Player 2";
			// 
			// player1
			// 
			this->player1->AutoSize = true;
			this->player1->BackColor = System::Drawing::Color::Transparent;
			this->player1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->player1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->player1->Location = System::Drawing::Point(422, 29);
			this->player1->Name = L"player1";
			this->player1->Size = System::Drawing::Size(70, 23);
			this->player1->TabIndex = 0;
			this->player1->Text = L"Player 1";
			// 
			// result
			// 
			this->result->AutoSize = true;
			this->result->BackColor = System::Drawing::Color::Transparent;
			this->result->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result->ForeColor = System::Drawing::SystemColors::ControlText;
			this->result->Location = System::Drawing::Point(870, 279);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(52, 20);
			this->result->TabIndex = 33;
			this->result->Text = L"Result:";
			// 
			// info
			// 
			this->info->AutoSize = true;
			this->info->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->info->ForeColor = System::Drawing::SystemColors::Desktop;
			this->info->Location = System::Drawing::Point(194, 202);
			this->info->Name = L"info";
			this->info->Size = System::Drawing::Size(398, 26);
			this->info->TabIndex = 169;
			this->info->Text = L"Please select the number of player strategies";
			this->info->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// reset_button
			// 
			this->reset_button->BackColor = System::Drawing::SystemColors::HighlightText;
			this->reset_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->reset_button->FlatAppearance->BorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->reset_button->FlatAppearance->BorderSize = 2;
			this->reset_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->reset_button->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->reset_button->Location = System::Drawing::Point(102, 382);
			this->reset_button->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->reset_button->Name = L"reset_button";
			this->reset_button->Size = System::Drawing::Size(247, 36);
			this->reset_button->TabIndex = 5;
			this->reset_button->Text = L"Reset";
			this->reset_button->UseVisualStyleBackColor = false;
			this->reset_button->Click += gcnew System::EventHandler(this, &MyForm::reset_button_Click);
			// 
			// calc_button
			// 
			this->calc_button->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->calc_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->calc_button->FlatAppearance->BorderColor = System::Drawing::SystemColors::HotTrack;
			this->calc_button->FlatAppearance->BorderSize = 0;
			this->calc_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->calc_button->ForeColor = System::Drawing::SystemColors::Window;
			this->calc_button->Location = System::Drawing::Point(428, 382);
			this->calc_button->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->calc_button->Name = L"calc_button";
			this->calc_button->Size = System::Drawing::Size(247, 36);
			this->calc_button->TabIndex = 8;
			this->calc_button->Text = L"Calculate";
			this->calc_button->UseVisualStyleBackColor = false;
			this->calc_button->Click += gcnew System::EventHandler(this, &MyForm::calc_button_Click);
			// 
			// configure
			// 
			this->configure->BackColor = System::Drawing::SystemColors::HighlightText;
			this->configure->FlatAppearance->BorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->configure->FlatAppearance->BorderSize = 2;
			this->configure->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->configure->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->configure->Location = System::Drawing::Point(807, 202);
			this->configure->Name = L"configure";
			this->configure->Size = System::Drawing::Size(195, 37);
			this->configure->TabIndex = 101;
			this->configure->Text = L"Configure";
			this->configure->UseVisualStyleBackColor = false;
			this->configure->Click += gcnew System::EventHandler(this, &MyForm::configure_Click);
			// 
			// configFrame
			// 
			this->configFrame->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->configFrame->Location = System::Drawing::Point(767, -4);
			this->configFrame->Name = L"configFrame";
			this->configFrame->Size = System::Drawing::Size(274, 479);
			this->configFrame->TabIndex = 167;
			this->configFrame->TabStop = false;
			// 
			// frames1s1
			// 
			this->frames1s1->BackColor = System::Drawing::SystemColors::Window;
			this->frames1s1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames1s1->Location = System::Drawing::Point(184, 104);
			this->frames1s1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames1s1->Name = L"frames1s1";
			this->frames1s1->Size = System::Drawing::Size(135, 55);
			this->frames1s1->TabIndex = 38;
			this->frames1s1->TabStop = false;
			// 
			// frames1s2
			// 
			this->frames1s2->BackColor = System::Drawing::SystemColors::Window;
			this->frames1s2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames1s2->Location = System::Drawing::Point(184, 165);
			this->frames1s2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames1s2->Name = L"frames1s2";
			this->frames1s2->Size = System::Drawing::Size(135, 51);
			this->frames1s2->TabIndex = 50;
			this->frames1s2->TabStop = false;
			// 
			// frames2s1
			// 
			this->frames2s1->BackColor = System::Drawing::SystemColors::Window;
			this->frames2s1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames2s1->Location = System::Drawing::Point(323, 104);
			this->frames2s1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames2s1->Name = L"frames2s1";
			this->frames2s1->Size = System::Drawing::Size(135, 55);
			this->frames2s1->TabIndex = 69;
			this->frames2s1->TabStop = false;
			// 
			// frames2s2
			// 
			this->frames2s2->BackColor = System::Drawing::SystemColors::Window;
			this->frames2s2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames2s2->Location = System::Drawing::Point(323, 165);
			this->frames2s2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames2s2->Name = L"frames2s2";
			this->frames2s2->Size = System::Drawing::Size(135, 51);
			this->frames2s2->TabIndex = 75;
			this->frames2s2->TabStop = false;
			// 
			// frames3s1
			// 
			this->frames3s1->BackColor = System::Drawing::SystemColors::Window;
			this->frames3s1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames3s1->Location = System::Drawing::Point(462, 104);
			this->frames3s1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames3s1->Name = L"frames3s1";
			this->frames3s1->Size = System::Drawing::Size(135, 55);
			this->frames3s1->TabIndex = 81;
			this->frames3s1->TabStop = false;
			// 
			// frames4s1
			// 
			this->frames4s1->BackColor = System::Drawing::SystemColors::Window;
			this->frames4s1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames4s1->Location = System::Drawing::Point(601, 104);
			this->frames4s1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames4s1->Name = L"frames4s1";
			this->frames4s1->Size = System::Drawing::Size(135, 55);
			this->frames4s1->TabIndex = 103;
			this->frames4s1->TabStop = false;
			// 
			// frames4s2
			// 
			this->frames4s2->BackColor = System::Drawing::SystemColors::Window;
			this->frames4s2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames4s2->Location = System::Drawing::Point(601, 165);
			this->frames4s2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames4s2->Name = L"frames4s2";
			this->frames4s2->Size = System::Drawing::Size(135, 51);
			this->frames4s2->TabIndex = 109;
			this->frames4s2->TabStop = false;
			// 
			// frames1s3
			// 
			this->frames1s3->BackColor = System::Drawing::SystemColors::Window;
			this->frames1s3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames1s3->Location = System::Drawing::Point(184, 222);
			this->frames1s3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames1s3->Name = L"frames1s3";
			this->frames1s3->Size = System::Drawing::Size(135, 51);
			this->frames1s3->TabIndex = 115;
			this->frames1s3->TabStop = false;
			// 
			// frames1s4
			// 
			this->frames1s4->BackColor = System::Drawing::SystemColors::Window;
			this->frames1s4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames1s4->Location = System::Drawing::Point(184, 279);
			this->frames1s4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames1s4->Name = L"frames1s4";
			this->frames1s4->Size = System::Drawing::Size(135, 49);
			this->frames1s4->TabIndex = 121;
			this->frames1s4->TabStop = false;
			// 
			// frames2s3
			// 
			this->frames2s3->BackColor = System::Drawing::SystemColors::Window;
			this->frames2s3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames2s3->Location = System::Drawing::Point(323, 222);
			this->frames2s3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames2s3->Name = L"frames2s3";
			this->frames2s3->Size = System::Drawing::Size(135, 51);
			this->frames2s3->TabIndex = 127;
			this->frames2s3->TabStop = false;
			// 
			// frames2s4
			// 
			this->frames2s4->BackColor = System::Drawing::SystemColors::Window;
			this->frames2s4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames2s4->Location = System::Drawing::Point(323, 279);
			this->frames2s4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames2s4->Name = L"frames2s4";
			this->frames2s4->Size = System::Drawing::Size(135, 49);
			this->frames2s4->TabIndex = 133;
			this->frames2s4->TabStop = false;
			// 
			// frames3s3
			// 
			this->frames3s3->BackColor = System::Drawing::SystemColors::Window;
			this->frames3s3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames3s3->Location = System::Drawing::Point(462, 222);
			this->frames3s3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames3s3->Name = L"frames3s3";
			this->frames3s3->Size = System::Drawing::Size(135, 51);
			this->frames3s3->TabIndex = 139;
			this->frames3s3->TabStop = false;
			// 
			// frames3s4
			// 
			this->frames3s4->BackColor = System::Drawing::SystemColors::Window;
			this->frames3s4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames3s4->Location = System::Drawing::Point(462, 279);
			this->frames3s4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames3s4->Name = L"frames3s4";
			this->frames3s4->Size = System::Drawing::Size(135, 49);
			this->frames3s4->TabIndex = 145;
			this->frames3s4->TabStop = false;
			// 
			// frames4s3
			// 
			this->frames4s3->BackColor = System::Drawing::SystemColors::Window;
			this->frames4s3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames4s3->Location = System::Drawing::Point(601, 222);
			this->frames4s3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames4s3->Name = L"frames4s3";
			this->frames4s3->Size = System::Drawing::Size(135, 51);
			this->frames4s3->TabIndex = 151;
			this->frames4s3->TabStop = false;
			// 
			// frames4s4
			// 
			this->frames4s4->BackColor = System::Drawing::SystemColors::Window;
			this->frames4s4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames4s4->Location = System::Drawing::Point(601, 279);
			this->frames4s4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames4s4->Name = L"frames4s4";
			this->frames4s4->Size = System::Drawing::Size(135, 49);
			this->frames4s4->TabIndex = 157;
			this->frames4s4->TabStop = false;
			// 
			// frames3s2
			// 
			this->frames3s2->BackColor = System::Drawing::SystemColors::Window;
			this->frames3s2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->frames3s2->Location = System::Drawing::Point(462, 165);
			this->frames3s2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->frames3s2->Name = L"frames3s2";
			this->frames3s2->Size = System::Drawing::Size(135, 51);
			this->frames3s2->TabIndex = 87;
			this->frames3s2->TabStop = false;
			// 
			// result_2player
			// 
			this->result_2player->Location = System::Drawing::Point(807, 392);
			this->result_2player->Name = L"result_2player";
			this->result_2player->ReadOnly = true;
			this->result_2player->Size = System::Drawing::Size(206, 26);
			this->result_2player->TabIndex = 34;
			// 
			// result_1player
			// 
			this->result_1player->Location = System::Drawing::Point(807, 331);
			this->result_1player->Name = L"result_1player";
			this->result_1player->ReadOnly = true;
			this->result_1player->Size = System::Drawing::Size(206, 26);
			this->result_1player->TabIndex = 95;
			// 
			// pl1s1s1
			// 
			this->pl1s1s1->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s1s1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s1s1->Location = System::Drawing::Point(203, 120);
			this->pl1s1s1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s1s1->Name = L"pl1s1s1";
			this->pl1s1s1->Size = System::Drawing::Size(36, 13);
			this->pl1s1s1->TabIndex = 37;
			this->pl1s1s1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s1s1
			// 
			this->pl2s1s1->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s1s1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s1s1->Location = System::Drawing::Point(261, 120);
			this->pl2s1s1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s1s1->Name = L"pl2s1s1";
			this->pl2s1s1->Size = System::Drawing::Size(36, 13);
			this->pl2s1s1->TabIndex = 39;
			this->pl2s1s1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s1s2
			// 
			this->pl1s1s2->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s1s2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s1s2->Location = System::Drawing::Point(203, 177);
			this->pl1s1s2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s1s2->Name = L"pl1s1s2";
			this->pl1s1s2->Size = System::Drawing::Size(36, 13);
			this->pl1s1s2->TabIndex = 49;
			this->pl1s1s2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s1s2
			// 
			this->pl2s1s2->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s1s2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s1s2->Location = System::Drawing::Point(261, 177);
			this->pl2s1s2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s1s2->Name = L"pl2s1s2";
			this->pl2s1s2->Size = System::Drawing::Size(36, 13);
			this->pl2s1s2->TabIndex = 51;
			this->pl2s1s2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s2s1
			// 
			this->pl2s2s1->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s2s1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s2s1->Location = System::Drawing::Point(400, 120);
			this->pl2s2s1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s2s1->Name = L"pl2s2s1";
			this->pl2s2s1->Size = System::Drawing::Size(36, 13);
			this->pl2s2s1->TabIndex = 70;
			this->pl2s2s1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s2s1
			// 
			this->pl1s2s1->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s2s1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s2s1->Location = System::Drawing::Point(342, 120);
			this->pl1s2s1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s2s1->Name = L"pl1s2s1";
			this->pl1s2s1->Size = System::Drawing::Size(36, 13);
			this->pl1s2s1->TabIndex = 68;
			this->pl1s2s1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s2s2
			// 
			this->pl2s2s2->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s2s2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s2s2->Location = System::Drawing::Point(400, 177);
			this->pl2s2s2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s2s2->Name = L"pl2s2s2";
			this->pl2s2s2->Size = System::Drawing::Size(36, 13);
			this->pl2s2s2->TabIndex = 76;
			this->pl2s2s2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s2s2
			// 
			this->pl1s2s2->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s2s2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s2s2->Location = System::Drawing::Point(342, 177);
			this->pl1s2s2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s2s2->Name = L"pl1s2s2";
			this->pl1s2s2->Size = System::Drawing::Size(36, 13);
			this->pl1s2s2->TabIndex = 74;
			this->pl1s2s2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s3s1
			// 
			this->pl2s3s1->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s3s1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s3s1->Location = System::Drawing::Point(539, 120);
			this->pl2s3s1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s3s1->Name = L"pl2s3s1";
			this->pl2s3s1->Size = System::Drawing::Size(36, 13);
			this->pl2s3s1->TabIndex = 82;
			this->pl2s3s1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s3s1
			// 
			this->pl1s3s1->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s3s1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s3s1->Location = System::Drawing::Point(481, 120);
			this->pl1s3s1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s3s1->Name = L"pl1s3s1";
			this->pl1s3s1->Size = System::Drawing::Size(36, 13);
			this->pl1s3s1->TabIndex = 80;
			this->pl1s3s1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s3s2
			// 
			this->pl2s3s2->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s3s2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s3s2->Location = System::Drawing::Point(539, 177);
			this->pl2s3s2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s3s2->Name = L"pl2s3s2";
			this->pl2s3s2->Size = System::Drawing::Size(36, 13);
			this->pl2s3s2->TabIndex = 88;
			this->pl2s3s2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s3s2
			// 
			this->pl1s3s2->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s3s2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s3s2->Location = System::Drawing::Point(481, 177);
			this->pl1s3s2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s3s2->Name = L"pl1s3s2";
			this->pl1s3s2->Size = System::Drawing::Size(36, 13);
			this->pl1s3s2->TabIndex = 86;
			this->pl1s3s2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s4s1
			// 
			this->pl2s4s1->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s4s1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s4s1->Location = System::Drawing::Point(678, 120);
			this->pl2s4s1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s4s1->Name = L"pl2s4s1";
			this->pl2s4s1->Size = System::Drawing::Size(36, 13);
			this->pl2s4s1->TabIndex = 104;
			this->pl2s4s1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s4s1
			// 
			this->pl1s4s1->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s4s1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s4s1->Location = System::Drawing::Point(620, 120);
			this->pl1s4s1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s4s1->Name = L"pl1s4s1";
			this->pl1s4s1->Size = System::Drawing::Size(36, 13);
			this->pl1s4s1->TabIndex = 102;
			this->pl1s4s1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s4s2
			// 
			this->pl2s4s2->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s4s2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s4s2->Location = System::Drawing::Point(678, 177);
			this->pl2s4s2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s4s2->Name = L"pl2s4s2";
			this->pl2s4s2->Size = System::Drawing::Size(36, 13);
			this->pl2s4s2->TabIndex = 110;
			this->pl2s4s2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s4s2
			// 
			this->pl1s4s2->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s4s2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s4s2->Location = System::Drawing::Point(620, 177);
			this->pl1s4s2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s4s2->Name = L"pl1s4s2";
			this->pl1s4s2->Size = System::Drawing::Size(36, 13);
			this->pl1s4s2->TabIndex = 108;
			this->pl1s4s2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s1s3
			// 
			this->pl2s1s3->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s1s3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s1s3->Location = System::Drawing::Point(261, 234);
			this->pl2s1s3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s1s3->Name = L"pl2s1s3";
			this->pl2s1s3->Size = System::Drawing::Size(36, 13);
			this->pl2s1s3->TabIndex = 116;
			this->pl2s1s3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s1s3
			// 
			this->pl1s1s3->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s1s3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s1s3->Location = System::Drawing::Point(203, 234);
			this->pl1s1s3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s1s3->Name = L"pl1s1s3";
			this->pl1s1s3->Size = System::Drawing::Size(36, 13);
			this->pl1s1s3->TabIndex = 114;
			this->pl1s1s3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s1s4
			// 
			this->pl2s1s4->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s1s4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s1s4->Location = System::Drawing::Point(261, 289);
			this->pl2s1s4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s1s4->Name = L"pl2s1s4";
			this->pl2s1s4->Size = System::Drawing::Size(36, 13);
			this->pl2s1s4->TabIndex = 122;
			this->pl2s1s4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s1s4
			// 
			this->pl1s1s4->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s1s4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s1s4->Location = System::Drawing::Point(203, 289);
			this->pl1s1s4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s1s4->Name = L"pl1s1s4";
			this->pl1s1s4->Size = System::Drawing::Size(36, 13);
			this->pl1s1s4->TabIndex = 120;
			this->pl1s1s4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s2s3
			// 
			this->pl2s2s3->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s2s3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s2s3->Location = System::Drawing::Point(400, 234);
			this->pl2s2s3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s2s3->Name = L"pl2s2s3";
			this->pl2s2s3->Size = System::Drawing::Size(36, 13);
			this->pl2s2s3->TabIndex = 128;
			this->pl2s2s3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s2s3
			// 
			this->pl1s2s3->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s2s3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s2s3->Location = System::Drawing::Point(342, 234);
			this->pl1s2s3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s2s3->Name = L"pl1s2s3";
			this->pl1s2s3->Size = System::Drawing::Size(36, 13);
			this->pl1s2s3->TabIndex = 126;
			this->pl1s2s3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s2s4
			// 
			this->pl2s2s4->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s2s4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s2s4->Location = System::Drawing::Point(400, 289);
			this->pl2s2s4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s2s4->Name = L"pl2s2s4";
			this->pl2s2s4->Size = System::Drawing::Size(36, 13);
			this->pl2s2s4->TabIndex = 134;
			this->pl2s2s4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s2s4
			// 
			this->pl1s2s4->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s2s4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s2s4->Location = System::Drawing::Point(342, 289);
			this->pl1s2s4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s2s4->Name = L"pl1s2s4";
			this->pl1s2s4->Size = System::Drawing::Size(36, 13);
			this->pl1s2s4->TabIndex = 132;
			this->pl1s2s4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s3s3
			// 
			this->pl2s3s3->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s3s3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s3s3->Location = System::Drawing::Point(539, 234);
			this->pl2s3s3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s3s3->Name = L"pl2s3s3";
			this->pl2s3s3->Size = System::Drawing::Size(36, 13);
			this->pl2s3s3->TabIndex = 140;
			this->pl2s3s3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s3s3
			// 
			this->pl1s3s3->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s3s3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s3s3->Location = System::Drawing::Point(481, 234);
			this->pl1s3s3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s3s3->Name = L"pl1s3s3";
			this->pl1s3s3->Size = System::Drawing::Size(36, 13);
			this->pl1s3s3->TabIndex = 138;
			this->pl1s3s3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s3s4
			// 
			this->pl2s3s4->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s3s4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s3s4->Location = System::Drawing::Point(539, 289);
			this->pl2s3s4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s3s4->Name = L"pl2s3s4";
			this->pl2s3s4->Size = System::Drawing::Size(36, 13);
			this->pl2s3s4->TabIndex = 146;
			this->pl2s3s4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s3s4
			// 
			this->pl1s3s4->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s3s4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s3s4->Location = System::Drawing::Point(481, 289);
			this->pl1s3s4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s3s4->Name = L"pl1s3s4";
			this->pl1s3s4->Size = System::Drawing::Size(36, 13);
			this->pl1s3s4->TabIndex = 144;
			this->pl1s3s4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s4s3
			// 
			this->pl2s4s3->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s4s3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s4s3->Location = System::Drawing::Point(678, 234);
			this->pl2s4s3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s4s3->Name = L"pl2s4s3";
			this->pl2s4s3->Size = System::Drawing::Size(36, 13);
			this->pl2s4s3->TabIndex = 152;
			this->pl2s4s3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s4s3
			// 
			this->pl1s4s3->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s4s3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s4s3->Location = System::Drawing::Point(620, 234);
			this->pl1s4s3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s4s3->Name = L"pl1s4s3";
			this->pl1s4s3->Size = System::Drawing::Size(36, 13);
			this->pl1s4s3->TabIndex = 150;
			this->pl1s4s3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl2s4s4
			// 
			this->pl2s4s4->BackColor = System::Drawing::SystemColors::Window;
			this->pl2s4s4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl2s4s4->Location = System::Drawing::Point(678, 289);
			this->pl2s4s4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl2s4s4->Name = L"pl2s4s4";
			this->pl2s4s4->Size = System::Drawing::Size(36, 13);
			this->pl2s4s4->TabIndex = 158;
			this->pl2s4s4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pl1s4s4
			// 
			this->pl1s4s4->BackColor = System::Drawing::SystemColors::Window;
			this->pl1s4s4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pl1s4s4->Location = System::Drawing::Point(620, 289);
			this->pl1s4s4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pl1s4s4->Name = L"pl1s4s4";
			this->pl1s4s4->Size = System::Drawing::Size(36, 13);
			this->pl1s4s4->TabIndex = 156;
			this->pl1s4s4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"2", L"3", L"4" });
			this->comboBox2->Location = System::Drawing::Point(895, 143);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(78, 28);
			this->comboBox2->TabIndex = 100;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"2", L"3", L"4" });
			this->comboBox1->Location = System::Drawing::Point(896, 104);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(77, 28);
			this->comboBox1->TabIndex = 99;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1031, 450);
			this->Controls->Add(this->info);
			this->Controls->Add(this->description);
			this->Controls->Add(this->player2_conf);
			this->Controls->Add(this->player1_conf);
			this->Controls->Add(this->result_player1);
			this->Controls->Add(this->result_1player);
			this->Controls->Add(this->result_player2);
			this->Controls->Add(this->result_2player);
			this->Controls->Add(this->configure);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->result);
			this->Controls->Add(this->configFrame);
			this->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::SystemColors::Control;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Nash Equilibrium";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->configFrame))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames1s1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames1s2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames2s1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames2s2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames3s1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames4s1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames4s2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames1s3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames1s4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames2s3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames2s4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames3s3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames3s4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames4s3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames4s4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frames3s2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void reset_button_Click(System::Object^ sender, System::EventArgs^ e) {
		pl1s1s1->Text = L"";
		pl1s1s2->Text = L"";
		pl1s1s3->Text = L"";
		pl1s1s4->Text = L"";

		pl1s2s1->Text = L"";
		pl1s2s2->Text = L"";
		pl1s2s3->Text = L"";
		pl1s2s4->Text = L"";
		
		pl1s3s1->Text = L"";
		pl1s3s2->Text = L"";
		pl1s3s3->Text = L"";
		pl1s3s4->Text = L"";

		pl1s4s1->Text = L"";
		pl1s4s2->Text = L"";
		pl1s4s3->Text = L"";
		pl1s4s4->Text = L"";
		
		pl2s1s1->Text = L"";
		pl2s1s2->Text = L"";
		pl2s1s3->Text = L"";
		pl2s1s4->Text = L"";
		
		pl2s2s1->Text = L"";
		pl2s2s2->Text = L"";
		pl2s2s3->Text = L"";
		pl2s2s4->Text = L"";
		
		pl2s3s1->Text = L"";
		pl2s3s2->Text = L"";
		pl2s3s3->Text = L"";
		pl2s3s4->Text = L"";

		pl2s4s1->Text = L"";
		pl2s4s2->Text = L"";
		pl2s4s3->Text = L"";
		pl2s4s4->Text = L"";

		result_1player->Text = L"";
		result_2player->Text = L"";
	}

	private: System::Void calc_button_Click(System::Object^ sender, System::EventArgs^ e) {
		
		PyObject* pName, * pModule, * pFunc, * pArgs, * pValue;
		pName = PyUnicode_FromString((char*)"calculation");
		pModule = PyImport_Import(pName);
		pFunc = PyObject_GetAttrString(pModule, (char*)"calc");
		pArgs = PyTuple_Pack(12,
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s1s1->Text)),
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s1s2->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s2s1->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s2s2->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s3s1->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl1s3s2->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s1s1->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s1s2->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s2s1->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s2s2->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s3s1->Text)), 
			PyFloat_FromDouble((double)System::Convert::ToDouble(pl2s3s2->Text)));
		pValue = PyObject_CallObject(pFunc, pArgs);
		std::string res = _PyUnicode_AsString(pValue);
		auto iter = res.find("],");
		auto iter2 = res.find("]]"); 
		res.replace(iter2, iter2 + 1, "]");

		std::string res_1_player = res.substr(1, iter);
		std::string res_2_player = res.substr(iter + 2);
		String^ res1_player = gcnew String(res_1_player.c_str());
		String^ res2_player = gcnew String(res_2_player.c_str());
		result_1player->Text = res1_player;
		result_2player->Text = res2_player;
		pl1s1s1;
	}

private: System::Void configure_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Controls->Clear();
	
	this->Controls->Add(this->description);
	this->Controls->Add(this->player2_conf);
	this->Controls->Add(this->player1_conf);
	this->Controls->Add(this->result_player1);
	this->Controls->Add(this->result_1player);
	this->Controls->Add(this->result_player2);
	this->Controls->Add(this->result_2player);
	this->Controls->Add(this->configure);
	this->Controls->Add(this->comboBox2);
	this->Controls->Add(this->calc_button);
	this->Controls->Add(this->comboBox1);
	this->Controls->Add(this->reset_button);
	this->Controls->Add(this->result);
	this->Controls->Add(this->player2);
	this->Controls->Add(this->player1);
	this->Controls->Add(this->configFrame);

	switch (comboBox1->SelectedIndex)
	{
	case 0:
		switch (comboBox2->SelectedIndex)
		{
		case 0: // matrix 2x2
			// gainings
			this->Controls->Add(this->pl1s1s1);
			this->Controls->Add(this->pl2s1s1);
			this->Controls->Add(this->stick1s1s1);
			this->Controls->Add(this->stick2s1s1);

			this->Controls->Add(this->pl1s2s1);
			this->Controls->Add(this->pl2s2s1);
			this->Controls->Add(this->stick1s2s1);
			this->Controls->Add(this->stick2s2s1);

			this->Controls->Add(this->pl1s1s2);
			this->Controls->Add(this->pl2s1s2);
			this->Controls->Add(this->stick1s1s2);
			this->Controls->Add(this->stick2s1s2);

			this->Controls->Add(this->pl1s2s2);
			this->Controls->Add(this->pl2s2s2);
			this->Controls->Add(this->stick1s2s2);
			this->Controls->Add(this->stick2s2s2);

			// strategies
			this->Controls->Add(this->player1s1);
			this->Controls->Add(this->player1s2);
			this->Controls->Add(this->player2s1);
			this->Controls->Add(this->player2s2);

			// semicolons
			this->Controls->Add(this->semicolons1s1);
			this->Controls->Add(this->semicolons1s2);
			this->Controls->Add(this->semicolons2s1);
			this->Controls->Add(this->semicolons2s2);

			// frames
			this->Controls->Add(this->frames1s1);
			this->Controls->Add(this->frames1s2);
			this->Controls->Add(this->frames2s1);
			this->Controls->Add(this->frames2s2);

			break;
		case 1: // matrix 2x3
			// gainings
			this->Controls->Add(this->pl1s1s1);
			this->Controls->Add(this->pl2s1s1);
			this->Controls->Add(this->stick1s1s1);
			this->Controls->Add(this->stick2s1s1);

			this->Controls->Add(this->pl1s2s1);
			this->Controls->Add(this->pl2s2s1);
			this->Controls->Add(this->stick1s2s1);
			this->Controls->Add(this->stick2s2s1);

			this->Controls->Add(this->pl1s1s2);
			this->Controls->Add(this->pl2s1s2);
			this->Controls->Add(this->stick1s1s2);
			this->Controls->Add(this->stick2s1s2);

			this->Controls->Add(this->pl1s2s2);
			this->Controls->Add(this->pl2s2s2);
			this->Controls->Add(this->stick1s2s2);
			this->Controls->Add(this->stick2s2s2);

			this->Controls->Add(this->pl1s1s3);
			this->Controls->Add(this->pl2s1s3);
			this->Controls->Add(this->stick1s1s3);
			this->Controls->Add(this->stick2s1s3);

			this->Controls->Add(this->pl1s2s3);
			this->Controls->Add(this->pl2s2s3);
			this->Controls->Add(this->stick1s2s3);
			this->Controls->Add(this->stick2s2s3);

			// strategies
			this->Controls->Add(this->player1s1);
			this->Controls->Add(this->player1s2);
			this->Controls->Add(this->player2s1);
			this->Controls->Add(this->player2s2);
			this->Controls->Add(this->player2s3);

			// semicolons
			this->Controls->Add(this->semicolons1s1);
			this->Controls->Add(this->semicolons1s2);
			this->Controls->Add(this->semicolons1s3);
			this->Controls->Add(this->semicolons2s1);
			this->Controls->Add(this->semicolons2s2);
			this->Controls->Add(this->semicolons2s3);

			// frames
			this->Controls->Add(this->frames1s1);
			this->Controls->Add(this->frames1s2);
			this->Controls->Add(this->frames1s3);
			this->Controls->Add(this->frames2s1);
			this->Controls->Add(this->frames2s2);
			this->Controls->Add(this->frames2s3);

			break;
		case 2: // matrix 2x4
			// gainings
			this->Controls->Add(this->pl1s1s1);
			this->Controls->Add(this->pl2s1s1);
			this->Controls->Add(this->stick1s1s1);
			this->Controls->Add(this->stick2s1s1);

			this->Controls->Add(this->pl1s2s1);
			this->Controls->Add(this->pl2s2s1);
			this->Controls->Add(this->stick1s2s1);
			this->Controls->Add(this->stick2s2s1);

			this->Controls->Add(this->pl1s1s2);
			this->Controls->Add(this->pl2s1s2);
			this->Controls->Add(this->stick1s1s2);
			this->Controls->Add(this->stick2s1s2);

			this->Controls->Add(this->pl1s2s2);
			this->Controls->Add(this->pl2s2s2);
			this->Controls->Add(this->stick1s2s2);
			this->Controls->Add(this->stick2s2s2);

			this->Controls->Add(this->pl1s1s3);
			this->Controls->Add(this->pl2s1s3);
			this->Controls->Add(this->stick1s1s3);
			this->Controls->Add(this->stick2s1s3);

			this->Controls->Add(this->pl1s2s3);
			this->Controls->Add(this->pl2s2s3);
			this->Controls->Add(this->stick1s2s3);
			this->Controls->Add(this->stick2s2s3);

			this->Controls->Add(this->pl1s1s4);
			this->Controls->Add(this->pl2s1s4);
			this->Controls->Add(this->stick1s1s4);
			this->Controls->Add(this->stick2s1s4);

			this->Controls->Add(this->pl1s2s4);
			this->Controls->Add(this->pl2s2s4);
			this->Controls->Add(this->stick1s2s4);
			this->Controls->Add(this->stick2s2s4);

			// strategies
			this->Controls->Add(this->player1s1);
			this->Controls->Add(this->player1s2);
			this->Controls->Add(this->player2s1);
			this->Controls->Add(this->player2s2);
			this->Controls->Add(this->player2s3);
			this->Controls->Add(this->player2s4);

			// semicolons
			this->Controls->Add(this->semicolons1s1);
			this->Controls->Add(this->semicolons1s2);
			this->Controls->Add(this->semicolons1s3);
			this->Controls->Add(this->semicolons1s4);
			this->Controls->Add(this->semicolons2s1);
			this->Controls->Add(this->semicolons2s2);
			this->Controls->Add(this->semicolons2s3);
			this->Controls->Add(this->semicolons2s4);

			// frames
			this->Controls->Add(this->frames1s1);
			this->Controls->Add(this->frames1s2);
			this->Controls->Add(this->frames1s3);
			this->Controls->Add(this->frames1s4);
			this->Controls->Add(this->frames2s1);
			this->Controls->Add(this->frames2s2);
			this->Controls->Add(this->frames2s3);
			this->Controls->Add(this->frames2s4);

			break;
		}
		break;
	case 1:
		switch (comboBox2->SelectedIndex)
		{
		case 0: // matrix 3x2
			// gainings
			this->Controls->Add(this->pl1s1s1);
			this->Controls->Add(this->pl2s1s1);
			this->Controls->Add(this->stick1s1s1);
			this->Controls->Add(this->stick2s1s1);

			this->Controls->Add(this->pl1s2s1);
			this->Controls->Add(this->pl2s2s1);
			this->Controls->Add(this->stick1s2s1);
			this->Controls->Add(this->stick2s2s1);

			this->Controls->Add(this->pl1s3s1);
			this->Controls->Add(this->pl2s3s1);
			this->Controls->Add(this->stick1s3s1);
			this->Controls->Add(this->stick2s3s1);

			this->Controls->Add(this->pl1s1s2);
			this->Controls->Add(this->pl2s1s2);
			this->Controls->Add(this->stick1s1s2);
			this->Controls->Add(this->stick2s1s2);

			this->Controls->Add(this->pl1s2s2);
			this->Controls->Add(this->pl2s2s2);
			this->Controls->Add(this->stick1s2s2);
			this->Controls->Add(this->stick2s2s2);

			this->Controls->Add(this->pl1s3s2);
			this->Controls->Add(this->pl2s3s2);
			this->Controls->Add(this->stick1s3s2);
			this->Controls->Add(this->stick2s3s2);

			// strategies
			this->Controls->Add(this->player1s1);
			this->Controls->Add(this->player1s2);
			this->Controls->Add(this->player1s3);
			this->Controls->Add(this->player2s1);
			this->Controls->Add(this->player2s2);

			// semicolons
			this->Controls->Add(this->semicolons1s1);
			this->Controls->Add(this->semicolons1s2);
			this->Controls->Add(this->semicolons2s1);
			this->Controls->Add(this->semicolons2s2);
			this->Controls->Add(this->semicolons3s1);
			this->Controls->Add(this->semicolons3s2);

			// frames
			this->Controls->Add(this->frames1s1);
			this->Controls->Add(this->frames1s2);
			this->Controls->Add(this->frames2s1);
			this->Controls->Add(this->frames2s2);
			this->Controls->Add(this->frames3s1);
			this->Controls->Add(this->frames3s2);

			break;
		case 1: // matrix 3x3
			// gainings
			this->Controls->Add(this->pl1s1s1);
			this->Controls->Add(this->pl2s1s1);
			this->Controls->Add(this->stick1s1s1);
			this->Controls->Add(this->stick2s1s1);

			this->Controls->Add(this->pl1s1s2);
			this->Controls->Add(this->pl2s1s2);
			this->Controls->Add(this->stick1s1s2);
			this->Controls->Add(this->stick2s1s2);

			this->Controls->Add(this->pl1s1s3);
			this->Controls->Add(this->pl2s1s3);
			this->Controls->Add(this->stick1s1s3);
			this->Controls->Add(this->stick2s1s3);

			this->Controls->Add(this->pl1s2s1);
			this->Controls->Add(this->pl2s2s1);
			this->Controls->Add(this->stick1s2s1);
			this->Controls->Add(this->stick2s2s1);

			this->Controls->Add(this->pl1s2s2);
			this->Controls->Add(this->pl2s2s2);
			this->Controls->Add(this->stick1s2s2);
			this->Controls->Add(this->stick2s2s2);

			this->Controls->Add(this->pl1s2s3);
			this->Controls->Add(this->pl2s2s3);
			this->Controls->Add(this->stick1s2s3);
			this->Controls->Add(this->stick2s2s3);

			this->Controls->Add(this->pl1s3s1);
			this->Controls->Add(this->pl2s3s1);
			this->Controls->Add(this->stick1s3s1);
			this->Controls->Add(this->stick2s3s1);

			this->Controls->Add(this->pl1s3s2);
			this->Controls->Add(this->pl2s3s2);
			this->Controls->Add(this->stick1s3s2);
			this->Controls->Add(this->stick2s3s2);

			this->Controls->Add(this->pl1s3s3);
			this->Controls->Add(this->pl2s3s3);
			this->Controls->Add(this->stick1s3s3);
			this->Controls->Add(this->stick2s3s3);

			// strategies
			this->Controls->Add(this->player1s1);
			this->Controls->Add(this->player1s2);
			this->Controls->Add(this->player1s3);
			this->Controls->Add(this->player2s1);
			this->Controls->Add(this->player2s2);
			this->Controls->Add(this->player2s3);

			// semicolons
			this->Controls->Add(this->semicolons1s1);
			this->Controls->Add(this->semicolons1s2);
			this->Controls->Add(this->semicolons1s3);
			this->Controls->Add(this->semicolons2s1);
			this->Controls->Add(this->semicolons2s2);
			this->Controls->Add(this->semicolons2s3);
			this->Controls->Add(this->semicolons3s1);
			this->Controls->Add(this->semicolons3s2);
			this->Controls->Add(this->semicolons3s3);

			// frames
			this->Controls->Add(this->frames1s1);
			this->Controls->Add(this->frames1s2);
			this->Controls->Add(this->frames1s3);
			this->Controls->Add(this->frames2s1);
			this->Controls->Add(this->frames2s2);
			this->Controls->Add(this->frames2s3);
			this->Controls->Add(this->frames3s1);
			this->Controls->Add(this->frames3s2);
			this->Controls->Add(this->frames3s3);

			break;
		case 2: // matrix 3x4
			// gainings
			this->Controls->Add(this->pl1s1s1);
			this->Controls->Add(this->pl2s1s1);
			this->Controls->Add(this->stick1s1s1);
			this->Controls->Add(this->stick2s1s1);

			this->Controls->Add(this->pl1s1s2);
			this->Controls->Add(this->pl2s1s2);
			this->Controls->Add(this->stick1s1s2);
			this->Controls->Add(this->stick2s1s2);

			this->Controls->Add(this->pl1s1s3);
			this->Controls->Add(this->pl2s1s3);
			this->Controls->Add(this->stick1s1s3);
			this->Controls->Add(this->stick2s1s3);

			this->Controls->Add(this->pl1s1s4);
			this->Controls->Add(this->pl2s1s4);
			this->Controls->Add(this->stick1s1s4);
			this->Controls->Add(this->stick2s1s4);

			this->Controls->Add(this->pl1s2s1);
			this->Controls->Add(this->pl2s2s1);
			this->Controls->Add(this->stick1s2s1);
			this->Controls->Add(this->stick2s2s1);

			this->Controls->Add(this->pl1s2s2);
			this->Controls->Add(this->pl2s2s2);
			this->Controls->Add(this->stick1s2s2);
			this->Controls->Add(this->stick2s2s2);

			this->Controls->Add(this->pl1s2s3);
			this->Controls->Add(this->pl2s2s3);
			this->Controls->Add(this->stick1s2s3);
			this->Controls->Add(this->stick2s2s3);

			this->Controls->Add(this->pl1s2s4);
			this->Controls->Add(this->pl2s2s4);
			this->Controls->Add(this->stick1s2s4);
			this->Controls->Add(this->stick2s2s4);

			this->Controls->Add(this->pl1s3s1);
			this->Controls->Add(this->pl2s3s1);
			this->Controls->Add(this->stick1s3s1);
			this->Controls->Add(this->stick2s3s1);

			this->Controls->Add(this->pl1s3s2);
			this->Controls->Add(this->pl2s3s2);
			this->Controls->Add(this->stick1s3s2);
			this->Controls->Add(this->stick2s3s2);

			this->Controls->Add(this->pl1s3s3);
			this->Controls->Add(this->pl2s3s3);
			this->Controls->Add(this->stick1s3s3);
			this->Controls->Add(this->stick2s3s3);

			this->Controls->Add(this->pl1s3s4);
			this->Controls->Add(this->pl2s3s4);
			this->Controls->Add(this->stick1s3s4);
			this->Controls->Add(this->stick2s3s4);

			// strategies
			this->Controls->Add(this->player1s1);
			this->Controls->Add(this->player1s2);
			this->Controls->Add(this->player1s3);
			this->Controls->Add(this->player2s1);
			this->Controls->Add(this->player2s2);
			this->Controls->Add(this->player2s3);
			this->Controls->Add(this->player2s4);

			// semicolons
			this->Controls->Add(this->semicolons1s1);
			this->Controls->Add(this->semicolons1s2);
			this->Controls->Add(this->semicolons1s3);
			this->Controls->Add(this->semicolons1s4);
			this->Controls->Add(this->semicolons2s1);
			this->Controls->Add(this->semicolons2s2);
			this->Controls->Add(this->semicolons2s3);
			this->Controls->Add(this->semicolons2s4);
			this->Controls->Add(this->semicolons3s1);
			this->Controls->Add(this->semicolons3s2);
			this->Controls->Add(this->semicolons3s3);
			this->Controls->Add(this->semicolons3s4);

			// frames
			this->Controls->Add(this->frames1s1);
			this->Controls->Add(this->frames1s2);
			this->Controls->Add(this->frames1s3);
			this->Controls->Add(this->frames1s4);
			this->Controls->Add(this->frames2s1);
			this->Controls->Add(this->frames2s2);
			this->Controls->Add(this->frames2s3);
			this->Controls->Add(this->frames2s4);
			this->Controls->Add(this->frames3s1);
			this->Controls->Add(this->frames3s2);
			this->Controls->Add(this->frames3s3);
			this->Controls->Add(this->frames3s4);

			break;
		}
		break;
	case 2:
		switch (comboBox2->SelectedIndex)
		{
		case 0: // matrix 4x2
			// gainings
			this->Controls->Add(this->pl1s1s1);
			this->Controls->Add(this->pl2s1s1);
			this->Controls->Add(this->stick1s1s1);
			this->Controls->Add(this->stick2s1s1);

			this->Controls->Add(this->pl1s2s1);
			this->Controls->Add(this->pl2s2s1);
			this->Controls->Add(this->stick1s2s1);
			this->Controls->Add(this->stick2s2s1);

			this->Controls->Add(this->pl1s3s1);
			this->Controls->Add(this->pl2s3s1);
			this->Controls->Add(this->stick1s3s1);
			this->Controls->Add(this->stick2s3s1);

			this->Controls->Add(this->pl1s4s1);
			this->Controls->Add(this->pl2s4s1);
			this->Controls->Add(this->stick1s4s1);
			this->Controls->Add(this->stick2s4s1);

			this->Controls->Add(this->pl1s1s2);
			this->Controls->Add(this->pl2s1s2);
			this->Controls->Add(this->stick1s1s2);
			this->Controls->Add(this->stick2s1s2);

			this->Controls->Add(this->pl1s2s2);
			this->Controls->Add(this->pl2s2s2);
			this->Controls->Add(this->stick1s2s2);
			this->Controls->Add(this->stick2s2s2);

			this->Controls->Add(this->pl1s3s2);
			this->Controls->Add(this->pl2s3s2);
			this->Controls->Add(this->stick1s3s2);
			this->Controls->Add(this->stick2s3s2);

			this->Controls->Add(this->pl1s4s2);
			this->Controls->Add(this->pl2s4s2);
			this->Controls->Add(this->stick1s4s2);
			this->Controls->Add(this->stick2s4s2);

			// strategies
			this->Controls->Add(this->player1s1);
			this->Controls->Add(this->player1s2);
			this->Controls->Add(this->player1s3);
			this->Controls->Add(this->player1s4);
			this->Controls->Add(this->player2s1);
			this->Controls->Add(this->player2s2);

			// semicolons
			this->Controls->Add(this->semicolons1s1);
			this->Controls->Add(this->semicolons1s2);
			this->Controls->Add(this->semicolons2s1);
			this->Controls->Add(this->semicolons2s2);
			this->Controls->Add(this->semicolons3s1);
			this->Controls->Add(this->semicolons3s2);
			this->Controls->Add(this->semicolons4s1);
			this->Controls->Add(this->semicolons4s2);

			// frames
			this->Controls->Add(this->frames1s1);
			this->Controls->Add(this->frames1s2);
			this->Controls->Add(this->frames2s1);
			this->Controls->Add(this->frames2s2);
			this->Controls->Add(this->frames3s1);
			this->Controls->Add(this->frames3s2);
			this->Controls->Add(this->frames4s1);
			this->Controls->Add(this->frames4s2);

			break;
		case 1: // matrix 4x3
			// gainings
			this->Controls->Add(this->pl1s1s1);
			this->Controls->Add(this->pl2s1s1);
			this->Controls->Add(this->stick1s1s1);
			this->Controls->Add(this->stick2s1s1);

			this->Controls->Add(this->pl1s2s1);
			this->Controls->Add(this->pl2s2s1);
			this->Controls->Add(this->stick1s2s1);
			this->Controls->Add(this->stick2s2s1);

			this->Controls->Add(this->pl1s3s1);
			this->Controls->Add(this->pl2s3s1);
			this->Controls->Add(this->stick1s3s1);
			this->Controls->Add(this->stick2s3s1);

			this->Controls->Add(this->pl1s4s1);
			this->Controls->Add(this->pl2s4s1);
			this->Controls->Add(this->stick1s4s1);
			this->Controls->Add(this->stick2s4s1);

			this->Controls->Add(this->pl1s1s2);
			this->Controls->Add(this->pl2s1s2);
			this->Controls->Add(this->stick1s1s2);
			this->Controls->Add(this->stick2s1s2);

			this->Controls->Add(this->pl1s2s2);
			this->Controls->Add(this->pl2s2s2);
			this->Controls->Add(this->stick1s2s2);
			this->Controls->Add(this->stick2s2s2);

			this->Controls->Add(this->pl1s3s2);
			this->Controls->Add(this->pl2s3s2);
			this->Controls->Add(this->stick1s3s2);
			this->Controls->Add(this->stick2s3s2);

			this->Controls->Add(this->pl1s4s2);
			this->Controls->Add(this->pl2s4s2);
			this->Controls->Add(this->stick1s4s2);
			this->Controls->Add(this->stick2s4s2);

			this->Controls->Add(this->pl1s1s3);
			this->Controls->Add(this->pl2s1s3);
			this->Controls->Add(this->stick1s1s3);
			this->Controls->Add(this->stick2s1s3);

			this->Controls->Add(this->pl1s2s3);
			this->Controls->Add(this->pl2s2s3);
			this->Controls->Add(this->stick1s2s3);
			this->Controls->Add(this->stick2s2s3);

			this->Controls->Add(this->pl1s3s3);
			this->Controls->Add(this->pl2s3s3);
			this->Controls->Add(this->stick1s3s3);
			this->Controls->Add(this->stick2s3s3);

			this->Controls->Add(this->pl1s4s3);
			this->Controls->Add(this->pl2s4s3);
			this->Controls->Add(this->stick1s4s3);
			this->Controls->Add(this->stick2s4s3);

			// strategies
			this->Controls->Add(this->player1s1);
			this->Controls->Add(this->player1s2);
			this->Controls->Add(this->player1s3);
			this->Controls->Add(this->player1s4);
			this->Controls->Add(this->player2s1);
			this->Controls->Add(this->player2s2);
			this->Controls->Add(this->player2s3);

			// semicolons
			this->Controls->Add(this->semicolons1s1);
			this->Controls->Add(this->semicolons1s2);
			this->Controls->Add(this->semicolons1s3);
			this->Controls->Add(this->semicolons2s1);
			this->Controls->Add(this->semicolons2s2);
			this->Controls->Add(this->semicolons2s3);
			this->Controls->Add(this->semicolons3s1);
			this->Controls->Add(this->semicolons3s2);
			this->Controls->Add(this->semicolons3s3);
			this->Controls->Add(this->semicolons4s1);
			this->Controls->Add(this->semicolons4s2);
			this->Controls->Add(this->semicolons4s3);

			// frames
			this->Controls->Add(this->frames1s1);
			this->Controls->Add(this->frames1s2);
			this->Controls->Add(this->frames1s3);
			this->Controls->Add(this->frames2s1);
			this->Controls->Add(this->frames2s2);
			this->Controls->Add(this->frames2s3);
			this->Controls->Add(this->frames3s1);
			this->Controls->Add(this->frames3s2);
			this->Controls->Add(this->frames3s3);
			this->Controls->Add(this->frames4s1);
			this->Controls->Add(this->frames4s2);
			this->Controls->Add(this->frames4s3);

			break;
		case 2: // matrix 4x4
			// gainings
			this->Controls->Add(this->pl1s1s1);
			this->Controls->Add(this->pl2s1s1);
			this->Controls->Add(this->stick1s1s1);
			this->Controls->Add(this->stick2s1s1);

			this->Controls->Add(this->pl1s2s1);
			this->Controls->Add(this->pl2s2s1);
			this->Controls->Add(this->stick1s2s1);
			this->Controls->Add(this->stick2s2s1);

			this->Controls->Add(this->pl1s3s1);
			this->Controls->Add(this->pl2s3s1);
			this->Controls->Add(this->stick1s3s1);
			this->Controls->Add(this->stick2s3s1);

			this->Controls->Add(this->pl1s4s1);
			this->Controls->Add(this->pl2s4s1);
			this->Controls->Add(this->stick1s4s1);
			this->Controls->Add(this->stick2s4s1);

			this->Controls->Add(this->pl1s1s2);
			this->Controls->Add(this->pl2s1s2);
			this->Controls->Add(this->stick1s1s2);
			this->Controls->Add(this->stick2s1s2);

			this->Controls->Add(this->pl1s2s2);
			this->Controls->Add(this->pl2s2s2);
			this->Controls->Add(this->stick1s2s2);
			this->Controls->Add(this->stick2s2s2);

			this->Controls->Add(this->pl1s3s2);
			this->Controls->Add(this->pl2s3s2);
			this->Controls->Add(this->stick1s3s2);
			this->Controls->Add(this->stick2s3s2);

			this->Controls->Add(this->pl1s4s2);
			this->Controls->Add(this->pl2s4s2);
			this->Controls->Add(this->stick1s4s2);
			this->Controls->Add(this->stick2s4s2);

			this->Controls->Add(this->pl1s1s3);
			this->Controls->Add(this->pl2s1s3);
			this->Controls->Add(this->stick1s1s3);
			this->Controls->Add(this->stick2s1s3);

			this->Controls->Add(this->pl1s2s3);
			this->Controls->Add(this->pl2s2s3);
			this->Controls->Add(this->stick1s2s3);
			this->Controls->Add(this->stick2s2s3);

			this->Controls->Add(this->pl1s3s3);
			this->Controls->Add(this->pl2s3s3);
			this->Controls->Add(this->stick1s3s3);
			this->Controls->Add(this->stick2s3s3);

			this->Controls->Add(this->pl1s4s3);
			this->Controls->Add(this->pl2s4s3);
			this->Controls->Add(this->stick1s4s3);
			this->Controls->Add(this->stick2s4s3);

			this->Controls->Add(this->pl1s1s4);
			this->Controls->Add(this->pl2s1s4);
			this->Controls->Add(this->stick1s1s4);
			this->Controls->Add(this->stick2s1s4);

			this->Controls->Add(this->pl1s2s4);
			this->Controls->Add(this->pl2s2s4);
			this->Controls->Add(this->stick1s2s4);
			this->Controls->Add(this->stick2s2s4);

			this->Controls->Add(this->pl1s3s4);
			this->Controls->Add(this->pl2s3s4);
			this->Controls->Add(this->stick1s3s4);
			this->Controls->Add(this->stick2s3s4);

			this->Controls->Add(this->pl1s4s4);
			this->Controls->Add(this->pl2s4s4);
			this->Controls->Add(this->stick1s4s4);
			this->Controls->Add(this->stick2s4s4);

			// strategies
			this->Controls->Add(this->player1s1);
			this->Controls->Add(this->player1s2);
			this->Controls->Add(this->player1s3);
			this->Controls->Add(this->player1s4);
			this->Controls->Add(this->player2s1);
			this->Controls->Add(this->player2s2);
			this->Controls->Add(this->player2s3);
			this->Controls->Add(this->player2s4);

			// semicolons
			this->Controls->Add(this->semicolons1s1);
			this->Controls->Add(this->semicolons1s2);
			this->Controls->Add(this->semicolons1s3);
			this->Controls->Add(this->semicolons1s4);
			this->Controls->Add(this->semicolons2s1);
			this->Controls->Add(this->semicolons2s2);
			this->Controls->Add(this->semicolons2s3);
			this->Controls->Add(this->semicolons2s4);
			this->Controls->Add(this->semicolons3s1);
			this->Controls->Add(this->semicolons3s2);
			this->Controls->Add(this->semicolons3s3);
			this->Controls->Add(this->semicolons3s4);
			this->Controls->Add(this->semicolons4s1);
			this->Controls->Add(this->semicolons4s2);
			this->Controls->Add(this->semicolons4s3);
			this->Controls->Add(this->semicolons4s4);

			// frames
			this->Controls->Add(this->frames1s1);
			this->Controls->Add(this->frames1s2);
			this->Controls->Add(this->frames1s3);
			this->Controls->Add(this->frames1s4);
			this->Controls->Add(this->frames2s1);
			this->Controls->Add(this->frames2s2);
			this->Controls->Add(this->frames2s3);
			this->Controls->Add(this->frames2s4);
			this->Controls->Add(this->frames3s1);
			this->Controls->Add(this->frames3s2);
			this->Controls->Add(this->frames3s3);
			this->Controls->Add(this->frames3s4);
			this->Controls->Add(this->frames4s1);
			this->Controls->Add(this->frames4s2);
			this->Controls->Add(this->frames4s3);
			this->Controls->Add(this->frames4s4);

			break;
		}
		break;
	}
}
};
};