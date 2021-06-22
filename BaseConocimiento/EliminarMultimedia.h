/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentra la función equivalente al botón del formulario
#include "Botones_ArchivoMultimedia.h"


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class EliminarMultimedia : public System::Windows::Forms::Form
	{
	public:
		EliminarMultimedia(void)
		{
			InitializeComponent();
		}

	protected:
		~EliminarMultimedia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ ComboBox_TipoDocumento;
	protected:
	private: System::Windows::Forms::Label^ Label_Tipo;
	private: System::Windows::Forms::Label^ Label_NombreDocumento;

	private: System::Windows::Forms::Button^ Boton_EliminarMultimedia;
	private: System::Windows::Forms::ComboBox^ ComboBox_Filename;




	protected:

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->ComboBox_TipoDocumento = (gcnew System::Windows::Forms::ComboBox());
			this->Label_Tipo = (gcnew System::Windows::Forms::Label());
			this->Label_NombreDocumento = (gcnew System::Windows::Forms::Label());
			this->Boton_EliminarMultimedia = (gcnew System::Windows::Forms::Button());
			this->ComboBox_Filename = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// ComboBox_TipoDocumento
			// 
			this->ComboBox_TipoDocumento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ComboBox_TipoDocumento->FormattingEnabled = true;
			this->ComboBox_TipoDocumento->Location = System::Drawing::Point(268, 37);
			this->ComboBox_TipoDocumento->Name = L"ComboBox_TipoDocumento";
			this->ComboBox_TipoDocumento->Size = System::Drawing::Size(268, 28);
			this->ComboBox_TipoDocumento->TabIndex = 19;
			this->ComboBox_TipoDocumento->SelectedIndexChanged += gcnew System::EventHandler(this, &EliminarMultimedia::ComboBox_TipoDocumento_SelectedIndexChanged);
			// 
			// Label_Tipo
			// 
			this->Label_Tipo->AutoSize = true;
			this->Label_Tipo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_Tipo->Location = System::Drawing::Point(44, 40);
			this->Label_Tipo->Name = L"Label_Tipo";
			this->Label_Tipo->Size = System::Drawing::Size(164, 20);
			this->Label_Tipo->TabIndex = 20;
			this->Label_Tipo->Text = L"Tipo de documento:";
			// 
			// Label_NombreDocumento
			// 
			this->Label_NombreDocumento->AutoSize = true;
			this->Label_NombreDocumento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_NombreDocumento->Location = System::Drawing::Point(44, 99);
			this->Label_NombreDocumento->Name = L"Label_NombreDocumento";
			this->Label_NombreDocumento->Size = System::Drawing::Size(198, 20);
			this->Label_NombreDocumento->TabIndex = 21;
			this->Label_NombreDocumento->Text = L"Nombre del documento:";
			// 
			// Boton_EliminarMultimedia
			// 
			this->Boton_EliminarMultimedia->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_EliminarMultimedia->Location = System::Drawing::Point(48, 152);
			this->Boton_EliminarMultimedia->Name = L"Boton_EliminarMultimedia";
			this->Boton_EliminarMultimedia->Size = System::Drawing::Size(488, 50);
			this->Boton_EliminarMultimedia->TabIndex = 23;
			this->Boton_EliminarMultimedia->Text = L"Eliminar archivo multimedia";
			this->Boton_EliminarMultimedia->UseVisualStyleBackColor = true;
			this->Boton_EliminarMultimedia->Click += gcnew System::EventHandler(this, &EliminarMultimedia::Boton_EliminarMultimedia_Click);
			// 
			// ComboBox_Filename
			// 
			this->ComboBox_Filename->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Filename->FormattingEnabled = true;
			this->ComboBox_Filename->Location = System::Drawing::Point(268, 96);
			this->ComboBox_Filename->Name = L"ComboBox_Filename";
			this->ComboBox_Filename->Size = System::Drawing::Size(268, 28);
			this->ComboBox_Filename->TabIndex = 24;
			// 
			// EliminarMultimedia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 231);
			this->Controls->Add(this->ComboBox_Filename);
			this->Controls->Add(this->Boton_EliminarMultimedia);
			this->Controls->Add(this->Label_NombreDocumento);
			this->Controls->Add(this->Label_Tipo);
			this->Controls->Add(this->ComboBox_TipoDocumento);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"EliminarMultimedia";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ELIMINAR ARCHIVO MULTIMEDIA";
			this->Load += gcnew System::EventHandler(this, &EliminarMultimedia::EliminarMultimedia_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	//Carga ComboBox tipo de documento
		private: System::Void EliminarMultimedia_Load(System::Object^ sender, System::EventArgs^ e) {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 1) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					ComboBox_TipoDocumento->Items->Add(Base);
				}
			}
		}


	//Carga CoboBox filename
		private: System::Void ComboBox_TipoDocumento_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (ComboBox_TipoDocumento->SelectedItem) {
				Base = toStandardString(ComboBox_TipoDocumento->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_TipoDocumento->Text);

			ComboBox_Filename->Items->Clear();

			vector <string> ArchivosMultimedia_Disponibles = ListaArchivosMultimediaDisponibles(Base);
			for (int i = 0; i < ArchivosMultimedia_Disponibles.size(); i++) {
				String^ Coleccion = gcnew String(ArchivosMultimedia_Disponibles[i].c_str());
				ComboBox_Filename->Items->Add(Coleccion);
			}
		}


	private: System::Void Boton_EliminarMultimedia_Click(System::Object^ sender, System::EventArgs^ e) {
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
		
		//Función equivalente al botón eliminar archivo multimedia
		EliminarArchivoMultimedia(base, nombre);
	}


};
}
