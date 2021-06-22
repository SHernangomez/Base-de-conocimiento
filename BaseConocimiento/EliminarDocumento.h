/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez

//Fichero de encabezamiento donde se encuentra la función que equivale al botón del formulario
#include "Botones_Documento.h"


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de EliminarDocumento
	/// </summary>
	public ref class EliminarDocumento : public System::Windows::Forms::Form
	{
	public:
		EliminarDocumento(void)
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
		~EliminarDocumento()
		{
			if (components)
			{
				delete components;
			}
		}






	private: System::Windows::Forms::Button^ Boton_Buscador;
	private: System::Windows::Forms::Label^ datos;
	private: System::Windows::Forms::Button^ Boton_Eliminar;
	private: System::Windows::Forms::TextBox^ salida_datos;
	private: System::Windows::Forms::ComboBox^ ComboBox_Nombre;
	private: System::Windows::Forms::ComboBox^ ComboBox_NombreColeccion;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ ComboBox_NombreBase;
	private: System::Windows::Forms::Label^ label2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EliminarDocumento::typeid));
			this->Boton_Buscador = (gcnew System::Windows::Forms::Button());
			this->datos = (gcnew System::Windows::Forms::Label());
			this->Boton_Eliminar = (gcnew System::Windows::Forms::Button());
			this->salida_datos = (gcnew System::Windows::Forms::TextBox());
			this->ComboBox_Nombre = (gcnew System::Windows::Forms::ComboBox());
			this->ComboBox_NombreColeccion = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ComboBox_NombreBase = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Boton_Buscador
			// 
			this->Boton_Buscador->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Boton_Buscador->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_Buscador.Image")));
			this->Boton_Buscador->Location = System::Drawing::Point(335, 46);
			this->Boton_Buscador->Name = L"Boton_Buscador";
			this->Boton_Buscador->Size = System::Drawing::Size(50, 62);
			this->Boton_Buscador->TabIndex = 73;
			this->Boton_Buscador->UseVisualStyleBackColor = false;
			this->Boton_Buscador->Click += gcnew System::EventHandler(this, &EliminarDocumento::Boton_Buscador_Click);
			// 
			// datos
			// 
			this->datos->AutoSize = true;
			this->datos->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datos->Location = System::Drawing::Point(442, 46);
			this->datos->Name = L"datos";
			this->datos->Size = System::Drawing::Size(0, 20);
			this->datos->TabIndex = 75;
			// 
			// Boton_Eliminar
			// 
			this->Boton_Eliminar->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_Eliminar->Location = System::Drawing::Point(32, 132);
			this->Boton_Eliminar->Name = L"Boton_Eliminar";
			this->Boton_Eliminar->Size = System::Drawing::Size(353, 56);
			this->Boton_Eliminar->TabIndex = 76;
			this->Boton_Eliminar->Text = L"Eliminar tema";
			this->Boton_Eliminar->UseVisualStyleBackColor = true;
			this->Boton_Eliminar->Click += gcnew System::EventHandler(this, &EliminarDocumento::Boton_Eliminar_Click);
			// 
			// salida_datos
			// 
			this->salida_datos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->salida_datos->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->salida_datos->Location = System::Drawing::Point(411, 45);
			this->salida_datos->Multiline = true;
			this->salida_datos->Name = L"salida_datos";
			this->salida_datos->ReadOnly = true;
			this->salida_datos->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->salida_datos->Size = System::Drawing::Size(526, 271);
			this->salida_datos->TabIndex = 110;
			// 
			// ComboBox_Nombre
			// 
			this->ComboBox_Nombre->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_Nombre->FormattingEnabled = true;
			this->ComboBox_Nombre->Location = System::Drawing::Point(32, 80);
			this->ComboBox_Nombre->Name = L"ComboBox_Nombre";
			this->ComboBox_Nombre->Size = System::Drawing::Size(297, 28);
			this->ComboBox_Nombre->TabIndex = 122;
			// 
			// ComboBox_NombreColeccion
			// 
			this->ComboBox_NombreColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ComboBox_NombreColeccion->FormattingEnabled = true;
			this->ComboBox_NombreColeccion->Location = System::Drawing::Point(212, 46);
			this->ComboBox_NombreColeccion->Name = L"ComboBox_NombreColeccion";
			this->ComboBox_NombreColeccion->Size = System::Drawing::Size(117, 28);
			this->ComboBox_NombreColeccion->TabIndex = 121;
			this->ComboBox_NombreColeccion->SelectedIndexChanged += gcnew System::EventHandler(this, &EliminarDocumento::ComboBox_NombreColeccion_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(189, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 19);
			this->label1->TabIndex = 119;
			this->label1->Text = L"C:";
			// 
			// ComboBox_NombreBase
			// 
			this->ComboBox_NombreBase->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ComboBox_NombreBase->FormattingEnabled = true;
			this->ComboBox_NombreBase->Location = System::Drawing::Point(64, 46);
			this->ComboBox_NombreBase->Name = L"ComboBox_NombreBase";
			this->ComboBox_NombreBase->Size = System::Drawing::Size(113, 28);
			this->ComboBox_NombreBase->TabIndex = 120;
			this->ComboBox_NombreBase->SelectedIndexChanged += gcnew System::EventHandler(this, &EliminarDocumento::ComboBox_NombreBase_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(29, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 19);
			this->label2->TabIndex = 118;
			this->label2->Text = L"BD:";
			// 
			// EliminarDocumento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 361);
			this->Controls->Add(this->ComboBox_Nombre);
			this->Controls->Add(this->ComboBox_NombreColeccion);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ComboBox_NombreBase);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->salida_datos);
			this->Controls->Add(this->Boton_Eliminar);
			this->Controls->Add(this->datos);
			this->Controls->Add(this->Boton_Buscador);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"EliminarDocumento";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ELIMINAR DOCUMENTO";
			this->Load += gcnew System::EventHandler(this, &EliminarDocumento::EliminarDocumento_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	//Carga de los nombres de las Bases de Datos en ComboBox_NombreBase
		private: System::Void EliminarDocumento_Load(System::Object^ sender, System::EventArgs^ e) {
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


	//Botón Eliminar Tema
		private: System::Void Boton_Eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
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

			string tema;
			if (ComboBox_Nombre->SelectedItem) {
				tema = toStandardString(ComboBox_Nombre->SelectedItem->ToString());
			}
			else tema = toStandardString(ComboBox_Nombre->Text);
			
			//Bandera para MessageBox
			string ubicacion = "Consulta.txt";
			CrearFichero(ubicacion, "identificador", tema);
			string contenido_fich = LeerFichero(ubicacion);
			remove(ubicacion.c_str());
			vector <string> existeDocumento = BuscarBaseColeccionDoc(contenido_fich);

			if (tema == "") MessageBox::Show("Debe escribir el nombre del documento en el espacio reservado para ello");
			else {
				
				if (existeDocumento.empty()) MessageBox::Show("No existe ningún documento que coincida con el nombre introducido");
				else {

					//Función equivalente al botón Eliminar Tema
					EliminarTema(Base, Coleccion, tema);

					MessageBox::Show("El documento ha sido eliminado.");
					this->Visible = false;
				}
			}
		}


};
}
