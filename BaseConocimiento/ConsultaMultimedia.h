/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentra la función equivalente al botón del formulario
#include "Botones_ArchivoMultimedia.h"


extern string ruta_descarga;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class ConsultaMultimedia : public System::Windows::Forms::Form
	{
	public:
		ConsultaMultimedia(void)
		{
			InitializeComponent();
		}

	protected:
		~ConsultaMultimedia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ GroupBox_ID;
	protected:
	private: System::Windows::Forms::GroupBox^ GroupBox_Nombre;
	private: System::Windows::Forms::Button^ Boton_ConsultarMultimediaID;

	private: System::Windows::Forms::TextBox^ TextBox_ID;

	private: System::Windows::Forms::Label^ Label_NombreDocumento;
	private: System::Windows::Forms::Label^ Label_Tipo;
	private: System::Windows::Forms::ComboBox^ ComboBox_TipoDocumento;
	private: System::Windows::Forms::Button^ Boton_ConsultarMultimediaNombre;
	private: System::Windows::Forms::FolderBrowserDialog^ CuadroDeDialogoCarpeta;
	private: System::Windows::Forms::ComboBox^ ComboBox_Filename;



	protected:

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ConsultaMultimedia::typeid));
			this->GroupBox_ID = (gcnew System::Windows::Forms::GroupBox());
			this->Boton_ConsultarMultimediaID = (gcnew System::Windows::Forms::Button());
			this->TextBox_ID = (gcnew System::Windows::Forms::TextBox());
			this->GroupBox_Nombre = (gcnew System::Windows::Forms::GroupBox());
			this->ComboBox_Filename = (gcnew System::Windows::Forms::ComboBox());
			this->Boton_ConsultarMultimediaNombre = (gcnew System::Windows::Forms::Button());
			this->Label_NombreDocumento = (gcnew System::Windows::Forms::Label());
			this->Label_Tipo = (gcnew System::Windows::Forms::Label());
			this->ComboBox_TipoDocumento = (gcnew System::Windows::Forms::ComboBox());
			this->CuadroDeDialogoCarpeta = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->GroupBox_ID->SuspendLayout();
			this->GroupBox_Nombre->SuspendLayout();
			this->SuspendLayout();
			// 
			// GroupBox_ID
			// 
			this->GroupBox_ID->Controls->Add(this->Boton_ConsultarMultimediaID);
			this->GroupBox_ID->Controls->Add(this->TextBox_ID);
			this->GroupBox_ID->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBox_ID->Location = System::Drawing::Point(23, 22);
			this->GroupBox_ID->Name = L"GroupBox_ID";
			this->GroupBox_ID->Size = System::Drawing::Size(485, 84);
			this->GroupBox_ID->TabIndex = 0;
			this->GroupBox_ID->TabStop = false;
			this->GroupBox_ID->Text = L"Consultar por ID";
			// 
			// Boton_ConsultarMultimediaID
			// 
			this->Boton_ConsultarMultimediaID->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Boton_ConsultarMultimediaID->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_ConsultarMultimediaID.Image")));
			this->Boton_ConsultarMultimediaID->Location = System::Drawing::Point(410, 33);
			this->Boton_ConsultarMultimediaID->Name = L"Boton_ConsultarMultimediaID";
			this->Boton_ConsultarMultimediaID->Size = System::Drawing::Size(51, 28);
			this->Boton_ConsultarMultimediaID->TabIndex = 78;
			this->Boton_ConsultarMultimediaID->UseVisualStyleBackColor = false;
			this->Boton_ConsultarMultimediaID->Click += gcnew System::EventHandler(this, &ConsultaMultimedia::Boton_ConsultarMultimediaID_Click);
			// 
			// TextBox_ID
			// 
			this->TextBox_ID->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TextBox_ID->Location = System::Drawing::Point(27, 34);
			this->TextBox_ID->Name = L"TextBox_ID";
			this->TextBox_ID->Size = System::Drawing::Size(387, 26);
			this->TextBox_ID->TabIndex = 77;
			// 
			// GroupBox_Nombre
			// 
			this->GroupBox_Nombre->Controls->Add(this->ComboBox_Filename);
			this->GroupBox_Nombre->Controls->Add(this->Boton_ConsultarMultimediaNombre);
			this->GroupBox_Nombre->Controls->Add(this->Label_NombreDocumento);
			this->GroupBox_Nombre->Controls->Add(this->Label_Tipo);
			this->GroupBox_Nombre->Controls->Add(this->ComboBox_TipoDocumento);
			this->GroupBox_Nombre->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBox_Nombre->Location = System::Drawing::Point(23, 123);
			this->GroupBox_Nombre->Name = L"GroupBox_Nombre";
			this->GroupBox_Nombre->Size = System::Drawing::Size(485, 199);
			this->GroupBox_Nombre->TabIndex = 1;
			this->GroupBox_Nombre->TabStop = false;
			this->GroupBox_Nombre->Text = L"Consultar por nombre";
			// 
			// ComboBox_Filename
			// 
			this->ComboBox_Filename->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Filename->FormattingEnabled = true;
			this->ComboBox_Filename->Location = System::Drawing::Point(193, 82);
			this->ComboBox_Filename->Name = L"ComboBox_Filename";
			this->ComboBox_Filename->Size = System::Drawing::Size(268, 28);
			this->ComboBox_Filename->TabIndex = 28;
			// 
			// Boton_ConsultarMultimediaNombre
			// 
			this->Boton_ConsultarMultimediaNombre->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_ConsultarMultimediaNombre->Location = System::Drawing::Point(27, 126);
			this->Boton_ConsultarMultimediaNombre->Name = L"Boton_ConsultarMultimediaNombre";
			this->Boton_ConsultarMultimediaNombre->Size = System::Drawing::Size(434, 50);
			this->Boton_ConsultarMultimediaNombre->TabIndex = 27;
			this->Boton_ConsultarMultimediaNombre->Text = L"Consultar";
			this->Boton_ConsultarMultimediaNombre->UseVisualStyleBackColor = true;
			this->Boton_ConsultarMultimediaNombre->Click += gcnew System::EventHandler(this, &ConsultaMultimedia::Boton_ConsultarMultimediaNombre_Click);
			// 
			// Label_NombreDocumento
			// 
			this->Label_NombreDocumento->AutoSize = true;
			this->Label_NombreDocumento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_NombreDocumento->Location = System::Drawing::Point(23, 85);
			this->Label_NombreDocumento->Name = L"Label_NombreDocumento";
			this->Label_NombreDocumento->Size = System::Drawing::Size(76, 20);
			this->Label_NombreDocumento->TabIndex = 25;
			this->Label_NombreDocumento->Text = L"Nombre:";
			// 
			// Label_Tipo
			// 
			this->Label_Tipo->AutoSize = true;
			this->Label_Tipo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_Tipo->Location = System::Drawing::Point(23, 42);
			this->Label_Tipo->Name = L"Label_Tipo";
			this->Label_Tipo->Size = System::Drawing::Size(164, 20);
			this->Label_Tipo->TabIndex = 24;
			this->Label_Tipo->Text = L"Tipo de documento:";
			// 
			// ComboBox_TipoDocumento
			// 
			this->ComboBox_TipoDocumento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ComboBox_TipoDocumento->FormattingEnabled = true;
			this->ComboBox_TipoDocumento->Location = System::Drawing::Point(193, 39);
			this->ComboBox_TipoDocumento->Name = L"ComboBox_TipoDocumento";
			this->ComboBox_TipoDocumento->Size = System::Drawing::Size(268, 28);
			this->ComboBox_TipoDocumento->TabIndex = 23;
			this->ComboBox_TipoDocumento->SelectedIndexChanged += gcnew System::EventHandler(this, &ConsultaMultimedia::ComboBox_TipoDocumento_SelectedIndexChanged);
			// 
			// ConsultaMultimedia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 341);
			this->Controls->Add(this->GroupBox_Nombre);
			this->Controls->Add(this->GroupBox_ID);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"ConsultaMultimedia";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CONSULTAR ARCHIVO MULTIMEDIA";
			this->Load += gcnew System::EventHandler(this, &ConsultaMultimedia::ConsultaMultimedia_Load);
			this->GroupBox_ID->ResumeLayout(false);
			this->GroupBox_ID->PerformLayout();
			this->GroupBox_Nombre->ResumeLayout(false);
			this->GroupBox_Nombre->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


	//Carga ComboBox tipo de documento y ruta_descarga
		private: System::Void ConsultaMultimedia_Load(System::Object^ sender, System::EventArgs^ e) {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 1) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					ComboBox_TipoDocumento->Items->Add(Base);
				}
			}
			this->Visible = true;
			MessageBox::Show("Para visualizar un archivo multimedia, este debe ser descargado de la Base de Conocimiento.\nPor favor seleccione la carpeta en la que desea guardar el archivo");
			if (CuadroDeDialogoCarpeta->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				ruta_descarga = toStandardString(CuadroDeDialogoCarpeta->SelectedPath);
			}
		}


	//Carga ComboBox filename
		private: System::Void ComboBox_TipoDocumento_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (ComboBox_TipoDocumento->SelectedItem) {
				Base = toStandardString(ComboBox_TipoDocumento->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_TipoDocumento->Text);

			vector <string> ArchivosMultimedia_Disponibles = ListaArchivosMultimediaDisponibles(Base);
			for (int i = 0; i < ArchivosMultimedia_Disponibles.size(); i++) {
				String^ Coleccion = gcnew String(ArchivosMultimedia_Disponibles[i].c_str());
				ComboBox_Filename->Items->Add(Coleccion);
			}
		}

	
	//Botón Consultar multimedia por ID
		private: System::Void Boton_ConsultarMultimediaID_Click(System::Object^ sender, System::EventArgs^ e) {
			string id_consulta;
			id_consulta = toStandardString(TextBox_ID->Text);

			//Función equivalente al botón Consultar Multimedia por ID
			ConsultarArchivoMultimedia(id_consulta, ruta_descarga);
		}


	//Botón Consultar multimedia por nombre
		private: System::Void Boton_ConsultarMultimediaNombre_Click(System::Object^ sender, System::EventArgs^ e) {
			string base;
			if (ComboBox_TipoDocumento->SelectedItem) {
				base = toStandardString(ComboBox_TipoDocumento->SelectedItem->ToString());
			}
			else base = toStandardString(ComboBox_TipoDocumento->Text);
			string nombre;
			if (ComboBox_Filename->SelectedItem) {
				nombre = toStandardString(ComboBox_Filename->SelectedItem->ToString());
			}
			else nombre = toStandardString(ComboBox_Filename->Text);

			//Función equivalente al botón Consultar Multimedia por Nombre
			ConsultarArchivoMultimediaPorNombre(base, nombre, ruta_descarga);
		}



};
}
