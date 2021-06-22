/*	TFG:	Sistema de conocimiento para robótica cognitiva social
			Grado en Ingeniería en Tecnologías Industriales
			Sofía Hernangómez Flores
			2021

	Tutor:	Daniel Galán Vicente
*/


#pragma once	//	Directiva para asegurar que el código fuente sea incluido una sola vez


//Fichero de encabezamiento donde se encuentra la función equivalente al botón del formulario
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

	private: System::Windows::Forms::Button^ Boton_AñadirImagen;
	private: System::Windows::Forms::Label^ Label_Ruta;

	private: System::Windows::Forms::Button^ Boton_AñadirVideo;
	private: System::Windows::Forms::Button^ Boton_AñadirAudio;
	private: System::Windows::Forms::Button^ Boton_AñadirTexto;
	private: System::Windows::Forms::Button^ Boton_AñadirArchivoMultimedia;
	private: System::Windows::Forms::TextBox^ TextBox_Nombre;
	private: System::Windows::Forms::Label^ Label_Nombre;
	protected:

	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->CuadroDeDialogo = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Boton_AñadirImagen = (gcnew System::Windows::Forms::Button());
			this->Label_Ruta = (gcnew System::Windows::Forms::Label());
			this->Boton_AñadirVideo = (gcnew System::Windows::Forms::Button());
			this->Boton_AñadirAudio = (gcnew System::Windows::Forms::Button());
			this->Boton_AñadirTexto = (gcnew System::Windows::Forms::Button());
			this->Boton_AñadirArchivoMultimedia = (gcnew System::Windows::Forms::Button());
			this->TextBox_Nombre = (gcnew System::Windows::Forms::TextBox());
			this->Label_Nombre = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Boton_AñadirImagen
			// 
			this->Boton_AñadirImagen->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_AñadirImagen->Location = System::Drawing::Point(37, 32);
			this->Boton_AñadirImagen->Name = L"Boton_AñadirImagen";
			this->Boton_AñadirImagen->Size = System::Drawing::Size(241, 40);
			this->Boton_AñadirImagen->TabIndex = 0;
			this->Boton_AñadirImagen->Text = L"Imagen";
			this->Boton_AñadirImagen->UseVisualStyleBackColor = true;
			this->Boton_AñadirImagen->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_AñadirImagen_Click);
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
			// Boton_AñadirVideo
			// 
			this->Boton_AñadirVideo->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_AñadirVideo->Location = System::Drawing::Point(307, 32);
			this->Boton_AñadirVideo->Name = L"Boton_AñadirVideo";
			this->Boton_AñadirVideo->Size = System::Drawing::Size(241, 40);
			this->Boton_AñadirVideo->TabIndex = 2;
			this->Boton_AñadirVideo->Text = L"Video";
			this->Boton_AñadirVideo->UseVisualStyleBackColor = true;
			this->Boton_AñadirVideo->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_AñadirVideo_Click);
			// 
			// Boton_AñadirAudio
			// 
			this->Boton_AñadirAudio->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_AñadirAudio->Location = System::Drawing::Point(37, 101);
			this->Boton_AñadirAudio->Name = L"Boton_AñadirAudio";
			this->Boton_AñadirAudio->Size = System::Drawing::Size(241, 40);
			this->Boton_AñadirAudio->TabIndex = 3;
			this->Boton_AñadirAudio->Text = L"Audio";
			this->Boton_AñadirAudio->UseVisualStyleBackColor = true;
			this->Boton_AñadirAudio->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_AñadirAudio_Click);
			// 
			// Boton_AñadirTexto
			// 
			this->Boton_AñadirTexto->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_AñadirTexto->Location = System::Drawing::Point(307, 101);
			this->Boton_AñadirTexto->Name = L"Boton_AñadirTexto";
			this->Boton_AñadirTexto->Size = System::Drawing::Size(241, 40);
			this->Boton_AñadirTexto->TabIndex = 4;
			this->Boton_AñadirTexto->Text = L"Texto";
			this->Boton_AñadirTexto->UseVisualStyleBackColor = true;
			this->Boton_AñadirTexto->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_AñadirTexto_Click);
			// 
			// Boton_AñadirArchivoMultimedia
			// 
			this->Boton_AñadirArchivoMultimedia->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Boton_AñadirArchivoMultimedia->Location = System::Drawing::Point(37, 249);
			this->Boton_AñadirArchivoMultimedia->Name = L"Boton_AñadirArchivoMultimedia";
			this->Boton_AñadirArchivoMultimedia->Size = System::Drawing::Size(511, 40);
			this->Boton_AñadirArchivoMultimedia->TabIndex = 5;
			this->Boton_AñadirArchivoMultimedia->Text = L"Añadir archivo multimedia";
			this->Boton_AñadirArchivoMultimedia->UseVisualStyleBackColor = true;
			this->Boton_AñadirArchivoMultimedia->Click += gcnew System::EventHandler(this, &NuevoMultimedia::Boton_AñadirArchivoMultimedia_Click);
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
			this->Controls->Add(this->Boton_AñadirArchivoMultimedia);
			this->Controls->Add(this->Boton_AñadirTexto);
			this->Controls->Add(this->Boton_AñadirAudio);
			this->Controls->Add(this->Boton_AñadirVideo);
			this->Controls->Add(this->Label_Ruta);
			this->Controls->Add(this->Boton_AñadirImagen);
			this->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"NuevoMultimedia";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AÑADIR ARCHIVO MULTIMEDIA";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
	//Botón seleccionar archivo de imagen
		private: System::Void Boton_AñadirImagen_Click(System::Object^ sender, System::EventArgs^ e) {
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
	
	
	//Botón seleccionar archivo de vídeo
		private: System::Void Boton_AñadirVideo_Click(System::Object^ sender, System::EventArgs^ e) {
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


	//Botón seleccionar archivo de audio
		private: System::Void Boton_AñadirAudio_Click(System::Object^ sender, System::EventArgs^ e) {
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


	//Botón seleccionar archivo de texto
		private: System::Void Boton_AñadirTexto_Click(System::Object^ sender, System::EventArgs^ e) {
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


	//Botón añadir archivo multimedia
		private: System::Void Boton_AñadirArchivoMultimedia_Click(System::Object^ sender, System::EventArgs^ e) {
			string nombre_doc = toStandardString(this->TextBox_Nombre->Text);
			//Función equivalente al botón Añadir archivo multimedia
			AñadirArchivoMultimedia(ruta, tipo_de_archivo, nombre_doc);
			AñadirAtributoMultimedia(tipo_de_archivo, nombre_doc, "extension", extension_archivo);
		}

};
}
