/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentra la función que equivale al botón del formulario
#include "Botones_Coleccion.h"

//Fichero de encabezamiento donde se encuentran las funciones básicas para el funcionamiento del programa
#include "Funciones.h"


//Declaración variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
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

	public ref class EliminarColeccion : public System::Windows::Forms::Form
	{
	public:
		EliminarColeccion(void)
		{
			InitializeComponent();
		}

	protected:
		~EliminarColeccion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Aviso_Base_Coleccion;
	private: System::Windows::Forms::Label^ Nombre_Base;
	private: System::Windows::Forms::Label^ Nombre_Coleccion;
	private: System::Windows::Forms::Button^ Boton_EliminarColeccion;
	private: System::Windows::Forms::ComboBox^ Lista_Bases;
	private: System::Windows::Forms::ComboBox^ Lista_Colecciones;

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->Aviso_Base_Coleccion = (gcnew System::Windows::Forms::Label());
			this->Nombre_Base = (gcnew System::Windows::Forms::Label());
			this->Nombre_Coleccion = (gcnew System::Windows::Forms::Label());
			this->Boton_EliminarColeccion = (gcnew System::Windows::Forms::Button());
			this->Lista_Bases = (gcnew System::Windows::Forms::ComboBox());
			this->Lista_Colecciones = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// Aviso_Base_Coleccion
			// 
			this->Aviso_Base_Coleccion->AutoSize = true;
			this->Aviso_Base_Coleccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Aviso_Base_Coleccion->Location = System::Drawing::Point(56, 23);
			this->Aviso_Base_Coleccion->Name = L"Aviso_Base_Coleccion";
			this->Aviso_Base_Coleccion->Size = System::Drawing::Size(366, 36);
			this->Aviso_Base_Coleccion->TabIndex = 9;
			this->Aviso_Base_Coleccion->Text = L"Escriba el nombre de la colección que desea eliminar, \r\nasí como el de la base de"
				L" datos a la que pertenece";
			this->Aviso_Base_Coleccion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Nombre_Base
			// 
			this->Nombre_Base->AutoSize = true;
			this->Nombre_Base->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nombre_Base->Location = System::Drawing::Point(55, 89);
			this->Nombre_Base->Name = L"Nombre_Base";
			this->Nombre_Base->Size = System::Drawing::Size(178, 19);
			this->Nombre_Base->TabIndex = 10;
			this->Nombre_Base->Text = L"Nombre base de datos:";
			// 
			// Nombre_Coleccion
			// 
			this->Nombre_Coleccion->AutoSize = true;
			this->Nombre_Coleccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nombre_Coleccion->Location = System::Drawing::Point(55, 140);
			this->Nombre_Coleccion->Name = L"Nombre_Coleccion";
			this->Nombre_Coleccion->Size = System::Drawing::Size(145, 19);
			this->Nombre_Coleccion->TabIndex = 12;
			this->Nombre_Coleccion->Text = L"Nombre colección:";
			// 
			// Boton_EliminarColeccion
			// 
			this->Boton_EliminarColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_EliminarColeccion->Location = System::Drawing::Point(59, 189);
			this->Boton_EliminarColeccion->Name = L"Boton_EliminarColeccion";
			this->Boton_EliminarColeccion->Size = System::Drawing::Size(363, 50);
			this->Boton_EliminarColeccion->TabIndex = 14;
			this->Boton_EliminarColeccion->Text = L"Eliminar colección";
			this->Boton_EliminarColeccion->UseVisualStyleBackColor = true;
			this->Boton_EliminarColeccion->Click += gcnew System::EventHandler(this, &EliminarColeccion::Boton_EliminarColeccion_Click);
			// 
			// Lista_Bases
			// 
			this->Lista_Bases->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lista_Bases->FormattingEnabled = true;
			this->Lista_Bases->Location = System::Drawing::Point(259, 85);
			this->Lista_Bases->Name = L"Lista_Bases";
			this->Lista_Bases->Size = System::Drawing::Size(163, 28);
			this->Lista_Bases->TabIndex = 15;
			this->Lista_Bases->SelectedIndexChanged += gcnew System::EventHandler(this, &EliminarColeccion::Lista_Bases_SelectedIndexChanged);
			// 
			// Lista_Colecciones
			// 
			this->Lista_Colecciones->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lista_Colecciones->FormattingEnabled = true;
			this->Lista_Colecciones->Location = System::Drawing::Point(259, 136);
			this->Lista_Colecciones->Name = L"Lista_Colecciones";
			this->Lista_Colecciones->Size = System::Drawing::Size(163, 28);
			this->Lista_Colecciones->TabIndex = 16;
			// 
			// EliminarColeccion
			// 
			this->AcceptButton = this->Boton_EliminarColeccion;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 261);
			this->Controls->Add(this->Lista_Colecciones);
			this->Controls->Add(this->Lista_Bases);
			this->Controls->Add(this->Boton_EliminarColeccion);
			this->Controls->Add(this->Nombre_Coleccion);
			this->Controls->Add(this->Nombre_Base);
			this->Controls->Add(this->Aviso_Base_Coleccion);
			this->Name = L"EliminarColeccion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ELIMINAR COLECCIÓN";
			this->Load += gcnew System::EventHandler(this, &EliminarColeccion::EliminarColeccion_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	//Carga de los nombres de las Bases de Datos disponibles en Lista_Bases (ComboBox)
		private: System::Void EliminarColeccion_Load(System::Object^ sender, System::EventArgs^ e) {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 0) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					Lista_Bases->Items->Add(Base);
				}
			}
		}

	
	//Carga de los nombres de las colecciones disponibles en Lista_Colecciones (ComboBox)
		private: System::Void Lista_Bases_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (Lista_Bases->SelectedItem) {
				Base = toStandardString(Lista_Bases->SelectedItem->ToString());
			}
			else Base = toStandardString(Lista_Bases->Text);

			Lista_Colecciones->Items->Clear();

			vector <string> Colecciones_Disponibles = ListaColeccionesDisponibles(Base);
			for (int i = 0; i < Colecciones_Disponibles.size(); i++) {
				String^ Coleccion = gcnew String(Colecciones_Disponibles[i].c_str());
				Lista_Colecciones->Items->Add(Coleccion);
			}
		}


	//Botón Eliminar Colección (accept button)
		private: System::Void Boton_EliminarColeccion_Click(System::Object^ sender, System::EventArgs^ e) {
			//Almacenamiento del nombre insertado para la Base de Datos en la variable Base
			string Base;
			if (Lista_Bases->SelectedItem) {
				Base = toStandardString(Lista_Bases->SelectedItem->ToString());
			}
			else Base = toStandardString(Lista_Bases->Text);
			
			//Almacenamiento del nombre insertado para la colección en la variable NuevaColeccion
			string ColeccionAEliminar;
			if (Lista_Colecciones->SelectedItem) {
				ColeccionAEliminar = toStandardString(Lista_Colecciones->SelectedItem->ToString());
			}
			else ColeccionAEliminar = toStandardString(Lista_Colecciones->Text);

			//Banderas para MessageBox
			int BaseExistente = ComprobacionExistenciaBase(Base);
			int BaseInherente = BaseInherenteMongoDB(Base);
			int ColeccionExistente = ColeccionPerteneceABase(Base, ColeccionAEliminar);
			
			//Función equivalente al Botón Añadir Coleccion
			EliminarColeccionExistente(Base, ColeccionAEliminar);

			if (BaseExistente == 1) {
			   if (BaseInherente == 0) {
				   if (ColeccionExistente == 1) {
					   MessageBox::Show("La colección ha sido eliminada correctamente.");
					   this->Visible = false;
				   }
				   else MessageBox::Show("La colección introducida no existe o no pertenece a la base de datos introducida");
			   }
			   else MessageBox::Show("No se ha podido completar la operación. La base de datos que está intentando modificar es inherente a MongoDB.");
			}
			else MessageBox::Show("La base de datos introducida no existe.");
		}
		
		
	};
}
