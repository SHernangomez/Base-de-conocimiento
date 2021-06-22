/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentra la funci�n que equivale al bot�n del formulario
#include "Botones_Coleccion.h"

//Fichero de encabezamiento donde se encuentran las funciones b�sicas para el funcionamiento del programa
#include "Funciones.h"


//Declaraci�n variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern bson_error_t error;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//	Inclusi�n namespace std para poder utilizar variables de tipo string
	using namespace std;

	public ref class NuevaColeccion : public System::Windows::Forms::Form
	{
	public:
		NuevaColeccion(void)
		{
			InitializeComponent();
		}

	protected:
		~NuevaColeccion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Aviso_Base_Coleccion;
	private: System::Windows::Forms::Label^ Nombre_Base;
	private: System::Windows::Forms::Label^ Nombre_Coleccion;
	private: System::Windows::Forms::TextBox^ TextBox_Coleccion;
	private: System::Windows::Forms::Button^ Boton_A�adirColeccion;
	private: System::Windows::Forms::ComboBox^ Lista_Bases;

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->Aviso_Base_Coleccion = (gcnew System::Windows::Forms::Label());
			this->Nombre_Base = (gcnew System::Windows::Forms::Label());
			this->Nombre_Coleccion = (gcnew System::Windows::Forms::Label());
			this->TextBox_Coleccion = (gcnew System::Windows::Forms::TextBox());
			this->Boton_A�adirColeccion = (gcnew System::Windows::Forms::Button());
			this->Lista_Bases = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// Aviso_Base_Coleccion
			// 
			this->Aviso_Base_Coleccion->AutoSize = true;
			this->Aviso_Base_Coleccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Aviso_Base_Coleccion->Location = System::Drawing::Point(70, 23);
			this->Aviso_Base_Coleccion->Name = L"Aviso_Base_Coleccion";
			this->Aviso_Base_Coleccion->Size = System::Drawing::Size(351, 36);
			this->Aviso_Base_Coleccion->TabIndex = 0;
			this->Aviso_Base_Coleccion->Text = L"Escriba el nombre de la colecci�n que desea a�adir, \r\nas� como el de la base de d"
				L"atos a la que pertenece\r\n";
			this->Aviso_Base_Coleccion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Nombre_Base
			// 
			this->Nombre_Base->AutoSize = true;
			this->Nombre_Base->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nombre_Base->Location = System::Drawing::Point(69, 79);
			this->Nombre_Base->Name = L"Nombre_Base";
			this->Nombre_Base->Size = System::Drawing::Size(188, 20);
			this->Nombre_Base->TabIndex = 1;
			this->Nombre_Base->Text = L"Nombre base de datos:";
			this->Nombre_Base->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Nombre_Coleccion
			// 
			this->Nombre_Coleccion->AutoSize = true;
			this->Nombre_Coleccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nombre_Coleccion->Location = System::Drawing::Point(69, 127);
			this->Nombre_Coleccion->Name = L"Nombre_Coleccion";
			this->Nombre_Coleccion->Size = System::Drawing::Size(153, 20);
			this->Nombre_Coleccion->TabIndex = 2;
			this->Nombre_Coleccion->Text = L"Nombre colecci�n:";
			this->Nombre_Coleccion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TextBox_Coleccion
			// 
			this->TextBox_Coleccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TextBox_Coleccion->Location = System::Drawing::Point(268, 124);
			this->TextBox_Coleccion->Name = L"TextBox_Coleccion";
			this->TextBox_Coleccion->Size = System::Drawing::Size(163, 26);
			this->TextBox_Coleccion->TabIndex = 4;
			// 
			// Boton_A�adirColeccion
			// 
			this->Boton_A�adirColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_A�adirColeccion->Location = System::Drawing::Point(73, 173);
			this->Boton_A�adirColeccion->Name = L"Boton_A�adirColeccion";
			this->Boton_A�adirColeccion->Size = System::Drawing::Size(358, 50);
			this->Boton_A�adirColeccion->TabIndex = 5;
			this->Boton_A�adirColeccion->Text = L"A�adir colecci�n";
			this->Boton_A�adirColeccion->UseVisualStyleBackColor = true;
			this->Boton_A�adirColeccion->Click += gcnew System::EventHandler(this, &NuevaColeccion::Boton_A�adirColeccion_Click);
			// 
			// Lista_Bases
			// 
			this->Lista_Bases->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lista_Bases->FormattingEnabled = true;
			this->Lista_Bases->Location = System::Drawing::Point(268, 76);
			this->Lista_Bases->Name = L"Lista_Bases";
			this->Lista_Bases->Size = System::Drawing::Size(163, 28);
			this->Lista_Bases->TabIndex = 6;
			// 
			// NuevaColeccion
			// 
			this->AcceptButton = this->Boton_A�adirColeccion;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 261);
			this->Controls->Add(this->Lista_Bases);
			this->Controls->Add(this->Boton_A�adirColeccion);
			this->Controls->Add(this->TextBox_Coleccion);
			this->Controls->Add(this->Nombre_Coleccion);
			this->Controls->Add(this->Nombre_Base);
			this->Controls->Add(this->Aviso_Base_Coleccion);
			this->Name = L"NuevaColeccion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"A�ADIR COLECCI�N";
			this->Load += gcnew System::EventHandler(this, &NuevaColeccion::NuevaColeccion_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	//Carga nombres bases de datos disponibles en Lista_Bases (ComboBox)
		private: System::Void NuevaColeccion_Load(System::Object^ sender, System::EventArgs^ e) {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 0) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					Lista_Bases->Items->Add(Base);
				}
			}
		}


	//Bot�n A�adir Colecci�n (accept button)
		private: System::Void Boton_A�adirColeccion_Click(System::Object^ sender, System::EventArgs^ e) {
			//Almacenamiento del nombre insertado para la Base de Datos en la variable Base
			string Base;
			if (Lista_Bases->SelectedItem) {
				Base = toStandardString(Lista_Bases->SelectedItem->ToString());
			}
			else Base = toStandardString(Lista_Bases->Text);

			//Almacenamiento del nombre insertado para la colecci�n en la variable NuevaColeccion
			string NuevaColeccion = toStandardString(this->TextBox_Coleccion->Text);

			//Banderas para MessageBox
			int BaseExistente = ComprobacionExistenciaBase(Base);
			int BaseInherente = BaseInherenteMongoDB(Base);
			int ColeccionExistente = ColeccionPerteneceABase(Base, NuevaColeccion);

			//Funci�n equivalente al Bot�n A�adir Coleccion
			CrearColeccion(Base, NuevaColeccion);

			if (BaseExistente == 1) {
				if (BaseInherente == 0) {
					if (ColeccionExistente == 0) {
						MessageBox::Show("La colecci�n se ha a�adido correctamente.");
						this->Visible = false;
					}
					else MessageBox::Show("Ya existe una colecci�n con ese nombre en la base de datos introducida");
				}
				else MessageBox::Show("No se ha podido completar la operaci�n.La base de datos que est� intentando modificar es inherente a MongoDB.");
			}
			else MessageBox::Show("No existe ninguna base de datos que coincida con el nombre introducido");
		}


	};
}
