/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentra la funci�n que equivale al bot�n del formulario
#include "Botones_BaseDeDatos.h"

//Fichero de encabezamiento donde se encuentran las funciones b�sicas para el funcionamiento del programa
#include "Funciones.h"


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//	Inclusi�n namespace std para poder utilizar variables de tipo string
	using namespace std;

	public ref class NuevaBaseDeDatos : public System::Windows::Forms::Form
	{
	public:
		NuevaBaseDeDatos(void)
		{
			InitializeComponent();
		}

	protected:
		~NuevaBaseDeDatos()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ Aviso_Base_Coleccion;
	private: System::Windows::Forms::Label^ Nombre_Base;
	private: System::Windows::Forms::Label^ Nombre_Coleccion;
	private: System::Windows::Forms::TextBox^ TextBox_Base;
	private: System::Windows::Forms::TextBox^ TextBox_Coleccion;
	private: System::Windows::Forms::Button^ Boton_A�adir;

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->Aviso_Base_Coleccion = (gcnew System::Windows::Forms::Label());
			this->Nombre_Base = (gcnew System::Windows::Forms::Label());
			this->Nombre_Coleccion = (gcnew System::Windows::Forms::Label());
			this->TextBox_Base = (gcnew System::Windows::Forms::TextBox());
			this->TextBox_Coleccion = (gcnew System::Windows::Forms::TextBox());
			this->Boton_A�adir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Aviso_Base_Coleccion
			// 
			this->Aviso_Base_Coleccion->AutoSize = true;
			this->Aviso_Base_Coleccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Aviso_Base_Coleccion->Location = System::Drawing::Point(71, 23);
			this->Aviso_Base_Coleccion->Name = L"Aviso_Base_Coleccion";
			this->Aviso_Base_Coleccion->Size = System::Drawing::Size(352, 36);
			this->Aviso_Base_Coleccion->TabIndex = 0;
			this->Aviso_Base_Coleccion->Text = L"Para a�adir una base de datos al servidor MongoDB, \r\nesta debe contener al menos "
				L"una colecci�n";
			this->Aviso_Base_Coleccion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Nombre_Base
			// 
			this->Nombre_Base->AutoSize = true;
			this->Nombre_Base->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nombre_Base->Location = System::Drawing::Point(70, 89);
			this->Nombre_Base->Name = L"Nombre_Base";
			this->Nombre_Base->Size = System::Drawing::Size(178, 19);
			this->Nombre_Base->TabIndex = 1;
			this->Nombre_Base->Text = L"Nombre base de datos:";
			// 
			// Nombre_Coleccion
			// 
			this->Nombre_Coleccion->AutoSize = true;
			this->Nombre_Coleccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nombre_Coleccion->Location = System::Drawing::Point(70, 140);
			this->Nombre_Coleccion->Name = L"Nombre_Coleccion";
			this->Nombre_Coleccion->Size = System::Drawing::Size(145, 19);
			this->Nombre_Coleccion->TabIndex = 2;
			this->Nombre_Coleccion->Text = L"Nombre colecci�n:";
			// 
			// TextBox_Base
			// 
			this->TextBox_Base->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TextBox_Base->Location = System::Drawing::Point(260, 83);
			this->TextBox_Base->Name = L"TextBox_Base";
			this->TextBox_Base->Size = System::Drawing::Size(163, 25);
			this->TextBox_Base->TabIndex = 3;
			// 
			// TextBox_Coleccion
			// 
			this->TextBox_Coleccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TextBox_Coleccion->Location = System::Drawing::Point(260, 137);
			this->TextBox_Coleccion->Name = L"TextBox_Coleccion";
			this->TextBox_Coleccion->Size = System::Drawing::Size(163, 25);
			this->TextBox_Coleccion->TabIndex = 4;
			// 
			// Boton_A�adir
			// 
			this->Boton_A�adir->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_A�adir->Location = System::Drawing::Point(74, 189);
			this->Boton_A�adir->Name = L"Boton_A�adir";
			this->Boton_A�adir->Size = System::Drawing::Size(349, 50);
			this->Boton_A�adir->TabIndex = 5;
			this->Boton_A�adir->Text = L"A�adir base de datos";
			this->Boton_A�adir->UseVisualStyleBackColor = true;
			this->Boton_A�adir->Click += gcnew System::EventHandler(this, &NuevaBaseDeDatos::Boton_A�adir_Click);
			// 
			// NuevaBaseDeDatos
			// 
			this->AcceptButton = this->Boton_A�adir;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 261);
			this->Controls->Add(this->Boton_A�adir);
			this->Controls->Add(this->TextBox_Coleccion);
			this->Controls->Add(this->TextBox_Base);
			this->Controls->Add(this->Nombre_Coleccion);
			this->Controls->Add(this->Nombre_Base);
			this->Controls->Add(this->Aviso_Base_Coleccion);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"NuevaBaseDeDatos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"A�ADIR BASE DE DATOS";
			this->Load += gcnew System::EventHandler(this, &NuevaBaseDeDatos::NuevaBaseDeDatos_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	//	Bot�n A�adir Base de Datos (accept button)
		private: System::Void Boton_A�adir_Click(System::Object^ sender, System::EventArgs^ e) {
			//Almacenamiento del nombre insertado para la Base de Datos en la variable NuevaBase
			string NuevaBase = toStandardString(this->TextBox_Base->Text);
			//Almacenamiento del nombre insertado para la colecci�n en la variable NuevaColeccion
			string NuevaColeccion = toStandardString(this->TextBox_Coleccion->Text);

			//Bandera para MessageBox
			int BaseExistente = ComprobacionExistenciaBase(NuevaBase);	
			
			//Funci�n equivalente al Bot�n A�adir Base de Datos
			CrearBaseDeDatos(NuevaBase, NuevaColeccion);

			if (BaseExistente == 0) {
				MessageBox::Show("La base de datos se ha a�adido correctamente");
				this->Visible = false;
			}
			else {
				MessageBox::Show("Ya existe una base de datos con el nombre introducido");
				this->TextBox_Base->Text = "";
				this->TextBox_Coleccion->Text = "";
			}
		}
		
		
private: System::Void NuevaBaseDeDatos_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
