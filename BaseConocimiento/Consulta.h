/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentran las funciones que equivalen a los botones del formulario
#include "Botones_Documento.h"
#include"MostrarDocumentoPorID.h"


//Declaración variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern bson_error_t error;
extern string id_introducido;


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
		/// Resumen de OperacionUpdate
		/// </summary>
		public ref class Consulta : public System::Windows::Forms::Form
		{
		public:
			Consulta(void)
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
			~Consulta()
			{
				if (components)
				{
					delete components;
				}
			}



		private: System::Windows::Forms::Panel^ Panel_BuscarPorColeccion;
		private: System::Windows::Forms::Button^ Boton_Coleccion;
		private: System::Windows::Forms::Label^ Label_CC;

		private: System::Windows::Forms::Panel^ Panel_ConsultarPorNombre;
		private: System::Windows::Forms::Label^ Label_CN;
		private: System::Windows::Forms::Button^ Boton_Buscador;

		private: System::Windows::Forms::Panel^ Panel_ConsultarPorAtributo;
		private: System::Windows::Forms::Label^ Label_CA;
		private: System::Windows::Forms::Button^ Boton_ConsultarAtributo;



		private: System::Windows::Forms::TextBox^ Valor4;
		private: System::Windows::Forms::TextBox^ Clave4;
		private: System::Windows::Forms::Label^ Atributo4;
		private: System::Windows::Forms::TextBox^ Valor3;
		private: System::Windows::Forms::TextBox^ Clave3;
		private: System::Windows::Forms::Label^ Atributo3;
		private: System::Windows::Forms::TextBox^ Valor2;
		private: System::Windows::Forms::TextBox^ Clave2;
		private: System::Windows::Forms::Label^ Atributo2;
		private: System::Windows::Forms::TextBox^ Valor1;
		private: System::Windows::Forms::TextBox^ Clave1;
		private: System::Windows::Forms::Label^ Atributo1;
		private: System::Windows::Forms::TextBox^ salida_datos;
		private: System::Windows::Forms::ComboBox^ ComboBox_Coleccion;
		private: System::Windows::Forms::Label^ Label_C;
		private: System::Windows::Forms::ComboBox^ ComboBox_Base;
		private: System::Windows::Forms::Label^ Label_BD;
		private: System::Windows::Forms::Panel^ Panel_ConsultarPorID;
		private: System::Windows::Forms::Label^ Label_CID;
		private: System::Windows::Forms::Button^ Boton_id;
		private: System::Windows::Forms::TextBox^ TextBox_id;
		private: System::Windows::Forms::ComboBox^ ComboBox_NombreColeccion;

		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::ComboBox^ ComboBox_NombreBase;

		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::ComboBox^ ComboBox_Nombre;


























		protected:

		private:
			/// <summary>
			/// Variable del diseñador necesaria.
			/// </summary>
			System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
			/// <summary>
			/// Método necesario para admitir el Diseñador. No se puede modificar
			/// el contenido de este método con el editor de código.
			/// </summary>
			void InitializeComponent(void)
			{
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Consulta::typeid));
				this->Panel_BuscarPorColeccion = (gcnew System::Windows::Forms::Panel());
				this->ComboBox_Coleccion = (gcnew System::Windows::Forms::ComboBox());
				this->Label_C = (gcnew System::Windows::Forms::Label());
				this->ComboBox_Base = (gcnew System::Windows::Forms::ComboBox());
				this->Label_BD = (gcnew System::Windows::Forms::Label());
				this->Boton_Coleccion = (gcnew System::Windows::Forms::Button());
				this->Label_CC = (gcnew System::Windows::Forms::Label());
				this->Panel_ConsultarPorNombre = (gcnew System::Windows::Forms::Panel());
				this->ComboBox_Nombre = (gcnew System::Windows::Forms::ComboBox());
				this->ComboBox_NombreColeccion = (gcnew System::Windows::Forms::ComboBox());
				this->Label_CN = (gcnew System::Windows::Forms::Label());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->Boton_Buscador = (gcnew System::Windows::Forms::Button());
				this->ComboBox_NombreBase = (gcnew System::Windows::Forms::ComboBox());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->Panel_ConsultarPorAtributo = (gcnew System::Windows::Forms::Panel());
				this->Label_CA = (gcnew System::Windows::Forms::Label());
				this->Valor4 = (gcnew System::Windows::Forms::TextBox());
				this->Boton_ConsultarAtributo = (gcnew System::Windows::Forms::Button());
				this->Clave4 = (gcnew System::Windows::Forms::TextBox());
				this->Atributo4 = (gcnew System::Windows::Forms::Label());
				this->Valor3 = (gcnew System::Windows::Forms::TextBox());
				this->Clave3 = (gcnew System::Windows::Forms::TextBox());
				this->Atributo3 = (gcnew System::Windows::Forms::Label());
				this->Valor2 = (gcnew System::Windows::Forms::TextBox());
				this->Clave2 = (gcnew System::Windows::Forms::TextBox());
				this->Atributo2 = (gcnew System::Windows::Forms::Label());
				this->Valor1 = (gcnew System::Windows::Forms::TextBox());
				this->Clave1 = (gcnew System::Windows::Forms::TextBox());
				this->Atributo1 = (gcnew System::Windows::Forms::Label());
				this->salida_datos = (gcnew System::Windows::Forms::TextBox());
				this->Panel_ConsultarPorID = (gcnew System::Windows::Forms::Panel());
				this->Label_CID = (gcnew System::Windows::Forms::Label());
				this->Boton_id = (gcnew System::Windows::Forms::Button());
				this->TextBox_id = (gcnew System::Windows::Forms::TextBox());
				this->Panel_BuscarPorColeccion->SuspendLayout();
				this->Panel_ConsultarPorNombre->SuspendLayout();
				this->Panel_ConsultarPorAtributo->SuspendLayout();
				this->Panel_ConsultarPorID->SuspendLayout();
				this->SuspendLayout();
				// 
				// Panel_BuscarPorColeccion
				// 
				this->Panel_BuscarPorColeccion->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Panel_BuscarPorColeccion->Controls->Add(this->ComboBox_Coleccion);
				this->Panel_BuscarPorColeccion->Controls->Add(this->Label_C);
				this->Panel_BuscarPorColeccion->Controls->Add(this->ComboBox_Base);
				this->Panel_BuscarPorColeccion->Controls->Add(this->Label_BD);
				this->Panel_BuscarPorColeccion->Controls->Add(this->Boton_Coleccion);
				this->Panel_BuscarPorColeccion->Controls->Add(this->Label_CC);
				this->Panel_BuscarPorColeccion->Location = System::Drawing::Point(12, 21);
				this->Panel_BuscarPorColeccion->Name = L"Panel_BuscarPorColeccion";
				this->Panel_BuscarPorColeccion->Size = System::Drawing::Size(387, 72);
				this->Panel_BuscarPorColeccion->TabIndex = 73;
				// 
				// ComboBox_Coleccion
				// 
				this->ComboBox_Coleccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ComboBox_Coleccion->FormattingEnabled = true;
				this->ComboBox_Coleccion->Location = System::Drawing::Point(194, 32);
				this->ComboBox_Coleccion->Name = L"ComboBox_Coleccion";
				this->ComboBox_Coleccion->Size = System::Drawing::Size(117, 28);
				this->ComboBox_Coleccion->TabIndex = 112;
				// 
				// Label_C
				// 
				this->Label_C->AutoSize = true;
				this->Label_C->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Label_C->Location = System::Drawing::Point(171, 36);
				this->Label_C->Name = L"Label_C";
				this->Label_C->Size = System::Drawing::Size(25, 19);
				this->Label_C->TabIndex = 95;
				this->Label_C->Text = L"C:";
				// 
				// ComboBox_Base
				// 
				this->ComboBox_Base->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ComboBox_Base->FormattingEnabled = true;
				this->ComboBox_Base->Location = System::Drawing::Point(52, 32);
				this->ComboBox_Base->Name = L"ComboBox_Base";
				this->ComboBox_Base->Size = System::Drawing::Size(113, 28);
				this->ComboBox_Base->TabIndex = 110;
				this->ComboBox_Base->SelectedIndexChanged += gcnew System::EventHandler(this, &Consulta::ComboBox_Base_SelectedIndexChanged);
				// 
				// Label_BD
				// 
				this->Label_BD->AutoSize = true;
				this->Label_BD->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Label_BD->Location = System::Drawing::Point(17, 36);
				this->Label_BD->Name = L"Label_BD";
				this->Label_BD->Size = System::Drawing::Size(37, 19);
				this->Label_BD->TabIndex = 94;
				this->Label_BD->Text = L"BD:";
				// 
				// Boton_Coleccion
				// 
				this->Boton_Coleccion->BackColor = System::Drawing::SystemColors::ButtonFace;
				this->Boton_Coleccion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_Coleccion.Image")));
				this->Boton_Coleccion->Location = System::Drawing::Point(317, 32);
				this->Boton_Coleccion->Name = L"Boton_Coleccion";
				this->Boton_Coleccion->Size = System::Drawing::Size(50, 28);
				this->Boton_Coleccion->TabIndex = 76;
				this->Boton_Coleccion->UseVisualStyleBackColor = false;
				this->Boton_Coleccion->Click += gcnew System::EventHandler(this, &Consulta::Boton_Coleccion_Click);
				// 
				// Label_CC
				// 
				this->Label_CC->AutoSize = true;
				this->Label_CC->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Label_CC->Location = System::Drawing::Point(18, 4);
				this->Label_CC->MaximumSize = System::Drawing::Size(450, 550);
				this->Label_CC->Name = L"Label_CC";
				this->Label_CC->Size = System::Drawing::Size(170, 16);
				this->Label_CC->TabIndex = 74;
				this->Label_CC->Text = L"Consultar por colección";
				// 
				// Panel_ConsultarPorNombre
				// 
				this->Panel_ConsultarPorNombre->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Panel_ConsultarPorNombre->Controls->Add(this->ComboBox_Nombre);
				this->Panel_ConsultarPorNombre->Controls->Add(this->ComboBox_NombreColeccion);
				this->Panel_ConsultarPorNombre->Controls->Add(this->Label_CN);
				this->Panel_ConsultarPorNombre->Controls->Add(this->label1);
				this->Panel_ConsultarPorNombre->Controls->Add(this->Boton_Buscador);
				this->Panel_ConsultarPorNombre->Controls->Add(this->ComboBox_NombreBase);
				this->Panel_ConsultarPorNombre->Controls->Add(this->label2);
				this->Panel_ConsultarPorNombre->Location = System::Drawing::Point(12, 195);
				this->Panel_ConsultarPorNombre->Name = L"Panel_ConsultarPorNombre";
				this->Panel_ConsultarPorNombre->Size = System::Drawing::Size(387, 115);
				this->Panel_ConsultarPorNombre->TabIndex = 74;
				// 
				// ComboBox_Nombre
				// 
				this->ComboBox_Nombre->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ComboBox_Nombre->FormattingEnabled = true;
				this->ComboBox_Nombre->Location = System::Drawing::Point(20, 68);
				this->ComboBox_Nombre->Name = L"ComboBox_Nombre";
				this->ComboBox_Nombre->Size = System::Drawing::Size(297, 28);
				this->ComboBox_Nombre->TabIndex = 117;
				// 
				// ComboBox_NombreColeccion
				// 
				this->ComboBox_NombreColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->ComboBox_NombreColeccion->FormattingEnabled = true;
				this->ComboBox_NombreColeccion->Location = System::Drawing::Point(200, 34);
				this->ComboBox_NombreColeccion->Name = L"ComboBox_NombreColeccion";
				this->ComboBox_NombreColeccion->Size = System::Drawing::Size(117, 28);
				this->ComboBox_NombreColeccion->TabIndex = 116;
				this->ComboBox_NombreColeccion->SelectedIndexChanged += gcnew System::EventHandler(this, &Consulta::ComboBox_NombreColeccion_SelectedIndexChanged);
				// 
				// Label_CN
				// 
				this->Label_CN->AutoSize = true;
				this->Label_CN->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Label_CN->Location = System::Drawing::Point(18, 4);
				this->Label_CN->Name = L"Label_CN";
				this->Label_CN->Size = System::Drawing::Size(158, 16);
				this->Label_CN->TabIndex = 77;
				this->Label_CN->Text = L"Consultar por nombre";
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(177, 38);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(25, 19);
				this->label1->TabIndex = 114;
				this->label1->Text = L"C:";
				// 
				// Boton_Buscador
				// 
				this->Boton_Buscador->BackColor = System::Drawing::SystemColors::ButtonFace;
				this->Boton_Buscador->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_Buscador.Image")));
				this->Boton_Buscador->Location = System::Drawing::Point(318, 34);
				this->Boton_Buscador->Name = L"Boton_Buscador";
				this->Boton_Buscador->Size = System::Drawing::Size(50, 62);
				this->Boton_Buscador->TabIndex = 76;
				this->Boton_Buscador->UseVisualStyleBackColor = false;
				this->Boton_Buscador->Click += gcnew System::EventHandler(this, &Consulta::Boton_Buscador_Click);
				// 
				// ComboBox_NombreBase
				// 
				this->ComboBox_NombreBase->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->ComboBox_NombreBase->FormattingEnabled = true;
				this->ComboBox_NombreBase->Location = System::Drawing::Point(52, 34);
				this->ComboBox_NombreBase->Name = L"ComboBox_NombreBase";
				this->ComboBox_NombreBase->Size = System::Drawing::Size(113, 28);
				this->ComboBox_NombreBase->TabIndex = 115;
				this->ComboBox_NombreBase->SelectedIndexChanged += gcnew System::EventHandler(this, &Consulta::ComboBox_NombreBase_SelectedIndexChanged);
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label2->Location = System::Drawing::Point(17, 38);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(37, 19);
				this->label2->TabIndex = 113;
				this->label2->Text = L"BD:";
				// 
				// Panel_ConsultarPorAtributo
				// 
				this->Panel_ConsultarPorAtributo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Panel_ConsultarPorAtributo->Controls->Add(this->Label_CA);
				this->Panel_ConsultarPorAtributo->Controls->Add(this->Valor4);
				this->Panel_ConsultarPorAtributo->Controls->Add(this->Boton_ConsultarAtributo);
				this->Panel_ConsultarPorAtributo->Location = System::Drawing::Point(12, 327);
				this->Panel_ConsultarPorAtributo->Name = L"Panel_ConsultarPorAtributo";
				this->Panel_ConsultarPorAtributo->Size = System::Drawing::Size(387, 312);
				this->Panel_ConsultarPorAtributo->TabIndex = 75;
				// 
				// Label_CA
				// 
				this->Label_CA->AutoSize = true;
				this->Label_CA->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Label_CA->Location = System::Drawing::Point(18, 4);
				this->Label_CA->Name = L"Label_CA";
				this->Label_CA->Size = System::Drawing::Size(162, 16);
				this->Label_CA->TabIndex = 76;
				this->Label_CA->Text = L"Consultar por atributo";
				// 
				// Valor4
				// 
				this->Valor4->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Valor4->Location = System::Drawing::Point(241, 198);
				this->Valor4->Name = L"Valor4";
				this->Valor4->Size = System::Drawing::Size(127, 25);
				this->Valor4->TabIndex = 88;
				// 
				// Boton_ConsultarAtributo
				// 
				this->Boton_ConsultarAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Boton_ConsultarAtributo->Location = System::Drawing::Point(20, 239);
				this->Boton_ConsultarAtributo->Name = L"Boton_ConsultarAtributo";
				this->Boton_ConsultarAtributo->Size = System::Drawing::Size(347, 52);
				this->Boton_ConsultarAtributo->TabIndex = 92;
				this->Boton_ConsultarAtributo->Text = L"Consultar";
				this->Boton_ConsultarAtributo->UseVisualStyleBackColor = true;
				this->Boton_ConsultarAtributo->Click += gcnew System::EventHandler(this, &Consulta::Boton_ConsultarAtributo_Click);
				// 
				// Clave4
				// 
				this->Clave4->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Clave4->Location = System::Drawing::Point(124, 526);
				this->Clave4->Name = L"Clave4";
				this->Clave4->Size = System::Drawing::Size(124, 25);
				this->Clave4->TabIndex = 87;
				// 
				// Atributo4
				// 
				this->Atributo4->AutoSize = true;
				this->Atributo4->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Atributo4->Location = System::Drawing::Point(30, 526);
				this->Atributo4->Name = L"Atributo4";
				this->Atributo4->Size = System::Drawing::Size(88, 19);
				this->Atributo4->TabIndex = 86;
				this->Atributo4->Text = L"Atributo 4:";
				// 
				// Valor3
				// 
				this->Valor3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Valor3->Location = System::Drawing::Point(254, 476);
				this->Valor3->Name = L"Valor3";
				this->Valor3->Size = System::Drawing::Size(127, 25);
				this->Valor3->TabIndex = 85;
				// 
				// Clave3
				// 
				this->Clave3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Clave3->Location = System::Drawing::Point(124, 476);
				this->Clave3->Name = L"Clave3";
				this->Clave3->Size = System::Drawing::Size(124, 25);
				this->Clave3->TabIndex = 84;
				// 
				// Atributo3
				// 
				this->Atributo3->AutoSize = true;
				this->Atributo3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Atributo3->Location = System::Drawing::Point(30, 476);
				this->Atributo3->Name = L"Atributo3";
				this->Atributo3->Size = System::Drawing::Size(88, 19);
				this->Atributo3->TabIndex = 83;
				this->Atributo3->Text = L"Atributo 3:";
				// 
				// Valor2
				// 
				this->Valor2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Valor2->Location = System::Drawing::Point(254, 426);
				this->Valor2->Name = L"Valor2";
				this->Valor2->Size = System::Drawing::Size(127, 25);
				this->Valor2->TabIndex = 82;
				// 
				// Clave2
				// 
				this->Clave2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Clave2->Location = System::Drawing::Point(124, 426);
				this->Clave2->Name = L"Clave2";
				this->Clave2->Size = System::Drawing::Size(124, 25);
				this->Clave2->TabIndex = 81;
				// 
				// Atributo2
				// 
				this->Atributo2->AutoSize = true;
				this->Atributo2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Atributo2->Location = System::Drawing::Point(30, 426);
				this->Atributo2->Name = L"Atributo2";
				this->Atributo2->Size = System::Drawing::Size(88, 19);
				this->Atributo2->TabIndex = 80;
				this->Atributo2->Text = L"Atributo 2:";
				// 
				// Valor1
				// 
				this->Valor1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Valor1->Location = System::Drawing::Point(254, 373);
				this->Valor1->Name = L"Valor1";
				this->Valor1->Size = System::Drawing::Size(127, 25);
				this->Valor1->TabIndex = 79;
				// 
				// Clave1
				// 
				this->Clave1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Clave1->Location = System::Drawing::Point(124, 373);
				this->Clave1->Name = L"Clave1";
				this->Clave1->Size = System::Drawing::Size(124, 25);
				this->Clave1->TabIndex = 78;
				// 
				// Atributo1
				// 
				this->Atributo1->AutoSize = true;
				this->Atributo1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Atributo1->Location = System::Drawing::Point(30, 376);
				this->Atributo1->Name = L"Atributo1";
				this->Atributo1->Size = System::Drawing::Size(88, 19);
				this->Atributo1->TabIndex = 77;
				this->Atributo1->Text = L"Atributo 1:";
				// 
				// salida_datos
				// 
				this->salida_datos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->salida_datos->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->salida_datos->Location = System::Drawing::Point(431, 21);
				this->salida_datos->Multiline = true;
				this->salida_datos->Name = L"salida_datos";
				this->salida_datos->ReadOnly = true;
				this->salida_datos->ScrollBars = System::Windows::Forms::ScrollBars::Both;
				this->salida_datos->Size = System::Drawing::Size(522, 618);
				this->salida_datos->TabIndex = 93;
				// 
				// Panel_ConsultarPorID
				// 
				this->Panel_ConsultarPorID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->Panel_ConsultarPorID->Controls->Add(this->Label_CID);
				this->Panel_ConsultarPorID->Controls->Add(this->Boton_id);
				this->Panel_ConsultarPorID->Controls->Add(this->TextBox_id);
				this->Panel_ConsultarPorID->Location = System::Drawing::Point(12, 109);
				this->Panel_ConsultarPorID->Name = L"Panel_ConsultarPorID";
				this->Panel_ConsultarPorID->Size = System::Drawing::Size(387, 70);
				this->Panel_ConsultarPorID->TabIndex = 78;
				// 
				// Label_CID
				// 
				this->Label_CID->AutoSize = true;
				this->Label_CID->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Label_CID->Location = System::Drawing::Point(18, 4);
				this->Label_CID->Name = L"Label_CID";
				this->Label_CID->Size = System::Drawing::Size(121, 16);
				this->Label_CID->TabIndex = 77;
				this->Label_CID->Text = L"Consultar por ID";
				// 
				// Boton_id
				// 
				this->Boton_id->BackColor = System::Drawing::SystemColors::ButtonFace;
				this->Boton_id->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_id.Image")));
				this->Boton_id->Location = System::Drawing::Point(317, 32);
				this->Boton_id->Name = L"Boton_id";
				this->Boton_id->Size = System::Drawing::Size(50, 28);
				this->Boton_id->TabIndex = 76;
				this->Boton_id->UseVisualStyleBackColor = false;
				this->Boton_id->Click += gcnew System::EventHandler(this, &Consulta::Boton_id_Click);
				// 
				// TextBox_id
				// 
				this->TextBox_id->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->TextBox_id->Location = System::Drawing::Point(20, 32);
				this->TextBox_id->Name = L"TextBox_id";
				this->TextBox_id->Size = System::Drawing::Size(297, 26);
				this->TextBox_id->TabIndex = 75;
				// 
				// Consulta
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(984, 661);
				this->Controls->Add(this->Panel_ConsultarPorID);
				this->Controls->Add(this->salida_datos);
				this->Controls->Add(this->Panel_ConsultarPorNombre);
				this->Controls->Add(this->Clave4);
				this->Controls->Add(this->Atributo4);
				this->Controls->Add(this->Valor3);
				this->Controls->Add(this->Clave3);
				this->Controls->Add(this->Atributo3);
				this->Controls->Add(this->Valor2);
				this->Controls->Add(this->Clave2);
				this->Controls->Add(this->Atributo2);
				this->Controls->Add(this->Valor1);
				this->Controls->Add(this->Clave1);
				this->Controls->Add(this->Atributo1);
				this->Controls->Add(this->Panel_ConsultarPorAtributo);
				this->Controls->Add(this->Panel_BuscarPorColeccion);
				this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Name = L"Consulta";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"CONSULTAR DOCUMENTO";
				this->Load += gcnew System::EventHandler(this, &Consulta::Consulta_Load);
				this->Panel_BuscarPorColeccion->ResumeLayout(false);
				this->Panel_BuscarPorColeccion->PerformLayout();
				this->Panel_ConsultarPorNombre->ResumeLayout(false);
				this->Panel_ConsultarPorNombre->PerformLayout();
				this->Panel_ConsultarPorAtributo->ResumeLayout(false);
				this->Panel_ConsultarPorAtributo->PerformLayout();
				this->Panel_ConsultarPorID->ResumeLayout(false);
				this->Panel_ConsultarPorID->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion


	//Carga de los nombres de las Bases de Datos disponibles en ComboBox_Base y ComboBox_NombreBase
		private: System::Void Consulta_Load(System::Object^ sender, System::EventArgs^ e) {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 0) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					ComboBox_Base->Items->Add(Base);
					ComboBox_NombreBase->Items->Add(Base);
				}
			}
		}

	
	//Carga de los nombres de las colecciones disponibles en ComboBox_Coleccion
		private: System::Void ComboBox_Base_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (ComboBox_Base->SelectedItem) {
				Base = toStandardString(ComboBox_Base->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_Base->Text);

			ComboBox_Coleccion->Items->Clear();

			vector <string> Colecciones_Disponibles = ListaColeccionesDisponibles(Base);
			for (int i = 0; i < Colecciones_Disponibles.size(); i++) {
				String^ Coleccion = gcnew String(Colecciones_Disponibles[i].c_str());
				ComboBox_Coleccion->Items->Add(Coleccion);
			}
		}


	//Carga de los nombres de las colecciones disponibles en ComboBox_NombreColeccion
		private: System::Void ComboBox_NombreBase_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (ComboBox_NombreBase->SelectedItem) {
				Base = toStandardString(ComboBox_NombreBase->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_NombreBase->Text);

			ComboBox_NombreColeccion->Items->Clear();

			vector <string> Colecciones_Disponibles = ListaColeccionesDisponibles(Base);
			for (int i = 0; i < Colecciones_Disponibles.size(); i++) {
				String^ Coleccion = gcnew String(Colecciones_Disponibles[i].c_str());
				ComboBox_NombreColeccion->Items->Add(Coleccion);
			}
		}


	//Carga de los nombres de los documentos disponibles en ComboBox_Nombre
		private: System::Void ComboBox_NombreColeccion_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (ComboBox_NombreBase->SelectedItem) {
				Base = toStandardString(ComboBox_NombreBase->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_NombreBase->Text);

			string Coleccion;
			if (ComboBox_NombreColeccion->SelectedItem) {
				Coleccion = toStandardString(ComboBox_NombreColeccion->SelectedItem->ToString());
			}
			else Coleccion = toStandardString(ComboBox_NombreColeccion->Text);

			ComboBox_Nombre->Items->Clear();

			vector <string> Documentos_Disponibles = ListaDocumentosDisponibles(Base, Coleccion);
			for (int i = 0; i < Documentos_Disponibles.size(); i++) {
				String^ Identificador = gcnew String(Documentos_Disponibles[i].c_str());
				ComboBox_Nombre->Items->Add(Identificador);
			}
		}


	//Método para limpiar la salida por pantalla y todos los TextBox menos TextBox_Colección al escribir en este último
		private: System::Void TextBox_Coleccion_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			this->salida_datos->Text = "";
			this->ComboBox_Nombre->Text = "";
			this->Clave1->Text = "";
			this->Clave2->Text = "";
			this->Clave3->Text = "";
			this->Clave4->Text = "";
			this->Valor1->Text = "";
			this->Valor2->Text = "";
			this->Valor3->Text = "";
			this->Valor4->Text = "";
		}


	//Método para limpiar la salida por pantalla y todos los TextBox menos TextBox_Buscador al escribir en este último
		private: System::Void TextBox_Buscador_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			this->salida_datos->Text = "";
			this->Clave1->Text = "";
			this->Clave2->Text = "";
			this->Clave3->Text = "";
			this->Clave4->Text = "";
			this->Valor1->Text = "";
			this->Valor2->Text = "";
			this->Valor3->Text = "";
			this->Valor4->Text = "";
		}


	//Método para limpiar la salida por pantalla, TextBox_Coleccion y TextBox_Buscador al escribir en atributos
		private: System::Void Clave1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			this->salida_datos->Text = "";
			this->ComboBox_Base->Text == "";
			this->ComboBox_Coleccion->Text == "";
			this->ComboBox_Nombre->Text = "";
		}


	//Botón buscar por colección
		private: System::Void Boton_Coleccion_Click(System::Object^ sender, System::EventArgs^ e) {
			this->salida_datos->Text = "";
			
			//Almacenamiento del nombre insertado para la Base de Datos en la variable Base
			string Base;
			if (ComboBox_Base->SelectedItem) {
				Base = toStandardString(ComboBox_Base->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_Base->Text);

			//Almacenamiento del nombre insertado para la colección en la variable NuevaColeccion
			string Coleccion;
			if (ComboBox_Coleccion->SelectedItem) {
				Coleccion = toStandardString(ComboBox_Coleccion->SelectedItem->ToString());
			}
			else Coleccion = toStandardString(ComboBox_Coleccion->Text);

			if (Base.empty() || Coleccion.empty()) MessageBox::Show("Por favor, seleccione una Base de Datos y una colección");
			else {
				//Función equivalente al Botón Buscar por colección
				vector <string> documentos_coleccion = BuscarDocumentosColeccion(Base, Coleccion);

				//	Separación del contenido del documento BSON en líneas para poder mostrar por pantalla
				for (int i = 0; i < documentos_coleccion.size(); i++) {
					string salida = documentos_coleccion[i];
					if (strcmp(salida.c_str(), "findeldocumento") != 0) {
						String^ SalidaPantalla = gcnew String(salida.c_str());
						this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n" + SalidaPantalla);
					}
					else this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n");
				}
			}
		}


	//Botón buscar por nombre
		private: System::Void Boton_Buscador_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Limpiamos lo que haya en pantalla de consultas anteriores
			this->salida_datos->Text = "";
			
			string Base;
			if (ComboBox_NombreBase->SelectedItem) {
				Base = toStandardString(ComboBox_NombreBase->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_NombreBase->Text);
			
			string Coleccion;
			if (ComboBox_NombreColeccion->SelectedItem) {
				Coleccion = toStandardString(ComboBox_NombreColeccion->SelectedItem->ToString());
			}
			else Coleccion = toStandardString(ComboBox_NombreColeccion->Text);

			string consulta;
			if (ComboBox_Nombre->SelectedItem) {
				consulta = toStandardString(ComboBox_Nombre->SelectedItem->ToString());
			}
			else consulta = toStandardString(ComboBox_Nombre->Text);

			//Banderas para MessageBox
			int ExistenciaBase = ComprobacionExistenciaBase(consulta);
			int ExistenciaColeccion = ComprobacionExistenciaColeccion(consulta);

			//Función equivalente al Botón Buscar por nombre
			vector <string> documentos_consulta = BuscarDocumento(Base, Coleccion, consulta);

			//	Buscamos una base de datos que coincida con el tema introducido
			if (ExistenciaBase == 1) {
				MessageBox::Show("La Base de Conocimiento para robots sociales dispone de una Base de Datos que coincide con el tema consultado");
			}
			//	Buscamos una colección que coincida con el tema introducido
			else {
				if (ExistenciaColeccion == 0) {
					//	Separación del contenido del documento BSON en líneas para poder mostrar por pantalla
					for (int i = 0; i < documentos_consulta.size(); i++) {
						string salida = documentos_consulta[i];
						if (strcmp(salida.c_str(), "findeldocumento") != 0) {
							String^ SalidaPantalla = gcnew String(salida.c_str());
							this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n" + SalidaPantalla);
						}
						else this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n");
					}
				}
				else MessageBox::Show("La Base de Conocimiento para robots sociales dispone de una colección que coincide con el tema consultado");
			}
		}


	//Botón buscar por atributo
		private: System::Void Boton_ConsultarAtributo_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Limpiamos lo que haya en pantalla de consultas anteriores
			this->salida_datos->Text = "";

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
			
			//Función equivalente al Botón Buscar por colección
			vector <string> documentos_coincidentes = BuscarDocumentoPorAtributos(atributos);

			//	Separación del contenido del documento BSON en líneas para poder mostrar por pantalla
			for (int i = 0; i < documentos_coincidentes.size(); i++) {
				string salida = documentos_coincidentes[i];
				if (strcmp(salida.c_str(), "findeldocumento") != 0) {
					String^ SalidaPantalla = gcnew String(salida.c_str());
					this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n" + SalidaPantalla);
				}
				else this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n");
			}

		}


		private: System::Void Boton_id_Click(System::Object^ sender, System::EventArgs^ e) {
			id_introducido = toStandardString(this->TextBox_id->Text);
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::MostrarDocumentoPorID^ MostrarDocumentoPorID = gcnew BaseConocimiento::MostrarDocumentoPorID();
			MostrarDocumentoPorID->ShowDialog();
		}



};
}
