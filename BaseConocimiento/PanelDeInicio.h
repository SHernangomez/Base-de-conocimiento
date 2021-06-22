/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez


//Inclusi�n de los ficheros de encabezamiento de los dem�s formularios para poder pasar de uno a otro en un click
#include "ListaBasesDeDatos.h"
#include "NuevaBaseDeDatos.h"
#include "EliminarBaseDeDatos.h"
#include "NuevaColeccion.h"
#include "EliminarColeccion.h"
#include "Consulta.h"
#include "NuevoDocumento.h"
#include "ModificarDocumento.h"
#include "EliminarDocumento.h"
#include "NuevaRelacion.h"
#include "Curiosidad.h"
#include "Multimedia.h"



namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class PanelDeInicio : public System::Windows::Forms::Form
	{
	public:
		PanelDeInicio(void)
		{
			InitializeComponent();
		}

	protected:
		~PanelDeInicio()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ MensajeBienvenida;
	private: System::Windows::Forms::Label^ PreguntaOperacion;











	private: System::Windows::Forms::GroupBox^ GroupBox_BD_C;
	private: System::Windows::Forms::Button^ BotonEliminarColeccion;
	private: System::Windows::Forms::Button^ BotonA�adirColeccion;
	private: System::Windows::Forms::Button^ BotonEliminarBase;
	private: System::Windows::Forms::Button^ BotonA�adirBase;
	private: System::Windows::Forms::Button^ BotonConsultarListaBases;
	private: System::Windows::Forms::GroupBox^ GroupBox_Documentos;

	private: System::Windows::Forms::Button^ Boton_EliminarTema;

	private: System::Windows::Forms::Button^ Boton_A�adirTema;
	private: System::Windows::Forms::Button^ Boton_ConsultarTema;


	private: System::Windows::Forms::Button^ Boton_EstablecerRelacion;
	private: System::Windows::Forms::Button^ Boton_ModificarTema;

	private: System::Windows::Forms::Button^ Boton_PreguntarCuriosidad;
	private: System::Windows::Forms::Button^ BotonSalir;
	private: System::Windows::Forms::Button^ Boton_Multimedia;



	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->MensajeBienvenida = (gcnew System::Windows::Forms::Label());
			this->PreguntaOperacion = (gcnew System::Windows::Forms::Label());
			this->GroupBox_BD_C = (gcnew System::Windows::Forms::GroupBox());
			this->BotonEliminarColeccion = (gcnew System::Windows::Forms::Button());
			this->BotonA�adirColeccion = (gcnew System::Windows::Forms::Button());
			this->BotonEliminarBase = (gcnew System::Windows::Forms::Button());
			this->BotonA�adirBase = (gcnew System::Windows::Forms::Button());
			this->BotonConsultarListaBases = (gcnew System::Windows::Forms::Button());
			this->GroupBox_Documentos = (gcnew System::Windows::Forms::GroupBox());
			this->Boton_EstablecerRelacion = (gcnew System::Windows::Forms::Button());
			this->Boton_ModificarTema = (gcnew System::Windows::Forms::Button());
			this->Boton_EliminarTema = (gcnew System::Windows::Forms::Button());
			this->Boton_A�adirTema = (gcnew System::Windows::Forms::Button());
			this->Boton_ConsultarTema = (gcnew System::Windows::Forms::Button());
			this->Boton_PreguntarCuriosidad = (gcnew System::Windows::Forms::Button());
			this->BotonSalir = (gcnew System::Windows::Forms::Button());
			this->Boton_Multimedia = (gcnew System::Windows::Forms::Button());
			this->GroupBox_BD_C->SuspendLayout();
			this->GroupBox_Documentos->SuspendLayout();
			this->SuspendLayout();
			// 
			// MensajeBienvenida
			// 
			this->MensajeBienvenida->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MensajeBienvenida->Location = System::Drawing::Point(175, 25);
			this->MensajeBienvenida->Name = L"MensajeBienvenida";
			this->MensajeBienvenida->Size = System::Drawing::Size(800, 40);
			this->MensajeBienvenida->TabIndex = 4;
			this->MensajeBienvenida->Text = L"Bienvenido a la base de conocimiento para robots sociales";
			this->MensajeBienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PreguntaOperacion
			// 
			this->PreguntaOperacion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PreguntaOperacion->Location = System::Drawing::Point(375, 80);
			this->PreguntaOperacion->Name = L"PreguntaOperacion";
			this->PreguntaOperacion->Size = System::Drawing::Size(400, 30);
			this->PreguntaOperacion->TabIndex = 5;
			this->PreguntaOperacion->Text = L"�Qu� operaci�n desea llevar a cabo\?";
			this->PreguntaOperacion->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GroupBox_BD_C
			// 
			this->GroupBox_BD_C->Controls->Add(this->BotonEliminarColeccion);
			this->GroupBox_BD_C->Controls->Add(this->BotonA�adirColeccion);
			this->GroupBox_BD_C->Controls->Add(this->BotonEliminarBase);
			this->GroupBox_BD_C->Controls->Add(this->BotonA�adirBase);
			this->GroupBox_BD_C->Controls->Add(this->BotonConsultarListaBases);
			this->GroupBox_BD_C->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBox_BD_C->Location = System::Drawing::Point(23, 139);
			this->GroupBox_BD_C->Name = L"GroupBox_BD_C";
			this->GroupBox_BD_C->Size = System::Drawing::Size(533, 256);
			this->GroupBox_BD_C->TabIndex = 13;
			this->GroupBox_BD_C->TabStop = false;
			this->GroupBox_BD_C->Text = L"Bases de datos y colecciones";
			// 
			// BotonEliminarColeccion
			// 
			this->BotonEliminarColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->BotonEliminarColeccion->Location = System::Drawing::Point(298, 180);
			this->BotonEliminarColeccion->Name = L"BotonEliminarColeccion";
			this->BotonEliminarColeccion->Size = System::Drawing::Size(212, 50);
			this->BotonEliminarColeccion->TabIndex = 14;
			this->BotonEliminarColeccion->Text = L"Eliminar colecci�n";
			this->BotonEliminarColeccion->UseVisualStyleBackColor = true;
			this->BotonEliminarColeccion->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonEliminarColeccion_Click);
			// 
			// BotonA�adirColeccion
			// 
			this->BotonA�adirColeccion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonA�adirColeccion->Location = System::Drawing::Point(23, 180);
			this->BotonA�adirColeccion->Name = L"BotonA�adirColeccion";
			this->BotonA�adirColeccion->Size = System::Drawing::Size(212, 47);
			this->BotonA�adirColeccion->TabIndex = 13;
			this->BotonA�adirColeccion->Text = L"A�adir colecci�n";
			this->BotonA�adirColeccion->UseVisualStyleBackColor = true;
			this->BotonA�adirColeccion->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonA�adirColeccion_Click);
			// 
			// BotonEliminarBase
			// 
			this->BotonEliminarBase->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonEliminarBase->Location = System::Drawing::Point(298, 111);
			this->BotonEliminarBase->Name = L"BotonEliminarBase";
			this->BotonEliminarBase->Size = System::Drawing::Size(212, 50);
			this->BotonEliminarBase->TabIndex = 12;
			this->BotonEliminarBase->Text = L"Eliminar base de datos";
			this->BotonEliminarBase->UseVisualStyleBackColor = true;
			this->BotonEliminarBase->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonEliminarBase_Click);
			// 
			// BotonA�adirBase
			// 
			this->BotonA�adirBase->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonA�adirBase->Location = System::Drawing::Point(23, 111);
			this->BotonA�adirBase->Name = L"BotonA�adirBase";
			this->BotonA�adirBase->Size = System::Drawing::Size(212, 50);
			this->BotonA�adirBase->TabIndex = 11;
			this->BotonA�adirBase->Text = L"A�adir base de datos";
			this->BotonA�adirBase->UseVisualStyleBackColor = true;
			this->BotonA�adirBase->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonA�adirBase_Click);
			// 
			// BotonConsultarListaBases
			// 
			this->BotonConsultarListaBases->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->BotonConsultarListaBases->Location = System::Drawing::Point(23, 42);
			this->BotonConsultarListaBases->Name = L"BotonConsultarListaBases";
			this->BotonConsultarListaBases->Size = System::Drawing::Size(487, 50);
			this->BotonConsultarListaBases->TabIndex = 10;
			this->BotonConsultarListaBases->Text = L"Consultar lista de bases de datos y colecciones disponibles";
			this->BotonConsultarListaBases->UseVisualStyleBackColor = true;
			this->BotonConsultarListaBases->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonConsultarListaBases_Click);
			// 
			// GroupBox_Documentos
			// 
			this->GroupBox_Documentos->Controls->Add(this->Boton_EstablecerRelacion);
			this->GroupBox_Documentos->Controls->Add(this->Boton_ModificarTema);
			this->GroupBox_Documentos->Controls->Add(this->Boton_EliminarTema);
			this->GroupBox_Documentos->Controls->Add(this->Boton_A�adirTema);
			this->GroupBox_Documentos->Controls->Add(this->Boton_ConsultarTema);
			this->GroupBox_Documentos->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GroupBox_Documentos->Location = System::Drawing::Point(576, 139);
			this->GroupBox_Documentos->Name = L"GroupBox_Documentos";
			this->GroupBox_Documentos->Size = System::Drawing::Size(533, 256);
			this->GroupBox_Documentos->TabIndex = 15;
			this->GroupBox_Documentos->TabStop = false;
			this->GroupBox_Documentos->Text = L"Documentos";
			// 
			// Boton_EstablecerRelacion
			// 
			this->Boton_EstablecerRelacion->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_EstablecerRelacion->Location = System::Drawing::Point(298, 180);
			this->Boton_EstablecerRelacion->Name = L"Boton_EstablecerRelacion";
			this->Boton_EstablecerRelacion->Size = System::Drawing::Size(212, 50);
			this->Boton_EstablecerRelacion->TabIndex = 19;
			this->Boton_EstablecerRelacion->Text = L"Establecer relaci�n";
			this->Boton_EstablecerRelacion->UseVisualStyleBackColor = true;
			this->Boton_EstablecerRelacion->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_EstablecerRelacion_Click);
			// 
			// Boton_ModificarTema
			// 
			this->Boton_ModificarTema->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_ModificarTema->Location = System::Drawing::Point(23, 180);
			this->Boton_ModificarTema->Name = L"Boton_ModificarTema";
			this->Boton_ModificarTema->Size = System::Drawing::Size(212, 50);
			this->Boton_ModificarTema->TabIndex = 18;
			this->Boton_ModificarTema->Text = L"Modificar tema";
			this->Boton_ModificarTema->UseVisualStyleBackColor = true;
			this->Boton_ModificarTema->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_ModificarTema_Click);
			// 
			// Boton_EliminarTema
			// 
			this->Boton_EliminarTema->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_EliminarTema->Location = System::Drawing::Point(298, 111);
			this->Boton_EliminarTema->Name = L"Boton_EliminarTema";
			this->Boton_EliminarTema->Size = System::Drawing::Size(212, 50);
			this->Boton_EliminarTema->TabIndex = 16;
			this->Boton_EliminarTema->Text = L"Eliminar tema";
			this->Boton_EliminarTema->UseVisualStyleBackColor = true;
			this->Boton_EliminarTema->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_EliminarTema_Click);
			// 
			// Boton_A�adirTema
			// 
			this->Boton_A�adirTema->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_A�adirTema->Location = System::Drawing::Point(23, 111);
			this->Boton_A�adirTema->Name = L"Boton_A�adirTema";
			this->Boton_A�adirTema->Size = System::Drawing::Size(212, 50);
			this->Boton_A�adirTema->TabIndex = 14;
			this->Boton_A�adirTema->Text = L"A�adir tema";
			this->Boton_A�adirTema->UseVisualStyleBackColor = true;
			this->Boton_A�adirTema->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_A�adirTema_Click);
			// 
			// Boton_ConsultarTema
			// 
			this->Boton_ConsultarTema->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_ConsultarTema->Location = System::Drawing::Point(23, 42);
			this->Boton_ConsultarTema->Name = L"Boton_ConsultarTema";
			this->Boton_ConsultarTema->Size = System::Drawing::Size(487, 50);
			this->Boton_ConsultarTema->TabIndex = 13;
			this->Boton_ConsultarTema->Text = L"Consultar tema";
			this->Boton_ConsultarTema->UseVisualStyleBackColor = true;
			this->Boton_ConsultarTema->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_ConsultarTema_Click);
			// 
			// Boton_PreguntarCuriosidad
			// 
			this->Boton_PreguntarCuriosidad->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_PreguntarCuriosidad->Location = System::Drawing::Point(23, 429);
			this->Boton_PreguntarCuriosidad->Name = L"Boton_PreguntarCuriosidad";
			this->Boton_PreguntarCuriosidad->Size = System::Drawing::Size(533, 50);
			this->Boton_PreguntarCuriosidad->TabIndex = 20;
			this->Boton_PreguntarCuriosidad->Text = L"Preguntar curiosidad";
			this->Boton_PreguntarCuriosidad->UseVisualStyleBackColor = true;
			this->Boton_PreguntarCuriosidad->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_PreguntarCuriosidad_Click);
			// 
			// BotonSalir
			// 
			this->BotonSalir->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->BotonSalir->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotonSalir->Location = System::Drawing::Point(23, 499);
			this->BotonSalir->Name = L"BotonSalir";
			this->BotonSalir->Size = System::Drawing::Size(1086, 50);
			this->BotonSalir->TabIndex = 21;
			this->BotonSalir->Text = L"No deseo llevar a cabo ninguna operaci�n";
			this->BotonSalir->UseVisualStyleBackColor = true;
			this->BotonSalir->Click += gcnew System::EventHandler(this, &PanelDeInicio::BotonSalir_Click);
			// 
			// Boton_Multimedia
			// 
			this->Boton_Multimedia->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_Multimedia->Location = System::Drawing::Point(576, 429);
			this->Boton_Multimedia->Name = L"Boton_Multimedia";
			this->Boton_Multimedia->Size = System::Drawing::Size(533, 50);
			this->Boton_Multimedia->TabIndex = 22;
			this->Boton_Multimedia->Text = L"Archivos multimedia";
			this->Boton_Multimedia->UseVisualStyleBackColor = true;
			this->Boton_Multimedia->Click += gcnew System::EventHandler(this, &PanelDeInicio::Boton_Multimedia_Click);
			// 
			// PanelDeInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1134, 576);
			this->Controls->Add(this->Boton_Multimedia);
			this->Controls->Add(this->BotonSalir);
			this->Controls->Add(this->Boton_PreguntarCuriosidad);
			this->Controls->Add(this->GroupBox_Documentos);
			this->Controls->Add(this->GroupBox_BD_C);
			this->Controls->Add(this->PreguntaOperacion);
			this->Controls->Add(this->MensajeBienvenida);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"PanelDeInicio";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PanelDeInicio::OperacionesBasicas_FormClosing);
			this->Load += gcnew System::EventHandler(this, &PanelDeInicio::PanelDeInicio_Load);
			this->GroupBox_BD_C->ResumeLayout(false);
			this->GroupBox_Documentos->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	

	//Bot�n Consultar lista de bases de datos y colecciones disponibles
		private: System::Void BotonConsultarListaBases_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionCreate
			BaseConocimiento::ListaBasesDeDatos^ ListaBasesDeDatos = gcnew BaseConocimiento::ListaBasesDeDatos();
			this->Visible = false;
			ListaBasesDeDatos->ShowDialog();
			this->Visible = true;
		}


	//Bot�n A�adir Base de Datos
		private: System::Void BotonA�adirBase_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionRead
			BaseConocimiento::NuevaBaseDeDatos^ NuevaBaseDeDatos = gcnew BaseConocimiento::NuevaBaseDeDatos();
			this->Visible = false;
			NuevaBaseDeDatos->ShowDialog();
			this->Visible = true;
		}


	//Bot�n Eliminar Base de Datos
		private: System::Void BotonEliminarBase_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionUpdate
			BaseConocimiento::EliminarBaseDeDatos^ EliminarBaseDeDatos = gcnew BaseConocimiento::EliminarBaseDeDatos();
			this->Visible = false;
			EliminarBaseDeDatos->ShowDialog();
			this->Visible = true;
		}


	//Bot�n A�adir Coleccion
		private: System::Void BotonA�adirColeccion_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::NuevaColeccion^ NuevaColeccion = gcnew BaseConocimiento::NuevaColeccion();
			this->Visible = false;
			NuevaColeccion->ShowDialog();
			this->Visible = true;
		}


	//Bot�n Eliminar Colecci�n
		private: System::Void BotonEliminarColeccion_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::EliminarColeccion^ EliminarColeccion = gcnew BaseConocimiento::EliminarColeccion();
			this->Visible = false;
			EliminarColeccion->ShowDialog();
			this->Visible = true;
		}

			   
	//Bot�n Consultar Tema
		private: System::Void Boton_ConsultarTema_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::Consulta^ Consulta = gcnew BaseConocimiento::Consulta();
			this->Visible = false;
			Consulta->ShowDialog();
			this->Visible = true;
		}

			   
	//Bot�n A�adir Tema
		private: System::Void Boton_A�adirTema_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::NuevoDocumento^ NuevoDocumento = gcnew BaseConocimiento::NuevoDocumento();
			this->Visible = false;
			NuevoDocumento->ShowDialog();
			this->Visible = true;
		}


	//Bot�n Modificar Tema
		private: System::Void Boton_ModificarTema_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::ModificarDocumento^ ModificarDocumento = gcnew BaseConocimiento::ModificarDocumento();
			this->Visible = false;
			ModificarDocumento->ShowDialog();
			this->Visible = true;
		}
		
	
	//Bot�n Eliminar Tema
		private: System::Void Boton_EliminarTema_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::EliminarDocumento^ EliminarDocumento = gcnew BaseConocimiento::EliminarDocumento();
			this->Visible = false;
			EliminarDocumento->ShowDialog();
			this->Visible = true;
		}


	//Bot�n Establecer Relaci�n
		private: System::Void Boton_EstablecerRelacion_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::NuevaRelacion^ NuevaRelacion = gcnew BaseConocimiento::NuevaRelacion();
			this->Visible = false;
			NuevaRelacion->ShowDialog();
			this->Visible = true;
		}


	//Bot�n Preguntar Curiosidad
		private: System::Void Boton_PreguntarCuriosidad_Click(System::Object^ sender, System::EventArgs^ e) {
			//	Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::Curiosidad^ Curiosidad = gcnew BaseConocimiento::Curiosidad();
			this->Visible = false;
			Curiosidad->ShowDialog();
			this->Visible = true;
		}


	//Bot�n Multimedia
		private: System::Void Boton_Multimedia_Click(System::Object^ sender, System::EventArgs^ e) {
			//Sintaxis para pasar en un click de OperacionesBasicas a OperacionDelete
			BaseConocimiento::Multimedia^ Multimedia = gcnew BaseConocimiento::Multimedia();
			this->Visible = false;
			Multimedia->ShowDialog();
			this->Visible = true;
		}


	//Bot�n Salir
		private: System::Void BotonSalir_Click(System::Object^ sender, System::EventArgs^ e) {
			if (MessageBox::Show("�Desea abandonar la base de conocimiento?", "Confirmaci�n",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//	Paramos el controlador MongoDB C y liberamos memoria
				mongoc_cleanup();
				//	Cerramos la aplicaci�n
				Application::ExitThread();
			}
		}
	

	//Confirmaci�n de salida cuando se produce el evento pulsar la x para cerrar el formulario
		private: System::Void OperacionesBasicas_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			if (MessageBox::Show("�Desea abandonar la base de conocimiento?", "Confirmaci�n",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				//	Paramos el controlador MongoDB C y liberamos memoria
				mongoc_cleanup();
				//	Cerramos la aplicaci�n
				Application::ExitThread();			
			}
			else e->Cancel = true;	//	Mantenemos abierta la aplicaci�n
		}


private: System::Void PanelDeInicio_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
