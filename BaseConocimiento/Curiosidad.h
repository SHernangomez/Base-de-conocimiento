/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


#include "Botones_Documento.h"


extern string Base_Sel;
extern string Coleccion_Sel;
extern string documento_curiosidad;
extern string clave_curiosidad;
extern string confianza_info;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Curiosidad : public System::Windows::Forms::Form
	{
	public:
		Curiosidad(void)
		{
			InitializeComponent();
		}

	protected:
		~Curiosidad()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:





	private: System::Windows::Forms::Button^ Boton_Responder;
	private: System::Windows::Forms::Label^ Label_PreguntaCompleta;
	private: System::Windows::Forms::TextBox^ TextBox_Respuesta;
	private: System::Windows::Forms::Button^ Boton_NoTiene;

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->Boton_Responder = (gcnew System::Windows::Forms::Button());
			this->Label_PreguntaCompleta = (gcnew System::Windows::Forms::Label());
			this->TextBox_Respuesta = (gcnew System::Windows::Forms::TextBox());
			this->Boton_NoTiene = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Boton_Responder
			// 
			this->Boton_Responder->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_Responder->Location = System::Drawing::Point(23, 150);
			this->Boton_Responder->Name = L"Boton_Responder";
			this->Boton_Responder->Size = System::Drawing::Size(549, 47);
			this->Boton_Responder->TabIndex = 6;
			this->Boton_Responder->Text = L"Responder";
			this->Boton_Responder->UseVisualStyleBackColor = true;
			this->Boton_Responder->Click += gcnew System::EventHandler(this, &Curiosidad::Boton_Responder_Click);
			// 
			// Label_PreguntaCompleta
			// 
			this->Label_PreguntaCompleta->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Label_PreguntaCompleta->Location = System::Drawing::Point(19, 32);
			this->Label_PreguntaCompleta->Name = L"Label_PreguntaCompleta";
			this->Label_PreguntaCompleta->Size = System::Drawing::Size(543, 20);
			this->Label_PreguntaCompleta->TabIndex = 7;
			this->Label_PreguntaCompleta->Text = L"Pregunta";
			// 
			// TextBox_Respuesta
			// 
			this->TextBox_Respuesta->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TextBox_Respuesta->Location = System::Drawing::Point(23, 83);
			this->TextBox_Respuesta->Name = L"TextBox_Respuesta";
			this->TextBox_Respuesta->Size = System::Drawing::Size(310, 26);
			this->TextBox_Respuesta->TabIndex = 8;
			// 
			// Boton_NoTiene
			// 
			this->Boton_NoTiene->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_NoTiene->Location = System::Drawing::Point(354, 73);
			this->Boton_NoTiene->Name = L"Boton_NoTiene";
			this->Boton_NoTiene->Size = System::Drawing::Size(218, 46);
			this->Boton_NoTiene->TabIndex = 9;
			this->Boton_NoTiene->Text = L"No tiene";
			this->Boton_NoTiene->UseVisualStyleBackColor = true;
			this->Boton_NoTiene->Click += gcnew System::EventHandler(this, &Curiosidad::Boton_NoTiene_Click);
			// 
			// Curiosidad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 224);
			this->Controls->Add(this->Boton_NoTiene);
			this->Controls->Add(this->TextBox_Respuesta);
			this->Controls->Add(this->Label_PreguntaCompleta);
			this->Controls->Add(this->Boton_Responder);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"Curiosidad";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PREGUNTAR CURIOSIDAD";
			this->Load += gcnew System::EventHandler(this, &Curiosidad::Curiosidad_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
		private: System::Void Curiosidad_Load(System::Object^ sender, System::EventArgs^ e) {
			string datos = PreguntarCuriosidad();
			int pos = datos.find('#');
			string pregunta = datos.substr(0, pos);
			datos = datos.substr(pos + 1, strlen(datos.c_str()));
			pos = datos.find('#');
			clave_curiosidad = datos.substr(0, pos);
			datos = datos.substr(pos + 1, strlen(datos.c_str()));
			pos = datos.find('#');
			documento_curiosidad = datos.substr(0, pos);
			datos = datos.substr(pos + 1, strlen(datos.c_str()));
			pos = datos.find('#');
			Coleccion_Sel = datos.substr(0, pos);
			Base_Sel = datos.substr(pos + 1, strlen(datos.c_str()));

			if (strcmpi(datos.c_str(), "Todos los documentos están completos") == 0) {
				MessageBox::Show("Todos los documentos están completos");
				this->TextBox_Respuesta->Visible = false;
				this->Boton_Responder->Visible = false;
				this->Boton_NoTiene->Visible = false;

			}
			String^ Pregunta_Completa = gcnew String(pregunta.c_str());
			this->Label_PreguntaCompleta->Text = Pregunta_Completa;
		}


		private: System::Void Boton_Responder_Click(System::Object^ sender, System::EventArgs^ e) {
			string pregunta = toStandardString(this->Label_PreguntaCompleta->Text);
			string valor = toStandardString(this->TextBox_Respuesta->Text);
			String^ clave_str = gcnew String(clave_curiosidad.c_str());
			String^ valor_str = gcnew String(valor.c_str());
			String^ documento_str = gcnew String(documento_curiosidad.c_str());
			if (MessageBox::Show("El/la " + clave_str + " de " + documento_str + " es " + valor_str + ".\n¿Desea añadir esta información a la Base de Conocimiento?", "",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				AñadirAtributoADocumento(documento_curiosidad, clave_curiosidad, valor, Base_Sel, Coleccion_Sel, confianza_info);
			}
			this->Visible = false;
		}


		private: System::Void Boton_NoTiene_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Visible = false;
		}
};
}
