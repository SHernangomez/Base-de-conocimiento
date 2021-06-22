/*	TFG:	Sistema de conocimiento para rob�tica cognitiva social
			Grado en Ingenier�a en Tecnolog�as Industriales
			Sof�a Hernang�mez Flores
			2021

	Tutor:	Daniel Gal�n Vicente
*/


#pragma once	//	Directiva para asegurar que el c�digo fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentra la funci�n equivalente al bot�n del formulario
#include "Botones_ArchivoMultimedia.h"

extern string ruta;
extern string extension_archivo;
extern const char* tipo_de_archivo;


namespace BaseConocimiento {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class NuevoMultimedia : public System::Windows::Forms::Form
	{
	public:
		NuevoMultimedia(void)
		{
			InitializeComponent();
		}

	protected:
		~NuevoMultimedia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ CuadroDeDialogo;
	protected:

	private: System::Windows::Forms::Button^ Boton_A�adirImagen;
	private: System::Windows::Forms::Label^ Label_Ruta;

	private: System::Windows::Forms::Button^ Boton_A�adirVideo;
	private: System::Windows::Forms::Button^ Boton_A�adirAudio;
	private: System::Windows::Forms::Button^ Boton_A�adirTexto;
	private: System::Windows::Forms::Button^ Boton_A�adirArchivoMultimedia;
	private: System::Windows::Forms::TextBox^ TextBox_Nombre;
	private: System::Windows::Forms::Label^ Label_Nombre;
	protected:

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->CuadroDeDialogo = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Boton_A�adirImagen = (gcnew System::Windows::Forms::Button());
			this->Label_Ruta = (gcnew System::Windows::Forms::Label());
			this->Boton_A�adirVideo = (gcnew System::Windows::Forms::Button());
			this->Boton_A�adirAudio = (gcnew System::Windows::Forms::Button());
			this->Boton_A�adirTexto = (gcnew System::Windows::Forms::Button());
			this->Boton_A�adirArchivoMultimedia = (gcnew System::Windows::Forms::Button());
			this->TextBox_Nombre = (gcnew System::Windows::Forms::TextBox());
			this->Label_Nombre = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Boton_A�adirImagen
			// 
			this->Boton_A�adirImagen->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_A�adirImagen->Location = System::Drawing::Point(37, 32);
			this->Boton_A�adirImagen->Name = L"Boton_A�adirImagen";
			this->Boton_A�adirImagen->Size = System::Drawing::Size(241, 40);
			this->Boton_A�adirImagen->TabIndex = 0;
			this->Boton_A�adirImagen->Text = L"Imagen";
			this->Boton_A�adirImagen->UseVisualStyleBackColor = true;
			this->Boton_A�adirImagen->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_A�adirImagen_Click);
			// 
			// Label_Ruta
			// 
			this->Label_Ruta->AutoSize = true;
			this->Label_Ruta->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_Ruta->Location = System::Drawing::Point(33, 169);
			this->Label_Ruta->Name = L"Label_Ruta";
			this->Label_Ruta->Size = System::Drawing::Size(0, 20);
			this->Label_Ruta->TabIndex = 1;
			// 
			// Boton_A�adirVideo
			// 
			this->Boton_A�adirVideo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_A�adirVideo->Location = System::Drawing::Point(307, 32);
			this->Boton_A�adirVideo->Name = L"Boton_A�adirVideo";
			this->Boton_A�adirVideo->Size = System::Drawing::Size(241, 40);
			this->Boton_A�adirVideo->TabIndex = 2;
			this->Boton_A�adirVideo->Text = L"Video";
			this->Boton_A�adirVideo->UseVisualStyleBackColor = true;
			this->Boton_A�adirVideo->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_A�adirVideo_Click);
			// 
			// Boton_A�adirAudio
			// 
			this->Boton_A�adirAudio->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_A�adirAudio->Location = System::Drawing::Point(37, 101);
			this->Boton_A�adirAudio->Name = L"Boton_A�adirAudio";
			this->Boton_A�adirAudio->Size = System::Drawing::Size(241, 40);
			this->Boton_A�adirAudio->TabIndex = 3;
			this->Boton_A�adirAudio->Text = L"Audio";
			this->Boton_A�adirAudio->UseVisualStyleBackColor = true;
			this->Boton_A�adirAudio->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_A�adirAudio_Click);
			// 
			// Boton_A�adirTexto
			// 
			this->Boton_A�adirTexto->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_A�adirTexto->Location = System::Drawing::Point(307, 101);
			this->Boton_A�adirTexto->Name = L"Boton_A�adirTexto";
			this->Boton_A�adirTexto->Size = System::Drawing::Size(241, 40);
			this->Boton_A�adirTexto->TabIndex = 4;
			this->Boton_A�adirTexto->Text = L"Texto";
			this->Boton_A�adirTexto->UseVisualStyleBackColor = true;
			this->Boton_A�adirTexto->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_A�adirTexto_Click);
			// 
			// Boton_A�adirArchivoMultimedia
			// 
			this->Boton_A�adirArchivoMultimedia->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_A�adirArchivoMultimedia->Location = System::Drawing::Point(37, 249);
			this->Boton_A�adirArchivoMultimedia->Name = L"Boton_A�adirArchivoMultimedia";
			this->Boton_A�adirArchivoMultimedia->Size = System::Drawing::Size(511, 40);
			this->Boton_A�adirArchivoMultimedia->TabIndex = 5;
			this->Boton_A�adirArchivoMultimedia->Text = L"A�adir archivo multimedia";
			this->Boton_A�adirArchivoMultimedia->UseVisualStyleBackColor = true;
			this->Boton_A�adirArchivoMultimedia->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_A�adirArchivoMultimedia_Click);
			// 
			// TextBox_Nombre
			// 
			this->TextBox_Nombre->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TextBox_Nombre->Location = System::Drawing::Point(115, 207);
			this->TextBox_Nombre->Name = L"TextBox_Nombre";
			this->TextBox_Nombre->Size = System::Drawing::Size(433, 26);
			this->TextBox_Nombre->TabIndex = 6;
			// 
			// Label_Nombre
			// 
			this->Label_Nombre->AutoSize = true;
			this->Label_Nombre->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_Nombre->Location = System::Drawing::Point(33, 210);
			this->Label_Nombre->Name = L"Label_Nombre";
			this->Label_Nombre->Size = System::Drawing::Size(76, 20);
			this->Label_Nombre->TabIndex = 7;
			this->Label_Nombre->Text = L"Nombre:";
			// 
			// NuevoMultimedia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 311);
			this->Controls->Add(this->Label_Nombre);
			this->Controls->Add(this->TextBox_Nombre);
			this->Controls->Add(this->Boton_A�adirArchivoMultimedia);
			this->Controls->Add(this->Boton_A�adirTexto);
			this->Controls->Add(this->Boton_A�adirAudio);
			this->Controls->Add(this->Boton_A�adirVideo);
			this->Controls->Add(this->Label_Ruta);
			this->Controls->Add(this->Boton_A�adirImagen);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"NuevoMultimedia";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"A�ADIR ARCHIVO MULTIMEDIA";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
	//Bot�n seleccionar archivo de imagen
		private: System::Void Boton_A�adirImagen_Click(System::Object^ sender, System::EventArgs^ e) {
			this->CuadroDeDialogo->Filter = L"Archivos JPG (*.jpg)|*.jpg|Archivos JPEG (*.jpeg)|*.jpg";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos PNG(*.png)|*.png";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos BMP(*.bmp)|*.bmp";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos GIF(*.gif)|*.gif";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos SVG(*.svg)|*.svg";
			if (CuadroDeDialogo->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				tipo_de_archivo = "imagen";
				ruta = toStandardString(CuadroDeDialogo->FileName);
				extension_archivo = ruta.substr(ruta.find('.'), strlen(ruta.c_str()));
				String^ ruta_str = gcnew String(ruta.c_str());
				Label_Ruta->Text = ruta_str;
			}
		}
	
	
	//Bot�n seleccionar archivo de v�deo
		private: System::Void Boton_A�adirVideo_Click(System::Object^ sender, System::EventArgs^ e) {
			this->CuadroDeDialogo->Filter = L"Archivos MP4 (*.mp4)|*.mp4";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos AVI(*.avi)|*.avi";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos MKV(*.mkv)|*.mkv";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos FLV(*.flv)|*.flv";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos MOV(*.mov)|*.mov";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos WMV(*.wmv)|*.wmv";
			if (CuadroDeDialogo->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				tipo_de_archivo = "video";
				ruta = toStandardString(CuadroDeDialogo->FileName);
				extension_archivo = ruta.substr(ruta.find('.'), strlen(ruta.c_str()));
				String^ ruta_str = gcnew String(ruta.c_str());
				Label_Ruta->Text = ruta_str;
			}
		}


	//Bot�n seleccionar archivo de audio
		private: System::Void Boton_A�adirAudio_Click(System::Object^ sender, System::EventArgs^ e) {
			this->CuadroDeDialogo->Filter = L"Archivos MP3 (*.mp3)|*.mp3";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos WAV(*.wav)|*.wav";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos AIFF(*.aiff)|*.aiff";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos WMA(*.wma)|*.wma";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos OGG(*.ogg)|*.ogg";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos FLAC(*.flac)|*.flac";
			if (CuadroDeDialogo->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				tipo_de_archivo = "audio";
				ruta = toStandardString(CuadroDeDialogo->FileName);
				extension_archivo = ruta.substr(ruta.find('.'), strlen(ruta.c_str()));
				String^ ruta_str = gcnew String(ruta.c_str());
				Label_Ruta->Text = ruta_str;
			}
		}


	//Bot�n seleccionar archivo de texto
		private: System::Void Boton_A�adirTexto_Click(System::Object^ sender, System::EventArgs^ e) {
			this->CuadroDeDialogo->Filter = L"Archivos TXT (*.txt)|*.txt";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos DOC(*.doc)|*.doc";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos DOCX(*.docx)|*.docx";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos PDF(*.pdf)|*.pdf";
			this->CuadroDeDialogo->Filter = this->CuadroDeDialogo->Filter + L"|Archivos EPUB(*.epub)|*.epub";
			if (CuadroDeDialogo->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				tipo_de_archivo = "texto";
				ruta = toStandardString(CuadroDeDialogo->FileName);
				extension_archivo = ruta.substr(ruta.find('.'), strlen(ruta.c_str()));
				String^ ruta_str = gcnew String(ruta.c_str());
				Label_Ruta->Text = ruta_str;
			}
		}


	//Bot�n a�adir archivo multimedia
		private: System::Void Boton_A�adirArchivoMultimedia_Click(System::Object^ sender, System::EventArgs^ e) {
			string nombre_doc = toStandardString(this->TextBox_Nombre->Text);
			//Funci�n equivalente al bot�n A�adir archivo multimedia
			A�adirArchivoMultimedia(ruta, tipo_de_archivo, nombre_doc);
			A�adirAtributoMultimedia(tipo_de_archivo, nombre_doc, "extension", extension_archivo);
		}

};
}
