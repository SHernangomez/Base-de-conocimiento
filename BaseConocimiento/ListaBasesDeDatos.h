/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Inclusión de los ficheros de encabezamiento de los demás formularios para poder pasar de uno a otro en un click
#include "NuevaBaseDeDatos.h"
#include "EliminarBaseDeDatos.h"
#include "NuevaColeccion.h"
#include "EliminarColeccion.h"


//Declaración variables globales que se utilizan en este archivo
	extern bson_error_t error;
	extern mongoc_client_t* cliente;
	extern mongoc_database_t* base_de_datos;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//	Inclusión namespace std para poder utilizar variables de tipo string
	using namespace std;

	public ref class ListaBasesDeDatos : public System::Windows::Forms::Form
	{
	public:
		ListaBasesDeDatos(void)
		{
			InitializeComponent();
		}

	protected:
		~ListaBasesDeDatos()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ TextBox_Buscador;
	private: System::Windows::Forms::Button^ Boton_Buscador;
	private: System::Windows::Forms::Button^ Boton_Actualizar;
	private: System::Windows::Forms::Panel^ Panel_Operaciones;
	private: System::Windows::Forms::Button^ Boton_AñadirBase;
	private: System::Windows::Forms::Button^ Boton_EliminarBase;
	private: System::Windows::Forms::Button^ Boton_AñadirColeccion;
	private: System::Windows::Forms::Button^ Boton_EliminarColeccion;
	private: System::Windows::Forms::TreeView^ ListaBases;
	private: System::Windows::Forms::Label^ titulo;
	private: System::Windows::Forms::Label^ Titulo_Operaciones;
	

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ListaBasesDeDatos::typeid));
			this->ListaBases = (gcnew System::Windows::Forms::TreeView());
			this->titulo = (gcnew System::Windows::Forms::Label());
			this->Panel_Operaciones = (gcnew System::Windows::Forms::Panel());
			this->Boton_EliminarColeccion = (gcnew System::Windows::Forms::Button());
			this->Boton_AñadirColeccion = (gcnew System::Windows::Forms::Button());
			this->Boton_EliminarBase = (gcnew System::Windows::Forms::Button());
			this->Boton_AñadirBase = (gcnew System::Windows::Forms::Button());
			this->Titulo_Operaciones = (gcnew System::Windows::Forms::Label());
			this->TextBox_Buscador = (gcnew System::Windows::Forms::TextBox());
			this->Boton_Buscador = (gcnew System::Windows::Forms::Button());
			this->Boton_Actualizar = (gcnew System::Windows::Forms::Button());
			this->Panel_Operaciones->SuspendLayout();
			this->SuspendLayout();
			// 
			// ListaBases
			// 
			this->ListaBases->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ListaBases->Location = System::Drawing::Point(30, 150);
			this->ListaBases->Name = L"ListaBases";
			this->ListaBases->Size = System::Drawing::Size(600, 270);
			this->ListaBases->TabIndex = 0;
			// 
			// titulo
			// 
			this->titulo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titulo->Location = System::Drawing::Point(30, 15);
			this->titulo->Name = L"titulo";
			this->titulo->Size = System::Drawing::Size(600, 70);
			this->titulo->TabIndex = 1;
			this->titulo->Text = L"A continuación, se muestra una lista con las bases de datos \r\ndisponibles en el s"
				L"ervidor y sus correspondientes colecciones";
			this->titulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Panel_Operaciones
			// 
			this->Panel_Operaciones->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Panel_Operaciones->Controls->Add(this->Boton_EliminarColeccion);
			this->Panel_Operaciones->Controls->Add(this->Boton_AñadirColeccion);
			this->Panel_Operaciones->Controls->Add(this->Boton_EliminarBase);
			this->Panel_Operaciones->Controls->Add(this->Boton_AñadirBase);
			this->Panel_Operaciones->Controls->Add(this->Titulo_Operaciones);
			this->Panel_Operaciones->Location = System::Drawing::Point(665, 35);
			this->Panel_Operaciones->Name = L"Panel_Operaciones";
			this->Panel_Operaciones->Size = System::Drawing::Size(285, 385);
			this->Panel_Operaciones->TabIndex = 3;
			// 
			// Boton_EliminarColeccion
			// 
			this->Boton_EliminarColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_EliminarColeccion->Location = System::Drawing::Point(42, 300);
			this->Boton_EliminarColeccion->Name = L"Boton_EliminarColeccion";
			this->Boton_EliminarColeccion->Size = System::Drawing::Size(201, 50);
			this->Boton_EliminarColeccion->TabIndex = 12;
			this->Boton_EliminarColeccion->Text = L"Eliminar coleccion";
			this->Boton_EliminarColeccion->UseVisualStyleBackColor = true;
			this->Boton_EliminarColeccion->Click += gcnew System::EventHandler(this, &ListaBasesDeDatos::Boton_EliminarColeccion_Click);
			// 
			// Boton_AñadirColeccion
			// 
			this->Boton_AñadirColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_AñadirColeccion->Location = System::Drawing::Point(42, 222);
			this->Boton_AñadirColeccion->Name = L"Boton_AñadirColeccion";
			this->Boton_AñadirColeccion->Size = System::Drawing::Size(201, 50);
			this->Boton_AñadirColeccion->TabIndex = 11;
			this->Boton_AñadirColeccion->Text = L"Añadir coleccion";
			this->Boton_AñadirColeccion->UseVisualStyleBackColor = true;
			this->Boton_AñadirColeccion->Click += gcnew System::EventHandler(this, &ListaBasesDeDatos::Boton_AñadirColeccion_Click);
			// 
			// Boton_EliminarBase
			// 
			this->Boton_EliminarBase->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_EliminarBase->Location = System::Drawing::Point(42, 145);
			this->Boton_EliminarBase->Name = L"Boton_EliminarBase";
			this->Boton_EliminarBase->Size = System::Drawing::Size(201, 50);
			this->Boton_EliminarBase->TabIndex = 10;
			this->Boton_EliminarBase->Text = L"Eliminar base de datos";
			this->Boton_EliminarBase->UseVisualStyleBackColor = true;
			this->Boton_EliminarBase->Click += gcnew System::EventHandler(this, &ListaBasesDeDatos::Boton_EliminarBase_Click);
			// 
			// Boton_AñadirBase
			// 
			this->Boton_AñadirBase->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_AñadirBase->Location = System::Drawing::Point(42, 70);
			this->Boton_AñadirBase->Name = L"Boton_AñadirBase";
			this->Boton_AñadirBase->Size = System::Drawing::Size(201, 50);
			this->Boton_AñadirBase->TabIndex = 9;
			this->Boton_AñadirBase->Text = L"Añadir base de datos";
			this->Boton_AñadirBase->UseVisualStyleBackColor = true;
			this->Boton_AñadirBase->Click += gcnew System::EventHandler(this, &ListaBasesDeDatos::Boton_AñadirBase_Click);
			// 
			// Titulo_Operaciones
			// 
			this->Titulo_Operaciones->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titulo_Operaciones->Location = System::Drawing::Point(-1, 23);
			this->Titulo_Operaciones->Name = L"Titulo_Operaciones";
			this->Titulo_Operaciones->Size = System::Drawing::Size(285, 26);
			this->Titulo_Operaciones->TabIndex = 8;
			this->Titulo_Operaciones->Text = L"O P E R A C I O N E S";
			this->Titulo_Operaciones->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TextBox_Buscador
			// 
			this->TextBox_Buscador->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TextBox_Buscador->Location = System::Drawing::Point(30, 118);
			this->TextBox_Buscador->Name = L"TextBox_Buscador";
			this->TextBox_Buscador->Size = System::Drawing::Size(250, 26);
			this->TextBox_Buscador->TabIndex = 4;
			// 
			// Boton_Buscador
			// 
			this->Boton_Buscador->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Boton_Buscador->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Boton_Buscador.Image")));
			this->Boton_Buscador->Location = System::Drawing::Point(280, 117);
			this->Boton_Buscador->Name = L"Boton_Buscador";
			this->Boton_Buscador->Size = System::Drawing::Size(50, 28);
			this->Boton_Buscador->TabIndex = 5;
			this->Boton_Buscador->UseVisualStyleBackColor = false;
			this->Boton_Buscador->Click += gcnew System::EventHandler(this, &ListaBasesDeDatos::Boton_Buscador_Click);
			// 
			// Boton_Actualizar
			// 
			this->Boton_Actualizar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Boton_Actualizar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->Boton_Actualizar->FlatAppearance->BorderSize = 3;
			this->Boton_Actualizar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Boton_Actualizar->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_Actualizar->Location = System::Drawing::Point(515, 115);
			this->Boton_Actualizar->Name = L"Boton_Actualizar";
			this->Boton_Actualizar->Size = System::Drawing::Size(115, 35);
			this->Boton_Actualizar->TabIndex = 13;
			this->Boton_Actualizar->Text = L"Actualizar";
			this->Boton_Actualizar->UseVisualStyleBackColor = false;
			this->Boton_Actualizar->Click += gcnew System::EventHandler(this, &ListaBasesDeDatos::Boton_Actualizar_Click);
			// 
			// ListaBasesDeDatos
			// 
			this->AcceptButton = this->Boton_Buscador;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 461);
			this->Controls->Add(this->Boton_Actualizar);
			this->Controls->Add(this->Boton_Buscador);
			this->Controls->Add(this->TextBox_Buscador);
			this->Controls->Add(this->Panel_Operaciones);
			this->Controls->Add(this->titulo);
			this->Controls->Add(this->ListaBases);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"ListaBasesDeDatos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LISTA BASES DE DATOS Y COLECCIONES";
			this->Load += gcnew System::EventHandler(this, &ListaBasesDeDatos::ListaBasesDeDatos_Load);
			this->Panel_Operaciones->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		
	//Método para crear un nuevo nodo en el TreeView
		public: void CrearNodo(System::String^ nombre_base) {
			BaseConocimiento::TreeNode^ nodo_base = gcnew BaseConocimiento::TreeNode();
			nodo_base->Text = nombre_base;
			this->ListaBases->Nodes->AddRange(gcnew cli::array<System::Windows::Forms::TreeNode^ >(1) { nodo_base });
			this->ListaBases->SelectedNode = nodo_base;
		}


	//Método para crear un nuevo subnodo en el TreeView
		public: void CrearSubnodo(System::String^ nombre_coleccion) {
			BaseConocimiento::TreeNode^ subnodo_coleccion = gcnew BaseConocimiento::TreeNode();
			subnodo_coleccion->Text = nombre_coleccion;
			this->ListaBases->SelectedNode->Nodes->AddRange(gcnew cli::array<System::Windows::Forms::TreeNode^ >(1) { subnodo_coleccion });
		}
		

	//Función para mostrar las Bases de Datos y las Colecciones en el TreeView
		private: void MostrarBasesDeDatos() {
			vector <string> Bases_Disponibles = ListaBasesDeDatosDisponibles();
			for (int i = 0; i < Bases_Disponibles.size(); i++) {
				if (BaseDeDatosMultimedia(Bases_Disponibles[i]) == 0) {
					String^ Base = gcnew String(Bases_Disponibles[i].c_str());
					//Creación nuevo nodo (Base de Datos)
					CrearNodo(Base);

					vector <string> Colecciones_Disponibles = ListaColeccionesDisponibles(Bases_Disponibles[i]);
					for (int j = 0; j < Colecciones_Disponibles.size(); j++) {
						String^ Coleccion = gcnew String(Colecciones_Disponibles[j].c_str());
						//Creación de un nuevo subnodo (colección)
						CrearSubnodo(Coleccion);
					}
				}
			}
		}


	//Carga de las Bases de Datos y las Colecciones al abrir el formulario ListaBasesDeDatos
		private: System::Void ListaBasesDeDatos_Load(System::Object^ sender, System::EventArgs^ e) {
			MostrarBasesDeDatos();
		}

		
	//Botón Buscador (Accept Button)
		private: System::Void Boton_Buscador_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Almacenamiento del tema buscado en la variable consulta
			string consulta = toStandardString(this->TextBox_Buscador->Text);

			if(ComprobacionExistenciaBase(consulta) == 1){

				//	Borramos los nodos y subnodos de la vista TreeView
				this->ListaBases->Nodes->Clear();
						
				//	Creamos el nodo de la base de datos coincidencia así como sus subnodos (coleccioens)
				String^ nombre_base_consultada = gcnew String(consulta.c_str());
				CrearNodo(nombre_base_consultada);

				vector <string> Colecciones_Disponibles = ListaColeccionesDisponibles(consulta);
				for (int i = 0; i < Colecciones_Disponibles.size(); i++) {
					String^ nombre_coleccion_base_consultada = gcnew String(Colecciones_Disponibles[i].c_str());
					CrearSubnodo(nombre_coleccion_base_consultada);
				}
				ListaBases->ExpandAll();
			}
			else {	//	No se ha encontrado ninguna coincidencia con las bases de datos disponibles
				if (MessageBox::Show("No hay ninguna base de datos que coincida con la expresión buscada. ¿Desea consultar si existe una colección que coincida con la expresión buscada?", "",
					MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
					//	El usuario quiere comprobar si hay alguna coincidencia con las colecciones disponibles
					if(ComprobacionExistenciaColeccion(consulta) == 1){

						vector <string> nombre_bases = BuscarBaseColeccion(consulta);

						//	Borramos los nodos y subnodos de la vista TreeView
						this->ListaBases->Nodes->Clear();

						//	Creamos los nodos correspondientes a la coincidencia
						for (int i = 0; i < nombre_bases.size(); i++) {
							String^ nombre_base_actual = gcnew String(nombre_bases[i].c_str());
							CrearNodo(nombre_base_actual);

							String^ nombre_coleccion_actual = gcnew String(consulta.c_str());
							CrearSubnodo(nombre_coleccion_actual);
						}
						ListaBases->ExpandAll();
					}
					else MessageBox::Show("No se ha encontrado ninguna coincidencia entre el tema buscado y las colecciones disponibles");
				}
			}
		}

	
	//	Botón Actualizar
		private: System::Void Boton_Actualizar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->TextBox_Buscador->Text = "";
			this->ListaBases->Nodes->Clear();
			MostrarBasesDeDatos();
		}


	//Botón Añadir Base de Datos
		private: System::Void Boton_AñadirBase_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionRead
			BaseConocimiento::NuevaBaseDeDatos^ NuevaBaseDeDatos = gcnew BaseConocimiento::NuevaBaseDeDatos();
			NuevaBaseDeDatos->ShowDialog();
			this->ListaBases->Nodes->Clear();
			MostrarBasesDeDatos();
		}


	//Botón Eliminar Base de Datos
		private: System::Void Boton_EliminarBase_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionRead
			BaseConocimiento::EliminarBaseDeDatos^ EliminarBaseDeDatos = gcnew BaseConocimiento::EliminarBaseDeDatos();
			EliminarBaseDeDatos->ShowDialog();
			this->ListaBases->Nodes->Clear();
			MostrarBasesDeDatos();
		}

		
	//Botón Añadir Colección
		private: System::Void Boton_AñadirColeccion_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionRead
			BaseConocimiento::NuevaColeccion^ NuevaColeccion = gcnew BaseConocimiento::NuevaColeccion();
			NuevaColeccion->ShowDialog();
			this->ListaBases->Nodes->Clear();
			MostrarBasesDeDatos();
		}

		
	//Botón Eliminar colección
		private: System::Void Boton_EliminarColeccion_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionRead
			BaseConocimiento::EliminarColeccion^ EliminarColeccion = gcnew BaseConocimiento::EliminarColeccion();
			EliminarColeccion->ShowDialog();
			this->ListaBases->Nodes->Clear();
			MostrarBasesDeDatos();
		}


};
}
