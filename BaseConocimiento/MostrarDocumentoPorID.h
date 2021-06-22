/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez


#include "Botones_Documento.h"


extern string id_introducido;

namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MostrarDocumentoPorID : public System::Windows::Forms::Form
	{
	public:
		MostrarDocumentoPorID(void)
		{
			InitializeComponent();
		}

	protected:
		~MostrarDocumentoPorID()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ salida_datos;
	protected:

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->salida_datos = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// salida_datos
			// 
			this->salida_datos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->salida_datos->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->salida_datos->Location = System::Drawing::Point(32, 12);
			this->salida_datos->Multiline = true;
			this->salida_datos->Name = L"salida_datos";
			this->salida_datos->ReadOnly = true;
			this->salida_datos->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->salida_datos->Size = System::Drawing::Size(522, 337);
			this->salida_datos->TabIndex = 94;
			// 
			// MostrarDocumentoPorID
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 361);
			this->Controls->Add(this->salida_datos);
			this->Name = L"MostrarDocumentoPorID";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mostrar documento";
			this->Load += gcnew System::EventHandler(this, &MostrarDocumentoPorID::MostrarDocumentoPorID_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	//Buscar documento por ID
		private: System::Void MostrarDocumentoPorID_Load(System::Object^ sender, System::EventArgs^ e) {
			//Funci�n equivalente al bot�n Buscar por ID
			vector <string> documento_consulta = BuscarDocumentoPorID(id_introducido);
			
			//	Separaci�n del contenido del documento BSON en l�neas para poder mostrar por pantalla
			for (int i = 0; i < documento_consulta.size(); i++) {
				string salida = documento_consulta[i];
				String^ SalidaPantalla = gcnew String(salida.c_str());
				this->salida_datos->Text = ((this->salida_datos->Text) + "\r\n" + SalidaPantalla);
			}
		}


	};
}
