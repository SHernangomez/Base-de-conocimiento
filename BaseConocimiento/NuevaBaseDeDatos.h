/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentra la función que equivale al botón del formulario
#include "Botones_BaseDeDatos.h"

//Fichero de encabezamiento donde se encuentran las funciones básicas para el funcionamiento del programa
#include "Funciones.h"


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//	Inclusión namespace std para poder utilizar variables de tipo string
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
	private: System::Windows::Forms::Button^ Boton_Añadir;

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
			this->Boton_Añadir = (gcnew System::Windows::Forms::Button());
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
			this->Aviso_Base_Coleccion->Text = L"Para añadir una base de datos al servidor MongoDB, \r\nesta debe contener al menos "
				L"una colección";
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
			this->Nombre_Coleccion->Text = L"Nombre colección:";
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
			// Boton_Añadir
			// 
			this->Boton_Añadir->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_Añadir->Location = System::Drawing::Point(74, 189);
			this->Boton_Añadir->Name = L"Boton_Añadir";
			this->Boton_Añadir->Size = System::Drawing::Size(349, 50);
			this->Boton_Añadir->TabIndex = 5;
			this->Boton_Añadir->Text = L"Añadir base de datos";
			this->Boton_Añadir->UseVisualStyleBackColor = true;
			this->Boton_Añadir->Click += gcnew System::EventHandler(this, &NuevaBaseDeDatos::Boton_Añadir_Click);
			// 
			// NuevaBaseDeDatos
			// 
			this->AcceptButton = this->Boton_Añadir;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 261);
			this->Controls->Add(this->Boton_Añadir);
			this->Controls->Add(this->TextBox_Coleccion);
			this->Controls->Add(this->TextBox_Base);
			this->Controls->Add(this->Nombre_Coleccion);
			this->Controls->Add(this->Nombre_Base);
			this->Controls->Add(this->Aviso_Base_Coleccion);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"NuevaBaseDeDatos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AÑADIR BASE DE DATOS";
			this->Load += gcnew System::EventHandler(this, &NuevaBaseDeDatos::NuevaBaseDeDatos_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	//	Botón Añadir Base de Datos (accept button)
		private: System::Void Boton_Añadir_Click(System::Object^ sender, System::EventArgs^ e) {
			//Almacenamiento del nombre insertado para la Base de Datos en la variable NuevaBase
			string NuevaBase = toStandardString(this->TextBox_Base->Text);
			//Almacenamiento del nombre insertado para la colección en la variable NuevaColeccion
			string NuevaColeccion = toStandardString(this->TextBox_Coleccion->Text);

			//Bandera para MessageBox
			int BaseExistente = ComprobacionExistenciaBase(NuevaBase);	
			
			//Función equivalente al Botón Añadir Base de Datos
			CrearBaseDeDatos(NuevaBase, NuevaColeccion);

			if (BaseExistente == 0) {
				MessageBox::Show("La base de datos se ha añadido correctamente");
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
