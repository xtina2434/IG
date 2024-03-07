#include "Texture.h"

//-------------------------------------------------------------------------

Texture::~Texture() 
{
	if(mId!=0)
    glDeleteTextures(1, &mId);
}
//-------------------------------------------------------------------------

void Texture::init()
{
  glGenTextures(1, &mId);
  glBindTexture(GL_TEXTURE_2D, mId);
 
  //Filters and clamping
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // GL_NEAREST
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL_NEAREST
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);     // GL_CLAMP
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);     // GL_CLAMP
   
}
//-------------------------------------------------------------------------

void Texture::bind(GLuint mixMode) // GL_REPLACE, GL_MODULATE, GL_ADD
{
  glBindTexture(GL_TEXTURE_2D, mId);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, mixMode);  
}
//-------------------------------------------------------------------------

void Texture::load(const std::string & BMP_Name, GLubyte alpha)
{
	if (mId == 0) init();
	
	PixMap32RGBA pixMap;
  
    pixMap.load_bmp24BGR(BMP_Name);

    if (alpha != 255)
       pixMap.set_alpha(alpha);

	mWidth = pixMap.width();
	mHeight = pixMap.height();

    GLint level = 0;   //Base image level
	GLint border = 0;  //No border
	
	glBindTexture(GL_TEXTURE_2D, mId);
    glTexImage2D(GL_TEXTURE_2D, level, GL_RGBA, mWidth, mHeight, border, GL_RGBA, GL_UNSIGNED_BYTE, pixMap.data());
		
    glBindTexture(GL_TEXTURE_2D, 0); 
}
//-------------------------------------------------------------------------

void Texture::setWrap(GLuint wp) // GL_REPEAT, GL_CLAMP
{
  glBindTexture(GL_TEXTURE_2D, mId);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wp);  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wp);  
  glBindTexture(GL_TEXTURE_2D, 0); 
}
//-------------------------------------------------------------------------
void Texture::loadColorBuffer(GLsizei width, GLsizei height, GLuint buffer) {

	if (mId == 0) init();
	//verificar si buffer es valido
	if (buffer != GL_FRONT && buffer != GL_BACK) {
		return;
	}

	////establecer tamaño textura (tamaño ventana)
	mWidth = width;
	mHeight = height ;

	GLint level = 0;
	GLint border = 0;
	
	glReadBuffer(buffer); //por defecto GL_BACK
	glBindTexture(GL_TEXTURE_2D, mId);
	//copiar en la textura activa el contenido del buffer
	glCopyTexImage2D(GL_TEXTURE_2D, level, GL_RGBA, 0, 0, mWidth, mHeight, border);
	//restaurar buffer
	glReadBuffer(GL_BACK);
	//desvincular textura
	glBindTexture(GL_TEXTURE_2D, 0);

}
void Texture::load(const std::string& BMP_Name, glm::u8vec3 color, GLubyte alpha) {
	if (mId == 0) init();

	PixMap32RGBA pixMap;

	pixMap.load_bmp24BGR(BMP_Name);

	//pasar por cada pixel de la imagen
	for (int y = 0; y < mHeight; y++) { //altura(filas img)
		for (int x = 0; x < mWidth; x++) {//ancho(columnas img)
			glm::u8vec4 pixel = pixMap.pixel(x, y); //obtener cada pixel

			//cambiar la componente alfa de los pixeles cuyo color coincida con el dado
			if (pixel.r == color.r && pixel.g == color.g && pixel.b == color.b) {
				//se cambia el valor de alpha
				pixel.a = alpha;
				pixMap.set_pixel(x, y, pixel); //cambiar al pixel modificado 
			}
		}
	}

	//mWidth = pixMap.width();
	//mHeight = pixMap.height();

	GLint level = 0;   //Base image level
	GLint border = 0;  //No border

	glBindTexture(GL_TEXTURE_2D, mId);
	glTexImage2D(GL_TEXTURE_2D, level, GL_RGBA, mWidth, mHeight, border, GL_RGBA, GL_UNSIGNED_BYTE, pixMap.data());

	glBindTexture(GL_TEXTURE_2D, 0);
	

}