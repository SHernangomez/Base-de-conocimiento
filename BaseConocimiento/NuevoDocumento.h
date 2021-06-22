/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentra la función que equivale al botón del formulario
#include "Botones_Documento.h"


//Declaración variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern bson_error_t error;
extern string Base_Sel;
extern string Coleccion_Sel;
extern string confianza_info;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//	Inclusión namespace std para poder utilizar variables de tipo string
	using namespace std;

	/// <summary>
	/// Resumen de OperacionDelete
	/// </summary>
	public ref class NuevoDocumento : public System::Windows::Forms::Form
	{
	public:
		NuevoDocumento(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~NuevoDocumento()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::CheckedListBox^ ListBox_Bases;
	private: System::Windows::Forms::CheckedListBox^ ListBox_Colecciones;
	private: System::Windows::Forms::Label^ Nombre_Documento;
	private: System::Windows::Forms::Label^ Atributo1;
	private: System::Windows::Forms::Label^ Atributo2;
	private: System::Windows::Forms::Label^ Atributo3;
	private: System::Windows::Forms::Label^ Atributo4;
	private: System::Windows::Forms::Label^ Atributo5;
	private: System::Windows::Forms::Label^ Atributo6;
	private: System::Windows::Forms::Label^ Atributo7;
	private: System::Windows::Forms::TextBox^ TextBox_NombreDocumento;
	private: System::Windows::Forms::TextBox^ Clave1;
	private: System::Windows::Forms::TextBox^ Valor1;
	private: System::Windows::Forms::TextBox^ Clave2;
	private: System::Windows::Forms::TextBox^ Valor2;
	private: System::Windows::Forms::TextBox^ Clave3;
	private: System::Windows::Forms::TextBox^ Valor3;
	private: System::Windows::Forms::TextBox^ Clave4;
	private: System::Windows::Forms::TextBox^ Valor4;
	private: System::Windows::Forms::TextBox^ Clave5;
	private: System::Windows::Forms::TextBox^ Valor5;
	private: System::Windows::Forms::TextBox^ Clave6;
	private: System::Windows::Forms::TextBox^ Valor6;
	private: System::Windows::Forms::TextBox^ Clave7;
	private: System::Windows::Forms::TextBox^ Valor7;
	private: System::Windows::Forms::Button^ Boton_Añadir;
	private: System::Windows::Forms::Label^ Indicaciones;
	private: System::Windows::Forms::Label^ Label_Base;
	private: System::Windows::Forms::Label^ Label_Coleccion;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ListBox_Bases = (gcnew System::Windows::Forms::CheckedListBox());
			this->ListBox_Colecciones = (gcnew System::Windows::Forms::CheckedListBox());
			this->Nombre_Documento = (gcnew System::Windows::Forms::Label());
			this->Atributo1 = (gcnew System::Windows::Forms::Label());
			this->Atributo2 = (gcnew System::Windows::Forms::Label());
			this->Atributo3 = (gcnew System::Windows::Forms::Label());
			this->Atributo4 = (gcnew System::Windows::Forms::Label());
			this->Atributo5 = (gcnew System::Windows::Forms::Label());
			this->Atributo6 = (gcnew System::Windows::Forms::Label());
			this->Atributo7 = (gcnew System::Windows::Forms::Label());
			this->TextBox_NombreDocumento = (gcnew System::Windows::Forms::TextBox());
			this->Clave1 = (gcnew System::Windows::Forms::TextBox());
			this->Valor1 = (gcnew System::Windows::Forms::TextBox());
			this->Clave2 = (gcnew System::Windows::Forms::TextBox());
			this->Valor2 = (gcnew System::Windows::Forms::TextBox());
			this->Clave3 = (gcnew System::Windows::Forms::TextBox());
			this->Valor3 = (gcnew System::Windows::Forms::TextBox());
			this->Clave4 = (gcnew System::Windows::Forms::TextBox());
			this->Valor4 = (gcnew System::Windows::Forms::TextBox());
			this->Clave5 = (gcnew System::Windows::Forms::TextBox());
			this->Valor5 = (gcnew System::Windows::Forms::TextBox());
			this->Clave6 = (gcnew System::Windows::Forms::TextBox());
			this->Valor6 = (gcnew System::Windows::Forms::TextBox());
			this->Clave7 = (gcnew System::Windows::Forms::TextBox());
			this->Valor7 = (gcnew System::Windows::Forms::TextBox());
			this->Boton_Añadir = (gcnew System::Windows::Forms::Button());
			this->Indicaciones = (gcnew System::Windows::Forms::Label());
			this->Label_Base = (gcnew System::Windows::Forms::Label());
			this->Label_Coleccion = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ListBox_Bases
			// 
			this->ListBox_Bases->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ListBox_Bases->FormattingEnabled = true;
			this->ListBox_Bases->Location = System::Drawing::Point(12, 86);
			this->ListBox_Bases->Name = L"ListBox_Bases";
			this->ListBox_Bases->Size = System::Drawing::Size(220, 340);
			this->ListBox_Bases->TabIndex = 13;
			this->ListBox_Bases->SelectedIndexChanged += gcnew System::EventHandler(this, &NuevoDocumento::ListBox_Bases_SelectedIndexChanged);
			// 
			// ListBox_Colecciones
			// 
			this->ListBox_Colecciones->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ListBox_Colecciones->FormattingEnabled = true;
			this->ListBox_Colecciones->Location = System::Drawing::Point(272, 86);
			this->ListBox_Colecciones->Name = L"ListBox_Colecciones";
			this->ListBox_Colecciones->Size = System::Drawing::Size(220, 340);
			this->ListBox_Colecciones->TabIndex = 14;
			this->ListBox_Colecciones->SelectedIndexChanged += gcnew System::EventHandler(this, &NuevoDocumento::ListBox_Colecciones_SelectedIndexChanged);
			// 
			// Nombre_Documento
			// 
			this->Nombre_Documento->AutoSize = true;
			this->Nombre_Documento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nombre_Documento->Location = System::Drawing::Point(703, 9);
			this->Nombre_Documento->Name = L"Nombre_Documento";
			this->Nombre_Documento->Size = System::Drawing::Size(114, 19);
			this->Nombre_Documento->TabIndex = 7;
			this->Nombre_Documento->Text = L"Nombre tema:";
			// 
			// Atributo1
			// 
			this->Atributo1->AutoSize = true;
			this->Atributo1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Atributo1->Location = System::Drawing::Point(520, 75);
			this->Atributo1->Name = L"Atributo1";
			this->Atributo1->Size = System::Drawing::Size(88, 19);
			this->Atributo1->TabIndex = 9;
			this->Atributo1->Text = L"Atributo 1:";
			// 
			// Atributo2
			// 
			this->Atributo2->AutoSize = true;
			this->Atributo2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Atributo2->Location = System::Drawing::Point(520, 110);
			this->Atributo2->Name = L"Atributo2";
			this->Atributo2->Size = System::Drawing::Size(88, 19);
			this->Atributo2->TabIndex = 15;
			this->Atributo2->Text = L"Atributo 2:";
			// 
			// Atributo3
			// 
			this->Atributo3->AutoSize = true;
			this->Atributo3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Atributo3->Location = System::Drawing::Point(520, 150);
			this->Atributo3->Name = L"Atributo3";
			this->Atributo3->Size = System::Drawing::Size(88, 19);
			this->Atributo3->TabIndex = 16;
			this->Atributo3->Text = L"Atributo 3:";
			// 
			// Atributo4
			// 
			this->Atributo4->AutoSize = true;
			this->Atributo4->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Atributo4->Location = System::Drawing::Point(520, 190);
			this->Atributo4->Name = L"Atributo4";
			this->Atributo4->Size = System::Drawing::Size(88, 19);
			this->Atributo4->TabIndex = 17;
			this->Atributo4->Text = L"Atributo 4:";
			// 
			// Atributo5
			// 
			this->Atributo5->AutoSize = true;
			this->Atributo5->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Atributo5->Location = System::Drawing::Point(520, 230);
			this->Atributo5->Name = L"Atributo5";
			this->Atributo5->Size = System::Drawing::Size(88, 19);
			this->Atributo5->TabIndex = 18;
			this->Atributo5->Text = L"Atributo 5:";
			// 
			// Atributo6
			// 
			this->Atributo6->AutoSize = true;
			this->Atributo6->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Atributo6->Location = System::Drawing::Point(520, 273);
			this->Atributo6->Name = L"Atributo6";
			this->Atributo6->Size = System::Drawing::Size(88, 19);
			this->Atributo6->TabIndex = 24;
			this->Atributo6->Text = L"Atributo 6:";
			// 
			// Atributo7
			// 
			this->Atributo7->AutoSize = true;
			this->Atributo7->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Atributo7->Location = System::Drawing::Point(520, 314);
			this->Atributo7->Name = L"Atributo7";
			this->Atributo7->Size = System::Drawing::Size(88, 19);
			this->Atributo7->TabIndex = 26;
			this->Atributo7->Text = L"Atributo 7:";
			// 
			// TextBox_NombreDocumento
			// 
			this->TextBox_NombreDocumento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TextBox_NombreDocumento->Location = System::Drawing::Point(612, 31);
			this->TextBox_NombreDocumento->Name = L"TextBox_NombreDocumento";
			this->TextBox_NombreDocumento->Size = System::Drawing::Size(332, 25);
			this->TextBox_NombreDocumento->TabIndex = 45;
			// 
			// Clave1
			// 
			this->Clave1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clave1->Location = System::Drawing::Point(612, 72);
			this->Clave1->Name = L"Clave1";
			this->Clave1->Size = System::Drawing::Size(163, 25);
			this->Clave1->TabIndex = 46;
			// 
			// Valor1
			// 
			this->Valor1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Valor1->Location = System::Drawing::Point(781, 72);
			this->Valor1->Name = L"Valor1";
			this->Valor1->Size = System::Drawing::Size(163, 25);
			this->Valor1->TabIndex = 47;
			// 
			// Clave2
			// 
			this->Clave2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clave2->Location = System::Drawing::Point(612, 107);
			this->Clave2->Name = L"Clave2";
			this->Clave2->Size = System::Drawing::Size(163, 25);
			this->Clave2->TabIndex = 48;
			// 
			// Valor2
			// 
			this->Valor2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Valor2->Location = System::Drawing::Point(781, 107);
			this->Valor2->Name = L"Valor2";
			this->Valor2->Size = System::Drawing::Size(163, 25);
			this->Valor2->TabIndex = 49;
			// 
			// Clave3
			// 
			this->Clave3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clave3->Location = System::Drawing::Point(612, 147);
			this->Clave3->Name = L"Clave3";
			this->Clave3->Size = System::Drawing::Size(163, 25);
			this->Clave3->TabIndex = 50;
			// 
			// Valor3
			// 
			this->Valor3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Valor3->Location = System::Drawing::Point(781, 147);
			this->Valor3->Name = L"Valor3";
			this->Valor3->Size = System::Drawing::Size(163, 25);
			this->Valor3->TabIndex = 51;
			// 
			// Clave4
			// 
			this->Clave4->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clave4->Location = System::Drawing::Point(612, 187);
			this->Clave4->Name = L"Clave4";
			this->Clave4->Size = System::Drawing::Size(163, 25);
			this->Clave4->TabIndex = 52;
			// 
			// Valor4
			// 
			this->Valor4->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Valor4->Location = System::Drawing::Point(781, 187);
			this->Valor4->Name = L"Valor4";
			this->Valor4->Size = System::Drawing::Size(163, 25);
			this->Valor4->TabIndex = 53;
			// 
			// Clave5
			// 
			this->Clave5->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clave5->Location = System::Drawing::Point(612, 226);
			this->Clave5->Name = L"Clave5";
			this->Clave5->Size = System::Drawing::Size(163, 25);
			this->Clave5->TabIndex = 54;
			// 
			// Valor5
			// 
			this->Valor5->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Valor5->Location = System::Drawing::Point(781, 226);
			this->Valor5->Name = L"Valor5";
			this->Valor5->Size = System::Drawing::Size(163, 25);
			this->Valor5->TabIndex = 55;
			// 
			// Clave6
			// 
			this->Clave6->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clave6->Location = System::Drawing::Point(612, 270);
			this->Clave6->Name = L"Clave6";
			this->Clave6->Size = System::Drawing::Size(163, 25);
			this->Clave6->TabIndex = 56;
			// 
			// Valor6
			// 
			this->Valor6->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Valor6->Location = System::Drawing::Point(781, 270);
			this->Valor6->Name = L"Valor6";
			this->Valor6->Size = System::Drawing::Size(163, 25);
			this->Valor6->TabIndex = 57;
			// 
			// Clave7
			// 
			this->Clave7->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clave7->Location = System::Drawing::Point(612, 311);
			this->Clave7->Name = L"Clave7";
			this->Clave7->Size = System::Drawing::Size(163, 25);
			this->Clave7->TabIndex = 58;
			// 
			// Valor7
			// 
			this->Valor7->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Valor7->Location = System::Drawing::Point(781, 311);
			this->Valor7->Name = L"Valor7";
			this->Valor7->Size = System::Drawing::Size(163, 25);
			this->Valor7->TabIndex = 59;
			// 
			// Boton_Añadir
			// 
			this->Boton_Añadir->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_Añadir->Location = System::Drawing::Point(524, 376);
			this->Boton_Añadir->Name = L"Boton_Añadir";
			this->Boton_Añadir->Size = System::Drawing::Size(420, 50);
			this->Boton_Añadir->TabIndex = 60;
			this->Boton_Añadir->Text = L"Añadir Tema";
			this->Boton_Añadir->UseVisualStyleBackColor = true;
			this->Boton_Añadir->Click += gcnew System::EventHandler(this, &NuevoDocumento::Boton_Añadir_Click);
			// 
			// Indicaciones
			// 
			this->Indicaciones->AutoSize = true;
			this->Indicaciones->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Indicaciones->Location = System::Drawing::Point(77, 16);
			this->Indicaciones->Name = L"Indicaciones";
			this->Indicaciones->Size = System::Drawing::Size(339, 40);
			this->Indicaciones->TabIndex = 61;
			this->Indicaciones->Text = L"Seleccione la base de datos y la colección \r\na la que desea añadir un documento.";
			// 
			// Label_Base
			// 
			this->Label_Base->AutoSize = true;
			this->Label_Base->Location = System::Drawing::Point(12, 68);
			this->Label_Base->Name = L"Label_Base";
			this->Label_Base->Size = System::Drawing::Size(89, 15);
			this->Label_Base->TabIndex = 62;
			this->Label_Base->Text = L"Bases de datos";
			// 
			// Label_Coleccion
			// 
			this->Label_Coleccion->AutoSize = true;
			this->Label_Coleccion->Location = System::Drawing::Point(269, 68);
			this->Label_Coleccion->Name = L"Label_Coleccion";
			this->Label_Coleccion->Size = System::Drawing::Size(73, 15);
			this->Label_Coleccion->TabIndex = 63;
			this->Label_Coleccion->Text = L"Colecciones";
			// 
			// NuevoDocumento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 461);
			this->Controls->Add(this->Label_Coleccion);
			this->Controls->Add(this->Label_Base);
			this->Controls->Add(this->Indicaciones);
			this->Controls->Add(this->Boton_Añadir);
			this->Controls->Add(this->Valor7);
			this->Controls->Add(this->Clave7);
			this->Controls->Add(this->Valor6);
			this->Controls->Add(this->Clave6);
			this->Controls->Add(this->Valor5);
			this->Controls->Add(this->Clave5);
			this->Controls->Add(this->Valor4);
			this->Controls->Add(this->Clave4);
			this->Controls->Add(this->Valor3);
			this->Controls->Add(this->Clave3);
			this->Controls->Add(this->Valor2);
			this->Controls->Add(this->Clave2);
			this->Controls->Add(this->Valor1);
			this->Controls->Add(this->Clave1);
			this->Controls->Add(this->TextBox_NombreDocumento);
			this->Controls->Add(this->Atributo7);
			this->Controls->Add(this->Atributo6);
			this->Controls->Add(this->Atributo5);
			this->Controls->Add(this->Atributo4);
			this->Controls->Add(this->Atributo3);
			this->Controls->Add(this->Atributo2);
			this->Controls->Add(this->ListBox_Colecciones);
			this->Controls->Add(this->ListBox_Bases);
			this->Controls->Add(this->Atributo1);
			this->Controls->Add(this->Nombre_Documento);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"NuevoDocumento";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AÑADIR DOCUMENTO";
			this->Load += gcnew System::EventHandler(this, &NuevoDocumento::NuevoDocumento_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	//Carga CheckedListBox Bases de Datos
		private: System::Void NuevoDocumento_Load(System::Object^ sender, System::EventArgs^ e) {
			//Por defecto hay que hacer click dos veces para que se marque la casilla
			//Con esta función cambiamos a que solo haya que hacer click una vez
			this->ListBox_Bases->CheckOnClick = true;
			this->ListBox_Bases->Text = "Bases de Datos";

			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 0) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					ListBox_Bases->Items->Add(Base);
				}
			}
		}


	//Método para que solo se pueda seleccionar una Base de Datos
		private: void SeleccionarSoloUnaBase() {
			for (int i = 0; i < ListBox_Bases->Items->Count; i++) {
				//Determinamos si el ítem está seleccionado
				if (ListBox_Bases->GetSelected(i) == true) {
					//Deseleccionamos todos los demas ítems
					for (int j = 0; j < ListBox_Bases->Items->Count; j++) {
						if (j != i) ListBox_Bases->SetItemChecked(j, false);
					}
				}
			}
		}


	//Carga CheckedListBox Colecciones
		private: System::Void ListBox_Bases_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			//Por defecto hay que hacer click dos veces para que se marque la casilla
			//Con esta función cambiamos a que solo haya que hacer click una vez
			this->ListBox_Colecciones->CheckOnClick = true;
			this->ListBox_Colecciones->Text = "Colecciones";

			SeleccionarSoloUnaBase();

			//Bucle para mostrar las colecciones de la Base de Datos seleccionada en ListBox_Colecciones
			for (int i = 0; i < ListBox_Bases->CheckedItems->Count; i++) {
				String^ Base = ListBox_Bases->CheckedItems[i]->ToString();
				Base_Sel = toStandardString(Base);

				vector <string> Colecciones_Disponibles = ListaColeccionesDisponibles(Base_Sel);
				this->ListBox_Colecciones->Items->Clear();
				for (int j = 0; j < Colecciones_Disponibles.size(); j++) {
					//Función para pasar de str basic string a system string
					String^ nombre_coleccion = gcnew String(Colecciones_Disponibles[j].c_str());
					this->ListBox_Colecciones->Items->Add(nombre_coleccion);
				}
			}

		}

	
	//Método para que solo se pueda seleccionar una coleccion
		private: void SeleccionarSoloUnaColeccion() {
			for (int i = 0; i < ListBox_Colecciones->Items->Count; i++) {
				// Determine if the item is selected.
				if (ListBox_Colecciones->GetSelected(i) == true) {
					// Deselect all items that are selected.
					for (int j = 0; j < ListBox_Colecciones->Items->Count; j++) {
						if (j != i) ListBox_Colecciones->SetItemChecked(j, false);
					}
				}
			}
		}


	//Método para vaciar el contenido de las celdas correspondientes a las claves
		private: void LimpiarClaves() {
			this->Clave1->Text = "";
			this->Clave2->Text = "";
			this->Clave3->Text = "";
			this->Clave4->Text = "";
			this->Clave5->Text = "";
			this->Clave6->Text = "";
			this->Clave7->Text = "";
		}


	//Método para guardar la colección seleccionada
		private: System::Void ListBox_Colecciones_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

			SeleccionarSoloUnaColeccion();
			LimpiarClaves();

			//	Bucle para guardar el nombre de la colección seleccionada
			for (int i = 0; i < ListBox_Colecciones->CheckedItems->Count; i++)
			{
				String^ Coleccion = ListBox_Colecciones->CheckedItems[i]->ToString();
				Coleccion_Sel = toStandardString(Coleccion);
			}
			
			vector <string> ListaAtributosComunes = AtributosComunesColeccion(Base_Sel, Coleccion_Sel);
			vector <string> AtributosAColocar = AtributosComunesPorcentaje(100, ListaAtributosComunes);

			if (AtributosAColocar.empty()) {
				ListaAtributosComunes = AtributosComunesBaseDeDatos(Base_Sel);
				AtributosAColocar = AtributosComunesPorcentaje(100, ListaAtributosComunes);
				for (int i = 0; i < ListaAtributosComunes.size(); i++) {
					if (strcmpi(ListaAtributosComunes[i].c_str(), "fin") == 0) i = ListaAtributosComunes.size();
					else if (strcmpi(ListaAtributosComunes[i].c_str(), "100") != 0) {
						AtributosAColocar.push_back(ListaAtributosComunes[i]);
					}
				}
			}

			if (AtributosAColocar.size() >= 1) {
				String^ key = gcnew String(AtributosAColocar[0].c_str());
				this->Clave1->Text = key;
			}
			if (AtributosAColocar.size() >= 2) {
				String^ key = gcnew String(AtributosAColocar[1].c_str());
				this->Clave2->Text = key;
			}
			if (AtributosAColocar.size() >= 3) {
				String^ key = gcnew String(AtributosAColocar[2].c_str());
				this->Clave3->Text = key;
			}
			if (AtributosAColocar.size() >= 4) {
				String^ key = gcnew String(AtributosAColocar[3].c_str());
				this->Clave4->Text = key;
			}
			if (AtributosAColocar.size() >= 5) {
				String^ key = gcnew String(AtributosAColocar[4].c_str());
				this->Clave5->Text = key;
			}
			if (AtributosAColocar.size() >= 6) {
				String^ key = gcnew String(AtributosAColocar[5].c_str());
				this->Clave6->Text = key;
			}
			if (AtributosAColocar.size() >= 7){
				String^ key = gcnew String(AtributosAColocar[6].c_str());
				this->Clave7->Text = key;
			}

		}

		
	//Botón añadir documento a una colección de una base de datos seleccionada
		private: System::Void Boton_Añadir_Click(System::Object^ sender, System::EventArgs^ e) {

			//Almacenamiento del nombre insertado para el documento en la variable nombre
			string nombre = toStandardString(this->TextBox_NombreDocumento->Text);

			vector <string> Documentos_Disponibles = ListaDocumentosDisponibles(Base_Sel, Coleccion_Sel);

			//Bandera para MessageBox
			int BaseInherente = BaseInherenteMongoDB(Base_Sel);
			int FicheroExistente = 0;
			for (int i = 0; i < Documentos_Disponibles.size(); i++) {
				if (strcmpi(Documentos_Disponibles[i].c_str(), nombre.c_str()) == 0) FicheroExistente = 1;
			}

			
			//Creamos un vector de strings para guardar en él todas las claves y atributos introducidos por pantalla
			vector <string> atributos;
			string key, value;

			//Guardamos en el vector atributos todas las claves y valores introducidos por pantalla
			if ((this->Clave1->Text != "") && (this->Valor1->Text != "")) {
				key = toStandardString(this->Clave1->Text);
				value = toStandardString(this->Valor1->Text);

				atributos.push_back(key);
				atributos.push_back(value);
			}
			if ((this->Clave2->Text != "") && (this->Valor2->Text != "")) {
				key = toStandardString(this->Clave2->Text);
				value = toStandardString(this->Valor2->Text);

				atributos.push_back(key);
				atributos.push_back(value);

			}
			if ((this->Clave3->Text != "") && (this->Valor3->Text != "")) {
				key = toStandardString(this->Clave3->Text);
				value = toStandardString(this->Valor3->Text);

				atributos.push_back(key);
				atributos.push_back(value);
			}
			if ((this->Clave4->Text != "") && (this->Valor4->Text != "")) {
				key = toStandardString(this->Clave4->Text);
				value = toStandardString(this->Valor4->Text);

				atributos.push_back(key);
				atributos.push_back(value);
			}
			if ((this->Clave5->Text != "") && (this->Valor5->Text != "")) {
				key = toStandardString(this->Clave5->Text);
				value = toStandardString(this->Valor5->Text);

				atributos.push_back(key);
				atributos.push_back(value);
			}
			if ((this->Clave6->Text != "") && (this->Valor6->Text != "")) {
				key = toStandardString(this->Clave1->Text);
				value = toStandardString(this->Valor1->Text);

				atributos.push_back(key);
				atributos.push_back(value);
			}
			if ((this->Clave7->Text != "") && (this->Valor7->Text != "")) {
				key = toStandardString(this->Clave1->Text);
				value = toStandardString(this->Valor1->Text);

				atributos.push_back(key);
				atributos.push_back(value);
			}

			
			if ((ListBox_Bases->CheckedItems->Count == 0) || (ListBox_Colecciones->CheckedItems->Count == 0)) {
				MessageBox::Show("Debe seleccionar una Base de Datos y una colección para añadir el documento.");
			}
			else {
				
				//Función equivalente al Botón Añadir Documento
				CrearDocumento(Base_Sel, Coleccion_Sel, nombre, atributos, confianza_info);
				
				if (BaseInherente == 0) {
					if (FicheroExistente == 1) {
						MessageBox::Show("Ya existe un documento sobre ese tema en la colección seleccionada");
					}
					else {
						MessageBox::Show("La información se ha añadido correctamente a la Base de Conocimiento");
						this->Visible = false;
					}
				}
				else MessageBox::Show("No se ha podido completar la operación.La Base de Datos que está intentando modificar es inherente a MongoDB.");
			}
				
		}


};
}
