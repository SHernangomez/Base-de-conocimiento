/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez


//Inclusi�n de los ficheros de encabezamiento de los dem�s formularios para poder pasar de uno a otro en un click
#include "NuevoMultimedia.h"
#include "EliminarMultimedia.h"
#include "ConsultaMultimedia.h"
#include "NuevaRelacionMultimedia.h"


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Multimedia : public System::Windows::Forms::Form
	{
	public:
		Multimedia(void)
		{
			InitializeComponent();
		}

	protected:
		~Multimedia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Boton_A�adirMultimediaDocumento;
	protected:
	private: System::Windows::Forms::GroupBox^ GroupBox_BaseConocimiento;
	private: System::Windows::Forms::Button^ Boton_ConsultarMultimedia;
	private: System::Windows::Forms::Button^ Boton_EliminarMultimedia;
	private: System::Windows::Forms::Button^ Boton_A�adirMultimedia;

	private:

		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->Boton_A�adirMultimediaDocumento = (gcnew System::Windows::Forms::Button());
			this->GroupBox_BaseConocimiento = (gcnew System::Windows::Forms::GroupBox());
			this->Boton_ConsultarMultimedia = (gcnew System::Windows::Forms::Button());
			this->Boton_EliminarMultimedia = (gcnew System::Windows::Forms::Button());
			this->Boton_A�adirMultimedia = (gcnew System::Windows::Forms::Button());
			this->GroupBox_BaseConocimiento->SuspendLayout();
			this->SuspendLayout();
			// 
			// Boton_A�adirMultimediaDocumento
			// 
			this->Boton_A�adirMultimediaDocumento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_A�adirMultimediaDocumento->Location = System::Drawing::Point(29, 221);
			this->Boton_A�adirMultimediaDocumento->Name = L"Boton_A�adirMultimediaDocumento";
			this->Boton_A�adirMultimediaDocumento->Size = System::Drawing::Size(527, 50);
			this->Boton_A�adirMultimediaDocumento->TabIndex = 15;
			this->Boton_A�adirMultimediaDocumento->Text = L"A�adir archivo multimedia a documento";
			this->Boton_A�adirMultimediaDocumento->UseVisualStyleBackColor = true;
			this->Boton_A�adirMultimediaDocumento->Click += gcnew System::EventHandler(this, &Multimedia::Boton_A�adirMultimediaDocumento_Click);
			// 
			// GroupBox_BaseConocimiento
			// 
			this->GroupBox_BaseConocimiento->Controls->Add(this->Boton_ConsultarMultimedia);
			this->GroupBox_BaseConocimiento->Controls->Add(this->Boton_EliminarMultimedia);
			this->GroupBox_BaseConocimiento->Controls->Add(this->Boton_A�adirMultimedia);
			this->GroupBox_BaseConocimiento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->GroupBox_BaseConocimiento->Location = System::Drawing::Point(12, 21);
			this->GroupBox_BaseConocimiento->Name = L"GroupBox_BaseConocimiento";
			this->GroupBox_BaseConocimiento->Size = System::Drawing::Size(560, 180);
			this->GroupBox_BaseConocimiento->TabIndex = 16;
			this->GroupBox_BaseConocimiento->TabStop = false;
			this->GroupBox_BaseConocimiento->Text = L"Base de conocimiento";
			// 
			// Boton_ConsultarMultimedia
			// 
			this->Boton_ConsultarMultimedia->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_ConsultarMultimedia->Location = System::Drawing::Point(17, 112);
			this->Boton_ConsultarMultimedia->Name = L"Boton_ConsultarMultimedia";
			this->Boton_ConsultarMultimedia->Size = System::Drawing::Size(527, 50);
			this->Boton_ConsultarMultimedia->TabIndex = 17;
			this->Boton_ConsultarMultimedia->Text = L"Consultar archivo multimedia";
			this->Boton_ConsultarMultimedia->UseVisualStyleBackColor = true;
			this->Boton_ConsultarMultimedia->Click += gcnew System::EventHandler(this, &Multimedia::Boton_ConsultarMultimedia_Click);
			// 
			// Boton_EliminarMultimedia
			// 
			this->Boton_EliminarMultimedia->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_EliminarMultimedia->Location = System::Drawing::Point(289, 31);
			this->Boton_EliminarMultimedia->Name = L"Boton_EliminarMultimedia";
			this->Boton_EliminarMultimedia->Size = System::Drawing::Size(255, 50);
			this->Boton_EliminarMultimedia->TabIndex = 16;
			this->Boton_EliminarMultimedia->Text = L"Eliminar archivo multimedia";
			this->Boton_EliminarMultimedia->UseVisualStyleBackColor = true;
			this->Boton_EliminarMultimedia->Click += gcnew System::EventHandler(this, &Multimedia::Boton_EliminarMultimedia_Click);
			// 
			// Boton_A�adirMultimedia
			// 
			this->Boton_A�adirMultimedia->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_A�adirMultimedia->Location = System::Drawing::Point(17, 31);
			this->Boton_A�adirMultimedia->Name = L"Boton_A�adirMultimedia";
			this->Boton_A�adirMultimedia->Size = System::Drawing::Size(255, 50);
			this->Boton_A�adirMultimedia->TabIndex = 15;
			this->Boton_A�adirMultimedia->Text = L"A�adir archivo multimedia";
			this->Boton_A�adirMultimedia->UseVisualStyleBackColor = true;
			this->Boton_A�adirMultimedia->Click += gcnew System::EventHandler(this, &Multimedia::Boton_A�adirMultimedia_Click);
			// 
			// Multimedia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 291);
			this->Controls->Add(this->GroupBox_BaseConocimiento);
			this->Controls->Add(this->Boton_A�adirMultimediaDocumento);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"Multimedia";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ARCHIVOS MULTIMEDIA";
			this->GroupBox_BaseConocimiento->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


	//Bot�n A�adir multimedia
		private: System::Void Boton_A�adirMultimedia_Click(System::Object^ sender, System::EventArgs^ e) {
			//Sintaxis para pasar en un click de Multimedia a NuevoMultimedia
			BaseConocimiento::NuevoMultimedia^ NuevoMultimedia = gcnew BaseConocimiento::NuevoMultimedia();
			this->Visible = false;
			NuevoMultimedia->ShowDialog();
			this->Visible = true;
		}

		
		//Bot�n Elimianr multimedia
		private: System::Void Boton_EliminarMultimedia_Click(System::Object^ sender, System::EventArgs^ e) {
			//Sintaxis para pasar en un click de Multimedia a EliminarMultimedia
			BaseConocimiento::EliminarMultimedia^ EliminarMultimedia = gcnew BaseConocimiento::EliminarMultimedia();
			this->Visible = false;
			EliminarMultimedia->ShowDialog();
			this->Visible = true;
		}


	//Bot�n Consultar multimedia
		private: System::Void Boton_ConsultarMultimedia_Click(System::Object^ sender, System::EventArgs^ e) {
			//Sintaxis para pasar en un click de Multimedia a ConsultaMultimedia
			BaseConocimiento::ConsultaMultimedia^ ConsultaMultimedia = gcnew BaseConocimiento::ConsultaMultimedia();
			this->Visible = false;
			ConsultaMultimedia->ShowDialog();
			this->Visible = true;
		}


	//Bot�n A�adir archivo multimedia a documento
		private: System::Void Boton_A�adirMultimediaDocumento_Click(System::Object^ sender, System::EventArgs^ e) {
			//Sintaxis para pasar en un click de Multimedia a NuevaRelacionMultimedia
			BaseConocimiento::NuevaRelacionMultimedia^ NuevaRelacionMultimedia = gcnew BaseConocimiento::NuevaRelacionMultimedia();
			this->Visible = false;
			NuevaRelacionMultimedia->ShowDialog();
			this->Visible = true;
		}
};
}
