/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


#include "Botones_Documento.h"


//Declaración variables globales que se utilizan en este archivo
extern mongoc_client_t* cliente;
extern mongoc_database_t* base_de_datos;
extern bson_error_t error;

extern string confianza_info;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class NuevaRelacion : public System::Windows::Forms::Form
	{
	public:
		NuevaRelacion(void)
		{
			InitializeComponent();
		}

	protected:
		~NuevaRelacion()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ Boton_Doc1;
	private: System::Windows::Forms::TextBox^ salida_datos_doc1;
	private: System::Windows::Forms::ComboBox^ ComboBox_Coleccion_1;
	private: System::Windows::Forms::Label^ Label_C_1;
	private: System::Windows::Forms::ComboBox^ ComboBox_Base_1;
	private: System::Windows::Forms::Label^ Label_BD_1;
	private: System::Windows::Forms::TextBox^ salida_datos_doc2;

	private: System::Windows::Forms::ComboBox^ ComboBox_Coleccion_2;
	private: System::Windows::Forms::Label^ Label_C_2;
	private: System::Windows::Forms::ComboBox^ ComboBox_Base_2;
	private: System::Windows::Forms::Label^ Label_BD_2;
	private: System::Windows::Forms::Button^ Boton_Doc2;

	private: System::Windows::Forms::Button^ Boton_EstablecerRelacion;
	private: System::Windows::Forms::ComboBox^ ComboBox_Doc_1;
	private: System::Windows::Forms::ComboBox^ ComboBox_Doc_2;





	protected:

	private:

		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NuevaRelacion::typeid));
			this->Boton_Doc1 = (gcnew System::Windows::Forms::Button());
			this->salida_datos_doc1 = (gcnew System::Windows::Forms::TextBox());
			this->ComboBox_Coleccion_1 = (gcnew System::Windows::Forms::ComboBox());
			this->Label_C_1 = (gcnew System::Windows::Forms::Label());
			this->ComboBox_Base_1 = (gcnew System::Windows::Forms::ComboBox());
			this->Label_BD_1 = (gcnew System::Windows::Forms::Label());
			this->salida_datos_doc2 = (gcnew System::Windows::Forms::TextBox());
			this->ComboBox_Coleccion_2 = (gcnew System::Windows::Forms::ComboBox());
			this->Label_C_2 = (gcnew System::Windows::Forms::Label());
			this->ComboBox_Base_2 = (gcnew System::Windows::Forms::ComboBox());
			this->Label_BD_2 = (gcnew System::Windows::Forms::Label());
			this->Boton_Doc2 = (gcnew System::Windows::Forms::Button());
			this->Boton_EstablecerRelacion = (gcnew System::Windows::Forms::Button());
			this->ComboBox_Doc_1 = (gcnew System::Windows::Forms::ComboBox());
			this->ComboBox_Doc_2 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// Boton_Doc1
			// 
			this->Boton_Doc1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Boton_Doc1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_Doc1.Image")));
			this->Boton_Doc1->Location = System::Drawing::Point(390, 37);
			this->Boton_Doc1->Name = L"Boton_Doc1";
			this->Boton_Doc1->Size = System::Drawing::Size(76, 60);
			this->Boton_Doc1->TabIndex = 77;
			this->Boton_Doc1->UseVisualStyleBackColor = false;
			this->Boton_Doc1->Click += gcnew System::EventHandler(this, &NuevaRelacion::Boton_Doc1_Click);
			// 
			// salida_datos_doc1
			// 
			this->salida_datos_doc1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->salida_datos_doc1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->salida_datos_doc1->Location = System::Drawing::Point(41, 116);
			this->salida_datos_doc1->Multiline = true;
			this->salida_datos_doc1->Name = L"salida_datos_doc1";
			this->salida_datos_doc1->ReadOnly = true;
			this->salida_datos_doc1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->salida_datos_doc1->Size = System::Drawing::Size(441, 307);
			this->salida_datos_doc1->TabIndex = 94;
			// 
			// ComboBox_Coleccion_1
			// 
			this->ComboBox_Coleccion_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Coleccion_1->FormattingEnabled = true;
			this->ComboBox_Coleccion_1->Location = System::Drawing::Point(254, 37);
			this->ComboBox_Coleccion_1->Name = L"ComboBox_Coleccion_1";
			this->ComboBox_Coleccion_1->Size = System::Drawing::Size(130, 28);
			this->ComboBox_Coleccion_1->TabIndex = 117;
			this->ComboBox_Coleccion_1->SelectedIndexChanged += gcnew System::EventHandler(this, &NuevaRelacion::ComboBox_Coleccion_1_SelectedIndexChanged);
			// 
			// Label_C_1
			// 
			this->Label_C_1->AutoSize = true;
			this->Label_C_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_C_1->Location = System::Drawing::Point(223, 41);
			this->Label_C_1->Name = L"Label_C_1";
			this->Label_C_1->Size = System::Drawing::Size(25, 19);
			this->Label_C_1->TabIndex = 115;
			this->Label_C_1->Text = L"C:";
			// 
			// ComboBox_Base_1
			// 
			this->ComboBox_Base_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Base_1->FormattingEnabled = true;
			this->ComboBox_Base_1->Location = System::Drawing::Point(80, 37);
			this->ComboBox_Base_1->Name = L"ComboBox_Base_1";
			this->ComboBox_Base_1->Size = System::Drawing::Size(130, 28);
			this->ComboBox_Base_1->TabIndex = 116;
			this->ComboBox_Base_1->SelectedIndexChanged += gcnew System::EventHandler(this, &NuevaRelacion::ComboBox_Base_1_SelectedIndexChanged);
			// 
			// Label_BD_1
			// 
			this->Label_BD_1->AutoSize = true;
			this->Label_BD_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_BD_1->Location = System::Drawing::Point(37, 41);
			this->Label_BD_1->Name = L"Label_BD_1";
			this->Label_BD_1->Size = System::Drawing::Size(37, 19);
			this->Label_BD_1->TabIndex = 114;
			this->Label_BD_1->Text = L"BD:";
			// 
			// salida_datos_doc2
			// 
			this->salida_datos_doc2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->salida_datos_doc2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->salida_datos_doc2->Location = System::Drawing::Point(515, 116);
			this->salida_datos_doc2->Multiline = true;
			this->salida_datos_doc2->Name = L"salida_datos_doc2";
			this->salida_datos_doc2->ReadOnly = true;
			this->salida_datos_doc2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->salida_datos_doc2->Size = System::Drawing::Size(445, 307);
			this->salida_datos_doc2->TabIndex = 118;
			// 
			// ComboBox_Coleccion_2
			// 
			this->ComboBox_Coleccion_2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Coleccion_2->FormattingEnabled = true;
			this->ComboBox_Coleccion_2->Location = System::Drawing::Point(728, 37);
			this->ComboBox_Coleccion_2->Name = L"ComboBox_Coleccion_2";
			this->ComboBox_Coleccion_2->Size = System::Drawing::Size(130, 28);
			this->ComboBox_Coleccion_2->TabIndex = 124;
			this->ComboBox_Coleccion_2->SelectedIndexChanged += gcnew System::EventHandler(this, &NuevaRelacion::ComboBox_Coleccion_2_SelectedIndexChanged);
			// 
			// Label_C_2
			// 
			this->Label_C_2->AutoSize = true;
			this->Label_C_2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_C_2->Location = System::Drawing::Point(697, 41);
			this->Label_C_2->Name = L"Label_C_2";
			this->Label_C_2->Size = System::Drawing::Size(25, 19);
			this->Label_C_2->TabIndex = 122;
			this->Label_C_2->Text = L"C:";
			// 
			// ComboBox_Base_2
			// 
			this->ComboBox_Base_2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Base_2->FormattingEnabled = true;
			this->ComboBox_Base_2->Location = System::Drawing::Point(554, 37);
			this->ComboBox_Base_2->Name = L"ComboBox_Base_2";
			this->ComboBox_Base_2->Size = System::Drawing::Size(130, 28);
			this->ComboBox_Base_2->TabIndex = 123;
			this->ComboBox_Base_2->SelectedIndexChanged += gcnew System::EventHandler(this, &NuevaRelacion::ComboBox_Base_2_SelectedIndexChanged);
			// 
			// Label_BD_2
			// 
			this->Label_BD_2->AutoSize = true;
			this->Label_BD_2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_BD_2->Location = System::Drawing::Point(511, 41);
			this->Label_BD_2->Name = L"Label_BD_2";
			this->Label_BD_2->Size = System::Drawing::Size(37, 19);
			this->Label_BD_2->TabIndex = 121;
			this->Label_BD_2->Text = L"BD:";
			// 
			// Boton_Doc2
			// 
			this->Boton_Doc2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Boton_Doc2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_Doc2.Image")));
			this->Boton_Doc2->Location = System::Drawing::Point(864, 37);
			this->Boton_Doc2->Name = L"Boton_Doc2";
			this->Boton_Doc2->Size = System::Drawing::Size(76, 60);
			this->Boton_Doc2->TabIndex = 120;
			this->Boton_Doc2->UseVisualStyleBackColor = false;
			this->Boton_Doc2->Click += gcnew System::EventHandler(this, &NuevaRelacion::Boton_Doc2_Click);
			// 
			// Boton_EstablecerRelacion
			// 
			this->Boton_EstablecerRelacion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_EstablecerRelacion->Location = System::Drawing::Point(41, 465);
			this->Boton_EstablecerRelacion->Name = L"Boton_EstablecerRelacion";
			this->Boton_EstablecerRelacion->Size = System::Drawing::Size(899, 52);
			this->Boton_EstablecerRelacion->TabIndex = 125;
			this->Boton_EstablecerRelacion->Text = L"Establecer relación";
			this->Boton_EstablecerRelacion->UseVisualStyleBackColor = true;
			this->Boton_EstablecerRelacion->Click += gcnew System::EventHandler(this, &NuevaRelacion::Boton_EstablecerRelacion_Click);
			// 
			// ComboBox_Doc_1
			// 
			this->ComboBox_Doc_1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Doc_1->FormattingEnabled = true;
			this->ComboBox_Doc_1->Location = System::Drawing::Point(41, 69);
			this->ComboBox_Doc_1->Name = L"ComboBox_Doc_1";
			this->ComboBox_Doc_1->Size = System::Drawing::Size(343, 28);
			this->ComboBox_Doc_1->TabIndex = 126;
			// 
			// ComboBox_Doc_2
			// 
			this->ComboBox_Doc_2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Doc_2->FormattingEnabled = true;
			this->ComboBox_Doc_2->Location = System::Drawing::Point(515, 69);
			this->ComboBox_Doc_2->Name = L"ComboBox_Doc_2";
			this->ComboBox_Doc_2->Size = System::Drawing::Size(343, 28);
			this->ComboBox_Doc_2->TabIndex = 127;
			// 
			// NuevaRelacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 561);
			this->Controls->Add(this->ComboBox_Doc_2);
			this->Controls->Add(this->ComboBox_Doc_1);
			this->Controls->Add(this->Boton_EstablecerRelacion);
			this->Controls->Add(this->ComboBox_Coleccion_2);
			this->Controls->Add(this->Label_C_2);
			this->Controls->Add(this->ComboBox_Base_2);
			this->Controls->Add(this->Label_BD_2);
			this->Controls->Add(this->Boton_Doc2);
			this->Controls->Add(this->salida_datos_doc2);
			this->Controls->Add(this->ComboBox_Coleccion_1);
			this->Controls->Add(this->Label_C_1);
			this->Controls->Add(this->ComboBox_Base_1);
			this->Controls->Add(this->Label_BD_1);
			this->Controls->Add(this->salida_datos_doc1);
			this->Controls->Add(this->Boton_Doc1);
			this->Name = L"NuevaRelacion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ESTABLECER RELACIÓN ENTRE DOCUMENTOS";
			this->Load += gcnew System::EventHandler(this, &NuevaRelacion::NuevaRelacion_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	
	//Carga de los nombres de las Bases de Datos disponibles en ComboBox_Base_1 y ComboBox_Base_2
		private: System::Void NuevaRelacion_Load(System::Object^ sender, System::EventArgs^ e) {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 0) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					ComboBox_Base_1->Items->Add(Base);
					ComboBox_Base_2->Items->Add(Base);
				}
			}
		}
	
		
	//Carga de los nombres de las colecciones disponibles en ComboBox_Coleccion_1
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


	//Carga de los nombres de los documentos disponibles en ComboBox_Doc_1
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


	//Carga de los nombres de las colecciones disponibles en ComboBox_Coleccion_2
		private: System::Void ComboBox_Base_2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (ComboBox_Base_2->SelectedItem) {
				Base = toStandardString(ComboBox_Base_2->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_Base_2->Text);

			ComboBox_Coleccion_2->Items->Clear();

			vector <string> Colecciones_Disponibles = ListaColeccionesDisponibles(Base);
			for (int i = 0; i < Colecciones_Disponibles.size(); i++) {
				String^ Coleccion = gcnew String(Colecciones_Disponibles[i].c_str());
				ComboBox_Coleccion_2->Items->Add(Coleccion);
			}
		}


	//Carga de los nombres de los documentos disponibles en ComboBox_Doc_2
		private: System::Void ComboBox_Coleccion_2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			string Base;
			if (ComboBox_Base_2->SelectedItem) {
				Base = toStandardString(ComboBox_Base_2->SelectedItem->ToString());
			}
			else Base = toStandardString(ComboBox_Base_2->Text);

			string Coleccion;
			if (ComboBox_Coleccion_2->SelectedItem) {
				Coleccion = toStandardString(ComboBox_Coleccion_2->SelectedItem->ToString());
			}
			else Coleccion = toStandardString(ComboBox_Coleccion_2->Text);

			ComboBox_Doc_2->Items->Clear();

			vector <string> Documentos_Disponibles = ListaDocumentosDisponibles(Base, Coleccion);
			for (int i = 0; i < Documentos_Disponibles.size(); i++) {
				String^ Identificador = gcnew String(Documentos_Disponibles[i].c_str());
				ComboBox_Doc_2->Items->Add(Identificador);
			}
		}
	
	
	//Botón buscador primer documento
		private: System::Void Boton_Doc1_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Limpiamos lo que haya en pantalla de consultas anteriores
			this->salida_datos_doc1->Text = "";
			string consulta;
			if(ComboBox_Doc_1->SelectedItem) consulta = toStandardString(ComboBox_Doc_1->SelectedItem->ToString());
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
							this->salida_datos_doc1->Text = ((this->salida_datos_doc1->Text) + "\r\n" + SalidaPantalla);
						}
						else this->salida_datos_doc1->Text = ((this->salida_datos_doc1->Text) + "\r\n");
					}
				}
				else MessageBox::Show("La Base de Conocimiento para robots sociales dispone de una colección que coincide con el tema consultado");
			}
		}


	//Botón buscador segundo documento
		private: System::Void Boton_Doc2_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Limpiamos lo que haya en pantalla de consultas anteriores
			this->salida_datos_doc2->Text = "";
			string consulta;
			if (ComboBox_Doc_2->SelectedItem) consulta = toStandardString(ComboBox_Doc_2->SelectedItem->ToString());
			else consulta = toStandardString(ComboBox_Doc_2->Text);
			string base;
			if (ComboBox_Base_2->SelectedItem) base = toStandardString(ComboBox_Base_2->SelectedItem->ToString());
			else base = toStandardString(ComboBox_Base_2->Text);
			string coleccion;
			if (ComboBox_Coleccion_2->SelectedItem) coleccion = toStandardString(ComboBox_Coleccion_2->SelectedItem->ToString());
			else coleccion = toStandardString(ComboBox_Coleccion_2->Text);

			//Banderas para MessageBox
			int ExistenciaBase = ComprobacionExistenciaBase(consulta);
			int ExistenciaColeccion = ComprobacionExistenciaColeccion(consulta);

			vector <string> salida_datos;

			if ((base.empty()) || (coleccion.empty())) MessageBox::Show("Por favor, seleccione una base de datos y una colección");
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
						String^ SalidaPantalla = gcnew String(salida.c_str());
						this->salida_datos_doc2->Text = ((this->salida_datos_doc2->Text) + "\r\n" + SalidaPantalla);
					}
				}
				else MessageBox::Show("La Base de Conocimiento para robots sociales dispone de una colección que coincide con el tema consultado");
			}
		}


	//Botón establecer relación
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
			string nombre_doc_atributo;
			if (ComboBox_Doc_2->SelectedItem) nombre_doc_atributo = toStandardString(ComboBox_Doc_2->SelectedItem->ToString());
			else nombre_doc_atributo = toStandardString(ComboBox_Doc_2->Text);
			string base_doc_atributo;
			if (ComboBox_Base_2->SelectedItem) base_doc_atributo = toStandardString(ComboBox_Base_2->SelectedItem->ToString());
			else base_doc_atributo = toStandardString(ComboBox_Base_2->Text);
			string coleccion_doc_atributo;
			if (ComboBox_Coleccion_2->SelectedItem) coleccion_doc_atributo = toStandardString(ComboBox_Coleccion_2->SelectedItem->ToString());
			else coleccion_doc_atributo = toStandardString(ComboBox_Coleccion_2->Text);

			EstablecerRelacion(nombre_doc, base_doc, coleccion_doc, nombre_doc_atributo, base_doc_atributo, coleccion_doc_atributo, confianza_info);
		}


};
}
