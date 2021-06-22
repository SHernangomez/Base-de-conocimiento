/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentran las funciones que equivalen a los botones del formulario
#include "Botones_Documento.h"


extern string confianza_info;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ModificarDocumento
	/// </summary>
	public ref class ModificarDocumento : public System::Windows::Forms::Form
	{
	public:
		ModificarDocumento(void)
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
		~ModificarDocumento()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Label^ AtributoEliminar;
	private: System::Windows::Forms::Label^ Label_EliminarAtributo;



	private: System::Windows::Forms::Panel^ Panel_AñadirAtributo;
	private: System::Windows::Forms::Label^ Label_AñadirAtributo;

	private: System::Windows::Forms::Label^ AtributoAñadir;
	private: System::Windows::Forms::TextBox^ ClaveAñadir;
	private: System::Windows::Forms::TextBox^ ValorAñadir;
	private: System::Windows::Forms::Panel^ Panel_ModificarAtributo;
	private: System::Windows::Forms::Label^ Label_ModificarAtributo;
	private: System::Windows::Forms::Label^ AtributoModificar;
	private: System::Windows::Forms::TextBox^ ValorModificar;

	private: System::Windows::Forms::Panel^ Panel_EliminarAtributo;






	private: System::Windows::Forms::Button^ Boton_AñadirAtributo;
	private: System::Windows::Forms::Button^ Boton_ModificarAtributo;
	private: System::Windows::Forms::Button^ Boton_EliminarAtributo;
	private: System::Windows::Forms::TextBox^ salida_datos;
	private: System::Windows::Forms::Panel^ Panel_Nombre;

	private: System::Windows::Forms::ComboBox^ ComboBox_Nombre;
	private: System::Windows::Forms::ComboBox^ ComboBox_NombreBase;
	private: System::Windows::Forms::ComboBox^ ComboBox_NombreColeccion;
	private: System::Windows::Forms::Button^ Boton_Buscador;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ Label_nombre;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ ClaveModificar;
	private: System::Windows::Forms::ComboBox^ ClaveEliminar;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModificarDocumento::typeid));
			this->AtributoEliminar = (gcnew System::Windows::Forms::Label());
			this->Label_EliminarAtributo = (gcnew System::Windows::Forms::Label());
			this->Panel_AñadirAtributo = (gcnew System::Windows::Forms::Panel());
			this->Boton_AñadirAtributo = (gcnew System::Windows::Forms::Button());
			this->Label_AñadirAtributo = (gcnew System::Windows::Forms::Label());
			this->AtributoAñadir = (gcnew System::Windows::Forms::Label());
			this->ClaveAñadir = (gcnew System::Windows::Forms::TextBox());
			this->ValorAñadir = (gcnew System::Windows::Forms::TextBox());
			this->Panel_ModificarAtributo = (gcnew System::Windows::Forms::Panel());
			this->ClaveModificar = (gcnew System::Windows::Forms::ComboBox());
			this->Boton_ModificarAtributo = (gcnew System::Windows::Forms::Button());
			this->Label_ModificarAtributo = (gcnew System::Windows::Forms::Label());
			this->AtributoModificar = (gcnew System::Windows::Forms::Label());
			this->ValorModificar = (gcnew System::Windows::Forms::TextBox());
			this->Panel_EliminarAtributo = (gcnew System::Windows::Forms::Panel());
			this->ClaveEliminar = (gcnew System::Windows::Forms::ComboBox());
			this->Boton_EliminarAtributo = (gcnew System::Windows::Forms::Button());
			this->salida_datos = (gcnew System::Windows::Forms::TextBox());
			this->Panel_Nombre = (gcnew System::Windows::Forms::Panel());
			this->ComboBox_Nombre = (gcnew System::Windows::Forms::ComboBox());
			this->ComboBox_NombreBase = (gcnew System::Windows::Forms::ComboBox());
			this->ComboBox_NombreColeccion = (gcnew System::Windows::Forms::ComboBox());
			this->Boton_Buscador = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Label_nombre = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Panel_AñadirAtributo->SuspendLayout();
			this->Panel_ModificarAtributo->SuspendLayout();
			this->Panel_EliminarAtributo->SuspendLayout();
			this->Panel_Nombre->SuspendLayout();
			this->SuspendLayout();
			// 
			// AtributoEliminar
			// 
			this->AtributoEliminar->AutoSize = true;
			this->AtributoEliminar->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AtributoEliminar->Location = System::Drawing::Point(18, 47);
			this->AtributoEliminar->Name = L"AtributoEliminar";
			this->AtributoEliminar->Size = System::Drawing::Size(74, 19);
			this->AtributoEliminar->TabIndex = 87;
			this->AtributoEliminar->Text = L"Atributo:";
			// 
			// Label_EliminarAtributo
			// 
			this->Label_EliminarAtributo->AutoSize = true;
			this->Label_EliminarAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Label_EliminarAtributo->Location = System::Drawing::Point(18, 4);
			this->Label_EliminarAtributo->Name = L"Label_EliminarAtributo";
			this->Label_EliminarAtributo->Size = System::Drawing::Size(129, 16);
			this->Label_EliminarAtributo->TabIndex = 86;
			this->Label_EliminarAtributo->Text = L"Eliminar atributo";
			// 
			// Panel_AñadirAtributo
			// 
			this->Panel_AñadirAtributo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Panel_AñadirAtributo->Controls->Add(this->Boton_AñadirAtributo);
			this->Panel_AñadirAtributo->Controls->Add(this->Label_AñadirAtributo);
			this->Panel_AñadirAtributo->Controls->Add(this->AtributoAñadir);
			this->Panel_AñadirAtributo->Controls->Add(this->ClaveAñadir);
			this->Panel_AñadirAtributo->Controls->Add(this->ValorAñadir);
			this->Panel_AñadirAtributo->Location = System::Drawing::Point(43, 151);
			this->Panel_AñadirAtributo->Name = L"Panel_AñadirAtributo";
			this->Panel_AñadirAtributo->Size = System::Drawing::Size(381, 153);
			this->Panel_AñadirAtributo->TabIndex = 99;
			// 
			// Boton_AñadirAtributo
			// 
			this->Boton_AñadirAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_AñadirAtributo->Location = System::Drawing::Point(22, 76);
			this->Boton_AñadirAtributo->Name = L"Boton_AñadirAtributo";
			this->Boton_AñadirAtributo->Size = System::Drawing::Size(338, 52);
			this->Boton_AñadirAtributo->TabIndex = 110;
			this->Boton_AñadirAtributo->Text = L"Añadir atributo";
			this->Boton_AñadirAtributo->UseVisualStyleBackColor = true;
			this->Boton_AñadirAtributo->Click += gcnew System::EventHandler(this, &ModificarDocumento::Boton_AñadirAtributo_Click);
			// 
			// Label_AñadirAtributo
			// 
			this->Label_AñadirAtributo->AutoSize = true;
			this->Label_AñadirAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_AñadirAtributo->Location = System::Drawing::Point(18, 4);
			this->Label_AñadirAtributo->Name = L"Label_AñadirAtributo";
			this->Label_AñadirAtributo->Size = System::Drawing::Size(113, 16);
			this->Label_AñadirAtributo->TabIndex = 100;
			this->Label_AñadirAtributo->Text = L"Añadir atributo";
			// 
			// AtributoAñadir
			// 
			this->AtributoAñadir->AutoSize = true;
			this->AtributoAñadir->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AtributoAñadir->Location = System::Drawing::Point(18, 48);
			this->AtributoAñadir->Name = L"AtributoAñadir";
			this->AtributoAñadir->Size = System::Drawing::Size(74, 19);
			this->AtributoAñadir->TabIndex = 101;
			this->AtributoAñadir->Text = L"Atributo:";
			// 
			// ClaveAñadir
			// 
			this->ClaveAñadir->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClaveAñadir->Location = System::Drawing::Point(102, 45);
			this->ClaveAñadir->Name = L"ClaveAñadir";
			this->ClaveAñadir->Size = System::Drawing::Size(124, 25);
			this->ClaveAñadir->TabIndex = 102;
			// 
			// ValorAñadir
			// 
			this->ValorAñadir->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ValorAñadir->Location = System::Drawing::Point(232, 45);
			this->ValorAñadir->Name = L"ValorAñadir";
			this->ValorAñadir->Size = System::Drawing::Size(127, 25);
			this->ValorAñadir->TabIndex = 103;
			// 
			// Panel_ModificarAtributo
			// 
			this->Panel_ModificarAtributo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Panel_ModificarAtributo->Controls->Add(this->ClaveModificar);
			this->Panel_ModificarAtributo->Controls->Add(this->Boton_ModificarAtributo);
			this->Panel_ModificarAtributo->Controls->Add(this->Label_ModificarAtributo);
			this->Panel_ModificarAtributo->Controls->Add(this->AtributoModificar);
			this->Panel_ModificarAtributo->Controls->Add(this->ValorModificar);
			this->Panel_ModificarAtributo->Location = System::Drawing::Point(43, 342);
			this->Panel_ModificarAtributo->Name = L"Panel_ModificarAtributo";
			this->Panel_ModificarAtributo->Size = System::Drawing::Size(381, 153);
			this->Panel_ModificarAtributo->TabIndex = 100;
			// 
			// ClaveModificar
			// 
			this->ClaveModificar->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClaveModificar->FormattingEnabled = true;
			this->ClaveModificar->Location = System::Drawing::Point(102, 42);
			this->ClaveModificar->Name = L"ClaveModificar";
			this->ClaveModificar->Size = System::Drawing::Size(124, 28);
			this->ClaveModificar->TabIndex = 136;
			this->ClaveModificar->Click += gcnew System::EventHandler(this, &ModificarDocumento::ClaveModificar_Click);
			// 
			// Boton_ModificarAtributo
			// 
			this->Boton_ModificarAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_ModificarAtributo->Location = System::Drawing::Point(23, 74);
			this->Boton_ModificarAtributo->Name = L"Boton_ModificarAtributo";
			this->Boton_ModificarAtributo->Size = System::Drawing::Size(338, 52);
			this->Boton_ModificarAtributo->TabIndex = 112;
			this->Boton_ModificarAtributo->Text = L"Modificar atributo";
			this->Boton_ModificarAtributo->UseVisualStyleBackColor = true;
			this->Boton_ModificarAtributo->Click += gcnew System::EventHandler(this, &ModificarDocumento::Boton_ModificarAtributo_Click);
			// 
			// Label_ModificarAtributo
			// 
			this->Label_ModificarAtributo->AutoSize = true;
			this->Label_ModificarAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Label_ModificarAtributo->Location = System::Drawing::Point(18, 4);
			this->Label_ModificarAtributo->Name = L"Label_ModificarAtributo";
			this->Label_ModificarAtributo->Size = System::Drawing::Size(134, 16);
			this->Label_ModificarAtributo->TabIndex = 101;
			this->Label_ModificarAtributo->Text = L"Modificar atributo";
			// 
			// AtributoModificar
			// 
			this->AtributoModificar->AutoSize = true;
			this->AtributoModificar->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AtributoModificar->Location = System::Drawing::Point(19, 46);
			this->AtributoModificar->Name = L"AtributoModificar";
			this->AtributoModificar->Size = System::Drawing::Size(74, 19);
			this->AtributoModificar->TabIndex = 102;
			this->AtributoModificar->Text = L"Atributo:";
			// 
			// ValorModificar
			// 
			this->ValorModificar->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ValorModificar->Location = System::Drawing::Point(233, 43);
			this->ValorModificar->Name = L"ValorModificar";
			this->ValorModificar->Size = System::Drawing::Size(127, 25);
			this->ValorModificar->TabIndex = 104;
			// 
			// Panel_EliminarAtributo
			// 
			this->Panel_EliminarAtributo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Panel_EliminarAtributo->Controls->Add(this->ClaveEliminar);
			this->Panel_EliminarAtributo->Controls->Add(this->Boton_EliminarAtributo);
			this->Panel_EliminarAtributo->Controls->Add(this->Label_EliminarAtributo);
			this->Panel_EliminarAtributo->Controls->Add(this->AtributoEliminar);
			this->Panel_EliminarAtributo->Location = System::Drawing::Point(43, 532);
			this->Panel_EliminarAtributo->Name = L"Panel_EliminarAtributo";
			this->Panel_EliminarAtributo->Size = System::Drawing::Size(381, 149);
			this->Panel_EliminarAtributo->TabIndex = 108;
			// 
			// ClaveEliminar
			// 
			this->ClaveEliminar->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClaveEliminar->FormattingEnabled = true;
			this->ClaveEliminar->Location = System::Drawing::Point(102, 43);
			this->ClaveEliminar->Name = L"ClaveEliminar";
			this->ClaveEliminar->Size = System::Drawing::Size(255, 28);
			this->ClaveEliminar->TabIndex = 137;
			this->ClaveEliminar->Click += gcnew System::EventHandler(this, &ModificarDocumento::ClaveEliminar_Click);
			// 
			// Boton_EliminarAtributo
			// 
			this->Boton_EliminarAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_EliminarAtributo->Location = System::Drawing::Point(19, 75);
			this->Boton_EliminarAtributo->Name = L"Boton_EliminarAtributo";
			this->Boton_EliminarAtributo->Size = System::Drawing::Size(338, 52);
			this->Boton_EliminarAtributo->TabIndex = 114;
			this->Boton_EliminarAtributo->Text = L"Eliminar atributo";
			this->Boton_EliminarAtributo->UseVisualStyleBackColor = true;
			this->Boton_EliminarAtributo->Click += gcnew System::EventHandler(this, &ModificarDocumento::Boton_EliminarAtributo_Click);
			// 
			// salida_datos
			// 
			this->salida_datos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->salida_datos->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->salida_datos->Location = System::Drawing::Point(450, 26);
			this->salida_datos->Multiline = true;
			this->salida_datos->Name = L"salida_datos";
			this->salida_datos->ReadOnly = true;
			this->salida_datos->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->salida_datos->Size = System::Drawing::Size(504, 655);
			this->salida_datos->TabIndex = 109;
			// 
			// Panel_Nombre
			// 
			this->Panel_Nombre->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Panel_Nombre->Controls->Add(this->ComboBox_Nombre);
			this->Panel_Nombre->Controls->Add(this->ComboBox_NombreBase);
			this->Panel_Nombre->Controls->Add(this->ComboBox_NombreColeccion);
			this->Panel_Nombre->Controls->Add(this->Boton_Buscador);
			this->Panel_Nombre->Controls->Add(this->label1);
			this->Panel_Nombre->Controls->Add(this->Label_nombre);
			this->Panel_Nombre->Controls->Add(this->label2);
			this->Panel_Nombre->Location = System::Drawing::Point(43, 26);
			this->Panel_Nombre->Name = L"Panel_Nombre";
			this->Panel_Nombre->Size = System::Drawing::Size(381, 119);
			this->Panel_Nombre->TabIndex = 128;
			// 
			// ComboBox_Nombre
			// 
			this->ComboBox_Nombre->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Nombre->FormattingEnabled = true;
			this->ComboBox_Nombre->Location = System::Drawing::Point(16, 71);
			this->ComboBox_Nombre->Name = L"ComboBox_Nombre";
			this->ComboBox_Nombre->Size = System::Drawing::Size(274, 28);
			this->ComboBox_Nombre->TabIndex = 135;
			this->ComboBox_Nombre->SelectedIndexChanged += gcnew System::EventHandler(this, &ModificarDocumento::ComboBox_Nombre_SelectedIndexChanged);
			// 
			// ComboBox_NombreBase
			// 
			this->ComboBox_NombreBase->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_NombreBase->FormattingEnabled = true;
			this->ComboBox_NombreBase->Location = System::Drawing::Point(49, 37);
			this->ComboBox_NombreBase->Name = L"ComboBox_NombreBase";
			this->ComboBox_NombreBase->Size = System::Drawing::Size(104, 28);
			this->ComboBox_NombreBase->TabIndex = 133;
			this->ComboBox_NombreBase->SelectedIndexChanged += gcnew System::EventHandler(this, &ModificarDocumento::ComboBox_NombreBase_SelectedIndexChanged);
			// 
			// ComboBox_NombreColeccion
			// 
			this->ComboBox_NombreColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ComboBox_NombreColeccion->FormattingEnabled = true;
			this->ComboBox_NombreColeccion->Location = System::Drawing::Point(188, 37);
			this->ComboBox_NombreColeccion->Name = L"ComboBox_NombreColeccion";
			this->ComboBox_NombreColeccion->Size = System::Drawing::Size(102, 28);
			this->ComboBox_NombreColeccion->TabIndex = 134;
			this->ComboBox_NombreColeccion->SelectedIndexChanged += gcnew System::EventHandler(this, &ModificarDocumento::ComboBox_NombreColeccion_SelectedIndexChanged);
			// 
			// Boton_Buscador
			// 
			this->Boton_Buscador->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Boton_Buscador->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_Buscador.Image")));
			this->Boton_Buscador->Location = System::Drawing::Point(296, 37);
			this->Boton_Buscador->Name = L"Boton_Buscador";
			this->Boton_Buscador->Size = System::Drawing::Size(50, 62);
			this->Boton_Buscador->TabIndex = 129;
			this->Boton_Buscador->UseVisualStyleBackColor = false;
			this->Boton_Buscador->Click += gcnew System::EventHandler(this, &ModificarDocumento::Boton_Buscador_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(163, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 19);
			this->label1->TabIndex = 132;
			this->label1->Text = L"C:";
			// 
			// Label_nombre
			// 
			this->Label_nombre->AutoSize = true;
			this->Label_nombre->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_nombre->Location = System::Drawing::Point(21, 5);
			this->Label_nombre->Name = L"Label_nombre";
			this->Label_nombre->Size = System::Drawing::Size(61, 16);
			this->Label_nombre->TabIndex = 130;
			this->Label_nombre->Text = L"Nombre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 19);
			this->label2->TabIndex = 131;
			this->label2->Text = L"BD:";
			// 
			// ModificarDocumento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 711);
			this->Controls->Add(this->Panel_Nombre);
			this->Controls->Add(this->salida_datos);
			this->Controls->Add(this->Panel_EliminarAtributo);
			this->Controls->Add(this->Panel_ModificarAtributo);
			this->Controls->Add(this->Panel_AñadirAtributo);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"ModificarDocumento";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MODIFICAR DOCUMENTO";
			this->Load += gcnew System::EventHandler(this, &ModificarDocumento::ModificarDocumento_Load);
			this->Panel_AñadirAtributo->ResumeLayout(false);
			this->Panel_AñadirAtributo->PerformLayout();
			this->Panel_ModificarAtributo->ResumeLayout(false);
			this->Panel_ModificarAtributo->PerformLayout();
			this->Panel_EliminarAtributo->ResumeLayout(false);
			this->Panel_EliminarAtributo->PerformLayout();
			this->Panel_Nombre->ResumeLayout(false);
			this->Panel_Nombre->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	//Carga de los nombres de las Bases de Datos disponibles en ComboBox_NombreBase
		private: System::Void ModificarDocumento_Load(System::Object^ sender, System::EventArgs^ e) {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 0) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					ComboBox_NombreBase->Items->Add(Base);
				}
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


	//Carga de los atributos disponibles en ClaveModificar y ClaveEliminar
		private: System::Void ComboBox_Nombre_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
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

			string nombre;
			if (ComboBox_Nombre->SelectedItem) {
				nombre = toStandardString(ComboBox_Nombre->SelectedItem->ToString());
			}
			else nombre = toStandardString(ComboBox_Nombre->Text);

			ClaveModificar->Items->Clear();
			ClaveEliminar->Items->Clear();

			vector <string> Atributos_Disponibles = ListaAtributosDisponibles(Base, Coleccion, nombre);
			for (int i = 0; i < Atributos_Disponibles.size(); i++) {
				String^ NombreAtributo = gcnew String(Atributos_Disponibles[i].c_str());
				ClaveModificar->Items->Add(NombreAtributo);
				ClaveEliminar->Items->Add(NombreAtributo);
			}
		}


		private: System::Void ClaveModificar_Click(System::Object^ sender, System::EventArgs^ e) {
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

			string nombre;
			if (ComboBox_Nombre->SelectedItem) {
				nombre = toStandardString(ComboBox_Nombre->SelectedItem->ToString());
			}
			else nombre = toStandardString(ComboBox_Nombre->Text);

			ClaveModificar->Items->Clear();

			vector <string> Atributos_Disponibles = ListaAtributosDisponibles(Base, Coleccion, nombre);
			for (int i = 0; i < Atributos_Disponibles.size(); i++) {
				String^ NombreAtributo = gcnew String(Atributos_Disponibles[i].c_str());
				ClaveModificar->Items->Add(NombreAtributo);
			}
		}


		private: System::Void ClaveEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
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

			string nombre;
			if (ComboBox_Nombre->SelectedItem) {
				nombre = toStandardString(ComboBox_Nombre->SelectedItem->ToString());
			}
			else nombre = toStandardString(ComboBox_Nombre->Text);

			ClaveEliminar->Items->Clear();

			vector <string> Atributos_Disponibles = ListaAtributosDisponibles(Base, Coleccion, nombre);
			for (int i = 0; i < Atributos_Disponibles.size(); i++) {
				String^ NombreAtributo = gcnew String(Atributos_Disponibles[i].c_str());
				ClaveEliminar->Items->Add(NombreAtributo);
			}
		}


	//Botón buscador
		private: System::Void Boton_Buscador_Click(System::Object^ sender, System::EventArgs^ e) {
			// Limpiamos lo que haya en pantalla de consultas anteriores
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


	//Botón Añadir Atributo
		private: System::Void Boton_AñadirAtributo_Click(System::Object^ sender, System::EventArgs^ e) {
			this->salida_datos->Text = "";
			string clave = toStandardString(this->ClaveAñadir->Text);
			string valor = toStandardString(this->ValorAñadir->Text);
			string base;
			if (ComboBox_NombreBase->SelectedItem) {
				base = toStandardString(ComboBox_NombreBase->SelectedItem->ToString());
			}
			else base = toStandardString(ComboBox_NombreBase->Text);

			string coleccion;
			if (ComboBox_NombreColeccion->SelectedItem) {
				coleccion = toStandardString(ComboBox_NombreColeccion->SelectedItem->ToString());
			}
			else coleccion = toStandardString(ComboBox_NombreColeccion->Text);

			string nombre;
			if (ComboBox_Nombre->SelectedItem) {
				nombre = toStandardString(ComboBox_Nombre->SelectedItem->ToString());
			}
			else nombre = toStandardString(ComboBox_Nombre->Text);

			if (nombre.empty()) MessageBox::Show("Por favor, introduzca un nombre en el espacio reservado para ello.");
			else if((clave.empty()) || (valor.empty())) MessageBox::Show("Por favor, rellene los campos del atributo que desea añadir.");
			else {
				//Función equivalente al botón Añadir Atributo
				bool success = AñadirAtributoADocumento(nombre, clave, valor, base, coleccion, confianza_info);

				if (success) {
					vector <string> documento_actualizado = BuscarDocumento(base, coleccion, nombre);
					//	Separación del contenido del documento BSON en líneas para poder mostrar por pantalla
					for (int i = 0; i < documento_actualizado.size(); i++) {
						string salida = documento_actualizado[i];
						if (strcmp(salida.c_str(), "findeldocumento") != 0) {
							String^ SalidaPantalla = gcnew String(salida.c_str());
							this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n" + SalidaPantalla);
						}
						else this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n");
					}
					this->ClaveAñadir->Text = "";
					this->ValorAñadir->Text = "";
				}
				else {
					MessageBox::Show("La operación no se ha podido completar con éxito");
				}
			}
		}


	//Botón Modificar Atributo
		private: System::Void Boton_ModificarAtributo_Click(System::Object^ sender, System::EventArgs^ e) {
			this->salida_datos->Text = "";
			string clave;
			if (ClaveModificar->SelectedItem) {
				clave = toStandardString(this->ClaveModificar->SelectedItem->ToString());
			}
			else clave = toStandardString(this->ClaveModificar->Text);
			string valor = toStandardString(this->ValorModificar->Text);
			string base;
			if (ComboBox_NombreBase->SelectedItem) {
				base = toStandardString(ComboBox_NombreBase->SelectedItem->ToString());
			}
			else base = toStandardString(ComboBox_NombreBase->Text);

			string coleccion;
			if (ComboBox_NombreColeccion->SelectedItem) {
				coleccion = toStandardString(ComboBox_NombreColeccion->SelectedItem->ToString());
			}
			else coleccion = toStandardString(ComboBox_NombreColeccion->Text);

			string nombre;
			if (ComboBox_Nombre->SelectedItem) {
				nombre = toStandardString(ComboBox_Nombre->SelectedItem->ToString());
			}
			else nombre = toStandardString(ComboBox_Nombre->Text);

			if (nombre.empty()) MessageBox::Show("Por favor, introduzca un nombre en el espacio reservado para ello.");
			else if ((clave.empty()) || (valor.empty())) MessageBox::Show("Por favor, rellene los campos del atributo que desea modificar.");
			else {
				//Función equivalente al botón Modificar Atributo
				ModificarAtributoDocumento(nombre, clave, valor, base, coleccion, confianza_info);

				vector <string> documento_actualizado = BuscarDocumento(base, coleccion, nombre);
				//	Separación del contenido del documento BSON en líneas para poder mostrar por pantalla
				for (int i = 0; i < documento_actualizado.size(); i++) {
					string salida = documento_actualizado[i];
					if (strcmp(salida.c_str(), "findeldocumento") != 0) {
						String^ SalidaPantalla = gcnew String(salida.c_str());
						this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n" + SalidaPantalla);
					}
					else this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n");
				}
			}
			
		}


	//Botón Eliminar Atributo
		private: System::Void Boton_EliminarAtributo_Click(System::Object^ sender, System::EventArgs^ e) {
			this->salida_datos->Text = "";
			string clave;
			if (ClaveEliminar->SelectedItem) {
				clave = toStandardString(this->ClaveEliminar->SelectedItem->ToString());
			}
			else clave = toStandardString(this->ClaveEliminar->Text);
			string base;
			if (ComboBox_NombreBase->SelectedItem) {
				base = toStandardString(ComboBox_NombreBase->SelectedItem->ToString());
			}
			else base = toStandardString(ComboBox_NombreBase->Text);

			string coleccion;
			if (ComboBox_NombreColeccion->SelectedItem) {
				coleccion = toStandardString(ComboBox_NombreColeccion->SelectedItem->ToString());
			}
			else coleccion = toStandardString(ComboBox_NombreColeccion->Text);

			string nombre;
			if (ComboBox_Nombre->SelectedItem) {
				nombre = toStandardString(ComboBox_Nombre->SelectedItem->ToString());
			}
			else nombre = toStandardString(ComboBox_Nombre->Text);

			if (nombre.empty()) MessageBox::Show("Por favor, introduzca un nombre en el espacio reservado para ello.");
			else if (clave.empty()) MessageBox::Show("Por favor, introduzca el nombre del atributo que desea eliminar.");
			else {

				//Función equivalente al botón Modificar Atributo
				EliminarAtributoDocumento(nombre, clave, base, coleccion);

				vector <string> documento_actualizado = BuscarDocumento(base, coleccion, nombre);
				//	Separación del contenido del documento BSON en líneas para poder mostrar por pantalla
				for (int i = 0; i < documento_actualizado.size(); i++) {
					string salida = documento_actualizado[i];
					if (strcmp(salida.c_str(), "findeldocumento") != 0) {
						String^ SalidaPantalla = gcnew String(salida.c_str());
						this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n" + SalidaPantalla);
					}
					else this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n");
				}
			}
		}


};
}
