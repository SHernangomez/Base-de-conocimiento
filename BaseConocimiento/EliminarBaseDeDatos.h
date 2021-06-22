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
#include "Funciones_MongoDB.h"


//Declaración variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern bson_error_t error;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//	Inclusión namespace std para poder utilizar variables de tipo string
	using namespace std;

	public ref class EliminarBaseDeDatos : public System::Windows::Forms::Form
	{
	public:
		EliminarBaseDeDatos(void)
		{
			InitializeComponent();
		}

	protected:
		~EliminarBaseDeDatos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Nombre_Base_A_Eliminar;
	private: System::Windows::Forms::Button^ Boton_Eliminar;
	private: System::Windows::Forms::Label^ Titulo;
	private: System::Windows::Forms::ComboBox^ Lista_Bases;

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->Nombre_Base_A_Eliminar = (gcnew System::Windows::Forms::Label());
			this->Boton_Eliminar = (gcnew System::Windows::Forms::Button());
			this->Titulo = (gcnew System::Windows::Forms::Label());
			this->Lista_Bases = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// Nombre_Base_A_Eliminar
			// 
			this->Nombre_Base_A_Eliminar->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Nombre_Base_A_Eliminar->Location = System::Drawing::Point(-44, 78);
			this->Nombre_Base_A_Eliminar->Name = L"Nombre_Base_A_Eliminar";
			this->Nombre_Base_A_Eliminar->Size = System::Drawing::Size(250, 26);
			this->Nombre_Base_A_Eliminar->TabIndex = 0;
			this->Nombre_Base_A_Eliminar->Text = L"Nombre:";
			this->Nombre_Base_A_Eliminar->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Boton_Eliminar
			// 
			this->Boton_Eliminar->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_Eliminar->Location = System::Drawing::Point(49, 125);
			this->Boton_Eliminar->Name = L"Boton_Eliminar";
			this->Boton_Eliminar->Size = System::Drawing::Size(381, 50);
			this->Boton_Eliminar->TabIndex = 2;
			this->Boton_Eliminar->Text = L"Eliminar";
			this->Boton_Eliminar->UseVisualStyleBackColor = true;
			this->Boton_Eliminar->Click += gcnew System::EventHandler(this, &EliminarBaseDeDatos::Boton_Eliminar_Click);
			// 
			// Titulo
			// 
			this->Titulo->AutoSize = true;
			this->Titulo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titulo->Location = System::Drawing::Point(46, 36);
			this->Titulo->Name = L"Titulo";
			this->Titulo->Size = System::Drawing::Size(384, 18);
			this->Titulo->TabIndex = 3;
			this->Titulo->Text = L"Escriba el nombre de la base de datos que desea eliminar";
			// 
			// Lista_Bases
			// 
			this->Lista_Bases->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lista_Bases->FormattingEnabled = true;
			this->Lista_Bases->Location = System::Drawing::Point(141, 78);
			this->Lista_Bases->Name = L"Lista_Bases";
			this->Lista_Bases->Size = System::Drawing::Size(289, 28);
			this->Lista_Bases->TabIndex = 4;
			// 
			// EliminarBaseDeDatos
			// 
			this->AcceptButton = this->Boton_Eliminar;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 211);
			this->Controls->Add(this->Lista_Bases);
			this->Controls->Add(this->Titulo);
			this->Controls->Add(this->Boton_Eliminar);
			this->Controls->Add(this->Nombre_Base_A_Eliminar);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"EliminarBaseDeDatos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ELIMINAR BASE DE DATOS";
			this->Load += gcnew System::EventHandler(this, &EliminarBaseDeDatos::EliminarBaseDeDatos_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	
	//Carga de los nombres de las Bases de Datos disponibles en Lista_Bases (ComboBox)
		private: System::Void EliminarBaseDeDatos_Load(System::Object^ sender, System::EventArgs^ e) {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 0) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					Lista_Bases->Items->Add(Base);
				}
			}
		}
	

	//Botón Eliminar Base de Datos (accept button)
		private: System::Void Boton_Eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Almacenamiento del nombre insertado en la variable BaseAEliminar
			string BaseAEliminar;
			if (Lista_Bases->SelectedItem) {
				BaseAEliminar = toStandardString(Lista_Bases->SelectedItem->ToString());
			}
			else BaseAEliminar = toStandardString(Lista_Bases->Text);

			//Banderas para MessageBox
			int NoPodemosEliminar = BaseInherenteMongoDB(BaseAEliminar);
			int BaseExistente = ComprobacionExistenciaBase(BaseAEliminar);

			//Función equivalente al Botón Eliminar Base de Datos
			EliminarBaseDeDatosExistente(BaseAEliminar);

			if (BaseExistente == 1) {
				if (NoPodemosEliminar == 0) {
					//	Mostramos un mensaje que indica que la operación ha tenido éxito
					MessageBox::Show("La base de datos ha sido eliminada correctamente.");
					//	Cerramos la ventana Eliminar Base de Datos
					this->Visible = false;
				}
				else {
					MessageBox::Show("No se ha podido completar la operación. La base de datos que está intentando eliminar es inherente a MongoDB.");
				}
			}
			else {
				MessageBox::Show("No existe ninguna base de datos que coincida con el nombre introducido");
			}
			
		}


};
}
