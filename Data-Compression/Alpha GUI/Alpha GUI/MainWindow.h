#pragma once
#include <fstream>
#include <string>
#include "DataCompression.h"
#include <msclr\marshal_cppstd.h>
using namespace std;


namespace AlphaGUI {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  fileDialog;
	protected: 

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->fileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// fileDialog
			// 
			this->fileDialog->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(28, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(601, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(644, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Test";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click_1);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(994, 122);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
<<<<<<< HEAD
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e)
	{
		 this->openFileDialog1->ShowDialog();
		 String^ path = this->openFileDialog1->FileName;
		 textBox1->Text = path;
		 string ox = "";
		 for (int i = 0; i < textBox1->TextLength; i++) {
			 ox += textBox1->Text[i];
		 }

		 textBox1->Clear();
	}


=======
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) 
			 {
				 //fileDialog->ShowDialog();
				 //textBox1->Text = fileDialog->FileName;

				 //array<System::Byte,1> t =  IO::File::ReadAllBytes( fileDialog->FileName ); 
					
				 ofstream f ("text.txt");

				 //f << MLZW("eu acum ma duc la masa");
				 
				  fileDialog->ShowDialog();
				  
				  String ^ str = fileDialog->FileName;

				  ifstream g( msclr::interop::marshal_as<std::string>(str) );

				  char c;


					string tot;

					g >> tot;

					f << MLZW(tot);
				  

				  //arr[0] = stream->ReadByte();



				  /*String ^ car = System::Convert::ToBase64String(arr,0,10);
				  std::string unmanaged = msclr::interop::marshal_as<std::string>(car);
				  f << MLZW(unmanaged);*/
			 };
>>>>>>> origin/NewGui
	};
}
