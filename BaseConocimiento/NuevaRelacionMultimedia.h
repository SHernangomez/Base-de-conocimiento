/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez

#include "Botones_Documento.h"
#include "Botones_ArchivoMultimedia.h"

extern string ruta_descarga;
extern string confianza_info;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class NuevaRelacionMultimedia : public System::Windows::Forms::Form
	{
	public:
		NuevaRelacionMultimedia(void)
		{
			InitializeComponent();
		}

	protected:
		~NuevaRelacionMultimedia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ ComboBox_Coleccion_1;
	protected:
	private: System::Windows::Forms::Label^ Label_C_1;
	private: System::Windows::Forms::ComboBox^ ComboBox_Base_1;
	private: System::Windows::Forms::Label^ Label_BD_1;
	private: System::Windows::Forms::TextBox^ salida_datos;

	private: System::Windows::Forms::Button^ Boton_Doc;

	private: System::Windows::Forms::Label^ Label_Documento;






	private: System::Windows::Forms::Button^ Boton_EstablecerRelacion;
	private: System::Windows::Forms::FolderBrowserDialog^ CuadroDeDialogoCarpeta;
	private: System::Windows::Forms::GroupBox^ GroupBox_Atributo;
	private: System::Windows::Forms::GroupBox^ GroupBox_ValorAtributo;
	private: System::Windows::Forms::Button^ Boton_ConsultarMultimediaID;
	private: System::Windows::Forms::ComboBox^ ComboBox_TipoDocumento;
	private: System::Windows::Forms::Label^ Label_Tipo;
	private: System::Windows::Forms::Label^ Label_NombreDocumento;

	private: System::Windows::Forms::Label^ Label_ArchivoMultimedia;
	private: System::Windows::Forms::TextBox^ TextBox_NombreAtributo;
	private: System::Windows::Forms::Label^ Label_NombreAtributo;
	private: System::Windows::Forms::ComboBox^ ComboBox_Filename;
	private: System::Windows::Forms::ComboBox^ ComboBox_Doc_1;

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NuevaRelacionMultimedia::typeid));
			this->ComboBox_Coleccion_1 = (gcnew System::Windows::Forms::ComboBox());
			this->Label_C_1 = (gcnew System::Windows::Forms::Label());
			this->ComboBox_Base_1 = (gcnew System::Windows::Forms::ComboBox());
			this->Label_BD_1 = (gcnew System::Windows::Forms::Label());
			this->salida_datos = (gcnew System::Windows::Forms::TextBox());
			this->Boton_Doc = (gcnew System::Windows::Forms::Button());
			this->Label_Documento = (gcnew System::Windows::Forms::Label());
			this->Boton_EstablecerRelacion = (gcnew System::Windows::Forms::Button());
			this->CuadroDeDialogoCarpeta = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->GroupBox_Atributo = (gcnew System::Windows::Forms::GroupBox());
			this->GroupBox_ValorAtributo = (gcnew System::Windows::Forms::GroupBox());
			this->Boton_ConsultarMultimediaID = (gcnew System::Windows::Forms::Button());
			this->ComboBox_Filename = (gcnew System::Windows::Forms::ComboBox());
			this->ComboBox_TipoDocumento = (gcnew System::Windows::Forms::ComboBox());
			this->Label_Tipo = (gcnew System::Windows::Forms::Label());
			this->Label_ArchivoMultimedia = (gcnew System::Windows::Forms::Label());
			this->Label_NombreDocumento = (gcnew System::Windows::Forms::Label());
			this->TextBox_NombreAtributo = (gcnew System::Windows::Forms::TextBox());
			this->Label_NombreAtributo = (gcnew System::Windows::Forms::Label());
			this->ComboBox_Doc_1 = (gcnew System::Windows::Forms::ComboBox());
			this->GroupBox_Atributo->SuspendLayout();
			this->GroupBox_ValorAtributo->SuspendLayout();
			this->SuspendLayout();
			// 
			// ComboBox_Coleccion_1
			// 
			this->ComboBox_Coleccion_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Coleccion_1->FormattingEnabled = true;
			this->ComboBox_Coleccion_1->Location = System::Drawing::Point(244, 67);
			this->ComboBox_Coleccion_1->Name = L"ComboBox_Coleccion_1";
			this->ComboBox_Coleccion_1->Size = System::Drawing::Size(130, 28);
			this->ComboBox_Coleccion_1->TabIndex = 124;
			this->ComboBox_Coleccion_1->SelectedIndexChanged += gcnew System::EventHandler(this, &NuevaRelacionMultimedia::ComboBox_Coleccion_1_SelectedIndexChanged);
			// 
			// Label_C_1
			// 
			this->Label_C_1->AutoSize = true;
			this->Label_C_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_C_1->Location = System::Drawing::Point(213, 71);
			this->Label_C_1->Name = L"Label_C_1";
			this->Label_C_1->Size = System::Drawing::Size(25, 19);
			this->Label_C_1->TabIndex = 122;
			this->Label_C_1->Text = L"C:";
			// 
			// ComboBox_Base_1
			// 
			this->ComboBox_Base_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Base_1->FormattingEnabled = true;
			this->ComboBox_Base_1->Location = System::Drawing::Point(70, 67);
			this->ComboBox_Base_1->Name = L"ComboBox_Base_1";
			this->ComboBox_Base_1->Size = System::Drawing::Size(130, 28);
			this->ComboBox_Base_1->TabIndex = 123;
			this->ComboBox_Base_1->SelectedIndexChanged += gcnew System::EventHandler(this, &NuevaRelacionMultimedia::ComboBox_Base_1_SelectedIndexChanged);
			// 
			// Label_BD_1
			// 
			this->Label_BD_1->AutoSize = true;
			this->Label_BD_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_BD_1->Location = System::Drawing::Point(27, 71);
			this->Label_BD_1->Name = L"Label_BD_1";
			this->Label_BD_1->Size = System::Drawing::Size(37, 19);
			this->Label_BD_1->TabIndex = 121;
			this->Label_BD_1->Text = L"BD:";
			// 
			// salida_datos
			// 
			this->salida_datos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->salida_datos->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->salida_datos->Location = System::Drawing::Point(31, 147);
			this->salida_datos->Multiline = true;
			this->salida_datos->Name = L"salida_datos";
			this->salida_datos->ReadOnly = true;
			this->salida_datos->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->salida_datos->Size = System::Drawing::Size(441, 259);
			this->salida_datos->TabIndex = 120;
			// 
			// Boton_Doc
			// 
			this->Boton_Doc->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Boton_Doc->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_Doc.Image")));
			this->Boton_Doc->Location = System::Drawing::Point(380, 67);
			this->Boton_Doc->Name = L"Boton_Doc";
			this->Boton_Doc->Size = System::Drawing::Size(76, 60);
			this->Boton_Doc->TabIndex = 119;
			this->Boton_Doc->UseVisualStyleBackColor = false;
			this->Boton_Doc->Click += gcnew System::EventHandler(this, &NuevaRelacionMultimedia::Boton_Doc_Click);
			// 
			// Label_Documento
			// 
			this->Label_Documento->AutoSize = true;
			this->Label_Documento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_Documento->Location = System::Drawing::Point(28, 37);
			this->Label_Documento->Name = L"Label_Documento";
			this->Label_Documento->Size = System::Drawing::Size(90, 16);
			this->Label_Documento->TabIndex = 125;
			this->Label_Documento->Text = L"Documento:";
			// 
			// Boton_EstablecerRelacion
			// 
			this->Boton_EstablecerRelacion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_EstablecerRelacion->Location = System::Drawing::Point(502, 354);
			this->Boton_EstablecerRelacion->Name = L"Boton_EstablecerRelacion";
			this->Boton_EstablecerRelacion->Size = System::Drawing::Size(453, 52);
			this->Boton_EstablecerRelacion->TabIndex = 132;
			this->Boton_EstablecerRelacion->Text = L"Establecer relación";
			this->Boton_EstablecerRelacion->UseVisualStyleBackColor = true;
			this->Boton_EstablecerRelacion->Click += gcnew System::EventHandler(this, &NuevaRelacionMultimedia::Boton_EstablecerRelacion_Click);
			// 
			// GroupBox_Atributo
			// 
			this->GroupBox_Atributo->Controls->Add(this->GroupBox_ValorAtributo);
			this->GroupBox_Atributo->Controls->Add(this->TextBox_NombreAtributo);
			this->GroupBox_Atributo->Controls->Add(this->Label_NombreAtributo);
			this->GroupBox_Atributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBox_Atributo->Location = System::Drawing::Point(502, 37);
			this->GroupBox_Atributo->Name = L"GroupBox_Atributo";
			this->GroupBox_Atributo->Size = System::Drawing::Size(453, 298);
			this->GroupBox_Atributo->TabIndex = 133;
			this->GroupBox_Atributo->TabStop = false;
			this->GroupBox_Atributo->Text = L"Atributo a añadir";
			// 
			// GroupBox_ValorAtributo
			// 
			this->GroupBox_ValorAtributo->Controls->Add(this->Boton_ConsultarMultimediaID);
			this->GroupBox_ValorAtributo->Controls->Add(this->ComboBox_Filename);
			this->GroupBox_ValorAtributo->Controls->Add(this->ComboBox_TipoDocumento);
			this->GroupBox_ValorAtributo->Controls->Add(this->Label_Tipo);
			this->GroupBox_ValorAtributo->Controls->Add(this->Label_ArchivoMultimedia);
			this->GroupBox_ValorAtributo->Controls->Add(this->Label_NombreDocumento);
			this->GroupBox_ValorAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBox_ValorAtributo->Location = System::Drawing::Point(9, 89);
			this->GroupBox_ValorAtributo->Name = L"GroupBox_ValorAtributo";
			this->GroupBox_ValorAtributo->Size = System::Drawing::Size(438, 196);
			this->GroupBox_ValorAtributo->TabIndex = 134;
			this->GroupBox_ValorAtributo->TabStop = false;
			this->GroupBox_ValorAtributo->Text = L"Valor";
			// 
			// Boton_ConsultarMultimediaID
			// 
			this->Boton_ConsultarMultimediaID->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Boton_ConsultarMultimediaID->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_ConsultarMultimediaID.Image")));
			this->Boton_ConsultarMultimediaID->Location = System::Drawing::Point(23, 137);
			this->Boton_ConsultarMultimediaID->Name = L"Boton_ConsultarMultimediaID";
			this->Boton_ConsultarMultimediaID->Size = System::Drawing::Size(389, 41);
			this->Boton_ConsultarMultimediaID->TabIndex = 140;
			this->Boton_ConsultarMultimediaID->UseVisualStyleBackColor = false;
			this->Boton_ConsultarMultimediaID->Click += gcnew System::EventHandler(this, &NuevaRelacionMultimedia::Boton_ConsultarMultimediaID_Click);
			// 
			// ComboBox_Filename
			// 
			this->ComboBox_Filename->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Filename->FormattingEnabled = true;
			this->ComboBox_Filename->Location = System::Drawing::Point(186, 96);
			this->ComboBox_Filename->Name = L"ComboBox_Filename";
			this->ComboBox_Filename->Size = System::Drawing::Size(226, 28);
			this->ComboBox_Filename->TabIndex = 141;
			// 
			// ComboBox_TipoDocumento
			// 
			this->ComboBox_TipoDocumento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ComboBox_TipoDocumento->FormattingEnabled = true;
			this->ComboBox_TipoDocumento->Location = System::Drawing::Point(186, 62);
			this->ComboBox_TipoDocumento->Name = L"ComboBox_TipoDocumento";
			this->ComboBox_TipoDocumento->Size = System::Drawing::Size(226, 28);
			this->ComboBox_TipoDocumento->TabIndex = 135;
			this->ComboBox_TipoDocumento->SelectedIndexChanged += gcnew System::EventHandler(this, &NuevaRelacionMultimedia::ComboBox_TipoDocumento_SelectedIndexChanged);
			// 
			// Label_Tipo
			// 
			this->Label_Tipo->AutoSize = true;
			this->Label_Tipo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_Tipo->Location = System::Drawing::Point(16, 62);
			this->Label_Tipo->Name = L"Label_Tipo";
			this->Label_Tipo->Size = System::Drawing::Size(154, 19);
			this->Label_Tipo->TabIndex = 136;
			this->Label_Tipo->Text = L"Tipo de documento:";
			// 
			// Label_ArchivoMultimedia
			// 
			this->Label_ArchivoMultimedia->AutoSize = true;
			this->Label_ArchivoMultimedia->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Label_ArchivoMultimedia->Location = System::Drawing::Point(17, 29);
			this->Label_ArchivoMultimedia->Name = L"Label_ArchivoMultimedia";
			this->Label_ArchivoMultimedia->Size = System::Drawing::Size(148, 16);
			this->Label_ArchivoMultimedia->TabIndex = 134;
			this->Label_ArchivoMultimedia->Text = L"Archivo multimedia:";
			// 
			// Label_NombreDocumento
			// 
			this->Label_NombreDocumento->AutoSize = true;
			this->Label_NombreDocumento->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Label_NombreDocumento->Location = System::Drawing::Point(19, 95);
			this->Label_NombreDocumento->Name = L"Label_NombreDocumento";
			this->Label_NombreDocumento->Size = System::Drawing::Size(158, 19);
			this->Label_NombreDocumento->TabIndex = 137;
			this->Label_NombreDocumento->Text = L"Nombre documento:";
			// 
			// TextBox_NombreAtributo
			// 
			this->TextBox_NombreAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->TextBox_NombreAtributo->Location = System::Drawing::Point(133, 43);
			this->TextBox_NombreAtributo->Name = L"TextBox_NombreAtributo";
			this->TextBox_NombreAtributo->Size = System::Drawing::Size(288, 26);
			this->TextBox_NombreAtributo->TabIndex = 133;
			// 
			// Label_NombreAtributo
			// 
			this->Label_NombreAtributo->AutoSize = true;
			this->Label_NombreAtributo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_NombreAtributo->Location = System::Drawing::Point(28, 46);
			this->Label_NombreAtributo->Name = L"Label_NombreAtributo";
			this->Label_NombreAtributo->Size = System::Drawing::Size(76, 20);
			this->Label_NombreAtributo->TabIndex = 132;
			this->Label_NombreAtributo->Text = L"Nombre:";
			// 
			// ComboBox_Doc_1
			// 
			this->ComboBox_Doc_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Doc_1->FormattingEnabled = true;
			this->ComboBox_Doc_1->Location = System::Drawing::Point(31, 99);
			this->ComboBox_Doc_1->Name = L"ComboBox_Doc_1";
			this->ComboBox_Doc_1->Size = System::Drawing::Size(343, 28);
			this->ComboBox_Doc_1->TabIndex = 134;
			// 
			// NuevaRelacionMultimedia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 435);
			this->Controls->Add(this->ComboBox_Doc_1);
			this->Controls->Add(this->GroupBox_Atributo);
			this->Controls->Add(this->Boton_EstablecerRelacion);
			this->Controls->Add(this->Label_Documento);
			this->Controls->Add(this->ComboBox_Coleccion_1);
			this->Controls->Add(this->Label_C_1);
			this->Controls->Add(this->ComboBox_Base_1);
			this->Controls->Add(this->Label_BD_1);
			this->Controls->Add(this->salida_datos);
			this->Controls->Add(this->Boton_Doc);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"NuevaRelacionMultimedia";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ESTABLECER RELACIÓN ENTRE DOCUMENTO Y ARCHIVO MULTIMEDIA";
			this->Load += gcnew System::EventHandler(this, &NuevaRelacionMultimedia::NuevaRelacionMultimedia_Load);
			this->GroupBox_Atributo->ResumeLayout(false);
			this->GroupBox_Atributo->PerformLayout();
			this->GroupBox_ValorAtributo->ResumeLayout(false);
			this->GroupBox_ValorAtributo->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	
	//Carga ComboBox_Base_1, ComboBox tipo de documento y ruta_descarga
		private: System::Void NuevaRelacionMultimedia_Load(System::Object^ sender, System::EventArgs^ e) {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				String^ Base = gcnew String(Bases_Disponibles[i].c_str());
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 1) {
					ComboBox_TipoDocumento->Items->Add(Base);
				}
				else {
					ComboBox_Base_1->Items->Add(Base);
				}
			}
			this->Visible = true;
			MessageBox::Show("Para visualizar un archivo multimedia, este debe ser descargado de la Base de Conocimiento.\nPor favor seleccione la carpeta en la que desea guardar el archivo");
			if (CuadroDeDialogoCarpeta->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				ruta_descarga = toStandardString(CuadroDeDialogoCarpeta->SelectedPath);
			}
		}


	//Carga ComboBox_Coleccion_1
		private: System::Void ComboBox_Base_1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (ComboBox_Base_1->SelectedItem) {
				Base = toStandardString(ComboBox_Base_1->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_Base_1->Text);

			ComboBox_Coleccion_1->Items->Clear();

			vector <string> Colecciones_Disponibles = ListaColeccionesDisponibles(Base);
			for (int i = 0; i < Colecciones_Disponibles.size(); i++) {
				String^ Coleccion = gcnew String(Colecciones_Disponibles[i].c_str());
				ComboBox_Coleccion_1->Items->Add(Coleccion);
			}
		}


	//Carga ComboBox_Doc_1
		private: System::Void ComboBox_Coleccion_1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (ComboBox_Base_1->SelectedItem) {
				Base = toStandardString(ComboBox_Base_1->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_Base_1->Text);

			string Coleccion;
			if (ComboBox_Coleccion_1->SelectedItem) {
				Coleccion = toStandardString(ComboBox_Coleccion_1->SelectedItem->ToString());
			}
			else Coleccion = toStandardString(ComboBox_Coleccion_1->Text);

			ComboBox_Doc_1->Items->Clear();

			vector <string> Documentos_Disponibles = ListaDocumentosDisponibles(Base, Coleccion);
			for (int i = 0; i < Documentos_Disponibles.size(); i++) {
				String^ Identificador = gcnew String(Documentos_Disponibles[i].c_str());
				ComboBox_Doc_1->Items->Add(Identificador);
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


		private: System::Void Boton_Doc_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Limpiamos lo que haya en pantalla de consultas anteriores
			this->salida_datos->Text = "";
			string consulta;
			if (ComboBox_Doc_1->SelectedItem) consulta = toStandardString(ComboBox_Doc_1->SelectedItem->ToString());
			else consulta = toStandardString(ComboBox_Doc_1->Text);
			string base;
			if (ComboBox_Base_1->SelectedItem) base = toStandardString(ComboBox_Base_1->SelectedItem->ToString());
			else base = toStandardString(ComboBox_Base_1->Text);
			string coleccion;
			if (ComboBox_Coleccion_1->SelectedItem) coleccion = toStandardString(ComboBox_Coleccion_1->SelectedItem->ToString());
			else coleccion = toStandardString(ComboBox_Coleccion_1->Text);

			//Banderas para MessageBox
			int ExistenciaBase = ComprobacionExistenciaBase(consulta);
			int ExistenciaColeccion = ComprobacionExistenciaColeccion(consulta);

			vector <string> salida_datos;

			if ((base.empty()) || (coleccion.empty())) salida_datos = BuscarDocumento(base, coleccion, consulta);
			else {
				string ubicacion_consulta = "Consulta.txt";
				CrearFichero(ubicacion_consulta, "identificador", consulta);
				string contenido_fichero = LeerFichero(ubicacion_consulta);
				remove(ubicacion_consulta.c_str());
				salida_datos = ExtraerContenidoDocumento(base, coleccion, contenido_fichero);
			}

			//	Buscamos una base de datos que coincida con el tema introducido
			if (ExistenciaBase == 1) {
				MessageBox::Show("La Base de Conocimiento para robots sociales dispone de una Base de Datos que coincide con el tema consultado");
			}
			//	Buscamos una colección que coincida con el tema introducido
			else {
				if (ExistenciaColeccion == 0) {
					//	Separación del contenido del documento BSON en líneas para poder mostrar por pantalla
					for (int i = 0; i < salida_datos.size(); i++) {
						string salida = salida_datos[i];
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


		private: System::Void Boton_ConsultarMultimediaID_Click(System::Object^ sender, System::EventArgs^ e) {
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


		private: System::Void Boton_EstablecerRelacion_Click(System::Object^ sender, System::EventArgs^ e) {
			//Guardamos los datos relativos al documento principal
			string nombre_doc;
			if (ComboBox_Doc_1->SelectedItem) nombre_doc = toStandardString(ComboBox_Doc_1->SelectedItem->ToString());
			else nombre_doc = toStandardString(ComboBox_Doc_1->Text);
			string base_doc;
			if (ComboBox_Base_1->SelectedItem) base_doc = toStandardString(ComboBox_Base_1->SelectedItem->ToString());
			else base_doc = toStandardString(ComboBox_Base_1->Text);
			string coleccion_doc;
			if (ComboBox_Coleccion_1->SelectedItem) coleccion_doc = toStandardString(ComboBox_Coleccion_1->SelectedItem->ToString());
			else coleccion_doc = toStandardString(ComboBox_Coleccion_1->Text);

			//Guardamos los datos relativos al documento secundario (el que se convertirá en un atributo)
			string nombre_atributo = toStandardString(this->TextBox_NombreAtributo->Text);
			string nombre_doc_atributo;
			if (ComboBox_Filename->SelectedItem) {
				nombre_doc_atributo = toStandardString(ComboBox_Filename->SelectedItem->ToString());
			}
			else nombre_doc_atributo = toStandardString(ComboBox_Filename->Text);
			string base_doc_atributo;
			if (ComboBox_TipoDocumento->SelectedItem) base_doc_atributo = toStandardString(ComboBox_TipoDocumento->SelectedItem->ToString());
			else base_doc_atributo = toStandardString(ComboBox_TipoDocumento->Text);
			string coleccion_doc_atributo = "fs.files";

			EstablecerRelacionMultimedia(nombre_doc, base_doc, coleccion_doc, nombre_atributo, nombre_doc_atributo, base_doc_atributo, coleccion_doc_atributo, confianza_info);
		}


};
}
